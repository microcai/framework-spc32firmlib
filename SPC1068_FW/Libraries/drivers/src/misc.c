/**************************************************************************//**
 * @file     misc.h
 * @brief    This file provides miscellaneous firmware functions.
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


#include "misc.h"




/**
 *  @brief  Access Key for writting register AIRCR
 */
#define AIRCR_VECTKEY_MASK    ((uint32_t)0x05FA0000)




/****************************************************************************//**
 * @brief      Configures the priority grouping: pre-emption priority and subpriority
 *
 * @param[in]  NVIC_PriorityGroup: specifies the priority grouping bits length.
 *             This parameter can be one of the following values:
 *              - \ref NVIC_PriorityGroup_0: 0 bits for pre-emption priority
 *                                           4 bits for subpriority
 *              - \ref NVIC_PriorityGroup_1: 1 bits for pre-emption priority
 *                                           3 bits for subpriority
 *              - \ref NVIC_PriorityGroup_2: 2 bits for pre-emption priority
 *                                           2 bits for subpriority
 *              - \ref NVIC_PriorityGroup_3: 3 bits for pre-emption priority
 *                                           1 bits for subpriority
 *              - \ref NVIC_PriorityGroup_4: 4 bits for pre-emption priority
 *                                           0 bits for subpriority
 *
 * @return     none
 *
 *******************************************************************************/
void NVIC_PriorityGroupConfig(uint32_t NVIC_PriorityGroup)
{
  /* Set the PRIGROUP[10:8] bits according to NVIC_PriorityGroup value */
  SCB->AIRCR = AIRCR_VECTKEY_MASK | NVIC_PriorityGroup;
}




/****************************************************************************//**
 * @brief      Initializes the NVIC peripheral according to the specified
 *             parameters in the NVIC_InitStruct
 *
 * @param[in]  NVIC_InitStruct: pointer to a NVIC_InitTypeDef structure that contains
 *             the configuration information for the specified NVIC peripheral.
 *
 * @return     none
 *
 *******************************************************************************/
void NVIC_Init(NVIC_InitTypeDef* NVIC_InitStruct)
{
  uint32_t tmppriority = 0x00, tmppre = 0x00, tmpsub = 0x0F;

  if (NVIC_InitStruct->NVIC_IRQChannelCmd != DISABLE)
  {
    /* Compute the Corresponding IRQ Priority */
    tmppriority = (0x700 - ((SCB->AIRCR) & (uint32_t)0x700))>> 0x08;
    tmppre = (0x4 - tmppriority);
    tmpsub = tmpsub >> tmppriority;

    tmppriority = (uint32_t)NVIC_InitStruct->NVIC_IRQChannelPreemptionPriority << tmppre;
    tmppriority |=  NVIC_InitStruct->NVIC_IRQChannelSubPriority & tmpsub;
    tmppriority = tmppriority << 0x04;
      
    NVIC->IP[NVIC_InitStruct->NVIC_IRQChannel] = tmppriority;

    /* Enable the Selected IRQ Channels */
    NVIC->ISER[NVIC_InitStruct->NVIC_IRQChannel >> 0x05] =
      (uint32_t)0x01 << (NVIC_InitStruct->NVIC_IRQChannel & (uint8_t)0x1F);
  }
  else
  {
    /* Disable the Selected IRQ Channels */
    NVIC->ICER[NVIC_InitStruct->NVIC_IRQChannel >> 0x05] =
      (uint32_t)0x01 << (NVIC_InitStruct->NVIC_IRQChannel & (uint8_t)0x1F);
  }
}




/****************************************************************************//**
 * @brief      Sets the vector table location and Offset
 *
 * @param[in]  NVIC_VectTab: specifies if the vector table is in RAM or FLASH memory.
 *             This parameter can be one of the following values:
 *              - \ref NVIC_VectTab_RAM
 *              - \ref NVIC_VectTab_FLASH
 * @param[in]  Offset: Vector Table base offset field.
 *                     This value must be a multiple of 0x100.
 *
 * @return     none
 *
 *******************************************************************************/
void NVIC_SetVectorTable(uint32_t NVIC_VectTab, uint32_t Offset)
{
  SCB->VTOR = NVIC_VectTab | (Offset & (uint32_t)0x1FFFFF80);
}


/******************* (C) COPYRIGHT 2021 SPINTROL LIMITED CO. *****END OF FILE****/
