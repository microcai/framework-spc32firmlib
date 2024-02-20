/**************************************************************************//**
 * @file     ecap.h
 * @brief    eCAP driver header file.
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

#ifndef ECAP_H
#define ECAP_H

#ifdef __cplusplus
extern "C" {
#endif


#include "spc1068.h"




/****************************************************************************//**
 * @brief      APWM Output is active high
 *
 * @param[in]  ECAPx:  Select the ECAP module
 *
 * @return     none
 *
 *******************************************************************************/
#define ECAP_APwmActiveHigh(ECAPx)          ((ECAPx)->CAPCTL.bit.APWMPOL = CAPCTL_BIT_APWMPOL_ACTIVE_HIGH)





/****************************************************************************//**
 * @brief      APWM Output is active low
 *
 * @param[in]  ECAPx:  Select the ECAP module
 *
 * @return     none
 *
 *******************************************************************************/
#define ECAP_APwmActiveLow(ECAPx)           ((ECAPx)->CAPCTL.bit.APWMPOL = CAPCTL_BIT_APWMPOL_ACTIVE_LOW)




/****************************************************************************//**
 * @brief      Counter Run
 *
 * @param[in]  ECAPx:  Select the ECAP module
 *
 * @return     none
 *
 *******************************************************************************/
#define ECAP_CounterRun(ECAPx)              ((ECAPx)->CAPCTL.bit.TSCNTRUN = CAPCTL_BIT_TSCNTRUN_START_COUNTER)




/****************************************************************************//**
 * @brief      Counter Stop
 *
 * @param[in]  ECAPx:  Select the ECAP module
 *
 * @return     none
 *
 *******************************************************************************/
#define ECAP_CounterStop(ECAPx)             ((ECAPx)->CAPCTL.bit.TSCNTRUN = CAPCTL_BIT_TSCNTRUN_STOP_COUNTER)




/****************************************************************************//**
 * @brief      Set Counter Value
 *
 * @param[in]  ECAPx    :  Select the ECAP module
 * @param[in]  u32CntVal:  Counter value
 *
 * @return     none
 *
 *******************************************************************************/
#define ECAP_SetCouterVal(ECAPx,u32CntVal)  ((ECAPx)->TSCNT.all = (u32CntVal))




/****************************************************************************//**
 * @brief      Enable CEVT0 Interrupt
 *
 * @param[in]  ECAPx:  Select the ECAP module
 *
 * @return     none
 *
 *******************************************************************************/
#define ECAP_EnableCEVT0Int(ECAPx)          ((ECAPx)->CAPIEIF.bit.IECEVT0 = CAPIEIF_BIT_IECEVT0_ENABLE)




/****************************************************************************//**
 * @brief      Disable CEVT0 Interrupt
 *
 * @param[in]  ECAPx:  Select the ECAP module
 *
 * @return     none
 *
 *******************************************************************************/
#define ECAP_DisableCEVT0Int(ECAPx)         ((ECAPx)->CAPIEIF.bit.IECEVT0 = CAPIEIF_BIT_IECEVT0_DISABLE)




/****************************************************************************//**
 * @brief      Enable CEVT1 Interrupt
 *
 * @param[in]  ECAPx:  Select the ECAP module
 *
 * @return     none
 *
 *******************************************************************************/
#define ECAP_EnableCEVT1Int(ECAPx)          ((ECAPx)->CAPIEIF.bit.IECEVT1 = CAPIEIF_BIT_IECEVT1_ENABLE)




/****************************************************************************//**
 * @brief      Disable CEVT1 Interrupt
 *
 * @param[in]  ECAPx:  Select the ECAP module
 *
 * @return     none
 *
 *******************************************************************************/
#define ECAP_DisableCEVT1Int(ECAPx)         ((ECAPx)->CAPIEIF.bit.IECEVT1 = CAPIEIF_BIT_IECEVT1_DISABLE)




/****************************************************************************//**
 * @brief      Enable CEVT2 Interrupt
 *
 * @param[in]  ECAPx:  Select the ECAP module
 *
 * @return     none
 *
 *******************************************************************************/
#define ECAP_EnableCEVT2Int(ECAPx)          ((ECAPx)->CAPIEIF.bit.IECEVT2 = CAPIEIF_BIT_IECEVT2_ENABLE)




/****************************************************************************//**
 * @brief      Disable CEVT2 Interrupt
 *
 * @param[in]  ECAPx:  Select the ECAP module
 *
 * @return     none
 *
 *******************************************************************************/
#define ECAP_DisableCEVT2Int(ECAPx)         ((ECAPx)->CAPIEIF.bit.IECEVT2 = CAPIEIF_BIT_IECEVT2_DISABLE)




/****************************************************************************//**
 * @brief      Enable CEVT3 Interrupt
 *
 * @param[in]  ECAPx:  Select the ECAP module
 *
 * @return     none
 *
 *******************************************************************************/
#define ECAP_EnableCEVT3Int(ECAPx)          ((ECAPx)->CAPIEIF.bit.IECEVT3 = CAPIEIF_BIT_IECEVT3_ENABLE)




/****************************************************************************//**
 * @brief      Disable CEVT3 Interrupt
 *
 * @param[in]  ECAPx:  Select the ECAP module
 *
 * @return     none
 *
 *******************************************************************************/
#define ECAP_DisableCEVT3Int(ECAPx)         ((ECAPx)->CAPIEIF.bit.IECEVT3 = CAPIEIF_BIT_IECEVT3_DISABLE)




/****************************************************************************//**
 * @brief      Enable Count Overflow Interrupt
 *
 * @param[in]  ECAPx:  Select the ECAP module
 *
 * @return     none
 *
 *******************************************************************************/
#define ECAP_EnableCntOverflowInt(ECAPx)    ((ECAPx)->CAPIEIF.bit.IECNTOVF = CAPIEIF_BIT_IECNTOVF_ENABLE)




/****************************************************************************//**
 * @brief      Disable Count Overflow Interrupt
 *
 * @param[in]  ECAPx:  Select the ECAP module
 *
 * @return     none
 *
 *******************************************************************************/
#define ECAP_DisableCntOverflowInt(ECAPx)   ((ECAPx)->CAPIEIF.bit.IECNTOVF = CAPIEIF_BIT_IECNTOVF_DISABLE)




/****************************************************************************//**
 * @brief      Enable Count Equal Period value Interrupt
 *
 * @param[in]  ECAPx:  Select the ECAP module
 *
 * @return     none
 *
 *******************************************************************************/
#define ECAP_EnableCntEqualPrdInt(ECAPx)    ((ECAPx)->CAPIEIF.bit.IEPRD = CAPIEIF_BIT_IEPRD_ENABLE)




/****************************************************************************//**
 * @brief      Disable Count Equal Period value Interrupt
 *
 * @param[in]  ECAPx:  Select the ECAP module
 *
 * @return     none
 *
 *******************************************************************************/
#define ECAP_DisableCntEqualPrdInt(ECAPx)   ((ECAPx)->CAPIEIF.bit.IEPRD = CAPIEIF_BIT_IEPRD_DISABLE)




/****************************************************************************//**
 * @brief      Enable Count Equal Compare value Interrupt
 *
 * @param[in]  ECAPx:  Select the ECAP module
 *
 * @return     none
 *
 *******************************************************************************/
#define ECAP_EnableCntEqualCmpInt(ECAPx)    ((ECAPx)->CAPIEIF.bit.IECMP = CAPIEIF_BIT_IECMP_ENABLE)




/****************************************************************************//**
 * @brief      Disable Count Equal Compare value Interrupt
 *
 * @param[in]  ECAPx:  Select the ECAP module
 *
 * @return     none
 *
 *******************************************************************************/
#define ECAP_DisableCntEqualCmpInt(ECAPx)   ((ECAPx)->CAPIEIF.bit.IECMP = CAPIEIF_BIT_IECMP_DISABLE)




/****************************************************************************//**
 * @brief      Get CEVT0 Interrupt Flag
 *
 * @param[in]  ECAPx:  Select the ECAP module
 *
 * @return     0 : Indicates no event occurred
 *             1 : Indicates the first event occurred at ECAPx pin
 *
 *******************************************************************************/
#define ECAP_GetCEVT0IntFlag(ECAPx)         ((ECAPx)->CAPIEIF.bit.IFCEVT0)




/****************************************************************************//**
 * @brief      Get CEVT1 Interrupt Flag
 *
 * @param[in]  ECAPx:  Select the ECAP module
 *
 * @return     0 : Indicates no event occurred
 *             1 : Indicates the second event occurred at ECAPx pin
 *
 *******************************************************************************/
#define ECAP_GetCEVT1IntFlag(ECAPx)         ((ECAPx)->CAPIEIF.bit.IFCEVT1)




/****************************************************************************//**
 * @brief      Get CEVT2 Interrupt Flag
 *
 * @param[in]  ECAPx:  Select the ECAP module
 *
 * @return     0 : Indicates no event occurred
 *             1 : Indicates the third event occurred at ECAPx pin
 *
 *******************************************************************************/
#define ECAP_GetCEVT2IntFlag(ECAPx)         ((ECAPx)->CAPIEIF.bit.IFCEVT2)




/****************************************************************************//**
 * @brief      Get CEVT3 Interrupt Flag
 *
 * @param[in]  ECAPx:  Select the ECAP module
 *
 * @return     0 : Indicates no event occurred
 *             1 : Indicates the fourth event occurred at ECAPx pin
 *
 *******************************************************************************/
#define ECAP_GetCEVT3IntFlag(ECAPx)         ((ECAPx)->CAPIEIF.bit.IFCEVT3)




/****************************************************************************//**
 * @brief      Get Count Overflow Interrupt Flag
 *
 * @param[in]  ECAPx:  Select the ECAP module
 *
 * @return     0 : Indicates no event occurred
 *             1 : Indicates the counter (TSCNT) has made the transition from FFFFFFFF to 00000000
 *
 *******************************************************************************/
#define ECAP_GetCntOverflowIntFlag(ECAPx)   ((ECAPx)->CAPIEIF.bit.IFCNTOVF)




/****************************************************************************//**
 * @brief      Get Count Equal Period value Interrupt Flag
 *
 * @param[in]  ECAPx:  Select the ECAP module
 *
 * @return     0 : Indicates no event occurred
 *             1 : Indicates the counter (TSCNT) reached the period register value (APRD) and was reset
 *
 * @note       This flag is only active in APWM mode
 *
 *******************************************************************************/
#define ECAP_GetCntEqualPrdIntFlag(ECAPx)   ((ECAPx)->CAPIEIF.bit.IFPRD)




/****************************************************************************//**
 * @brief      Get Count Equal Compare value Interrupt Flag
 *
 * @param[in]  ECAPx:  Select the ECAP module
 *
 * @return     0 : Indicates no event occurred
 *             1 : Indicates the counter (TSCNT) reached the compare register value (ACMP)
 *
 * @note       This flag is only active in APWM mode
 *
 *******************************************************************************/
#define ECAP_GetCntEqualCmpIntFlag(ECAPx)   ((ECAPx)->CAPIEIF.bit.IFCMP)




/****************************************************************************//**
 * @brief      Get Global Interrupt flag
 *
 * @param[in]  ECAPx:  Select the ECAP module.
 *
 * @return     0 : Indicates no interrupt generated
 *             1 : Indicates that an interrupt was generated
 *
 *******************************************************************************/
#define ECAP_GetGlobalIntFlag(ECAPx)        ((ECAPx)->CAPIEIF.bit.IFGLB)




/****************************************************************************//**
 * @brief      Is Interrupt Pending
 *
 * @param[in]  ECAPx:  Select the ECAP module
 *
 * @return     0 : No interrupt pending
 *             1 : Interrupt pending
 *
 *******************************************************************************/
#define ECAP_IsGlobalIntPending(ECAPx)      ((ECAPx)->CAPIEIF.bit.IFGLB)




/****************************************************************************//**
 * @brief      Force CEVT0 Interrupt
 *
 * @param[in]  ECAPx:  Select the ECAP module
 *
 * @return     none
 *
 *******************************************************************************/
#define ECAP_ForceCEVT0Int(ECAPx)           ((ECAPx)->CAPICFRC.all = CAPICFRC_ALL_FRCCEVT0_FORCE)




/****************************************************************************//**
 * @brief      Force CEVT1 Interrupt
 *
 * @param[in]  ECAPx:  Select the ECAP module
 *
 * @return     none
 *
 *******************************************************************************/
#define ECAP_ForceCEVT1Int(ECAPx)           ((ECAPx)->CAPICFRC.all = CAPICFRC_ALL_FRCCEVT1_FORCE)




/****************************************************************************//**
 * @brief      Force CEVT2 Interrupt
 *
 * @param[in]  ECAPx:  Select the ECAP module
 *
 * @return     none
 *
 *******************************************************************************/
#define ECAP_ForceCEVT2Int(ECAPx)           ((ECAPx)->CAPICFRC.all = CAPICFRC_ALL_FRCCEVT2_FORCE)




/****************************************************************************//**
 * @brief      Force CEVT3 Interrupt
 *
 * @param[in]  ECAPx:  Select the ECAP module
 *
 * @return     none
 *
 *******************************************************************************/
#define ECAP_ForceCEVT3Int(ECAPx)           ((ECAPx)->CAPICFRC.all = CAPICFRC_ALL_FRCCEVT3_FORCE)




/****************************************************************************//**
 * @brief      Force Count Overflow Interrupt
 *
 * @param[in]  ECAPx:  Select the ECAP module
 *
 * @return     none
 *
 *******************************************************************************/
#define ECAP_ForceCntOverflowInt(ECAPx)     ((ECAPx)->CAPICFRC.all = CAPICFRC_ALL_FRCCNTOVF_FORCE_CNT_OVERFLOW)




/****************************************************************************//**
 * @brief      Force Count Equal Period value Interrupt
 *
 * @param[in]  ECAPx:  Select the ECAP module
 *
 * @return     none
 *
 *******************************************************************************/
#define ECAP_ForceCntEqualPrdInt(ECAPx)     ((ECAPx)->CAPICFRC.all = CAPICFRC_ALL_FRCPRD_FORCE_CNT_EQU_PRD)




/****************************************************************************//**
 * @brief      Force Count Equal Compare value Interrupt
 *
 * @param[in]  ECAPx:  Select the ECAP module
 *
 * @return     none
 *
 *******************************************************************************/
#define ECAP_ForceCntEqualCmpInt(ECAPx)     ((ECAPx)->CAPICFRC.all = CAPICFRC_ALL_FRCCMP_FORCE_CNT_EQU_COMP)




/****************************************************************************//**
 * @brief      Clear CEVT0 Interrupt Flag
 *
 * @param[in]  ECAPx:  Select the ECAP module
 *
 * @return     none
 *
 *******************************************************************************/
#define ECAP_ClearCEVT0Int(ECAPx)           ((ECAPx)->CAPICFRC.all = CAPICFRC_ALL_ICCEVT0_CLEAR)




/****************************************************************************//**
 * @brief      Clear CEVT1 Interrupt Flag
 *
 * @param[in]  ECAPx:  Select the ECAP module
 *
 * @return     none
 *
 *******************************************************************************/
#define ECAP_ClearCEVT1Int(ECAPx)           ((ECAPx)->CAPICFRC.all = CAPICFRC_ALL_ICCEVT1_CLEAR)




/****************************************************************************//**
 * @brief      Clear CEVT2 Interrupt Flag
 *
 * @param[in]  ECAPx:  Select the ECAP module
 *
 * @return     none
 *
 *******************************************************************************/
#define ECAP_ClearCEVT2Int(ECAPx)           ((ECAPx)->CAPICFRC.all = CAPICFRC_ALL_ICCEVT2_CLEAR)




/****************************************************************************//**
 * @brief      Clear CEVT3 Interrupt Flag
 *
 * @param[in]  ECAPx:  Select the ECAP module
 *
 * @return     none
 *
 *******************************************************************************/
#define ECAP_ClearCEVT3Int(ECAPx)           ((ECAPx)->CAPICFRC.all = CAPICFRC_ALL_ICCEVT3_CLEAR)




/****************************************************************************//**
 * @brief      Clear Count Overflow Interrupt Flag
 *
 * @param[in]  ECAPx:  Select the ECAP module
 *
 * @return     none
 *
 *******************************************************************************/
#define ECAP_ClearCntOverflowInt(ECAPx)     ((ECAPx)->CAPICFRC.all = CAPICFRC_ALL_ICCNTOVF_CLEAR_CNT_OVERFLOW_FLAG)




/****************************************************************************//**
 * @brief      Clear Count Equal Period value Interrupt Flag
 *
 * @param[in]  ECAPx:  Select the ECAP module
 *
 * @return     none
 *
 *******************************************************************************/
#define ECAP_ClearCntEqualPrdInt(ECAPx)     ((ECAPx)->CAPICFRC.all = CAPICFRC_ALL_ICPRD_CLEAR_CNT_EQU_PRD_FLAG)




/****************************************************************************//**
 * @brief      Clear Count Equal Compare value Interrupt Flag
 *
 * @param[in]  ECAPx:  Select the ECAP module
 *
 * @return     none
 *
 *******************************************************************************/
#define ECAP_ClearCntEqualCmpInt(ECAPx)     ((ECAPx)->CAPICFRC.all = CAPICFRC_ALL_ICCMP_CLEAR_CNT_EQU_COMP_FLAG)




/****************************************************************************//**
 * @brief      Clear Global Interrupt Flag
 *
 * @param[in]  ECAPx:  Select the ECAP module
 *
 * @return     none
 *
 *******************************************************************************/
#define ECAP_ClearGlobalInt(ECAPx)          ((ECAPx)->CAPICFRC.all = CAPICFRC_ALL_ICGLB_CLEAR_GLOBAL_INT_FLAG)




/**
 *  @brief ECAP Public Function Declaration
 */
void ECAP_CaptureModeInit(ECAP_REGS* ECAPx, GPIO_PinEnum ePinNum);
void ECAP_APwmModeInit(ECAP_REGS* ECAPx, GPIO_PinEnum ePinNum, uint32_t u32PwmFreq);
void ECAP_APwmSetDuty(ECAP_REGS* ECAPx, uint32_t u32PwmDuty);


#ifdef __cplusplus
}
#endif /* extern "C" */

#endif /* ECAP_H */


/******************* (C) COPYRIGHT 2021 SPINTROL LIMITED CO. *****END OF FILE****/
