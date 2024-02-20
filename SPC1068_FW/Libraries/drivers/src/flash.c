/**************************************************************************//**
 * @file     flash.c
 * @brief    This file provides Internal FLASH firmware functions.
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

#include "flash.h"


/**  
 *  @brief Flash Private Functions
 */
void FLASH_WriteEnable(void);
void FLASH_WriteDisable(void);
void FLASH_WriteEnableVSR(void);
uint8_t FLASH_GetStatusL(void);
uint8_t FLASH_GetStatusH(void);
ErrorStatus FLASH_WriteStatus(uint16_t u16StatusVal);

uint32_t FLASH_GetManufacturerID(void);




/****************************************************************************//**
 * @brief      Flush Write and Read FIFOs
 *
 * @param[in]  none
 *
 * @return     none
 *
 *******************************************************************************/
void QSPI_FlushFIFO(void)
{
  QSPI->QSPICTL1.all |= QSPICTL1_ALL_FIFOFLUSH_FLUSH;
    
  /* Wait until Write and Read FIFOs are flushed. */ 
  while((QSPI->QSPICTL1.all & QSPICTL1_ALL_FIFOFLUSH_Msk) == QSPICTL1_ALL_FIFOFLUSH_FLUSH);
}




/****************************************************************************//**
 * @brief      Activate serial select output
 *
 * @param[in]  none
 *
 * @return     none
 *
 *******************************************************************************/
void QSPI_SSEnable(void)
{
  /* Serial select is activated, serial interface select output is driven low */
  QSPI->QSPICTL0.all |= QSPICTL0_ALL_EN_ENABLE;
  
  /* Wait until QSPI ready for a new transfer */
  while((QSPI->QSPICTL0.all & QSPICTL0_ALL_RDY_Msk) == QSPICTL0_ALL_RDY_TRANSFER_BUSY);
}




/****************************************************************************//**
 * @brief      De-activate serial select output
 *
 * @param[in]  none
 *
 * @return     none
 *
 *******************************************************************************/
void QSPI_SSDisable(void)
{
  /* Serial select is de-activated, serial interface select output is driven high */
  QSPI->QSPICTL0.all &= ~QSPICTL0_ALL_EN_Msk;
  
  /* Wait until QSPI ready for a new transfer */
  while((QSPI->QSPICTL0.all & QSPICTL0_ALL_RDY_Msk) == QSPICTL0_ALL_RDY_TRANSFER_BUSY);
}




/****************************************************************************//**
 * @brief      Start the specified QSPI write transfer
 *
 * @param[in]  none
 *
 * @return     none
 *
 *******************************************************************************/
void QSPI_StartWriteTransfer(void)
{
  /* Assert QSPI SS */
  QSPI_SSEnable();
  
  /* Set write mode */
  QSPI->QSPICTL1.all |= QSPICTL1_ALL_WEN_WRITE;
  
  /* Start QSPI */
  QSPI->QSPICTL1.all |= QSPICTL1_ALL_START_TRANSFER_START;
}




/****************************************************************************//**
 * @brief      Start the specified QSPI read transfer
 *
 * @param[in]  none
 *
 * @return     none
 *
 *******************************************************************************/
void QSPI_StartReadTransfer(void)
{
  /* Assert QSPI SS */
  QSPI_SSEnable();
  
  /* Set read/write mode */
  QSPI->QSPICTL1.all &= ~QSPICTL1_ALL_WEN_Msk;
  
  /* Start QSPI */
  QSPI->QSPICTL1.all |= QSPICTL1_ALL_START_TRANSFER_START;
}




/****************************************************************************//**
 * @brief      Stop QSPI transfer
 *
 * @param[in]  none
 *
 * @return     none
 *
 *******************************************************************************/
void QSPI_StopTransfer(void) 
{
  /* Wait until QSPI ready */
  while((QSPI->QSPICTL0.all & QSPICTL0_ALL_RDY_Msk) == QSPICTL0_ALL_RDY_TRANSFER_BUSY);
  
  /* Wait until wfifo empty */
  while((QSPI->QSPICTL0.all & QSPICTL0_ALL_WFIFOEMPTY_Msk) == QSPICTL0_ALL_WFIFOEMPTY_NOT_OCCUR);
        
  /* Stop QSPI */
  QSPI->QSPICTL1.all |= QSPICTL1_ALL_STOP_TRANSFER_STOP;
  
  /* Wait until QSPI release start signal */
  while((QSPI->QSPICTL1.all & QSPICTL1_ALL_START_Msk) == QSPICTL1_ALL_START_TRANSFER_START);
  
  /* De-assert QSPI SS */
  QSPI_SSDisable();
}




/****************************************************************************//**
 * @brief      Write a byte to QSPI serial interface
 *
 * @param[in]  u8ByteData:  Byte data to be written
 *
 * @return     none
 *
 *******************************************************************************/
void QSPI_WriteByte(uint8_t u8ByteData)
{
  /* Wait unitl WFIFO is not full*/
  while((QSPI->QSPICTL0.all & QSPICTL0_ALL_WFIFOFULL_Msk) == QSPICTL0_ALL_WFIFOFULL_OCCUR);
  
  QSPI->QSPIDOUT.all = (u8ByteData & 0xFF);
}




/****************************************************************************//**
 * @brief      Read a byte from QSPI serial interface
 *
 * @param[in]  none
 *
 * @return     Byte read from QSPI serial interface
 *
 *******************************************************************************/
uint8_t QSPI_ReadByte(void)
{
  uint8_t data;
  
  /* Wait if RFIFO is empty*/
  while((QSPI->QSPICTL0.all & QSPICTL0_ALL_RFIFOEMPTY_Msk) == QSPICTL0_ALL_RFIFOEMPTY_OCCUR);
  
  data = (QSPI->QSPIDIN.all & 0xFF);
  
  return data;
}






/****************************************************************************//**
 * @brief      Set flash write enable
 *
 * @param[in]  none
 *
 * @return     none
 *
 *******************************************************************************/
void FLASH_WriteEnable(void)
{
  /* Clear QSPI FIFO */
  QSPI_FlushFIFO();
  
  /* Set Header count - 1 instruction count */
  QSPI->QSPIHEADER.all = QSPIHEADER_ALL_CMDCNT_1_BYTE;
  
  /* Set data in counter */
  QSPI->QSPIDINCNT.all = 0;
  
  /* Set instruction */
  QSPI->QSPICMD.all = FLASH_INS_CODE_WE;
  
  /* Set QSPI write */
  QSPI_StartWriteTransfer();
  
  /* Stop QSPI transfer */
  QSPI_StopTransfer();
}




/****************************************************************************//**
 * @brief      Set flash write disable
 *
 * @param[in]  none
 *
 * @return     none
 *
 *******************************************************************************/
void FLASH_WriteDisable(void)
{
  /* Clear QSPI FIFO */
  QSPI_FlushFIFO();
  
  /* Set Header count - 1 instruction count */
  QSPI->QSPIHEADER.all = QSPIHEADER_ALL_CMDCNT_1_BYTE;
  
  /* Set data in counter */
  QSPI->QSPIDINCNT.all = 0;
  
  /* Set instruction */
  QSPI->QSPICMD.all = FLASH_INS_CODE_WD;
  
  /* Set QSPI write */
  QSPI_StartWriteTransfer();
  
  /* Stop QSPI transfer */
  QSPI_StopTransfer();
}




/****************************************************************************//**
 * @brief      Write enable for volatile status register
 *
 * @param[in]  none
 *
 * @return     none
 *
 *******************************************************************************/
void FLASH_WriteEnableVSR(void)
{
  /* Clear QSPI FIFO */
  QSPI_FlushFIFO();
  
  /* Set Header count - 1 instruction count */
  QSPI->QSPIHEADER.all = QSPIHEADER_ALL_CMDCNT_1_BYTE;
  
  /* Set data in counter */
  QSPI->QSPIDINCNT.all = 0;
  
  /* Set instruction */
  QSPI->QSPICMD.all = FLASH_INS_CODE_WE_VSR;
  
  /* Set QSPI write */
  QSPI_StartWriteTransfer();
  
  /* Stop QSPI transfer */
  QSPI_StopTransfer();
}




/****************************************************************************//**
 * @brief      Get the status register-1
 *
 * @param[in]  none
 *
 * @return     Specified status = Status[7:0]
 *
 *******************************************************************************/
uint8_t FLASH_GetStatusL(void)
{
  uint8_t status;
  
  /* Clear QSPI FIFO */
  QSPI_FlushFIFO();
  
  /* Set Header count - 1 instruction count */
  QSPI->QSPIHEADER.all = QSPIHEADER_ALL_CMDCNT_1_BYTE;
  
  /* Set data in counter */
  QSPI->QSPIDINCNT.all = 1;
  
  /* Set instruction */
  QSPI->QSPICMD.all = FLASH_INS_CODE_RSR1;
  
  /* Set QSPI data pin mode and byte length */
  QSPI->QSPICTL1.all = ((QSPI->QSPICTL1.all & (~(QSPICTL1_ALL_DATAPIN_Msk | QSPICTL1_ALL_BYTELEN_Msk))) | 
                        (QSPICTL1_ALL_DATAPIN_1_PIN | QSPICTL1_ALL_BYTELEN_1_BYTE));
  
  /* Set QSPI read */
  QSPI_StartReadTransfer();
  
  /* Get flash busy status */
  status = QSPI_ReadByte();
  
  /* Disable QSPI */
  QSPI_SSDisable();
  
  return status;
}




/****************************************************************************//**
 * @brief      Get the status register-2
 *
 * @param[in]  none
 *
 * @return     Specified status = Status[15:8]
 *
 *******************************************************************************/
uint8_t FLASH_GetStatusH(void)
{
  uint8_t status;
  
  /* Clear QSPI FIFO */
  QSPI_FlushFIFO();
  
  /* Set Header count - 1 instruction count */
  QSPI->QSPIHEADER.all = QSPIHEADER_ALL_CMDCNT_1_BYTE;
  
  /* Set data in counter */
  QSPI->QSPIDINCNT.all = 1;
  
  /* Set instruction */
  QSPI->QSPICMD.all = FLASH_INS_CODE_RSR2;
  
  /* Set QSPI data pin mode and byte length */
  QSPI->QSPICTL1.all = ((QSPI->QSPICTL1.all & (~(QSPICTL1_ALL_DATAPIN_Msk | QSPICTL1_ALL_BYTELEN_Msk))) | 
                        (QSPICTL1_ALL_DATAPIN_1_PIN | QSPICTL1_ALL_BYTELEN_1_BYTE));
  
  /* Set QSPI read */
  QSPI_StartReadTransfer();
  
  /* Get flash busy status */
  status = QSPI_ReadByte();
  
  /* Disable QSPI */
  QSPI_SSDisable();
  
  return status;
}




/****************************************************************************//**
 * @brief      Write flash status register volatile bit
 *
 * @param[in]  u16StatusVal:  Status value to be written
 *
 * @return     SUCCESS or ERROR
 *
 *******************************************************************************/
ErrorStatus FLASH_WriteStatusVSR(uint16_t u16StatusVal)
{
  volatile uint32_t localCnt = 0;
  uint8_t byte;
   
  /* Enable flash write */
  FLASH_WriteEnableVSR();
  
  /* Header count and DINCNT has already set in FLASH_WriteEnableVSR */
  
  /* Set instruction */
  QSPI->QSPICMD.all = FLASH_INS_CODE_WSR;
  
  /* Set QSPI data pin mode and byte length */
  QSPI->QSPICTL1.all = ((QSPI->QSPICTL1.all & (~(QSPICTL1_ALL_DATAPIN_Msk | QSPICTL1_ALL_BYTELEN_Msk))) | 
                        (QSPICTL1_ALL_DATAPIN_1_PIN | QSPICTL1_ALL_BYTELEN_1_BYTE));

  /* Set QSPI write */
  QSPI_StartWriteTransfer();
  
  /* Write status[7:0] */
  byte = u16StatusVal & 0xFF;
  QSPI_WriteByte(byte);
  
  /* Write status[15:8] */
  byte = (u16StatusVal >> 8) & 0xFF;
  QSPI_WriteByte(byte);
  
  /* Stop QSPI transfer */
  QSPI_StopTransfer();
  
  while(localCnt++ < 100000)
  {
    /* Check flash busy status */ 
    if(FLASH_GetBusyStatus() == RESET)
    {
      return SUCCESS;
    }
  }
  
  return ERROR;
}




/****************************************************************************//**
 * @brief      Write flash status register non-volatile bit
 *
 * @param[in]  u16StatusVal:  Status value to be written
 *
 * @return     SUCCESS or ERROR
 *
 *******************************************************************************/
ErrorStatus FLASH_WriteStatus(uint16_t u16StatusVal)
{
  volatile uint32_t localCnt = 0;
  uint8_t byte;
   
  /* Enable flash write */
  FLASH_WriteEnable();
  
  /* Header count and DINCNT has already set in FLASH_WriteEnableVSR */
  
  /* Set instruction */
  QSPI->QSPICMD.all = FLASH_INS_CODE_WSR;
  
  /* Set QSPI data pin mode and byte length */
  QSPI->QSPICTL1.all = ((QSPI->QSPICTL1.all & (~(QSPICTL1_ALL_DATAPIN_Msk | QSPICTL1_ALL_BYTELEN_Msk))) | 
                        (QSPICTL1_ALL_DATAPIN_1_PIN | QSPICTL1_ALL_BYTELEN_1_BYTE));

  /* Set QSPI write */
  QSPI_StartWriteTransfer();
  
  /* Write status[7:0] */
  byte = u16StatusVal & 0xFF;
  QSPI_WriteByte(byte);
  
  /* Write status[15:8] */
  byte = (u16StatusVal >> 8) & 0xFF;
  QSPI_WriteByte(byte);
  
  /* Stop QSPI transfer */
  QSPI_StopTransfer();
  
  while(localCnt++ < 100000)
  {
    /* Check flash busy status */ 
    if(FLASH_GetBusyStatus() == RESET)
    {
      return SUCCESS;
    }
  }
  
  return ERROR;
}




/****************************************************************************//**
 * @brief      Get the flash busy status
 *
 * @param[in]  none
 *
 * @return     Flash busy status
 *              - \ref RESET : Flash is not busy
 *              - \ref SET   : Flash is busy
 *
 *******************************************************************************/
FlagStatus FLASH_GetBusyStatus(void)
{
  FlagStatus funcStatus;
  
  /* Clear QSPI FIFO */
  QSPI_FlushFIFO();
  
  /* Set Header count - 1 instruction count */
  QSPI->QSPIHEADER.all = QSPIHEADER_ALL_CMDCNT_1_BYTE;
  
  /* Set data in counter */
  QSPI->QSPIDINCNT.all = 1;
  
  /* Set instruction */
  QSPI->QSPICMD.all = FLASH_INS_CODE_RSR1;
  
  /* Set QSPI data pin mode and byte length */
  QSPI->QSPICTL1.all = ((QSPI->QSPICTL1.all & (~(QSPICTL1_ALL_DATAPIN_Msk | QSPICTL1_ALL_BYTELEN_Msk))) | 
                        (QSPICTL1_ALL_DATAPIN_1_PIN | QSPICTL1_ALL_BYTELEN_1_BYTE));

  /* Set QSPI read */
  QSPI_StartReadTransfer();
  
  /* Get flash busy status */
  funcStatus = (QSPI_ReadByte() & 0x01)? SET : RESET;
  
  /* Disable QSPI */
  QSPI_SSDisable();
  
  return funcStatus;
}




/****************************************************************************//**
 * @brief      Set flash protection mode
 *
 * @param[in]  eProtectMode:  Protection mode selection
 *                            See FLASH_ProtectionEnum for details
 *
 * @return     SUCCESS or ERROR
 *
 *******************************************************************************/
ErrorStatus FLASH_SetProtectionMode(FLASH_ProtectionEnum eProtectMode)
{
  volatile uint32_t localCnt = 0;
  
  /* Enable flash write */
  FLASH_WriteEnable();
  
  /* Set instruction */
  QSPI->QSPICMD.all = FLASH_INS_CODE_WSR;
  
  /* Set QSPI data pin mode and byte length */
  QSPI->QSPICTL1.all = ((QSPI->QSPICTL1.all & (~(QSPICTL1_ALL_DATAPIN_Msk | QSPICTL1_ALL_BYTELEN_Msk))) | 
                        (QSPICTL1_ALL_DATAPIN_1_PIN | QSPICTL1_ALL_BYTELEN_1_BYTE));
  
  /* Set QSPI write */
  QSPI_StartWriteTransfer();
  
  /* Write protection mode (SEC, TB, BP2, BP1, BP0) */
  QSPI_WriteByte(eProtectMode & 0x7F);
  
  /* Write protection mode (CMP) */
  QSPI_WriteByte((eProtectMode & 0x80)>>1);
  
  /* Stop QSPI transfer */
  QSPI_StopTransfer();
  
  while(localCnt++ < 100000)
  {
    /* Check flash busy status */ 
    if(FLASH_GetBusyStatus() == RESET)
    {
      return SUCCESS;
    }
  }
  
  return ERROR;
}




/****************************************************************************//**
 * @brief      Erase the whole flash chip
 *
 * @param[in]  none
 *
 * @return     SUCCESS or ERROR
 *
 *******************************************************************************/
ErrorStatus FLASH_EraseAll(void)
{
  volatile uint32_t localCnt = 0;
    
  /* Enable flash write */
  FLASH_WriteEnable();
  
  /* Set instruction */
  QSPI->QSPICMD.all = FLASH_INS_CODE_CE;
  
  /* Set QSPI write */
  QSPI_StartWriteTransfer();
  
  /* Stop QSPI transfer */
  QSPI_StopTransfer();
  
  while(localCnt++ < 0xFFFFFFF)
  {
    /* Check flash busy status */ 
    if(FLASH_GetBusyStatus() == RESET)
    {
      return SUCCESS;
    }
  }
  
  return ERROR;
}




/****************************************************************************//**
 * @brief      Flash sector erase
 *
 * @param[in]  u32SectorNum:  Sector number to be erased
 *
 * @return     SUCCESS or ERROR
 *
 *******************************************************************************/
ErrorStatus FLASH_SectorErase(uint32_t u32SectorNum)
{
  volatile uint32_t localCnt = 0;
  
  uint32_t sectorAddress;
  
  if(!(u32SectorNum > FLASH_LAST_SECTOR))
  {
    /* Enable flash write */
    FLASH_WriteEnable();
    
    /* Get start address for sector to be erased */
    sectorAddress = u32SectorNum * FLASH_SECTOR_SIZE;
    
    /* Set address counter */
    QSPI->QSPIHEADER.all = (QSPIHEADER_ALL_ADDRCNT_3_BYTE | QSPIHEADER_ALL_CMDCNT_1_BYTE);
   
    /* Set QSPI address pin mode */
    QSPI->QSPICTL1.bit.ADDRPIN = QSPICTL1_BIT_ADDRPIN_1_PIN;
    
    /* Set address */ 
    QSPI->QSPIADDR.all = sectorAddress;
    
    /* Set instruction */
    QSPI->QSPICMD.all = FLASH_INS_CODE_SE;
    
    /* Set QSPI write */
    QSPI_StartWriteTransfer();
    
    /* Stop QSPI transfer */
    QSPI_StopTransfer();
    
    while(localCnt++ < 1000000)
    {
      /* Check flash busy status */ 
      if(FLASH_GetBusyStatus() == RESET)
      {
        return SUCCESS;
      }
    }
  }
  
  return ERROR;
}




/****************************************************************************//**
 * @brief      Flash 32KB block erase
 *
 * @param[in]  u32BlockNum:  Block number to be erased
 *
 * @return     SUCCESS or ERROR
 *
 *******************************************************************************/
ErrorStatus FLASH_Block32KErase(uint32_t u32BlockNum)
{
  uint32_t blockAddress;
  volatile uint32_t localCnt = 0;
  
  if(!(u32BlockNum > FLASH_LAST_32K_BLOCK)) 
  {
    /* Enable flash write */
    FLASH_WriteEnable();
    
    /* Get start address of the block to be erased */
    blockAddress = u32BlockNum * FLASH_32K_BLOCK_SIZE;
    
    /* Set address counter */
    QSPI->QSPIHEADER.all = (QSPIHEADER_ALL_ADDRCNT_3_BYTE | QSPIHEADER_ALL_CMDCNT_1_BYTE);
   
    /* Set QSPI address pin mode */
    QSPI->QSPICTL1.bit.ADDRPIN = QSPICTL1_BIT_ADDRPIN_1_PIN;
    
    /* Set address */ 
    QSPI->QSPIADDR.all = blockAddress;
    
    /* Set instruction */
    QSPI->QSPICMD.all = FLASH_INS_CODE_BE_32K;
    
    /* Set QSPI write */
    QSPI_StartWriteTransfer();
    
    /* Stop QSPI transfer */
    QSPI_StopTransfer();
    
    while(localCnt++ < 2000000)
    {
      /* Check flash busy status */ 
      if(FLASH_GetBusyStatus() == RESET)
      {
        return SUCCESS;
      }
    }
  }
  
  return ERROR;
}




/****************************************************************************//**
 * @brief      Flash 64KB block erase
 *
 * @param[in]  u32BlockNum:  Block number to be erased
 *
 * @return     SUCCESS or ERROR
 *
 *******************************************************************************/
ErrorStatus FLASH_Block64KErase(uint32_t u32BlockNum)
{
  uint32_t blockAddress;
  volatile uint32_t localCnt = 0;
  
  if(!(u32BlockNum > FLASH_LAST_64K_BLOCK))
  {
    /* Enable flash write */
    FLASH_WriteEnable();
    
    /* Get start address of the block to be erased */
    blockAddress = u32BlockNum * FLASH_64K_BLOCK_SIZE;
    
    /* Set address counter */
    QSPI->QSPIHEADER.all = (QSPIHEADER_ALL_ADDRCNT_3_BYTE | QSPIHEADER_ALL_CMDCNT_1_BYTE);
   
    /* Set QSPI address pin mode */
    QSPI->QSPICTL1.bit.ADDRPIN = QSPICTL1_BIT_ADDRPIN_1_PIN;
    
    /* Set address */ 
    QSPI->QSPIADDR.all = blockAddress;
    
    /* Set instruction */
    QSPI->QSPICMD.all = FLASH_INS_CODE_BE_64K;
    
    /* Set QSPI write */
    QSPI_StartWriteTransfer();
    
    /* Stop QSPI transfer */
    QSPI_StopTransfer();
    
    while(localCnt++ < 2000000)
    {
      /* Check flash busy status */ 
      if(FLASH_GetBusyStatus() == RESET)
      {
        return SUCCESS;
      }
    }
  }
  
  return ERROR;
}




/****************************************************************************//**
 * @brief      Erase specfied address range of the flash
 *
 * @param[in]  u32StartAddr:  Start address to be erased
 * @param[in]  u32EndAddr  :  End address to be erased
 *
 * @return     SUCCESS or ERROR
 *
 *******************************************************************************/
ErrorStatus FLASH_Erase(uint32_t u32StartAddr, uint32_t u32EndAddr)
{
  uint32_t startSector, endSector, sectorNumber;

  /* Get sector number of start address */
  startSector = (u32StartAddr / FLASH_SECTOR_SIZE);
 
  /* Get sector number of end address */
  endSector = (u32EndAddr / FLASH_SECTOR_SIZE);

  for(sectorNumber = startSector; sectorNumber <= endSector; sectorNumber++)
  {
    if(FLASH_SectorErase(sectorNumber) == ERROR)
    {
      return ERROR;
    }
  }
  
  return SUCCESS;
}




/****************************************************************************//**
 * @brief      Read flash data from specified address
 *
 * @param[in]  pu8Buf     :  Buffer to hold data read from flash
 * @param[in]  u32Addr    :  Flash address to be read
 * @param[in]  u32NumBytes:  Number of byte data to be read
 *
 * @return     Number of data read out from flash, in bytes
 *
 *******************************************************************************/
uint32_t FLASH_Read(uint8_t *pu8Buf, uint32_t u32Addr, uint32_t u32NumBytes)
{
  uint32_t i;
  uint32_t readBytes;
    
  readBytes = 0;
  
  /* Clear QSPI FIFO */
  QSPI_FlushFIFO();

  /* Set Header count */
  QSPI->QSPIHEADER.all = (QSPIHEADER_ALL_ADDRCNT_3_BYTE | QSPIHEADER_ALL_CMDCNT_1_BYTE);
  
  /* Set read mode */
  QSPI->QSPIRMODE.all = 0;

  /* Set data in counter */
  QSPI->QSPIDINCNT.all = u32NumBytes;
  
  /* Set address */ 
  QSPI->QSPIADDR.all = u32Addr;
  
  /* Set address pin mode, data pin mode and data length */
  QSPI->QSPICTL1.all = ((QSPI->QSPICTL1.all & (~(QSPICTL1_ALL_ADDRPIN_Msk | QSPICTL1_ALL_DATAPIN_Msk | QSPICTL1_ALL_BYTELEN_Msk))) | 
                        (QSPICTL1_ALL_ADDRPIN_1_PIN | QSPICTL1_ALL_DATAPIN_1_PIN | QSPICTL1_ALL_BYTELEN_1_BYTE));
  
  /* Set instruction */
  QSPI->QSPICMD.all = FLASH_INS_CODE_RD;
  
  /* Set QSPI read */
  QSPI_StartReadTransfer();
    
  for (i = 0; i < u32NumBytes; i++)
  {
    pu8Buf[i] = QSPI_ReadByte();
    
    readBytes++;
  }
  
  /* Disable QSPI */
  QSPI_SSDisable();
  
  return readBytes;
}




/****************************************************************************//**
 * @brief      Read flash data from specified address
 *
 * @param[in]  pu32Buf    :  Buffer to hold word data read from flash
 * @param[in]  u32Addr    :  Flash address to be read
 * @param[in]  u32NumWords:  Number of word data to be read
 *
 * @return     Number of data read out from flash, in words
 *
 *******************************************************************************/
uint32_t FLASH_ReadWords(uint32_t *pu32Buf, uint32_t u32Addr, uint32_t u32NumWords)
{
  uint32_t i;
  uint32_t readWords;
    
  readWords = 0;
  
  /* Clear QSPI FIFO */
  QSPI_FlushFIFO();

  /* Set Header count register: instruction counter, address counter, read mode counter and dummy counter */
  QSPI->QSPIHEADER.all = (QSPIHEADER_ALL_ADDRCNT_3_BYTE | QSPIHEADER_ALL_CMDCNT_1_BYTE);
  
  /* Set read mode */
  QSPI->QSPIRMODE.all = 0;

  /* Set data in counter */
  QSPI->QSPIDINCNT.all = (u32NumWords * 4);
  
  /* Set address */ 
  QSPI->QSPIADDR.all = u32Addr;
  
  /* Set address pin mode, data pin mode and data length */
  QSPI->QSPICTL1.all = ((QSPI->QSPICTL1.all & (~(QSPICTL1_ALL_ADDRPIN_Msk | QSPICTL1_ALL_DATAPIN_Msk | QSPICTL1_ALL_BYTELEN_Msk))) | 
                        (QSPICTL1_ALL_ADDRPIN_1_PIN | QSPICTL1_ALL_DATAPIN_1_PIN | QSPICTL1_ALL_BYTELEN_4_BYTE));
  
  /* Set instruction */
  QSPI->QSPICMD.all = FLASH_INS_CODE_RD;
  
  /* Set QSPI read */
  QSPI_StartReadTransfer();
    
  for(i = 0; i < u32NumWords; i++)
  {
    /* Waiting for RFIFO not empty */
    while((QSPI->QSPICTL0.all & QSPICTL0_ALL_RFIFOEMPTY_Msk) == QSPICTL0_ALL_RFIFOEMPTY_OCCUR);
    
    pu32Buf[i] = QSPI->QSPIDIN.all;
    
    readWords++;
  }
  
  /* Disable QSPI */
  QSPI_SSDisable();
  
  return readWords;
}




/****************************************************************************//**
 * @brief      Write data to flash within a page
 *
 * @param[in]  pu8Buf     :  Pointer to the data to be programmed to flash
 * @param[in]  u32Addr    :  Flash address - page aligned
 * @param[in]  u32NumBytes:  Number of byte data to be programmed
 *
 * @return     SUCCESS or ERROR
 *
 *******************************************************************************/
ErrorStatus FLASH_WritePage(uint8_t *pu8Buf, uint32_t u32Addr, uint32_t u32NumBytes)
{
  uint32_t i;
  volatile uint32_t localCnt = 0;
  
  /* Check address validity */
  if((FLASH_PAGE_NUM(u32Addr + u32NumBytes - 1) > FLASH_PAGE_NUM(u32Addr)) || u32NumBytes == 0)
  {
    return ERROR;
  }
  
  /* Enable flash write */
  FLASH_WriteEnable();
  
  /* Set Header count: address counter */
  QSPI->QSPIHEADER.all = (QSPIHEADER_ALL_ADDRCNT_3_BYTE | QSPIHEADER_ALL_CMDCNT_1_BYTE);
  
  /* Set address */ 
  QSPI->QSPIADDR.all = u32Addr;
  
  /* Set address pin mode, data pin mode and data length */
  QSPI->QSPICTL1.all = ((QSPI->QSPICTL1.all & (~(QSPICTL1_ALL_ADDRPIN_Msk | QSPICTL1_ALL_DATAPIN_Msk | QSPICTL1_ALL_BYTELEN_Msk))) | 
                        (QSPICTL1_ALL_ADDRPIN_1_PIN | QSPICTL1_ALL_DATAPIN_1_PIN | QSPICTL1_ALL_BYTELEN_1_BYTE));
  
  /* Set instruction */
  QSPI->QSPICMD.all = FLASH_INS_CODE_PP;
  
  /* Set QSPI write */
  QSPI_StartWriteTransfer();
  
  for(i = 0; i < u32NumBytes; i++) 
  {
    QSPI_WriteByte(pu8Buf[i]);
  }
  
  /* Stop QSPI transfer */
  QSPI_StopTransfer();
  
  while(localCnt++ < 1000000)
  {
    /* Check flash busy status */ 
    if(FLASH_GetBusyStatus() == RESET)
    {
      return SUCCESS;
    }
  }

  return ERROR;
}




/****************************************************************************//**
 * @brief      Write data to flash with any address and size
 *
 * @param[in]  pu8Buf     :  Pointer to the data to be programmed to flash
 * @param[in]  u32Addr    :  Flash address
 * @param[in]  u32NumBytes:  Number of byte data to be programmed
 *
 * @return     SUCCESS or ERROR
 *
 *******************************************************************************/
ErrorStatus FLASH_Write(uint8_t *pu8Buf, uint32_t u32Addr, uint32_t u32NumBytes) 
{
  uint8_t *pBuf;
  uint32_t begPgNum;
  uint32_t endPgNum;
  uint32_t step;
  uint32_t addrCur;
  uint32_t i;
  ErrorStatus funcStatus = SUCCESS;
  
  pBuf = pu8Buf;
  addrCur = u32Addr;
  
  /* Get page number of start address */
  begPgNum = FLASH_PAGE_NUM(u32Addr);
  /* Get page number of end address */
  endPgNum = FLASH_PAGE_NUM(u32Addr + u32NumBytes - 1);

  /* Both start address and end address are within the same page */
  if(begPgNum == endPgNum)
  {
    return (FLASH_WritePage(pu8Buf, u32Addr, u32NumBytes));
  }
  /* Start address and end address are not in the same page */
  else
  {
    /* For first page */
    step = FLASH_PAGE_END_ADDR(u32Addr) - u32Addr + 1;
    funcStatus = FLASH_WritePage(pBuf, u32Addr, step);
    if(funcStatus == ERROR)
    {
      return ERROR;
    }
    
    pBuf += step;
    addrCur += step;

    for(i=begPgNum+1; i<=endPgNum; i++)
    {
      /* For last page */
      if(i == endPgNum)
      {
        step = (u32Addr + u32NumBytes) & 0xFF;
        
        /* If step is 0, the last page has 256 bytes data to be writen ( num of data is 0x100 ) */
        if(step == 0)
        {
          step = 0x100;
        }
        
        return( FLASH_WritePage(pBuf, addrCur, step) );
      }
      else
      {
        funcStatus = FLASH_WritePage(pBuf, addrCur, FLASH_PAGE_SIZE);
        if(funcStatus == ERROR)
        {
          return ERROR;
        }
        
        pBuf += FLASH_PAGE_SIZE;
        addrCur += FLASH_PAGE_SIZE;
      }
    }
  }
  
  return funcStatus;
}




/****************************************************************************//**
 * @brief      Get flash manufacturer ID
 *
 * @param[in]  none
 *
 * @return     Flash Manufacturer ID (Lower 24-bit)
 *
 *******************************************************************************/
uint32_t FLASH_GetManufacturerID(void)
{
  uint32_t u32MID;

  /* Clear QSPI FIFO */
  QSPI_FlushFIFO();
  
  /* Set Header count register: instruction counter, address counter, read mode counter and dummy counter */
  QSPI->QSPIHEADER.all = (QSPIHEADER_ALL_CMDCNT_1_BYTE);
  
  /* Set data in counter */
  QSPI->QSPIDINCNT.all = 3;
  
  /* Set address */ 
  QSPI->QSPIADDR.all = 0;
  
  /* Set address pin mode, data pin mode and data length */
  QSPI->QSPICTL1.all = ((QSPI->QSPICTL1.all & (~(QSPICTL1_ALL_ADDRPIN_Msk | QSPICTL1_ALL_DATAPIN_Msk | QSPICTL1_ALL_BYTELEN_Msk))) | 
                        (QSPICTL1_ALL_ADDRPIN_1_PIN | QSPICTL1_ALL_DATAPIN_1_PIN | QSPICTL1_ALL_BYTELEN_1_BYTE));
  
  /* Set instruction */
  QSPI->QSPICMD.all = FLASH_INS_CODE_RMID;

  /* Set QSPI read */
  QSPI_StartReadTransfer();

  u32MID = QSPI_ReadByte();
  u32MID <<= 8;
  u32MID |= QSPI_ReadByte();
  u32MID <<= 8;
  u32MID |= QSPI_ReadByte();
  
  QSPI_SSDisable();
  
  return u32MID;
}




/****************************************************************************//**
 * @brief      Erase OTP flash
 *
 * @param[in]  u32Addr:  OTP flash address
 *
 * @return     SUCCESS or ERROR
 *
 *******************************************************************************/
ErrorStatus FLASH_EraseOTP(uint32_t u32Addr)
{
  volatile uint32_t localCnt = 0;
  
  /* Actual OTP Flash address */
  uint32_t u32OTPAddr;
  
  /* Flash Manufacturer ID */
  uint32_t u32MID;
  
  
  /* OTP Flash address */
  u32OTPAddr = u32Addr;
  
  /* Get Flash Manufacturer UID */
  u32MID = FLASH_GetManufacturerID();
  
  /* GigaDevice Flash */
  if((u32MID & 0x00FF0000) == 0x00C80000)
  {
    /* Remap OTP2 Flash address */
    if((u32Addr >= FLASH_OTP2_ADDR) && (u32Addr < (FLASH_OTP2_ADDR + 512U)))
    {
      u32OTPAddr -= FLASH_OTP2_ADDR;
    }
    /* GigaDevice Flash does not have OTP3 */
    else if(u32Addr >= FLASH_OTP3_ADDR)
    {
      return ERROR;
    }
  }
  
  
  /* Enable flash write */
  FLASH_WriteEnable();
  
  /* Set instruction count and address count */
  QSPI->QSPIHEADER.all = (QSPIHEADER_ALL_CMDCNT_1_BYTE | QSPIHEADER_ALL_ADDRCNT_3_BYTE);
  
  /* Set address */
  QSPI->QSPIADDR.all = u32OTPAddr;
  
  /* Set QSPI address pin mode */
  QSPI->QSPICTL1.bit.ADDRPIN = QSPICTL1_BIT_ADDRPIN_1_PIN;
  
  /* Set instruction */
  QSPI->QSPICMD.all = FLASH_INS_CODE_SRE;
  
  /* Set QSPI write */
  QSPI_StartWriteTransfer();
  
  /* Stop QSPI transfer */
  QSPI_StopTransfer();
  
  while(localCnt++ < 1000000)
  {
    /* Check flash busy status */ 
    if( FLASH_GetBusyStatus() == RESET )
    {
      return SUCCESS;
    }
  }
  
  return ERROR;
}




/****************************************************************************//**
 * @brief      Read OTP flash data to buffer
 *
 * @param[in]  pu8Buf     :  Buffer to hold data read from OTP flash
 * @param[in]  u32Addr    :  OTP flash address to be read
 * @param[in]  u32NumBytes:  Number of byte data to be read
 *
 * @return     Number of byte data read out from OTP flash
 *
 *******************************************************************************/
uint32_t FLASH_ReadOTP(uint8_t *pu8Buf, uint32_t u32Addr, uint32_t u32NumBytes)
{
  uint32_t i;
  uint32_t readBytes;
  
  /* Actual OTP Flash address */
  uint32_t u32OTPAddr;
  
  /* Flash Manufacturer ID */
  uint32_t u32MID;
  
  
  /* OTP Flash address */
  u32OTPAddr = u32Addr;
  
  /* Get Flash Manufacturer UID */
  u32MID = FLASH_GetManufacturerID();
  
  /* GigaDevice Flash */
  if((u32MID & 0x00FF0000) == 0x00C80000)
  {
    /* Remap OTP2 Flash address */
    if((u32Addr >= FLASH_OTP2_ADDR) && (u32Addr < (FLASH_OTP2_ADDR + 512U)))
    {
      u32OTPAddr -= FLASH_OTP2_ADDR;
    }
    /* GigaDevice Flash does not have OTP3 */
    else if(u32Addr >= FLASH_OTP3_ADDR)
    {
      return 0;
    }
  }
  
  
  readBytes = 0;
  
  /* Clear QSPI FIFO */
  QSPI_FlushFIFO();

  /* Set Header count */
  QSPI->QSPIHEADER.all = (QSPIHEADER_ALL_CMDCNT_1_BYTE | QSPIHEADER_ALL_ADDRCNT_3_BYTE | QSPIHEADER_ALL_DMYCNT_1_BYTE);

  /* Set data in counter */
  QSPI->QSPIDINCNT.all = u32NumBytes;
  
  /* Set address */
  QSPI->QSPIADDR.all = u32OTPAddr;
  
  QSPI->QSPICTL1.all = ((QSPI->QSPICTL1.all & (~(QSPICTL1_ALL_ADDRPIN_Msk | QSPICTL1_ALL_DATAPIN_Msk | QSPICTL1_ALL_BYTELEN_Msk))) | 
                        (QSPICTL1_ALL_ADDRPIN_1_PIN | QSPICTL1_ALL_DATAPIN_1_PIN | QSPICTL1_ALL_BYTELEN_1_BYTE));
  
  /* Set instruction */
  QSPI->QSPICMD.all = FLASH_INS_CODE_SRRD;
  
  /* Set QSPI read */
  QSPI_StartReadTransfer();
    
  for(i = 0; i < u32NumBytes; i++)
  {
    pu8Buf[i] = QSPI_ReadByte();
    
    readBytes++;
  }
  
  /* Disable QSPI */
  QSPI_SSDisable();
  
  return readBytes;
}




/****************************************************************************//**
 * @brief      Write data to OTP flash within a page
 *
 * @param[in]  pu8Buf     :  Buffer data to be programmed to OTP flash
 * @param[in]  u32Addr    :  OTP flash address
 * @param[in]  u32NumBytes:  Number of byte data to be programmed
 *
 * @return     SUCCESS or ERROR
 *
 *******************************************************************************/
ErrorStatus FLASH_WriteOTP(uint8_t *pu8Buf, uint32_t u32Addr, uint32_t u32NumBytes)
{
  uint32_t i;
  volatile uint32_t localCnt = 0;
  
  /* Actual OTP Flash address */
  uint32_t u32OTPAddr;
  
  /* Flash Manufacturer ID */
  uint32_t u32MID;
  
  
  /* OTP Flash address */
  u32OTPAddr = u32Addr;
  
  /* Get Flash Manufacturer UID */
  u32MID = FLASH_GetManufacturerID();
  
  /* GigaDevice Flash */
  if((u32MID & 0x00FF0000) == 0x00C80000)
  {
    /* Remap OTP2 Flash address */
    if((u32Addr >= FLASH_OTP2_ADDR) && (u32Addr < (FLASH_OTP2_ADDR + 512U)))
    {
      u32OTPAddr -= FLASH_OTP2_ADDR;
    }
    /* GigaDevice Flash does not have OTP3 */
    else if(u32Addr >= FLASH_OTP3_ADDR)
    {
      return ERROR;
    }
  }
  
  
  /* Enable flash write */
  FLASH_WriteEnable();
  
  /* Set Header count */
  QSPI->QSPIHEADER.all = (QSPIHEADER_ALL_CMDCNT_1_BYTE | QSPIHEADER_ALL_ADDRCNT_3_BYTE);

  /* Set data in counter */
  QSPI->QSPIDINCNT.all = u32NumBytes;
  
  /* Set address */
  QSPI->QSPIADDR.all = u32OTPAddr;
  
  QSPI->QSPICTL1.all = ((QSPI->QSPICTL1.all & (~(QSPICTL1_ALL_ADDRPIN_Msk | QSPICTL1_ALL_DATAPIN_Msk | QSPICTL1_ALL_BYTELEN_Msk))) | 
                        (QSPICTL1_ALL_ADDRPIN_1_PIN | QSPICTL1_ALL_DATAPIN_1_PIN | QSPICTL1_ALL_BYTELEN_1_BYTE));
  
  /* Set instruction */
  QSPI->QSPICMD.all = FLASH_INS_CODE_SRP;
  
  /* Set QSPI write */
  QSPI_StartWriteTransfer();
    
  for (i = 0; i < u32NumBytes; i++) 
  {
    QSPI_WriteByte(pu8Buf[i]);
  }
  
  /* Stop QSPI transfer */
  QSPI_StopTransfer();
  
  while(localCnt++ < 1000000)
  {
    /* Check flash busy status */ 
    if(FLASH_GetBusyStatus() == RESET)
    {
      return SUCCESS;
    }
  }

  return ERROR;
}




/****************************************************************************//**
 * @brief      Lock OTP flash (For SPC1068 and SPC1068G)
 *
 * @param[in]  u16LockBitsVal:  OTP flash lock bits value
 *                               - \ref FLASH_OTP1_LOCK_BIT_Val (For SPINTROL only       )
 *                               - \ref FLASH_OTP2_LOCK_BIT_Val (For SPC1068 and SPC1068G)
 *                               - \ref FLASH_OTP3_LOCK_BIT_Val (For SPC1068 only        )
 *
 * @return     SUCCESS or ERROR
 *
 * @example    FLASH_LockOTP(FLASH_OTP2_LOCK_BIT_Val);
 *
 *******************************************************************************/
ErrorStatus FLASH_LockOTP(uint16_t u16LockBitsVal)
{
  ErrorStatus errorStatus = SUCCESS;
  uint16_t statusLow, statusHigh, statusWrite;
  
  /* OTP lock mask */
  uint16_t u16LockMask;
  
    /* Flash Manufacturer ID */
  uint32_t u32MID;
  
  
  u16LockMask = u16LockBitsVal;
  
  /* Get Flash Manufacturer UID */
  u32MID = FLASH_GetManufacturerID();
  
  /* GigaDevice Flash */
  if((u32MID & 0x00FF0000) == 0x00C80000)
  {
    /* OTP Flash 2 lock bit in Status Register is BIT10 in SPC1068G */
    if((u16LockBitsVal & FLASH_OTP2_LOCK_BIT_Val) != 0)
    {
      u16LockMask &= ~FLASH_OTP2_LOCK_BIT_Val;
      u16LockMask |= (0x1U << 10);
    }
    
    /* GigaDevice Flash does not have OTP3 */
    if((u16LockBitsVal & FLASH_OTP3_LOCK_BIT_Val) != 0)
    {
      return ERROR;
    }
  }
  
  
  statusLow = statusHigh = 0x0000;
  
  /* Read Status Register-1 */
  statusLow = FLASH_GetStatusL();
  
  /* Read Status Register-2 */
  statusHigh = FLASH_GetStatusH();
  
  /* Set Security Register Lock Bits */
  statusWrite = ((statusHigh << 8) | statusLow) | u16LockMask;
  
  /* Write Status register */
  errorStatus = FLASH_WriteStatus(statusWrite);
  
  return errorStatus;
}


/******************* (C) COPYRIGHT 2021 SPINTROL LIMITED CO. *****END OF FILE****/
