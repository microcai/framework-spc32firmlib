/**
  *****************************************************************************
  * @file    Libraries/Device/EG32M0xx/startup/arm/eg32m0xx_startup.c
  * @author  EGMICRO Application Team
  * @version V1.0.0
  * @date    02_02_2023
  * @brief   CMSIS Cortex-M0 Core Peripheral Access Layer Source File for 
  *          EGMICRO EG32M0xx MCU
  ****************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2023 EGMICRO</center></h2>
  *
  *
  *
  ******************************************************************************
  */ 
#include <stdint.h>
#include "system_spc1068.h"

/* Macro Definitions */
#if defined(__CC_ARM)                /* KEIL Compiler */
#define WEAK            __attribute__ ((weak))
#define ALIAS(f)        __attribute__ ((weak, alias(#f)))
#define WEAK_ALIAS_FUNC(FUN, FUN_ALIAS) \
    void FUN(void) __attribute__ ((weak, alias(#FUN_ALIAS)));

#elif defined(__GNUC__)              /* GCC Compiler */
#define WEAK            __attribute__ ((weak))
#define ALIAS(f)        __attribute__ ((weak, alias(#f)))
#define WEAK_ALIAS_FUNC(FUN, FUN_ALIAS) \
    void FUN(void) __attribute__ ((weak, alias(#FUN_ALIAS)));

#elif defined (__ICCARM__)           /* IAR Compiler */
#define WEAK_ALIAS_FUNC(FUN, FUN_ALIAS) \
void FUN(void);                         \
_Pragma(_STRINGIFY(_WEAK_ALIAS_FUNC(FUN, FUN_ALIAS)))
#define _WEAK_ALIAS_FUNC(FUN, FUN_ALIAS) weak __WEAK_ALIAS_FUNC(FUN, FUN_ALIAS)
#define __WEAK_ALIAS_FUNC(FUN, FUN_ALIAS) FUN##=##FUN_ALIAS
#endif

/* Initialize segments */
#if defined(__CC_ARM)                /* KEIL Compiler */
extern uint32_t Image$$ARM_LIB_STACK$$ZI$$Limit;
extern void __main(void);

#elif defined(__GNUC__)              /* GCC Compiler */
extern uint32_t __StackTop;
extern uint32_t __etext;
extern uint32_t __data_start__;
extern uint32_t __data_end__;
extern uint32_t __bss_start__;
extern uint32_t __bss_end__;
extern uint32_t __bss_extern_start__  WEAK;
extern uint32_t __bss_extern_end__ WEAK;

extern void uvisor_init(void);
extern void software_init_hook(void) __attribute__((weak));
extern void __libc_init_array(void);
extern int main(void);

#elif defined (__ICCARM__)           /* IAR Compiler */
void __iar_program_start(void);

#endif
void HardFault_Handler(void);
void MemManage_Handler(void);
void BusFault_Handler(void);
void DebugMon_Handler(void);
void UsageFault_Handler(void);
/* Default empty handler */
void Default_Handler(void);

void NMI_Handler(void);

/* Reset handler */
void Reset_Handler(void);

/* Cortex-M0 core handlers */
WEAK_ALIAS_FUNC(NMI_Handler,                                                Default_Handler)
WEAK_ALIAS_FUNC(HardFault_Handler,                                          Default_Handler)
WEAK_ALIAS_FUNC(MemManage_Handler,                                          Default_Handler)
WEAK_ALIAS_FUNC(BusFault_Handler,                                          Default_Handler)
WEAK_ALIAS_FUNC(UsageFault_Handler,                                          Default_Handler)
WEAK_ALIAS_FUNC(DebugMon_Handler,                                           Default_Handler)
WEAK_ALIAS_FUNC(SVC_Handler,                                                Default_Handler)
WEAK_ALIAS_FUNC(PendSV_Handler,                                             Default_Handler)
WEAK_ALIAS_FUNC(SysTick_Handler,                                            Default_Handler)

/* Peripherals handlers */
WEAK_ALIAS_FUNC(UART_IRQHandler,                                            Default_Handler)
WEAK_ALIAS_FUNC(I2C_IRQHandler,                                             Default_Handler)
WEAK_ALIAS_FUNC(SSP_IRQHandler,                                             Default_Handler)
WEAK_ALIAS_FUNC(GPIOEdge_IRQHandler,                                        Default_Handler)
WEAK_ALIAS_FUNC(QSPI_IRQHandler,                                            Default_Handler)
WEAK_ALIAS_FUNC(ECAP_IRQHandler,                                            Default_Handler)
WEAK_ALIAS_FUNC(ADC0_IRQHandler,                                            Default_Handler)
WEAK_ALIAS_FUNC(PWM0_IRQHandler,                                            Default_Handler)
WEAK_ALIAS_FUNC(PWM0TZ_IRQHandler,                                          Default_Handler)
WEAK_ALIAS_FUNC(TIM0_IRQHandler,                                            Default_Handler)
WEAK_ALIAS_FUNC(TIM1_IRQHandler,                                            Default_Handler)
WEAK_ALIAS_FUNC(TIM2_IRQHandler,                                            Default_Handler)
WEAK_ALIAS_FUNC(WDT1_IRQHandler,                                            Default_Handler)
WEAK_ALIAS_FUNC(ADC1_IRQHandler,                                            Default_Handler)
WEAK_ALIAS_FUNC(ADC2_IRQHandler,                                            Default_Handler)
WEAK_ALIAS_FUNC(ADC3_IRQHandler,                                            Default_Handler)
WEAK_ALIAS_FUNC(ADC4_IRQHandler,                                            Default_Handler)
WEAK_ALIAS_FUNC(ADC5_IRQHandler,                                            Default_Handler)
WEAK_ALIAS_FUNC(ADC6_IRQHandler,                                            Default_Handler)
WEAK_ALIAS_FUNC(ADC7_IRQHandler,                                            Default_Handler)
WEAK_ALIAS_FUNC(ADC8_IRQHandler,                                            Default_Handler)
WEAK_ALIAS_FUNC(PWM1_IRQHandler,                                            Default_Handler)
WEAK_ALIAS_FUNC(PWM1TZ_IRQHandler,                                          Default_Handler)
WEAK_ALIAS_FUNC(PWM2_IRQHandler,                                            Default_Handler)
WEAK_ALIAS_FUNC(PWM2TZ_IRQHandler,                                          Default_Handler)
WEAK_ALIAS_FUNC(PWM3_IRQHandler,                                            Default_Handler)
WEAK_ALIAS_FUNC(PWM3TZ_IRQHandler,                                          Default_Handler)
WEAK_ALIAS_FUNC(PWM4_IRQHandler,                                            Default_Handler)
WEAK_ALIAS_FUNC(PWM4TZ_IRQHandler,                                          Default_Handler)
WEAK_ALIAS_FUNC(PWM5_IRQHandler,                                            Default_Handler)
WEAK_ALIAS_FUNC(PWM5TZ_IRQHandler,                                          Default_Handler)
WEAK_ALIAS_FUNC(PWM6_IRQHandler,                                            Default_Handler)
WEAK_ALIAS_FUNC(PWM6TZ_IRQHandler,                                          Default_Handler)
WEAK_ALIAS_FUNC(MemParity_IRQHandler,                                       Default_Handler)
WEAK_ALIAS_FUNC(AES_IRQHandler,                                             Default_Handler)
WEAK_ALIAS_FUNC(CRC_IRQHandler,                                             Default_Handler)
WEAK_ALIAS_FUNC(GPIOLevel_IRQHandler,                                       Default_Handler)
WEAK_ALIAS_FUNC(CLOCK_IRQHandler,                                           Default_Handler)
WEAK_ALIAS_FUNC(BOD_IRQHandler,                                             Default_Handler)
WEAK_ALIAS_FUNC(ADC9_IRQHandler,                                            Default_Handler)
WEAK_ALIAS_FUNC(ADC10_IRQHandler,                                           Default_Handler)
WEAK_ALIAS_FUNC(ADC11_IRQHandler,                                           Default_Handler)
WEAK_ALIAS_FUNC(ADC12_IRQHandler,                                           Default_Handler)
WEAK_ALIAS_FUNC(ADC13_IRQHandler,                                           Default_Handler)
WEAK_ALIAS_FUNC(ADC14_IRQHandler,                                           Default_Handler)
WEAK_ALIAS_FUNC(ADC15_IRQHandler,                                           Default_Handler)


typedef void (*FUNC_IRQ)(void);

/* Vector table */
#if defined(__CC_ARM)           /* KEIL Compiler */
__attribute__((section("RESET")))
const FUNC_IRQ __vector_handlers[] = {
#elif defined(__GNUC__)         /* GCC Compiler */
__attribute__((section(".intvec")))
const FUNC_IRQ __vector_handlers[] = {
#elif defined (__ICCARM__)      /* IAR Compiler */
extern uint32_t CSTACK$$Limit;
const FUNC_IRQ __vector_table[] @ ".intvec" = {
#endif

#if defined(__CC_ARM)           /* KEIL Compiler */
    (FUNC_IRQ)&Image$$ARM_LIB_STACK$$ZI$$Limit,
#elif defined(__GNUC__)         /* GCC Compiler */
    (FUNC_IRQ)&__StackTop,
#elif defined(__ICCARM__)       /* IAR Compiler */
    (FUNC_IRQ)&CSTACK$$Limit,
#endif

    Reset_Handler,              // Reset Handler
    NMI_Handler,                // NMI Handler
    HardFault_Handler,          // Hard Fault Handler
    MemManage_Handler,          // MPU Fault Handler
    BusFault_Handler,           // Bus Fault Handler
    UsageFault_Handler,         // Usage Fault Handler
    0,                          // Reserved
    0,                          // Reserved
    0,                          // Reserved
    0,                          // Reserved
    SVC_Handler,                // SVCall Handler
    DebugMon_Handler,                          // Reserved
    0,                          // Reserved
    PendSV_Handler,             // PendSV Handler
    SysTick_Handler,            // SysTick Handler

    /* External Interrupts */

    UART_IRQHandler,            //  0 UART
    I2C_IRQHandler,             //  1 I2C
    SSP_IRQHandler,             //  2 SSP
    GPIOEdge_IRQHandler,        //  3 GPIO Edge
    QSPI_IRQHandler,            //  4 QSPI
    ECAP_IRQHandler,            //  5 eCAP
    ADC0_IRQHandler,            //  6 ADC SOC0
    PWM0_IRQHandler,            //  7 PWM0
    PWM0TZ_IRQHandler,          //  8 PWM0 Trip-zone
    TIM0_IRQHandler,            //  9 Timer0
    TIM1_IRQHandler,            // 10 Timer1
    TIM2_IRQHandler,            // 11 Timer2
    WDT1_IRQHandler,            // 12 Watchdog Timer1
    ADC1_IRQHandler,            // 13 ADC SOC1
    ADC2_IRQHandler,            // 14 ADC SOC2
    ADC3_IRQHandler,            // 15 ADC SOC3
    ADC4_IRQHandler,            // 16 ADC SOC4
    ADC5_IRQHandler,            // 17 ADC SOC5
    ADC6_IRQHandler,            // 18 ADC SOC6
    ADC7_IRQHandler,            // 19 ADC SOC7
    ADC8_IRQHandler,            // 20 ADC SOC8
    PWM1_IRQHandler,            // 21 PWM1
    PWM1TZ_IRQHandler,          // 22 PWM1 Trip-Zone
    PWM2_IRQHandler,            // 23 PWM2
    PWM2TZ_IRQHandler,          // 24 PWM2 Trip-Zone
    PWM3_IRQHandler,            // 25 PWM3
    PWM3TZ_IRQHandler,          // 26 PWM3 Trip-Zone
    PWM4_IRQHandler,            // 27 PWM4
    PWM4TZ_IRQHandler,          // 28 PWM4 Trip-Zone
    PWM5_IRQHandler,            // 29 PWM5
    PWM5TZ_IRQHandler,          // 30 PWM5 Trip-Zone
    PWM6_IRQHandler,            // 31 PWM6
    PWM6TZ_IRQHandler,          // 32 PWM6 Trip-Zone
    MemParity_IRQHandler,       // 33 Memory parity check
    AES_IRQHandler,             // 34 AES
    CRC_IRQHandler,             // 35 CRC
    GPIOLevel_IRQHandler,       // 36 GPIO Level
    CLOCK_IRQHandler,           // 37 Clock
    BOD_IRQHandler,             // 38 BOD
    ADC9_IRQHandler,            // 39 ADC SOC9
    ADC10_IRQHandler,           // 40 ADC SOC10
    ADC11_IRQHandler,           // 41 ADC SOC11
    ADC12_IRQHandler,           // 42 ADC SOC12
    ADC13_IRQHandler,           // 43 ADC SOC13
    ADC14_IRQHandler,           // 44 ADC SOC14
    ADC15_IRQHandler,           // 45 ADC SOC15
    0,
    0
};

extern void SystemInit(void);
extern int main(void);
void Reset_Handler(void)
{
    SystemInit();

#if defined(__CC_ARM)           /* KEIL Compiler */
   __main();
#elif defined(__ICCARM__)       /* GCC Compiler */
    __iar_program_start();
#elif defined(__GNUC__)         /* IAR Compiler */
    uint32_t *src_ind = (uint32_t *) &__etext;
    uint32_t *dst_ind = (uint32_t *) &__data_start__;
    uint32_t *dst_end = (uint32_t *) &__data_end__;

    /* Move .data section from ROM to RAM */
    if(src_ind != dst_ind) {
        for(; dst_ind < dst_end;) {
            *dst_ind ++ = *src_ind ++;
        }
    }

    /* Initialize .bss section to zero */
    dst_ind = (uint32_t *) &__bss_start__;
    dst_end = (uint32_t *) &__bss_end__;
    if(dst_ind != dst_end) {
        for(; dst_ind < dst_end;) {
            *dst_ind ++ = 0;
        }
    }

    /* Initialize .bss.extern section to zero */
    dst_ind = (uint32_t *) &__bss_extern_start__;
    dst_end = (uint32_t *) &__bss_extern_end__;
    if(dst_ind != dst_end) {
        for(; dst_ind < dst_end;) {
            *dst_ind ++ = 0;
        }
    }

    /* uvisor_init();  */

    if(software_init_hook) {
        /**
         * Give control to the RTOS via software_init_hook() which will also call __libc_init_array().
         * Assume software_init_hook() is defined in libraries/rtos/rtx/TARGET_CORTEX_M/RTX_CM_lib.h.
         */
        software_init_hook();
    } else {
        __libc_init_array();
        main();
    }
#endif
    /* Infinite loop */
    while(1);
}


void Default_Handler(void)
{
    while(1);
}

/*************************** (C) COPYRIGHT 2023 EGMICRO ***** END OF FILE *****/
