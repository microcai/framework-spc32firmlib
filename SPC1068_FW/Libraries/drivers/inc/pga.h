/*******************************************************************************
* @file     pga.h
* @brief    PGA driver header file.
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


#ifndef PGA_H
#define PGA_H

#ifdef __cplusplus
extern "C" {
#endif


#include "spc1068.h"




/**
 *  @brief  PGA selection
 */
typedef enum
{ 
  PGA0                  = 0,                /*!< PGA 0                */
  PGA1                  = 1,                /*!< PGA 1                */
  PGA2                  = 2                 /*!< PGA 2                */
} PGA_NumEnum;




/**
 *  @brief  Input channel selection for PGA 0 "Positive"
 */
typedef enum
{ 
  PGA0_CH_P_VSSA        = 0x00,             /*!< GND                  */
  PGA0_CH_P_VDDR12_ANA  = 0x01,             /*!< VDDR12_ANA           */
  PGA0_CH_P_ADC5        = 0x02,             /*!< GPIO6                */
  PGA0_CH_P_ADC9        = 0x03,             /*!< GPIO10               */
  PGA0_CH_P_ADC2        = 0x04,             /*!< GPIO3                */
  PGA0_CH_P_ADC7        = 0x05,             /*!< GPIO8                */
  PGA0_CH_P_ADC14       = 0x06,             /*!< GPIO15               */
  PGA0_CH_P_RESDIV0     = 0x07,             /*!<                      */
  PGA1_CH_P_VSSA        = 0x10,             /*!< GND                  */
  PGA1_CH_P_DAC_HI      = 0x11,             /*!< DAC High             */
  PGA1_CH_P_ADC1        = 0x12,             /*!< GPIO2                */
  PGA1_CH_P_ADC11       = 0x13,             /*!< GPIO12               */
  PGA1_CH_P_ADC4        = 0x14,             /*!< GPIO5                */
  PGA1_CH_P_ADC7        = 0x15,             /*!< GPIO8                */
  PGA1_CH_P_ADC14       = 0x16,             /*!< GPIO15               */
  PGA1_CH_P_RESDIV1     = 0x17,             /*!<                      */
  PGA2_CH_P_VSSA        = 0x20,             /*!< GND                  */
  PGA2_CH_P_TSENSE1     = 0x21,             /*!< T-sensor out 1       */
  PGA2_CH_P_ADC3        = 0x22,             /*!< GPIO4                */
  PGA2_CH_P_ADC13       = 0x23,             /*!< GPIO14               */
  PGA2_CH_P_ADC6        = 0x24,             /*!< GPIO7                */
  PGA2_CH_P_ADC7        = 0x25,             /*!< GPIO8                */
  PGA2_CH_P_ADC14       = 0x26,             /*!< GPIO15               */
  PGA2_CH_P_RESDIV2     = 0x27              /*!<                      */
} PGA_CH_P;




/**
 *  @brief  Input channel selection for PGA 0 "Negative"
 */
typedef enum
{ 
  PGA0_CH_N_VSSA        = 0x50,             /*!< GND                  */
  PGA0_CH_N_TEST        = 0x51,             /*!< GPIO25               */
  PGA0_CH_N_ADC9        = 0x52,             /*!< GPIO10               */
  PGA0_CH_N_ADC8        = 0x53,             /*!< GPIO9                */
  PGA0_CH_N_ADC1        = 0x54,             /*!< GPIO2                */
  PGA0_CH_N_ADC0        = 0x55,             /*!< GPIO1                */
  PGA0_CH_N_ADC15       = 0x56,             /*!< GPIO16               */
  PGA0_CH_N_RESDIV0     = 0x57,             /*!< RESDIV0              */
  PGA1_CH_N_VSSA        = 0x40,             /*!< GND                  */
  PGA1_CH_N_ADC_1dot2   = 0x41,             /*!< ADC 1.2V Reference   */
  PGA1_CH_N_ADC8        = 0x42,             /*!< GPIO9                */
  PGA1_CH_N_ADC10       = 0x43,             /*!< GPIO11               */
  PGA1_CH_N_ADC3        = 0x44,             /*!< GPIO4                */
  PGA1_CH_N_ADC0        = 0x45,             /*!< GPIO1                */
  PGA1_CH_N_ADC15       = 0x46,             /*!< GPIO16               */
  PGA1_CH_N_RESDIV1     = 0x47,             /*!< RESDIV1              */
  PGA2_CH_N_VSSA        = 0x30,             /*!< GND                  */
  PGA2_CH_N_TSENSE0     = 0x31,             /*!< T-sensor out 0       */
  PGA2_CH_N_ADC10       = 0x32,             /*!< GPIO11               */
  PGA2_CH_N_ADC12       = 0x33,             /*!< GPIO13               */
  PGA2_CH_N_ADC5        = 0x34,             /*!< GPIO6                */
  PGA2_CH_N_ADC0        = 0x35,             /*!< GPIO1                */
  PGA2_CH_N_ADC15       = 0x36,             /*!< GPIO16               */
  PGA2_CH_N_RESDIV2     = 0x37              /*!< RESDIV2              */
} PGA_CH_N;




/**
 *  @brief  PGA Gain
 */
typedef enum
{ 
  PGA_SCALE_4X          = 0,
  PGA_SCALE_8X          = 1,
  PGA_SCALE_16X         = 2,
  PGA_SCALE_32X         = 3
} PGA_SCALE;




/**
 *  @brief  PGA Public Function Declaration
 */
void PGA_DiffInit(PGA_NumEnum ePGANo, PGA_CH_P u8PChannelNo, PGA_CH_N u8NChannelNo, PGA_SCALE u8ScaleNo);
void PGA_ResistorDividerConifg(PGA_NumEnum ePGANo, uint8_t u8ResistDividerValue);
void PGA_SelecPositiveCHAsComInput(PGA_NumEnum ePGANo);
void PGA_SelecNegativeCHAsComInput(PGA_NumEnum ePGANo);



#ifdef __cplusplus
}
#endif /* extern "C" */

#endif /* PGA_H */


/******************* (C) COPYRIGHT 2021 SPINTROL LIMITED CO. *****END OF FILE****/
