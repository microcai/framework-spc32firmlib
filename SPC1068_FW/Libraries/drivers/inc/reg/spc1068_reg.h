/**************************************************************************//**
 * @file     spc1068_reg.h
 * @brief    SPC1068 register structure definition.
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


#ifndef SPC1068_REG_H
#define SPC1068_REG_H

#ifdef __cplusplus
extern "C" {
#endif

#include "core_cm3.h"




/********************************************************************************
*
* Module Name     WDT1
*
*
********************************************************************************/



/**
 *  @brief  Union type to access the Watchdog Timer Load Register (WDTLOAD), offset 0x0.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label        */
        uint32_t VAL           :32;  /*!< bit: 31.. 0  WDTLOAD_BIT_VAL         */
    } bit;                           /*!< Structure used for bit  access       */
    uint32_t all;                    /*!< Type      used for word access       */
} WDTLOAD_REG;


/**
 *  @brief  Union type to access the Watchdog Timer Current Value Register (WDTCNT), offset 0x4.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label        */
        uint32_t VAL           :32;  /*!< bit: 31.. 0  WDTCNT_BIT_VAL          */
    } bit;                           /*!< Structure used for bit  access       */
    uint32_t all;                    /*!< Type      used for word access       */
} WDTCNT_REG;


/**
 *  @brief  Union type to access the Watchdog Timer Control Register (WDTCTL), offset 0x8.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label        */
        uint32_t INTEN         : 1;  /*!< bit:      0  WDTCTL_BIT_INTEN        */
        uint32_t RSTEN         : 1;  /*!< bit:      1  WDTCTL_BIT_RSTEN        */
        uint32_t RESERVED_31_2 :30;  /*!< bit: 31.. 2                          */
    } bit;                           /*!< Structure used for bit  access       */
    uint32_t all;                    /*!< Type      used for word access       */
} WDTCTL_REG;


/**
 *  @brief  Union type to access the Watchdog Timer Clear Interrupt Register  (WDTIC), offset 0xC.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label        */
        uint32_t VAL           :32;  /*!< bit: 31.. 0  WDTIC_BIT_VAL           */
    } bit;                           /*!< Structure used for bit  access       */
    uint32_t all;                    /*!< Type      used for word access       */
} WDTIC_REG;


/**
 *  @brief  Union type to access the Watchdog Timer Raw Interrupt Status Register (WDTRAWIF), offset 0x10.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label        */
        uint32_t RAWINT        : 1;  /*!< bit:      0  WDTRAWIF_BIT_RAWINT     */
        uint32_t RESERVED_2_1  : 2;  /*!< bit:  2.. 1                          */
        uint32_t RESERVED_31_3 :29;  /*!< bit: 31.. 3                          */
    } bit;                           /*!< Structure used for bit  access       */
    uint32_t all;                    /*!< Type      used for word access       */
} WDTRAWIF_REG;


/**
 *  @brief  Union type to access the Watchdog Timer Interrupt Status Register (WDTIF), offset 0x14.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label        */
        uint32_t INT           : 1;  /*!< bit:      0  WDTIF_BIT_INT           */
        uint32_t RESERVED_31_1 :31;  /*!< bit: 31.. 1                          */
    } bit;                           /*!< Structure used for bit  access       */
    uint32_t all;                    /*!< Type      used for word access       */
} WDTIF_REG;


/**
 *  @brief  Union type to access the Watchdog Timer Lock Register (WDTLOCK), offset 0x18.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label        */
        uint32_t LCKSTS        : 1;  /*!< bit:      0  WDTLOCK_BIT_LCKSTS      */
        uint32_t LCKCTL        :31;  /*!< bit: 31.. 1  WDTLOCK_BIT_LCKCTL      */
    } bit;                           /*!< Structure used for bit  access       */
    uint32_t all;                    /*!< Type      used for word access       */
} WDTLOCK_REG;





/**
  *  @brief  Structure type to access the WDT Controller (WDT).
  */
typedef struct
{
    __IO WDTLOAD_REG      WDTLOAD           ; /*!< Offset: 0x00000000 (RW  )  Watchdog Timer Load Register                  */
    __I  WDTCNT_REG       WDTCNT            ; /*!< Offset: 0x00000004 (RO  )  Watchdog Timer Current Value Register         */
    __IO WDTCTL_REG       WDTCTL            ; /*!< Offset: 0x00000008 (RW  )  Watchdog Timer Control Register               */
    __O  WDTIC_REG        WDTIC             ; /*!< Offset: 0x0000000C (WO  )  Watchdog Timer Clear Interrupt Register       */
    __IO WDTRAWIF_REG     WDTRAWIF          ; /*!< Offset: 0x00000010 (RW  )  Watchdog Timer Raw Interrupt Status Register  */
    __I  WDTIF_REG        WDTIF             ; /*!< Offset: 0x00000014 (RO  )  Watchdog Timer Interrupt Status Register      */
    __IO WDTLOCK_REG      WDTLOCK           ; /*!< Offset: 0x00000018 (RW  )  Watchdog Timer Lock Register                  */
} WDT_REGS;


/********************************************************************************
*
* Module Name     TIMER0
*
*
********************************************************************************/



/**
 *  @brief  Union type to access the Timer Control Register (TMRCTL), offset 0x0.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t EN            : 1;  /*!< bit:      0  TMRCTL_BIT_EN          */
        uint32_t EXINT4EN      : 1;  /*!< bit:      1  TMRCTL_BIT_EXINT4EN    */
        uint32_t EXINT4CLK     : 1;  /*!< bit:      2  TMRCTL_BIT_EXINT4CLK   */
        uint32_t INTEN         : 1;  /*!< bit:      3  TMRCTL_BIT_INTEN       */
        uint32_t RESERVED_31_4 :28;  /*!< bit: 31.. 4                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} TMRCTL_REG;


/**
 *  @brief  Union type to access the Timer Counter Value Register (TMRCNT), offset 0x4.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :32;  /*!< bit: 31.. 0  TMRCNT_BIT_VAL         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} TMRCNT_REG;


/**
 *  @brief  Union type to access the Timer Reload Value Register (TMRRELOAD), offset 0x8.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :32;  /*!< bit: 31.. 0  TMRRELOAD_BIT_VAL      */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} TMRRELOAD_REG;


/**
 *  @brief  Union type to access the Timer Interrupt Status Register (TMRIF), offset 0xC.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t INT           : 1;  /*!< bit:      0  TMRIF_BIT_INT          */
        uint32_t RESERVED_31_1 :31;  /*!< bit: 31.. 1                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} TMRIF_REG;





/**
  *  @brief  Structure type to access the TIMER Controller (TIMER).
  */
typedef struct
{
    __IO TMRCTL_REG        TMRCTL             ; /*!< Offset: 0x00000000 (RW  )  Timer Control Register           */
    __IO TMRCNT_REG        TMRCNT             ; /*!< Offset: 0x00000004 (RW  )  Timer Counter Value Register     */
    __IO TMRRELOAD_REG     TMRRELOAD          ; /*!< Offset: 0x00000008 (RW  )  Timer Reload Value Register      */
    __IO TMRIF_REG         TMRIF              ; /*!< Offset: 0x0000000C (RW  )  Timer Interrupt Status Register  */
} TIMER_REGS;


/********************************************************************************
*
* Module Name     GPIO
*
*
********************************************************************************/



/**
 *  @brief  Union type to access the GPIO Pin Level Register 0 (GPLR0), offset 0x0.
            Union type to access the GPIO Pin Level Register 1 (GPLR1), offset 0x4.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :32;  /*!< bit: 31.. 0  GPLR0_BIT_VAL          
                                                       GPLR1_BIT_VAL          */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} GPLRx_REG;


/**
 *  @brief  Union type to access the GPIO Pin Direction Register 0 (GPDR0), offset 0xC.
            Union type to access the GPIO Pin Direction Register 1 (GPDR1), offset 0x10.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :32;  /*!< bit: 31.. 0  GPDR0_BIT_VAL          
                                                       GPDR1_BIT_VAL          */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} GPDRx_REG;


/**
 *  @brief  Union type to access the GPIO Pin Output Set Register 0 (GPSR0), offset 0x18.
            Union type to access the GPIO Pin Output Set Register 1 (GPSR1), offset 0x1C.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :32;  /*!< bit: 31.. 0  GPSR0_BIT_VAL          
                                                       GPSR1_BIT_VAL          */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} GPSRx_REG;


/**
 *  @brief  Union type to access the GPIO Pin Output Clear Register 0 (GPCR0), offset 0x24.
            Union type to access the GPIO Pin Output Clear Register 1 (GPCR1), offset 0x28.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :32;  /*!< bit: 31.. 0  GPCR0_BIT_VAL          
                                                       GPCR1_BIT_VAL          */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} GPCRx_REG;


/**
 *  @brief  Union type to access the GPIO Rising Edge detect Enable Register 0 (GRER0), offset 0x30.
            Union type to access the GPIO Rising Edge detect Enable Register 1 (GRER1), offset 0x34.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :32;  /*!< bit: 31.. 0  GRER0_BIT_VAL          
                                                       GRER1_BIT_VAL          */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} GRERx_REG;


/**
 *  @brief  Union type to access the GPIO Falling Edge detect Enable Register 0 (GFER0), offset 0x3C.
            Union type to access the GPIO Falling Edge detect Enable Register 1 (GFER1), offset 0x40.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :32;  /*!< bit: 31.. 0  GFER0_BIT_VAL          
                                                       GFER1_BIT_VAL          */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} GFERx_REG;


/**
 *  @brief  Union type to access the GPIO Edge detect Status Register 0 (GEDR0), offset 0x48.
            Union type to access the GPIO Edge detect Status Register 1 (GEDR1), offset 0x4C.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :32;  /*!< bit: 31.. 0  GEDR0_BIT_VAL          
                                                       GEDR1_BIT_VAL          */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} GEDRx_REG;


/**
 *  @brief  Union type to access the GPIO Pin Bitwise Set Direction Register 0 (GSDR0), offset 0x54.
            Union type to access the GPIO Pin Bitwise Set Direction Register 1 (GSDR1), offset 0x58.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :32;  /*!< bit: 31.. 0  GSDR0_BIT_VAL          
                                                       GSDR1_BIT_VAL          */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} GSDRx_REG;


/**
 *  @brief  Union type to access the GPIO Pin Bitwise Clear Direction Register 0 (GCDR0), offset 0x60.
            Union type to access the GPIO Pin Bitwise Clear Direction Register 1 (GCDR1), offset 0x64.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :32;  /*!< bit: 31.. 0  GCDR0_BIT_VAL          
                                                       GCDR1_BIT_VAL          */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} GCDRx_REG;


/**
 *  @brief  Union type to access the GPIO Bitwise Set Rising Edge detect Enable Register 0 (GSRER0), offset 0x6C.
            Union type to access the GPIO Bitwise Set Rising Edge detect Enable Register 1 (GSRER1), offset 0x70.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :32;  /*!< bit: 31.. 0  GSRER0_BIT_VAL         
                                                       GSRER1_BIT_VAL         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} GSRERx_REG;


/**
 *  @brief  Union type to access the GPIO Bitwise Clear Rising Edge detect Enable Register 0 (GCRER0), offset 0x78.
            Union type to access the GPIO Bitwise Clear Rising Edge detect Enable Register 1 (GCRER1), offset 0x7C.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :32;  /*!< bit: 31.. 0  GCRER0_BIT_VAL         
                                                       GCRER1_BIT_VAL         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} GCRERx_REG;


/**
 *  @brief  Union type to access the GPIO Bitwise Set Falling Edge detect Enable Register 0 (GSFER0), offset 0x84.
            Union type to access the GPIO Bitwise Set Falling Edge detect Enable Register 1 (GSFER1), offset 0x88.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :32;  /*!< bit: 31.. 0  GSFER0_BIT_VAL         
                                                       GSFER1_BIT_VAL         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} GSFERx_REG;


/**
 *  @brief  Union type to access the GPIO Bitwise Clear Falling Edge detect Enable Register 0 (GCFER0), offset 0x90.
            Union type to access the GPIO Bitwise Clear Falling Edge detect Enable Register 1 (GCFER1), offset 0x94.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :32;  /*!< bit: 31.. 0  GCFER0_BIT_VAL         
                                                       GCFER1_BIT_VAL         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} GCFERx_REG;


/**
 *  @brief  Union type to access the GPIO Bitwise mask of Edge detect Status Register 0 (APMSK0), offset 0x9C.
            Union type to access the GPIO Bitwise mask of Edge detect Status Register 1 (APMSK1), offset 0xA0.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :32;  /*!< bit: 31.. 0  APMSK0_BIT_VAL         
                                                       APMSK1_BIT_VAL         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} APMSKx_REG;





/**
  *  @brief  Structure type to access the GPIO Controller (GPIO).
  */
typedef struct
{
    __I  GPLRx_REG        GPLR[2]           ; /*!< Offset: 0x00000000 (RO  )  GPIO Pin Level Register 0                                 */
         uint32_t         RESERVED0         ; 
    __IO GPDRx_REG        GPDR[2]           ; /*!< Offset: 0x0000000C (RW  )  GPIO Pin Direction Register 0                             */
         uint32_t         RESERVED1         ; 
    __O  GPSRx_REG        GPSR[2]           ; /*!< Offset: 0x00000018 (WO  )  GPIO Pin Output Set Register 0                            */
         uint32_t         RESERVED2         ; 
    __O  GPCRx_REG        GPCR[2]           ; /*!< Offset: 0x00000024 (WO  )  GPIO Pin Output Clear Register 0                          */
         uint32_t         RESERVED3         ; 
    __IO GRERx_REG        GRER[2]           ; /*!< Offset: 0x00000030 (RW  )  GPIO Rising Edge detect Enable Register 0                 */
         uint32_t         RESERVED4         ; 
    __IO GFERx_REG        GFER[2]           ; /*!< Offset: 0x0000003C (RW  )  GPIO Falling Edge detect Enable Register 0                */
         uint32_t         RESERVED5         ; 
    __IO GEDRx_REG        GEDR[2]           ; /*!< Offset: 0x00000048 (RW  )  GPIO Edge detect Status Register 0                        */
         uint32_t         RESERVED6         ; 
    __O  GSDRx_REG        GSDR[2]           ; /*!< Offset: 0x00000054 (WO  )  GPIO Pin Bitwise Set Direction Register 0                 */
         uint32_t         RESERVED7         ; 
    __O  GCDRx_REG        GCDR[2]           ; /*!< Offset: 0x00000060 (WO  )  GPIO Pin Bitwise Clear Direction Register 0               */
         uint32_t         RESERVED8         ; 
    __O  GSRERx_REG       GSRER[2]          ; /*!< Offset: 0x0000006C (WO  )  GPIO Bitwise Set Rising Edge detect Enable Register 0     */
         uint32_t         RESERVED9         ; 
    __O  GCRERx_REG       GCRER[2]          ; /*!< Offset: 0x00000078 (WO  )  GPIO Bitwise Clear Rising Edge detect Enable Register 0   */
         uint32_t         RESERVED10        ; 
    __O  GSFERx_REG       GSFER[2]          ; /*!< Offset: 0x00000084 (WO  )  GPIO Bitwise Set Falling Edge detect Enable Register 0    */
         uint32_t         RESERVED11        ; 
    __O  GCFERx_REG       GCFER[2]          ; /*!< Offset: 0x00000090 (WO  )  GPIO Bitwise Clear Falling Edge detect Enable Register 0  */
         uint32_t         RESERVED12        ; 
    __IO APMSKx_REG       APMSK[2]          ; /*!< Offset: 0x0000009C (RW  )  GPIO Bitwise mask of Edge detect Status Register 0        */
} GPIO_REGS;


/********************************************************************************
*
* Module Name     UART
*
*
********************************************************************************/



/**
 *  @brief  Union type to access the UART Receive Buffer Register (UARTRBR), offset 0x0.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :32;  /*!< bit: 31.. 0  UARTRBR_BIT_VAL        */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} UARTRBR_REG;


/**
 *  @brief  Union type to access the UART Transmit Holding Register (UARTTHR), offset 0x0.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :32;  /*!< bit: 31.. 0  UARTTHR_BIT_VAL        */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} UARTTHR_REG;


/**
 *  @brief  Union type to access the UART Divisor Latch Low Byte Register (UARTDLL), offset 0x0.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           : 8;  /*!< bit:  7.. 0  UARTDLL_BIT_VAL        */
        uint32_t RESERVED_31_8 :24;  /*!< bit: 31.. 8                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} UARTDLL_REG;


/**
 *  @brief  Union type to access the UART Divisor Latch High Byte Register (UARTDLH), offset 0x4.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           : 8;  /*!< bit:  7.. 0  UARTDLH_BIT_VAL        */
        uint32_t RESERVED_31_8 :24;  /*!< bit: 31.. 8                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} UARTDLH_REG;


/**
 *  @brief  Union type to access the UART Interrupt Enable Register (UARTIER), offset 0x4.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t RAVIE         : 1;  /*!< bit:      0  UARTIER_BIT_RAVIE      */
        uint32_t TIE           : 1;  /*!< bit:      1  UARTIER_BIT_TIE        */
        uint32_t RLSE          : 1;  /*!< bit:      2  UARTIER_BIT_RLSE       */
        uint32_t MIE           : 1;  /*!< bit:      3  UARTIER_BIT_MIE        */
        uint32_t RTOIE         : 1;  /*!< bit:      4  UARTIER_BIT_RTOIE      */
        uint32_t NRZE          : 1;  /*!< bit:      5  UARTIER_BIT_NRZE       */
        uint32_t UUE           : 1;  /*!< bit:      6  UARTIER_BIT_UUE        */
        uint32_t RESERVED_7_7  : 1;  /*!< bit:      7                         */
        uint32_t RESERVED_31_8 :24;  /*!< bit: 31.. 8                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} UARTIER_REG;


/**
 *  @brief  Union type to access the UART Interrupt Identification Register (UARTIIR), offset 0x8.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t NIP           : 1;  /*!< bit:      0  UARTIIR_BIT_NIP        */
        uint32_t IID           : 2;  /*!< bit:  2.. 1  UARTIIR_BIT_IID        */
        uint32_t TOD           : 1;  /*!< bit:      3  UARTIIR_BIT_TOD        */
        uint32_t ABL           : 1;  /*!< bit:      4  UARTIIR_BIT_ABL        */
        uint32_t RESERVED_5_5  : 1;  /*!< bit:      5                         */
        uint32_t FIFOSTS       : 2;  /*!< bit:  7.. 6  UARTIIR_BIT_FIFOSTS    */
        uint32_t RESERVED_31_8 :24;  /*!< bit: 31.. 8                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} UARTIIR_REG;


/**
 *  @brief  Union type to access the UART FIFO Control Register (UARTFCR), offset 0x8.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t TRFIFOE       : 1;  /*!< bit:      0  UARTFCR_BIT_TRFIFOE    */
        uint32_t RSTRF         : 1;  /*!< bit:      1  UARTFCR_BIT_RSTRF      */
        uint32_t RSTTF         : 1;  /*!< bit:      2  UARTFCR_BIT_RSTTF      */
        uint32_t TIL           : 1;  /*!< bit:      3  UARTFCR_BIT_TIL        */
        uint32_t RESERVED_4_4  : 1;  /*!< bit:      4                         */
        uint32_t RESERVED_5_5  : 1;  /*!< bit:      5                         */
        uint32_t ITL           : 2;  /*!< bit:  7.. 6  UARTFCR_BIT_ITL        */
        uint32_t RESERVED_31_8 :24;  /*!< bit: 31.. 8                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} UARTFCR_REG;


/**
 *  @brief  Union type to access the UART Line Control Register (UARTLCR), offset 0xC.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t WLS           : 2;  /*!< bit:  1.. 0  UARTLCR_BIT_WLS        */
        uint32_t STB           : 1;  /*!< bit:      2  UARTLCR_BIT_STB        */
        uint32_t PEN           : 1;  /*!< bit:      3  UARTLCR_BIT_PEN        */
        uint32_t EPS           : 1;  /*!< bit:      4  UARTLCR_BIT_EPS        */
        uint32_t STKYP         : 1;  /*!< bit:      5  UARTLCR_BIT_STKYP      */
        uint32_t SB            : 1;  /*!< bit:      6  UARTLCR_BIT_SB         */
        uint32_t DLAB          : 1;  /*!< bit:      7  UARTLCR_BIT_DLAB       */
        uint32_t RESERVED_31_8 :24;  /*!< bit: 31.. 8                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} UARTLCR_REG;


/**
 *  @brief  Union type to access the UART Modem Control Register (UARTMCR), offset 0x10.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t RESERVED_0_0  : 1;  /*!< bit:      0                         */
        uint32_t RESERVED_1_1  : 1;  /*!< bit:      1                         */
        uint32_t RESERVED_2_2  : 1;  /*!< bit:      2                         */
        uint32_t OUT2          : 1;  /*!< bit:      3  UARTMCR_BIT_OUT2       */
        uint32_t LOOP          : 1;  /*!< bit:      4  UARTMCR_BIT_LOOP       */
        uint32_t RESERVED_5_5  : 1;  /*!< bit:      5                         */
        uint32_t RESERVED_31_6 :26;  /*!< bit: 31.. 6                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} UARTMCR_REG;


/**
 *  @brief  Union type to access the UART Line Status Register (UARTLSR), offset 0x14.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t DR            : 1;  /*!< bit:      0  UARTLSR_BIT_DR         */
        uint32_t OE            : 1;  /*!< bit:      1  UARTLSR_BIT_OE         */
        uint32_t PE            : 1;  /*!< bit:      2  UARTLSR_BIT_PE         */
        uint32_t FE            : 1;  /*!< bit:      3  UARTLSR_BIT_FE         */
        uint32_t BI            : 1;  /*!< bit:      4  UARTLSR_BIT_BI         */
        uint32_t TDRQ          : 1;  /*!< bit:      5  UARTLSR_BIT_TDRQ       */
        uint32_t TXEMPTY       : 1;  /*!< bit:      6  UARTLSR_BIT_TXEMPTY    */
        uint32_t FIFOERR       : 1;  /*!< bit:      7  UARTLSR_BIT_FIFOERR    */
        uint32_t RESERVED_31_8 :24;  /*!< bit: 31.. 8                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} UARTLSR_REG;


/**
 *  @brief  Union type to access the UART Infrared Selection Register (UARTISR), offset 0x20.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t XMITIR        : 1;  /*!< bit:      0  UARTISR_BIT_XMITIR     */
        uint32_t RCVEIR        : 1;  /*!< bit:      1  UARTISR_BIT_RCVEIR     */
        uint32_t XMODE         : 1;  /*!< bit:      2  UARTISR_BIT_XMODE      */
        uint32_t TXPL          : 1;  /*!< bit:      3  UARTISR_BIT_TXPL       */
        uint32_t RXPL          : 1;  /*!< bit:      4  UARTISR_BIT_RXPL       */
        uint32_t RESERVED_31_5 :27;  /*!< bit: 31.. 5                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} UARTISR_REG;


/**
 *  @brief  Union type to access the UART Receive FIFO Occupancy Register (UARTFOR), offset 0x24.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t BYTECNT       : 6;  /*!< bit:  5.. 0  UARTFOR_BIT_BYTECNT    */
        uint32_t RESERVED_31_6 :26;  /*!< bit: 31.. 6                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} UARTFOR_REG;


/**
 *  @brief  Union type to access the UART Auto-Baud Control Register (UARTABR), offset 0x28.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t ABE           : 1;  /*!< bit:      0  UARTABR_BIT_ABE        */
        uint32_t ABLIE         : 1;  /*!< bit:      1  UARTABR_BIT_ABLIE      */
        uint32_t ABUP          : 1;  /*!< bit:      2  UARTABR_BIT_ABUP       */
        uint32_t ABT           : 1;  /*!< bit:      3  UARTABR_BIT_ABT        */
        uint32_t RESERVED_31_4 :28;  /*!< bit: 31.. 4                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} UARTABR_REG;


/**
 *  @brief  Union type to access the UART Auto-Baud Count Register (UARTACR), offset 0x2C.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t CNTVAL        :16;  /*!< bit: 15.. 0  UARTACR_BIT_CNTVAL     */
        uint32_t RESERVED_31_16:16;  /*!< bit: 31..16                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} UARTACR_REG;





/**
  *  @brief  Structure type to access the UART Controller (UART).
  */
typedef struct
{
    union
    {
        __I  UARTRBR_REG     UARTRBR      ; /*!< Offset: 0x00000000 (RO  )  UART Receive Buffer Register            */
        __O  UARTTHR_REG     UARTTHR      ; /*!< Offset: 0x00000000 (WO  )  UART Transmit Holding Register          */
        __IO UARTDLL_REG     UARTDLL      ; /*!< Offset: 0x00000000 (RW  )  UART Divisor Latch Low Byte Register    */
    } UARTRBR_UARTTHR_UARTDLL;
    union
    {
        __IO UARTDLH_REG     UARTDLH      ; /*!< Offset: 0x00000004 (RW  )  UART Divisor Latch High Byte Register   */
        __IO UARTIER_REG     UARTIER      ; /*!< Offset: 0x00000004 (RW  )  UART Interrupt Enable Register          */
    } UARTDLH_UARTIER;
    union
    {
        __I  UARTIIR_REG     UARTIIR      ; /*!< Offset: 0x00000008 (RO  )  UART Interrupt Identification Register  */
        __O  UARTFCR_REG     UARTFCR      ; /*!< Offset: 0x00000008 (WO  )  UART FIFO Control Register              */
    } UARTIIR_UARTFCR;
    __IO UARTLCR_REG     UARTLCR          ; /*!< Offset: 0x0000000C (RW  )  UART Line Control Register              */
    __IO UARTMCR_REG     UARTMCR          ; /*!< Offset: 0x00000010 (RW  )  UART Modem Control Register             */
    __I  UARTLSR_REG     UARTLSR          ; /*!< Offset: 0x00000014 (RO  )  UART Line Status Register               */
         uint32_t        RESERVED0        ; 
         uint32_t        RESERVED1        ; 
    __IO UARTISR_REG     UARTISR          ; /*!< Offset: 0x00000020 (RW  )  UART Infrared Selection Register        */
    __I  UARTFOR_REG     UARTFOR          ; /*!< Offset: 0x00000024 (RO  )  UART Receive FIFO Occupancy Register    */
    __IO UARTABR_REG     UARTABR          ; /*!< Offset: 0x00000028 (RW  )  UART Auto-Baud Control Register         */
    __I  UARTACR_REG     UARTACR          ; /*!< Offset: 0x0000002C (RO  )  UART Auto-Baud Count Register           */
} UART_REGS;


/********************************************************************************
*
* Module Name     SSP
*
*
********************************************************************************/



/**
 *  @brief  Union type to access the SSP Control Register 0 (SSPCTL0), offset 0x0.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t SIZESEL       : 4;  /*!< bit:  3.. 0  SSPCTL0_BIT_SIZESEL    */
        uint32_t FRMSEL        : 2;  /*!< bit:  5.. 4  SSPCTL0_BIT_FRMSEL     */
        uint32_t RESERVED_6_6  : 1;  /*!< bit:      6                         */
        uint32_t EN            : 1;  /*!< bit:      7  SSPCTL0_BIT_EN         */
        uint32_t RESERVED_19_8 :12;  /*!< bit: 19.. 8                         */
        uint32_t ESIZESEL      : 1;  /*!< bit:     20  SSPCTL0_BIT_ESIZESEL   */
        uint32_t RESERVED_21_21: 1;  /*!< bit:     21                         */
        uint32_t RFINTMSK      : 1;  /*!< bit:     22  SSPCTL0_BIT_RFINTMSK   */
        uint32_t TFINTMSK      : 1;  /*!< bit:     23  SSPCTL0_BIT_TFINTMSK   */
        uint32_t FRMRATE       : 3;  /*!< bit: 26..24  SSPCTL0_BIT_FRMRATE    */
        uint32_t RESERVED_28_27: 2;  /*!< bit: 28..27                         */
        uint32_t FPACKEN       : 1;  /*!< bit:     29  SSPCTL0_BIT_FPACKEN    */
        uint32_t RESERVED_30_30: 1;  /*!< bit:     30                         */
        uint32_t MODE          : 1;  /*!< bit:     31  SSPCTL0_BIT_MODE       */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} SSPCTL0_REG;


/**
 *  @brief  Union type to access the SSP Control Register 1 (SSPCTL1), offset 0x4.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t RFIE          : 1;  /*!< bit:      0  SSPCTL1_BIT_RFIE       */
        uint32_t TFIE          : 1;  /*!< bit:      1  SSPCTL1_BIT_TFIE       */
        uint32_t LOOP          : 1;  /*!< bit:      2  SSPCTL1_BIT_LOOP       */
        uint32_t CLKPOL        : 1;  /*!< bit:      3  SSPCTL1_BIT_CLKPOL     */
        uint32_t CLKPHS        : 1;  /*!< bit:      4  SSPCTL1_BIT_CLKPHS     */
        uint32_t RESERVED_5_5  : 1;  /*!< bit:      5                         */
        uint32_t TFTH          : 4;  /*!< bit:  9.. 6  SSPCTL1_BIT_TFTH       */
        uint32_t RFTH          : 4;  /*!< bit: 13..10  SSPCTL1_BIT_RFTH       */
        uint32_t EFWR          : 1;  /*!< bit:     14  SSPCTL1_BIT_EFWR       */
        uint32_t STRF          : 1;  /*!< bit:     15  SSPCTL1_BIT_STRF       */
        uint32_t FRMINV        : 1;  /*!< bit:     16  SSPCTL1_BIT_FRMINV     */
        uint32_t RESERVED_18_17: 2;  /*!< bit: 18..17                         */
        uint32_t RXTOIE        : 1;  /*!< bit:     19  SSPCTL1_BIT_RXTOIE     */
        uint32_t RESERVED_20_20: 1;  /*!< bit:     20                         */
        uint32_t RESERVED_21_21: 1;  /*!< bit:     21                         */
        uint32_t RESERVED_22_22: 1;  /*!< bit:     22                         */
        uint32_t RXONLY        : 1;  /*!< bit:     23  SSPCTL1_BIT_RXONLY     */
        uint32_t FRMDIR        : 1;  /*!< bit:     24  SSPCTL1_BIT_FRMDIR     */
        uint32_t CLKDIR        : 1;  /*!< bit:     25  SSPCTL1_BIT_CLKDIR     */
        uint32_t RESERVED_27_26: 2;  /*!< bit: 27..26                         */
        uint32_t SLVCLKSEL     : 1;  /*!< bit:     28  SSPCTL1_BIT_SLVCLKSEL  */
        uint32_t BITCNTERRIE   : 1;  /*!< bit:     29  SSPCTL1_BIT_BITCNTERRIE*/
        uint32_t TXTRIEN       : 1;  /*!< bit:     30  SSPCTL1_BIT_TXTRIEN    */
        uint32_t TXTRITIME     : 1;  /*!< bit:     31  SSPCTL1_BIT_TXTRITIME  */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} SSPCTL1_REG;


/**
 *  @brief  Union type to access the SSP Status Register (SSPSTS), offset 0x8.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t RESERVED_1_0  : 2;  /*!< bit:  1.. 0                         */
        uint32_t TNF           : 1;  /*!< bit:      2  SSPSTS_BIT_TNF         */
        uint32_t RNE           : 1;  /*!< bit:      3  SSPSTS_BIT_RNE         */
        uint32_t BUSY          : 1;  /*!< bit:      4  SSPSTS_BIT_BUSY        */
        uint32_t TFS           : 1;  /*!< bit:      5  SSPSTS_BIT_TFS         */
        uint32_t RFS           : 1;  /*!< bit:      6  SSPSTS_BIT_RFS         */
        uint32_t RFOVF         : 1;  /*!< bit:      7  SSPSTS_BIT_RFOVF       */
        uint32_t TFLVL         : 4;  /*!< bit: 11.. 8  SSPSTS_BIT_TFLVL       */
        uint32_t RFLVL         : 4;  /*!< bit: 15..12  SSPSTS_BIT_RFLVL       */
        uint32_t RESERVED_18_16: 3;  /*!< bit: 18..16                         */
        uint32_t RXTOINT       : 1;  /*!< bit:     19  SSPSTS_BIT_RXTOINT     */
        uint32_t RESERVED_20_20: 1;  /*!< bit:     20                         */
        uint32_t TFUDF         : 1;  /*!< bit:     21  SSPSTS_BIT_TFUDF       */
        uint32_t SLVCLKSTS     : 1;  /*!< bit:     22  SSPSTS_BIT_SLVCLKSTS   */
        uint32_t BITCNTERR     : 1;  /*!< bit:     23  SSPSTS_BIT_BITCNTERR   */
        uint32_t RESERVED_29_24: 6;  /*!< bit: 29..24                         */
        uint32_t TFODDSTS      : 1;  /*!< bit:     30  SSPSTS_BIT_TFODDSTS    */
        uint32_t RFODDSTS      : 1;  /*!< bit:     31  SSPSTS_BIT_RFODDSTS    */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} SSPSTS_REG;


/**
 *  @brief  Union type to access the SSP Interrupt Test Register (SSPFRC), offset 0xC.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t RESERVED_4_0  : 5;  /*!< bit:  4.. 0                         */
        uint32_t TFREQ         : 1;  /*!< bit:      5  SSPFRC_BIT_TFREQ       */
        uint32_t RFREQ         : 1;  /*!< bit:      6  SSPFRC_BIT_RFREQ       */
        uint32_t RFOVF         : 1;  /*!< bit:      7  SSPFRC_BIT_RFOVF       */
        uint32_t RESERVED_31_8 :24;  /*!< bit: 31.. 8                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} SSPFRC_REG;


/**
 *  @brief  Union type to access the SSP Data Register (SSPDATA), offset 0x10.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :32;  /*!< bit: 31.. 0  SSPDATA_BIT_VAL        */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} SSPDATA_REG;


/**
 *  @brief  Union type to access the SSP Time Out Register (SSPTO), offset 0x28.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :24;  /*!< bit: 23.. 0  SSPTO_BIT_VAL          */
        uint32_t RESERVED_31_24: 8;  /*!< bit: 31..24                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} SSPTO_REG;


/**
 *  @brief  Union type to access the SSP Programmable Serial Protocol Register (SSPPSP), offset 0x2C.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t CLKMODE       : 2;  /*!< bit:  1.. 0  SSPPSP_BIT_CLKMODE     */
        uint32_t FRMPOL        : 1;  /*!< bit:      2  SSPPSP_BIT_FRMPOL      */
        uint32_t ETDS          : 1;  /*!< bit:      3  SSPPSP_BIT_ETDS        */
        uint32_t STARTDLY      : 3;  /*!< bit:  6.. 4  SSPPSP_BIT_STARTDLY    */
        uint32_t DMYSTART      : 2;  /*!< bit:  8.. 7  SSPPSP_BIT_DMYSTART    */
        uint32_t FRMDLY        : 7;  /*!< bit: 15.. 9  SSPPSP_BIT_FRMDLY      */
        uint32_t FRMWIDTH      : 6;  /*!< bit: 21..16  SSPPSP_BIT_FRMWIDTH    */
        uint32_t RESERVED_22_22: 1;  /*!< bit:     22                         */
        uint32_t DMYSTOP       : 2;  /*!< bit: 24..23  SSPPSP_BIT_DMYSTOP     */
        uint32_t FRMSYNC       : 1;  /*!< bit:     25  SSPPSP_BIT_FRMSYNC     */
        uint32_t EDMYSTART     : 2;  /*!< bit: 27..26  SSPPSP_BIT_EDMYSTART   */
        uint32_t EDMYSTOP      : 3;  /*!< bit: 30..28  SSPPSP_BIT_EDMYSTOP    */
        uint32_t RESERVED_31_31: 1;  /*!< bit:     31                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} SSPPSP_REG;


/**
 *  @brief  Union type to access the SSP TX Time Slot Active Register (SSPTXSLOTEN), offset 0x30.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t SLOT0         : 1;  /*!< bit:      0  SSPTXSLOTEN_BIT_SLOT0  */
        uint32_t SLOT1         : 1;  /*!< bit:      1  SSPTXSLOTEN_BIT_SLOT1  */
        uint32_t SLOT2         : 1;  /*!< bit:      2  SSPTXSLOTEN_BIT_SLOT2  */
        uint32_t SLOT3         : 1;  /*!< bit:      3  SSPTXSLOTEN_BIT_SLOT3  */
        uint32_t SLOT4         : 1;  /*!< bit:      4  SSPTXSLOTEN_BIT_SLOT4  */
        uint32_t SLOT5         : 1;  /*!< bit:      5  SSPTXSLOTEN_BIT_SLOT5  */
        uint32_t SLOT6         : 1;  /*!< bit:      6  SSPTXSLOTEN_BIT_SLOT6  */
        uint32_t SLOT7         : 1;  /*!< bit:      7  SSPTXSLOTEN_BIT_SLOT7  */
        uint32_t RESERVED_31_8 :24;  /*!< bit: 31.. 8                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} SSPTXSLOTEN_REG;


/**
 *  @brief  Union type to access the SSP RX Time Slot Active Register (SSPRXSLOTEN), offset 0x34.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t SLOT0         : 1;  /*!< bit:      0  SSPRXSLOTEN_BIT_SLOT0  */
        uint32_t SLOT1         : 1;  /*!< bit:      1  SSPRXSLOTEN_BIT_SLOT1  */
        uint32_t SLOT2         : 1;  /*!< bit:      2  SSPRXSLOTEN_BIT_SLOT2  */
        uint32_t SLOT3         : 1;  /*!< bit:      3  SSPRXSLOTEN_BIT_SLOT3  */
        uint32_t SLOT4         : 1;  /*!< bit:      4  SSPRXSLOTEN_BIT_SLOT4  */
        uint32_t SLOT5         : 1;  /*!< bit:      5  SSPRXSLOTEN_BIT_SLOT5  */
        uint32_t SLOT6         : 1;  /*!< bit:      6  SSPRXSLOTEN_BIT_SLOT6  */
        uint32_t SLOT7         : 1;  /*!< bit:      7  SSPRXSLOTEN_BIT_SLOT7  */
        uint32_t RESERVED_31_8 :24;  /*!< bit: 31.. 8                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} SSPRXSLOTEN_REG;


/**
 *  @brief  Union type to access the SSP Time Slot Status Register (SSPNETSTS), offset 0x38.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t SLOTACT       : 3;  /*!< bit:  2.. 0  SSPNETSTS_BIT_SLOTACT  */
        uint32_t RESERVED_30_3 :28;  /*!< bit: 30.. 3                         */
        uint32_t BUSY          : 1;  /*!< bit:     31  SSPNETSTS_BIT_BUSY     */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} SSPNETSTS_REG;





/**
  *  @brief  Structure type to access the SSP Controller (SSP).
  */
typedef struct
{
    __IO SSPCTL0_REG         SSPCTL0              ; /*!< Offset: 0x00000000 (RW  )  SSP Control Register 0                     */
    __IO SSPCTL1_REG         SSPCTL1              ; /*!< Offset: 0x00000004 (RW  )  SSP Control Register 1                     */
    __IO SSPSTS_REG          SSPSTS               ; /*!< Offset: 0x00000008 (RW  )  SSP Status Register                        */
    __IO SSPFRC_REG          SSPFRC               ; /*!< Offset: 0x0000000C (RW  )  SSP Interrupt Test Register                */
    __IO SSPDATA_REG         SSPDATA              ; /*!< Offset: 0x00000010 (RW  )  SSP Data Register                          */
         uint32_t            RESERVED0[5]         ; 
    __IO SSPTO_REG           SSPTO                ; /*!< Offset: 0x00000028 (RW  )  SSP Time Out Register                      */
    __IO SSPPSP_REG          SSPPSP               ; /*!< Offset: 0x0000002C (RW  )  SSP Programmable Serial Protocol Register  */
    __IO SSPTXSLOTEN_REG     SSPTXSLOTEN          ; /*!< Offset: 0x00000030 (RW  )  SSP TX Time Slot Active Register           */
    __IO SSPRXSLOTEN_REG     SSPRXSLOTEN          ; /*!< Offset: 0x00000034 (RW  )  SSP RX Time Slot Active Register           */
    __I  SSPNETSTS_REG       SSPNETSTS            ; /*!< Offset: 0x00000038 (RO  )  SSP Time Slot Status Register              */
} SSP_REGS;


/********************************************************************************
*
* Module Name     I2C
*
*
********************************************************************************/



/**
 *  @brief  Union type to access the I2C Control Register (I2CCTL), offset 0x0.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label              */
        uint32_t MASTER        : 1;  /*!< bit:      0  I2CCTL_BIT_MASTER             */
        uint32_t SPEED         : 2;  /*!< bit:  2.. 1  I2CCTL_BIT_SPEED              */
        uint32_t SLVADDR10B    : 1;  /*!< bit:      3  I2CCTL_BIT_SLVADDR10B         */
        uint32_t ADDRSTS       : 1;  /*!< bit:      4  I2CCTL_BIT_ADDRSTS            */
        uint32_t RESTARTEN     : 1;  /*!< bit:      5  I2CCTL_BIT_RESTARTEN          */
        uint32_t SLVDIS        : 1;  /*!< bit:      6  I2CCTL_BIT_SLVDIS             */
        uint32_t RESERVED_31_7 :25;  /*!< bit: 31.. 7                                */
    } bit;                           /*!< Structure used for bit  access             */
    uint32_t all;                    /*!< Type      used for word access             */
} I2CCTL_REG;


/**
 *  @brief  Union type to access the I2C Master Address Register (I2CMASTERADDR), offset 0x4.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label              */
        uint32_t TARADDR       :10;  /*!< bit:  9.. 0  I2CMASTERADDR_BIT_TARADDR     */
        uint32_t GCORSTART     : 1;  /*!< bit:     10  I2CMASTERADDR_BIT_GCORSTART   */
        uint32_t SPECIAL       : 1;  /*!< bit:     11  I2CMASTERADDR_BIT_SPECIAL     */
        uint32_t MASTERADDR10B : 1;  /*!< bit:     12  I2CMASTERADDR_BIT_MASTERADDR10B*/
        uint32_t RESERVED_31_13:19;  /*!< bit: 31..13                                */
    } bit;                           /*!< Structure used for bit  access             */
    uint32_t all;                    /*!< Type      used for word access             */
} I2CMASTERADDR_REG;


/**
 *  @brief  Union type to access the I2C Slave Address Register (I2CSLVADDR), offset 0x8.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label              */
        uint32_t VAL           :10;  /*!< bit:  9.. 0  I2CSLVADDR_BIT_VAL            */
        uint32_t RESERVED_31_10:22;  /*!< bit: 31..10                                */
    } bit;                           /*!< Structure used for bit  access             */
    uint32_t all;                    /*!< Type      used for word access             */
} I2CSLVADDR_REG;


/**
 *  @brief  Union type to access the I2C High Speed Master Mode Code Address Register (I2CHSMADDR), offset 0xC.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label              */
        uint32_t VAL           : 3;  /*!< bit:  2.. 0  I2CHSMADDR_BIT_VAL            */
        uint32_t RESERVED_31_3 :29;  /*!< bit: 31.. 3                                */
    } bit;                           /*!< Structure used for bit  access             */
    uint32_t all;                    /*!< Type      used for word access             */
} I2CHSMADDR_REG;


/**
 *  @brief  Union type to access the I2C Data Buffer and Command Register (I2CDATACMD), offset 0x10.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label              */
        uint32_t DATA          : 8;  /*!< bit:  7.. 0  I2CDATACMD_BIT_DATA           */
        uint32_t CMD           : 1;  /*!< bit:      8  I2CDATACMD_BIT_CMD            */
        uint32_t RESERVED_31_9 :23;  /*!< bit: 31.. 9                                */
    } bit;                           /*!< Structure used for bit  access             */
    uint32_t all;                    /*!< Type      used for word access             */
} I2CDATACMD_REG;


/**
 *  @brief  Union type to access the Standard Speed I2C Clock SCL High Count Register (I2CSSHCNT), offset 0x14.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label              */
        uint32_t VAL           :16;  /*!< bit: 15.. 0  I2CSSHCNT_BIT_VAL             */
        uint32_t RESERVED_31_16:16;  /*!< bit: 31..16                                */
    } bit;                           /*!< Structure used for bit  access             */
    uint32_t all;                    /*!< Type      used for word access             */
} I2CSSHCNT_REG;


/**
 *  @brief  Union type to access the Standard Speed I2C Clock SCL Low Count Register (I2CSSLCNT), offset 0x18.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label              */
        uint32_t VAL           :16;  /*!< bit: 15.. 0  I2CSSLCNT_BIT_VAL             */
        uint32_t RESERVED_31_16:16;  /*!< bit: 31..16                                */
    } bit;                           /*!< Structure used for bit  access             */
    uint32_t all;                    /*!< Type      used for word access             */
} I2CSSLCNT_REG;


/**
 *  @brief  Union type to access the Fast Speed I2C Clock SCL High Count Register (I2CFSHCNT), offset 0x1C.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label              */
        uint32_t VAL           :16;  /*!< bit: 15.. 0  I2CFSHCNT_BIT_VAL             */
        uint32_t RESERVED_31_16:16;  /*!< bit: 31..16                                */
    } bit;                           /*!< Structure used for bit  access             */
    uint32_t all;                    /*!< Type      used for word access             */
} I2CFSHCNT_REG;


/**
 *  @brief  Union type to access the Fast Speed I2C Clock SCL Low Count Register (I2CFSLCNT), offset 0x20.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label              */
        uint32_t VAL           :16;  /*!< bit: 15.. 0  I2CFSLCNT_BIT_VAL             */
        uint32_t RESERVED_31_16:16;  /*!< bit: 31..16                                */
    } bit;                           /*!< Structure used for bit  access             */
    uint32_t all;                    /*!< Type      used for word access             */
} I2CFSLCNT_REG;


/**
 *  @brief  Union type to access the High Speed I2C Clock SCL High Count Register (I2CHSHCNT), offset 0x24.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label              */
        uint32_t VAL           :16;  /*!< bit: 15.. 0  I2CHSHCNT_BIT_VAL             */
        uint32_t RESERVED_31_16:16;  /*!< bit: 31..16                                */
    } bit;                           /*!< Structure used for bit  access             */
    uint32_t all;                    /*!< Type      used for word access             */
} I2CHSHCNT_REG;


/**
 *  @brief  Union type to access the High Speed I2C Clock SCL Low Count Register (I2CHSLCNT), offset 0x28.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label              */
        uint32_t VAL           :16;  /*!< bit: 15.. 0  I2CHSLCNT_BIT_VAL             */
        uint32_t RESERVED_31_16:16;  /*!< bit: 31..16                                */
    } bit;                           /*!< Structure used for bit  access             */
    uint32_t all;                    /*!< Type      used for word access             */
} I2CHSLCNT_REG;


/**
 *  @brief  Union type to access the I2C Interrupt Flag Register (I2CIF), offset 0x2C.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label              */
        uint32_t RXUDF         : 1;  /*!< bit:      0  I2CIF_BIT_RXUDF               */
        uint32_t RXOVF         : 1;  /*!< bit:      1  I2CIF_BIT_RXOVF               */
        uint32_t RXFULL        : 1;  /*!< bit:      2  I2CIF_BIT_RXFULL              */
        uint32_t TXOVF         : 1;  /*!< bit:      3  I2CIF_BIT_TXOVF               */
        uint32_t TXEMPTY       : 1;  /*!< bit:      4  I2CIF_BIT_TXEMPTY             */
        uint32_t RDREQ         : 1;  /*!< bit:      5  I2CIF_BIT_RDREQ               */
        uint32_t TXABRT        : 1;  /*!< bit:      6  I2CIF_BIT_TXABRT              */
        uint32_t RXDONE        : 1;  /*!< bit:      7  I2CIF_BIT_RXDONE              */
        uint32_t ACT           : 1;  /*!< bit:      8  I2CIF_BIT_ACT                 */
        uint32_t STOPDET       : 1;  /*!< bit:      9  I2CIF_BIT_STOPDET             */
        uint32_t STARTDET      : 1;  /*!< bit:     10  I2CIF_BIT_STARTDET            */
        uint32_t GENCALL       : 1;  /*!< bit:     11  I2CIF_BIT_GENCALL             */
        uint32_t RESERVED_31_12:20;  /*!< bit: 31..12                                */
    } bit;                           /*!< Structure used for bit  access             */
    uint32_t all;                    /*!< Type      used for word access             */
} I2CIF_REG;


/**
 *  @brief  Union type to access the I2C Interrupt Enable Register (I2CIE), offset 0x30.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label              */
        uint32_t RXUDF         : 1;  /*!< bit:      0  I2CIE_BIT_RXUDF               */
        uint32_t RXOVF         : 1;  /*!< bit:      1  I2CIE_BIT_RXOVF               */
        uint32_t RXFULL        : 1;  /*!< bit:      2  I2CIE_BIT_RXFULL              */
        uint32_t TXOVF         : 1;  /*!< bit:      3  I2CIE_BIT_TXOVF               */
        uint32_t TXEMPTY       : 1;  /*!< bit:      4  I2CIE_BIT_TXEMPTY             */
        uint32_t RDREQ         : 1;  /*!< bit:      5  I2CIE_BIT_RDREQ               */
        uint32_t TXABRT        : 1;  /*!< bit:      6  I2CIE_BIT_TXABRT              */
        uint32_t RXDONE        : 1;  /*!< bit:      7  I2CIE_BIT_RXDONE              */
        uint32_t ACT           : 1;  /*!< bit:      8  I2CIE_BIT_ACT                 */
        uint32_t STOPDET       : 1;  /*!< bit:      9  I2CIE_BIT_STOPDET             */
        uint32_t STARTDET      : 1;  /*!< bit:     10  I2CIE_BIT_STARTDET            */
        uint32_t GENCALL       : 1;  /*!< bit:     11  I2CIE_BIT_GENCALL             */
        uint32_t RESERVED_31_12:20;  /*!< bit: 31..12                                */
    } bit;                           /*!< Structure used for bit  access             */
    uint32_t all;                    /*!< Type      used for word access             */
} I2CIE_REG;


/**
 *  @brief  Union type to access the I2C Raw Interrupt Flag Register (I2CRAWIF), offset 0x34.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label              */
        uint32_t RXUDF         : 1;  /*!< bit:      0  I2CRAWIF_BIT_RXUDF            */
        uint32_t RXOVF         : 1;  /*!< bit:      1  I2CRAWIF_BIT_RXOVF            */
        uint32_t RXFULL        : 1;  /*!< bit:      2  I2CRAWIF_BIT_RXFULL           */
        uint32_t TXOVF         : 1;  /*!< bit:      3  I2CRAWIF_BIT_TXOVF            */
        uint32_t TXEMPTY       : 1;  /*!< bit:      4  I2CRAWIF_BIT_TXEMPTY          */
        uint32_t RDREQ         : 1;  /*!< bit:      5  I2CRAWIF_BIT_RDREQ            */
        uint32_t TXABRT        : 1;  /*!< bit:      6  I2CRAWIF_BIT_TXABRT           */
        uint32_t RXDONE        : 1;  /*!< bit:      7  I2CRAWIF_BIT_RXDONE           */
        uint32_t ACT           : 1;  /*!< bit:      8  I2CRAWIF_BIT_ACT              */
        uint32_t STOPDET       : 1;  /*!< bit:      9  I2CRAWIF_BIT_STOPDET          */
        uint32_t STARTDET      : 1;  /*!< bit:     10  I2CRAWIF_BIT_STARTDET         */
        uint32_t GENCALL       : 1;  /*!< bit:     11  I2CRAWIF_BIT_GENCALL          */
        uint32_t RESERVED_31_12:20;  /*!< bit: 31..12                                */
    } bit;                           /*!< Structure used for bit  access             */
    uint32_t all;                    /*!< Type      used for word access             */
} I2CRAWIF_REG;


/**
 *  @brief  Union type to access the I2C Receive FIFO Threshold Register (I2CRXTH), offset 0x38.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label              */
        uint32_t VAL           : 4;  /*!< bit:  3.. 0  I2CRXTH_BIT_VAL               */
        uint32_t KEY           : 4;  /*!< bit:  7.. 4  I2CRXTH_BIT_KEY               */
        uint32_t RESERVED_31_8 :24;  /*!< bit: 31.. 8                                */
    } bit;                           /*!< Structure used for bit  access             */
    uint32_t all;                    /*!< Type      used for word access             */
} I2CRXTH_REG;


/**
 *  @brief  Union type to access the I2C Transmit FIFO Threshold Register (I2CTXTH), offset 0x3C.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label              */
        uint32_t VAL           : 4;  /*!< bit:  3.. 0  I2CTXTH_BIT_VAL               */
        uint32_t KEY           : 4;  /*!< bit:  7.. 4  I2CTXTH_BIT_KEY               */
        uint32_t RESERVED_31_8 :24;  /*!< bit: 31.. 8                                */
    } bit;                           /*!< Structure used for bit  access             */
    uint32_t all;                    /*!< Type      used for word access             */
} I2CTXTH_REG;


/**
 *  @brief  Union type to access the Clear Combined and Individual Interrupt Register (I2CINTCLR), offset 0x40.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label              */
        uint32_t CLR           : 1;  /*!< bit:      0  I2CINTCLR_BIT_CLR             */
        uint32_t RESERVED_31_1 :31;  /*!< bit: 31.. 1                                */
    } bit;                           /*!< Structure used for bit  access             */
    uint32_t all;                    /*!< Type      used for word access             */
} I2CINTCLR_REG;


/**
 *  @brief  Union type to access the Clear RXUDF Interrupt Register (I2CRXUDFCLR), offset 0x44.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label              */
        uint32_t CLR           : 1;  /*!< bit:      0  I2CRXUDFCLR_BIT_CLR           */
        uint32_t RESERVED_31_1 :31;  /*!< bit: 31.. 1                                */
    } bit;                           /*!< Structure used for bit  access             */
    uint32_t all;                    /*!< Type      used for word access             */
} I2CRXUDFCLR_REG;


/**
 *  @brief  Union type to access the Clear RXOVF Interrupt Register (I2CRXOVFCLR), offset 0x48.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label              */
        uint32_t CLR           : 1;  /*!< bit:      0  I2CRXOVFCLR_BIT_CLR           */
        uint32_t RESERVED_31_1 :31;  /*!< bit: 31.. 1                                */
    } bit;                           /*!< Structure used for bit  access             */
    uint32_t all;                    /*!< Type      used for word access             */
} I2CRXOVFCLR_REG;


/**
 *  @brief  Union type to access the Clear TXOVF Interrupt Register (I2CTXOVFCLR), offset 0x4C.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label              */
        uint32_t CLR           : 1;  /*!< bit:      0  I2CTXOVFCLR_BIT_CLR           */
        uint32_t RESERVED_31_1 :31;  /*!< bit: 31.. 1                                */
    } bit;                           /*!< Structure used for bit  access             */
    uint32_t all;                    /*!< Type      used for word access             */
} I2CTXOVFCLR_REG;


/**
 *  @brief  Union type to access the Clear RDREQ Interrupt Register (I2CRDREQCLR), offset 0x50.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label              */
        uint32_t CLR           : 1;  /*!< bit:      0  I2CRDREQCLR_BIT_CLR           */
        uint32_t RESERVED_31_1 :31;  /*!< bit: 31.. 1                                */
    } bit;                           /*!< Structure used for bit  access             */
    uint32_t all;                    /*!< Type      used for word access             */
} I2CRDREQCLR_REG;


/**
 *  @brief  Union type to access the Clear TXABRT Interrupt Register (I2CTXABRTCLR), offset 0x54.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label              */
        uint32_t CLR           : 1;  /*!< bit:      0  I2CTXABRTCLR_BIT_CLR          */
        uint32_t RESERVED_31_1 :31;  /*!< bit: 31.. 1                                */
    } bit;                           /*!< Structure used for bit  access             */
    uint32_t all;                    /*!< Type      used for word access             */
} I2CTXABRTCLR_REG;


/**
 *  @brief  Union type to access the Clear RXDONE Interrupt Register (I2CRXDONECLR), offset 0x58.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label              */
        uint32_t CLR           : 1;  /*!< bit:      0  I2CRXDONECLR_BIT_CLR          */
        uint32_t RESERVED_31_1 :31;  /*!< bit: 31.. 1                                */
    } bit;                           /*!< Structure used for bit  access             */
    uint32_t all;                    /*!< Type      used for word access             */
} I2CRXDONECLR_REG;


/**
 *  @brief  Union type to access the Clear ACT Interrupt Register (I2CACTCLR), offset 0x5C.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label              */
        uint32_t CLR           : 1;  /*!< bit:      0  I2CACTCLR_BIT_CLR             */
        uint32_t RESERVED_31_1 :31;  /*!< bit: 31.. 1                                */
    } bit;                           /*!< Structure used for bit  access             */
    uint32_t all;                    /*!< Type      used for word access             */
} I2CACTCLR_REG;


/**
 *  @brief  Union type to access the Clear STOPDET Interrupt Register (I2CSTOPDETCLR), offset 0x60.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label              */
        uint32_t CLR           : 1;  /*!< bit:      0  I2CSTOPDETCLR_BIT_CLR         */
        uint32_t RESERVED_31_1 :31;  /*!< bit: 31.. 1                                */
    } bit;                           /*!< Structure used for bit  access             */
    uint32_t all;                    /*!< Type      used for word access             */
} I2CSTOPDETCLR_REG;


/**
 *  @brief  Union type to access the Clear STARTDET Interrupt Register (I2CSTARTDETCLR), offset 0x64.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label              */
        uint32_t CLR           : 1;  /*!< bit:      0  I2CSTARTDETCLR_BIT_CLR        */
        uint32_t RESERVED_31_1 :31;  /*!< bit: 31.. 1                                */
    } bit;                           /*!< Structure used for bit  access             */
    uint32_t all;                    /*!< Type      used for word access             */
} I2CSTARTDETCLR_REG;


/**
 *  @brief  Union type to access the Clear GENCALL Interrupt Register (I2CGENCALLCLR), offset 0x68.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label              */
        uint32_t CLR           : 1;  /*!< bit:      0  I2CGENCALLCLR_BIT_CLR         */
        uint32_t RESERVED_31_1 :31;  /*!< bit: 31.. 1                                */
    } bit;                           /*!< Structure used for bit  access             */
    uint32_t all;                    /*!< Type      used for word access             */
} I2CGENCALLCLR_REG;


/**
 *  @brief  Union type to access the I2C Enable Register (I2CENABLE), offset 0x6C.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label              */
        uint32_t EN            : 1;  /*!< bit:      0  I2CENABLE_BIT_EN              */
        uint32_t RESERVED_31_1 :31;  /*!< bit: 31.. 1                                */
    } bit;                           /*!< Structure used for bit  access             */
    uint32_t all;                    /*!< Type      used for word access             */
} I2CENABLE_REG;


/**
 *  @brief  Union type to access the I2C Status Register (I2CSTS), offset 0x70.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label              */
        uint32_t ACT           : 1;  /*!< bit:      0  I2CSTS_BIT_ACT                */
        uint32_t TFNF          : 1;  /*!< bit:      1  I2CSTS_BIT_TFNF               */
        uint32_t TFE           : 1;  /*!< bit:      2  I2CSTS_BIT_TFE                */
        uint32_t RFNE          : 1;  /*!< bit:      3  I2CSTS_BIT_RFNE               */
        uint32_t RFF           : 1;  /*!< bit:      4  I2CSTS_BIT_RFF                */
        uint32_t MACT          : 1;  /*!< bit:      5  I2CSTS_BIT_MACT               */
        uint32_t SACT          : 1;  /*!< bit:      6  I2CSTS_BIT_SACT               */
        uint32_t RESERVED_31_7 :25;  /*!< bit: 31.. 7                                */
    } bit;                           /*!< Structure used for bit  access             */
    uint32_t all;                    /*!< Type      used for word access             */
} I2CSTS_REG;


/**
 *  @brief  Union type to access the I2C Transmit FIFO Level Register (I2CTFLVL), offset 0x74.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label              */
        uint32_t VAL           : 5;  /*!< bit:  4.. 0  I2CTFLVL_BIT_VAL              */
        uint32_t RESERVED_31_5 :27;  /*!< bit: 31.. 5                                */
    } bit;                           /*!< Structure used for bit  access             */
    uint32_t all;                    /*!< Type      used for word access             */
} I2CTFLVL_REG;


/**
 *  @brief  Union type to access the I2C Receive FIFO Level Register (I2CRFLVL), offset 0x78.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label              */
        uint32_t VAL           : 5;  /*!< bit:  4.. 0  I2CRFLVL_BIT_VAL              */
        uint32_t RESERVED_31_5 :27;  /*!< bit: 31.. 5                                */
    } bit;                           /*!< Structure used for bit  access             */
    uint32_t all;                    /*!< Type      used for word access             */
} I2CRFLVL_REG;


/**
 *  @brief  Union type to access the I2C Transmit Abort Source Register (I2CTXABRTSRC), offset 0x80.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label              */
        uint32_t ADDR7BNACK    : 1;  /*!< bit:      0  I2CTXABRTSRC_BIT_ADDR7BNACK   */
        uint32_t ADDR10B1NACK  : 1;  /*!< bit:      1  I2CTXABRTSRC_BIT_ADDR10B1NACK */
        uint32_t ADDR10B2NACK  : 1;  /*!< bit:      2  I2CTXABRTSRC_BIT_ADDR10B2NACK */
        uint32_t TXDATANACK    : 1;  /*!< bit:      3  I2CTXABRTSRC_BIT_TXDATANACK   */
        uint32_t GCNACK        : 1;  /*!< bit:      4  I2CTXABRTSRC_BIT_GCNACK       */
        uint32_t GCREAD        : 1;  /*!< bit:      5  I2CTXABRTSRC_BIT_GCREAD       */
        uint32_t HSACKDET      : 1;  /*!< bit:      6  I2CTXABRTSRC_BIT_HSACKDET     */
        uint32_t STARTACKDET   : 1;  /*!< bit:      7  I2CTXABRTSRC_BIT_STARTACKDET  */
        uint32_t HSNORESTART   : 1;  /*!< bit:      8  I2CTXABRTSRC_BIT_HSNORESTART  */
        uint32_t STARTNORESTART: 1;  /*!< bit:      9  I2CTXABRTSRC_BIT_STARTNORESTART*/
        uint32_t RD10BNORESTART: 1;  /*!< bit:     10  I2CTXABRTSRC_BIT_RD10BNORESTART*/
        uint32_t MASTERDIS     : 1;  /*!< bit:     11  I2CTXABRTSRC_BIT_MASTERDIS    */
        uint32_t MARBLOST      : 1;  /*!< bit:     12  I2CTXABRTSRC_BIT_MARBLOST     */
        uint32_t SLVFLUSHTF    : 1;  /*!< bit:     13  I2CTXABRTSRC_BIT_SLVFLUSHTF   */
        uint32_t SARBLOST      : 1;  /*!< bit:     14  I2CTXABRTSRC_BIT_SARBLOST     */
        uint32_t SLVRDINTX     : 1;  /*!< bit:     15  I2CTXABRTSRC_BIT_SLVRDINTX    */
        uint32_t RESERVED_31_16:16;  /*!< bit: 31..16                                */
    } bit;                           /*!< Structure used for bit  access             */
    uint32_t all;                    /*!< Type      used for word access             */
} I2CTXABRTSRC_REG;


/**
 *  @brief  Union type to access the I2C SDA Setup Register (I2CSDASETUP), offset 0x94.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label              */
        uint32_t VAL           : 8;  /*!< bit:  7.. 0  I2CSDASETUP_BIT_VAL           */
        uint32_t RESERVED_31_8 :24;  /*!< bit: 31.. 8                                */
    } bit;                           /*!< Structure used for bit  access             */
    uint32_t all;                    /*!< Type      used for word access             */
} I2CSDASETUP_REG;


/**
 *  @brief  Union type to access the I2C ACK General Call Register (I2CACKGC), offset 0x98.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label              */
        uint32_t ACKGC         : 1;  /*!< bit:      0  I2CACKGC_BIT_ACKGC            */
        uint32_t RESERVED_31_1 :31;  /*!< bit: 31.. 1                                */
    } bit;                           /*!< Structure used for bit  access             */
    uint32_t all;                    /*!< Type      used for word access             */
} I2CACKGC_REG;


/**
 *  @brief  Union type to access the I2C Enable Status Register (I2CENSTS), offset 0x9C.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label              */
        uint32_t EN            : 1;  /*!< bit:      0  I2CENSTS_BIT_EN               */
        uint32_t SLVDISONBUSY  : 1;  /*!< bit:      1  I2CENSTS_BIT_SLVDISONBUSY     */
        uint32_t SLVRDLOST     : 1;  /*!< bit:      2  I2CENSTS_BIT_SLVRDLOST        */
        uint32_t RESERVED_31_3 :29;  /*!< bit: 31.. 3                                */
    } bit;                           /*!< Structure used for bit  access             */
    uint32_t all;                    /*!< Type      used for word access             */
} I2CENSTS_REG;





/**
  *  @brief  Structure type to access the I2C Controller (I2C).
  */
typedef struct
{
    __IO I2CCTL_REG             I2CCTL                  ; /*!< Offset: 0x00000000 (RW  )  I2C Control Register                              */
    __IO I2CMASTERADDR_REG      I2CMASTERADDR           ; /*!< Offset: 0x00000004 (RW  )  I2C Master Address Register                       */
    __IO I2CSLVADDR_REG         I2CSLVADDR              ; /*!< Offset: 0x00000008 (RW  )  I2C Slave Address Register                        */
    __IO I2CHSMADDR_REG         I2CHSMADDR              ; /*!< Offset: 0x0000000C (RW  )  I2C High Speed Master Mode Code Address Register  */
    __IO I2CDATACMD_REG         I2CDATACMD              ; /*!< Offset: 0x00000010 (RW  )  I2C Data Buffer and Command Register              */
    __IO I2CSSHCNT_REG          I2CSSHCNT               ; /*!< Offset: 0x00000014 (RW  )  Standard Speed I2C Clock SCL High Count Register  */
    __IO I2CSSLCNT_REG          I2CSSLCNT               ; /*!< Offset: 0x00000018 (RW  )  Standard Speed I2C Clock SCL Low Count Register   */
    __IO I2CFSHCNT_REG          I2CFSHCNT               ; /*!< Offset: 0x0000001C (RW  )  Fast Speed I2C Clock SCL High Count Register      */
    __IO I2CFSLCNT_REG          I2CFSLCNT               ; /*!< Offset: 0x00000020 (RW  )  Fast Speed I2C Clock SCL Low Count Register       */
    __IO I2CHSHCNT_REG          I2CHSHCNT               ; /*!< Offset: 0x00000024 (RW  )  High Speed I2C Clock SCL High Count Register      */
    __IO I2CHSLCNT_REG          I2CHSLCNT               ; /*!< Offset: 0x00000028 (RW  )  High Speed I2C Clock SCL Low Count Register       */
    __I  I2CIF_REG              I2CIF                   ; /*!< Offset: 0x0000002C (RO  )  I2C Interrupt Flag Register                       */
    __IO I2CIE_REG              I2CIE                   ; /*!< Offset: 0x00000030 (RW  )  I2C Interrupt Enable Register                     */
    __I  I2CRAWIF_REG           I2CRAWIF                ; /*!< Offset: 0x00000034 (RO  )  I2C Raw Interrupt Flag Register                   */
    __IO I2CRXTH_REG            I2CRXTH                 ; /*!< Offset: 0x00000038 (RW  )  I2C Receive FIFO Threshold Register               */
    __IO I2CTXTH_REG            I2CTXTH                 ; /*!< Offset: 0x0000003C (RW  )  I2C Transmit FIFO Threshold Register              */
    __I  I2CINTCLR_REG          I2CINTCLR               ; /*!< Offset: 0x00000040 (RO  )  Clear Combined and Individual Interrupt Register  */
    __I  I2CRXUDFCLR_REG        I2CRXUDFCLR             ; /*!< Offset: 0x00000044 (RO  )  Clear RXUDF Interrupt Register                    */
    __I  I2CRXOVFCLR_REG        I2CRXOVFCLR             ; /*!< Offset: 0x00000048 (RO  )  Clear RXOVF Interrupt Register                    */
    __I  I2CTXOVFCLR_REG        I2CTXOVFCLR             ; /*!< Offset: 0x0000004C (RO  )  Clear TXOVF Interrupt Register                    */
    __I  I2CRDREQCLR_REG        I2CRDREQCLR             ; /*!< Offset: 0x00000050 (RO  )  Clear RDREQ Interrupt Register                    */
    __I  I2CTXABRTCLR_REG       I2CTXABRTCLR            ; /*!< Offset: 0x00000054 (RO  )  Clear TXABRT Interrupt Register                   */
    __I  I2CRXDONECLR_REG       I2CRXDONECLR            ; /*!< Offset: 0x00000058 (RO  )  Clear RXDONE Interrupt Register                   */
    __I  I2CACTCLR_REG          I2CACTCLR               ; /*!< Offset: 0x0000005C (RO  )  Clear ACT Interrupt Register                      */
    __I  I2CSTOPDETCLR_REG      I2CSTOPDETCLR           ; /*!< Offset: 0x00000060 (RO  )  Clear STOPDET Interrupt Register                  */
    __I  I2CSTARTDETCLR_REG     I2CSTARTDETCLR          ; /*!< Offset: 0x00000064 (RO  )  Clear STARTDET Interrupt Register                 */
    __I  I2CGENCALLCLR_REG      I2CGENCALLCLR           ; /*!< Offset: 0x00000068 (RO  )  Clear GENCALL Interrupt Register                  */
    __IO I2CENABLE_REG          I2CENABLE               ; /*!< Offset: 0x0000006C (RW  )  I2C Enable Register                               */
    __I  I2CSTS_REG             I2CSTS                  ; /*!< Offset: 0x00000070 (RO  )  I2C Status Register                               */
    __I  I2CTFLVL_REG           I2CTFLVL                ; /*!< Offset: 0x00000074 (RO  )  I2C Transmit FIFO Level Register                  */
    __I  I2CRFLVL_REG           I2CRFLVL                ; /*!< Offset: 0x00000078 (RO  )  I2C Receive FIFO Level Register                   */
         uint32_t               RESERVED0               ; 
    __I  I2CTXABRTSRC_REG       I2CTXABRTSRC            ; /*!< Offset: 0x00000080 (RO  )  I2C Transmit Abort Source Register                */
         uint32_t               RESERVED1               ; 
         uint32_t               RESERVED2               ; 
         uint32_t               RESERVED3               ; 
         uint32_t               RESERVED4               ; 
    __IO I2CSDASETUP_REG        I2CSDASETUP             ; /*!< Offset: 0x00000094 (RW  )  I2C SDA Setup Register                            */
    __IO I2CACKGC_REG           I2CACKGC                ; /*!< Offset: 0x00000098 (RW  )  I2C ACK General Call Register                     */
    __I  I2CENSTS_REG           I2CENSTS                ; /*!< Offset: 0x0000009C (RO  )  I2C Enable Status Register                        */
} I2C_REGS;


/********************************************************************************
*
* Module Name     PWM0
*
*
********************************************************************************/



/**
 *  @brief  Union type to access the Time-Base Period Register (TBPRD), offset 0x0.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :16;  /*!< bit: 15.. 0  TBPRD_BIT_VAL          */
        uint32_t RESERVED_31_16:16;  /*!< bit: 31..16                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} TBPRD_REG;


/**
 *  @brief  Union type to access the Time-Base Phase Register (TBPHS), offset 0x4.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :16;  /*!< bit: 15.. 0  TBPHS_BIT_VAL          */
        uint32_t RESERVED_31_16:16;  /*!< bit: 31..16                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} TBPHS_REG;


/**
 *  @brief  Union type to access the Time-Base Counter Register (TBCNT), offset 0x8.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :16;  /*!< bit: 15.. 0  TBCNT_BIT_VAL          */
        uint32_t RESERVED_31_16:16;  /*!< bit: 31..16                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} TBCNT_REG;


/**
 *  @brief  Union type to access the Time-Base Control Register (TBCTL), offset 0xC.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t CNTMODE       : 2;  /*!< bit:  1.. 0  TBCTL_BIT_CNTMODE      */
        uint32_t PHSEN         : 1;  /*!< bit:      2  TBCTL_BIT_PHSEN        */
        uint32_t PRDLD         : 1;  /*!< bit:      3  TBCTL_BIT_PRDLD        */
        uint32_t SYNCOSEL      : 2;  /*!< bit:  5.. 4  TBCTL_BIT_SYNCOSEL     */
        uint32_t FRCSYNC       : 1;  /*!< bit:      6  TBCTL_BIT_FRCSYNC      */
        uint32_t RESERVED_9_7  : 3;  /*!< bit:  9.. 7                         */
        uint32_t TBCLKDIV      : 3;  /*!< bit: 12..10  TBCTL_BIT_TBCLKDIV     */
        uint32_t PHSDIR        : 1;  /*!< bit:     13  TBCTL_BIT_PHSDIR       */
        uint32_t DBGRUN        : 2;  /*!< bit: 15..14  TBCTL_BIT_DBGRUN       */
        uint32_t RESERVED_31_16:16;  /*!< bit: 31..16                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} TBCTL_REG;


/**
 *  @brief  Union type to access the Time-Base Status Register (TBSTS), offset 0x10.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t CNTDIR        : 1;  /*!< bit:      0  TBSTS_BIT_CNTDIR       */
        uint32_t SYNCI         : 1;  /*!< bit:      1  TBSTS_BIT_SYNCI        */
        uint32_t CNTMAX        : 1;  /*!< bit:      2  TBSTS_BIT_CNTMAX       */
        uint32_t RESERVED_31_3 :29;  /*!< bit: 31.. 3                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} TBSTS_REG;


/**
 *  @brief  Union type to access the Counter-Compare A Threshold Register (CMPA), offset 0x14.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :16;  /*!< bit: 15.. 0  CMPA_BIT_VAL           */
        uint32_t RESERVED_31_16:16;  /*!< bit: 31..16                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} CMPA_REG;


/**
 *  @brief  Union type to access the Counter-Compare B Threshold Register (CMPB), offset 0x18.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :16;  /*!< bit: 15.. 0  CMPB_BIT_VAL           */
        uint32_t RESERVED_31_16:16;  /*!< bit: 31..16                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} CMPB_REG;


/**
 *  @brief  Union type to access the Counter-Compare Control Register (CMPCTL), offset 0x1C.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t LOADAMODE     : 2;  /*!< bit:  1.. 0  CMPCTL_BIT_LOADAMODE   */
        uint32_t LOADBMODE     : 2;  /*!< bit:  3.. 2  CMPCTL_BIT_LOADBMODE   */
        uint32_t SHDWAMODE     : 1;  /*!< bit:      4  CMPCTL_BIT_SHDWAMODE   */
        uint32_t ADVCMPA       : 1;  /*!< bit:      5  CMPCTL_BIT_ADVCMPA     */
        uint32_t SHDWBMODE     : 1;  /*!< bit:      6  CMPCTL_BIT_SHDWBMODE   */
        uint32_t ADVCMPB       : 1;  /*!< bit:      7  CMPCTL_BIT_ADVCMPB     */
        uint32_t SHDWAFULL     : 1;  /*!< bit:      8  CMPCTL_BIT_SHDWAFULL   */
        uint32_t SHDWBFULL     : 1;  /*!< bit:      9  CMPCTL_BIT_SHDWBFULL   */
        uint32_t RESERVED_31_10:22;  /*!< bit: 31..10                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} CMPCTL_REG;


/**
 *  @brief  Union type to access the Action-Qualifier Output A Control Register (AQCTLA), offset 0x24.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t ZRO           : 2;  /*!< bit:  1.. 0  AQCTLA_BIT_ZRO         */
        uint32_t PRD           : 2;  /*!< bit:  3.. 2  AQCTLA_BIT_PRD         */
        uint32_t CAU           : 2;  /*!< bit:  5.. 4  AQCTLA_BIT_CAU         */
        uint32_t CAD           : 2;  /*!< bit:  7.. 6  AQCTLA_BIT_CAD         */
        uint32_t CBU           : 2;  /*!< bit:  9.. 8  AQCTLA_BIT_CBU         */
        uint32_t CBD           : 2;  /*!< bit: 11..10  AQCTLA_BIT_CBD         */
        uint32_t RESERVED_31_12:20;  /*!< bit: 31..12                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} AQCTLA_REG;


/**
 *  @brief  Union type to access the Action-Qualifier B Control Register (AQCTLB), offset 0x28.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t ZRO           : 2;  /*!< bit:  1.. 0  AQCTLB_BIT_ZRO         */
        uint32_t PRD           : 2;  /*!< bit:  3.. 2  AQCTLB_BIT_PRD         */
        uint32_t CAU           : 2;  /*!< bit:  5.. 4  AQCTLB_BIT_CAU         */
        uint32_t CAD           : 2;  /*!< bit:  7.. 6  AQCTLB_BIT_CAD         */
        uint32_t CBU           : 2;  /*!< bit:  9.. 8  AQCTLB_BIT_CBU         */
        uint32_t CBD           : 2;  /*!< bit: 11..10  AQCTLB_BIT_CBD         */
        uint32_t RESERVED_31_12:20;  /*!< bit: 31..12                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} AQCTLB_REG;


/**
 *  @brief  Union type to access the Action-Qualifier Software Force Register (AQSFRC), offset 0x2C.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t ACTSFA        : 2;  /*!< bit:  1.. 0  AQSFRC_BIT_ACTSFA      */
        uint32_t OTSFA         : 1;  /*!< bit:      2  AQSFRC_BIT_OTSFA       */
        uint32_t ACTSFB        : 2;  /*!< bit:  4.. 3  AQSFRC_BIT_ACTSFB      */
        uint32_t OTSFB         : 1;  /*!< bit:      5  AQSFRC_BIT_OTSFB       */
        uint32_t RLDCSF        : 2;  /*!< bit:  7.. 6  AQSFRC_BIT_RLDCSF      */
        uint32_t RESERVED_31_8 :24;  /*!< bit: 31.. 8                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} AQSFRC_REG;


/**
 *  @brief  Union type to access the Action-Qualifier Continuous Software Force Register (AQCSFRC), offset 0x30.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t CSFA          : 2;  /*!< bit:  1.. 0  AQCSFRC_BIT_CSFA       */
        uint32_t CSFB          : 2;  /*!< bit:  3.. 2  AQCSFRC_BIT_CSFB       */
        uint32_t RESERVED_31_4 :28;  /*!< bit: 31.. 4                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} AQCSFRC_REG;


/**
 *  @brief  Union type to access the Dead-Band Generator Control Register (DBCTL), offset 0x34.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t OUTMODE       : 2;  /*!< bit:  1.. 0  DBCTL_BIT_OUTMODE      */
        uint32_t POLSEL        : 2;  /*!< bit:  3.. 2  DBCTL_BIT_POLSEL       */
        uint32_t INMODE        : 2;  /*!< bit:  5.. 4  DBCTL_BIT_INMODE       */
        uint32_t RESERVED_14_6 : 9;  /*!< bit: 14.. 6                         */
        uint32_t HALFCYCLE     : 1;  /*!< bit:     15  DBCTL_BIT_HALFCYCLE    */
        uint32_t RESERVED_31_16:16;  /*!< bit: 31..16                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} DBCTL_REG;


/**
 *  @brief  Union type to access the Dead-Band Generator Rising Edge Delay Register (DBRED), offset 0x38.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :10;  /*!< bit:  9.. 0  DBRED_BIT_VAL          */
        uint32_t RESERVED_31_10:22;  /*!< bit: 31..10                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} DBRED_REG;


/**
 *  @brief  Union type to access the Dead-Band Generator Falling Edge Delay Register (DBFED), offset 0x3C.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :10;  /*!< bit:  9.. 0  DBFED_BIT_VAL          */
        uint32_t RESERVED_31_10:22;  /*!< bit: 31..10                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} DBFED_REG;


/**
 *  @brief  Union type to access the Trip-Zone Select Register (TZSEL), offset 0x44.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t CBC1          : 1;  /*!< bit:      0  TZSEL_BIT_CBC1         */
        uint32_t CBC2          : 1;  /*!< bit:      1  TZSEL_BIT_CBC2         */
        uint32_t CBC3          : 1;  /*!< bit:      2  TZSEL_BIT_CBC3         */
        uint32_t CBC4          : 1;  /*!< bit:      3  TZSEL_BIT_CBC4         */
        uint32_t CBC5          : 1;  /*!< bit:      4  TZSEL_BIT_CBC5         */
        uint32_t CBCCLKERR     : 1;  /*!< bit:      5  TZSEL_BIT_CBCCLKERR    */
        uint32_t DCAEVT2       : 1;  /*!< bit:      6  TZSEL_BIT_DCAEVT2      */
        uint32_t DCBEVT2       : 1;  /*!< bit:      7  TZSEL_BIT_DCBEVT2      */
        uint32_t OSHT1         : 1;  /*!< bit:      8  TZSEL_BIT_OSHT1        */
        uint32_t OSHT2         : 1;  /*!< bit:      9  TZSEL_BIT_OSHT2        */
        uint32_t OSHT3         : 1;  /*!< bit:     10  TZSEL_BIT_OSHT3        */
        uint32_t OSHT4         : 1;  /*!< bit:     11  TZSEL_BIT_OSHT4        */
        uint32_t OSHT5         : 1;  /*!< bit:     12  TZSEL_BIT_OSHT5        */
        uint32_t OSHTCLKERR    : 1;  /*!< bit:     13  TZSEL_BIT_OSHTCLKERR   */
        uint32_t DCAEVT1       : 1;  /*!< bit:     14  TZSEL_BIT_DCAEVT1      */
        uint32_t DCBEVT1       : 1;  /*!< bit:     15  TZSEL_BIT_DCBEVT1      */
        uint32_t CBCCOMP0H     : 1;  /*!< bit:     16  TZSEL_BIT_CBCCOMP0H    */
        uint32_t CBCCOMP0L     : 1;  /*!< bit:     17  TZSEL_BIT_CBCCOMP0L    */
        uint32_t CBCCOMP1H     : 1;  /*!< bit:     18  TZSEL_BIT_CBCCOMP1H    */
        uint32_t CBCCOMP1L     : 1;  /*!< bit:     19  TZSEL_BIT_CBCCOMP1L    */
        uint32_t CBCCOMP2H     : 1;  /*!< bit:     20  TZSEL_BIT_CBCCOMP2H    */
        uint32_t CBCCOMP2L     : 1;  /*!< bit:     21  TZSEL_BIT_CBCCOMP2L    */
        uint32_t OSHTCOMP0H    : 1;  /*!< bit:     22  TZSEL_BIT_OSHTCOMP0H   */
        uint32_t OSHTCOMP0L    : 1;  /*!< bit:     23  TZSEL_BIT_OSHTCOMP0L   */
        uint32_t OSHTCOMP1H    : 1;  /*!< bit:     24  TZSEL_BIT_OSHTCOMP1H   */
        uint32_t OSHTCOMP1L    : 1;  /*!< bit:     25  TZSEL_BIT_OSHTCOMP1L   */
        uint32_t OSHTCOMP2H    : 1;  /*!< bit:     26  TZSEL_BIT_OSHTCOMP2H   */
        uint32_t OSHTCOMP2L    : 1;  /*!< bit:     27  TZSEL_BIT_OSHTCOMP2L   */
        uint32_t CBCDBG        : 1;  /*!< bit:     28  TZSEL_BIT_CBCDBG       */
        uint32_t OSHTDBG       : 1;  /*!< bit:     29  TZSEL_BIT_OSHTDBG      */
        uint32_t RESERVED_31_30: 2;  /*!< bit: 31..30                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} TZSEL_REG;


/**
 *  @brief  Union type to access the Trip-Zone Control Register (TZCTL), offset 0x48.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t TZA           : 2;  /*!< bit:  1.. 0  TZCTL_BIT_TZA          */
        uint32_t TZB           : 2;  /*!< bit:  3.. 2  TZCTL_BIT_TZB          */
        uint32_t DCAEVT1       : 2;  /*!< bit:  5.. 4  TZCTL_BIT_DCAEVT1      */
        uint32_t DCAEVT2       : 2;  /*!< bit:  7.. 6  TZCTL_BIT_DCAEVT2      */
        uint32_t DCBEVT1       : 2;  /*!< bit:  9.. 8  TZCTL_BIT_DCBEVT1      */
        uint32_t DCBEVT2       : 2;  /*!< bit: 11..10  TZCTL_BIT_DCBEVT2      */
        uint32_t RESERVED_31_12:20;  /*!< bit: 31..12                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} TZCTL_REG;


/**
 *  @brief  Union type to access the Trip-Zone Enable Interrupt Register (TZIE), offset 0x4C.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t RESERVED_0_0  : 1;  /*!< bit:      0                         */
        uint32_t CBC           : 1;  /*!< bit:      1  TZIE_BIT_CBC           */
        uint32_t OST           : 1;  /*!< bit:      2  TZIE_BIT_OST           */
        uint32_t DCAEVT1       : 1;  /*!< bit:      3  TZIE_BIT_DCAEVT1       */
        uint32_t DCAEVT2       : 1;  /*!< bit:      4  TZIE_BIT_DCAEVT2       */
        uint32_t DCBEVT1       : 1;  /*!< bit:      5  TZIE_BIT_DCBEVT1       */
        uint32_t DCBEVT2       : 1;  /*!< bit:      6  TZIE_BIT_DCBEVT2       */
        uint32_t RESERVED_31_7 :25;  /*!< bit: 31.. 7                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} TZIE_REG;


/**
 *  @brief  Union type to access the Trip-Zone Flag Register (TZFLG), offset 0x50.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t INT           : 1;  /*!< bit:      0  TZFLG_BIT_INT          */
        uint32_t CBC           : 1;  /*!< bit:      1  TZFLG_BIT_CBC          */
        uint32_t OST           : 1;  /*!< bit:      2  TZFLG_BIT_OST          */
        uint32_t DCAEVT1       : 1;  /*!< bit:      3  TZFLG_BIT_DCAEVT1      */
        uint32_t DCAEVT2       : 1;  /*!< bit:      4  TZFLG_BIT_DCAEVT2      */
        uint32_t DCBEVT1       : 1;  /*!< bit:      5  TZFLG_BIT_DCBEVT1      */
        uint32_t DCBEVT2       : 1;  /*!< bit:      6  TZFLG_BIT_DCBEVT2      */
        uint32_t RESERVED_31_7 :25;  /*!< bit: 31.. 7                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} TZFLG_REG;


/**
 *  @brief  Union type to access the Trip-Zone Clear Register (TZCLR), offset 0x54.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t INT           : 1;  /*!< bit:      0  TZCLR_BIT_INT          */
        uint32_t CBC           : 1;  /*!< bit:      1  TZCLR_BIT_CBC          */
        uint32_t OST           : 1;  /*!< bit:      2  TZCLR_BIT_OST          */
        uint32_t DCAEVT1       : 1;  /*!< bit:      3  TZCLR_BIT_DCAEVT1      */
        uint32_t DCAEVT2       : 1;  /*!< bit:      4  TZCLR_BIT_DCAEVT2      */
        uint32_t DCBEVT1       : 1;  /*!< bit:      5  TZCLR_BIT_DCBEVT1      */
        uint32_t DCBEVT2       : 1;  /*!< bit:      6  TZCLR_BIT_DCBEVT2      */
        uint32_t RESERVED_31_7 :25;  /*!< bit: 31.. 7                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} TZCLR_REG;


/**
 *  @brief  Union type to access the Trip-Zone Force Register (TZFRC), offset 0x58.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t RESERVED_0_0  : 1;  /*!< bit:      0                         */
        uint32_t CBC           : 1;  /*!< bit:      1  TZFRC_BIT_CBC          */
        uint32_t OST           : 1;  /*!< bit:      2  TZFRC_BIT_OST          */
        uint32_t DCAEVT1       : 1;  /*!< bit:      3  TZFRC_BIT_DCAEVT1      */
        uint32_t DCAEVT2       : 1;  /*!< bit:      4  TZFRC_BIT_DCAEVT2      */
        uint32_t DCBEVT1       : 1;  /*!< bit:      5  TZFRC_BIT_DCBEVT1      */
        uint32_t DCBEVT2       : 1;  /*!< bit:      6  TZFRC_BIT_DCBEVT2      */
        uint32_t RESERVED_31_7 :25;  /*!< bit: 31.. 7                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} TZFRC_REG;


/**
 *  @brief  Union type to access the Trip-Zone Digital Compare Event Select Register (TZDCSEL), offset 0x5C.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t DCAEVT1       : 3;  /*!< bit:  2.. 0  TZDCSEL_BIT_DCAEVT1    */
        uint32_t DCAEVT2       : 3;  /*!< bit:  5.. 3  TZDCSEL_BIT_DCAEVT2    */
        uint32_t DCBEVT1       : 3;  /*!< bit:  8.. 6  TZDCSEL_BIT_DCBEVT1    */
        uint32_t DCBEVT2       : 3;  /*!< bit: 11.. 9  TZDCSEL_BIT_DCBEVT2    */
        uint32_t RESERVED_31_12:20;  /*!< bit: 31..12                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} TZDCSEL_REG;


/**
 *  @brief  Union type to access the Digital Compare Trip Select Register (DCTRIPSEL), offset 0x60.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t DCAHCOMPSEL   : 4;  /*!< bit:  3.. 0  DCTRIPSEL_BIT_DCAHCOMPSEL*/
        uint32_t DCALCOMPSEL   : 4;  /*!< bit:  7.. 4  DCTRIPSEL_BIT_DCALCOMPSEL*/
        uint32_t DCBHCOMPSEL   : 4;  /*!< bit: 11.. 8  DCTRIPSEL_BIT_DCBHCOMPSEL*/
        uint32_t DCBLCOMPSEL   : 4;  /*!< bit: 15..12  DCTRIPSEL_BIT_DCBLCOMPSEL*/
        uint32_t RESERVED_31_16:16;  /*!< bit: 31..16                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} DCTRIPSEL_REG;


/**
 *  @brief  Union type to access the Digital Compare A Control Register (DCACTL), offset 0x64.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t EVT1SRCSEL    : 1;  /*!< bit:      0  DCACTL_BIT_EVT1SRCSEL  */
        uint32_t EVT1SRCASYNC  : 1;  /*!< bit:      1  DCACTL_BIT_EVT1SRCASYNC*/
        uint32_t EVT1SOCE      : 1;  /*!< bit:      2  DCACTL_BIT_EVT1SOCE    */
        uint32_t EVT1SYNCE     : 1;  /*!< bit:      3  DCACTL_BIT_EVT1SYNCE   */
        uint32_t RESERVED_7_4  : 4;  /*!< bit:  7.. 4                         */
        uint32_t EVT2SRCSEL    : 1;  /*!< bit:      8  DCACTL_BIT_EVT2SRCSEL  */
        uint32_t EVT2SRCASYNC  : 1;  /*!< bit:      9  DCACTL_BIT_EVT2SRCASYNC*/
        uint32_t RESERVED_31_10:22;  /*!< bit: 31..10                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} DCACTL_REG;


/**
 *  @brief  Union type to access the Digital Compare B Control Register (DCBCTL), offset 0x68.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t EVT1SRCSEL    : 1;  /*!< bit:      0  DCBCTL_BIT_EVT1SRCSEL  */
        uint32_t EVT1SRCASYNC  : 1;  /*!< bit:      1  DCBCTL_BIT_EVT1SRCASYNC*/
        uint32_t EVT1SOCE      : 1;  /*!< bit:      2  DCBCTL_BIT_EVT1SOCE    */
        uint32_t EVT1SYNCE     : 1;  /*!< bit:      3  DCBCTL_BIT_EVT1SYNCE   */
        uint32_t RESERVED_7_4  : 4;  /*!< bit:  7.. 4                         */
        uint32_t EVT2SRCSEL    : 1;  /*!< bit:      8  DCBCTL_BIT_EVT2SRCSEL  */
        uint32_t EVT2SRCASYNC  : 1;  /*!< bit:      9  DCBCTL_BIT_EVT2SRCASYNC*/
        uint32_t RESERVED_31_10:22;  /*!< bit: 31..10                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} DCBCTL_REG;


/**
 *  @brief  Union type to access the Digital Compare Filter Register (DCFCTL), offset 0x6C.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t SRCSEL        : 2;  /*!< bit:  1.. 0  DCFCTL_BIT_SRCSEL      */
        uint32_t BLANKEN       : 1;  /*!< bit:      2  DCFCTL_BIT_BLANKEN     */
        uint32_t BLANKINV      : 1;  /*!< bit:      3  DCFCTL_BIT_BLANKINV    */
        uint32_t PULSESEL      : 2;  /*!< bit:  5.. 4  DCFCTL_BIT_PULSESEL    */
        uint32_t RESERVED_31_6 :26;  /*!< bit: 31.. 6                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} DCFCTL_REG;


/**
 *  @brief  Union type to access the Digital Compare Capture Control Register (DCCAPCTL), offset 0x70.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t CAPEN         : 1;  /*!< bit:      0  DCCAPCTL_BIT_CAPEN     */
        uint32_t SHDWMODE      : 1;  /*!< bit:      1  DCCAPCTL_BIT_SHDWMODE  */
        uint32_t RESERVED_31_2 :30;  /*!< bit: 31.. 2                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} DCCAPCTL_REG;


/**
 *  @brief  Union type to access the Digital Compare Counter Capture Register (DCCAP), offset 0x74.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :16;  /*!< bit: 15.. 0  DCCAP_BIT_VAL          */
        uint32_t RESERVED_31_16:16;  /*!< bit: 31..16                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} DCCAP_REG;


/**
 *  @brief  Union type to access the Digital Compare Filter Offset Register (DCFOFFSET), offset 0x78.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :16;  /*!< bit: 15.. 0  DCFOFFSET_BIT_VAL      */
        uint32_t RESERVED_31_16:16;  /*!< bit: 31..16                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} DCFOFFSET_REG;


/**
 *  @brief  Union type to access the Digital Compare Filter Offset Counter Register (DCFOFFSETCNT), offset 0x7C.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :16;  /*!< bit: 15.. 0  DCFOFFSETCNT_BIT_VAL   */
        uint32_t RESERVED_31_16:16;  /*!< bit: 31..16                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} DCFOFFSETCNT_REG;


/**
 *  @brief  Union type to access the Digital Compare Filter Window Register (DCFWINDOW), offset 0x80.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :16;  /*!< bit: 15.. 0  DCFWINDOW_BIT_VAL      */
        uint32_t RESERVED_31_16:16;  /*!< bit: 31..16                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} DCFWINDOW_REG;


/**
 *  @brief  Union type to access the Digital Compare Filter Window Counter Register (DCFWINDOWCNT), offset 0x84.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           : 8;  /*!< bit:  7.. 0  DCFWINDOWCNT_BIT_VAL   */
        uint32_t RESERVED_31_8 :24;  /*!< bit: 31.. 8                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} DCFWINDOWCNT_REG;


/**
 *  @brief  Union type to access the Event-Trigger Select Register (ETSEL), offset 0x88.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t INTSEL        : 3;  /*!< bit:  2.. 0  ETSEL_BIT_INTSEL       */
        uint32_t INTEN         : 1;  /*!< bit:      3  ETSEL_BIT_INTEN        */
        uint32_t RESERVED_7_4  : 4;  /*!< bit:  7.. 4                         */
        uint32_t SOCASEL       : 3;  /*!< bit: 10.. 8  ETSEL_BIT_SOCASEL      */
        uint32_t SOCAEN        : 1;  /*!< bit:     11  ETSEL_BIT_SOCAEN       */
        uint32_t SOCBSEL       : 3;  /*!< bit: 14..12  ETSEL_BIT_SOCBSEL      */
        uint32_t SOCBEN        : 1;  /*!< bit:     15  ETSEL_BIT_SOCBEN       */
        uint32_t RESERVED_31_16:16;  /*!< bit: 31..16                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} ETSEL_REG;


/**
 *  @brief  Union type to access the Event-Trigger Prescale Register (ETPS), offset 0x8C.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t INTPRD        : 2;  /*!< bit:  1.. 0  ETPS_BIT_INTPRD        */
        uint32_t INTCNT        : 2;  /*!< bit:  3.. 2  ETPS_BIT_INTCNT        */
        uint32_t RESERVED_7_4  : 4;  /*!< bit:  7.. 4                         */
        uint32_t SOCAPRD       : 2;  /*!< bit:  9.. 8  ETPS_BIT_SOCAPRD       */
        uint32_t SOCACNT       : 2;  /*!< bit: 11..10  ETPS_BIT_SOCACNT       */
        uint32_t SOCBPRD       : 2;  /*!< bit: 13..12  ETPS_BIT_SOCBPRD       */
        uint32_t SOCBCNT       : 2;  /*!< bit: 15..14  ETPS_BIT_SOCBCNT       */
        uint32_t RESERVED_31_16:16;  /*!< bit: 31..16                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} ETPS_REG;


/**
 *  @brief  Union type to access the Event-Trigger Flag Register (ETFLG), offset 0x90.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t INT           : 1;  /*!< bit:      0  ETFLG_BIT_INT          */
        uint32_t RESERVED_1_1  : 1;  /*!< bit:      1                         */
        uint32_t SOCA          : 1;  /*!< bit:      2  ETFLG_BIT_SOCA         */
        uint32_t SOCB          : 1;  /*!< bit:      3  ETFLG_BIT_SOCB         */
        uint32_t RESERVED_31_4 :28;  /*!< bit: 31.. 4                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} ETFLG_REG;


/**
 *  @brief  Union type to access the Event-Trigger Clear Register (ETCLR), offset 0x94.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t INT           : 1;  /*!< bit:      0  ETCLR_BIT_INT          */
        uint32_t RESERVED_1_1  : 1;  /*!< bit:      1                         */
        uint32_t SOCA          : 1;  /*!< bit:      2  ETCLR_BIT_SOCA         */
        uint32_t SOCB          : 1;  /*!< bit:      3  ETCLR_BIT_SOCB         */
        uint32_t RESERVED_31_4 :28;  /*!< bit: 31.. 4                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} ETCLR_REG;


/**
 *  @brief  Union type to access the Event-Trigger Force Register (ETFRC), offset 0x98.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t INT           : 1;  /*!< bit:      0  ETFRC_BIT_INT          */
        uint32_t RESERVED_1_1  : 1;  /*!< bit:      1                         */
        uint32_t SOCA          : 1;  /*!< bit:      2  ETFRC_BIT_SOCA         */
        uint32_t SOCB          : 1;  /*!< bit:      3  ETFRC_BIT_SOCB         */
        uint32_t RESERVED_31_4 :28;  /*!< bit: 31.. 4                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} ETFRC_REG;





/**
  *  @brief  Structure type to access the PWM Controller (PWM).
  */
typedef struct
{
    __IO TBPRD_REG            TBPRD                 ; /*!< Offset: 0x00000000 (RW  )  Time-Base Period Register                            */
    __IO TBPHS_REG            TBPHS                 ; /*!< Offset: 0x00000004 (RW  )  Time-Base Phase Register                             */
    __I  TBCNT_REG            TBCNT                 ; /*!< Offset: 0x00000008 (RO  )  Time-Base Counter Register                           */
    __IO TBCTL_REG            TBCTL                 ; /*!< Offset: 0x0000000C (RW  )  Time-Base Control Register                           */
    __IO TBSTS_REG            TBSTS                 ; /*!< Offset: 0x00000010 (RW  )  Time-Base Status Register                            */
    __IO CMPA_REG             CMPA                  ; /*!< Offset: 0x00000014 (RW  )  Counter-Compare A Threshold Register                 */
    __IO CMPB_REG             CMPB                  ; /*!< Offset: 0x00000018 (RW  )  Counter-Compare B Threshold Register                 */
    __IO CMPCTL_REG           CMPCTL                ; /*!< Offset: 0x0000001C (RW  )  Counter-Compare Control Register                     */
         uint32_t             RESERVED0             ; 
    __IO AQCTLA_REG           AQCTLA                ; /*!< Offset: 0x00000024 (RW  )  Action-Qualifier Output A Control Register           */
    __IO AQCTLB_REG           AQCTLB                ; /*!< Offset: 0x00000028 (RW  )  Action-Qualifier B Control Register                  */
    __IO AQSFRC_REG           AQSFRC                ; /*!< Offset: 0x0000002C (RW  )  Action-Qualifier Software Force Register             */
    __IO AQCSFRC_REG          AQCSFRC               ; /*!< Offset: 0x00000030 (RW  )  Action-Qualifier Continuous Software Force Register  */
    __IO DBCTL_REG            DBCTL                 ; /*!< Offset: 0x00000034 (RW  )  Dead-Band Generator Control Register                 */
    __IO DBRED_REG            DBRED                 ; /*!< Offset: 0x00000038 (RW  )  Dead-Band Generator Rising Edge Delay Register       */
    __IO DBFED_REG            DBFED                 ; /*!< Offset: 0x0000003C (RW  )  Dead-Band Generator Falling Edge Delay Register      */
         uint32_t             RESERVED1             ; 
    __IO TZSEL_REG            TZSEL                 ; /*!< Offset: 0x00000044 (RW  )  Trip-Zone Select Register                            */
    __IO TZCTL_REG            TZCTL                 ; /*!< Offset: 0x00000048 (RW  )  Trip-Zone Control Register                           */
    __IO TZIE_REG             TZIE                  ; /*!< Offset: 0x0000004C (RW  )  Trip-Zone Enable Interrupt Register                  */
    __I  TZFLG_REG            TZFLG                 ; /*!< Offset: 0x00000050 (RO  )  Trip-Zone Flag Register                              */
    __IO TZCLR_REG            TZCLR                 ; /*!< Offset: 0x00000054 (RW  )  Trip-Zone Clear Register                             */
    __IO TZFRC_REG            TZFRC                 ; /*!< Offset: 0x00000058 (RW  )  Trip-Zone Force Register                             */
    __IO TZDCSEL_REG          TZDCSEL               ; /*!< Offset: 0x0000005C (RW  )  Trip-Zone Digital Compare Event Select Register      */
    __IO DCTRIPSEL_REG        DCTRIPSEL             ; /*!< Offset: 0x00000060 (RW  )  Digital Compare Trip Select Register                 */
    __IO DCACTL_REG           DCACTL                ; /*!< Offset: 0x00000064 (RW  )  Digital Compare A Control Register                   */
    __IO DCBCTL_REG           DCBCTL                ; /*!< Offset: 0x00000068 (RW  )  Digital Compare B Control Register                   */
    __IO DCFCTL_REG           DCFCTL                ; /*!< Offset: 0x0000006C (RW  )  Digital Compare Filter Register                      */
    __IO DCCAPCTL_REG         DCCAPCTL              ; /*!< Offset: 0x00000070 (RW  )  Digital Compare Capture Control Register             */
    __I  DCCAP_REG            DCCAP                 ; /*!< Offset: 0x00000074 (RO  )  Digital Compare Counter Capture Register             */
    __IO DCFOFFSET_REG        DCFOFFSET             ; /*!< Offset: 0x00000078 (RW  )  Digital Compare Filter Offset Register               */
    __I  DCFOFFSETCNT_REG     DCFOFFSETCNT          ; /*!< Offset: 0x0000007C (RO  )  Digital Compare Filter Offset Counter Register       */
    __IO DCFWINDOW_REG        DCFWINDOW             ; /*!< Offset: 0x00000080 (RW  )  Digital Compare Filter Window Register               */
    __I  DCFWINDOWCNT_REG     DCFWINDOWCNT          ; /*!< Offset: 0x00000084 (RO  )  Digital Compare Filter Window Counter Register       */
    __IO ETSEL_REG            ETSEL                 ; /*!< Offset: 0x00000088 (RW  )  Event-Trigger Select Register                        */
    __IO ETPS_REG             ETPS                  ; /*!< Offset: 0x0000008C (RW  )  Event-Trigger Prescale Register                      */
    __I  ETFLG_REG            ETFLG                 ; /*!< Offset: 0x00000090 (RO  )  Event-Trigger Flag Register                          */
    __O  ETCLR_REG            ETCLR                 ; /*!< Offset: 0x00000094 (WO  )  Event-Trigger Clear Register                         */
    __O  ETFRC_REG            ETFRC                 ; /*!< Offset: 0x00000098 (WO  )  Event-Trigger Force Register                         */
} PWM_REGS;


/********************************************************************************
*
* Module Name     QSPI
*
*
********************************************************************************/



/**
 *  @brief  Union type to access the Serial Interface Control Register 0 (QSPICTL0), offset 0x0.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        uint32_t EN            : 1;  /*!< bit:      0  QSPICTL0_BIT_EN          */
        uint32_t RDY           : 1;  /*!< bit:      1  QSPICTL0_BIT_RDY         */
        uint32_t RESERVED_3_2  : 2;  /*!< bit:  3.. 2                           */
        uint32_t RFIFOEMPTY    : 1;  /*!< bit:      4  QSPICTL0_BIT_RFIFOEMPTY  */
        uint32_t RFIFOFULL     : 1;  /*!< bit:      5  QSPICTL0_BIT_RFIFOFULL   */
        uint32_t WFIFOEMPTY    : 1;  /*!< bit:      6  QSPICTL0_BIT_WFIFOEMPTY  */
        uint32_t WFIFOFULL     : 1;  /*!< bit:      7  QSPICTL0_BIT_WFIFOFULL   */
        uint32_t RFIFOUDF      : 1;  /*!< bit:      8  QSPICTL0_BIT_RFIFOUDF    */
        uint32_t RFIFOOVF      : 1;  /*!< bit:      9  QSPICTL0_BIT_RFIFOOVF    */
        uint32_t WFIFOUDF      : 1;  /*!< bit:     10  QSPICTL0_BIT_WFIFOUDF    */
        uint32_t WFIFOOVF      : 1;  /*!< bit:     11  QSPICTL0_BIT_WFIFOOVF    */
        uint32_t RESERVED_31_12:20;  /*!< bit: 31..12                           */
    } bit;                           /*!< Structure used for bit  access        */
    uint32_t all;                    /*!< Type      used for word access        */
} QSPICTL0_REG;


/**
 *  @brief  Union type to access the Serial Interface Control Register 1 (QSPICTL1), offset 0x4.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        uint32_t CLKDIV        : 5;  /*!< bit:  4.. 0  QSPICTL1_BIT_CLKDIV      */
        uint32_t BYTELEN       : 1;  /*!< bit:      5  QSPICTL1_BIT_BYTELEN     */
        uint32_t RESERVED_6_6  : 1;  /*!< bit:      6                           */
        uint32_t CLKPHS        : 1;  /*!< bit:      7  QSPICTL1_BIT_CLKPHS      */
        uint32_t CLKPOL        : 1;  /*!< bit:      8  QSPICTL1_BIT_CLKPOL      */
        uint32_t FIFOFLUSH     : 1;  /*!< bit:      9  QSPICTL1_BIT_FIFOFLUSH   */
        uint32_t DATAPIN       : 2;  /*!< bit: 11..10  QSPICTL1_BIT_DATAPIN     */
        uint32_t ADDRPIN       : 1;  /*!< bit:     12  QSPICTL1_BIT_ADDRPIN     */
        uint32_t WEN           : 1;  /*!< bit:     13  QSPICTL1_BIT_WEN         */
        uint32_t STOP          : 1;  /*!< bit:     14  QSPICTL1_BIT_STOP        */
        uint32_t START         : 1;  /*!< bit:     15  QSPICTL1_BIT_START       */
        uint32_t RESERVED_31_16:16;  /*!< bit: 31..16                           */
    } bit;                           /*!< Structure used for bit  access        */
    uint32_t all;                    /*!< Type      used for word access        */
} QSPICTL1_REG;


/**
 *  @brief  Union type to access the Serial Interface Data Out Register (QSPIDOUT), offset 0x8.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        uint32_t VAL           :32;  /*!< bit: 31.. 0  QSPIDOUT_BIT_VAL         */
    } bit;                           /*!< Structure used for bit  access        */
    uint32_t all;                    /*!< Type      used for word access        */
} QSPIDOUT_REG;


/**
 *  @brief  Union type to access the Serial Interface Data In Register (QSPIDIN), offset 0xC.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        uint32_t VAL           :32;  /*!< bit: 31.. 0  QSPIDIN_BIT_VAL          */
    } bit;                           /*!< Structure used for bit  access        */
    uint32_t all;                    /*!< Type      used for word access        */
} QSPIDIN_REG;


/**
 *  @brief  Union type to access the Serial Interface Instruction Register (QSPICMD), offset 0x10.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        uint32_t VAL           :16;  /*!< bit: 15.. 0  QSPICMD_BIT_VAL          */
        uint32_t RESERVED_31_16:16;  /*!< bit: 31..16                           */
    } bit;                           /*!< Structure used for bit  access        */
    uint32_t all;                    /*!< Type      used for word access        */
} QSPICMD_REG;


/**
 *  @brief  Union type to access the Serial Interface Address Register (QSPIADDR), offset 0x14.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        uint32_t VAL           :32;  /*!< bit: 31.. 0  QSPIADDR_BIT_VAL         */
    } bit;                           /*!< Structure used for bit  access        */
    uint32_t all;                    /*!< Type      used for word access        */
} QSPIADDR_REG;


/**
 *  @brief  Union type to access the Serial Interface Read Mode Register (QSPIRMODE), offset 0x18.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        uint32_t VAL           :16;  /*!< bit: 15.. 0  QSPIRMODE_BIT_VAL        */
        uint32_t RESERVED_31_16:16;  /*!< bit: 31..16                           */
    } bit;                           /*!< Structure used for bit  access        */
    uint32_t all;                    /*!< Type      used for word access        */
} QSPIRMODE_REG;


/**
 *  @brief  Union type to access the Serial Interface Header Register (QSPIHEADER), offset 0x1C.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        uint32_t CMDCNT        : 2;  /*!< bit:  1.. 0  QSPIHEADER_BIT_CMDCNT    */
        uint32_t RESERVED_3_2  : 2;  /*!< bit:  3.. 2                           */
        uint32_t ADDRCNT       : 3;  /*!< bit:  6.. 4  QSPIHEADER_BIT_ADDRCNT   */
        uint32_t RESERVED_7_7  : 1;  /*!< bit:      7                           */
        uint32_t RMODECNT      : 2;  /*!< bit:  9.. 8  QSPIHEADER_BIT_RMODECNT  */
        uint32_t RESERVED_11_10: 2;  /*!< bit: 11..10                           */
        uint32_t DMYCNT        : 2;  /*!< bit: 13..12  QSPIHEADER_BIT_DMYCNT    */
        uint32_t RESERVED_31_14:18;  /*!< bit: 31..14                           */
    } bit;                           /*!< Structure used for bit  access        */
    uint32_t all;                    /*!< Type      used for word access        */
} QSPIHEADER_REG;


/**
 *  @brief  Union type to access the Serial Interface Data In Count Register (QSPIDINCNT), offset 0x20.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        uint32_t VAL           :20;  /*!< bit: 19.. 0  QSPIDINCNT_BIT_VAL       */
        uint32_t RESERVED_31_20:12;  /*!< bit: 31..20                           */
    } bit;                           /*!< Structure used for bit  access        */
    uint32_t all;                    /*!< Type      used for word access        */
} QSPIDINCNT_REG;


/**
 *  @brief  Union type to access the Serial Interface Timing Register (QSPITIMING), offset 0x24.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        uint32_t DINDLY        : 2;  /*!< bit:  1.. 0  QSPITIMING_BIT_DINDLY    */
        uint32_t RESERVED_3_2  : 2;  /*!< bit:  3.. 2                           */
        uint32_t CLKINDLY      : 2;  /*!< bit:  5.. 4  QSPITIMING_BIT_CLKINDLY  */
        uint32_t CLKEDGE       : 1;  /*!< bit:      6  QSPITIMING_BIT_CLKEDGE   */
        uint32_t RESERVED_7_7  : 1;  /*!< bit:      7                           */
        uint32_t CLKOUTDLY     : 2;  /*!< bit:  9.. 8  QSPITIMING_BIT_CLKOUTDLY */
        uint32_t RESERVED_31_10:22;  /*!< bit: 31..10                           */
    } bit;                           /*!< Structure used for bit  access        */
    uint32_t all;                    /*!< Type      used for word access        */
} QSPITIMING_REG;


/**
 *  @brief  Union type to access the Serial Interface Control Register 2 (QSPICTL2), offset 0x28.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        uint32_t SWRST         : 1;  /*!< bit:      0  QSPICTL2_BIT_SWRST       */
        uint32_t RESERVED_1_1  : 1;  /*!< bit:      1                           */
        uint32_t RESERVED_2_2  : 1;  /*!< bit:      2                           */
        uint32_t RESERVED_7_3  : 5;  /*!< bit:  7.. 3                           */
        uint32_t RESERVED_9_8  : 2;  /*!< bit:  9.. 8                           */
        uint32_t RESERVED_11_10: 2;  /*!< bit: 11..10                           */
        uint32_t RESERVED_13_12: 2;  /*!< bit: 13..12                           */
        uint32_t RESERVED_31_14:18;  /*!< bit: 31..14                           */
    } bit;                           /*!< Structure used for bit  access        */
    uint32_t all;                    /*!< Type      used for word access        */
} QSPICTL2_REG;


/**
 *  @brief  Union type to access the Serial Interface Interrupt Flag Register (QSPIIF), offset 0x2C.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        uint32_t DONE          : 1;  /*!< bit:      0  QSPIIF_BIT_DONE          */
        uint32_t RDY           : 1;  /*!< bit:      1  QSPIIF_BIT_RDY           */
        uint32_t RFIFODMABURST : 1;  /*!< bit:      2  QSPIIF_BIT_RFIFODMABURST */
        uint32_t WFIFODMABURST : 1;  /*!< bit:      3  QSPIIF_BIT_WFIFODMABURST */
        uint32_t RFIFOEMPTY    : 1;  /*!< bit:      4  QSPIIF_BIT_RFIFOEMPTY    */
        uint32_t RFIFOFULL     : 1;  /*!< bit:      5  QSPIIF_BIT_RFIFOFULL     */
        uint32_t WFIFOEMPTY    : 1;  /*!< bit:      6  QSPIIF_BIT_WFIFOEMPTY    */
        uint32_t WFIFOFULL     : 1;  /*!< bit:      7  QSPIIF_BIT_WFIFOFULL     */
        uint32_t RFIFOUDF      : 1;  /*!< bit:      8  QSPIIF_BIT_RFIFOUDF      */
        uint32_t RFIFOOVF      : 1;  /*!< bit:      9  QSPIIF_BIT_RFIFOOVF      */
        uint32_t WFIFOUDF      : 1;  /*!< bit:     10  QSPIIF_BIT_WFIFOUDF      */
        uint32_t WFIFOOVF      : 1;  /*!< bit:     11  QSPIIF_BIT_WFIFOOVF      */
        uint32_t RESERVED_31_12:20;  /*!< bit: 31..12                           */
    } bit;                           /*!< Structure used for bit  access        */
    uint32_t all;                    /*!< Type      used for word access        */
} QSPIIF_REG;


/**
 *  @brief  Union type to access the Serial Interface Interrupt Mask Register (QSPIINTMSK), offset 0x30.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        uint32_t DONE          : 1;  /*!< bit:      0  QSPIINTMSK_BIT_DONE      */
        uint32_t RDY           : 1;  /*!< bit:      1  QSPIINTMSK_BIT_RDY       */
        uint32_t RFIFODMABURST : 1;  /*!< bit:      2  QSPIINTMSK_BIT_RFIFODMABURST*/
        uint32_t WFIFODMABURST : 1;  /*!< bit:      3  QSPIINTMSK_BIT_WFIFODMABURST*/
        uint32_t RFIFOEMPTY    : 1;  /*!< bit:      4  QSPIINTMSK_BIT_RFIFOEMPTY*/
        uint32_t RFIFOFULL     : 1;  /*!< bit:      5  QSPIINTMSK_BIT_RFIFOFULL */
        uint32_t WFIFOEMPTY    : 1;  /*!< bit:      6  QSPIINTMSK_BIT_WFIFOEMPTY*/
        uint32_t WFIFOFULL     : 1;  /*!< bit:      7  QSPIINTMSK_BIT_WFIFOFULL */
        uint32_t RFIFOUDF      : 1;  /*!< bit:      8  QSPIINTMSK_BIT_RFIFOUDF  */
        uint32_t RFIFOOVF      : 1;  /*!< bit:      9  QSPIINTMSK_BIT_RFIFOOVF  */
        uint32_t WFIFOUDF      : 1;  /*!< bit:     10  QSPIINTMSK_BIT_WFIFOUDF  */
        uint32_t WFIFOOVF      : 1;  /*!< bit:     11  QSPIINTMSK_BIT_WFIFOOVF  */
        uint32_t RESERVED1     :20;  /*!< bit: 31..12  QSPIINTMSK_BIT_RESERVED1 */
    } bit;                           /*!< Structure used for bit  access        */
    uint32_t all;                    /*!< Type      used for word access        */
} QSPIINTMSK_REG;


/**
 *  @brief  Union type to access the Serial Interface Interrupt Raw Flag Register (QSPIRAWIF), offset 0x34.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        uint32_t DONE          : 1;  /*!< bit:      0  QSPIRAWIF_BIT_DONE       */
        uint32_t RDY           : 1;  /*!< bit:      1  QSPIRAWIF_BIT_RDY        */
        uint32_t RFIFODMABURST : 1;  /*!< bit:      2  QSPIRAWIF_BIT_RFIFODMABURST*/
        uint32_t WFIFODMABURST : 1;  /*!< bit:      3  QSPIRAWIF_BIT_WFIFODMABURST*/
        uint32_t RFIFOEMPTY    : 1;  /*!< bit:      4  QSPIRAWIF_BIT_RFIFOEMPTY */
        uint32_t RFIFOFULL     : 1;  /*!< bit:      5  QSPIRAWIF_BIT_RFIFOFULL  */
        uint32_t WFIFOEMPTY    : 1;  /*!< bit:      6  QSPIRAWIF_BIT_WFIFOEMPTY */
        uint32_t WFIFOFULL     : 1;  /*!< bit:      7  QSPIRAWIF_BIT_WFIFOFULL  */
        uint32_t RFIFOUDF      : 1;  /*!< bit:      8  QSPIRAWIF_BIT_RFIFOUDF   */
        uint32_t RFIFOOVF      : 1;  /*!< bit:      9  QSPIRAWIF_BIT_RFIFOOVF   */
        uint32_t WFIFOUDF      : 1;  /*!< bit:     10  QSPIRAWIF_BIT_WFIFOUDF   */
        uint32_t WFIFOOVF      : 1;  /*!< bit:     11  QSPIRAWIF_BIT_WFIFOOVF   */
        uint32_t RESERVED_31_12:20;  /*!< bit: 31..12                           */
    } bit;                           /*!< Structure used for bit  access        */
    uint32_t all;                    /*!< Type      used for word access        */
} QSPIRAWIF_REG;


/**
 *  @brief  Union type to access the Serial Interface Interrupt Clear Register (QSPIIC), offset 0x38.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        uint32_t DONE          : 1;  /*!< bit:      0  QSPIIC_BIT_DONE          */
        uint32_t RESERVED_31_1 :31;  /*!< bit: 31.. 1                           */
    } bit;                           /*!< Structure used for bit  access        */
    uint32_t all;                    /*!< Type      used for word access        */
} QSPIIC_REG;





/**
  *  @brief  Structure type to access the QSPI Controller (QSPI).
  */
typedef struct
{
    __IO QSPICTL0_REG       QSPICTL0            ; /*!< Offset: 0x00000000 (RW  )  Serial Interface Control Register 0           */
    __IO QSPICTL1_REG       QSPICTL1            ; /*!< Offset: 0x00000004 (RW  )  Serial Interface Control Register 1           */
    __IO QSPIDOUT_REG       QSPIDOUT            ; /*!< Offset: 0x00000008 (RW  )  Serial Interface Data Out Register            */
    __I  QSPIDIN_REG        QSPIDIN             ; /*!< Offset: 0x0000000C (RO  )  Serial Interface Data In Register             */
    __IO QSPICMD_REG        QSPICMD             ; /*!< Offset: 0x00000010 (RW  )  Serial Interface Instruction Register         */
    __IO QSPIADDR_REG       QSPIADDR            ; /*!< Offset: 0x00000014 (RW  )  Serial Interface Address Register             */
    __IO QSPIRMODE_REG      QSPIRMODE           ; /*!< Offset: 0x00000018 (RW  )  Serial Interface Read Mode Register           */
    __IO QSPIHEADER_REG     QSPIHEADER          ; /*!< Offset: 0x0000001C (RW  )  Serial Interface Header Register              */
    __IO QSPIDINCNT_REG     QSPIDINCNT          ; /*!< Offset: 0x00000020 (RW  )  Serial Interface Data In Count Register       */
    __IO QSPITIMING_REG     QSPITIMING          ; /*!< Offset: 0x00000024 (RW  )  Serial Interface Timing Register              */
    __IO QSPICTL2_REG       QSPICTL2            ; /*!< Offset: 0x00000028 (RW  )  Serial Interface Control Register 2           */
    __I  QSPIIF_REG         QSPIIF              ; /*!< Offset: 0x0000002C (RO  )  Serial Interface Interrupt Flag Register      */
    __IO QSPIINTMSK_REG     QSPIINTMSK          ; /*!< Offset: 0x00000030 (RW  )  Serial Interface Interrupt Mask Register      */
    __I  QSPIRAWIF_REG      QSPIRAWIF           ; /*!< Offset: 0x00000034 (RO  )  Serial Interface Interrupt Raw Flag Register  */
    __IO QSPIIC_REG         QSPIIC              ; /*!< Offset: 0x00000038 (RW  )  Serial Interface Interrupt Clear Register     */
} QSPI_REGS;


/********************************************************************************
*
* Module Name     PGA
*
*
********************************************************************************/



/**
 *  @brief  Union type to access the PGA Channel Select Control Register 0 (PGACHCTL0), offset 0xE8.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t CHSEL0P       : 3;  /*!< bit:  2.. 0  PGACHCTL0_BIT_CHSEL0P  */
        uint32_t CHSEL1P       : 3;  /*!< bit:  5.. 3  PGACHCTL0_BIT_CHSEL1P  */
        uint32_t CHSEL2P       : 3;  /*!< bit:  8.. 6  PGACHCTL0_BIT_CHSEL2P  */
        uint32_t GAIN0P        : 2;  /*!< bit: 10.. 9  PGACHCTL0_BIT_GAIN0P   */
        uint32_t GAIN1P        : 2;  /*!< bit: 12..11  PGACHCTL0_BIT_GAIN1P   */
        uint32_t GAIN2P        : 2;  /*!< bit: 14..13  PGACHCTL0_BIT_GAIN2P   */
        uint32_t RESERVED_31_15:17;  /*!< bit: 31..15                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} PGACHCTL0_REG;


/**
 *  @brief  Union type to access the PGA Channel Select Control Register 1 (PGACHCTL1), offset 0xEC.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t CHSEL0N       : 3;  /*!< bit:  2.. 0  PGACHCTL1_BIT_CHSEL0N  */
        uint32_t CHSEL1N       : 3;  /*!< bit:  5.. 3  PGACHCTL1_BIT_CHSEL1N  */
        uint32_t CHSEL2N       : 3;  /*!< bit:  8.. 6  PGACHCTL1_BIT_CHSEL2N  */
        uint32_t GAIN0N        : 2;  /*!< bit: 10.. 9  PGACHCTL1_BIT_GAIN0N   */
        uint32_t GAIN1N        : 2;  /*!< bit: 12..11  PGACHCTL1_BIT_GAIN1N   */
        uint32_t GAIN2N        : 2;  /*!< bit: 14..13  PGACHCTL1_BIT_GAIN2N   */
        uint32_t RDIVSEL0      : 5;  /*!< bit: 19..15  PGACHCTL1_BIT_RDIVSEL0 */
        uint32_t RDIVSEL1      : 5;  /*!< bit: 24..20  PGACHCTL1_BIT_RDIVSEL1 */
        uint32_t RDIVSEL2      : 5;  /*!< bit: 29..25  PGACHCTL1_BIT_RDIVSEL2 */
        uint32_t RESERVED_31_30: 2;  /*!< bit: 31..30                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} PGACHCTL1_REG;


/**
 *  @brief  Union type to access the PGA Control Register 0 (PGACTL0), offset 0xF0.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t RESERVED_0_0  : 1;  /*!< bit:      0                         */
        uint32_t RESERVED_1_1  : 1;  /*!< bit:      1                         */
        uint32_t RESERVED_2_2  : 1;  /*!< bit:      2                         */
        uint32_t BYP0P         : 1;  /*!< bit:      3  PGACTL0_BIT_BYP0P      */
        uint32_t BYP1P         : 1;  /*!< bit:      4  PGACTL0_BIT_BYP1P      */
        uint32_t BYP2P         : 1;  /*!< bit:      5  PGACTL0_BIT_BYP2P      */
        uint32_t SINGLE0P      : 1;  /*!< bit:      6  PGACTL0_BIT_SINGLE0P   */
        uint32_t SINGLE1P      : 1;  /*!< bit:      7  PGACTL0_BIT_SINGLE1P   */
        uint32_t SINGLE2P      : 1;  /*!< bit:      8  PGACTL0_BIT_SINGLE2P   */
        uint32_t CMEN0P        : 1;  /*!< bit:      9  PGACTL0_BIT_CMEN0P     */
        uint32_t CMEN1P        : 1;  /*!< bit:     10  PGACTL0_BIT_CMEN1P     */
        uint32_t CMEN2P        : 1;  /*!< bit:     11  PGACTL0_BIT_CMEN2P     */
        uint32_t RESERVED_14_12: 3;  /*!< bit: 14..12                         */
        uint32_t EN0P          : 1;  /*!< bit:     15  PGACTL0_BIT_EN0P       */
        uint32_t EN1P          : 1;  /*!< bit:     16  PGACTL0_BIT_EN1P       */
        uint32_t EN2P          : 1;  /*!< bit:     17  PGACTL0_BIT_EN2P       */
        uint32_t RESERVED_31_18:14;  /*!< bit: 31..18                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} PGACTL0_REG;


/**
 *  @brief  Union type to access the PGA Control Register 1 (PGACTL1), offset 0xF4.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t RESERVED_0_0  : 1;  /*!< bit:      0                         */
        uint32_t RESERVED_1_1  : 1;  /*!< bit:      1                         */
        uint32_t RESERVED_2_2  : 1;  /*!< bit:      2                         */
        uint32_t BYP0N         : 1;  /*!< bit:      3  PGACTL1_BIT_BYP0N      */
        uint32_t BYP1N         : 1;  /*!< bit:      4  PGACTL1_BIT_BYP1N      */
        uint32_t BYP2N         : 1;  /*!< bit:      5  PGACTL1_BIT_BYP2N      */
        uint32_t SINGLE0N      : 1;  /*!< bit:      6  PGACTL1_BIT_SINGLE0N   */
        uint32_t SINGLE1N      : 1;  /*!< bit:      7  PGACTL1_BIT_SINGLE1N   */
        uint32_t SINGLE2N      : 1;  /*!< bit:      8  PGACTL1_BIT_SINGLE2N   */
        uint32_t CMEN0N        : 1;  /*!< bit:      9  PGACTL1_BIT_CMEN0N     */
        uint32_t CMEN1N        : 1;  /*!< bit:     10  PGACTL1_BIT_CMEN1N     */
        uint32_t CMEN2N        : 1;  /*!< bit:     11  PGACTL1_BIT_CMEN2N     */
        uint32_t RESERVED_14_12: 3;  /*!< bit: 14..12                         */
        uint32_t EN0N          : 1;  /*!< bit:     15  PGACTL1_BIT_EN0N       */
        uint32_t EN1N          : 1;  /*!< bit:     16  PGACTL1_BIT_EN1N       */
        uint32_t EN2N          : 1;  /*!< bit:     17  PGACTL1_BIT_EN2N       */
        uint32_t RDIVEN0       : 1;  /*!< bit:     18  PGACTL1_BIT_RDIVEN0    */
        uint32_t RDIVEN1       : 1;  /*!< bit:     19  PGACTL1_BIT_RDIVEN1    */
        uint32_t RDIVEN2       : 1;  /*!< bit:     20  PGACTL1_BIT_RDIVEN2    */
        uint32_t RESERVED_31_21:11;  /*!< bit: 31..21                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} PGACTL1_REG;





/**
  *  @brief  Structure type to access the PGA Controller (PGA).
  */
typedef struct
{
         uint32_t          RESERVED0[58]      ; 
    __IO PGACHCTL0_REG     PGACHCTL0          ; /*!< Offset: 0x000000E8 (RW  )  PGA Channel Select Control Register 0  */
    __IO PGACHCTL1_REG     PGACHCTL1          ; /*!< Offset: 0x000000EC (RW  )  PGA Channel Select Control Register 1  */
    __IO PGACTL0_REG       PGACTL0            ; /*!< Offset: 0x000000F0 (RW  )  PGA Control Register 0                 */
    __IO PGACTL1_REG       PGACTL1            ; /*!< Offset: 0x000000F4 (RW  )  PGA Control Register 1                 */
} PGA_REGS;


/********************************************************************************
*
* Module Name     COMP
*
*
********************************************************************************/



/**
 *  @brief  Union type to access the Comparator Input Selection Register (COMPSEL), offset 0xE0.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t CHSEL0        : 2;  /*!< bit:  1.. 0  COMPSEL_BIT_CHSEL0     */
        uint32_t CHSEL1        : 2;  /*!< bit:  3.. 2  COMPSEL_BIT_CHSEL1     */
        uint32_t CHSEL2        : 2;  /*!< bit:  5.. 4  COMPSEL_BIT_CHSEL2     */
        uint32_t RESERVED_31_6 :26;  /*!< bit: 31.. 6                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} COMPSEL_REG;


/**
 *  @brief  Union type to access the Comparator Control Register (COMPCTL), offset 0xE4.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t RESERVED_0_0  : 1;  /*!< bit:      0                         */
        uint32_t RESERVED_1_1  : 1;  /*!< bit:      1                         */
        uint32_t RESERVED_2_2  : 1;  /*!< bit:      2                         */
        uint32_t RESERVED_3_3  : 1;  /*!< bit:      3                         */
        uint32_t RESERVED_4_4  : 1;  /*!< bit:      4                         */
        uint32_t RESERVED_5_5  : 1;  /*!< bit:      5                         */
        uint32_t COMP0LINV     : 1;  /*!< bit:      6  COMPCTL_BIT_COMP0LINV  */
        uint32_t COMP1LINV     : 1;  /*!< bit:      7  COMPCTL_BIT_COMP1LINV  */
        uint32_t COMP2LINV     : 1;  /*!< bit:      8  COMPCTL_BIT_COMP2LINV  */
        uint32_t COMP0HINV     : 1;  /*!< bit:      9  COMPCTL_BIT_COMP0HINV  */
        uint32_t COMP1HINV     : 1;  /*!< bit:     10  COMPCTL_BIT_COMP1HINV  */
        uint32_t COMP2HINV     : 1;  /*!< bit:     11  COMPCTL_BIT_COMP2HINV  */
        uint32_t COMP0LEN      : 1;  /*!< bit:     12  COMPCTL_BIT_COMP0LEN   */
        uint32_t COMP1LEN      : 1;  /*!< bit:     13  COMPCTL_BIT_COMP1LEN   */
        uint32_t COMP2LEN      : 1;  /*!< bit:     14  COMPCTL_BIT_COMP2LEN   */
        uint32_t COMP0HEN      : 1;  /*!< bit:     15  COMPCTL_BIT_COMP0HEN   */
        uint32_t COMP1HEN      : 1;  /*!< bit:     16  COMPCTL_BIT_COMP1HEN   */
        uint32_t COMP2HEN      : 1;  /*!< bit:     17  COMPCTL_BIT_COMP2HEN   */
        uint32_t COMP0LHYEN    : 1;  /*!< bit:     18  COMPCTL_BIT_COMP0LHYEN */
        uint32_t COMP1LHYEN    : 1;  /*!< bit:     19  COMPCTL_BIT_COMP1LHYEN */
        uint32_t COMP2LHYEN    : 1;  /*!< bit:     20  COMPCTL_BIT_COMP2LHYEN */
        uint32_t COMP0HHYEN    : 1;  /*!< bit:     21  COMPCTL_BIT_COMP0HHYEN */
        uint32_t COMP1HHYEN    : 1;  /*!< bit:     22  COMPCTL_BIT_COMP1HHYEN */
        uint32_t COMP2HHYEN    : 1;  /*!< bit:     23  COMPCTL_BIT_COMP2HHYEN */
        uint32_t DGPRDSEL      : 7;  /*!< bit: 30..24  COMPCTL_BIT_DGPRDSEL   */
        uint32_t DGEN          : 1;  /*!< bit:     31  COMPCTL_BIT_DGEN       */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} COMPCTL_REG;


/**
 *  @brief  Union type to access the DAC Code Register (DACCODE), offset 0xF8.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t LO            :10;  /*!< bit:  9.. 0  DACCODE_BIT_LO         */
        uint32_t HI            :10;  /*!< bit: 19..10  DACCODE_BIT_HI         */
        uint32_t RESERVED_31_20:12;  /*!< bit: 31..20                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} DACCODE_REG;


/**
 *  @brief  Union type to access the DAC Control Register (DACCTL), offset 0xFC.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t RESERVED_0_0  : 1;  /*!< bit:      0                         */
        uint32_t RESERVED_1_1  : 1;  /*!< bit:      1                         */
        uint32_t RANGE2XLO     : 1;  /*!< bit:      2  DACCTL_BIT_RANGE2XLO   */
        uint32_t RANGE2XHI     : 1;  /*!< bit:      3  DACCTL_BIT_RANGE2XHI   */
        uint32_t DIVSRCLO      : 1;  /*!< bit:      4  DACCTL_BIT_DIVSRCLO    */
        uint32_t DIVSRCHI      : 1;  /*!< bit:      5  DACCTL_BIT_DIVSRCHI    */
        uint32_t ENLO          : 1;  /*!< bit:      6  DACCTL_BIT_ENLO        */
        uint32_t ENHI          : 1;  /*!< bit:      7  DACCTL_BIT_ENHI        */
        uint32_t RESERVED_31_8 :24;  /*!< bit: 31.. 8                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} DACCTL_REG;





/**
  *  @brief  Structure type to access the COMP Controller (COMP).
  */
typedef struct
{
         uint32_t        RESERVED0[56]    ; 
    __IO COMPSEL_REG     COMPSEL          ; /*!< Offset: 0x000000E0 (RW  )  Comparator Input Selection Register  */
    __IO COMPCTL_REG     COMPCTL          ; /*!< Offset: 0x000000E4 (RW  )  Comparator Control Register          */
         uint32_t        RESERVED1[4]     ; 
    __IO DACCODE_REG     DACCODE          ; /*!< Offset: 0x000000F8 (RW  )  DAC Code Register                    */
    __IO DACCTL_REG      DACCTL           ; /*!< Offset: 0x000000FC (RW  )  DAC Control Register                 */
} COMP_REGS;


/********************************************************************************
*
* Module Name     ADC
*
*
********************************************************************************/



/**
 *  @brief  Union type to access the ADC Control Register 0 (ADCCTL0), offset 0x0.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label            */
        uint32_t RESERVED_2_0  : 3;  /*!< bit:  2.. 0                              */
        uint32_t VREFSEL       : 1;  /*!< bit:      3  ADCCTL0_BIT_VREFSEL         */
        uint32_t RESERVED_4_4  : 1;  /*!< bit:      4                              */
        uint32_t VREFEN        : 1;  /*!< bit:      5  ADCCTL0_BIT_VREFEN          */
        uint32_t RESERVED_13_6 : 8;  /*!< bit: 13.. 6                              */
        uint32_t EN            : 1;  /*!< bit:     14  ADCCTL0_BIT_EN              */
        uint32_t RST           : 1;  /*!< bit:     15  ADCCTL0_BIT_RST             */
        uint32_t RESERVED_16_16: 1;  /*!< bit:     16                              */
        uint32_t RESERVED_17_17: 1;  /*!< bit:     17                              */
        uint32_t RESERVED_18_18: 1;  /*!< bit:     18                              */
        uint32_t RESERVED_19_19: 1;  /*!< bit:     19                              */
        uint32_t RESERVED_31_20:12;  /*!< bit: 31..20                              */
    } bit;                           /*!< Structure used for bit  access           */
    uint32_t all;                    /*!< Type      used for word access           */
} ADCCTL0_REG;


/**
 *  @brief  Union type to access the ADC Control Register 1 (ADCCTL1), offset 0x4.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label            */
        uint32_t CLKSYNCEN     : 1;  /*!< bit:      0  ADCCTL1_BIT_CLKSYNCEN       */
        uint32_t CLKDIV        : 3;  /*!< bit:  3.. 1  ADCCTL1_BIT_CLKDIV          */
        uint32_t CLKSEL        : 2;  /*!< bit:  5.. 4  ADCCTL1_BIT_CLKSEL          */
        uint32_t RESERVED_7_6  : 2;  /*!< bit:  7.. 6                              */
        uint32_t RESERVED_8_8  : 1;  /*!< bit:      8                              */
        uint32_t DACSETTLECTL  : 2;  /*!< bit: 10.. 9  ADCCTL1_BIT_DACSETTLECTL    */
        uint32_t SPEEDUP       : 1;  /*!< bit:     11  ADCCTL1_BIT_SPEEDUP         */
        uint32_t DLYSEL        : 4;  /*!< bit: 15..12  ADCCTL1_BIT_DLYSEL          */
        uint32_t SHANTIELO     : 1;  /*!< bit:     16  ADCCTL1_BIT_SHANTIELO       */
        uint32_t SHBNTIELO     : 1;  /*!< bit:     17  ADCCTL1_BIT_SHBNTIELO       */
        uint32_t SHAPTIELO     : 1;  /*!< bit:     18  ADCCTL1_BIT_SHAPTIELO       */
        uint32_t SHBPTIELO     : 1;  /*!< bit:     19  ADCCTL1_BIT_SHBPTIELO       */
        uint32_t SHANTIEEN     : 1;  /*!< bit:     20  ADCCTL1_BIT_SHANTIEEN       */
        uint32_t SHBNTIEEN     : 1;  /*!< bit:     21  ADCCTL1_BIT_SHBNTIEEN       */
        uint32_t SHAPTIEEN     : 1;  /*!< bit:     22  ADCCTL1_BIT_SHAPTIEEN       */
        uint32_t SHBPTIEEN     : 1;  /*!< bit:     23  ADCCTL1_BIT_SHBPTIEEN       */
        uint32_t COMPPREAMPCTL : 3;  /*!< bit: 26..24  ADCCTL1_BIT_COMPPREAMPCTL   */
        uint32_t RESERVED_31_27: 5;  /*!< bit: 31..27                              */
    } bit;                           /*!< Structure used for bit  access           */
    uint32_t all;                    /*!< Type      used for word access           */
} ADCCTL1_REG;


/**
 *  @brief  Union type to access the ADC Interrupt Flag Register (ADCIF), offset 0x8.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label            */
        uint32_t INT0          : 1;  /*!< bit:      0  ADCIF_BIT_INT0              */
        uint32_t INT1          : 1;  /*!< bit:      1  ADCIF_BIT_INT1              */
        uint32_t INT2          : 1;  /*!< bit:      2  ADCIF_BIT_INT2              */
        uint32_t INT3          : 1;  /*!< bit:      3  ADCIF_BIT_INT3              */
        uint32_t INT4          : 1;  /*!< bit:      4  ADCIF_BIT_INT4              */
        uint32_t INT5          : 1;  /*!< bit:      5  ADCIF_BIT_INT5              */
        uint32_t INT6          : 1;  /*!< bit:      6  ADCIF_BIT_INT6              */
        uint32_t INT7          : 1;  /*!< bit:      7  ADCIF_BIT_INT7              */
        uint32_t INT8          : 1;  /*!< bit:      8  ADCIF_BIT_INT8              */
        uint32_t INT9          : 1;  /*!< bit:      9  ADCIF_BIT_INT9              */
        uint32_t INT10         : 1;  /*!< bit:     10  ADCIF_BIT_INT10             */
        uint32_t INT11         : 1;  /*!< bit:     11  ADCIF_BIT_INT11             */
        uint32_t INT12         : 1;  /*!< bit:     12  ADCIF_BIT_INT12             */
        uint32_t INT13         : 1;  /*!< bit:     13  ADCIF_BIT_INT13             */
        uint32_t INT14         : 1;  /*!< bit:     14  ADCIF_BIT_INT14             */
        uint32_t INT15         : 1;  /*!< bit:     15  ADCIF_BIT_INT15             */
        uint32_t RESERVED_31_16:16;  /*!< bit: 31..16                              */
    } bit;                           /*!< Structure used for bit  access           */
    uint32_t all;                    /*!< Type      used for word access           */
} ADCIF_REG;


/**
 *  @brief  Union type to access the ADC Interrupt Flag Clear Register (ADCIC), offset 0xC.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label            */
        uint32_t INT0          : 1;  /*!< bit:      0  ADCIC_BIT_INT0              */
        uint32_t INT1          : 1;  /*!< bit:      1  ADCIC_BIT_INT1              */
        uint32_t INT2          : 1;  /*!< bit:      2  ADCIC_BIT_INT2              */
        uint32_t INT3          : 1;  /*!< bit:      3  ADCIC_BIT_INT3              */
        uint32_t INT4          : 1;  /*!< bit:      4  ADCIC_BIT_INT4              */
        uint32_t INT5          : 1;  /*!< bit:      5  ADCIC_BIT_INT5              */
        uint32_t INT6          : 1;  /*!< bit:      6  ADCIC_BIT_INT6              */
        uint32_t INT7          : 1;  /*!< bit:      7  ADCIC_BIT_INT7              */
        uint32_t INT8          : 1;  /*!< bit:      8  ADCIC_BIT_INT8              */
        uint32_t INT9          : 1;  /*!< bit:      9  ADCIC_BIT_INT9              */
        uint32_t INT10         : 1;  /*!< bit:     10  ADCIC_BIT_INT10             */
        uint32_t INT11         : 1;  /*!< bit:     11  ADCIC_BIT_INT11             */
        uint32_t INT12         : 1;  /*!< bit:     12  ADCIC_BIT_INT12             */
        uint32_t INT13         : 1;  /*!< bit:     13  ADCIC_BIT_INT13             */
        uint32_t INT14         : 1;  /*!< bit:     14  ADCIC_BIT_INT14             */
        uint32_t INT15         : 1;  /*!< bit:     15  ADCIC_BIT_INT15             */
        uint32_t RESERVED_31_16:16;  /*!< bit: 31..16                              */
    } bit;                           /*!< Structure used for bit  access           */
    uint32_t all;                    /*!< Type      used for word access           */
} ADCIC_REG;


/**
 *  @brief  Union type to access the ADC Interrupt Overflow Flag Register (ADCIOVF), offset 0x10.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label            */
        uint32_t INT0          : 1;  /*!< bit:      0  ADCIOVF_BIT_INT0            */
        uint32_t INT1          : 1;  /*!< bit:      1  ADCIOVF_BIT_INT1            */
        uint32_t INT2          : 1;  /*!< bit:      2  ADCIOVF_BIT_INT2            */
        uint32_t INT3          : 1;  /*!< bit:      3  ADCIOVF_BIT_INT3            */
        uint32_t INT4          : 1;  /*!< bit:      4  ADCIOVF_BIT_INT4            */
        uint32_t INT5          : 1;  /*!< bit:      5  ADCIOVF_BIT_INT5            */
        uint32_t INT6          : 1;  /*!< bit:      6  ADCIOVF_BIT_INT6            */
        uint32_t INT7          : 1;  /*!< bit:      7  ADCIOVF_BIT_INT7            */
        uint32_t INT8          : 1;  /*!< bit:      8  ADCIOVF_BIT_INT8            */
        uint32_t INT9          : 1;  /*!< bit:      9  ADCIOVF_BIT_INT9            */
        uint32_t INT10         : 1;  /*!< bit:     10  ADCIOVF_BIT_INT10           */
        uint32_t INT11         : 1;  /*!< bit:     11  ADCIOVF_BIT_INT11           */
        uint32_t INT12         : 1;  /*!< bit:     12  ADCIOVF_BIT_INT12           */
        uint32_t INT13         : 1;  /*!< bit:     13  ADCIOVF_BIT_INT13           */
        uint32_t INT14         : 1;  /*!< bit:     14  ADCIOVF_BIT_INT14           */
        uint32_t INT15         : 1;  /*!< bit:     15  ADCIOVF_BIT_INT15           */
        uint32_t RESERVED_31_16:16;  /*!< bit: 31..16                              */
    } bit;                           /*!< Structure used for bit  access           */
    uint32_t all;                    /*!< Type      used for word access           */
} ADCIOVF_REG;


/**
 *  @brief  Union type to access the ADC Interrupt Overflow Flag Clear Register (ADCIOVFC), offset 0x14.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label            */
        uint32_t INT0          : 1;  /*!< bit:      0  ADCIOVFC_BIT_INT0           */
        uint32_t INT1          : 1;  /*!< bit:      1  ADCIOVFC_BIT_INT1           */
        uint32_t INT2          : 1;  /*!< bit:      2  ADCIOVFC_BIT_INT2           */
        uint32_t INT3          : 1;  /*!< bit:      3  ADCIOVFC_BIT_INT3           */
        uint32_t INT4          : 1;  /*!< bit:      4  ADCIOVFC_BIT_INT4           */
        uint32_t INT5          : 1;  /*!< bit:      5  ADCIOVFC_BIT_INT5           */
        uint32_t INT6          : 1;  /*!< bit:      6  ADCIOVFC_BIT_INT6           */
        uint32_t INT7          : 1;  /*!< bit:      7  ADCIOVFC_BIT_INT7           */
        uint32_t INT8          : 1;  /*!< bit:      8  ADCIOVFC_BIT_INT8           */
        uint32_t INT9          : 1;  /*!< bit:      9  ADCIOVFC_BIT_INT9           */
        uint32_t INT10         : 1;  /*!< bit:     10  ADCIOVFC_BIT_INT10          */
        uint32_t INT11         : 1;  /*!< bit:     11  ADCIOVFC_BIT_INT11          */
        uint32_t INT12         : 1;  /*!< bit:     12  ADCIOVFC_BIT_INT12          */
        uint32_t INT13         : 1;  /*!< bit:     13  ADCIOVFC_BIT_INT13          */
        uint32_t INT14         : 1;  /*!< bit:     14  ADCIOVFC_BIT_INT14          */
        uint32_t INT15         : 1;  /*!< bit:     15  ADCIOVFC_BIT_INT15          */
        uint32_t RESERVED_31_16:16;  /*!< bit: 31..16                              */
    } bit;                           /*!< Structure used for bit  access           */
    uint32_t all;                    /*!< Type      used for word access           */
} ADCIOVFC_REG;


/**
 *  @brief  Union type to access the ADC Interrupt Select Register 0 (ADCINTSEL0), offset 0x18.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label            */
        uint32_t RESERVED_4_0  : 5;  /*!< bit:  4.. 0                              */
        uint32_t INT0EN        : 1;  /*!< bit:      5  ADCINTSEL0_BIT_INT0EN       */
        uint32_t INT0CONT      : 1;  /*!< bit:      6  ADCINTSEL0_BIT_INT0CONT     */
        uint32_t RESERVED_12_7 : 6;  /*!< bit: 12.. 7                              */
        uint32_t INT1EN        : 1;  /*!< bit:     13  ADCINTSEL0_BIT_INT1EN       */
        uint32_t INT1CONT      : 1;  /*!< bit:     14  ADCINTSEL0_BIT_INT1CONT     */
        uint32_t RESERVED_31_15:17;  /*!< bit: 31..15                              */
    } bit;                           /*!< Structure used for bit  access           */
    uint32_t all;                    /*!< Type      used for word access           */
} ADCINTSEL0_REG;


/**
 *  @brief  Union type to access the ADC Interrupt Select Register 1 (ADCINTSEL1), offset 0x1C.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label            */
        uint32_t RESERVED_4_0  : 5;  /*!< bit:  4.. 0                              */
        uint32_t INT2EN        : 1;  /*!< bit:      5  ADCINTSEL1_BIT_INT2EN       */
        uint32_t INT2CONT      : 1;  /*!< bit:      6  ADCINTSEL1_BIT_INT2CONT     */
        uint32_t RESERVED_12_7 : 6;  /*!< bit: 12.. 7                              */
        uint32_t INT3EN        : 1;  /*!< bit:     13  ADCINTSEL1_BIT_INT3EN       */
        uint32_t INT3CONT      : 1;  /*!< bit:     14  ADCINTSEL1_BIT_INT3CONT     */
        uint32_t RESERVED_31_15:17;  /*!< bit: 31..15                              */
    } bit;                           /*!< Structure used for bit  access           */
    uint32_t all;                    /*!< Type      used for word access           */
} ADCINTSEL1_REG;


/**
 *  @brief  Union type to access the ADC Interrupt Select Register 2 (ADCINTSEL2), offset 0x20.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label            */
        uint32_t RESERVED_4_0  : 5;  /*!< bit:  4.. 0                              */
        uint32_t INT4EN        : 1;  /*!< bit:      5  ADCINTSEL2_BIT_INT4EN       */
        uint32_t INT4CONT      : 1;  /*!< bit:      6  ADCINTSEL2_BIT_INT4CONT     */
        uint32_t RESERVED_12_7 : 6;  /*!< bit: 12.. 7                              */
        uint32_t INT5EN        : 1;  /*!< bit:     13  ADCINTSEL2_BIT_INT5EN       */
        uint32_t INT5CONT      : 1;  /*!< bit:     14  ADCINTSEL2_BIT_INT5CONT     */
        uint32_t RESERVED_31_15:17;  /*!< bit: 31..15                              */
    } bit;                           /*!< Structure used for bit  access           */
    uint32_t all;                    /*!< Type      used for word access           */
} ADCINTSEL2_REG;


/**
 *  @brief  Union type to access the ADC Interrupt Select Register 3 (ADCINTSEL3), offset 0x24.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label            */
        uint32_t INT15CONT     : 1;  /*!< bit:      0  ADCINTSEL3_BIT_INT15CONT    */
        uint32_t INT12EN       : 1;  /*!< bit:      1  ADCINTSEL3_BIT_INT12EN      */
        uint32_t INT12CONT     : 1;  /*!< bit:      2  ADCINTSEL3_BIT_INT12CONT    */
        uint32_t INT11EN       : 1;  /*!< bit:      3  ADCINTSEL3_BIT_INT11EN      */
        uint32_t INT11CONT     : 1;  /*!< bit:      4  ADCINTSEL3_BIT_INT11CONT    */
        uint32_t INT6EN        : 1;  /*!< bit:      5  ADCINTSEL3_BIT_INT6EN       */
        uint32_t INT6CONT      : 1;  /*!< bit:      6  ADCINTSEL3_BIT_INT6CONT     */
        uint32_t RESERVED_7_7  : 1;  /*!< bit:      7                              */
        uint32_t INT15EN       : 1;  /*!< bit:      8  ADCINTSEL3_BIT_INT15EN      */
        uint32_t INT14EN       : 1;  /*!< bit:      9  ADCINTSEL3_BIT_INT14EN      */
        uint32_t INT14CONT     : 1;  /*!< bit:     10  ADCINTSEL3_BIT_INT14CONT    */
        uint32_t INT13EN       : 1;  /*!< bit:     11  ADCINTSEL3_BIT_INT13EN      */
        uint32_t INT13CONT     : 1;  /*!< bit:     12  ADCINTSEL3_BIT_INT13CONT    */
        uint32_t INT7EN        : 1;  /*!< bit:     13  ADCINTSEL3_BIT_INT7EN       */
        uint32_t INT7CONT      : 1;  /*!< bit:     14  ADCINTSEL3_BIT_INT7CONT     */
        uint32_t RESERVED_31_15:17;  /*!< bit: 31..15                              */
    } bit;                           /*!< Structure used for bit  access           */
    uint32_t all;                    /*!< Type      used for word access           */
} ADCINTSEL3_REG;


/**
 *  @brief  Union type to access the ADC Interrupt Select Register 4 (ADCINTSEL4), offset 0x28.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label            */
        uint32_t RESERVED_0_0  : 1;  /*!< bit:      0                              */
        uint32_t INT10EN       : 1;  /*!< bit:      1  ADCINTSEL4_BIT_INT10EN      */
        uint32_t INT10CONT     : 1;  /*!< bit:      2  ADCINTSEL4_BIT_INT10CONT    */
        uint32_t INT9EN        : 1;  /*!< bit:      3  ADCINTSEL4_BIT_INT9EN       */
        uint32_t INT9CONT      : 1;  /*!< bit:      4  ADCINTSEL4_BIT_INT9CONT     */
        uint32_t INT8EN        : 1;  /*!< bit:      5  ADCINTSEL4_BIT_INT8EN       */
        uint32_t INT8CONT      : 1;  /*!< bit:      6  ADCINTSEL4_BIT_INT8CONT     */
        uint32_t RESERVED_31_7 :25;  /*!< bit: 31.. 7                              */
    } bit;                           /*!< Structure used for bit  access           */
    uint32_t all;                    /*!< Type      used for word access           */
} ADCINTSEL4_REG;


/**
 *  @brief  Union type to access the ADC State of Conversion Priority Control Register (ADCSOCPRICTL), offset 0x2C.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label            */
        uint32_t PRIORITY      : 5;  /*!< bit:  4.. 0  ADCSOCPRICTL_BIT_PRIORITY   */
        uint32_t RRPOINTER     : 6;  /*!< bit: 10.. 5  ADCSOCPRICTL_BIT_RRPOINTER  */
        uint32_t RESERVED_31_11:21;  /*!< bit: 31..11                              */
    } bit;                           /*!< Structure used for bit  access           */
    uint32_t all;                    /*!< Type      used for word access           */
} ADCSOCPRICTL_REG;


/**
 *  @brief  Union type to access the ADC Interrupt Trigger SOC Select Register 0 (ADCINTSOCSEL0), offset 0x34.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label            */
        uint32_t SOC0          : 5;  /*!< bit:  4.. 0  ADCINTSOCSEL0_BIT_SOC0      */
        uint32_t SOC1          : 5;  /*!< bit:  9.. 5  ADCINTSOCSEL0_BIT_SOC1      */
        uint32_t SOC2          : 5;  /*!< bit: 14..10  ADCINTSOCSEL0_BIT_SOC2      */
        uint32_t SOC3          : 5;  /*!< bit: 19..15  ADCINTSOCSEL0_BIT_SOC3      */
        uint32_t SOC4          : 5;  /*!< bit: 24..20  ADCINTSOCSEL0_BIT_SOC4      */
        uint32_t SOC5          : 5;  /*!< bit: 29..25  ADCINTSOCSEL0_BIT_SOC5      */
        uint32_t RESERVED_31_30: 2;  /*!< bit: 31..30                              */
    } bit;                           /*!< Structure used for bit  access           */
    uint32_t all;                    /*!< Type      used for word access           */
} ADCINTSOCSEL0_REG;


/**
 *  @brief  Union type to access the ADC Interrupt Trigger SOC Select Register 1 (ADCINTSOCSEL1), offset 0x38.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label            */
        uint32_t SOC6          : 5;  /*!< bit:  4.. 0  ADCINTSOCSEL1_BIT_SOC6      */
        uint32_t SOC7          : 5;  /*!< bit:  9.. 5  ADCINTSOCSEL1_BIT_SOC7      */
        uint32_t SOC8          : 5;  /*!< bit: 14..10  ADCINTSOCSEL1_BIT_SOC8      */
        uint32_t SOC9          : 5;  /*!< bit: 19..15  ADCINTSOCSEL1_BIT_SOC9      */
        uint32_t SOC10         : 5;  /*!< bit: 24..20  ADCINTSOCSEL1_BIT_SOC10     */
        uint32_t SOC11         : 5;  /*!< bit: 29..25  ADCINTSOCSEL1_BIT_SOC11     */
        uint32_t RESERVED_31_30: 2;  /*!< bit: 31..30                              */
    } bit;                           /*!< Structure used for bit  access           */
    uint32_t all;                    /*!< Type      used for word access           */
} ADCINTSOCSEL1_REG;


/**
 *  @brief  Union type to access the ADC SOC Flag Register (ADCSOCFLG), offset 0x3C.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label            */
        uint32_t SOC0          : 1;  /*!< bit:      0  ADCSOCFLG_BIT_SOC0          */
        uint32_t SOC1          : 1;  /*!< bit:      1  ADCSOCFLG_BIT_SOC1          */
        uint32_t SOC2          : 1;  /*!< bit:      2  ADCSOCFLG_BIT_SOC2          */
        uint32_t SOC3          : 1;  /*!< bit:      3  ADCSOCFLG_BIT_SOC3          */
        uint32_t SOC4          : 1;  /*!< bit:      4  ADCSOCFLG_BIT_SOC4          */
        uint32_t SOC5          : 1;  /*!< bit:      5  ADCSOCFLG_BIT_SOC5          */
        uint32_t SOC6          : 1;  /*!< bit:      6  ADCSOCFLG_BIT_SOC6          */
        uint32_t SOC7          : 1;  /*!< bit:      7  ADCSOCFLG_BIT_SOC7          */
        uint32_t SOC8          : 1;  /*!< bit:      8  ADCSOCFLG_BIT_SOC8          */
        uint32_t SOC9          : 1;  /*!< bit:      9  ADCSOCFLG_BIT_SOC9          */
        uint32_t SOC10         : 1;  /*!< bit:     10  ADCSOCFLG_BIT_SOC10         */
        uint32_t SOC11         : 1;  /*!< bit:     11  ADCSOCFLG_BIT_SOC11         */
        uint32_t SOC12         : 1;  /*!< bit:     12  ADCSOCFLG_BIT_SOC12         */
        uint32_t SOC13         : 1;  /*!< bit:     13  ADCSOCFLG_BIT_SOC13         */
        uint32_t SOC14         : 1;  /*!< bit:     14  ADCSOCFLG_BIT_SOC14         */
        uint32_t SOC15         : 1;  /*!< bit:     15  ADCSOCFLG_BIT_SOC15         */
        uint32_t RESERVED_31_16:16;  /*!< bit: 31..16                              */
    } bit;                           /*!< Structure used for bit  access           */
    uint32_t all;                    /*!< Type      used for word access           */
} ADCSOCFLG_REG;


/**
 *  @brief  Union type to access the ADC SOC Force Register (ADCSOCFRC), offset 0x40.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label            */
        uint32_t SOC0          : 1;  /*!< bit:      0  ADCSOCFRC_BIT_SOC0          */
        uint32_t SOC1          : 1;  /*!< bit:      1  ADCSOCFRC_BIT_SOC1          */
        uint32_t SOC2          : 1;  /*!< bit:      2  ADCSOCFRC_BIT_SOC2          */
        uint32_t SOC3          : 1;  /*!< bit:      3  ADCSOCFRC_BIT_SOC3          */
        uint32_t SOC4          : 1;  /*!< bit:      4  ADCSOCFRC_BIT_SOC4          */
        uint32_t SOC5          : 1;  /*!< bit:      5  ADCSOCFRC_BIT_SOC5          */
        uint32_t SOC6          : 1;  /*!< bit:      6  ADCSOCFRC_BIT_SOC6          */
        uint32_t SOC7          : 1;  /*!< bit:      7  ADCSOCFRC_BIT_SOC7          */
        uint32_t SOC8          : 1;  /*!< bit:      8  ADCSOCFRC_BIT_SOC8          */
        uint32_t SOC9          : 1;  /*!< bit:      9  ADCSOCFRC_BIT_SOC9          */
        uint32_t SOC10         : 1;  /*!< bit:     10  ADCSOCFRC_BIT_SOC10         */
        uint32_t SOC11         : 1;  /*!< bit:     11  ADCSOCFRC_BIT_SOC11         */
        uint32_t SOC12         : 1;  /*!< bit:     12  ADCSOCFRC_BIT_SOC12         */
        uint32_t SOC13         : 1;  /*!< bit:     13  ADCSOCFRC_BIT_SOC13         */
        uint32_t SOC14         : 1;  /*!< bit:     14  ADCSOCFRC_BIT_SOC14         */
        uint32_t SOC15         : 1;  /*!< bit:     15  ADCSOCFRC_BIT_SOC15         */
        uint32_t RESERVED_31_16:16;  /*!< bit: 31..16                              */
    } bit;                           /*!< Structure used for bit  access           */
    uint32_t all;                    /*!< Type      used for word access           */
} ADCSOCFRC_REG;


/**
 *  @brief  Union type to access the ADC SOC Overflow Register (ADCSOCOVF), offset 0x44.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label            */
        uint32_t SOC0          : 1;  /*!< bit:      0  ADCSOCOVF_BIT_SOC0          */
        uint32_t SOC1          : 1;  /*!< bit:      1  ADCSOCOVF_BIT_SOC1          */
        uint32_t SOC2          : 1;  /*!< bit:      2  ADCSOCOVF_BIT_SOC2          */
        uint32_t SOC3          : 1;  /*!< bit:      3  ADCSOCOVF_BIT_SOC3          */
        uint32_t SOC4          : 1;  /*!< bit:      4  ADCSOCOVF_BIT_SOC4          */
        uint32_t SOC5          : 1;  /*!< bit:      5  ADCSOCOVF_BIT_SOC5          */
        uint32_t SOC6          : 1;  /*!< bit:      6  ADCSOCOVF_BIT_SOC6          */
        uint32_t SOC7          : 1;  /*!< bit:      7  ADCSOCOVF_BIT_SOC7          */
        uint32_t SOC8          : 1;  /*!< bit:      8  ADCSOCOVF_BIT_SOC8          */
        uint32_t SOC9          : 1;  /*!< bit:      9  ADCSOCOVF_BIT_SOC9          */
        uint32_t SOC10         : 1;  /*!< bit:     10  ADCSOCOVF_BIT_SOC10         */
        uint32_t SOC11         : 1;  /*!< bit:     11  ADCSOCOVF_BIT_SOC11         */
        uint32_t SOC12         : 1;  /*!< bit:     12  ADCSOCOVF_BIT_SOC12         */
        uint32_t SOC13         : 1;  /*!< bit:     13  ADCSOCOVF_BIT_SOC13         */
        uint32_t SOC14         : 1;  /*!< bit:     14  ADCSOCOVF_BIT_SOC14         */
        uint32_t SOC15         : 1;  /*!< bit:     15  ADCSOCOVF_BIT_SOC15         */
        uint32_t RESERVED_31_16:16;  /*!< bit: 31..16                              */
    } bit;                           /*!< Structure used for bit  access           */
    uint32_t all;                    /*!< Type      used for word access           */
} ADCSOCOVF_REG;


/**
 *  @brief  Union type to access the ADC SOC Overflow Clear Register (ADCSOCOVFC), offset 0x48.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label            */
        uint32_t SOC0          : 1;  /*!< bit:      0  ADCSOCOVFC_BIT_SOC0         */
        uint32_t SOC1          : 1;  /*!< bit:      1  ADCSOCOVFC_BIT_SOC1         */
        uint32_t SOC2          : 1;  /*!< bit:      2  ADCSOCOVFC_BIT_SOC2         */
        uint32_t SOC3          : 1;  /*!< bit:      3  ADCSOCOVFC_BIT_SOC3         */
        uint32_t SOC4          : 1;  /*!< bit:      4  ADCSOCOVFC_BIT_SOC4         */
        uint32_t SOC5          : 1;  /*!< bit:      5  ADCSOCOVFC_BIT_SOC5         */
        uint32_t SOC6          : 1;  /*!< bit:      6  ADCSOCOVFC_BIT_SOC6         */
        uint32_t SOC7          : 1;  /*!< bit:      7  ADCSOCOVFC_BIT_SOC7         */
        uint32_t SOC8          : 1;  /*!< bit:      8  ADCSOCOVFC_BIT_SOC8         */
        uint32_t SOC9          : 1;  /*!< bit:      9  ADCSOCOVFC_BIT_SOC9         */
        uint32_t SOC10         : 1;  /*!< bit:     10  ADCSOCOVFC_BIT_SOC10        */
        uint32_t SOC11         : 1;  /*!< bit:     11  ADCSOCOVFC_BIT_SOC11        */
        uint32_t SOC12         : 1;  /*!< bit:     12  ADCSOCOVFC_BIT_SOC12        */
        uint32_t SOC13         : 1;  /*!< bit:     13  ADCSOCOVFC_BIT_SOC13        */
        uint32_t SOC14         : 1;  /*!< bit:     14  ADCSOCOVFC_BIT_SOC14        */
        uint32_t SOC15         : 1;  /*!< bit:     15  ADCSOCOVFC_BIT_SOC15        */
        uint32_t RESERVED_31_16:16;  /*!< bit: 31..16                              */
    } bit;                           /*!< Structure used for bit  access           */
    uint32_t all;                    /*!< Type      used for word access           */
} ADCSOCOVFC_REG;


/**
 *  @brief  Union type to access the ADC SOC0 Control Register (ADCSOCCTL0), offset 0x4C.
            Union type to access the ADC SOC1 Control Register (ADCSOCCTL1), offset 0x50.
            Union type to access the ADC SOC2 Control Register (ADCSOCCTL2), offset 0x54.
            Union type to access the ADC SOC3 Control Register (ADCSOCCTL3), offset 0x58.
            Union type to access the ADC SOC4 Control Register (ADCSOCCTL4), offset 0x5C.
            Union type to access the ADC SOC5 Control Register (ADCSOCCTL5), offset 0x60.
            Union type to access the ADC SOC6 Control Register (ADCSOCCTL6), offset 0x64.
            Union type to access the ADC SOC7 Control Register (ADCSOCCTL7), offset 0x68.
            Union type to access the ADC SOC8 Control Register (ADCSOCCTL8), offset 0x6C.
            Union type to access the ADC SOC9 Control Register (ADCSOCCTL9), offset 0x70.
            Union type to access the ADC SOC10 Control Register (ADCSOCCTL10), offset 0x74.
            Union type to access the ADC SOC11 Control Register (ADCSOCCTL11), offset 0x78.
            Union type to access the ADC SOC12 Control Register (ADCSOCCTL12), offset 0x7C.
            Union type to access the ADC SOC13 Control Register (ADCSOCCTL13), offset 0x80.
            Union type to access the ADC SOC14 Control Register (ADCSOCCTL14), offset 0x84.
            Union type to access the ADC SOC15 Control Register (ADCSOCCTL15), offset 0x88.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label            */
        uint32_t CONVCNT       : 6;  /*!< bit:  5.. 0  ADCSOCCTL0_BIT_CONVCNT      
                                                       ADCSOCCTL1_BIT_CONVCNT      
                                                       ADCSOCCTL2_BIT_CONVCNT      
                                                       ADCSOCCTL3_BIT_CONVCNT      
                                                       ADCSOCCTL4_BIT_CONVCNT      
                                                       ADCSOCCTL5_BIT_CONVCNT      
                                                       ADCSOCCTL6_BIT_CONVCNT      
                                                       ADCSOCCTL7_BIT_CONVCNT      
                                                       ADCSOCCTL8_BIT_CONVCNT      
                                                       ADCSOCCTL9_BIT_CONVCNT      
                                                       ADCSOCCTL10_BIT_CONVCNT     
                                                       ADCSOCCTL11_BIT_CONVCNT     
                                                       ADCSOCCTL12_BIT_CONVCNT     
                                                       ADCSOCCTL13_BIT_CONVCNT     
                                                       ADCSOCCTL14_BIT_CONVCNT     
                                                       ADCSOCCTL15_BIT_CONVCNT     */
        uint32_t SAMPCNT       : 7;  /*!< bit: 12.. 6  ADCSOCCTL0_BIT_SAMPCNT      
                                                       ADCSOCCTL1_BIT_SAMPCNT      
                                                       ADCSOCCTL2_BIT_SAMPCNT      
                                                       ADCSOCCTL3_BIT_SAMPCNT      
                                                       ADCSOCCTL4_BIT_SAMPCNT      
                                                       ADCSOCCTL5_BIT_SAMPCNT      
                                                       ADCSOCCTL6_BIT_SAMPCNT      
                                                       ADCSOCCTL7_BIT_SAMPCNT      
                                                       ADCSOCCTL8_BIT_SAMPCNT      
                                                       ADCSOCCTL9_BIT_SAMPCNT      
                                                       ADCSOCCTL10_BIT_SAMPCNT     
                                                       ADCSOCCTL11_BIT_SAMPCNT     
                                                       ADCSOCCTL12_BIT_SAMPCNT     
                                                       ADCSOCCTL13_BIT_SAMPCNT     
                                                       ADCSOCCTL14_BIT_SAMPCNT     
                                                       ADCSOCCTL15_BIT_SAMPCNT     */
        uint32_t CHSELAN       : 3;  /*!< bit: 15..13  ADCSOCCTL0_BIT_CHSELAN      
                                                       ADCSOCCTL1_BIT_CHSELAN      
                                                       ADCSOCCTL2_BIT_CHSELAN      
                                                       ADCSOCCTL3_BIT_CHSELAN      
                                                       ADCSOCCTL4_BIT_CHSELAN      
                                                       ADCSOCCTL5_BIT_CHSELAN      
                                                       ADCSOCCTL6_BIT_CHSELAN      
                                                       ADCSOCCTL7_BIT_CHSELAN      
                                                       ADCSOCCTL8_BIT_CHSELAN      
                                                       ADCSOCCTL9_BIT_CHSELAN      
                                                       ADCSOCCTL10_BIT_CHSELAN     
                                                       ADCSOCCTL11_BIT_CHSELAN     
                                                       ADCSOCCTL12_BIT_CHSELAN     
                                                       ADCSOCCTL13_BIT_CHSELAN     
                                                       ADCSOCCTL14_BIT_CHSELAN     
                                                       ADCSOCCTL15_BIT_CHSELAN     */
        uint32_t CHSELAP       : 3;  /*!< bit: 18..16  ADCSOCCTL0_BIT_CHSELAP      
                                                       ADCSOCCTL1_BIT_CHSELAP      
                                                       ADCSOCCTL2_BIT_CHSELAP      
                                                       ADCSOCCTL3_BIT_CHSELAP      
                                                       ADCSOCCTL4_BIT_CHSELAP      
                                                       ADCSOCCTL5_BIT_CHSELAP      
                                                       ADCSOCCTL6_BIT_CHSELAP      
                                                       ADCSOCCTL7_BIT_CHSELAP      
                                                       ADCSOCCTL8_BIT_CHSELAP      
                                                       ADCSOCCTL9_BIT_CHSELAP      
                                                       ADCSOCCTL10_BIT_CHSELAP     
                                                       ADCSOCCTL11_BIT_CHSELAP     
                                                       ADCSOCCTL12_BIT_CHSELAP     
                                                       ADCSOCCTL13_BIT_CHSELAP     
                                                       ADCSOCCTL14_BIT_CHSELAP     
                                                       ADCSOCCTL15_BIT_CHSELAP     */
        uint32_t CHSELBN       : 3;  /*!< bit: 21..19  ADCSOCCTL0_BIT_CHSELBN      
                                                       ADCSOCCTL1_BIT_CHSELBN      
                                                       ADCSOCCTL2_BIT_CHSELBN      
                                                       ADCSOCCTL3_BIT_CHSELBN      
                                                       ADCSOCCTL4_BIT_CHSELBN      
                                                       ADCSOCCTL5_BIT_CHSELBN      
                                                       ADCSOCCTL6_BIT_CHSELBN      
                                                       ADCSOCCTL7_BIT_CHSELBN      
                                                       ADCSOCCTL8_BIT_CHSELBN      
                                                       ADCSOCCTL9_BIT_CHSELBN      
                                                       ADCSOCCTL10_BIT_CHSELBN     
                                                       ADCSOCCTL11_BIT_CHSELBN     
                                                       ADCSOCCTL12_BIT_CHSELBN     
                                                       ADCSOCCTL13_BIT_CHSELBN     
                                                       ADCSOCCTL14_BIT_CHSELBN     
                                                       ADCSOCCTL15_BIT_CHSELBN     */
        uint32_t CHSELBP       : 3;  /*!< bit: 24..22  ADCSOCCTL0_BIT_CHSELBP      
                                                       ADCSOCCTL1_BIT_CHSELBP      
                                                       ADCSOCCTL2_BIT_CHSELBP      
                                                       ADCSOCCTL3_BIT_CHSELBP      
                                                       ADCSOCCTL4_BIT_CHSELBP      
                                                       ADCSOCCTL5_BIT_CHSELBP      
                                                       ADCSOCCTL6_BIT_CHSELBP      
                                                       ADCSOCCTL7_BIT_CHSELBP      
                                                       ADCSOCCTL8_BIT_CHSELBP      
                                                       ADCSOCCTL9_BIT_CHSELBP      
                                                       ADCSOCCTL10_BIT_CHSELBP     
                                                       ADCSOCCTL11_BIT_CHSELBP     
                                                       ADCSOCCTL12_BIT_CHSELBP     
                                                       ADCSOCCTL13_BIT_CHSELBP     
                                                       ADCSOCCTL14_BIT_CHSELBP     
                                                       ADCSOCCTL15_BIT_CHSELBP     */
        uint32_t TRIGSEL       : 5;  /*!< bit: 29..25  ADCSOCCTL0_BIT_TRIGSEL      
                                                       ADCSOCCTL1_BIT_TRIGSEL      
                                                       ADCSOCCTL2_BIT_TRIGSEL      
                                                       ADCSOCCTL3_BIT_TRIGSEL      
                                                       ADCSOCCTL4_BIT_TRIGSEL      
                                                       ADCSOCCTL5_BIT_TRIGSEL      
                                                       ADCSOCCTL6_BIT_TRIGSEL      
                                                       ADCSOCCTL7_BIT_TRIGSEL      
                                                       ADCSOCCTL8_BIT_TRIGSEL      
                                                       ADCSOCCTL9_BIT_TRIGSEL      
                                                       ADCSOCCTL10_BIT_TRIGSEL     
                                                       ADCSOCCTL11_BIT_TRIGSEL     
                                                       ADCSOCCTL12_BIT_TRIGSEL     
                                                       ADCSOCCTL13_BIT_TRIGSEL     
                                                       ADCSOCCTL14_BIT_TRIGSEL     
                                                       ADCSOCCTL15_BIT_TRIGSEL     */
        uint32_t SHBEN         : 1;  /*!< bit:     30  ADCSOCCTL0_BIT_SHBEN        
                                                       ADCSOCCTL1_BIT_SHBEN        
                                                       ADCSOCCTL2_BIT_SHBEN        
                                                       ADCSOCCTL3_BIT_SHBEN        
                                                       ADCSOCCTL4_BIT_SHBEN        
                                                       ADCSOCCTL5_BIT_SHBEN        
                                                       ADCSOCCTL6_BIT_SHBEN        
                                                       ADCSOCCTL7_BIT_SHBEN        
                                                       ADCSOCCTL8_BIT_SHBEN        
                                                       ADCSOCCTL9_BIT_SHBEN        
                                                       ADCSOCCTL10_BIT_SHBEN       
                                                       ADCSOCCTL11_BIT_SHBEN       
                                                       ADCSOCCTL12_BIT_SHBEN       
                                                       ADCSOCCTL13_BIT_SHBEN       
                                                       ADCSOCCTL14_BIT_SHBEN       
                                                       ADCSOCCTL15_BIT_SHBEN       */
        uint32_t SHAEN         : 1;  /*!< bit:     31  ADCSOCCTL0_BIT_SHAEN        
                                                       ADCSOCCTL1_BIT_SHAEN        
                                                       ADCSOCCTL2_BIT_SHAEN        
                                                       ADCSOCCTL3_BIT_SHAEN        
                                                       ADCSOCCTL4_BIT_SHAEN        
                                                       ADCSOCCTL5_BIT_SHAEN        
                                                       ADCSOCCTL6_BIT_SHAEN        
                                                       ADCSOCCTL7_BIT_SHAEN        
                                                       ADCSOCCTL8_BIT_SHAEN        
                                                       ADCSOCCTL9_BIT_SHAEN        
                                                       ADCSOCCTL10_BIT_SHAEN       
                                                       ADCSOCCTL11_BIT_SHAEN       
                                                       ADCSOCCTL12_BIT_SHAEN       
                                                       ADCSOCCTL13_BIT_SHAEN       
                                                       ADCSOCCTL14_BIT_SHAEN       
                                                       ADCSOCCTL15_BIT_SHAEN       */
    } bit;                           /*!< Structure used for bit  access           */
    uint32_t all;                    /*!< Type      used for word access           */
} ADCSOCCTLx_REG;


/**
 *  @brief  Union type to access the ADC Gain Trim Register (ADCGAINTRIM), offset 0x8C.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label            */
        uint32_t SHAGAIN       :16;  /*!< bit: 15.. 0  ADCGAINTRIM_BIT_SHAGAIN     */
        uint32_t SHBGAIN       :16;  /*!< bit: 31..16  ADCGAINTRIM_BIT_SHBGAIN     */
    } bit;                           /*!< Structure used for bit  access           */
    uint32_t all;                    /*!< Type      used for word access           */
} ADCGAINTRIM_REG;


/**
 *  @brief  Union type to access the ADC Offset Trim Register (ADCOFFSETTRIM), offset 0x90.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label            */
        uint32_t SHAOFFSET     : 9;  /*!< bit:  8.. 0  ADCOFFSETTRIM_BIT_SHAOFFSET */
        uint32_t SHBOFFSET     : 9;  /*!< bit: 17.. 9  ADCOFFSETTRIM_BIT_SHBOFFSET */
        uint32_t RESERVED_31_18:14;  /*!< bit: 31..18                              */
    } bit;                           /*!< Structure used for bit  access           */
    uint32_t all;                    /*!< Type      used for word access           */
} ADCOFFSETTRIM_REG;


/**
 *  @brief  Union type to access the ADC Result Register 0 (ADCRESULT0), offset 0x98.
            Union type to access the ADC Result Register 1 (ADCRESULT1), offset 0x9C.
            Union type to access the ADC Result Register 2 (ADCRESULT2), offset 0xA0.
            Union type to access the ADC Result Register 3 (ADCRESULT3), offset 0xA4.
            Union type to access the ADC Result Register 4 (ADCRESULT4), offset 0xA8.
            Union type to access the ADC Result Register 5 (ADCRESULT5), offset 0xAC.
            Union type to access the ADC Result Register 6 (ADCRESULT6), offset 0xB0.
            Union type to access the ADC Result Register 7 (ADCRESULT7), offset 0xB4.
            Union type to access the ADC Result Register 8 (ADCRESULT8), offset 0xB8.
            Union type to access the ADC Result Register 9 (ADCRESULT9), offset 0xBC.
            Union type to access the ADC Result Register 10 (ADCRESULT10), offset 0xC0.
            Union type to access the ADC Result Register 11 (ADCRESULT11), offset 0xC4.
            Union type to access the ADC Result Register 12 (ADCRESULT12), offset 0xC8.
            Union type to access the ADC Result Register 13 (ADCRESULT13), offset 0xCC.
            Union type to access the ADC Result Register 14 (ADCRESULT14), offset 0xD0.
            Union type to access the ADC Result Register 15 (ADCRESULT15), offset 0xD4.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label            */
        uint32_t VAL           :13;  /*!< bit: 12.. 0  ADCRESULT0_BIT_VAL          
                                                       ADCRESULT1_BIT_VAL          
                                                       ADCRESULT2_BIT_VAL          
                                                       ADCRESULT3_BIT_VAL          
                                                       ADCRESULT4_BIT_VAL          
                                                       ADCRESULT5_BIT_VAL          
                                                       ADCRESULT6_BIT_VAL          
                                                       ADCRESULT7_BIT_VAL          
                                                       ADCRESULT8_BIT_VAL          
                                                       ADCRESULT9_BIT_VAL          
                                                       ADCRESULT10_BIT_VAL         
                                                       ADCRESULT11_BIT_VAL         
                                                       ADCRESULT12_BIT_VAL         
                                                       ADCRESULT13_BIT_VAL         
                                                       ADCRESULT14_BIT_VAL         
                                                       ADCRESULT15_BIT_VAL         */
        uint32_t RESERVED_31_13:19;  /*!< bit: 31..13                              */
    } bit;                           /*!< Structure used for bit  access           */
    uint32_t all;                    /*!< Type      used for word access           */
} ADCRESULTx_REG;


/**
 *  @brief  Union type to access the ADC Status Register (ADCSTS), offset 0xD8.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label            */
        uint32_t COMP0L        : 1;  /*!< bit:      0  ADCSTS_BIT_COMP0L           */
        uint32_t COMP1L        : 1;  /*!< bit:      1  ADCSTS_BIT_COMP1L           */
        uint32_t COMP2L        : 1;  /*!< bit:      2  ADCSTS_BIT_COMP2L           */
        uint32_t COMP0H        : 1;  /*!< bit:      3  ADCSTS_BIT_COMP0H           */
        uint32_t COMP1H        : 1;  /*!< bit:      4  ADCSTS_BIT_COMP1H           */
        uint32_t COMP2H        : 1;  /*!< bit:      5  ADCSTS_BIT_COMP2H           */
        uint32_t RESERVED_6_6  : 1;  /*!< bit:      6                              */
        uint32_t RESERVED_7_7  : 1;  /*!< bit:      7                              */
        uint32_t RESERVED_30_8 :23;  /*!< bit: 30.. 8                              */
        uint32_t COMPSTSCLR    : 1;  /*!< bit:     31  ADCSTS_BIT_COMPSTSCLR       */
    } bit;                           /*!< Structure used for bit  access           */
    uint32_t all;                    /*!< Type      used for word access           */
} ADCSTS_REG;


/**
 *  @brief  Union type to access the Temperature Sensor Control Register (TSENSCTL), offset 0xDC.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label            */
        uint32_t RESERVED_3_0  : 4;  /*!< bit:  3.. 0                              */
        uint32_t RESERVED_4_4  : 1;  /*!< bit:      4                              */
        uint32_t RESERVED_5_5  : 1;  /*!< bit:      5                              */
        uint32_t EN            : 1;  /*!< bit:      6  TSENSCTL_BIT_EN             */
        uint32_t RESERVED_31_7 :25;  /*!< bit: 31.. 7                              */
    } bit;                           /*!< Structure used for bit  access           */
    uint32_t all;                    /*!< Type      used for word access           */
} TSENSCTL_REG;


/**
 *  @brief  Union type to access the ADC Trimming Control Register (ADCTRIM), offset 0x100.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label            */
        uint32_t RESERVED_9_0  :10;  /*!< bit:  9.. 0                              */
        uint32_t VREGTRIM      : 4;  /*!< bit: 13..10  ADCTRIM_BIT_VREGTRIM        */
        uint32_t VREFTRIM      : 5;  /*!< bit: 18..14  ADCTRIM_BIT_VREFTRIM        */
        uint32_t VREGBLEEDTRIM : 4;  /*!< bit: 22..19  ADCTRIM_BIT_VREGBLEEDTRIM   */
        uint32_t RESERVED_31_23: 9;  /*!< bit: 31..23                              */
    } bit;                           /*!< Structure used for bit  access           */
    uint32_t all;                    /*!< Type      used for word access           */
} ADCTRIM_REG;


/**
 *  @brief  Union type to access the ADC Interrupt Trigger SOC Select Register 2 (ADCINTSOCSEL2), offset 0x104.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label            */
        uint32_t SOC12         : 5;  /*!< bit:  4.. 0  ADCINTSOCSEL2_BIT_SOC12     */
        uint32_t SOC13         : 5;  /*!< bit:  9.. 5  ADCINTSOCSEL2_BIT_SOC13     */
        uint32_t SOC14         : 5;  /*!< bit: 14..10  ADCINTSOCSEL2_BIT_SOC14     */
        uint32_t SOC15         : 5;  /*!< bit: 19..15  ADCINTSOCSEL2_BIT_SOC15     */
        uint32_t RESERVED_31_20:12;  /*!< bit: 31..20                              */
    } bit;                           /*!< Structure used for bit  access           */
    uint32_t all;                    /*!< Type      used for word access           */
} ADCINTSOCSEL2_REG;





/**
  *  @brief  Structure type to access the ADC Controller (ADC).
  */
typedef struct
{
    __IO ADCCTL0_REG           ADCCTL0                ; /*!< Offset: 0x00000000 (RW  )  ADC Control Register 0                             */
    __IO ADCCTL1_REG           ADCCTL1                ; /*!< Offset: 0x00000004 (RW  )  ADC Control Register 1                             */
    __I  ADCIF_REG             ADCIF                  ; /*!< Offset: 0x00000008 (RO  )  ADC Interrupt Flag Register                        */
    __O  ADCIC_REG             ADCIC                  ; /*!< Offset: 0x0000000C (WO  )  ADC Interrupt Flag Clear Register                  */
    __I  ADCIOVF_REG           ADCIOVF                ; /*!< Offset: 0x00000010 (RO  )  ADC Interrupt Overflow Flag Register               */
    __O  ADCIOVFC_REG          ADCIOVFC               ; /*!< Offset: 0x00000014 (WO  )  ADC Interrupt Overflow Flag Clear Register         */
    __IO ADCINTSEL0_REG        ADCINTSEL0             ; /*!< Offset: 0x00000018 (RW  )  ADC Interrupt Select Register 0                    */
    __IO ADCINTSEL1_REG        ADCINTSEL1             ; /*!< Offset: 0x0000001C (RW  )  ADC Interrupt Select Register 1                    */
    __IO ADCINTSEL2_REG        ADCINTSEL2             ; /*!< Offset: 0x00000020 (RW  )  ADC Interrupt Select Register 2                    */
    __IO ADCINTSEL3_REG        ADCINTSEL3             ; /*!< Offset: 0x00000024 (RW  )  ADC Interrupt Select Register 3                    */
    __IO ADCINTSEL4_REG        ADCINTSEL4             ; /*!< Offset: 0x00000028 (RW  )  ADC Interrupt Select Register 4                    */
    __IO ADCSOCPRICTL_REG      ADCSOCPRICTL           ; /*!< Offset: 0x0000002C (RW  )  ADC State of Conversion Priority Control Register  */
         uint32_t              RESERVED0              ; 
    __IO ADCINTSOCSEL0_REG     ADCINTSOCSEL0          ; /*!< Offset: 0x00000034 (RW  )  ADC Interrupt Trigger SOC Select Register 0        */
    __IO ADCINTSOCSEL1_REG     ADCINTSOCSEL1          ; /*!< Offset: 0x00000038 (RW  )  ADC Interrupt Trigger SOC Select Register 1        */
    __I  ADCSOCFLG_REG         ADCSOCFLG              ; /*!< Offset: 0x0000003C (RO  )  ADC SOC Flag Register                              */
    __O  ADCSOCFRC_REG         ADCSOCFRC              ; /*!< Offset: 0x00000040 (WO  )  ADC SOC Force Register                             */
    __I  ADCSOCOVF_REG         ADCSOCOVF              ; /*!< Offset: 0x00000044 (RO  )  ADC SOC Overflow Register                          */
    __O  ADCSOCOVFC_REG        ADCSOCOVFC             ; /*!< Offset: 0x00000048 (WO  )  ADC SOC Overflow Clear Register                    */
    __IO ADCSOCCTLx_REG        ADCSOCCTL[16]          ; /*!< Offset: 0x0000004C (RW  )  ADC SOC0 Control Register                          */
    __IO ADCGAINTRIM_REG       ADCGAINTRIM            ; /*!< Offset: 0x0000008C (RW  )  ADC Gain Trim Register                             */
    __IO ADCOFFSETTRIM_REG     ADCOFFSETTRIM          ; /*!< Offset: 0x00000090 (RW  )  ADC Offset Trim Register                           */
         uint32_t              RESERVED1              ; 
    __I  ADCRESULTx_REG        ADCRESULT[16]          ; /*!< Offset: 0x00000098 (RO  )  ADC Result Register 0                              */
    __IO ADCSTS_REG            ADCSTS                 ; /*!< Offset: 0x000000D8 (RW  )  ADC Status Register                                */
    __IO TSENSCTL_REG          TSENSCTL               ; /*!< Offset: 0x000000DC (RW  )  Temperature Sensor Control Register                */
         uint32_t              RESERVED2[8]           ; 
    __IO ADCTRIM_REG           ADCTRIM                ; /*!< Offset: 0x00000100 (RW  )  ADC Trimming Control Register                      */
    __IO ADCINTSOCSEL2_REG     ADCINTSOCSEL2          ; /*!< Offset: 0x00000104 (RW  )  ADC Interrupt Trigger SOC Select Register 2        */
} ADC_REGS;


/********************************************************************************
*
* Module Name     CLOCK
*
*
********************************************************************************/



/**
 *  @brief  Union type to access the HCLK Control Register (HCLKCTL), offset 0x94.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t DIV           : 6;  /*!< bit:  5.. 0  HCLKCTL_BIT_DIV        */
        uint32_t RESERVED_6_6  : 1;  /*!< bit:      6                         */
        uint32_t EN            : 1;  /*!< bit:      7  HCLKCTL_BIT_EN         */
        uint32_t RESERVED_31_8 :24;  /*!< bit: 31.. 8                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} HCLKCTL_REG;


/**
 *  @brief  Union type to access the PCLK Control Register (PCLKCTL), offset 0x98.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t DIV           : 6;  /*!< bit:  5.. 0  PCLKCTL_BIT_DIV        */
        uint32_t RESERVED_6_6  : 1;  /*!< bit:      6                         */
        uint32_t EN            : 1;  /*!< bit:      7  PCLKCTL_BIT_EN         */
        uint32_t RESERVED_31_8 :24;  /*!< bit: 31.. 8                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} PCLKCTL_REG;


/**
 *  @brief  Union type to access the UART Clock Control Register (UARTCLKCTL), offset 0x9C.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t DIV           : 6;  /*!< bit:  5.. 0  UARTCLKCTL_BIT_DIV     */
        uint32_t RESERVED_6_6  : 1;  /*!< bit:      6                         */
        uint32_t EN            : 1;  /*!< bit:      7  UARTCLKCTL_BIT_EN      */
        uint32_t RESERVED_31_8 :24;  /*!< bit: 31.. 8                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} UARTCLKCTL_REG;


/**
 *  @brief  Union type to access the SSP Clock Control Register (SSPCLKCTL), offset 0xA0.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t DIV0          : 6;  /*!< bit:  5.. 0  SSPCLKCTL_BIT_DIV0     */
        uint32_t RESERVED_6_6  : 1;  /*!< bit:      6                         */
        uint32_t EN            : 1;  /*!< bit:      7  SSPCLKCTL_BIT_EN       */
        uint32_t DIV1          : 6;  /*!< bit: 13.. 8  SSPCLKCTL_BIT_DIV1     */
        uint32_t RESERVED_31_14:18;  /*!< bit: 31..14                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} SSPCLKCTL_REG;


/**
 *  @brief  Union type to access the QSPI Clock Control Register (QSPICLKCTL), offset 0xA4.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t DIV           : 6;  /*!< bit:  5.. 0  QSPICLKCTL_BIT_DIV     */
        uint32_t RESERVED_6_6  : 1;  /*!< bit:      6                         */
        uint32_t EN            : 1;  /*!< bit:      7  QSPICLKCTL_BIT_EN      */
        uint32_t RESERVED_31_8 :24;  /*!< bit: 31.. 8                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} QSPICLKCTL_REG;


/**
 *  @brief  Union type to access the I2C Clock Control Register (I2CCLKCTL), offset 0xA8.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t DIV           : 6;  /*!< bit:  5.. 0  I2CCLKCTL_BIT_DIV      */
        uint32_t RESERVED_6_6  : 1;  /*!< bit:      6                         */
        uint32_t EN            : 1;  /*!< bit:      7  I2CCLKCTL_BIT_EN       */
        uint32_t RESERVED_31_8 :24;  /*!< bit: 31.. 8                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} I2CCLKCTL_REG;


/**
 *  @brief  Union type to access the ADC Clock Control Register (ADCCLKCTL), offset 0xAC.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t DIV           : 6;  /*!< bit:  5.. 0  ADCCLKCTL_BIT_DIV      */
        uint32_t RESERVED_6_6  : 1;  /*!< bit:      6                         */
        uint32_t EN            : 1;  /*!< bit:      7  ADCCLKCTL_BIT_EN       */
        uint32_t RESERVED_31_8 :24;  /*!< bit: 31.. 8                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} ADCCLKCTL_REG;


/**
 *  @brief  Union type to access the PWM0 Clock Control Register (PWM0CLKCTL), offset 0xB0.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t DIV           : 6;  /*!< bit:  5.. 0  PWM0CLKCTL_BIT_DIV     */
        uint32_t RESERVED_6_6  : 1;  /*!< bit:      6                         */
        uint32_t EN            : 1;  /*!< bit:      7  PWM0CLKCTL_BIT_EN      */
        uint32_t RESERVED_31_8 :24;  /*!< bit: 31.. 8                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} PWM0CLKCTL_REG;


/**
 *  @brief  Union type to access the Global Clock Control Register (GLBCLKCTL), offset 0xB4.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t CLK0GATEBYP   : 1;  /*!< bit:      0  GLBCLKCTL_BIT_CLK0GATEBYP*/
        uint32_t CLK0GATEEN    : 1;  /*!< bit:      1  GLBCLKCTL_BIT_CLK0GATEEN*/
        uint32_t CLK0GATEDIS   : 1;  /*!< bit:      2  GLBCLKCTL_BIT_CLK0GATEDIS*/
        uint32_t CLK1GATEBYP   : 1;  /*!< bit:      3  GLBCLKCTL_BIT_CLK1GATEBYP*/
        uint32_t CLK1GATEEN    : 1;  /*!< bit:      4  GLBCLKCTL_BIT_CLK1GATEEN*/
        uint32_t CLK1GATEDIS   : 1;  /*!< bit:      5  GLBCLKCTL_BIT_CLK1GATEDIS*/
        uint32_t CLK0SEL       : 2;  /*!< bit:  7.. 6  GLBCLKCTL_BIT_CLK0SEL  */
        uint32_t CLK1SEL       : 2;  /*!< bit:  9.. 8  GLBCLKCTL_BIT_CLK1SEL  */
        uint32_t PWM0CLKSEL    : 2;  /*!< bit: 11..10  GLBCLKCTL_BIT_PWM0CLKSEL*/
        uint32_t PWM1CLKSEL    : 2;  /*!< bit: 13..12  GLBCLKCTL_BIT_PWM1CLKSEL*/
        uint32_t PWM2CLKSEL    : 2;  /*!< bit: 15..14  GLBCLKCTL_BIT_PWM2CLKSEL*/
        uint32_t PWM3CLKSEL    : 2;  /*!< bit: 17..16  GLBCLKCTL_BIT_PWM3CLKSEL*/
        uint32_t PWM4CLKSEL    : 2;  /*!< bit: 19..18  GLBCLKCTL_BIT_PWM4CLKSEL*/
        uint32_t PWM5CLKSEL    : 2;  /*!< bit: 21..20  GLBCLKCTL_BIT_PWM5CLKSEL*/
        uint32_t PWM6CLKSEL    : 2;  /*!< bit: 23..22  GLBCLKCTL_BIT_PWM6CLKSEL*/
        uint32_t ECAPCLKSEL    : 1;  /*!< bit:     24  GLBCLKCTL_BIT_ECAPCLKSEL*/
        uint32_t WDT0CLKSEL    : 2;  /*!< bit: 26..25  GLBCLKCTL_BIT_WDT0CLKSEL*/
        uint32_t WDT1CLKSEL    : 2;  /*!< bit: 28..27  GLBCLKCTL_BIT_WDT1CLKSEL*/
        uint32_t PWMCLKSYNC    : 1;  /*!< bit:     29  GLBCLKCTL_BIT_PWMCLKSYNC*/
        uint32_t RESERVED_31_30: 2;  /*!< bit: 31..30                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} GLBCLKCTL_REG;


/**
 *  @brief  Union type to access the ECAP Clock Control Register (ECAPCLKCTL), offset 0xB8.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t DIV           : 6;  /*!< bit:  5.. 0  ECAPCLKCTL_BIT_DIV     */
        uint32_t RESERVED_6_6  : 1;  /*!< bit:      6                         */
        uint32_t EN            : 1;  /*!< bit:      7  ECAPCLKCTL_BIT_EN      */
        uint32_t RESERVED_31_8 :24;  /*!< bit: 31.. 8                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} ECAPCLKCTL_REG;


/**
 *  @brief  Union type to access the De-glitch Clock Control Register (DGCLKCTL), offset 0xC0.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t DIV           : 3;  /*!< bit:  2.. 0  DGCLKCTL_BIT_DIV       */
        uint32_t RESERVED_31_3 :29;  /*!< bit: 31.. 3                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} DGCLKCTL_REG;


/**
 *  @brief  Union type to access the PWM1 Clock Control Register (PWM1CLKCTL), offset 0xE4.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t DIV           : 6;  /*!< bit:  5.. 0  PWM1CLKCTL_BIT_DIV     */
        uint32_t RESERVED_6_6  : 1;  /*!< bit:      6                         */
        uint32_t EN            : 1;  /*!< bit:      7  PWM1CLKCTL_BIT_EN      */
        uint32_t RESERVED_31_8 :24;  /*!< bit: 31.. 8                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} PWM1CLKCTL_REG;


/**
 *  @brief  Union type to access the PWM2 Clock Control Register (PWM2CLKCTL), offset 0xE8.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t DIV           : 6;  /*!< bit:  5.. 0  PWM2CLKCTL_BIT_DIV     */
        uint32_t RESERVED_6_6  : 1;  /*!< bit:      6                         */
        uint32_t EN            : 1;  /*!< bit:      7  PWM2CLKCTL_BIT_EN      */
        uint32_t RESERVED_31_8 :24;  /*!< bit: 31.. 8                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} PWM2CLKCTL_REG;


/**
 *  @brief  Union type to access the PWM3 Clock Control Register (PWM3CLKCTL), offset 0xEC.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t DIV           : 6;  /*!< bit:  5.. 0  PWM3CLKCTL_BIT_DIV     */
        uint32_t RESERVED_6_6  : 1;  /*!< bit:      6                         */
        uint32_t EN            : 1;  /*!< bit:      7  PWM3CLKCTL_BIT_EN      */
        uint32_t RESERVED_31_8 :24;  /*!< bit: 31.. 8                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} PWM3CLKCTL_REG;


/**
 *  @brief  Union type to access the PWM4 Clock Control Register (PWM4CLKCTL), offset 0xF0.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t DIV           : 6;  /*!< bit:  5.. 0  PWM4CLKCTL_BIT_DIV     */
        uint32_t RESERVED_6_6  : 1;  /*!< bit:      6                         */
        uint32_t EN            : 1;  /*!< bit:      7  PWM4CLKCTL_BIT_EN      */
        uint32_t RESERVED_31_8 :24;  /*!< bit: 31.. 8                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} PWM4CLKCTL_REG;


/**
 *  @brief  Union type to access the PWM5 Clock Control Register (PWM5CLKCTL), offset 0xF4.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t DIV           : 6;  /*!< bit:  5.. 0  PWM5CLKCTL_BIT_DIV     */
        uint32_t RESERVED_6_6  : 1;  /*!< bit:      6                         */
        uint32_t EN            : 1;  /*!< bit:      7  PWM5CLKCTL_BIT_EN      */
        uint32_t RESERVED_31_8 :24;  /*!< bit: 31.. 8                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} PWM5CLKCTL_REG;


/**
 *  @brief  Union type to access the PWM6 Clock Control Register (PWM6CLKCTL), offset 0xF8.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t DIV           : 6;  /*!< bit:  5.. 0  PWM6CLKCTL_BIT_DIV     */
        uint32_t RESERVED_6_6  : 1;  /*!< bit:      6                         */
        uint32_t EN            : 1;  /*!< bit:      7  PWM6CLKCTL_BIT_EN      */
        uint32_t RESERVED_31_8 :24;  /*!< bit: 31.. 8                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} PWM6CLKCTL_REG;


/**
 *  @brief  Union type to access the Clock Detection Control Register (CLKDETCTL), offset 0xFC.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t RCLKSEL       : 3;  /*!< bit:  2.. 0  CLKDETCTL_BIT_RCLKSEL  */
        uint32_t DCLKSEL       : 3;  /*!< bit:  5.. 3  CLKDETCTL_BIT_DCLKSEL  */
        uint32_t RCLKDIV       : 3;  /*!< bit:  8.. 6  CLKDETCTL_BIT_RCLKDIV  */
        uint32_t DCLKDIV       : 3;  /*!< bit: 11.. 9  CLKDETCTL_BIT_DCLKDIV  */
        uint32_t IC            : 1;  /*!< bit:     12  CLKDETCTL_BIT_IC       */
        uint32_t IE            : 1;  /*!< bit:     13  CLKDETCTL_BIT_IE       */
        uint32_t TZOE          : 1;  /*!< bit:     14  CLKDETCTL_BIT_TZOE     */
        uint32_t EN            : 1;  /*!< bit:     15  CLKDETCTL_BIT_EN       */
        uint32_t RESERVED_31_16:16;  /*!< bit: 31..16                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} CLKDETCTL_REG;


/**
 *  @brief  Union type to access the Clock Detection Counter Threshold Register (CLKDETCTH), offset 0x100.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t LO            :16;  /*!< bit: 15.. 0  CLKDETCTH_BIT_LO       */
        uint32_t HI            :16;  /*!< bit: 31..16  CLKDETCTH_BIT_HI       */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} CLKDETCTH_REG;


/**
 *  @brief  Union type to access the Clock Detection Counter Register (CLKDETCNT), offset 0x104.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :16;  /*!< bit: 15.. 0  CLKDETCNT_BIT_VAL      */
        uint32_t RESERVED_31_16:16;  /*!< bit: 31..16                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} CLKDETCNT_REG;


/**
 *  @brief  Union type to access the Clock Status Register (CLKSTS), offset 0x114.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t CPREGRDY      : 1;  /*!< bit:      0  CLKSTS_BIT_CPREGRDY    */
        uint32_t RCO0ARDY      : 1;  /*!< bit:      1  CLKSTS_BIT_RCO0ARDY    */
        uint32_t RCO0DRDY      : 1;  /*!< bit:      2  CLKSTS_BIT_RCO0DRDY    */
        uint32_t RCO1ARDY      : 1;  /*!< bit:      3  CLKSTS_BIT_RCO1ARDY    */
        uint32_t RCO1DRDY      : 1;  /*!< bit:      4  CLKSTS_BIT_RCO1DRDY    */
        uint32_t RESERVED_5_5  : 1;  /*!< bit:      5                         */
        uint32_t XORDY         : 1;  /*!< bit:      6  CLKSTS_BIT_XORDY       */
        uint32_t PLLARDY       : 1;  /*!< bit:      7  CLKSTS_BIT_PLLARDY     */
        uint32_t PLLDRDY       : 1;  /*!< bit:      8  CLKSTS_BIT_PLLDRDY     */
        uint32_t PLLPRDY       : 1;  /*!< bit:      9  CLKSTS_BIT_PLLPRDY     */
        uint32_t RESERVED_17_10: 8;  /*!< bit: 17..10                         */
        uint32_t PLLCSDUP      : 1;  /*!< bit:     18  CLKSTS_BIT_PLLCSDUP    */
        uint32_t PLLCSDDN      : 1;  /*!< bit:     19  CLKSTS_BIT_PLLCSDDN    */
        uint32_t PLLFLG        : 1;  /*!< bit:     20  CLKSTS_BIT_PLLFLG      */
        uint32_t PLLFLGRDY     : 1;  /*!< bit:     21  CLKSTS_BIT_PLLFLGRDY   */
        uint32_t CLKDETERR     : 1;  /*!< bit:     22  CLKSTS_BIT_CLKDETERR   */
        uint32_t RESERVED_31_23: 9;  /*!< bit: 31..23                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} CLKSTS_REG;


/**
 *  @brief  Union type to access the Charge-pump Regulator Control Register (CPREGCTL), offset 0x118.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t EN            : 1;  /*!< bit:      0  CPREGCTL_BIT_EN        */
        uint32_t RESERVED_1_1  : 1;  /*!< bit:      1                         */
        uint32_t VREFSEL       : 4;  /*!< bit:  5.. 2  CPREGCTL_BIT_VREFSEL   */
        uint32_t RESERVED_31_6 :26;  /*!< bit: 31.. 6                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} CPREGCTL_REG;


/**
 *  @brief  Union type to access the RCO0 Control Register (RCO0CTL), offset 0x11C.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t EN            : 1;  /*!< bit:      0  RCO0CTL_BIT_EN         */
        uint32_t MODE          : 1;  /*!< bit:      1  RCO0CTL_BIT_MODE       */
        uint32_t CPREGBYP      : 1;  /*!< bit:      2  RCO0CTL_BIT_CPREGBYP   */
        uint32_t TEMPTRIM      : 4;  /*!< bit:  6.. 3  RCO0CTL_BIT_TEMPTRIM   */
        uint32_t FREQTRIM      : 9;  /*!< bit: 15.. 7  RCO0CTL_BIT_FREQTRIM   */
        uint32_t RESERVED_31_16:16;  /*!< bit: 31..16                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} RCO0CTL_REG;


/**
 *  @brief  Union type to access the RCO1 Control Register (RCO1CTL), offset 0x120.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t EN            : 1;  /*!< bit:      0  RCO1CTL_BIT_EN         */
        uint32_t MODE          : 1;  /*!< bit:      1  RCO1CTL_BIT_MODE       */
        uint32_t CPREGBYP      : 1;  /*!< bit:      2  RCO1CTL_BIT_CPREGBYP   */
        uint32_t TEMPTRIM      : 4;  /*!< bit:  6.. 3  RCO1CTL_BIT_TEMPTRIM   */
        uint32_t FREQTRIM      : 9;  /*!< bit: 15.. 7  RCO1CTL_BIT_FREQTRIM   */
        uint32_t RESERVED_31_16:16;  /*!< bit: 31..16                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} RCO1CTL_REG;


/**
 *  @brief  Union type to access the Crystal Oscillator Control Register (XOCTL), offset 0x124.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t EN            : 1;  /*!< bit:      0  XOCTL_BIT_EN           */
        uint32_t RESERVED_1_1  : 1;  /*!< bit:      1                         */
        uint32_t FASTEN        : 1;  /*!< bit:      2  XOCTL_BIT_FASTEN       */
        uint32_t RESERVED_7_3  : 5;  /*!< bit:  7.. 3                         */
        uint32_t PRECNT        : 8;  /*!< bit: 15.. 8  XOCTL_BIT_PRECNT       */
        uint32_t RESERVED_31_16:16;  /*!< bit: 31..16                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} XOCTL_REG;


/**
 *  @brief  Union type to access the PLL Control Register 0 (PLLCTL0), offset 0x138.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t EN            : 1;  /*!< bit:      0  PLLCTL0_BIT_EN         */
        uint32_t ACLKEN        : 1;  /*!< bit:      1  PLLCTL0_BIT_ACLKEN     */
        uint32_t DCLKEN        : 1;  /*!< bit:      2  PLLCTL0_BIT_DCLKEN     */
        uint32_t PWMCLKEN      : 1;  /*!< bit:      3  PLLCTL0_BIT_PWMCLKEN   */
        uint32_t CSDEN         : 1;  /*!< bit:      4  PLLCTL0_BIT_CSDEN      */
        uint32_t CSDRST        : 1;  /*!< bit:      5  PLLCTL0_BIT_CSDRST     */
        uint32_t DSMLSB        : 1;  /*!< bit:      6  PLLCTL0_BIT_DSMLSB     */
        uint32_t FCALEN        : 1;  /*!< bit:      7  PLLCTL0_BIT_FCALEN     */
        uint32_t FCALWIN       : 1;  /*!< bit:      8  PLLCTL0_BIT_FCALWIN    */
        uint32_t FREQTRIM      : 3;  /*!< bit: 11.. 9  PLLCTL0_BIT_FREQTRIM   */
        uint32_t RCLKSEL       : 1;  /*!< bit:     12  PLLCTL0_BIT_RCLKSEL    */
        uint32_t ICP           : 5;  /*!< bit: 17..13  PLLCTL0_BIT_ICP        */
        uint32_t LOOPCLOSE     : 1;  /*!< bit:     18  PLLCTL0_BIT_LOOPCLOSE  */
        uint32_t RESERVED_19_19: 1;  /*!< bit:     19                         */
        uint32_t RESERVED_21_20: 2;  /*!< bit: 21..20                         */
        uint32_t RESERVED_24_22: 3;  /*!< bit: 24..22                         */
        uint32_t NIN           : 3;  /*!< bit: 27..25  PLLCTL0_BIT_NIN        */
        uint32_t CPREGBYP      : 1;  /*!< bit:     28  PLLCTL0_BIT_CPREGBYP   */
        uint32_t RESERVED_31_29: 3;  /*!< bit: 31..29                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} PLLCTL0_REG;


/**
 *  @brief  Union type to access the PLL Control Register 1 (PLLCTL1), offset 0x13C.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t NFBFRAC       :16;  /*!< bit: 15.. 0  PLLCTL1_BIT_NFBFRAC    */
        uint32_t NFBINTG       : 8;  /*!< bit: 23..16  PLLCTL1_BIT_NFBINTG    */
        uint32_t NDIG          : 2;  /*!< bit: 25..24  PLLCTL1_BIT_NDIG       */
        uint32_t NPWM          : 2;  /*!< bit: 27..26  PLLCTL1_BIT_NPWM       */
        uint32_t ND2A          : 3;  /*!< bit: 30..28  PLLCTL1_BIT_ND2A       */
        uint32_t RESERVED_31_31: 1;  /*!< bit:     31                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} PLLCTL1_REG;


/**
 *  @brief  Union type to access the WDT0 Clock Control Register (WDT0CLKCTL), offset 0x164.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t DIV           : 6;  /*!< bit:  5.. 0  WDT0CLKCTL_BIT_DIV     */
        uint32_t DBGRUN        : 1;  /*!< bit:      6  WDT0CLKCTL_BIT_DBGRUN  */
        uint32_t EN            : 1;  /*!< bit:      7  WDT0CLKCTL_BIT_EN      */
        uint32_t RESERVED_31_8 :24;  /*!< bit: 31.. 8                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} WDT0CLKCTL_REG;


/**
 *  @brief  Union type to access the WDT1 Clock Control Register (WDT1CLKCTL), offset 0x168.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t DIV           : 6;  /*!< bit:  5.. 0  WDT1CLKCTL_BIT_DIV     */
        uint32_t DBGRUN        : 1;  /*!< bit:      6  WDT1CLKCTL_BIT_DBGRUN  */
        uint32_t EN            : 1;  /*!< bit:      7  WDT1CLKCTL_BIT_EN      */
        uint32_t RESERVED_31_8 :24;  /*!< bit: 31.. 8                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} WDT1CLKCTL_REG;





/**
  *  @brief  Structure type to access the CLOCK Controller (CLOCK).
  */
typedef struct
{
         uint32_t           RESERVED0[37]       ; 
    __IO HCLKCTL_REG        HCLKCTL             ; /*!< Offset: 0x00000094 (RW  )  HCLK Control Register                       */
    __IO PCLKCTL_REG        PCLKCTL             ; /*!< Offset: 0x00000098 (RW  )  PCLK Control Register                       */
    __IO UARTCLKCTL_REG     UARTCLKCTL          ; /*!< Offset: 0x0000009C (RW  )  UART Clock Control Register                 */
    __IO SSPCLKCTL_REG      SSPCLKCTL           ; /*!< Offset: 0x000000A0 (RW  )  SSP Clock Control Register                  */
    __IO QSPICLKCTL_REG     QSPICLKCTL          ; /*!< Offset: 0x000000A4 (RW  )  QSPI Clock Control Register                 */
    __IO I2CCLKCTL_REG      I2CCLKCTL           ; /*!< Offset: 0x000000A8 (RW  )  I2C Clock Control Register                  */
    __IO ADCCLKCTL_REG      ADCCLKCTL           ; /*!< Offset: 0x000000AC (RW  )  ADC Clock Control Register                  */
    __IO PWM0CLKCTL_REG     PWM0CLKCTL          ; /*!< Offset: 0x000000B0 (RW  )  PWM0 Clock Control Register                 */
    __IO GLBCLKCTL_REG      GLBCLKCTL           ; /*!< Offset: 0x000000B4 (RW  )  Global Clock Control Register               */
    __IO ECAPCLKCTL_REG     ECAPCLKCTL          ; /*!< Offset: 0x000000B8 (RW  )  ECAP Clock Control Register                 */
         uint32_t           RESERVED1           ; 
    __IO DGCLKCTL_REG       DGCLKCTL            ; /*!< Offset: 0x000000C0 (RW  )  De-glitch Clock Control Register            */
         uint32_t           RESERVED2[8]        ; 
    __IO PWM1CLKCTL_REG     PWM1CLKCTL          ; /*!< Offset: 0x000000E4 (RW  )  PWM1 Clock Control Register                 */
    __IO PWM2CLKCTL_REG     PWM2CLKCTL          ; /*!< Offset: 0x000000E8 (RW  )  PWM2 Clock Control Register                 */
    __IO PWM3CLKCTL_REG     PWM3CLKCTL          ; /*!< Offset: 0x000000EC (RW  )  PWM3 Clock Control Register                 */
    __IO PWM4CLKCTL_REG     PWM4CLKCTL          ; /*!< Offset: 0x000000F0 (RW  )  PWM4 Clock Control Register                 */
    __IO PWM5CLKCTL_REG     PWM5CLKCTL          ; /*!< Offset: 0x000000F4 (RW  )  PWM5 Clock Control Register                 */
    __IO PWM6CLKCTL_REG     PWM6CLKCTL          ; /*!< Offset: 0x000000F8 (RW  )  PWM6 Clock Control Register                 */
    __IO CLKDETCTL_REG      CLKDETCTL           ; /*!< Offset: 0x000000FC (RW  )  Clock Detection Control Register            */
    __IO CLKDETCTH_REG      CLKDETCTH           ; /*!< Offset: 0x00000100 (RW  )  Clock Detection Counter Threshold Register  */
    __I  CLKDETCNT_REG      CLKDETCNT           ; /*!< Offset: 0x00000104 (RO  )  Clock Detection Counter Register            */
         uint32_t           RESERVED3[3]        ; 
    __I  CLKSTS_REG         CLKSTS              ; /*!< Offset: 0x00000114 (RO  )  Clock Status Register                       */
    __IO CPREGCTL_REG       CPREGCTL            ; /*!< Offset: 0x00000118 (RW  )  Charge-pump Regulator Control Register      */
    __IO RCO0CTL_REG        RCO0CTL             ; /*!< Offset: 0x0000011C (RW  )  RCO0 Control Register                       */
    __IO RCO1CTL_REG        RCO1CTL             ; /*!< Offset: 0x00000120 (RW  )  RCO1 Control Register                       */
    __IO XOCTL_REG          XOCTL               ; /*!< Offset: 0x00000124 (RW  )  Crystal Oscillator Control Register         */
         uint32_t           RESERVED4[4]        ; 
    __IO PLLCTL0_REG        PLLCTL0             ; /*!< Offset: 0x00000138 (RW  )  PLL Control Register 0                      */
    __IO PLLCTL1_REG        PLLCTL1             ; /*!< Offset: 0x0000013C (RW  )  PLL Control Register 1                      */
         uint32_t           RESERVED5[9]        ; 
    __IO WDT0CLKCTL_REG     WDT0CLKCTL          ; /*!< Offset: 0x00000164 (RW  )  WDT0 Clock Control Register                 */
    __IO WDT1CLKCTL_REG     WDT1CLKCTL          ; /*!< Offset: 0x00000168 (RW  )  WDT1 Clock Control Register                 */
} CLOCK_REGS;


/********************************************************************************
*
* Module Name     GLOBAL
*
*
********************************************************************************/



/**
 *  @brief  Union type to access the Memory Parity Check Enable Register (MEMPCE), offset 0xBC.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label          */
        uint32_t ROMPCE        : 1;  /*!< bit:      0  MEMPCE_BIT_ROMPCE         */
        uint32_t RAM32KPCE     : 1;  /*!< bit:      1  MEMPCE_BIT_RAM32KPCE      */
        uint32_t RAM16KPCE     : 1;  /*!< bit:      2  MEMPCE_BIT_RAM16KPCE      */
        uint32_t GLBPCE        : 1;  /*!< bit:      3  MEMPCE_BIT_GLBPCE         */
        uint32_t RESERVED_31_4 :28;  /*!< bit: 31.. 4                            */
    } bit;                           /*!< Structure used for bit  access         */
    uint32_t all;                    /*!< Type      used for word access         */
} MEMPCE_REG;


/**
 *  @brief  Union type to access the GPIO Interrupt Enable Register 0 (GPIOIE0), offset 0xC4.
            Union type to access the GPIO Interrupt Enable Register 1 (GPIOIE1), offset 0xC8.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label          */
        uint32_t GPIO0         : 1;  /*!< bit:      0  GPIOIE0_BIT_GPIO0         
                                                       GPIOIE1_BIT_GPIO0         */
        uint32_t GPIO1         : 1;  /*!< bit:      1  GPIOIE0_BIT_GPIO1         
                                                       GPIOIE1_BIT_GPIO1         */
        uint32_t GPIO2         : 1;  /*!< bit:      2  GPIOIE0_BIT_GPIO2         
                                                       GPIOIE1_BIT_GPIO2         */
        uint32_t GPIO3         : 1;  /*!< bit:      3  GPIOIE0_BIT_GPIO3         
                                                       GPIOIE1_BIT_GPIO3         */
        uint32_t GPIO4         : 1;  /*!< bit:      4  GPIOIE0_BIT_GPIO4         
                                                       GPIOIE1_BIT_GPIO4         */
        uint32_t GPIO5         : 1;  /*!< bit:      5  GPIOIE0_BIT_GPIO5         
                                                       GPIOIE1_BIT_GPIO5         */
        uint32_t GPIO6         : 1;  /*!< bit:      6  GPIOIE0_BIT_GPIO6         
                                                       GPIOIE1_BIT_GPIO6         */
        uint32_t GPIO7         : 1;  /*!< bit:      7  GPIOIE0_BIT_GPIO7         
                                                       GPIOIE1_BIT_GPIO7         */
        uint32_t GPIO8         : 1;  /*!< bit:      8  GPIOIE0_BIT_GPIO8         
                                                       GPIOIE1_BIT_GPIO8         */
        uint32_t GPIO9         : 1;  /*!< bit:      9  GPIOIE0_BIT_GPIO9         
                                                       GPIOIE1_BIT_GPIO9         */
        uint32_t GPIO10        : 1;  /*!< bit:     10  GPIOIE0_BIT_GPIO10        
                                                       GPIOIE1_BIT_GPIO10        */
        uint32_t GPIO11        : 1;  /*!< bit:     11  GPIOIE0_BIT_GPIO11        
                                                       GPIOIE1_BIT_GPIO11        */
        uint32_t GPIO12        : 1;  /*!< bit:     12  GPIOIE0_BIT_GPIO12        
                                                       GPIOIE1_BIT_GPIO12        */
        uint32_t GPIO13        : 1;  /*!< bit:     13  GPIOIE0_BIT_GPIO13        
                                                       GPIOIE1_BIT_GPIO13        */
        uint32_t GPIO14        : 1;  /*!< bit:     14  GPIOIE0_BIT_GPIO14        
                                                       GPIOIE1_BIT_GPIO14        */
        uint32_t GPIO15        : 1;  /*!< bit:     15  GPIOIE0_BIT_GPIO15        
                                                       GPIOIE1_BIT_GPIO15        */
        uint32_t GPIO16        : 1;  /*!< bit:     16  GPIOIE0_BIT_GPIO16        
                                                       GPIOIE1_BIT_GPIO16        */
        uint32_t GPIO17        : 1;  /*!< bit:     17  GPIOIE0_BIT_GPIO17        
                                                       GPIOIE1_BIT_GPIO17        */
        uint32_t RESERVED_31_18:14;  /*!< bit: 31..18                            */
    } bit;                           /*!< Structure used for bit  access         */
    uint32_t all;                    /*!< Type      used for word access         */
} GPIOIEx_REG;


/**
 *  @brief  Union type to access the GPIO Interrupt Clear Register 0 (GPIOIC0), offset 0xCC.
            Union type to access the GPIO Interrupt Clear Register 1 (GPIOIC1), offset 0xD0.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label          */
        uint32_t GPIO0         : 1;  /*!< bit:      0  GPIOIC0_BIT_GPIO0         
                                                       GPIOIC1_BIT_GPIO0         */
        uint32_t GPIO1         : 1;  /*!< bit:      1  GPIOIC0_BIT_GPIO1         
                                                       GPIOIC1_BIT_GPIO1         */
        uint32_t GPIO2         : 1;  /*!< bit:      2  GPIOIC0_BIT_GPIO2         
                                                       GPIOIC1_BIT_GPIO2         */
        uint32_t GPIO3         : 1;  /*!< bit:      3  GPIOIC0_BIT_GPIO3         
                                                       GPIOIC1_BIT_GPIO3         */
        uint32_t GPIO4         : 1;  /*!< bit:      4  GPIOIC0_BIT_GPIO4         
                                                       GPIOIC1_BIT_GPIO4         */
        uint32_t GPIO5         : 1;  /*!< bit:      5  GPIOIC0_BIT_GPIO5         
                                                       GPIOIC1_BIT_GPIO5         */
        uint32_t GPIO6         : 1;  /*!< bit:      6  GPIOIC0_BIT_GPIO6         
                                                       GPIOIC1_BIT_GPIO6         */
        uint32_t GPIO7         : 1;  /*!< bit:      7  GPIOIC0_BIT_GPIO7         
                                                       GPIOIC1_BIT_GPIO7         */
        uint32_t GPIO8         : 1;  /*!< bit:      8  GPIOIC0_BIT_GPIO8         
                                                       GPIOIC1_BIT_GPIO8         */
        uint32_t GPIO9         : 1;  /*!< bit:      9  GPIOIC0_BIT_GPIO9         
                                                       GPIOIC1_BIT_GPIO9         */
        uint32_t GPIO10        : 1;  /*!< bit:     10  GPIOIC0_BIT_GPIO10        
                                                       GPIOIC1_BIT_GPIO10        */
        uint32_t GPIO11        : 1;  /*!< bit:     11  GPIOIC0_BIT_GPIO11        
                                                       GPIOIC1_BIT_GPIO11        */
        uint32_t GPIO12        : 1;  /*!< bit:     12  GPIOIC0_BIT_GPIO12        
                                                       GPIOIC1_BIT_GPIO12        */
        uint32_t GPIO13        : 1;  /*!< bit:     13  GPIOIC0_BIT_GPIO13        
                                                       GPIOIC1_BIT_GPIO13        */
        uint32_t GPIO14        : 1;  /*!< bit:     14  GPIOIC0_BIT_GPIO14        
                                                       GPIOIC1_BIT_GPIO14        */
        uint32_t GPIO15        : 1;  /*!< bit:     15  GPIOIC0_BIT_GPIO15        
                                                       GPIOIC1_BIT_GPIO15        */
        uint32_t GPIO16        : 1;  /*!< bit:     16  GPIOIC0_BIT_GPIO16        
                                                       GPIOIC1_BIT_GPIO16        */
        uint32_t GPIO17        : 1;  /*!< bit:     17  GPIOIC0_BIT_GPIO17        
                                                       GPIOIC1_BIT_GPIO17        */
        uint32_t RESERVED_31_18:14;  /*!< bit: 31..18                            */
    } bit;                           /*!< Structure used for bit  access         */
    uint32_t all;                    /*!< Type      used for word access         */
} GPIOICx_REG;


/**
 *  @brief  Union type to access the GPIO Interrupt Force Register 0 (GPIOIFRC0), offset 0xD4.
            Union type to access the GPIO Interrupt Force Register 1 (GPIOIFRC1), offset 0xD8.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label          */
        uint32_t GPIO0         : 1;  /*!< bit:      0  GPIOIFRC0_BIT_GPIO0       
                                                       GPIOIFRC1_BIT_GPIO0       */
        uint32_t GPIO1         : 1;  /*!< bit:      1  GPIOIFRC0_BIT_GPIO1       
                                                       GPIOIFRC1_BIT_GPIO1       */
        uint32_t GPIO2         : 1;  /*!< bit:      2  GPIOIFRC0_BIT_GPIO2       
                                                       GPIOIFRC1_BIT_GPIO2       */
        uint32_t GPIO3         : 1;  /*!< bit:      3  GPIOIFRC0_BIT_GPIO3       
                                                       GPIOIFRC1_BIT_GPIO3       */
        uint32_t GPIO4         : 1;  /*!< bit:      4  GPIOIFRC0_BIT_GPIO4       
                                                       GPIOIFRC1_BIT_GPIO4       */
        uint32_t GPIO5         : 1;  /*!< bit:      5  GPIOIFRC0_BIT_GPIO5       
                                                       GPIOIFRC1_BIT_GPIO5       */
        uint32_t GPIO6         : 1;  /*!< bit:      6  GPIOIFRC0_BIT_GPIO6       
                                                       GPIOIFRC1_BIT_GPIO6       */
        uint32_t GPIO7         : 1;  /*!< bit:      7  GPIOIFRC0_BIT_GPIO7       
                                                       GPIOIFRC1_BIT_GPIO7       */
        uint32_t GPIO8         : 1;  /*!< bit:      8  GPIOIFRC0_BIT_GPIO8       
                                                       GPIOIFRC1_BIT_GPIO8       */
        uint32_t GPIO9         : 1;  /*!< bit:      9  GPIOIFRC0_BIT_GPIO9       
                                                       GPIOIFRC1_BIT_GPIO9       */
        uint32_t GPIO10        : 1;  /*!< bit:     10  GPIOIFRC0_BIT_GPIO10      
                                                       GPIOIFRC1_BIT_GPIO10      */
        uint32_t GPIO11        : 1;  /*!< bit:     11  GPIOIFRC0_BIT_GPIO11      
                                                       GPIOIFRC1_BIT_GPIO11      */
        uint32_t GPIO12        : 1;  /*!< bit:     12  GPIOIFRC0_BIT_GPIO12      
                                                       GPIOIFRC1_BIT_GPIO12      */
        uint32_t GPIO13        : 1;  /*!< bit:     13  GPIOIFRC0_BIT_GPIO13      
                                                       GPIOIFRC1_BIT_GPIO13      */
        uint32_t GPIO14        : 1;  /*!< bit:     14  GPIOIFRC0_BIT_GPIO14      
                                                       GPIOIFRC1_BIT_GPIO14      */
        uint32_t GPIO15        : 1;  /*!< bit:     15  GPIOIFRC0_BIT_GPIO15      
                                                       GPIOIFRC1_BIT_GPIO15      */
        uint32_t GPIO16        : 1;  /*!< bit:     16  GPIOIFRC0_BIT_GPIO16      
                                                       GPIOIFRC1_BIT_GPIO16      */
        uint32_t GPIO17        : 1;  /*!< bit:     17  GPIOIFRC0_BIT_GPIO17      
                                                       GPIOIFRC1_BIT_GPIO17      */
        uint32_t RESERVED_31_18:14;  /*!< bit: 31..18                            */
    } bit;                           /*!< Structure used for bit  access         */
    uint32_t all;                    /*!< Type      used for word access         */
} GPIOIFRCx_REG;


/**
 *  @brief  Union type to access the GPIO Interrupt Polarity Inversion Register 0 (GPIOINTINV0), offset 0xDC.
            Union type to access the GPIO Interrupt Polarity Inversion Register 1 (GPIOINTINV1), offset 0xE0.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label          */
        uint32_t GPIO0         : 1;  /*!< bit:      0  GPIOINTINV0_BIT_GPIO0     
                                                       GPIOINTINV1_BIT_GPIO0     */
        uint32_t GPIO1         : 1;  /*!< bit:      1  GPIOINTINV0_BIT_GPIO1     
                                                       GPIOINTINV1_BIT_GPIO1     */
        uint32_t GPIO2         : 1;  /*!< bit:      2  GPIOINTINV0_BIT_GPIO2     
                                                       GPIOINTINV1_BIT_GPIO2     */
        uint32_t GPIO3         : 1;  /*!< bit:      3  GPIOINTINV0_BIT_GPIO3     
                                                       GPIOINTINV1_BIT_GPIO3     */
        uint32_t GPIO4         : 1;  /*!< bit:      4  GPIOINTINV0_BIT_GPIO4     
                                                       GPIOINTINV1_BIT_GPIO4     */
        uint32_t GPIO5         : 1;  /*!< bit:      5  GPIOINTINV0_BIT_GPIO5     
                                                       GPIOINTINV1_BIT_GPIO5     */
        uint32_t GPIO6         : 1;  /*!< bit:      6  GPIOINTINV0_BIT_GPIO6     
                                                       GPIOINTINV1_BIT_GPIO6     */
        uint32_t GPIO7         : 1;  /*!< bit:      7  GPIOINTINV0_BIT_GPIO7     
                                                       GPIOINTINV1_BIT_GPIO7     */
        uint32_t GPIO8         : 1;  /*!< bit:      8  GPIOINTINV0_BIT_GPIO8     
                                                       GPIOINTINV1_BIT_GPIO8     */
        uint32_t GPIO9         : 1;  /*!< bit:      9  GPIOINTINV0_BIT_GPIO9     
                                                       GPIOINTINV1_BIT_GPIO9     */
        uint32_t GPIO10        : 1;  /*!< bit:     10  GPIOINTINV0_BIT_GPIO10    
                                                       GPIOINTINV1_BIT_GPIO10    */
        uint32_t GPIO11        : 1;  /*!< bit:     11  GPIOINTINV0_BIT_GPIO11    
                                                       GPIOINTINV1_BIT_GPIO11    */
        uint32_t GPIO12        : 1;  /*!< bit:     12  GPIOINTINV0_BIT_GPIO12    
                                                       GPIOINTINV1_BIT_GPIO12    */
        uint32_t GPIO13        : 1;  /*!< bit:     13  GPIOINTINV0_BIT_GPIO13    
                                                       GPIOINTINV1_BIT_GPIO13    */
        uint32_t GPIO14        : 1;  /*!< bit:     14  GPIOINTINV0_BIT_GPIO14    
                                                       GPIOINTINV1_BIT_GPIO14    */
        uint32_t GPIO15        : 1;  /*!< bit:     15  GPIOINTINV0_BIT_GPIO15    
                                                       GPIOINTINV1_BIT_GPIO15    */
        uint32_t GPIO16        : 1;  /*!< bit:     16  GPIOINTINV0_BIT_GPIO16    
                                                       GPIOINTINV1_BIT_GPIO16    */
        uint32_t GPIO17        : 1;  /*!< bit:     17  GPIOINTINV0_BIT_GPIO17    
                                                       GPIOINTINV1_BIT_GPIO17    */
        uint32_t RESERVED_31_18:14;  /*!< bit: 31..18                            */
    } bit;                           /*!< Structure used for bit  access         */
    uint32_t all;                    /*!< Type      used for word access         */
} GPIOINTINVx_REG;


/**
 *  @brief  Union type to access the GPIO Miscellaneous Control Register (GPIOMISC), offset 0x108.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label          */
        uint32_t TZ1SEL        : 3;  /*!< bit:  2.. 0  GPIOMISC_BIT_TZ1SEL       */
        uint32_t TZ2SEL        : 3;  /*!< bit:  5.. 3  GPIOMISC_BIT_TZ2SEL       */
        uint32_t TZ3SEL        : 3;  /*!< bit:  8.. 6  GPIOMISC_BIT_TZ3SEL       */
        uint32_t TZ4SEL        : 3;  /*!< bit: 11.. 9  GPIOMISC_BIT_TZ4SEL       */
        uint32_t TZ5SEL        : 3;  /*!< bit: 14..12  GPIOMISC_BIT_TZ5SEL       */
        uint32_t ECAPSEL       : 7;  /*!< bit: 21..15  GPIOMISC_BIT_ECAPSEL      */
        uint32_t EXTSOCSEL     : 7;  /*!< bit: 28..22  GPIOMISC_BIT_EXTSOCSEL    */
        uint32_t RESERVED_31_29: 3;  /*!< bit: 31..29                            */
    } bit;                           /*!< Structure used for bit  access         */
    uint32_t all;                    /*!< Type      used for word access         */
} GPIOMISC_REG;


/**
 *  @brief  Union type to access the Timer External Event Select Register (TMREXTSEL), offset 0x10C.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label          */
        uint32_t TMR0          : 7;  /*!< bit:  6.. 0  TMREXTSEL_BIT_TMR0        */
        uint32_t TMR1          : 7;  /*!< bit: 13.. 7  TMREXTSEL_BIT_TMR1        */
        uint32_t TMR2          : 7;  /*!< bit: 20..14  TMREXTSEL_BIT_TMR2        */
        uint32_t RESERVED_31_21:11;  /*!< bit: 31..21                            */
    } bit;                           /*!< Structure used for bit  access         */
    uint32_t all;                    /*!< Type      used for word access         */
} TMREXTSEL_REG;


/**
 *  @brief  Union type to access the Global PWM Force Synchronization Register (PWMFRCSYNC), offset 0x16C.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label          */
        uint32_t PWM0SYNC      : 1;  /*!< bit:      0  PWMFRCSYNC_BIT_PWM0SYNC   */
        uint32_t PWM1SYNC      : 1;  /*!< bit:      1  PWMFRCSYNC_BIT_PWM1SYNC   */
        uint32_t PWM2SYNC      : 1;  /*!< bit:      2  PWMFRCSYNC_BIT_PWM2SYNC   */
        uint32_t PWM3SYNC      : 1;  /*!< bit:      3  PWMFRCSYNC_BIT_PWM3SYNC   */
        uint32_t PWM4SYNC      : 1;  /*!< bit:      4  PWMFRCSYNC_BIT_PWM4SYNC   */
        uint32_t PWM5SYNC      : 1;  /*!< bit:      5  PWMFRCSYNC_BIT_PWM5SYNC   */
        uint32_t PWM6SYNC      : 1;  /*!< bit:      6  PWMFRCSYNC_BIT_PWM6SYNC   */
        uint32_t RESERVED_31_7 :25;  /*!< bit: 31.. 7                            */
    } bit;                           /*!< Structure used for bit  access         */
    uint32_t all;                    /*!< Type      used for word access         */
} PWMFRCSYNC_REG;





/**
  *  @brief  Structure type to access the GLOBAL Controller (GLOBAL).
  */
typedef struct
{
         uint32_t              RESERVED0[47]          ; 
    __IO MEMPCE_REG            MEMPCE                 ; /*!< Offset: 0x000000BC (RW  )  Memory Parity Check Enable Register           */
         uint32_t              RESERVED1              ; 
    __IO GPIOIEx_REG           GPIOIE[2]              ; /*!< Offset: 0x000000C4 (RW  )  GPIO Interrupt Enable Register 0              */
    __IO GPIOICx_REG           GPIOIC[2]              ; /*!< Offset: 0x000000CC (RW  )  GPIO Interrupt Clear Register 0               */
    __IO GPIOIFRCx_REG         GPIOIFRC[2]            ; /*!< Offset: 0x000000D4 (RW  )  GPIO Interrupt Force Register 0               */
    __IO GPIOINTINVx_REG       GPIOINTINV[2]          ; /*!< Offset: 0x000000DC (RW  )  GPIO Interrupt Polarity Inversion Register 0  */
         uint32_t              RESERVED2[9]           ; 
    __IO GPIOMISC_REG          GPIOMISC               ; /*!< Offset: 0x00000108 (RW  )  GPIO Miscellaneous Control Register           */
    __IO TMREXTSEL_REG         TMREXTSEL              ; /*!< Offset: 0x0000010C (RW  )  Timer External Event Select Register          */
         uint32_t              RESERVED3              ; 
         uint32_t              RESERVED4[22]          ; 
    __O  PWMFRCSYNC_REG        PWMFRCSYNC             ; /*!< Offset: 0x0000016C (WO  )  Global PWM Force Synchronization Register     */
         uint32_t              RESERVED5              ; 
} GLOBAL_REGS;


/********************************************************************************
*
* Module Name     POWER
*
*
********************************************************************************/



/**
 *  @brief  Union type to access the Bandgap Control Register (BGCTL), offset 0x148.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        uint32_t RESERVED_0_0  : 1;  /*!< bit:      0                           */
        uint32_t TEMPTRIM      : 4;  /*!< bit:  4.. 1  BGCTL_BIT_TEMPTRIM       */
        uint32_t ADCBGDIS      : 1;  /*!< bit:      5  BGCTL_BIT_ADCBGDIS       */
        uint32_t ADCBGTEMPTRIM : 4;  /*!< bit:  9.. 6  BGCTL_BIT_ADCBGTEMPTRIM  */
        uint32_t RESERVED_31_10:22;  /*!< bit: 31..10                           */
    } bit;                           /*!< Structure used for bit  access        */
    uint32_t all;                    /*!< Type      used for word access        */
} BGCTL_REG;


/**
 *  @brief  Union type to access the VCAP12 BOD Control Register (BODVCAP12CTL), offset 0x14C.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        uint32_t HIBODEN       : 1;  /*!< bit:      0  BODVCAP12CTL_BIT_HIBODEN */
        uint32_t LOBODEN       : 1;  /*!< bit:      1  BODVCAP12CTL_BIT_LOBODEN */
        uint32_t HIBODOM       : 1;  /*!< bit:      2  BODVCAP12CTL_BIT_HIBODOM */
        uint32_t LOBODOM       : 1;  /*!< bit:      3  BODVCAP12CTL_BIT_LOBODOM */
        uint32_t HIBODL2HVTH   : 3;  /*!< bit:  6.. 4  BODVCAP12CTL_BIT_HIBODL2HVTH*/
        uint32_t HIBODH2LVTH   : 3;  /*!< bit:  9.. 7  BODVCAP12CTL_BIT_HIBODH2LVTH*/
        uint32_t LOBODH2LVTH   : 3;  /*!< bit: 12..10  BODVCAP12CTL_BIT_LOBODH2LVTH*/
        uint32_t LOBODL2HVTH   : 3;  /*!< bit: 15..13  BODVCAP12CTL_BIT_LOBODL2HVTH*/
        uint32_t HIBODRSTEN    : 1;  /*!< bit:     16  BODVCAP12CTL_BIT_HIBODRSTEN*/
        uint32_t LOBODRSTEN    : 1;  /*!< bit:     17  BODVCAP12CTL_BIT_LOBODRSTEN*/
        uint32_t RESERVED_31_18:14;  /*!< bit: 31..18                           */
    } bit;                           /*!< Structure used for bit  access        */
    uint32_t all;                    /*!< Type      used for word access        */
} BODVCAP12CTL_REG;


/**
 *  @brief  Union type to access the VDD BOD Control Register (BODVDDCTL), offset 0x150.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        uint32_t HIBODEN       : 1;  /*!< bit:      0  BODVDDCTL_BIT_HIBODEN    */
        uint32_t LOBODEN       : 1;  /*!< bit:      1  BODVDDCTL_BIT_LOBODEN    */
        uint32_t HIBODOM       : 1;  /*!< bit:      2  BODVDDCTL_BIT_HIBODOM    */
        uint32_t LOBODOM       : 1;  /*!< bit:      3  BODVDDCTL_BIT_LOBODOM    */
        uint32_t HIBODL2HVTH   : 3;  /*!< bit:  6.. 4  BODVDDCTL_BIT_HIBODL2HVTH*/
        uint32_t HIBODH2LVTH   : 3;  /*!< bit:  9.. 7  BODVDDCTL_BIT_HIBODH2LVTH*/
        uint32_t LOBODH2LVTH   : 3;  /*!< bit: 12..10  BODVDDCTL_BIT_LOBODH2LVTH*/
        uint32_t LOBODL2HVTH   : 3;  /*!< bit: 15..13  BODVDDCTL_BIT_LOBODL2HVTH*/
        uint32_t HIBODRSTEN    : 1;  /*!< bit:     16  BODVDDCTL_BIT_HIBODRSTEN */
        uint32_t LOBODRSTEN    : 1;  /*!< bit:     17  BODVDDCTL_BIT_LOBODRSTEN */
        uint32_t RESERVED_31_18:14;  /*!< bit: 31..18                           */
    } bit;                           /*!< Structure used for bit  access        */
    uint32_t all;                    /*!< Type      used for word access        */
} BODVDDCTL_REG;


/**
 *  @brief  Union type to access the LDO Control Register (LDOCTL), offset 0x154.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        uint32_t RESERVED_0_0  : 1;  /*!< bit:      0                           */
        uint32_t VREFEN        : 1;  /*!< bit:      1  LDOCTL_BIT_VREFEN        */
        uint32_t RESERVED_2_2  : 1;  /*!< bit:      2                           */
        uint32_t RESERVED_4_3  : 2;  /*!< bit:  4.. 3                           */
        uint32_t VREFSEL       : 4;  /*!< bit:  8.. 5  LDOCTL_BIT_VREFSEL       */
        uint32_t LPREFSEL      : 3;  /*!< bit: 11.. 9  LDOCTL_BIT_LPREFSEL      */
        uint32_t RESERVED_31_12:20;  /*!< bit: 31..12                           */
    } bit;                           /*!< Structure used for bit  access        */
    uint32_t all;                    /*!< Type      used for word access        */
} LDOCTL_REG;


/**
 *  @brief  Union type to access the BOD Status Register (BODSTS), offset 0x15C.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        uint32_t VCAP12TOOHI   : 1;  /*!< bit:      0  BODSTS_BIT_VCAP12TOOHI   */
        uint32_t VCAP12TOOLO   : 1;  /*!< bit:      1  BODSTS_BIT_VCAP12TOOLO   */
        uint32_t VDDTOOHI      : 1;  /*!< bit:      2  BODSTS_BIT_VDDTOOHI      */
        uint32_t VDDTOOLO      : 1;  /*!< bit:      3  BODSTS_BIT_VDDTOOLO      */
        uint32_t RESERVED_30_4 :27;  /*!< bit: 30.. 4                           */
        uint32_t CLR           : 1;  /*!< bit:     31  BODSTS_BIT_CLR           */
    } bit;                           /*!< Structure used for bit  access        */
    uint32_t all;                    /*!< Type      used for word access        */
} BODSTS_REG;


/**
 *  @brief  Union type to access the BOD Control Register (BODCTL), offset 0x160.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label         */
        uint32_t VREFSEL       : 4;  /*!< bit:  3.. 0  BODCTL_BIT_VREFSEL       */
        uint32_t RESERVED_31_4 :28;  /*!< bit: 31.. 4                           */
    } bit;                           /*!< Structure used for bit  access        */
    uint32_t all;                    /*!< Type      used for word access        */
} BODCTL_REG;





/**
  *  @brief  Structure type to access the POWER Controller (POWER).
  */
typedef struct
{
         uint32_t             RESERVED0[82]         ; 
    __IO BGCTL_REG            BGCTL                 ; /*!< Offset: 0x00000148 (RW  )  Bandgap Control Register        */
    __IO BODVCAP12CTL_REG     BODVCAP12CTL          ; /*!< Offset: 0x0000014C (RW  )  VCAP12 BOD Control Register     */
    __IO BODVDDCTL_REG        BODVDDCTL             ; /*!< Offset: 0x00000150 (RW  )  VDD BOD Control Register        */
    __IO LDOCTL_REG           LDOCTL                ; /*!< Offset: 0x00000154 (RW  )  LDO Control Register            */
         uint32_t             RESERVED1             ; 
    __IO BODSTS_REG           BODSTS                ; /*!< Offset: 0x0000015C (RW  )  BOD Status Register             */
    __IO BODCTL_REG           BODCTL                ; /*!< Offset: 0x00000160 (RW  )  BOD Control Register            */
} POWER_REGS;


/********************************************************************************
*
* Module Name     PINMUX
*
*
********************************************************************************/



/**
 *  @brief  Union type to access the GPIO0 Pin Configuration Register (GPIO0), offset 0x0.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t MUXSEL        : 3;  /*!< bit:  2.. 0  GPIO0_BIT_MUXSEL       */
        uint32_t DEMUX         : 8;  /*!< bit: 10.. 3  GPIO0_BIT_DEMUX        */
        uint32_t NPU           : 8;  /*!< bit: 18..11  GPIO0_BIT_NPU          */
        uint32_t DEGLITCH      : 1;  /*!< bit:     19  GPIO0_BIT_DEGLITCH     */
        uint32_t RESERVED_31_20:12;  /*!< bit: 31..20                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} GPIO0_REG;


/**
 *  @brief  Union type to access the GPIO1 Pin Configuration Register (GPIO1), offset 0x8.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t MUXSEL        : 3;  /*!< bit:  2.. 0  GPIO1_BIT_MUXSEL       */
        uint32_t DEMUX         : 8;  /*!< bit: 10.. 3  GPIO1_BIT_DEMUX        */
        uint32_t NPU           : 8;  /*!< bit: 18..11  GPIO1_BIT_NPU          */
        uint32_t DEGLITCH      : 1;  /*!< bit:     19  GPIO1_BIT_DEGLITCH     */
        uint32_t RESERVED_31_20:12;  /*!< bit: 31..20                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} GPIO1_REG;


/**
 *  @brief  Union type to access the GPIO2 Pin Configuration Register (GPIO2), offset 0xC.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t MUXSEL        : 3;  /*!< bit:  2.. 0  GPIO2_BIT_MUXSEL       */
        uint32_t DEMUX         : 8;  /*!< bit: 10.. 3  GPIO2_BIT_DEMUX        */
        uint32_t NPU           : 8;  /*!< bit: 18..11  GPIO2_BIT_NPU          */
        uint32_t DEGLITCH      : 1;  /*!< bit:     19  GPIO2_BIT_DEGLITCH     */
        uint32_t RESERVED_31_20:12;  /*!< bit: 31..20                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} GPIO2_REG;


/**
 *  @brief  Union type to access the GPIO3 Pin Configuration Register (GPIO3), offset 0x10.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t MUXSEL        : 3;  /*!< bit:  2.. 0  GPIO3_BIT_MUXSEL       */
        uint32_t DEMUX         : 8;  /*!< bit: 10.. 3  GPIO3_BIT_DEMUX        */
        uint32_t NPU           : 8;  /*!< bit: 18..11  GPIO3_BIT_NPU          */
        uint32_t DEGLITCH      : 1;  /*!< bit:     19  GPIO3_BIT_DEGLITCH     */
        uint32_t RESERVED_31_20:12;  /*!< bit: 31..20                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} GPIO3_REG;


/**
 *  @brief  Union type to access the GPIO4 Pin Configuration Register (GPIO4), offset 0x14.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t MUXSEL        : 3;  /*!< bit:  2.. 0  GPIO4_BIT_MUXSEL       */
        uint32_t DEMUX         : 8;  /*!< bit: 10.. 3  GPIO4_BIT_DEMUX        */
        uint32_t NPU           : 8;  /*!< bit: 18..11  GPIO4_BIT_NPU          */
        uint32_t DEGLITCH      : 1;  /*!< bit:     19  GPIO4_BIT_DEGLITCH     */
        uint32_t RESERVED_31_20:12;  /*!< bit: 31..20                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} GPIO4_REG;


/**
 *  @brief  Union type to access the GPIO5 Pin Configuration Register (GPIO5), offset 0x18.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t MUXSEL        : 3;  /*!< bit:  2.. 0  GPIO5_BIT_MUXSEL       */
        uint32_t DEMUX         : 8;  /*!< bit: 10.. 3  GPIO5_BIT_DEMUX        */
        uint32_t NPU           : 8;  /*!< bit: 18..11  GPIO5_BIT_NPU          */
        uint32_t DEGLITCH      : 1;  /*!< bit:     19  GPIO5_BIT_DEGLITCH     */
        uint32_t RESERVED_31_20:12;  /*!< bit: 31..20                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} GPIO5_REG;


/**
 *  @brief  Union type to access the GPIO6 Pin Configuration Register (GPIO6), offset 0x1C.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t MUXSEL        : 3;  /*!< bit:  2.. 0  GPIO6_BIT_MUXSEL       */
        uint32_t DEMUX         : 8;  /*!< bit: 10.. 3  GPIO6_BIT_DEMUX        */
        uint32_t NPU           : 8;  /*!< bit: 18..11  GPIO6_BIT_NPU          */
        uint32_t DEGLITCH      : 1;  /*!< bit:     19  GPIO6_BIT_DEGLITCH     */
        uint32_t RESERVED_31_20:12;  /*!< bit: 31..20                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} GPIO6_REG;


/**
 *  @brief  Union type to access the GPIO7 Pin Configuration Register (GPIO7), offset 0x20.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t MUXSEL        : 3;  /*!< bit:  2.. 0  GPIO7_BIT_MUXSEL       */
        uint32_t DEMUX         : 8;  /*!< bit: 10.. 3  GPIO7_BIT_DEMUX        */
        uint32_t NPU           : 8;  /*!< bit: 18..11  GPIO7_BIT_NPU          */
        uint32_t DEGLITCH      : 1;  /*!< bit:     19  GPIO7_BIT_DEGLITCH     */
        uint32_t RESERVED_31_20:12;  /*!< bit: 31..20                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} GPIO7_REG;


/**
 *  @brief  Union type to access the GPIO8 Pin Configuration Register (GPIO8), offset 0x24.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t MUXSEL        : 3;  /*!< bit:  2.. 0  GPIO8_BIT_MUXSEL       */
        uint32_t DEMUX         : 8;  /*!< bit: 10.. 3  GPIO8_BIT_DEMUX        */
        uint32_t NPU           : 8;  /*!< bit: 18..11  GPIO8_BIT_NPU          */
        uint32_t DEGLITCH      : 1;  /*!< bit:     19  GPIO8_BIT_DEGLITCH     */
        uint32_t RESERVED_31_20:12;  /*!< bit: 31..20                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} GPIO8_REG;


/**
 *  @brief  Union type to access the GPIO9 Pin Configuration Register (GPIO9), offset 0x28.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t MUXSEL        : 3;  /*!< bit:  2.. 0  GPIO9_BIT_MUXSEL       */
        uint32_t DEMUX         : 8;  /*!< bit: 10.. 3  GPIO9_BIT_DEMUX        */
        uint32_t NPU           : 8;  /*!< bit: 18..11  GPIO9_BIT_NPU          */
        uint32_t DEGLITCH      : 1;  /*!< bit:     19  GPIO9_BIT_DEGLITCH     */
        uint32_t RESERVED_31_20:12;  /*!< bit: 31..20                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} GPIO9_REG;


/**
 *  @brief  Union type to access the GPIO10 Pin Configuration Register (GPIO10), offset 0x2C.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t MUXSEL        : 3;  /*!< bit:  2.. 0  GPIO10_BIT_MUXSEL      */
        uint32_t DEMUX         : 8;  /*!< bit: 10.. 3  GPIO10_BIT_DEMUX       */
        uint32_t NPU           : 8;  /*!< bit: 18..11  GPIO10_BIT_NPU         */
        uint32_t DEGLITCH      : 1;  /*!< bit:     19  GPIO10_BIT_DEGLITCH    */
        uint32_t RESERVED_31_20:12;  /*!< bit: 31..20                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} GPIO10_REG;


/**
 *  @brief  Union type to access the GPIO11 Pin Configuration Register (GPIO11), offset 0x30.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t MUXSEL        : 3;  /*!< bit:  2.. 0  GPIO11_BIT_MUXSEL      */
        uint32_t DEMUX         : 8;  /*!< bit: 10.. 3  GPIO11_BIT_DEMUX       */
        uint32_t NPU           : 8;  /*!< bit: 18..11  GPIO11_BIT_NPU         */
        uint32_t DEGLITCH      : 1;  /*!< bit:     19  GPIO11_BIT_DEGLITCH    */
        uint32_t RESERVED_31_20:12;  /*!< bit: 31..20                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} GPIO11_REG;


/**
 *  @brief  Union type to access the GPIO12 Pin Configuration Register (GPIO12), offset 0x34.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t MUXSEL        : 3;  /*!< bit:  2.. 0  GPIO12_BIT_MUXSEL      */
        uint32_t DEMUX         : 8;  /*!< bit: 10.. 3  GPIO12_BIT_DEMUX       */
        uint32_t NPU           : 8;  /*!< bit: 18..11  GPIO12_BIT_NPU         */
        uint32_t DEGLITCH      : 1;  /*!< bit:     19  GPIO12_BIT_DEGLITCH    */
        uint32_t RESERVED_31_20:12;  /*!< bit: 31..20                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} GPIO12_REG;


/**
 *  @brief  Union type to access the GPIO13 Pin Configuration Register (GPIO13), offset 0x38.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t MUXSEL        : 3;  /*!< bit:  2.. 0  GPIO13_BIT_MUXSEL      */
        uint32_t DEMUX         : 8;  /*!< bit: 10.. 3  GPIO13_BIT_DEMUX       */
        uint32_t NPU           : 8;  /*!< bit: 18..11  GPIO13_BIT_NPU         */
        uint32_t DEGLITCH      : 1;  /*!< bit:     19  GPIO13_BIT_DEGLITCH    */
        uint32_t RESERVED_31_20:12;  /*!< bit: 31..20                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} GPIO13_REG;


/**
 *  @brief  Union type to access the GPIO14 Pin Configuration Register (GPIO14), offset 0x3C.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t MUXSEL        : 3;  /*!< bit:  2.. 0  GPIO14_BIT_MUXSEL      */
        uint32_t DEMUX         : 8;  /*!< bit: 10.. 3  GPIO14_BIT_DEMUX       */
        uint32_t NPU           : 8;  /*!< bit: 18..11  GPIO14_BIT_NPU         */
        uint32_t DEGLITCH      : 1;  /*!< bit:     19  GPIO14_BIT_DEGLITCH    */
        uint32_t RESERVED_31_20:12;  /*!< bit: 31..20                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} GPIO14_REG;


/**
 *  @brief  Union type to access the GPIO15 Pin Configuration Register (GPIO15), offset 0x40.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t MUXSEL        : 3;  /*!< bit:  2.. 0  GPIO15_BIT_MUXSEL      */
        uint32_t DEMUX         : 8;  /*!< bit: 10.. 3  GPIO15_BIT_DEMUX       */
        uint32_t NPU           : 8;  /*!< bit: 18..11  GPIO15_BIT_NPU         */
        uint32_t DEGLITCH      : 1;  /*!< bit:     19  GPIO15_BIT_DEGLITCH    */
        uint32_t RESERVED_31_20:12;  /*!< bit: 31..20                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} GPIO15_REG;


/**
 *  @brief  Union type to access the GPIO16 Pin Configuration Register (GPIO16), offset 0x44.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t MUXSEL        : 3;  /*!< bit:  2.. 0  GPIO16_BIT_MUXSEL      */
        uint32_t DEMUX         : 8;  /*!< bit: 10.. 3  GPIO16_BIT_DEMUX       */
        uint32_t NPU           : 8;  /*!< bit: 18..11  GPIO16_BIT_NPU         */
        uint32_t DEGLITCH      : 1;  /*!< bit:     19  GPIO16_BIT_DEGLITCH    */
        uint32_t RESERVED_31_20:12;  /*!< bit: 31..20                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} GPIO16_REG;


/**
 *  @brief  Union type to access the GPIO17 Pin Configuration Register (GPIO17), offset 0x48.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t MUXSEL        : 3;  /*!< bit:  2.. 0  GPIO17_BIT_MUXSEL      */
        uint32_t DEMUX         : 8;  /*!< bit: 10.. 3  GPIO17_BIT_DEMUX       */
        uint32_t NPU           : 8;  /*!< bit: 18..11  GPIO17_BIT_NPU         */
        uint32_t DEGLITCH      : 1;  /*!< bit:     19  GPIO17_BIT_DEGLITCH    */
        uint32_t RESERVED_31_20:12;  /*!< bit: 31..20                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} GPIO17_REG;


/**
 *  @brief  Union type to access the GPIO18 Pin Configuration Register (GPIO18), offset 0x4C.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t MUXSEL        : 3;  /*!< bit:  2.. 0  GPIO18_BIT_MUXSEL      */
        uint32_t DEMUX         : 8;  /*!< bit: 10.. 3  GPIO18_BIT_DEMUX       */
        uint32_t NPU           : 8;  /*!< bit: 18..11  GPIO18_BIT_NPU         */
        uint32_t DEGLITCH      : 1;  /*!< bit:     19  GPIO18_BIT_DEGLITCH    */
        uint32_t RESERVED_31_20:12;  /*!< bit: 31..20                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} GPIO18_REG;


/**
 *  @brief  Union type to access the GPIO19 Pin Configuration Register (GPIO19), offset 0x50.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t MUXSEL        : 3;  /*!< bit:  2.. 0  GPIO19_BIT_MUXSEL      */
        uint32_t DEMUX         : 8;  /*!< bit: 10.. 3  GPIO19_BIT_DEMUX       */
        uint32_t NPU           : 8;  /*!< bit: 18..11  GPIO19_BIT_NPU         */
        uint32_t DEGLITCH      : 1;  /*!< bit:     19  GPIO19_BIT_DEGLITCH    */
        uint32_t RESERVED_31_20:12;  /*!< bit: 31..20                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} GPIO19_REG;


/**
 *  @brief  Union type to access the GPIO20 Pin Configuration Register (GPIO20), offset 0x54.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t MUXSEL        : 3;  /*!< bit:  2.. 0  GPIO20_BIT_MUXSEL      */
        uint32_t DEMUX         : 8;  /*!< bit: 10.. 3  GPIO20_BIT_DEMUX       */
        uint32_t NPU           : 8;  /*!< bit: 18..11  GPIO20_BIT_NPU         */
        uint32_t DEGLITCH      : 1;  /*!< bit:     19  GPIO20_BIT_DEGLITCH    */
        uint32_t RESERVED_31_20:12;  /*!< bit: 31..20                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} GPIO20_REG;


/**
 *  @brief  Union type to access the GPIO21 Pin Configuration Register (GPIO21), offset 0x58.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t MUXSEL        : 3;  /*!< bit:  2.. 0  GPIO21_BIT_MUXSEL      */
        uint32_t DEMUX         : 8;  /*!< bit: 10.. 3  GPIO21_BIT_DEMUX       */
        uint32_t NPU           : 8;  /*!< bit: 18..11  GPIO21_BIT_NPU         */
        uint32_t DEGLITCH      : 1;  /*!< bit:     19  GPIO21_BIT_DEGLITCH    */
        uint32_t RESERVED_31_20:12;  /*!< bit: 31..20                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} GPIO21_REG;


/**
 *  @brief  Union type to access the GPIO22 Pin Configuration Register (GPIO22), offset 0x5C.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t MUXSEL        : 3;  /*!< bit:  2.. 0  GPIO22_BIT_MUXSEL      */
        uint32_t DEMUX         : 8;  /*!< bit: 10.. 3  GPIO22_BIT_DEMUX       */
        uint32_t NPU           : 8;  /*!< bit: 18..11  GPIO22_BIT_NPU         */
        uint32_t DEGLITCH      : 1;  /*!< bit:     19  GPIO22_BIT_DEGLITCH    */
        uint32_t RESERVED_31_20:12;  /*!< bit: 31..20                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} GPIO22_REG;


/**
 *  @brief  Union type to access the GPIO23 Pin Configuration Register (GPIO23), offset 0x60.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t MUXSEL        : 3;  /*!< bit:  2.. 0  GPIO23_BIT_MUXSEL      */
        uint32_t DEMUX         : 8;  /*!< bit: 10.. 3  GPIO23_BIT_DEMUX       */
        uint32_t NPU           : 8;  /*!< bit: 18..11  GPIO23_BIT_NPU         */
        uint32_t DEGLITCH      : 1;  /*!< bit:     19  GPIO23_BIT_DEGLITCH    */
        uint32_t RESERVED_31_20:12;  /*!< bit: 31..20                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} GPIO23_REG;


/**
 *  @brief  Union type to access the GPIO24 Pin Configuration Register (GPIO24), offset 0x64.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t MUXSEL        : 3;  /*!< bit:  2.. 0  GPIO24_BIT_MUXSEL      */
        uint32_t DEMUX         : 8;  /*!< bit: 10.. 3  GPIO24_BIT_DEMUX       */
        uint32_t NPU           : 8;  /*!< bit: 18..11  GPIO24_BIT_NPU         */
        uint32_t DEGLITCH      : 1;  /*!< bit:     19  GPIO24_BIT_DEGLITCH    */
        uint32_t RESERVED_31_20:12;  /*!< bit: 31..20                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} GPIO24_REG;


/**
 *  @brief  Union type to access the GPIO25 Pin Configuration Register (GPIO25), offset 0x68.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t MUXSEL        : 3;  /*!< bit:  2.. 0  GPIO25_BIT_MUXSEL      */
        uint32_t DEMUX         : 8;  /*!< bit: 10.. 3  GPIO25_BIT_DEMUX       */
        uint32_t NPU           : 8;  /*!< bit: 18..11  GPIO25_BIT_NPU         */
        uint32_t DEGLITCH      : 1;  /*!< bit:     19  GPIO25_BIT_DEGLITCH    */
        uint32_t RESERVED_31_20:12;  /*!< bit: 31..20                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} GPIO25_REG;


/**
 *  @brief  Union type to access the GPIO26 Pin Configuration Register (GPIO26), offset 0x6C.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t MUXSEL        : 3;  /*!< bit:  2.. 0  GPIO26_BIT_MUXSEL      */
        uint32_t DEMUX         : 8;  /*!< bit: 10.. 3  GPIO26_BIT_DEMUX       */
        uint32_t NPU           : 8;  /*!< bit: 18..11  GPIO26_BIT_NPU         */
        uint32_t DEGLITCH      : 1;  /*!< bit:     19  GPIO26_BIT_DEGLITCH    */
        uint32_t RESERVED_31_20:12;  /*!< bit: 31..20                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} GPIO26_REG;


/**
 *  @brief  Union type to access the GPIO27 Pin Configuration Register (GPIO27), offset 0x70.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t MUXSEL        : 3;  /*!< bit:  2.. 0  GPIO27_BIT_MUXSEL      */
        uint32_t DEMUX         : 8;  /*!< bit: 10.. 3  GPIO27_BIT_DEMUX       */
        uint32_t NPU           : 8;  /*!< bit: 18..11  GPIO27_BIT_NPU         */
        uint32_t DEGLITCH      : 1;  /*!< bit:     19  GPIO27_BIT_DEGLITCH    */
        uint32_t RESERVED_31_20:12;  /*!< bit: 31..20                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} GPIO27_REG;


/**
 *  @brief  Union type to access the GPIO28 Pin Configuration Register (GPIO28), offset 0x74.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t MUXSEL        : 3;  /*!< bit:  2.. 0  GPIO28_BIT_MUXSEL      */
        uint32_t DEMUX         : 8;  /*!< bit: 10.. 3  GPIO28_BIT_DEMUX       */
        uint32_t NPU           : 8;  /*!< bit: 18..11  GPIO28_BIT_NPU         */
        uint32_t DEGLITCH      : 1;  /*!< bit:     19  GPIO28_BIT_DEGLITCH    */
        uint32_t RESERVED_31_20:12;  /*!< bit: 31..20                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} GPIO28_REG;


/**
 *  @brief  Union type to access the GPIO29 Pin Configuration Register (GPIO29), offset 0x78.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t MUXSEL        : 3;  /*!< bit:  2.. 0  GPIO29_BIT_MUXSEL      */
        uint32_t DEMUX         : 8;  /*!< bit: 10.. 3  GPIO29_BIT_DEMUX       */
        uint32_t NPU           : 8;  /*!< bit: 18..11  GPIO29_BIT_NPU         */
        uint32_t DEGLITCH      : 1;  /*!< bit:     19  GPIO29_BIT_DEGLITCH    */
        uint32_t RESERVED_31_20:12;  /*!< bit: 31..20                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} GPIO29_REG;


/**
 *  @brief  Union type to access the GPIO30 Pin Configuration Register (GPIO30), offset 0x7C.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t MUXSEL        : 3;  /*!< bit:  2.. 0  GPIO30_BIT_MUXSEL      */
        uint32_t DEMUX         : 8;  /*!< bit: 10.. 3  GPIO30_BIT_DEMUX       */
        uint32_t NPU           : 8;  /*!< bit: 18..11  GPIO30_BIT_NPU         */
        uint32_t DEGLITCH      : 1;  /*!< bit:     19  GPIO30_BIT_DEGLITCH    */
        uint32_t RESERVED_31_20:12;  /*!< bit: 31..20                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} GPIO30_REG;


/**
 *  @brief  Union type to access the GPIO31 Pin Configuration Register (GPIO31), offset 0x80.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t MUXSEL        : 3;  /*!< bit:  2.. 0  GPIO31_BIT_MUXSEL      */
        uint32_t DEMUX         : 8;  /*!< bit: 10.. 3  GPIO31_BIT_DEMUX       */
        uint32_t NPU           : 8;  /*!< bit: 18..11  GPIO31_BIT_NPU         */
        uint32_t DEGLITCH      : 1;  /*!< bit:     19  GPIO31_BIT_DEGLITCH    */
        uint32_t RESERVED_31_20:12;  /*!< bit: 31..20                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} GPIO31_REG;


/**
 *  @brief  Union type to access the GPIO32 Pin Configuration Register (GPIO32), offset 0x84.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t MUXSEL        : 3;  /*!< bit:  2.. 0  GPIO32_BIT_MUXSEL      */
        uint32_t DEMUX         : 8;  /*!< bit: 10.. 3  GPIO32_BIT_DEMUX       */
        uint32_t NPU           : 8;  /*!< bit: 18..11  GPIO32_BIT_NPU         */
        uint32_t DEGLITCH      : 1;  /*!< bit:     19  GPIO32_BIT_DEGLITCH    */
        uint32_t RESERVED_31_20:12;  /*!< bit: 31..20                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} GPIO32_REG;


/**
 *  @brief  Union type to access the GPIO33 Pin Configuration Register (GPIO33), offset 0x88.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t MUXSEL        : 3;  /*!< bit:  2.. 0  GPIO33_BIT_MUXSEL      */
        uint32_t DEMUX         : 8;  /*!< bit: 10.. 3  GPIO33_BIT_DEMUX       */
        uint32_t NPU           : 8;  /*!< bit: 18..11  GPIO33_BIT_NPU         */
        uint32_t DEGLITCH      : 1;  /*!< bit:     19  GPIO33_BIT_DEGLITCH    */
        uint32_t RESERVED_31_20:12;  /*!< bit: 31..20                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} GPIO33_REG;


/**
 *  @brief  Union type to access the GPIO34 Pin Configuration Register (GPIO34), offset 0x8C.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t MUXSEL        : 3;  /*!< bit:  2.. 0  GPIO34_BIT_MUXSEL      */
        uint32_t DEMUX         : 8;  /*!< bit: 10.. 3  GPIO34_BIT_DEMUX       */
        uint32_t NPU           : 8;  /*!< bit: 18..11  GPIO34_BIT_NPU         */
        uint32_t DEGLITCH      : 1;  /*!< bit:     19  GPIO34_BIT_DEGLITCH    */
        uint32_t RESERVED_31_20:12;  /*!< bit: 31..20                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} GPIO34_REG;


/**
 *  @brief  Union type to access the GPIO35 Pin Configuration Register (GPIO35), offset 0x90.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t MUXSEL        : 3;  /*!< bit:  2.. 0  GPIO35_BIT_MUXSEL      */
        uint32_t DEMUX         : 8;  /*!< bit: 10.. 3  GPIO35_BIT_DEMUX       */
        uint32_t NPU           : 8;  /*!< bit: 18..11  GPIO35_BIT_NPU         */
        uint32_t DEGLITCH      : 1;  /*!< bit:     19  GPIO35_BIT_DEGLITCH    */
        uint32_t RESERVED_31_20:12;  /*!< bit: 31..20                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} GPIO35_REG;





/**
  *  @brief  Structure type to access the PINMUX Controller (PINMUX).
  */
typedef struct
{
    __IO GPIO0_REG         GPIO0              ; /*!< Offset: 0x00000000 (RW  )  GPIO0 Pin Configuration Register   */
         uint32_t          RESERVED0          ; 
    __IO GPIO1_REG         GPIO1              ; /*!< Offset: 0x00000008 (RW  )  GPIO1 Pin Configuration Register   */
    __IO GPIO2_REG         GPIO2              ; /*!< Offset: 0x0000000C (RW  )  GPIO2 Pin Configuration Register   */
    __IO GPIO3_REG         GPIO3              ; /*!< Offset: 0x00000010 (RW  )  GPIO3 Pin Configuration Register   */
    __IO GPIO4_REG         GPIO4              ; /*!< Offset: 0x00000014 (RW  )  GPIO4 Pin Configuration Register   */
    __IO GPIO5_REG         GPIO5              ; /*!< Offset: 0x00000018 (RW  )  GPIO5 Pin Configuration Register   */
    __IO GPIO6_REG         GPIO6              ; /*!< Offset: 0x0000001C (RW  )  GPIO6 Pin Configuration Register   */
    __IO GPIO7_REG         GPIO7              ; /*!< Offset: 0x00000020 (RW  )  GPIO7 Pin Configuration Register   */
    __IO GPIO8_REG         GPIO8              ; /*!< Offset: 0x00000024 (RW  )  GPIO8 Pin Configuration Register   */
    __IO GPIO9_REG         GPIO9              ; /*!< Offset: 0x00000028 (RW  )  GPIO9 Pin Configuration Register   */
    __IO GPIO10_REG        GPIO10             ; /*!< Offset: 0x0000002C (RW  )  GPIO10 Pin Configuration Register  */
    __IO GPIO11_REG        GPIO11             ; /*!< Offset: 0x00000030 (RW  )  GPIO11 Pin Configuration Register  */
    __IO GPIO12_REG        GPIO12             ; /*!< Offset: 0x00000034 (RW  )  GPIO12 Pin Configuration Register  */
    __IO GPIO13_REG        GPIO13             ; /*!< Offset: 0x00000038 (RW  )  GPIO13 Pin Configuration Register  */
    __IO GPIO14_REG        GPIO14             ; /*!< Offset: 0x0000003C (RW  )  GPIO14 Pin Configuration Register  */
    __IO GPIO15_REG        GPIO15             ; /*!< Offset: 0x00000040 (RW  )  GPIO15 Pin Configuration Register  */
    __IO GPIO16_REG        GPIO16             ; /*!< Offset: 0x00000044 (RW  )  GPIO16 Pin Configuration Register  */
    __IO GPIO17_REG        GPIO17             ; /*!< Offset: 0x00000048 (RW  )  GPIO17 Pin Configuration Register  */
    __IO GPIO18_REG        GPIO18             ; /*!< Offset: 0x0000004C (RW  )  GPIO18 Pin Configuration Register  */
    __IO GPIO19_REG        GPIO19             ; /*!< Offset: 0x00000050 (RW  )  GPIO19 Pin Configuration Register  */
    __IO GPIO20_REG        GPIO20             ; /*!< Offset: 0x00000054 (RW  )  GPIO20 Pin Configuration Register  */
    __IO GPIO21_REG        GPIO21             ; /*!< Offset: 0x00000058 (RW  )  GPIO21 Pin Configuration Register  */
    __IO GPIO22_REG        GPIO22             ; /*!< Offset: 0x0000005C (RW  )  GPIO22 Pin Configuration Register  */
    __IO GPIO23_REG        GPIO23             ; /*!< Offset: 0x00000060 (RW  )  GPIO23 Pin Configuration Register  */
    __IO GPIO24_REG        GPIO24             ; /*!< Offset: 0x00000064 (RW  )  GPIO24 Pin Configuration Register  */
    __IO GPIO25_REG        GPIO25             ; /*!< Offset: 0x00000068 (RW  )  GPIO25 Pin Configuration Register  */
    __IO GPIO26_REG        GPIO26             ; /*!< Offset: 0x0000006C (RW  )  GPIO26 Pin Configuration Register  */
    __IO GPIO27_REG        GPIO27             ; /*!< Offset: 0x00000070 (RW  )  GPIO27 Pin Configuration Register  */
    __IO GPIO28_REG        GPIO28             ; /*!< Offset: 0x00000074 (RW  )  GPIO28 Pin Configuration Register  */
    __IO GPIO29_REG        GPIO29             ; /*!< Offset: 0x00000078 (RW  )  GPIO29 Pin Configuration Register  */
    __IO GPIO30_REG        GPIO30             ; /*!< Offset: 0x0000007C (RW  )  GPIO30 Pin Configuration Register  */
    __IO GPIO31_REG        GPIO31             ; /*!< Offset: 0x00000080 (RW  )  GPIO31 Pin Configuration Register  */
    __IO GPIO32_REG        GPIO32             ; /*!< Offset: 0x00000084 (RW  )  GPIO32 Pin Configuration Register  */
    __IO GPIO33_REG        GPIO33             ; /*!< Offset: 0x00000088 (RW  )  GPIO33 Pin Configuration Register  */
    __IO GPIO34_REG        GPIO34             ; /*!< Offset: 0x0000008C (RW  )  GPIO34 Pin Configuration Register  */
    __IO GPIO35_REG        GPIO35             ; /*!< Offset: 0x00000090 (RW  )  GPIO35 Pin Configuration Register  */
} PINMUX_REGS;


/********************************************************************************
*
* Module Name     ECAP
*
*
********************************************************************************/



/**
 *  @brief  Union type to access the Time-Stamp Counter Register (TSCNT), offset 0x0.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :32;  /*!< bit: 31.. 0  TSCNT_BIT_VAL          */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} TSCNT_REG;


/**
 *  @brief  Union type to access the Counter Phase Offset Value Register (CNTPHS), offset 0x4.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :32;  /*!< bit: 31.. 0  CNTPHS_BIT_VAL         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} CNTPHS_REG;


/**
 *  @brief  Union type to access the Capture Register 0 (CAP0), offset 0x8.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :32;  /*!< bit: 31.. 0  CAP0_BIT_VAL           */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} CAP0_REG;


/**
 *  @brief  Union type to access the Capture Register 1 (CAP1), offset 0xC.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :32;  /*!< bit: 31.. 0  CAP1_BIT_VAL           */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} CAP1_REG;


/**
 *  @brief  Union type to access the Capture Register 2 (CAP2), offset 0x10.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :32;  /*!< bit: 31.. 0  CAP2_BIT_VAL           */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} CAP2_REG;


/**
 *  @brief  Union type to access the Capture Register 3 (CAP3), offset 0x14.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :32;  /*!< bit: 31.. 0  CAP3_BIT_VAL           */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} CAP3_REG;


/**
 *  @brief  Union type to access the Capture Control Register (CAPCTL), offset 0x18.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t CAP0POL       : 1;  /*!< bit:      0  CAPCTL_BIT_CAP0POL     */
        uint32_t CNTRST0       : 1;  /*!< bit:      1  CAPCTL_BIT_CNTRST0     */
        uint32_t CAP1POL       : 1;  /*!< bit:      2  CAPCTL_BIT_CAP1POL     */
        uint32_t CNTRST1       : 1;  /*!< bit:      3  CAPCTL_BIT_CNTRST1     */
        uint32_t CAP2POL       : 1;  /*!< bit:      4  CAPCTL_BIT_CAP2POL     */
        uint32_t CNTRST2       : 1;  /*!< bit:      5  CAPCTL_BIT_CNTRST2     */
        uint32_t CAP3POL       : 1;  /*!< bit:      6  CAPCTL_BIT_CAP3POL     */
        uint32_t CNTRST3       : 1;  /*!< bit:      7  CAPCTL_BIT_CNTRST3     */
        uint32_t CAPLDEN       : 1;  /*!< bit:      8  CAPCTL_BIT_CAPLDEN     */
        uint32_t EVTDIV        : 5;  /*!< bit: 13.. 9  CAPCTL_BIT_EVTDIV      */
        uint32_t DBGRUN        : 2;  /*!< bit: 15..14  CAPCTL_BIT_DBGRUN      */
        uint32_t MODE          : 1;  /*!< bit:     16  CAPCTL_BIT_MODE        */
        uint32_t STOPWRAP      : 2;  /*!< bit: 18..17  CAPCTL_BIT_STOPWRAP    */
        uint32_t REARM         : 1;  /*!< bit:     19  CAPCTL_BIT_REARM       */
        uint32_t TSCNTRUN      : 1;  /*!< bit:     20  CAPCTL_BIT_TSCNTRUN    */
        uint32_t SYNCIEN       : 1;  /*!< bit:     21  CAPCTL_BIT_SYNCIEN     */
        uint32_t SYNCOSEL      : 2;  /*!< bit: 23..22  CAPCTL_BIT_SYNCOSEL    */
        uint32_t FRCSYNC       : 1;  /*!< bit:     24  CAPCTL_BIT_FRCSYNC     */
        uint32_t CAPAPWM       : 1;  /*!< bit:     25  CAPCTL_BIT_CAPAPWM     */
        uint32_t APWMPOL       : 1;  /*!< bit:     26  CAPCTL_BIT_APWMPOL     */
        uint32_t RESERVED_31_27: 5;  /*!< bit: 31..27                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} CAPCTL_REG;


/**
 *  @brief  Union type to access the Capture Interrupt Enable and Flag Register (CAPIEIF), offset 0x1C.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t IFGLB         : 1;  /*!< bit:      0  CAPIEIF_BIT_IFGLB      */
        uint32_t IFCEVT0       : 1;  /*!< bit:      1  CAPIEIF_BIT_IFCEVT0    */
        uint32_t IFCEVT1       : 1;  /*!< bit:      2  CAPIEIF_BIT_IFCEVT1    */
        uint32_t IFCEVT2       : 1;  /*!< bit:      3  CAPIEIF_BIT_IFCEVT2    */
        uint32_t IFCEVT3       : 1;  /*!< bit:      4  CAPIEIF_BIT_IFCEVT3    */
        uint32_t IFCNTOVF      : 1;  /*!< bit:      5  CAPIEIF_BIT_IFCNTOVF   */
        uint32_t IFPRD         : 1;  /*!< bit:      6  CAPIEIF_BIT_IFPRD      */
        uint32_t IFCMP         : 1;  /*!< bit:      7  CAPIEIF_BIT_IFCMP      */
        uint32_t RESERVED_8_8  : 1;  /*!< bit:      8                         */
        uint32_t IECEVT0       : 1;  /*!< bit:      9  CAPIEIF_BIT_IECEVT0    */
        uint32_t IECEVT1       : 1;  /*!< bit:     10  CAPIEIF_BIT_IECEVT1    */
        uint32_t IECEVT2       : 1;  /*!< bit:     11  CAPIEIF_BIT_IECEVT2    */
        uint32_t IECEVT3       : 1;  /*!< bit:     12  CAPIEIF_BIT_IECEVT3    */
        uint32_t IECNTOVF      : 1;  /*!< bit:     13  CAPIEIF_BIT_IECNTOVF   */
        uint32_t IEPRD         : 1;  /*!< bit:     14  CAPIEIF_BIT_IEPRD      */
        uint32_t IECMP         : 1;  /*!< bit:     15  CAPIEIF_BIT_IECMP      */
        uint32_t RESERVED_31_16:16;  /*!< bit: 31..16                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} CAPIEIF_REG;


/**
 *  @brief  Union type to access the Capture Interrupt Clear and Force Register (CAPICFRC), offset 0x20.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t RESERVED_0_0  : 1;  /*!< bit:      0                         */
        uint32_t FRCCEVT0      : 1;  /*!< bit:      1  CAPICFRC_BIT_FRCCEVT0  */
        uint32_t FRCCEVT1      : 1;  /*!< bit:      2  CAPICFRC_BIT_FRCCEVT1  */
        uint32_t FRCCEVT2      : 1;  /*!< bit:      3  CAPICFRC_BIT_FRCCEVT2  */
        uint32_t FRCCEVT3      : 1;  /*!< bit:      4  CAPICFRC_BIT_FRCCEVT3  */
        uint32_t FRCCNTOVF     : 1;  /*!< bit:      5  CAPICFRC_BIT_FRCCNTOVF */
        uint32_t FRCPRD        : 1;  /*!< bit:      6  CAPICFRC_BIT_FRCPRD    */
        uint32_t FRCCMP        : 1;  /*!< bit:      7  CAPICFRC_BIT_FRCCMP    */
        uint32_t ICGLB         : 1;  /*!< bit:      8  CAPICFRC_BIT_ICGLB     */
        uint32_t ICCEVT0       : 1;  /*!< bit:      9  CAPICFRC_BIT_ICCEVT0   */
        uint32_t ICCEVT1       : 1;  /*!< bit:     10  CAPICFRC_BIT_ICCEVT1   */
        uint32_t ICCEVT2       : 1;  /*!< bit:     11  CAPICFRC_BIT_ICCEVT2   */
        uint32_t ICCEVT3       : 1;  /*!< bit:     12  CAPICFRC_BIT_ICCEVT3   */
        uint32_t ICCNTOVF      : 1;  /*!< bit:     13  CAPICFRC_BIT_ICCNTOVF  */
        uint32_t ICPRD         : 1;  /*!< bit:     14  CAPICFRC_BIT_ICPRD     */
        uint32_t ICCMP         : 1;  /*!< bit:     15  CAPICFRC_BIT_ICCMP     */
        uint32_t RESERVED_31_16:16;  /*!< bit: 31..16                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} CAPICFRC_REG;





/**
  *  @brief  Structure type to access the ECAP Controller (ECAP).
  */
typedef struct
{
    __IO TSCNT_REG        TSCNT             ; /*!< Offset: 0x00000000 (RW  )  Time-Stamp Counter Register                 */
    __IO CNTPHS_REG       CNTPHS            ; /*!< Offset: 0x00000004 (RW  )  Counter Phase Offset Value Register         */
    __IO CAP0_REG         CAP0              ; /*!< Offset: 0x00000008 (RW  )  Capture Register 0                          */
    __IO CAP1_REG         CAP1              ; /*!< Offset: 0x0000000C (RW  )  Capture Register 1                          */
    __IO CAP2_REG         CAP2              ; /*!< Offset: 0x00000010 (RW  )  Capture Register 2                          */
    __IO CAP3_REG         CAP3              ; /*!< Offset: 0x00000014 (RW  )  Capture Register 3                          */
    __IO CAPCTL_REG       CAPCTL            ; /*!< Offset: 0x00000018 (RW  )  Capture Control Register                    */
    __IO CAPIEIF_REG      CAPIEIF           ; /*!< Offset: 0x0000001C (RW  )  Capture Interrupt Enable and Flag Register  */
    __IO CAPICFRC_REG     CAPICFRC          ; /*!< Offset: 0x00000020 (RW  )  Capture Interrupt Clear and Force Register  */
} ECAP_REGS;


/********************************************************************************
*
* Module Name     CRC
*
*
********************************************************************************/



/**
 *  @brief  Union type to access the CRC Interrupt Flag Register (CRCIF), offset 0x0.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t DONE          : 1;  /*!< bit:      0  CRCIF_BIT_DONE         */
        uint32_t RESERVED_31_1 :31;  /*!< bit: 31.. 1                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} CRCIF_REG;


/**
 *  @brief  Union type to access the CRC Raw Interrupt Flag Register (CRCRAWIF), offset 0x4.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t DONE          : 1;  /*!< bit:      0  CRCRAWIF_BIT_DONE      */
        uint32_t RESERVED_31_1 :31;  /*!< bit: 31.. 1                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} CRCRAWIF_REG;


/**
 *  @brief  Union type to access the CRC Interrupt Clear Register (CRCIC), offset 0x8.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t DONE          : 1;  /*!< bit:      0  CRCIC_BIT_DONE         */
        uint32_t RESERVED_31_1 :31;  /*!< bit: 31.. 1                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} CRCIC_REG;


/**
 *  @brief  Union type to access the CRC Interrupt Mask Register (CRCINTMSK), offset 0xC.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t MSKDONE       : 1;  /*!< bit:      0  CRCINTMSK_BIT_MSKDONE  */
        uint32_t RESERVED_31_1 :31;  /*!< bit: 31.. 1                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} CRCINTMSK_REG;


/**
 *  @brief  Union type to access the CRC Control Register (CRCCTL), offset 0x10.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t EN            : 1;  /*!< bit:      0  CRCCTL_BIT_EN          */
        uint32_t MODE          : 3;  /*!< bit:  3.. 1  CRCCTL_BIT_MODE        */
        uint32_t RESERVED_31_4 :28;  /*!< bit: 31.. 4                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} CRCCTL_REG;


/**
 *  @brief  Union type to access the CRC Stream Length Register (CRCSTRLEN), offset 0x14.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :32;  /*!< bit: 31.. 0  CRCSTRLEN_BIT_VAL      */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} CRCSTRLEN_REG;


/**
 *  @brief  Union type to access the CRC Stream Input Register (CRCSTRIN), offset 0x18.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :32;  /*!< bit: 31.. 0  CRCSTRIN_BIT_VAL       */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} CRCSTRIN_REG;


/**
 *  @brief  Union type to access the CRC Result Register (CRCRESULT), offset 0x1C.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :32;  /*!< bit: 31.. 0  CRCRESULT_BIT_VAL      */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} CRCRESULT_REG;





/**
  *  @brief  Structure type to access the CRC Controller (CRC).
  */
typedef struct
{
    __I  CRCIF_REG         CRCIF              ; /*!< Offset: 0x00000000 (RO  )  CRC Interrupt Flag Register      */
    __I  CRCRAWIF_REG      CRCRAWIF           ; /*!< Offset: 0x00000004 (RO  )  CRC Raw Interrupt Flag Register  */
    __O  CRCIC_REG         CRCIC              ; /*!< Offset: 0x00000008 (WO  )  CRC Interrupt Clear Register     */
    __IO CRCINTMSK_REG     CRCINTMSK          ; /*!< Offset: 0x0000000C (RW  )  CRC Interrupt Mask Register      */
    __IO CRCCTL_REG        CRCCTL             ; /*!< Offset: 0x00000010 (RW  )  CRC Control Register             */
    __IO CRCSTRLEN_REG     CRCSTRLEN          ; /*!< Offset: 0x00000014 (RW  )  CRC Stream Length Register       */
    __IO CRCSTRIN_REG      CRCSTRIN           ; /*!< Offset: 0x00000018 (RW  )  CRC Stream Input Register        */
    __I  CRCRESULT_REG     CRCRESULT          ; /*!< Offset: 0x0000001C (RO  )  CRC Result Register              */
} CRC_REGS;


/********************************************************************************
*
* Module Name     AES
*
*
********************************************************************************/



/**
 *  @brief  Union type to access the AES Control Register 0 (AESCTL0), offset 0x0.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t START         : 1;  /*!< bit:      0  AESCTL0_BIT_START      */
        uint32_t RESERVED_1_1  : 1;  /*!< bit:      1                         */
        uint32_t IFIFOCLR      : 1;  /*!< bit:      2  AESCTL0_BIT_IFIFOCLR   */
        uint32_t OFIFOCLR      : 1;  /*!< bit:      3  AESCTL0_BIT_OFIFOCLR   */
        uint32_t OUTMSG        : 1;  /*!< bit:      4  AESCTL0_BIT_OUTMSG     */
        uint32_t OUTHDR        : 1;  /*!< bit:      5  AESCTL0_BIT_OUTHDR     */
        uint32_t RESERVED_7_6  : 2;  /*!< bit:  7.. 6                         */
        uint32_t RESERVED_8_8  : 1;  /*!< bit:      8                         */
        uint32_t RESERVED_9_9  : 1;  /*!< bit:      9                         */
        uint32_t KEYSIZE       : 2;  /*!< bit: 11..10  AESCTL0_BIT_KEYSIZE    */
        uint32_t MICLEN        : 2;  /*!< bit: 13..12  AESCTL0_BIT_MICLEN     */
        uint32_t OUTMIC        : 1;  /*!< bit:     14  AESCTL0_BIT_OUTMIC     */
        uint32_t DECRYPTEN     : 1;  /*!< bit:     15  AESCTL0_BIT_DECRYPTEN  */
        uint32_t MODE          : 3;  /*!< bit: 18..16  AESCTL0_BIT_MODE       */
        uint32_t CNTMOD        : 7;  /*!< bit: 25..19  AESCTL0_BIT_CNTMOD     */
        uint32_t RESERVED_31_26: 6;  /*!< bit: 31..26                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} AESCTL0_REG;


/**
 *  @brief  Union type to access the AES Control Register 1 (AESCTL1), offset 0x4.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t RST           : 1;  /*!< bit:      0  AESCTL1_BIT_RST        */
        uint32_t RESERVED_31_1 :31;  /*!< bit: 31.. 1                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} AESCTL1_REG;


/**
 *  @brief  Union type to access the AES Status Register (AESSTS), offset 0x8.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t DONE          : 1;  /*!< bit:      0  AESSTS_BIT_DONE        */
        uint32_t RESERVED_3_1  : 3;  /*!< bit:  3.. 1                         */
        uint32_t IFIFOFULL     : 1;  /*!< bit:      4  AESSTS_BIT_IFIFOFULL   */
        uint32_t RESERVED_5_5  : 1;  /*!< bit:      5                         */
        uint32_t OFIFORDY      : 1;  /*!< bit:      6  AESSTS_BIT_OFIFORDY    */
        uint32_t OFIFOEMPTY    : 1;  /*!< bit:      7  AESSTS_BIT_OFIFOEMPTY  */
        uint32_t RESERVED_10_8 : 3;  /*!< bit: 10.. 8                         */
        uint32_t ERRCODE       : 3;  /*!< bit: 13..11  AESSTS_BIT_ERRCODE     */
        uint32_t IFIFODEPTH    : 3;  /*!< bit: 16..14  AESSTS_BIT_IFIFODEPTH  */
        uint32_t OFIFODEPTH    : 3;  /*!< bit: 19..17  AESSTS_BIT_OFIFODEPTH  */
        uint32_t RESERVED_31_20:12;  /*!< bit: 31..20                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} AESSTS_REG;


/**
 *  @brief  Union type to access the AES Associate String Length Register (AESASTRLEN), offset 0xC.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :32;  /*!< bit: 31.. 0  AESASTRLEN_BIT_VAL     */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} AESASTRLEN_REG;


/**
 *  @brief  Union type to access the AES Message String Length Register (AESMSTRLEN), offset 0x10.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :32;  /*!< bit: 31.. 0  AESMSTRLEN_BIT_VAL     */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} AESMSTRLEN_REG;


/**
 *  @brief  Union type to access the AES Input Message Word Register (AESSTRIN), offset 0x14.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :32;  /*!< bit: 31.. 0  AESSTRIN_BIT_VAL       */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} AESSTRIN_REG;


/**
 *  @brief  Union type to access the AES Initial Vector Register 0 (AESIV0), offset 0x18.
            Union type to access the AES Initial Vector Register 1 (AESIV1), offset 0x1C.
            Union type to access the AES Initial Vector Register 2 (AESIV2), offset 0x20.
            Union type to access the AES Initial Vector Register 3 (AESIV3), offset 0x24.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :32;  /*!< bit: 31.. 0  AESIV0_BIT_VAL         
                                                       AESIV1_BIT_VAL         
                                                       AESIV2_BIT_VAL         
                                                       AESIV3_BIT_VAL         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} AESIVx_REG;


/**
 *  @brief  Union type to access the AES Key Register 0 (AESKEY0), offset 0x28.
            Union type to access the AES Key Register 1 (AESKEY1), offset 0x2C.
            Union type to access the AES Key Register 2 (AESKEY2), offset 0x30.
            Union type to access the AES Key Register 3 (AESKEY3), offset 0x34.
            Union type to access the AES Key Register 4 (AESKEY4), offset 0x38.
            Union type to access the AES Key Register 5 (AESKEY5), offset 0x3C.
            Union type to access the AES Key Register 6 (AESKEY6), offset 0x40.
            Union type to access the AES Key Register 7 (AESKEY7), offset 0x44.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :32;  /*!< bit: 31.. 0  AESKEY0_BIT_VAL        
                                                       AESKEY1_BIT_VAL        
                                                       AESKEY2_BIT_VAL        
                                                       AESKEY3_BIT_VAL        
                                                       AESKEY4_BIT_VAL        
                                                       AESKEY5_BIT_VAL        
                                                       AESKEY6_BIT_VAL        
                                                       AESKEY7_BIT_VAL        */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} AESKEYx_REG;


/**
 *  @brief  Union type to access the AES Output Message Word Register (AESSTROUT), offset 0x48.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :32;  /*!< bit: 31.. 0  AESSTROUT_BIT_VAL      */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} AESSTROUT_REG;


/**
 *  @brief  Union type to access the AES Output Vector Register 0 (AESOV0), offset 0x4C.
            Union type to access the AES Output Vector Register 1 (AESOV1), offset 0x50.
            Union type to access the AES Output Vector Register 2 (AESOV2), offset 0x54.
            Union type to access the AES Output Vector Register 3 (AESOV3), offset 0x58.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t VAL           :32;  /*!< bit: 31.. 0  AESOV0_BIT_VAL         
                                                       AESOV1_BIT_VAL         
                                                       AESOV2_BIT_VAL         
                                                       AESOV3_BIT_VAL         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} AESOVx_REG;


/**
 *  @brief  Union type to access the AES Interrupt Status Register (AESIF), offset 0x5C.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t DONE          : 1;  /*!< bit:      0  AESIF_BIT_DONE         */
        uint32_t IFIFOFULL     : 1;  /*!< bit:      1  AESIF_BIT_IFIFOFULL    */
        uint32_t OFIFOEMPTY    : 1;  /*!< bit:      2  AESIF_BIT_OFIFOEMPTY   */
        uint32_t RESERVED_31_3 :29;  /*!< bit: 31.. 3                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} AESIF_REG;


/**
 *  @brief  Union type to access the AES Interrupt Mask Register (AESINTMSK), offset 0x60.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t DONE          : 1;  /*!< bit:      0  AESINTMSK_BIT_DONE     */
        uint32_t IFIFOFULL     : 1;  /*!< bit:      1  AESINTMSK_BIT_IFIFOFULL*/
        uint32_t OFIFOEMPTY    : 1;  /*!< bit:      2  AESINTMSK_BIT_OFIFOEMPTY*/
        uint32_t RESERVED_31_3 :29;  /*!< bit: 31.. 3                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} AESINTMSK_REG;


/**
 *  @brief  Union type to access the AES Interrupt RAW status Register (AESRAWIF), offset 0x64.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t DONE          : 1;  /*!< bit:      0  AESRAWIF_BIT_DONE      */
        uint32_t IFIFOFULL     : 1;  /*!< bit:      1  AESRAWIF_BIT_IFIFOFULL */
        uint32_t OFIFOEMPTY    : 1;  /*!< bit:      2  AESRAWIF_BIT_OFIFOEMPTY*/
        uint32_t RESERVED_31_3 :29;  /*!< bit: 31.. 3                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} AESRAWIF_REG;


/**
 *  @brief  Union type to access the AES Interrupt Clear Register (AESIC), offset 0x68.
 */
typedef union
{
    struct
    {                                /*!< Bit zone     Definition label       */
        uint32_t DONE          : 1;  /*!< bit:      0  AESIC_BIT_DONE         */
        uint32_t IFIFOFULL     : 1;  /*!< bit:      1  AESIC_BIT_IFIFOFULL    */
        uint32_t OFIFOEMPTY    : 1;  /*!< bit:      2  AESIC_BIT_OFIFOEMPTY   */
        uint32_t RESERVED_31_3 :29;  /*!< bit: 31.. 3                         */
    } bit;                           /*!< Structure used for bit  access      */
    uint32_t all;                    /*!< Type      used for word access      */
} AESIC_REG;





/**
  *  @brief  Structure type to access the AES Controller (AES).
  */
typedef struct
{
    __IO AESCTL0_REG        AESCTL0             ; /*!< Offset: 0x00000000 (RW  )  AES Control Register 0                */
    __IO AESCTL1_REG        AESCTL1             ; /*!< Offset: 0x00000004 (RW  )  AES Control Register 1                */
    __I  AESSTS_REG         AESSTS              ; /*!< Offset: 0x00000008 (RO  )  AES Status Register                   */
    __IO AESASTRLEN_REG     AESASTRLEN          ; /*!< Offset: 0x0000000C (RW  )  AES Associate String Length Register  */
    __IO AESMSTRLEN_REG     AESMSTRLEN          ; /*!< Offset: 0x00000010 (RW  )  AES Message String Length Register    */
    __O  AESSTRIN_REG       AESSTRIN            ; /*!< Offset: 0x00000014 (WO  )  AES Input Message Word Register       */
    __IO AESIVx_REG         AESIV[4]            ; /*!< Offset: 0x00000018 (RW  )  AES Initial Vector Register 0         */
    __IO AESKEYx_REG        AESKEY[8]           ; /*!< Offset: 0x00000028 (RW  )  AES Key Register 0                    */
    __I  AESSTROUT_REG      AESSTROUT           ; /*!< Offset: 0x00000048 (RO  )  AES Output Message Word Register      */
    __I  AESOVx_REG         AESOV[4]            ; /*!< Offset: 0x0000004C (RO  )  AES Output Vector Register 0          */
    __I  AESIF_REG          AESIF               ; /*!< Offset: 0x0000005C (RO  )  AES Interrupt Status Register         */
    __IO AESINTMSK_REG      AESINTMSK           ; /*!< Offset: 0x00000060 (RW  )  AES Interrupt Mask Register           */
    __I  AESRAWIF_REG       AESRAWIF            ; /*!< Offset: 0x00000064 (RO  )  AES Interrupt RAW status Register     */
    __IO AESIC_REG          AESIC               ; /*!< Offset: 0x00000068 (RW  )  AES Interrupt Clear Register          */
} AES_REGS;




#ifdef __cplusplus
}
#endif /* extern "C" */

#endif /* SPC1068_REG_H */

/******************* (C) COPYRIGHT 2021 SPINTROL LIMITED CO. *****END OF FILE****/
