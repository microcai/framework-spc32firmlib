/**************************************************************************//**
 * @file     gpio.h
 * @brief    GPIO driver module header file.
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


#ifndef GPIO_H
#define GPIO_H

#ifdef __cplusplus
extern "C" {
#endif


#include "spc1068.h"




/**
 *  @brief  GPIO Pinmux channel type definition 
 */
typedef enum
{
  PINMUX_CHANNEL_0                = 0,      /*!< GPIO pin mux channel 0 define */
  PINMUX_CHANNEL_1                = 1,      /*!< GPIO pin mux channel 1 define */
  PINMUX_CHANNEL_2                = 2,      /*!< GPIO pin mux channel 2 define */
  PINMUX_CHANNEL_3                = 3,      /*!< GPIO pin mux channel 3 define */
  PINMUX_CHANNEL_4                = 4,      /*!< GPIO pin mux channel 4 define */
  PINMUX_CHANNEL_5                = 5,      /*!< GPIO pin mux channel 5 define */
  PINMUX_CHANNEL_6                = 6,      /*!< GPIO pin mux channel 6 define */
  PINMUX_CHANNEL_7                = 7,      /*!< GPIO pin mux channel 7 define */
} GPIO_PinMuxChannelEnum;




/**
 *  @brief  GPIO data direction type definition
 */
typedef enum
{
  GPIO_INPUT                      = 0,      /*!< Set GPIO port data direction as input  */
  GPIO_OUTPUT                     = 1,      /*!< Set GPIO port data direction as output */
} GPIO_DirEnum;




/**
 *  @brief  GPIO data Input/Output type definition
 */
typedef enum
{
  GPIO_LEVEL_LOW                  = 0,      /*!< Set GPIO port data Input/Output value as low  */
  GPIO_LEVEL_HIGH                 = 1,      /*!< Set GPIO port data Input/Output value as high */
} GPIO_LevelEnum;




/**
 *  @brief  GPIO edge detection type definition
 */
typedef enum
{
  GPIO_INT_RISING_EDGE            = 0,      /*!< Rising edge detection                  */
  GPIO_INT_FALLING_EDGE           = 1,      /*!< Falling edge detection                 */
  GPIO_INT_BOTH_EDGES             = 2,      /*!< Rising edge and Falling edge detection */
  GPIO_INT_IGNORE_EDGE            = 3,      /*!< Disable edge detection                 */
} GPIO_EdgeIntEnum;




/**
 *  @brief  GPIO deglitch window size definition
 */
typedef enum
{
  GPIO_DEGLITCH_WINDOW_1          = 0,      /*!< De-glitch clock divide 1   from PCLK     */
  GPIO_DEGLITCH_WINDOW_2          = 1,      /*!< De-glitch clock divide 2   from PCLK     */
  GPIO_DEGLITCH_WINDOW_4          = 2,      /*!< De-glitch clock divide 4   from PCLK     */
  GPIO_DEGLITCH_WINDOW_8          = 3,      /*!< De-glitch clock divide 8   from PCLK     */
  GPIO_DEGLITCH_WINDOW_16         = 4,      /*!< De-glitch clock divide 16  from PCLK     */
  GPIO_DEGLITCH_WINDOW_32         = 5,      /*!< De-glitch clock divide 32  from PCLK     */
  GPIO_DEGLITCH_WINDOW_64         = 6,      /*!< De-glitch clock divide 64  from PCLK     */
  GPIO_DEGLITCH_WINDOW_128        = 7,      /*!< De-glitch clock divide 128 from PCLK     */
} GPIO_DeglitchWindowEnum;




/**
 *  @brief  GPIO0 pinmux function define
 */
#define GPIO0_GPIO0               PINMUX_CHANNEL_0
#define GPIO0_UART_TXD            PINMUX_CHANNEL_1
#define GPIO0_I2C_SCL             PINMUX_CHANNEL_2




/**
 *  @brief  GPIO1 pinmux function define
 */
#define GPIO1_ADC0                PINMUX_CHANNEL_0
#define GPIO1_GPIO1               PINMUX_CHANNEL_1
#define GPIO1_PWMSYNCI            PINMUX_CHANNEL_2
#define GPIO1_PWMSYNCO            PINMUX_CHANNEL_3
#define GPIO1_I2C_SDA             PINMUX_CHANNEL_4




/**
 *  @brief  GPIO2 pinmux function define
 */
#define GPIO2_ADC1                PINMUX_CHANNEL_0
#define GPIO2_GPIO2               PINMUX_CHANNEL_1
#define GPIO2_PWM5B               PINMUX_CHANNEL_2




/**
 *  @brief  GPIO3 pinmux function define
 */
#define GPIO3_ADC2                PINMUX_CHANNEL_0
#define GPIO3_GPIO3               PINMUX_CHANNEL_1
#define GPIO3_PWM5A               PINMUX_CHANNEL_2




/**
 *  @brief  GPIO4 pinmux function define
 */
#define GPIO4_ADC3                PINMUX_CHANNEL_0
#define GPIO4_GPIO4               PINMUX_CHANNEL_1
#define GPIO4_PWM6B               PINMUX_CHANNEL_2




/**
 *  @brief  GPIO5 pinmux function define
 */
#define GPIO5_ADC4                PINMUX_CHANNEL_0
#define GPIO5_GPIO5               PINMUX_CHANNEL_1
#define GPIO5_PWM6A               PINMUX_CHANNEL_2




/**
 *  @brief  GPIO6 pinmux function define
 */
#define GPIO6_ADC5                PINMUX_CHANNEL_0
#define GPIO6_GPIO6               PINMUX_CHANNEL_1
#define GPIO6_PWM4B               PINMUX_CHANNEL_2


/**
 *  @brief  GPIO7 pinmux function define
 */
#define GPIO7_ADC6                PINMUX_CHANNEL_0
#define GPIO7_GPIO7               PINMUX_CHANNEL_1
#define GPIO7_PWM4A               PINMUX_CHANNEL_2




/**
 *  @brief  GPIO8 pinmux function define
 */
#define GPIO8_ADC7                PINMUX_CHANNEL_0
#define GPIO8_GPIO8               PINMUX_CHANNEL_1
#define GPIO8_PWM4A               PINMUX_CHANNEL_2
#define GPIO8_COMP0HOUT           PINMUX_CHANNEL_3




/**
 *  @brief  GPIO9 pinmux function define
 */
#define GPIO9_ADC8                PINMUX_CHANNEL_0
#define GPIO9_GPIO9               PINMUX_CHANNEL_1
#define GPIO9_PWM4B               PINMUX_CHANNEL_2
#define GPIO9_COMP1HOUT           PINMUX_CHANNEL_3




/**
 *  @brief  GPIO10 pinmux function define
 */
#define GPIO10_ADC9               PINMUX_CHANNEL_0
#define GPIO10_GPIO10             PINMUX_CHANNEL_1
#define GPIO10_PWM6A              PINMUX_CHANNEL_2
#define GPIO10_COMP2HOUT          PINMUX_CHANNEL_3




/**
 *  @brief  GPIO11 pinmux function define
 */
#define GPIO11_ADC10              PINMUX_CHANNEL_0
#define GPIO11_GPIO11             PINMUX_CHANNEL_1
#define GPIO11_PWM6B              PINMUX_CHANNEL_2
#define GPIO11_COMP0LOUT          PINMUX_CHANNEL_3




/**
 *  @brief  GPIO12 pinmux function define
 */
#define GPIO12_ADC11              PINMUX_CHANNEL_0
#define GPIO12_GPIO12             PINMUX_CHANNEL_1
#define GPIO12_PWM5A              PINMUX_CHANNEL_2
#define GPIO12_COMP1LOUT          PINMUX_CHANNEL_3




/**
 *  @brief  GPIO13 pinmux function define
 */
#define GPIO13_ADC12              PINMUX_CHANNEL_0
#define GPIO13_GPIO13             PINMUX_CHANNEL_1
#define GPIO13_PWM5B              PINMUX_CHANNEL_2
#define GPIO13_COMP2LOUT          PINMUX_CHANNEL_3




/**
 *  @brief  GPIO14 pinmux function define
 */
#define GPIO14_ADC13              PINMUX_CHANNEL_0
#define GPIO14_GPIO14             PINMUX_CHANNEL_1




/**
 *  @brief  GPIO15 pinmux function define
 */
#define GPIO15_ADC14              PINMUX_CHANNEL_0
#define GPIO15_GPIO15             PINMUX_CHANNEL_1
#define GPIO15_TDI                PINMUX_CHANNEL_2




/**
 *  @brief  GPIO16 pinmux function define
 */
#define GPIO16_ADC15              PINMUX_CHANNEL_0
#define GPIO16_GPIO16             PINMUX_CHANNEL_1
#define GPIO16_TMS                PINMUX_CHANNEL_2
#define GPIO16_SWD                PINMUX_CHANNEL_2




/**
 *  @brief  GPIO17 pinmux function define
 */
#define GPIO17_GPIO17             PINMUX_CHANNEL_0
#define GPIO17_TDO                PINMUX_CHANNEL_2
#define GPIO17_TMS                PINMUX_CHANNEL_3
#define GPIO17_SWD                PINMUX_CHANNEL_3
#define GPIO17_SPI_FRM            PINMUX_CHANNEL_5
#define GPIO17_PWM6B              PINMUX_CHANNEL_6




/**
 *  @brief  GPIO18 pinmux function define
 */
#define GPIO18_GPIO18             PINMUX_CHANNEL_0
#define GPIO18_SPI_MO             PINMUX_CHANNEL_1
#define GPIO18_TCK                PINMUX_CHANNEL_2
#define GPIO18_SWCK               PINMUX_CHANNEL_2
#define GPIO18_I2C_SDA            PINMUX_CHANNEL_4
#define GPIO18_SPI_MI             PINMUX_CHANNEL_5
#define GPIO18_PWM6A              PINMUX_CHANNEL_6




/**
 *  @brief  GPIO19 pinmux function define
 */
#define GPIO19_GPIO19             PINMUX_CHANNEL_0
#define GPIO19_SPI_CLK            PINMUX_CHANNEL_1
#define GPIO19_UART_TXD           PINMUX_CHANNEL_2
#define GPIO19_CLK_TEST           PINMUX_CHANNEL_3
#define GPIO19_I2C_SCL            PINMUX_CHANNEL_4
#define GPIO19_PWM5B              PINMUX_CHANNEL_6




/**
 *  @brief  GPIO20 pinmux function define
 */
#define GPIO20_GPIO20             PINMUX_CHANNEL_0
#define GPIO20_SPI_FRM            PINMUX_CHANNEL_2
#define GPIO20_UART_RXD           PINMUX_CHANNEL_3
#define GPIO20_PWM5A              PINMUX_CHANNEL_6




/**
 *  @brief  GPIO21 pinmux function define
 */
#define GPIO21_GPIO21             PINMUX_CHANNEL_0
#define GPIO21_SPI_MI             PINMUX_CHANNEL_1
#define GPIO21_SPI_SO             PINMUX_CHANNEL_2
#define GPIO21_PWM4B              PINMUX_CHANNEL_6




/**
 *  @brief  GPIO22 pinmux function define
 */
#define GPIO22_GPIO22             PINMUX_CHANNEL_0
#define GPIO22_SPI_MO             PINMUX_CHANNEL_1
#define GPIO22_SPI_SI             PINMUX_CHANNEL_2
#define GPIO22_PWM4A              PINMUX_CHANNEL_6




/**
 *  @brief  GPIO23 pinmux function define
 */
#define GPIO23_GPIO23             PINMUX_CHANNEL_0
#define GPIO23_PWM0B              PINMUX_CHANNEL_1
#define GPIO23_COMPLOUT           PINMUX_CHANNEL_2




/**
 *  @brief  GPIO24 pinmux function define
 */
#define GPIO24_GPIO24             PINMUX_CHANNEL_0
#define GPIO24_PWM0A              PINMUX_CHANNEL_1
#define GPIO24_ATEST              PINMUX_CHANNEL_2




/**
 *  @brief  GPIO25 pinmux function define
 */
#define GPIO25_TEST               PINMUX_CHANNEL_0
#define GPIO25_GPIO25             PINMUX_CHANNEL_1




/**
 *  @brief  GPIO26 pinmux function define
 */
#define GPIO26_GPIO26             PINMUX_CHANNEL_0
#define GPIO26_I2C_SDA            PINMUX_CHANNEL_1
#define GPIO26_PWMSYNCI           PINMUX_CHANNEL_2
#define GPIO26_ADCSOCAO           PINMUX_CHANNEL_3




/**
 *  @brief  GPIO27 pinmux function define
 */
#define GPIO27_GPIO27             PINMUX_CHANNEL_0
#define GPIO27_I2C_SCL            PINMUX_CHANNEL_1
#define GPIO27_PWMSYNCO           PINMUX_CHANNEL_2
#define GPIO27_ADCSOCBO           PINMUX_CHANNEL_3




/**
 *  @brief  GPIO28 pinmux function define
 */
#define GPIO28_GPIO28             PINMUX_CHANNEL_0
#define GPIO28_PWM1A              PINMUX_CHANNEL_1
#define GPIO28_TDI                PINMUX_CHANNEL_4




/**
 *  @brief  GPIO29 pinmux function define
 */
#define GPIO29_GPIO29             PINMUX_CHANNEL_0
#define GPIO29_PWM1B              PINMUX_CHANNEL_1
#define GPIO29_COMP0HOUT          PINMUX_CHANNEL_2
#define GPIO29_TDO                PINMUX_CHANNEL_4




/**
 *  @brief  GPIO30 pinmux function define
 */
#define GPIO30_GPIO30             PINMUX_CHANNEL_0
#define GPIO30_PWM2A              PINMUX_CHANNEL_1
#define GPIO30_TMS                PINMUX_CHANNEL_4
#define GPIO30_SWD                PINMUX_CHANNEL_4




/**
 *  @brief  GPIO31 pinmux function define
 */
#define GPIO31_GPIO31             PINMUX_CHANNEL_0
#define GPIO31_PWM2B              PINMUX_CHANNEL_1
#define GPIO31_TCK                PINMUX_CHANNEL_4
#define GPIO31_SWCK               PINMUX_CHANNEL_4




/**
 *  @brief  GPIO32 pinmux function define
 */
#define GPIO32_GPIO32             PINMUX_CHANNEL_0
#define GPIO32_PWM3A              PINMUX_CHANNEL_1
#define GPIO32_PWMSYNCI           PINMUX_CHANNEL_2
#define GPIO32_PWMSYNCO           PINMUX_CHANNEL_3
#define GPIO32_SPI_CLK            PINMUX_CHANNEL_4




/**
 *  @brief  GPIO33 pinmux function define
 */
#define GPIO33_GPIO33             PINMUX_CHANNEL_0
#define GPIO33_PWM3B              PINMUX_CHANNEL_1
#define GPIO33_UART_RXD           PINMUX_CHANNEL_2
#define GPIO33_SPI_FRM            PINMUX_CHANNEL_4




/**
 *  @brief  GPIO34 pinmux function define
 */
#define GPIO34_GPIO34             PINMUX_CHANNEL_0
#define GPIO34_UART_TXD           PINMUX_CHANNEL_1
#define GPIO34_UART_RXD           PINMUX_CHANNEL_3




/**
 *  @brief  GPIO35 pinmux function define
 */
#define GPIO35_GPIO35             PINMUX_CHANNEL_0
#define GPIO35_UART_RXD           PINMUX_CHANNEL_1
#define GPIO35_I2C_SDA            PINMUX_CHANNEL_2
#define GPIO35_UART_TXD           PINMUX_CHANNEL_3




/****************************************************************************//**
 * @brief      Get Global GPIO Pin Port and Index
 *
 * @param[in]  ePinNum:  Select the GPIO pin, should be GPIO_PinEnum
 *
 * @return     none
 *
 *******************************************************************************/
#define GlobalPinPort(ePinNum)              (((ePinNum) < GPIO_18)? 0 : 1)
#define GlobalPinIndex(ePinNum)             (((ePinNum) < GPIO_18)? (ePinNum) : ((ePinNum) - GPIO_18))




/****************************************************************************//**
 * @brief      Get GPIO pin port and index
 *
 * @param[in]  ePinNum:  Select the GPIO pin, should be GPIO_PinEnum
 *
 * @return     none
 *
 *******************************************************************************/
#define GpioPinPort(ePinNum)                ((ePinNum) >> (5UL))
#define GpioPinIndex(ePinNum)               ((ePinNum) & (0x1FUL))




/****************************************************************************//**
 * @brief      GPIO Pin Configuration Register define
 *
 * @param[in]  ePinNum:  Select the GPIO pin, should be GPIO_PinEnum
 *
 * @return     none
 *
 *******************************************************************************/
#define PinmuxGpioOffset(ePinNum)           (((ePinNum) == GPIO_0)? ((ePinNum) * 4) : (((ePinNum) + 1) * 4))
#define PINMUX_GPIO(ePinNum)                ((__IO GPIO0_REG*)(PINMUX_BASE + PinmuxGpioOffset(ePinNum)))




/****************************************************************************//**
 * @brief      Set GPIO pin channel
 *
 * @param[in]  ePinNum :  Select the GPIO pin, should be GPIO_PinEnum
 * @param[in]  eChannel:  GPIO pin channel, should be GPIO_PinMuxChannelEnum
 *
 * @return     none
 *
 *******************************************************************************/
#define GPIO_SetPinChannel(ePinNum,eChannel)    (PINMUX_GPIO(ePinNum)->bit.MUXSEL = (eChannel & 0x07))




/****************************************************************************//**
 * @brief      Enable GPIO pin pull-up
 *
 * @param[in]  ePinNum :  Select the GPIO pin, should be GPIO_PinEnum
 * @param[in]  eChannel:  GPIO pin channel, should be GPIO_PinMuxChannelEnum
 *
 * @return     none
 *
 *******************************************************************************/
#define GPIO_EnablePullup(ePinNum,eChannel)     (PINMUX_GPIO(ePinNum)->bit.NPU &= (~(0x01 << eChannel)))




/****************************************************************************//**
 * @brief      Disable GPIO pin pull-up
 *
 * @param[in]  ePinNum :  Select the GPIO pin, should be GPIO_PinEnum
 * @param[in]  eChannel:  GPIO pin channel, should be GPIO_PinMuxChannelEnum
 *
 * @return     none
 *
 *******************************************************************************/
#define GPIO_DisablePullup(ePinNum,eChannel)    (PINMUX_GPIO(ePinNum)->bit.NPU |= (0x01 << eChannel))




/****************************************************************************//**
 * @brief      Enable GPIO pin deglitch filter
 *
 * @param[in]  ePinNum:  Select the GPIO pin, should be GPIO_PinEnum
 *
 * @return     none
 *
 *******************************************************************************/
#define GPIO_EnableDeglitch(ePinNum)        (PINMUX_GPIO(ePinNum)->bit.DEGLITCH = 1)




/****************************************************************************//**
 * @brief      Disable GPIO pin deglitch filter
 *
 * @param[in]  ePinNum:  Select the GPIO pin, should be GPIO_PinEnum
 *
 * @return     none
 *
 *******************************************************************************/
#define GPIO_DisableDeglitch(ePinNum)       (PINMUX_GPIO(ePinNum)->bit.DEGLITCH = 0)




/****************************************************************************//**
 * @brief      Set GPIO pin deglitch window size
 *
 * @param[in]  eWindow:  Deglitch window size, should be GPIO_DeglitchWindowEnum
 *
 * @return     none
 *
 *******************************************************************************/
#define GPIO_SetDeglitchWindow(eWindow)     (CLOCK->DGCLKCTL.all = (eWindow))




/****************************************************************************//**
 * @brief      Write one GPIO pin output
 *
 * @param[in]  ePinNum:  Select the GPIO pin, should be GPIO_PinEnum
 * @param[in]  eBitVal:  Value to be write to GPIO pin, should be GPIO_LevelEnum
 *                        - \ref GPIO_LEVEL_LOW
 *                        - \ref GPIO_LEVEL_HIGH
 *
 * @return     none
 *
 *******************************************************************************/
#define GPIO_WritePin(ePinNum,bitVal)       (*(volatile uint32_t*)(((uint32_t)(&GPIO->GPCR[0].all))+(GpioPinPort(ePinNum)<<2)- (bitVal * 12)) =( 0x01UL << GpioPinIndex(ePinNum)))




/****************************************************************************//**
 * @brief      Read one GPIO pin level of input or output
 *
 * @param[in]  ePinNum:  Select the GPIO pin, should be GPIO_PinEnum
 *
 * @return     Value read from GPIO pin
 *             - \ref 0 : GPIO level is LOW
 *             - \ref 1 : GPIO level is HIGH
 *
 *******************************************************************************/
#define GpioGplrAddr(ePinNum)               ((uint32_t)(GPIO_BASE + (GpioPinPort(ePinNum) << 2)))
#define GPIO_ReadPin(ePinNum)               ((GPIO->GPLR[GpioPinPort(ePinNum)].all & (0x01 << GpioPinIndex(ePinNum)))? (1UL) : (0UL))
#define GPIO_ReadPinBitBand(ePinNum)        REG_BIT(GpioGplrAddr(ePinNum), GpioPinIndex(ePinNum))



/****************************************************************************//**
 * @brief      Toggle GPIO pin output value
 *
 * @param[in]  ePinNum:  Select the GPIO pin, should be GPIO_PinEnum
 *
 * @return     none
 *
 *******************************************************************************/
#define GPIO_TogglePin(ePinNum)             (GPIO_WritePin(ePinNum,!GPIO_ReadPin(ePinNum)))




/****************************************************************************//**
 * @brief      Enable GPIO edge detect
 *
 * @param[in]  pinNum:  Select the GPIO pin, should be GPIO_PinEnum
 *
 * @return     none
 *
 *******************************************************************************/
#define GPIO_EnableEdgeInt(ePinNum)         (GPIO->APMSK[GpioPinPort(ePinNum)].all |= (0x01 << GpioPinIndex(ePinNum)))




/****************************************************************************//**
 * @brief      Disable GPIO edge detect
 *
 * @param[in]  ePinNum:  Select the GPIO pin, should be GPIO_PinEnum
 *
 * @return     none
 *
 *******************************************************************************/
#define GPIO_DisableEdgeInt(ePinNum)        (GPIO->APMSK[GpioPinPort(ePinNum)].all &= (~(0x01 << GpioPinIndex(ePinNum))))




/****************************************************************************//**
 * @brief      Get GPIO edge detect status
 *
 * @param[in]  ePinNum:  Select the GPIO pin, should be GPIO_PinEnum
 *
 * @return     0 : No detected rising or falling edge
 *             1 : Edge was detected
 *
 *******************************************************************************/
#define GPIO_GetEdgeIntStatus(ePinNum)      ((GPIO->GEDR[GpioPinPort(ePinNum)].all & (0x01 << GpioPinIndex(ePinNum)))? (1UL) : (0UL))




/****************************************************************************//**
 * @brief      Clear GPIO edge detect status
 *
 * @param[in]  ePinNum:  Select the GPIO pin, should be GPIO_PinEnum
 *
 * @return     none
 *
 *******************************************************************************/
#define GPIO_ClearEdgeInt(ePinNum)          (GPIO->GEDR[GpioPinPort(ePinNum)].all = (0x01 << GpioPinIndex(ePinNum)))




/****************************************************************************//**
 * @brief      Enable GPIO level triggered interrupt
 *
 * @param[in]  ePinNum:  Select the GPIO pin, should be GPIO_PinEnum
 *
 * @return     none
 *
 *******************************************************************************/
#define GPIO_EnableLevelInt(ePinNum)        (GLOBAL->GPIOIE[GlobalPinPort(ePinNum)].all |= (0x01 << GlobalPinIndex(ePinNum)))




/****************************************************************************//**
 * @brief      Disable GPIO level triggered interrupt
 *
 * @param[in]  ePinNum:  Select the GPIO pin.
 *
 * @return     none
 *
 *******************************************************************************/
#define GPIO_DisableLevelInt(ePinNum)       (GLOBAL->GPIOIE[GlobalPinPort(ePinNum)].all &= (~(0x01 << GlobalPinIndex(ePinNum))))




/****************************************************************************//**
 * @brief      Clear GPIO level triggered interrupt
 *
 * @param[in]  ePinNum:  Select the GPIO pin, should be GPIO_PinEnum
 *
 * @return     none
 *
 * @note       This function will clear the selected GPIO pin level interrupt and
 *             release other GPIO pins level interrupt clear
 *
 *******************************************************************************/
#define GPIO_ClearLevelInt(ePinNum)         (GLOBAL->GPIOIC[GlobalPinPort(ePinNum)].all = (0x01 << GlobalPinIndex(ePinNum)))




/****************************************************************************//**
 * @brief      Release clear level triggered interrupt
 *
 * @param[in]  ePinNum:  Select the GPIO pin, should be GPIO_PinEnum
 *
 * @return     none
 *
 * @note       This function will release all GPIO pin level interrupt clear
 *
 *******************************************************************************/
#define GPIO_ClearLevelIntRelease(ePinNum)  (GLOBAL->GPIOIC[GlobalPinPort(ePinNum)].all = 0)




/****************************************************************************//**
 * @brief      Force level triggered interrupt
 *
 * @param[in]  ePinNum:  Select the GPIO pin, should be GPIO_PinEnum
 *
 * @return     none
 *
 *******************************************************************************/
#define GPIO_ForceLevelInt(ePinNum)         (GLOBAL->GPIOIFRC[GlobalPinPort(ePinNum)].all |= (0x01 << GlobalPinIndex(ePinNum)))




/****************************************************************************//**
 * @brief      Release Force level triggered interrupt
 *
 * @param[in]  ePinNum:  Select the GPIO pin, should be GPIO_PinEnum
 *
 * @return     none
 *
 *******************************************************************************/
#define GPIO_ForceLevelIntRelease(ePinNum)  (GLOBAL->GPIOIFRC[GlobalPinPort(ePinNum)].all &= (~(0x01 << GlobalPinIndex(ePinNum))))



/****************************************************************************//**
 * @brief      Interrupt triggered when GPIO level is high
 *
 * @param[in]  ePinNum:  Select the GPIO pin, should be GPIO_PinEnum
 *
 * @return     none
 *
 *******************************************************************************/
#define GPIO_LevelIntActiveHigh(ePinNum)    (GLOBAL->GPIOINTINV[GlobalPinPort(ePinNum)].all &= (~(0x01 << GlobalPinIndex(ePinNum))))




/****************************************************************************//**
 * @brief      Interrupt triggered when GPIO level is low
 *
 * @param[in]  ePinNum:  Select the GPIO pin, should be GPIO_PinEnum
 *
 * @return     none
 *
 *******************************************************************************/
#define GPIO_LevelIntActiveLow(ePinNum)     (GLOBAL->GPIOINTINV[GlobalPinPort(ePinNum)].all |= (0x01 << GlobalPinIndex(ePinNum)))




/****************************************************************************//**
 * @brief      Get level triggered interrupt polarity
 *
 * @param[in]  ePinNum:  Select the GPIO pin, should be GPIO_PinEnum
 *
 * @return    0 : Interrupt triggered when GPIO level is HIGH
 *            1 : Interrupt triggered when GPIO level is LOW
 *
 *******************************************************************************/
#define GPIO_GetLevelIntPol(ePinNum)        ((GLOBAL->GPIOINTINV[GlobalPinPort(ePinNum)].all & (0x01 << GlobalPinIndex(ePinNum)))? (1) : (0))




/****************************************************************************//**
 * @brief      Get level triggered interrupt status
 *
 * @param[in]  ePinNum:  Select the GPIO pin, should be GPIO_PinEnum
 *
 * @return    0 : No level interrupt was detected
 *            1 : A level interrupt was detected
 *
 *******************************************************************************/
#define GPIO_GetLevelIntStatus(ePinNum)     ((GLOBAL->GPIOIC[GlobalPinPort(ePinNum)].all & (0x01 << GlobalPinIndex(ePinNum)))? (1UL) : (0UL))




/**
 *  @brief GPIO Public Function Declaration
 */
void GPIO_SetPinAsGPIO(GPIO_PinEnum ePinNum);
void GPIO_SetPinAsAnalog(GPIO_PinEnum ePinNum);
void GPIO_SetPinDir(GPIO_PinEnum ePinNum, GPIO_DirEnum eDir);
void GPIO_ResetAllPin(void);

void GPIO_SetEdgeIntMode(GPIO_PinEnum ePinNum, GPIO_EdgeIntEnum eIntType);


#ifdef __cplusplus
}
#endif /* extern "C" */

#endif /* GPIO_H */


/******************* (C) COPYRIGHT 2021 SPINTROL LIMITED CO. *****END OF FILE****/
