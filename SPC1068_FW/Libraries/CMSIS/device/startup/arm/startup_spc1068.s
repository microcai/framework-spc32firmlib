;/**************************************************************************//**
; * @file     startup_ARMCM3.s
; * @brief    CMSIS Core Device Startup File for
; *           ARMCM3 Device Series
; * @version  V1.08
; * @date     23. November 2012
; *
; * @note
; *
; ******************************************************************************/
;/* Copyright (c) 2011 - 2012 ARM LIMITED
;
;   All rights reserved.
;   Redistribution and use in source and binary forms, with or without
;   modification, are permitted provided that the following conditions are met:
;   - Redistributions of source code must retain the above copyright
;     notice, this list of conditions and the following disclaimer.
;   - Redistributions in binary form must reproduce the above copyright
;     notice, this list of conditions and the following disclaimer in the
;     documentation and/or other materials provided with the distribution.
;   - Neither the name of ARM nor the names of its contributors may be used
;     to endorse or promote products derived from this software without
;     specific prior written permission.
;   *
;   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
;   AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
;   IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
;   ARE DISCLAIMED. IN NO EVENT SHALL COPYRIGHT HOLDERS AND CONTRIBUTORS BE
;   LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
;   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
;   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
;   INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
;   CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
;   ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
;   POSSIBILITY OF SUCH DAMAGE.
;   ---------------------------------------------------------------------------*/
;/*
;//-------- <<< Use Configuration Wizard in Context Menu >>> ------------------
;*/


; <h> Stack Configuration
;   <o> Stack Size (in Bytes) <0x0-0xFFFFFFFF:8>
; </h>

Stack_Size      EQU     0x00000400

                AREA    STACK, NOINIT, READWRITE, ALIGN=3
Stack_Mem       SPACE   Stack_Size
__initial_sp


; <h> Heap Configuration
;   <o>  Heap Size (in Bytes) <0x0-0xFFFFFFFF:8>
; </h>

Heap_Size       EQU     0x00000400

                AREA    HEAP, NOINIT, READWRITE, ALIGN=3
__heap_base
Heap_Mem        SPACE   Heap_Size
__heap_limit


                PRESERVE8
                THUMB


; Vector Table Mapped to Address 0 at Reset

                AREA    RESET, DATA, READONLY
                EXPORT  __Vectors
                EXPORT  __Vectors_End
                EXPORT  __Vectors_Size

__Vectors       DCD     __initial_sp              ;-16 Top of Stack
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
__Vectors_End

__Vectors_Size  EQU     __Vectors_End - __Vectors

                AREA    |.text|, CODE, READONLY


; Reset Handler

Reset_Handler   PROC
                EXPORT  Reset_Handler             [WEAK]
                IMPORT  SystemInit
                IMPORT  __main
                
                ;* C routines are likely to be called. Setup the stack now
                LDR     SP,=__initial_sp
                
                LDR     R0, =SystemInit
                BLX     R0
                
                ;* Reset stack pointer before zipping off to user application
                LDR     SP,=__initial_sp
                
                LDR     R0, =__main
                BX      R0
                ENDP


; Dummy Exception Handlers (infinite loops which can be modified)

NMI_Handler     PROC
                EXPORT  NMI_Handler               [WEAK]
                B       .
                ENDP
HardFault_Handler\
                PROC
                EXPORT  HardFault_Handler         [WEAK]
                B       .
                ENDP
MemManage_Handler\
                PROC
                EXPORT  MemManage_Handler         [WEAK]
                B       .
                ENDP
BusFault_Handler\
                PROC
                EXPORT  BusFault_Handler          [WEAK]
                B       .
                ENDP
UsageFault_Handler\
                PROC
                EXPORT  UsageFault_Handler        [WEAK]
                B       .
                ENDP
SVC_Handler     PROC
                EXPORT  SVC_Handler               [WEAK]
                B       .
                ENDP
DebugMon_Handler\
                PROC
                EXPORT  DebugMon_Handler          [WEAK]
                B       .
                ENDP
PendSV_Handler  PROC
                EXPORT  PendSV_Handler            [WEAK]
                B       .
                ENDP
SysTick_Handler PROC
                EXPORT  SysTick_Handler           [WEAK]
                B       .
                ENDP

Default_Handler PROC

                EXPORT  UART_IRQHandler           [WEAK]
                EXPORT  I2C_IRQHandler            [WEAK]
                EXPORT  SSP_IRQHandler            [WEAK]
                EXPORT  GPIOEdge_IRQHandler       [WEAK]
                EXPORT  QSPI_IRQHandler           [WEAK]
                EXPORT  ECAP_IRQHandler           [WEAK]
                EXPORT  ADC0_IRQHandler           [WEAK]
                EXPORT  PWM0_IRQHandler           [WEAK]
                EXPORT  PWM0TZ_IRQHandler         [WEAK]
                EXPORT  TIM0_IRQHandler           [WEAK]
                EXPORT  TIM1_IRQHandler           [WEAK]
                EXPORT  TIM2_IRQHandler           [WEAK]
                EXPORT  WDT1_IRQHandler           [WEAK]
                EXPORT  ADC1_IRQHandler           [WEAK]
                EXPORT  ADC2_IRQHandler           [WEAK]
                EXPORT  ADC3_IRQHandler           [WEAK]
                EXPORT  ADC4_IRQHandler           [WEAK]
                EXPORT  ADC5_IRQHandler           [WEAK]
                EXPORT  ADC6_IRQHandler           [WEAK]
                EXPORT  ADC7_IRQHandler           [WEAK]
                EXPORT  ADC8_IRQHandler           [WEAK]
                EXPORT  PWM1_IRQHandler           [WEAK]
                EXPORT  PWM1TZ_IRQHandler         [WEAK]
                EXPORT  PWM2_IRQHandler           [WEAK]
                EXPORT  PWM2TZ_IRQHandler         [WEAK]
                EXPORT  PWM3_IRQHandler           [WEAK]
                EXPORT  PWM3TZ_IRQHandler         [WEAK]
                EXPORT  PWM4_IRQHandler           [WEAK]
                EXPORT  PWM4TZ_IRQHandler         [WEAK]
                EXPORT  PWM5_IRQHandler           [WEAK]
                EXPORT  PWM5TZ_IRQHandler         [WEAK]
                EXPORT  PWM6_IRQHandler           [WEAK]
                EXPORT  PWM6TZ_IRQHandler         [WEAK]
                EXPORT  MemParity_IRQHandler      [WEAK]
                EXPORT  AES_IRQHandler            [WEAK]
                EXPORT  CRC_IRQHandler            [WEAK]
                EXPORT  GPIOLevel_IRQHandler      [WEAK]
                EXPORT  CLOCK_IRQHandler          [WEAK]
                EXPORT  BOD_IRQHandler            [WEAK]
                EXPORT  ADC9_IRQHandler           [WEAK]
                EXPORT  ADC10_IRQHandler          [WEAK]
                EXPORT  ADC11_IRQHandler          [WEAK]
                EXPORT  ADC12_IRQHandler          [WEAK]
                EXPORT  ADC13_IRQHandler          [WEAK]
                EXPORT  ADC14_IRQHandler          [WEAK]
                EXPORT  ADC15_IRQHandler          [WEAK]

UART_IRQHandler
I2C_IRQHandler
SSP_IRQHandler
GPIOEdge_IRQHandler
QSPI_IRQHandler
ECAP_IRQHandler
ADC0_IRQHandler
PWM0_IRQHandler
PWM0TZ_IRQHandler
TIM0_IRQHandler
TIM1_IRQHandler
TIM2_IRQHandler
WDT1_IRQHandler
ADC1_IRQHandler
ADC2_IRQHandler
ADC3_IRQHandler
ADC4_IRQHandler
ADC5_IRQHandler
ADC6_IRQHandler
ADC7_IRQHandler
ADC8_IRQHandler
PWM1_IRQHandler
PWM1TZ_IRQHandler
PWM2_IRQHandler
PWM2TZ_IRQHandler
PWM3_IRQHandler
PWM3TZ_IRQHandler
PWM4_IRQHandler
PWM4TZ_IRQHandler
PWM5_IRQHandler
PWM5TZ_IRQHandler
PWM6_IRQHandler
PWM6TZ_IRQHandler
MemParity_IRQHandler
AES_IRQHandler
CRC_IRQHandler
GPIOLevel_IRQHandler
CLOCK_IRQHandler
BOD_IRQHandler
ADC9_IRQHandler
ADC10_IRQHandler
ADC11_IRQHandler
ADC12_IRQHandler
ADC13_IRQHandler
ADC14_IRQHandler
ADC15_IRQHandler
                B       .

                ENDP


                ALIGN


; User Initial Stack & Heap

                IF      :DEF:__MICROLIB

                EXPORT  __initial_sp
                EXPORT  __heap_base
                EXPORT  __heap_limit

                ELSE

                IMPORT  __use_two_region_memory
                EXPORT  __user_initial_stackheap

__user_initial_stackheap PROC
                LDR     R0, =  Heap_Mem
                LDR     R1, =(Stack_Mem + Stack_Size)
                LDR     R2, = (Heap_Mem +  Heap_Size)
                LDR     R3, = Stack_Mem
                BX      LR
                ENDP

                ALIGN

                ENDIF


                END
