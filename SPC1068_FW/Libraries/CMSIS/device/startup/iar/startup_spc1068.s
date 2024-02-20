/**************************************************************************//**
 * @file     startup_spc1068.s
 * @brief    SPC1068 device vector table for EWARM toolchain
 * @version  V1.1.0
 * @date     03-August-2017
 *
 * @note
 * Copyright (C) 2017 Spintrol Limited Corporation. All rights reserved.
 *
 * @attention
 * THIS SOFTWARE JUST PROVIDES CUSTOMERS WITH CODING INFORMATION REGARDING 
 * THEIR PRODUCTS, WHICH AIMS AT SAVING TIME FOR THEM. SPINTROL SHALL NOT BE
 * LIABLE FOR THE USE OF THE SOFTWARE. SPINTROL DOES NOT GUARANTEE THE 
 * CORRECTNESS OF THIS SOFTWARE AND RESERVES THE RIGHT TO MODIFY THE SOFTWARE 
 * WITHOUT NOTIFICATION.
 *
 ******************************************************************************/
;
;
; The modules in this file are included in the libraries, and may be replaced
; by any user-defined modules that define the PUBLIC symbol _program_start or
; a user defined start symbol.
; To override the cstartup defined in the library, simply add your modified
; version to the workbench project.
;
; The vector table is normally located at address 0.
; When debugging in RAM, it can be located in RAM, aligned to at least 2^6.
; The name "__vector_table" has special meaning for C-SPY:
; it is where the SP start value is found, and the NVIC vector
; table register (VTOR) is initialized to this address if != 0.
;
; Cortex-M version
;

        MODULE  ?cstartup

        ;; Forward declaration of sections.
        SECTION CSTACK:DATA:NOROOT(3)

        SECTION .intvec:CODE:NOROOT(2)

        EXTERN  __iar_program_start
        EXTERN  SystemInit
        PUBLIC  __vector_table

        DATA
__vector_table
        DCD     sfe(CSTACK)               ;-16 Top of Stack
        DCD     Reset_Handler             ;-15 Reset Handler
        
        DCD     NMI_Handler               ;-14 NMI Handler
        DCD     HardFault_Handler         ;-13 Hard Fault Handler
        DCD     MemManage_Handler         ;-12 MPU Fault Handler
        DCD     BusFault_Handler          ;-11 Bus Fault Handler
        DCD     UsageFault_Handler        ;-10 Usage Fault Handler
        DCD     0                         ;- 9 Reserved
        DCD     0                         ;- 8 Reserved
        DCD     0                         ;- 7 Reserved
        DCD     0                         ;- 6 Reserved
        DCD     SVC_Handler               ;- 5 SVCall Handler
        DCD     DebugMon_Handler          ;- 4 Debug Monitor Handler
        DCD     0                         ;- 3 Reserved
        DCD     PendSV_Handler            ;- 2 PendSV Handler
        DCD     SysTick_Handler           ;- 1 SysTick Handler

        ; External Interrupts
        DCD     UART_IRQHandler           ;  0 UART
        DCD     I2C_IRQHandler            ;  1 I2C
        DCD     SSP_IRQHandler            ;  2 SSP
        DCD     GPIOEdge_IRQHandler       ;  3 GPIO Edge
        DCD     QSPI_IRQHandler           ;  4 QSPI
        DCD     ECAP_IRQHandler           ;  5 eCAP
        DCD     ADC0_IRQHandler           ;  6 ADC SOC0
        DCD     PWM0_IRQHandler           ;  7 PWM0
        DCD     PWM0TZ_IRQHandler         ;  8 PWM0 Trip-zone
        DCD     TIM0_IRQHandler           ;  9 Timer0
        DCD     TIM1_IRQHandler           ; 10 Timer1
        DCD     TIM2_IRQHandler           ; 11 Timer2
        DCD     WDT1_IRQHandler           ; 12 Watchdog Timer1
        DCD     ADC1_IRQHandler           ; 13 ADC SOC1
        DCD     ADC2_IRQHandler           ; 14 ADC SOC2
        DCD     ADC3_IRQHandler           ; 15 ADC SOC3
        DCD     ADC4_IRQHandler           ; 16 ADC SOC4
        DCD     ADC5_IRQHandler           ; 17 ADC SOC5
        DCD     ADC6_IRQHandler           ; 18 ADC SOC6
        DCD     ADC7_IRQHandler           ; 19 ADC SOC7
        DCD     ADC8_IRQHandler           ; 20 ADC SOC8
        DCD     PWM1_IRQHandler           ; 21 PWM1
        DCD     PWM1TZ_IRQHandler         ; 22 PWM1 Trip-Zone
        DCD     PWM2_IRQHandler           ; 23 PWM2
        DCD     PWM2TZ_IRQHandler         ; 24 PWM2 Trip-Zone
        DCD     PWM3_IRQHandler           ; 25 PWM3
        DCD     PWM3TZ_IRQHandler         ; 26 PWM3 Trip-Zone
        DCD     PWM4_IRQHandler           ; 27 PWM4
        DCD     PWM4TZ_IRQHandler         ; 28 PWM4 Trip-Zone
        DCD     PWM5_IRQHandler           ; 29 PWM5
        DCD     PWM5TZ_IRQHandler         ; 30 PWM5 Trip-Zone
        DCD     PWM6_IRQHandler           ; 31 PWM6
        DCD     PWM6TZ_IRQHandler         ; 32 PWM6 Trip-Zone
        DCD     MemParity_IRQHandler      ; 33 Memory parity check
        DCD     AES_IRQHandler            ; 34 AES
        DCD     CRC_IRQHandler            ; 35 CRC
        DCD     GPIOLevel_IRQHandler      ; 36 GPIO Level
        DCD     CLOCK_IRQHandler          ; 37 Clock
        DCD     BOD_IRQHandler            ; 38 BOD
        DCD     ADC9_IRQHandler           ; 39 ADC SOC9
        DCD     ADC10_IRQHandler          ; 40 ADC SOC10
        DCD     ADC11_IRQHandler          ; 41 ADC SOC11
        DCD     ADC12_IRQHandler          ; 42 ADC SOC12
        DCD     ADC13_IRQHandler          ; 43 ADC SOC13
        DCD     ADC14_IRQHandler          ; 44 ADC SOC14
        DCD     ADC15_IRQHandler          ; 45 ADC SOC15
        DCD     0                         ; 46 Reserved
        DCD     0                         ; 47 Reserved


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; Default interrupt handlers.
;;
        THUMB
        PUBWEAK Reset_Handler
        SECTION .text:CODE:REORDER:NOROOT(2)
Reset_Handler
        
        ;* C routines are likely to be called. Setup the stack now
        LDR     SP,=sfe(CSTACK)
        
        LDR     R0, =SystemInit
        BLX     R0
        
        ;* Reset stack pointer before zipping off to user application
        LDR     SP,=sfe(CSTACK)
        
        LDR     R0, =__iar_program_start
        BX      R0


        PUBWEAK NMI_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
NMI_Handler
        B NMI_Handler

        PUBWEAK HardFault_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
HardFault_Handler
        B HardFault_Handler
        
        PUBWEAK MemManage_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
MemManage_Handler
        B MemManage_Handler

        PUBWEAK BusFault_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
BusFault_Handler
        B  BusFault_Handler

        PUBWEAK UsageFault_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
UsageFault_Handler
        B UsageFault_Handler

        PUBWEAK SVC_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
SVC_Handler
        B SVC_Handler

        PUBWEAK DebugMon_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
DebugMon_Handler
        B DebugMon_Handler

        PUBWEAK PendSV_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
PendSV_Handler
        B PendSV_Handler

        PUBWEAK SysTick_Handler
        SECTION .text:CODE:REORDER:NOROOT(1)
SysTick_Handler
        B  SysTick_Handler


        PUBWEAK UART_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
UART_IRQHandler
        B UART_IRQHandler
        
        PUBWEAK I2C_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1) 
I2C_IRQHandler
        B I2C_IRQHandler
        
        PUBWEAK SSP_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1) 
SSP_IRQHandler
        B SSP_IRQHandler
        
        PUBWEAK GPIOEdge_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1) 
GPIOEdge_IRQHandler
        B GPIOEdge_IRQHandler

        PUBWEAK QSPI_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1) 
QSPI_IRQHandler
        B QSPI_IRQHandler
        
        PUBWEAK ECAP_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1) 
ECAP_IRQHandler
        B ECAP_IRQHandler
        
        PUBWEAK ADC0_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1) 
ADC0_IRQHandler
        B ADC0_IRQHandler
        
        PUBWEAK PWM0_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1) 
PWM0_IRQHandler
        B PWM0_IRQHandler
      
        PUBWEAK PWM0TZ_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1) 
PWM0TZ_IRQHandler
        B PWM0TZ_IRQHandler
        
        PUBWEAK TIM0_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1) 
TIM0_IRQHandler
        B TIM0_IRQHandler
      
        PUBWEAK TIM1_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1) 
TIM1_IRQHandler
        B TIM1_IRQHandler
        
        PUBWEAK TIM2_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1) 
TIM2_IRQHandler
        B TIM2_IRQHandler

        PUBWEAK WDT1_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1) 
WDT1_IRQHandler
        B WDT1_IRQHandler

        PUBWEAK ADC1_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1) 
ADC1_IRQHandler
        B ADC1_IRQHandler

        PUBWEAK ADC2_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1) 
ADC2_IRQHandler
        B ADC2_IRQHandler

        PUBWEAK ADC3_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1) 
ADC3_IRQHandler
        B ADC3_IRQHandler

        PUBWEAK ADC4_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1) 
ADC4_IRQHandler
        B ADC4_IRQHandler
        
        PUBWEAK ADC5_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1) 
ADC5_IRQHandler
        B ADC5_IRQHandler
        
        PUBWEAK ADC6_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1) 
ADC6_IRQHandler
        B ADC6_IRQHandler
        
        PUBWEAK ADC7_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1) 
ADC7_IRQHandler
        B ADC7_IRQHandler
        
        PUBWEAK ADC8_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1) 
ADC8_IRQHandler
        B ADC8_IRQHandler
        
        PUBWEAK PWM1_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1) 
PWM1_IRQHandler
        B PWM1_IRQHandler

        PUBWEAK PWM1TZ_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1) 
PWM1TZ_IRQHandler
        B PWM1TZ_IRQHandler

        PUBWEAK PWM2_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1) 
PWM2_IRQHandler
        B PWM2_IRQHandler
        
        PUBWEAK PWM2TZ_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1) 
PWM2TZ_IRQHandler
        B PWM2TZ_IRQHandler
        
        PUBWEAK PWM3_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1) 
PWM3_IRQHandler
        B PWM3_IRQHandler
        
        PUBWEAK PWM3TZ_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
PWM3TZ_IRQHandler
        B PWM3TZ_IRQHandler
        
        PUBWEAK PWM4_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
PWM4_IRQHandler
        B PWM4_IRQHandler
      
        PUBWEAK PWM4TZ_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
PWM4TZ_IRQHandler
        B PWM4TZ_IRQHandler
      
        PUBWEAK PWM5_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1)
PWM5_IRQHandler
        B PWM5_IRQHandler
      
        PUBWEAK PWM5TZ_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1) 
PWM5TZ_IRQHandler
        B PWM5TZ_IRQHandler
      
        PUBWEAK PWM6_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1) 
PWM6_IRQHandler
        B PWM6_IRQHandler

        PUBWEAK PWM6TZ_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1) 
PWM6TZ_IRQHandler
        B PWM6TZ_IRQHandler

        PUBWEAK MemParity_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1) 
MemParity_IRQHandler
        B MemParity_IRQHandler

        PUBWEAK AES_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1) 
AES_IRQHandler
        B AES_IRQHandler
      
        PUBWEAK CRC_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1) 
CRC_IRQHandler
        B CRC_IRQHandler

        PUBWEAK GPIOLevel_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1) 
GPIOLevel_IRQHandler
        B GPIOLevel_IRQHandler

        PUBWEAK CLOCK_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1) 
CLOCK_IRQHandler
        B CLOCK_IRQHandler
        
        PUBWEAK BOD_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1) 
BOD_IRQHandler
        B BOD_IRQHandler
        
        PUBWEAK ADC9_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1) 
ADC9_IRQHandler
        B ADC9_IRQHandler
        
        PUBWEAK ADC10_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1) 
ADC10_IRQHandler
        B ADC10_IRQHandler
        
        PUBWEAK ADC11_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1) 
ADC11_IRQHandler
        B ADC11_IRQHandler
        
        PUBWEAK ADC12_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1) 
ADC12_IRQHandler
        B ADC12_IRQHandler

        PUBWEAK ADC13_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1) 
ADC13_IRQHandler
        B ADC13_IRQHandler

        PUBWEAK ADC14_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1) 
ADC14_IRQHandler
        B ADC14_IRQHandler

        PUBWEAK ADC15_IRQHandler
        SECTION .text:CODE:REORDER:NOROOT(1) 
ADC15_IRQHandler
        B ADC15_IRQHandler


        END

/******************* (C) COPYRIGHT 2017 SPINTROL LIMITED CO. *****END OF FILE****/
