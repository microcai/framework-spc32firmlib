/**************************************************************************//**
 * @file     flash.h
 * @brief    Internal flash driver header file.
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

#ifndef FLASH_H
#define FLASH_H

#ifdef __cplusplus
extern "C" {
#endif


#include "spc1068.h"




/**
 *  @brief  FLASH CONSTANTS
 */
#define FLASH_PAGE_SIZE           0x100     /*!< Flash Page Size - 256 bytes  */
#define FLASH_SECTOR_SIZE         0x1000    /*!< Flash Sector Size - 4KB      */
#define FLASH_32K_BLOCK_SIZE      0x8000    /*!< Flash Block32 Size - 32KB    */
#define FLASH_64K_BLOCK_SIZE      0x10000   /*!< Flash Block64 Size - 64KB    */
#define FLASH_CHIP_SIZE           0x80000   /*!< Flash Chip Size - 512KB      */




/**
 *  @brief  FLASH Security Register (OTP) Address
 */
#define FLASH_OTP1_ADDR           0x1000    /*!< Flash Security Register 1 Start Address (For SPINTROL only)        */
#define FLASH_OTP2_ADDR           0x2000    /*!< Flash Security Register 2 Start Address (For SPC1068 and SPC1068G) */
#define FLASH_OTP3_ADDR           0x3000    /*!< Flash Security Register 3 Start Address (For SPC1068 Only)         */




/**
 *  @brief  FLASH Security Register (OTP) Lock Bit (For SPC1068 and SPC1068G Only)
 */
#define FLASH_OTP1_LOCK_BIT_Pos   (11)
#define FLASH_OTP1_LOCK_BIT_Val   (1UL << FLASH_OTP1_LOCK_BIT_Pos)    /*!< Flash Security Register 1 Lock Mask (For SPINTROL only)        */

#define FLASH_OTP2_LOCK_BIT_Pos   (12)
#define FLASH_OTP2_LOCK_BIT_Val   (1UL << FLASH_OTP2_LOCK_BIT_Pos)    /*!< Flash Security Register 2 Lock Mask (For SPC1068 and SPC1068G) */

#define FLASH_OTP3_LOCK_BIT_Pos   (13)
#define FLASH_OTP3_LOCK_BIT_Val   (1UL << FLASH_OTP3_LOCK_BIT_Pos)    /*!< Flash Security Register 3 Lock Mask (For SPC1068 Only)         */




/**
 *  @brief  Flash last sector/block32/block64 number
 */
#define FLASH_LAST_SECTOR         ((FLASH_CHIP_SIZE/FLASH_SECTOR_SIZE) - 1)
#define FLASH_LAST_32K_BLOCK      ((FLASH_CHIP_SIZE/FLASH_32K_BLOCK_SIZE) - 1)
#define FLASH_LAST_64K_BLOCK      ((FLASH_CHIP_SIZE/FLASH_64K_BLOCK_SIZE) - 1)




/****************************************************************************//**
 * @brief      Get the page number according to the address
 *
 * @param[in]  addr:  Address within the flash
 *
 * @return     Page number
 *
*******************************************************************************/
#define FLASH_PAGE_NUM(addr)                ((addr)>>8)




/****************************************************************************//**
 * @brief      Get the page begin and end address according to the address
 *
 * @param[in]  addr:  Address within the flash
 *
 * @return     Page begin/end address
 *
*******************************************************************************/
#define FLASH_PAGE_BEGIN_ADDR(addr)         (FLASH_PAGE_SIZE * FLASH_PAGE_NUM(addr))
#define FLASH_PAGE_END_ADDR(addr)           (FLASH_PAGE_SIZE * (FLASH_PAGE_NUM(addr)+1) - 1)




/****************************************************************************//**
 * @brief      Get the sector number according to the address
 *
 * @param[in]  addr:  Address within the flash
 *
 * @return     Sector number
 *
*******************************************************************************/
#define FLASH_SECTOR_NUM(addr)              ((addr)>>12)




/****************************************************************************//**
 * @brief      Get the 32KB block number according to the address
 *
 * @param[in]  addr:  Address within the flash
 *
 * @return     32KB block number
 *
*******************************************************************************/
#define FLASH_BLOCK32_NUM(addr)             ((addr)>>15)




/****************************************************************************//**
 * @brief      Get the 64KB block number according to the address
 *
 * @param[in]  addr:  Address within the flash
 *
 * @return     64KB block number
 *
*******************************************************************************/
#define FLASH_BLOCK64_NUM(addr)             ((addr)>>16)




/**
 *  @brief  FLASH INSTRUCTIONS
 */
#define FLASH_INS_CODE_WE         0x06      /*!< Write enable               */
#define FLASH_INS_CODE_WE_VSR     0x50      /*!< Write enable for volatile status register */
#define FLASH_INS_CODE_WD         0x04      /*!< Write disable              */
#define FLASH_INS_CODE_RSR1       0x05      /*!< Read status register 1     */
#define FLASH_INS_CODE_RSR2       0x35      /*!< Read status register 2     */
#define FLASH_INS_CODE_WSR        0x01      /*!< Write status register      */
#define FLASH_INS_CODE_PP         0x02      /*!< Page program               */
#define FLASH_INS_CODE_QPP        0x32      /*!< Quad page program          */
#define FLASH_INS_CODE_SE         0x20      /*!< Sector(4k) erase           */
#define FLASH_INS_CODE_BE_32K     0x52      /*!< Block(32k) erase           */
#define FLASH_INS_CODE_BE_64K     0xD8      /*!< Block(64k) erase           */
#define FLASH_INS_CODE_CE         0xC7      /*!< Chip erase                 */
#define FLASH_INS_CODE_PD         0xB9      /*!< Power down                 */

#define FLASH_INS_CODE_RD         0x03      /*!< Read data                  */
#define FLASH_INS_CODE_FR         0x0B      /*!< Fast read                  */
#define FLASH_INS_CODE_FRDO       0x3B      /*!< Fast read dual output      */
#define FLASH_INS_CODE_FRQO       0x6B      /*!< Fast read quad output      */
#define FLASH_INS_CODE_FRDIO      0xBB      /*!< Fast read dual IO          */
#define FLASH_INS_CODE_FRQIO      0xEB      /*!< Fast read quad IO          */

#define FLASH_INS_CODE_RPD_DI     0xAB      /*!< Release power down or device ID */
#define FLASH_INS_CODE_RUID       0x4B      /*!< Read unique ID number      */
#define FLASH_INS_CODE_RMID       0x9F      /*!< Read manufacturer ID number     */

#define FLASH_INS_CODE_SRE        0x44      /*!< Security register erase    */
#define FLASH_INS_CODE_SRP        0x42      /*!< Security register program  */
#define FLASH_INS_CODE_SRRD       0x48      /*!< Security register read     */




/**
 *  @brief  FLASH protection type
 */
typedef enum
{
  FLASH_PROT_NONE                 = 0x00,   /*!< None protection                          */
  
  FLASH_PROT_UPPER_256KB          = 0xAC,   /*!< Protect upper 256KB  0x040000 ~ 0x07FFFF */
                                  
  FLASH_PROT_LOWER_64KB           = 0x24,   /*!< Protect lower 64KB   0x000000 ~ 0x00FFFF */
  FLASH_PROT_LOWER_128KB          = 0x28,   /*!< Protect lower 128KB  0x000000 ~ 0x01FFFF */
  FLASH_PROT_LOWER_256KB          = 0x2C,   /*!< Protect lower 256KB  0x000000 ~ 0x03FFFF */
  
  FLASH_PROT_ALL                  = 0x30,   /*!< Protect all          0x000000 ~ 0x07FFFF */

  FLASH_PROT_LOWER_4KB            = 0x64,   /*!< Protect lower 4KB    0x000000 ~ 0x000FFF */
  FLASH_PROT_LOWER_8KB            = 0x68,   /*!< Protect lower 8KB    0x000000 ~ 0x001FFF */
  FLASH_PROT_LOWER_16KB           = 0x6C,   /*!< Protect lower 16KB   0x000000 ~ 0x003FFF */
  FLASH_PROT_LOWER_32KB           = 0x70,   /*!< Protect lower 32KB   0x000000 ~ 0x007FFF */

  FLASH_PROT_UPPER_448KB          = 0xA4,   /*!< Protect upper 448KB  0x010000 ~ 0x07FFFF */
  FLASH_PROT_UPPER_384KB          = 0xA8,   /*!< Protect upper 384KB  0x020000 ~ 0x07FFFF */

  FLASH_PROT_UPPER_508KB          = 0xE4,   /*!< Protect upper 508KB  0x001000 ~ 0x07FFFF */
  FLASH_PROT_UPPER_504KB          = 0xE8,   /*!< Protect upper 504KB  0x002000 ~ 0x07FFFF */
  FLASH_PROT_UPPER_496KB          = 0xEC,   /*!< Protect upper 496KB  0x004000 ~ 0x07FFFF */
  FLASH_PROT_UPPER_480KB          = 0xF0,   /*!< Protect upper 480KB  0x008000 ~ 0x07FFFF */
} FLASH_ProtectionEnum;




/**
 *  @brief FLASH Public Function Declaration
 */
FlagStatus FLASH_GetBusyStatus(void);
ErrorStatus FLASH_SetProtectionMode(FLASH_ProtectionEnum eProtectMode);

ErrorStatus FLASH_EraseAll(void);
ErrorStatus FLASH_SectorErase(uint32_t u32SectorNum);
ErrorStatus FLASH_Block32KErase(uint32_t u32BlockNum);
ErrorStatus FLASH_Block64KErase(uint32_t u32BlockNum);
ErrorStatus FLASH_Erase(uint32_t u32StartAddr, uint32_t u32EndAddr);

uint32_t FLASH_Read(uint8_t *pu8Buf, uint32_t u32Addr, uint32_t u32NumBytes);
uint32_t FLASH_ReadWords(uint32_t *pu32Buf, uint32_t u32Addr, uint32_t u32NumWords);

ErrorStatus FLASH_WritePage(uint8_t *pu8Buf, uint32_t u32Addr, uint32_t u32NumBytes);
ErrorStatus FLASH_Write(uint8_t *pu8Buf, uint32_t u32Addr, uint32_t u32NumBytes);

ErrorStatus FLASH_EraseOTP(uint32_t u32Addr);
uint32_t FLASH_ReadOTP(uint8_t *pu8Buf, uint32_t u32Addr, uint32_t u32NumBytes);
ErrorStatus FLASH_WriteOTP(uint8_t *pu8Buf, uint32_t u32Addr, uint32_t u32NumBytes);
ErrorStatus FLASH_LockOTP(uint16_t u16LockBitsVal);

uint32_t FLASH_GetManufacturerID(void);


#ifdef __cplusplus
}
#endif /* extern "C" */

#endif /* FLASH_H */


/******************* (C) COPYRIGHT 2021 SPINTROL LIMITED CO. *****END OF FILE****/
