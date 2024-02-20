/**************************************************************************//**
 * @file     pwm.h
 * @brief    PWM driver module header file.
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


#ifndef PWM_H
#define PWM_H

#ifdef __cplusplus
extern "C" {
#endif


#include "spc1068.h"




/**
 *  @brief  PWM channel A or B select type
 */
typedef enum
{
  PWM_CHA               = 0,                /*!< PWM Channel A define     */
  PWM_CHB               = 1                 /*!< PWM Channel B define     */
} PWM_ChannelEnum;




/**
 *  @brief  PWM event period
 */
typedef enum
{
  NO_EVENT              = ETPS_BIT_SOCAPRD_GEN_SOCA_DISABLE,        /*!< Disable event counter. No event pulse will be generated */
  ON_1ST_EVENT          = ETPS_BIT_SOCAPRD_GEN_SOCA_ON_1ST_EVENT,   /*!< Generate pulse when first event      */
  ON_2ND_EVENT          = ETPS_BIT_SOCAPRD_GEN_SOCA_ON_2ND_EVENT,   /*!< Generate pulse when second event     */
  ON_3RD_EVENT          = ETPS_BIT_SOCAPRD_GEN_SOCA_ON_3RD_EVENT    /*!< Generate pulse when third event      */
} PWM_EventPeriodEnum;




/**
 *  @brief  PWM event (SOC or INT) timing configuration
 */
typedef enum
{
  EQU_ZERO                = ETSEL_BIT_SOCASEL_TBCNT_EQU_ZERO,         /*!< event TBCNT=0                                 */
  EQU_PERIOD              = ETSEL_BIT_SOCASEL_TBCNT_EQU_PERIOD,       /*!< event TBCNT=TBPRD                             */
  EQU_ZERO_PERIOD         = ETSEL_BIT_SOCASEL_TBCNT_EQU_ZERO_PERIOD,  /*!< event TBCNT=0 or TBCNT=TBPRD                  */
  EQU_CMPA_UP_COUNTING    = ETSEL_BIT_SOCASEL_CMPA_UP_COUNTING ,      /*!< event TBCNT=CMPA when counter is incrementing */
  EQU_CMPA_DOWN_COUNTING  = ETSEL_BIT_SOCASEL_CMPA_DOWN_COUNTING,     /*!< event TBCNT=CMPA when counter is decrementing */
  EQU_CMPB_UP_COUNTING    = ETSEL_BIT_SOCASEL_CMPB_UP_COUNTING,       /*!< event TBCNT=CMPB when counter is incrementing */
  EQU_CMPB_DOWN_COUNTING  = ETSEL_BIT_SOCASEL_CMPB_DOWN_COUNTING      /*!< event TBCNT=CMPB when counter is decrementing */
} PWM_EventTimingEnum;




/**
 *  @brief  PWM output A and B reaction after trip event occurs
 */
typedef enum
{
  TRIP_AT_TRI_STATE     = TZCTL_BIT_TZA_TRI_STATE,          /*!< Set output A/B to high-impedance */
  TRIP_AT_HIGH          = TZCTL_BIT_TZA_SET_HIGH,           /*!< Force output A/B to high state   */
  TRIP_AT_LOW           = TZCTL_BIT_TZA_SET_LOW,            /*!< Force output A/B to low state    */
  TRIP_DO_NOTHING       = TZCTL_BIT_TZA_DO_NOTHING          /*!< Do nothing for output A/B        */
} PWM_PWMOutputTripEnum;




/**
 *  @brief  PWM waveform configuration after time event
 */
typedef enum
{
  CBD_DO_NOTHING        = AQCTLA_ALL_CBD_DO_NOTHING,
  CBD_SET_LOW           = AQCTLA_ALL_CBD_SET_LOW, 
  CBD_SET_HIGH          = AQCTLA_ALL_CBD_SET_HIGH,
  CBD_TOGGLE            = AQCTLA_ALL_CBD_TOGGLE,
  
  CBU_DO_NOTHING        = AQCTLA_ALL_CBU_DO_NOTHING,
  CBU_SET_LOW           = AQCTLA_ALL_CBU_SET_LOW, 
  CBU_SET_HIGH          = AQCTLA_ALL_CBU_SET_HIGH,
  CBU_TOGGLE            = AQCTLA_ALL_CBU_TOGGLE,
  
  CAD_DO_NOTHING        = AQCTLA_ALL_CAD_DO_NOTHING,
  CAD_SET_LOW           = AQCTLA_ALL_CAD_SET_LOW, 
  CAD_SET_HIGH          = AQCTLA_ALL_CAD_SET_HIGH,
  CAD_TOGGLE            = AQCTLA_ALL_CAD_TOGGLE,
  
  CAU_DO_NOTHING        = AQCTLA_ALL_CAU_DO_NOTHING,
  CAU_SET_LOW           = AQCTLA_ALL_CAU_SET_LOW, 
  CAU_SET_HIGH          = AQCTLA_ALL_CAU_SET_HIGH,
  CAU_TOGGLE            = AQCTLA_ALL_CAU_TOGGLE,
  
  PRD_DO_NOTHING        = AQCTLA_ALL_PRD_DO_NOTHING,
  PRD_SET_LOW           = AQCTLA_ALL_PRD_SET_LOW, 
  PRD_SET_HIGH          = AQCTLA_ALL_PRD_SET_HIGH,
  PRD_TOGGLE            = AQCTLA_ALL_PRD_TOGGLE,
  
  ZRO_DO_NOTHING        = AQCTLA_ALL_ZRO_DO_NOTHING,
  ZRO_SET_LOW           = AQCTLA_ALL_ZRO_SET_LOW,
  ZRO_SET_HIGH          = AQCTLA_ALL_ZRO_SET_HIGH,
  ZRO_TOGGLE            = AQCTLA_ALL_ZRO_TOGGLE
} PWM_ActionQualifierEnum;




/**
 *  @brief  PWM Comparator A and B reload timing selection
 */
typedef enum
{
  ON_ZERO               = CMPCTL_BIT_LOADAMODE_LOAD_ON_ZERO,          /*!< Load on TBCNT=Zero                           */
  ON_PERIOD             = CMPCTL_BIT_LOADAMODE_LOAD_ON_PERIOD,        /*!< Load on TBCNT=TBPRD                          */
  ON_ZERO_PERIOD        = CMPCTL_BIT_LOADAMODE_LOAD_ON_ZERO_PERIOD,   /*!< Load on either TBCNT=Zero or TBCNT=TBPRD     */
  NO_LOAD               = CMPCTL_BIT_LOADAMODE_FREEZE                 /*!< Freeze CMPA active value (No loads possible) */
} PWM_CMPxLoadTimingEnum;




/**
 *  @brief  PWM clock count mode selection
 */
typedef enum
{
  COUNT_UP_AND_RUN      = TBCTL_BIT_CNTMODE_COUNT_UP_AND_RUN,         /*!< Up-count                           */
  COUNT_DOWN_AND_RUN    = TBCTL_BIT_CNTMODE_COUNT_DOWN_AND_RUN,       /*!< Down-count                         */
  COUNT_UP_DOWN_AND_RUN = TBCTL_BIT_CNTMODE_COUNT_UP_DOWN_AND_RUN,    /*!< Up-down-count                      */
  COUNT_STOP            = TBCTL_BIT_CNTMODE_COUNT_STOP                /*!< Stop and freeze (default on reset) */
} PWM_CounterRunControlEnum;




/**
 *  @brief  PWM clock divider selection
 */
typedef enum
{
  PWM_CLKDIV_1          = TBCTL_BIT_TBCLKDIV_1,             /*!< /1 (default on reset) */
  PWM_CLKDIV_2          = TBCTL_BIT_TBCLKDIV_2,             /*!< /2                    */
  PWM_CLKDIV_4          = TBCTL_BIT_TBCLKDIV_4,             /*!< /4                    */
  PWM_CLKDIV_8          = TBCTL_BIT_TBCLKDIV_8,             /*!< /8                    */
  PWM_CLKDIV_16         = TBCTL_BIT_TBCLKDIV_16,            /*!< /16                   */
  PWM_CLKDIV_32         = TBCTL_BIT_TBCLKDIV_32,            /*!< /32                   */
  PWM_CLKDIV_64         = TBCTL_BIT_TBCLKDIV_64,            /*!< /64                   */
  PWM_CLKDIV_128        = TBCTL_BIT_TBCLKDIV_128            /*!< /128                  */
} PWM_ClockDivEnum;




/****************************************************************************//**
 * @brief      Get current PWM counter value
 *
 * @param[in]  PWMx:  Select the PWM module (PWM0~PWM6)
 *
 * @return     PWM current counter (16 bit)
 *
 *******************************************************************************/
#define PWM_GetCounterValue(PWMx)           ((PWMx)->TBCNT.all)




/****************************************************************************//**
 * @brief      Get PWM period value
 *
 * @param[in]  PWMx:  Select the PWM module (PWM0~PWM6)
 *
 * @return     PWM period (16 bit)
 *
 *******************************************************************************/
#define PWM_GetPeriodValue(PWMx)            ((PWMx)->TBPRD.all)




/****************************************************************************//**
 * @brief      Set PWM period value
 *
 * @param[in]  PWMx  :  Select the PWM module (PWM0~PWM6)
 * @param[in]  u16Val:  PWM reload counter (16 bit)
 *
 * @return     none
 *
 * @detail     PWM carrier frequency will be decided by period value
 *             If PWM is up counting or down counting,
 *                PWM frequency = PWM clock/Period
 *             if PWM is up counting and down counting,
 *                PWM frequency = PWM clock/Period/2
 *             Thus user may design PWM frequency by Period and PWM clock frequency
 *
 *******************************************************************************/
#define PWM_SetPeriodValue(PWMx,u16Val)     ((PWMx)->TBPRD.all = (u16Val))




/****************************************************************************//**
 * @brief      Set PWM synchronization reload value
 *             PWM counter will equal TBPHS after synchronization event
 *
 * @param[in]  PWMx  :  Select the PWM module (PWM0~PWM6)
 * @param[in]  u16Val:  PWM reload value
 *
 * @return     none
 *
 *******************************************************************************/
#define PWM_SetSyncReloadValue(PWMx,u16Val) ((PWMx)->TBPHS.all = (u16Val))




/****************************************************************************//**
 * @brief      PWM counter will not increase when in MCU debug mode
 *             Note: Please remember to configure CBC trip zone when debug
 *
 * @param[in]  PWMx:  Select the PWM module (PWM0~PWM6)
 *
 * @return     none
 *
 *******************************************************************************/
#define PWM_StopCounterInDebug(PWMx)        ((PWMx)->TBCTL.bit.DBGRUN  = TBCTL_BIT_DBGRUN_STOP_AFTER_CYCLE)




/****************************************************************************//**
 * @brief      Configure PWMx clock divider sacle
 *
 * @param[in]  PWMx:  Select the PWM module (PWM0~PWM6)
 * @param[in]  eDiv:  Specifies the divider
 *                    Please goto PWM_ClockDivEnum for selection
 *                     - \ref PWM_CLKDIV_1
 *                     - \ref PWM_CLKDIV_2
 *                     - \ref PWM_CLKDIV_4
 *                     - \ref PWM_CLKDIV_8
 *                     - \ref PWM_CLKDIV_16
 *                     - \ref PWM_CLKDIV_32
 *                     - \ref PWM_CLKDIV_64
 *                     - \ref PWM_CLKDIV_128
 *
 * @return     none
 *
 * @example    PWM_SetClockDiv(PWM_CLKDIV_1);
 *             PWM_SetClockDiv(PWM_CLKDIV_8);
 * 
 *******************************************************************************/
#define PWM_SetClockDiv(PWMx,eDiv)          ((PWMx)->TBCTL.bit.TBCLKDIV = (eDiv))




/****************************************************************************//**
 * @brief      Get PWM clock divider value
 *
 * @param[in]  PWMx:  Select the PWM module (PWM0~PWM6)
 *
 * @return     PWM_ClockDivEnum
 *
 *******************************************************************************/
#define PWM_GetClockDiv(PWMx)               ((PWMx)->TBCTL.bit.TBCLKDIV)




/****************************************************************************//**
 * @brief      Configure PWMx clock counting mode (4 modes include stop)
 *
 * @param[in]  PWMx :  Select the PWM module (PWM0~PWM6)
 * @param[in]  eMode:  Specifies the clock counting mode
 *                     Please goto PWM_CounterRunControlEnum for selection
 *                      - \ref COUNT_UP_AND_RUN
 *                      - \ref COUNT_DOWN_AND_RUN
 *                      - \ref COUNT_UP_DOWN_AND_RUN
 *                      - \ref COUNT_STOP
 *
 * @return     none
 *
 * @example    PWM_CounterRunControl(COUNT_UP_DOWN_AND_RUN);
 *             PWM_CounterRunControl(COUNT_STOP);
 * 
 *******************************************************************************/
#define PWM_CounterRunControl(PWMx,eMode)   ((PWMx)->TBCTL.bit.CNTMODE = (eMode))




/****************************************************************************//**
 * @brief      Get the counter direction of PWM counter
 *
 * @param[in]  PWMx:  Select the PWM module (PWM0~PWM6)
 *
 * @return     0: PWM counter is counting down
 *             1: PWM counter is counting up
 *
 *******************************************************************************/
#define PWM_GetCountingDirection(PWMx)      ((PWMx)->TBSTS.bit.CNTDIR)




/****************************************************************************//**
 * @brief      Check if PWM counter is counting up
 *
 * @param[in]  PWMx:  Select the PWM module (PWM0~PWM6)
 *
 * @return     0: PWM counter is counting down
 *             1: PWM counter is counting up
 *
 *******************************************************************************/
#define PWM_IsCountingUp(PWMx)              ((((PWMx)->TBSTS.all & TBSTS_ALL_CNTDIR_Msk)==TBSTS_ALL_CNTDIR_COUNTING_UP)?(1):(0))




/****************************************************************************//**
 * @brief      Check if PWM counter is counting down
 *
 * @param[in]  PWMx:  Select the PWM module (PWM0~PWM6)
 *
 * @return     0: PWM counter is counting up
 *             1: PWM counter is counting down
 *
 *******************************************************************************/
#define PWM_IsCountingDown(PWMx)            ((((PWMx)->TBSTS.all & TBSTS_ALL_CNTDIR_Msk)==TBSTS_ALL_CNTDIR_COUNTING_DOWN)?(1):(0))




/****************************************************************************//**
 * @brief      Set PWMx CMPA value
 *
 * @param[in]  PWMx  :  Select the PWM module (PWM0~PWM6)
 * @param[in]  u16Val:  PWM comparator A value(16 bit)
 *                      It should be a value from 0~TBPRD
 *
 * @return     none
 *
 *******************************************************************************/
#define PWM_SetCMPA(PWMx,u16Val)            ((PWMx)->CMPA.all = (u16Val))




/****************************************************************************//**
 * @brief      Set PWMx CMPB value
 *
 * @param[in]  PWMx  :  Select the PWM module (PWM0~PWM6)
 * @param[in]  u16Val:  PWM comparator B value(16 bit)
 *                      It should be a value from 0~TBPRD
 *
 * @return     none
 *
 *******************************************************************************/
#define PWM_SetCMPB(PWMx,u16Val)            ((PWMx)->CMPB.all = (u16Val))




/****************************************************************************//**
 * @brief      Configure CMPA/CMPB reload timing
 *
 * @param[in]  PWMx :  Select the PWM module (PWM0~PWM6)
 * @param[in]  eMode:  Specifies the reload timing
 *                     Please goto PWM_CMPxLoadTimingEnum for selection
 *                      - \ref ON_ZERO
 *                      - \ref ON_PERIOD
 *                      - \ref ON_ZERO_PERIOD
 *                      - \ref NO_LOAD
 *
 * @return     none
 *
 * @example    PWM_SetCMPALoadTiming(ON_ZERO);
 *             PWM_SetCMPBLoadTiming(ON_ZERO_PERIOD);
 * 
 *******************************************************************************/
#define PWM_SetCMPALoadTiming(PWMx,eMode)   ((PWMx)->CMPCTL.bit.LOADAMODE = (eMode))
#define PWM_SetCMPBLoadTiming(PWMx,eMode)   ((PWMx)->CMPCTL.bit.LOADBMODE = (eMode))




/****************************************************************************//**
 * @brief      Enable PWMx advanced comparator mode
 *             Note: Spintrol suggest enable this function
 *
 * @param[in]  PWMx:  Select the PWM module (PWM0~PWM6)
 *
 * @return     none
 *
 * @details    Event CMPA/B=0 and CMPA/B=Period will occur when this mode enabled
 *
 *******************************************************************************/
#define PWM_EnableCMP_AdvanceMode(PWMx)     ((PWMx)->CMPCTL.all |= (CMPCTL_ALL_ADVCMPA_ADVANCED_MODE|CMPCTL_ALL_ADVCMPB_ADVANCED_MODE))




/****************************************************************************//**
 * @brief      Disable PWMx advanced comparator mode
 *             Note: Spintrol suggest enable this function
 *
 * @param[in]  PWMx:  Select the PWM module (PWM0~PWM6)
 *
 * @return     none
 *
 * @details    Event CMPA/B=0 and CMPA/B=Period will NOT occur when this mode enabled
 *
 *******************************************************************************/
#define PWM_DisableCMP_AdvanceMode(PWMx)    ((PWMx)->CMPCTL.all &= (~(CMPCTL_ALL_ADVCMPA_Msk|CMPCTL_ALL_ADVCMPB_Msk)))




/****************************************************************************//**
 * @brief      Configure PWMxA output waveform
 *
 * @param[in]  PWMx      :  Select the PWM module (PWM0~PWM6)
 * @param[in]  eActionSel:  Specifies the action after trip zone
 *                          Please goto PWM_ActionQualifierEnum for selection
 *                          PWM state after TBCNT = CMPB and TBCNT is down counting
 *                           - \ref CBD_DO_NOTHING
 *                           - \ref CBD_SET_LOW
 *                           - \ref CBD_SET_HIGH
 *                           - \ref CBD_TOGGLE
 *                          PWM state after TBCNT = CMPB and TBCNT is up counting
 *                           - \ref CBU_DO_NOTHING
 *                           - \ref CBU_SET_LOW
 *                           - \ref CBU_SET_HIGH
 *                           - \ref CBU_TOGGLE
 *                          PWM state after TBCNT = CMPA and TBCNT is down counting
 *                           - \ref CAD_DO_NOTHING
 *                           - \ref CAD_SET_LOW
 *                           - \ref CAD_SET_HIGH
 *                           - \ref CAD_TOGGLE
 *                          PWM state after TBCNT = CMPA and TBCNT is up counting
 *                           - \ref CAU_DO_NOTHING
 *                           - \ref CAU_SET_LOW
 *                           - \ref CAU_SET_HIGH
 *                           - \ref CAU_TOGGLE
 *                          PWM state after TBCNT = Period  
 *                           - \ref PRD_DO_NOTHING
 *                           - \ref PRD_SET_LOW
 *                           - \ref PRD_SET_HIGH
 *                           - \ref PRD_TOGGLE
 *                          PWM state after TBCNT = 0
 *                           - \ref ZRO_DO_NOTHING
 *                           - \ref ZRO_SET_LOW
 *                           - \ref ZRO_SET_HIGH
 *                           - \ref ZRO_TOGGLE
 *
 * @return     none
 *
 * @example    PWM_ActionQualifierCHA(CAU_SET_HIGH|CAD_SET_LOW|
 *                                    CBD_DO_NOTHING|CBU_DO_NOTHING|
 *                                    PRD_DO_NOTHING|ZRO_SET_LOW);
 *             Wrong Confiquration!!
 *             PWM_ActionQualifierCHA(CAU_SET_HIGH|CAU_SET_LOW|  -->Can NOT configure 2 reactions after same event
 *                                    CBD_DO_NOTHING|CBU_DO_NOTHING|
 *                                    PRD_DO_NOTHING|ZRO_SET_LOW);  
 * 
 *******************************************************************************/
#define PWM_ActionQualifierCHA(PWMx,eActionSel) ((PWMx)->AQCTLA.all = (eActionSel))
#define PWM_ActionQualifierCHB(PWMx,eActionSel) ((PWMx)->AQCTLB.all = (eActionSel))




/****************************************************************************//**
 * @brief      Continuous force PWMxA/B low
 *             Note: This forced state will be released if PWM_DisableForceCHA/B() is called
 *
 * @param[in]  PWMx:  Select the PWM module (PWM0~PWM6)
 *
 * @return     none
 *
 *******************************************************************************/
#define PWM_ForceCHALow(PWMx)               ((PWMx)->AQCSFRC.bit.CSFA=(AQCSFRC_BIT_CSFA_FORCE_CONTINUOUS_LOW))
#define PWM_ForceCHBLow(PWMx)               ((PWMx)->AQCSFRC.bit.CSFB=(AQCSFRC_BIT_CSFB_FORCE_CONTINUOUS_LOW))
#define PWM_ForceCHAandCHBLow(PWMx)         ((PWMx)->AQCSFRC.all = AQCSFRC_ALL_CSFA_FORCE_CONTINUOUS_LOW | AQCSFRC_ALL_CSFB_FORCE_CONTINUOUS_LOW)




/****************************************************************************//**
 * @brief      Continuous force PWMxA/B High
 *             Note: This forced state will be released until PWM_DisableForcePWMAOutput() is called
 *
 * @param[in]  PWMx:  Select the PWM module (PWM0~PWM6)
 *
 * @return     none
 *
 *******************************************************************************/
#define PWM_ForceCHAHigh(PWMx)              ((PWMx)->AQCSFRC.bit.CSFA = (AQCSFRC_BIT_CSFA_FORCE_CONTINUOUS_HIGH))
#define PWM_ForceCHBHigh(PWMx)              ((PWMx)->AQCSFRC.bit.CSFB = (AQCSFRC_BIT_CSFB_FORCE_CONTINUOUS_HIGH))
#define PWM_ForceCHAandCHBHigh(PWMx)        ((PWMx)->AQCSFRC.all = AQCSFRC_ALL_CSFA_FORCE_CONTINUOUS_HIGH | AQCSFRC_ALL_CSFB_FORCE_CONTINUOUS_HIGH)




/****************************************************************************//**
 * @brief      Disable/Release force PWMxA/B 
 *
 * @param[in]  PWMx:  Select the PWM module (PWM0~PWM6)
 *
 * @return     none
 *
 *******************************************************************************/
#define PWM_DisableForceCHA(PWMx)           ((PWMx)->AQCSFRC.bit.CSFA = (AQCSFRC_BIT_CSFA_NO_EFFECT))
#define PWM_DisableForceCHB(PWMx)           ((PWMx)->AQCSFRC.bit.CSFB = (AQCSFRC_BIT_CSFB_NO_EFFECT))
#define PWM_DisableForceCHAandCHB(PWMx)     ((PWMx)->AQCSFRC.all = AQCSFRC_ALL_CSFA_NO_EFFECT | AQCSFRC_ALL_CSFB_NO_EFFECT)




/****************************************************************************//**
 * @brief      PWM Dead band(time) waveform rising edge delay
 *
 * @param[in]  PWMx    :  Select the PWM module (PWM0~PWM6)
 * @param[in]  u32Delay:  unit is PWM module clock
 *
 * @return     none
 *
 *******************************************************************************/
#define PWM_DeadBandRisingDelay(PWMx,u32Delay)    ((PWMx)->DBRED.all=(u32Delay))




/****************************************************************************//**
 * @brief      PWM Dead band(time) waveform falling edge delay
 *
 * @param[in]  PWMx    :  Select the PWM module (PWM0~PWM6)
 * @param[in]  u32Delay:  unit is PWM module clock
 *
 * @return     none
 *
 *******************************************************************************/
#define PWM_DeadBandFallingDelay(PWMx,u32Delay)   ((PWMx)->DBFED.all=(u32Delay))




/****************************************************************************//**
 * @brief      Enable Debug mode as an CBC trip event
 *             PWM output will be triped to configured state when in Debug mode
 *             Example : 
 *             Please remember call PWM_SetCHAOutputWhenTrip() and PWM_SetCHAOutputWhenTrip 
 *             to set the PWM output when trip
 *
 * @param[in]  PWMx:  Select the PWM module (PWM0~PWM6)
 *
 * @return     none
 *
 *******************************************************************************/
#define PWM_EnableTripWhenDebug(PWMx)       ((PWMx)->TZSEL.bit.CBCDBG = (TZSEL_BIT_CBCDBG_DEBUG_ENABLE))




/****************************************************************************//**
 * @brief      Configure PWMxA output pin state after trip zone event happen
 *
 * @param[in]  PWMx   :  Select the PWM module (PWM0~PWM6)
 * @param[in]  eAction:  Specifies the action after trip zone
 *                       Please goto PWM_PWMOutputTripEnum for selection
 *                        - \ref TRIP_AT_TRI_STATE
 *                        - \ref TRIP_AT_HIGH
 *                        - \ref TRIP_AT_LOW
 *                        - \ref TRIP_DO_NOTHING
 *
 * @return     none
 *
 *******************************************************************************/
#define PWM_SetCHAOutputWhenTrip(PWMx,eAction) ((PWMx)->TZCTL.bit.TZA = (eAction))
#define PWM_SetCHBOutputWhenTrip(PWMx,eAction) ((PWMx)->TZCTL.bit.TZB = (eAction))




/****************************************************************************//**
 * @brief      Enable one shot interrupt
 *
 * @param[in]  PWMx:  Select the PWM module (PWM0~PWM6)
 *
 * @return     none
 *
 *******************************************************************************/
#define PWM_EnableOneShotTripInt(PWMx)      ((PWMx)->TZIE.bit.OST = TZIE_BIT_OST_ENABLE)




/****************************************************************************//**
 * @brief      Disable one shot interrupt
 *
 * @param[in]  PWMx:  Select the PWM module (PWM0~PWM6)
 *
 * @return     none
 *
 *******************************************************************************/
#define PWM_DisableOneShotTripInt(PWMx)     ((PWMx)->TZIE.bit.OST = TZIE_BIT_OST_DISABLE)




/****************************************************************************//**
 * @brief      Enable cycle by cycle interrupt
 *
 * @param[in]  PWMx:  Select the PWM module (PWM0~PWM6)
 *
 * @return     none
 *
 *******************************************************************************/
#define PWM_EnableCBCTripInt(PWMx)          ((PWMx)->TZIE.bit.CBC = TZIE_BIT_CBC_ENABLE)




/****************************************************************************//**
 * @brief      Disable cycle by cycle interrupt
 *
 * @param[in]  PWMx:  Select the PWM module (PWM0~PWM6)
 *
 * @return     none
 *
 *******************************************************************************/
#define PWM_DisableCBCTripInt(PWMx)         ((PWMx)->TZIE.bit.CBC = TZIE_BIT_CBC_DISABLE)




/****************************************************************************//**
 * @brief      Get one shot trip zone event status
 *
 * @param[in]  PWMx:  Select the PWM module (PWM0~PWM6)
 *
 * @return     0: No one shot event occurred
 *             1: one shot event has occurred
 *
 *******************************************************************************/
#define PWM_GetOneShotTripIntFlag(PWMx)     ((PWMx)->TZFLG.bit.OST)




/****************************************************************************//**
 * @brief      Get cycle by cycle trip zone event status
 *
 * @param[in]  PWMx:  Select the PWM module (PWM0~PWM6)
 *
 * @return     0: No cycle by cycle event occurred
 *             1: cycle by cycle event has occurred
 *
 *******************************************************************************/
#define PWM_GetCBCTripIntFlag(PWMx)         ((PWMx)->TZFLG.bit.CBC)




/****************************************************************************//**
 * @brief      Get global trip zone event status
 *
 * @param[in]  PWMx:  Select the PWM module (PWM0~PWM6)
 *
 * @return     0: No cycle by cycle or one shot event occurred
 *             1: Cycle by cycle or one shot event has occurred
 *
 *******************************************************************************/
#define PWM_GetGlobalTripIntFlag(PWMx)      ((PWMx)->TZFLG.bit.INT)




/****************************************************************************//**
 * @brief      Clear one shot flag
 *
 * @param[in]  PWMx:  Select the PWM module (PWM0~PWM6)
 *
 * @return     none
 *
 *******************************************************************************/
#define PWM_ClearOneShotTripInt(PWMx)       ((PWMx)->TZCLR.all = TZCLR_ALL_OST_CLEAR_FLAG)




/****************************************************************************//**
 * @brief      Clear cycle by cycle flag
 *
 * @param[in]  PWMx:  Select the PWM module (PWM0~PWM6)
 *
 * @return     none
 *
 *******************************************************************************/
#define PWM_ClearCBCTripInt(PWMx)           ((PWMx)->TZCLR.all = TZCLR_ALL_CBC_CLEAR_FLAG)




/****************************************************************************//**
 * @brief      Clear global trip zone event flag
 *
 * @param[in]  PWMx:  Select the PWM module (PWM0~PWM6)
 *
 * @return     none
 *
 *******************************************************************************/
#define PWM_ClearGlobalTripInt(PWMx)        ((PWMx)->TZCLR.all = TZCLR_ALL_INT_CLEAR_FLAG)




/****************************************************************************//**
 * @brief      Enable SOCA as an ADC trigger signal
 *
 * @param[in]  PWMx:  Select the PWM module (PWM0~PWM6)
 *
 * @return     none
 *
 *******************************************************************************/
#define PWM_EnableSOCATrig(PWMx)            ((PWMx)->ETSEL.bit.SOCAEN = ETSEL_BIT_SOCAEN_ENABLE)




/****************************************************************************//**
 * @brief      Disable SOCA as an ADC trigger signal
 *
 * @param[in]  PWMx:  Select the PWM module (PWM0~PWM6)
 *
 * @return     none
 *
 *******************************************************************************/
#define PWM_DisableSOCATrig(PWMx)           ((PWMx)->ETSEL.bit.SOCAEN = ETSEL_BIT_SOCAEN_DISABLE)




/****************************************************************************//**
 * @brief      Configure PWMA SOC(SOCA) trigger pulse generate timing
 *
 * @param[in]  PWMx   :  Select the PWM module (PWM0~PWM6)
 * @param[in]  eTiming:  Specifies the event timing
 *                       Please goto PWM_EventTimingEnum for selection
 *                        - \ref EQU_ZERO
 *                        - \ref EQU_PERIOD
 *                        - \ref EQU_ZERO_PERIOD
 *                        - \ref EQU_CMPA_UP_COUNTING
 *                        - \ref EQU_CMPA_DOWN_COUNTING
 *                        - \ref EQU_CMPB_UP_COUNTING
 *                        - \ref EQU_CMPB_DOWN_COUNTING
 *
 * @return     none
 *
 * @details    This function is to confiqure the event period that ADC trigger 
 *             signal or PWM time event.
 * 
 *******************************************************************************/
#define PWM_SetSOCATiming(PWMx,eTiming)     ((PWMx)->ETSEL.bit.SOCASEL = (eTiming))




 /****************************************************************************//**
 * @brief      Configure PWMA SOC(SOCA) trigger pulse generate period
 *
 * @param[in]  PWMx   :  Select the PWM module (PWM0~PWM6)
 * @param[in]  ePeriod:  Specifies the period
 *                       Please goto PWM_EventPeriodEnum for selection
 *                        - \ref NO_EVENT      Disable event counter. No event pulse will be generated 
 *                        - \ref ON_1ST_EVENT  Generate pulse when first event
 *                        - \ref ON_1ST_EVENT  Generate pulse when second event
 *                        - \ref ON_1ST_EVENT  Generate pulse when third event
 *
 * @return     none
 *
 * @details    This function is to confiqure the event period that ADC trigger 
 *             signal or PWM time event.
 * 
 *******************************************************************************/
#define PWM_SetSOCAPeriod(PWMx,ePeriod)     ((PWMx)->ETPS.bit.SOCAPRD  = (ePeriod))




 /****************************************************************************//**
 * @brief      Enable SOCB as an ADC trigger signal
 *
 * @param[in]  PWMx:  Select the PWM module (PWM0~PWM6)
 *
 * @return     none
 *
 *******************************************************************************/
#define PWM_EnableSOCBTrig(PWMx)            ((PWMx)->ETSEL.bit.SOCBEN = ETSEL_BIT_SOCBEN_ENABLE)




/****************************************************************************//**
 * @brief      Disble SOCB as an ADC trigger signal
 *
 * @param[in]  PWMx:  Select the PWM module (PWM0~PWM6)
 *
 * @return     none
 *
 *******************************************************************************/
#define PWM_DisableSOCBTrig(PWMx)           ((PWMx)->ETSEL.bit.SOCBEN = ETSEL_BIT_SOCBEN_DISABLE)




/****************************************************************************//**
 * @brief      Configure PWMB SOC(SOCB) ADC trigger pulse generate timing
 *
 * @param[in]  PWMx   :  Select the PWM module (PWM0~PWM6)
 * @param[in]  eTiming:  Specifies the event timing
 *                       Please goto PWM_EventTimingEnum for selection
 *                        - \ref EQU_ZERO
 *                        - \ref EQU_PERIOD
 *                        - \ref EQU_ZERO_PERIOD
 *                        - \ref EQU_CMPA_UP_COUNTING
 *                        - \ref EQU_CMPA_DOWN_COUNTING
 *                        - \ref EQU_CMPB_UP_COUNTING
 *                        - \ref EQU_CMPB_DOWN_COUNTING
 *
 * @return     none
 * 
 * @details    This function is to confiqure the event period that ADC trigger 
 *             signal or PWM time event
 * 
 *******************************************************************************/
#define PWM_SetSOCBTiming(PWMx,eTiming)     ((PWMx)->ETSEL.bit.SOCBSEL = (eTiming))




/****************************************************************************//**
 * @brief      Configure PWMB SOC(SOCB) trigger pulse generate period
 *
 * @param[in]  PWMx   :  Select the PWM module (PWM0~PWM6)
 * @param[in]  ePeriod:  Specifies the period
 *                       Please goto PWM_EventPeriodEnum for selection
 *                        - \ref NO_EVENT      Disable event counter. No event pulse will be generated
 *                        - \ref ON_1ST_EVENT  Generate pulse when first event
 *                        - \ref ON_1ST_EVENT  Generate pulse when second event
 *                        - \ref ON_1ST_EVENT  Generate pulse when third event
 *
 * @return     none
 *
 * @details    This function is to confiqure the event period that ADC trigger 
 *             signal or PWM time event.
 * 
 *******************************************************************************/
#define PWM_SetSOCBPeriod(PWMx,ePeriod)     ((PWMx)->ETPS.bit.SOCBPRD  = (ePeriod))




/****************************************************************************//**
 * @brief      Enable Time event interrupt
 *
 * @param[in]  PWMx:  Select the PWM module (PWM0~PWM6)
 *
 * @return     none
 *
 *******************************************************************************/
#define PWM_EnableTimeEvtINT(PWMx)          ((PWMx)->ETSEL.bit.INTEN  = ETSEL_BIT_INTEN_ENABLE)




/****************************************************************************//**
 * @brief      Disable Time event interrupt
 *
 * @param[in]  PWMx:  Select the PWM module (PWM0~PWM6)
 *
 * @return     none
 *
 *******************************************************************************/
#define PWM_DisableTimeEvtINT(PWMx)         ((PWMx)->ETSEL.bit.INTEN  = ETSEL_BIT_INTEN_DISABLE)




/****************************************************************************//**
 * @brief      Configure PWM time event generate timing
 *
 * @param[in]  PWMx   :  Select the PWM module (PWM0~PWM6)
 * @param[in]  eTiming:  Specifies the event timing
 *                       Please goto PWM_EventTimingEnum for selection
 *                        - \ref EQU_ZERO
 *                        - \ref EQU_PERIOD
 *                        - \ref EQU_ZERO_PERIOD
 *                        - \ref EQU_CMPA_UP_COUNTING
 *                        - \ref EQU_CMPA_DOWN_COUNTING
 *                        - \ref EQU_CMPB_UP_COUNTING
 *                        - \ref EQU_CMPB_DOWN_COUNTING
 *
 * @return     none
 *
 * @details    This function is to confiqure the event period that ADC trigger 
 *             signal or PWM time event.
 * 
 *******************************************************************************/
#define PWM_SetTimeEvtTiming(PWMx,eTiming)  ((PWMx)->ETSEL.bit.INTSEL = (eTiming))




/****************************************************************************//**
 * @brief      Configure PWM time event generate period
 *
 * @param[in]  PWMx   :  Select the PWM module (PWM0~PWM6)
 * @param[in]  ePeriod:  Specifies the period
 *                       Please goto PWM_EventPeriodEnum for selection
 *                        - \ref NO_EVENT      Disable event counter. No event pulse will be generated
 *                        - \ref ON_1ST_EVENT  Generate pulse when first event
 *                        - \ref ON_1ST_EVENT  Generate pulse when second event
 *                        - \ref ON_1ST_EVENT  Generate pulse when third event
 * 
 * @return     none
 * 
 * @details    This function is to confiqure the event period that ADC trigger 
 *             signal or PWM time event.
 * 
 *******************************************************************************/
#define PWM_SetTimeEvtPeriod(PWMx,ePeriod)  ((PWMx)->ETPS.bit.INTPRD = (ePeriod))




/****************************************************************************//**
 * @brief      Clear time event interrupt flag
 *
 * @param[in]  PWMx:  Select the PWM module (PWM0~PWM6)
 *
 * @return     none
 *
 *******************************************************************************/
#define PWM_ClearTimeEvtInt(PWMx)           ((PWMx)->ETCLR.all = ETCLR_ALL_INT_CLEAR_FLAG)




/****************************************************************************//**
 * @brief      Get time event status flag
 *
 * @param[in]  PWMx:  Select the PWM module (PWM0~PWM6)
 *
 * @return     none
 *
 *******************************************************************************/
#define PWM_GetTimeEvtIntFlag(PWMx)         ((PWMx)->ETFLG.bit.INT)




/****************************************************************************//**
 * @brief      Calculate COMPx index in TZSEL register
 *
 * @param[in]  CompX:  Select the comparator module
 *                     Please goto COMP_ComparatorSelEnum for selection
 *                      - \ref COMP_0_LO
 *                      - \ref COMP_1_LO
 *                      - \ref COMP_2_LO
 *                      - \ref COMP_0_HI
 *                      - \ref COMP_1_HI
 *                      - \ref COMP_2_HI
 *
 * @return     none
 *
 *******************************************************************************/
 #define PWM_GetTripSelCompIndex(CompX)     (((CompX)<3)?(1+((CompX)<<1)):(((CompX)-3)<<1)) 




/**
 *  @brief  PWM Public Function Declaration
 */
void PWM_ComplementaryPairChannelInit(PWM_REGS* PWMx, uint32_t u32PWMFreqHz, uint32_t u32DeadTimeNs);
void PWM_SingleChannelInit(PWM_REGS* PWMx, PWM_ChannelEnum ePWM_CH, uint32_t u32PWMFreqHz);
void PWM_SetOneshotTripFromExtPin(PWM_REGS* pPWM, GPIO_PinEnum ePinNum);
void PWM_EnableOneShotTripFromComp(PWM_REGS* pPWM, uint8_t eCOMP);


#ifdef __cplusplus
}
#endif /* extern "C" */

#endif /* PWM_H */


/******************* (C) COPYRIGHT 2021 SPINTROL LIMITED CO. *****END OF FILE****/
