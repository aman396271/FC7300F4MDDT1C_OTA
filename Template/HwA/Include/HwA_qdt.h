/**
 * @file HwA_qdt.h
 * @author Flagchip0084
 * @brief Hardware access layer for QDT
 * @version 2.0.0
 * @date 2024-07-25
 *
 * SDK Version: 2.6.0
 *

 * @copyright Copyright (c) 2022 Flagchip Semiconductors Co., Ltd.
 *
 */
/* ********************************************************************************
   *   Revision History:
   *
   *   Version     Date          Initials      CR#          Descriptions
   *   ---------   ----------    ------------  ----------   ---------------
   *   0.1.0      2023-12-15     Flagchip084   N/A          First version for FC7300
   *   2.0.0      2024-10-12     Flagchip084   N/A          Change version and release
   ******************************************************************************** */

#ifndef _HWA_QDT_H_
#define _HWA_QDT_H_

#include "device_header.h"

#if QDT_INSTANCE_COUNT > 0U

/**
 * @defgroup HwA_qdt
 * @ingroup fc7xxx_driver_qdt
 * @{
 */

/**
 * @brief Get the value of EXTCLK_SEL.
 * External Clock Select
 * Selects the external clock as the QDT function clock.
 * This field is write protected (depends on WPDIS/WPEN).
 * 00b - QDT_TCLK0 pin as QDT external clock.
 * 01b - QDT_TCLK1 pin as QDT external clock.
 * 10b - QDT_TCLK2 pin as QDT external clock.
 * 11b - No clock input
 * @param pQdt the base address of the QDT instance.

 * @return uint8_t the value of EXTCLK_SEL.
 */
LOCAL_INLINE uint8_t QDT_HWA_GetEXTCLK_SEL(const QDT_Type *const pQdt)
{
    uint8_t u8TmpVal = (pQdt->SC & QDT_SC_EXTCLK_SEL_MASK) >> QDT_SC_EXTCLK_SEL_SHIFT;
    return u8TmpVal;
}


/**
 * @brief Set EXTCLK_SEL.
 * External Clock Select
 * Selects the external clock as the QDT function clock.
 * This field is write protected (depends on WPDIS/WPEN).
 * 00b - QDT_TCLK0 pin as QDT external clock.
 * 01b - QDT_TCLK1 pin as QDT external clock.
 * 10b - QDT_TCLK2 pin as QDT external clock.
 * 11b - No clock input
 * @param pQdt the base address of the QDT instance.

 * @param uint8_t u8Value EXTCLK_SEL value.
 */
LOCAL_INLINE void QDT_HWA_SetEXTCLK_SEL(QDT_Type *const pQdt, uint8_t u8Value)
{
    pQdt->SC = (pQdt->SC & ~QDT_SC_EXTCLK_SEL_MASK) | QDT_SC_EXTCLK_SEL(u8Value);
}



/**
 * @brief Get the value of WDOGF.
 * WDOG Timerout Flag
 * Same as WDOG[WDOGF].
 * @param pQdt the base address of the QDT instance.

 * @return uint8_t the value of WDOGF.
 */
LOCAL_INLINE uint8_t QDT_HWA_SC_GetWDOGF(const QDT_Type *const pQdt)
{
    uint8_t u8TmpVal = (pQdt->SC & QDT_SC_WDOGF_MASK) >> QDT_SC_WDOGF_SHIFT;
    return u8TmpVal;
}


/**
 * @brief Clear WDOGF.
 * WDOG Timerout Flag
 * Same as WDOG[WDOGF].
 * @param pQdt the base address of the QDT instance.

 */
LOCAL_INLINE void QDT_HWA_SC_ClearWDOGF(QDT_Type *const pQdt)
{
    pQdt->SC &= ~QDT_SC_WDOGF_MASK;
}


/**
 * @brief Get the value of CHNF.
 * Channel (n) Flag
 * Same as CSnC[CHF].
 * MSB is CH3, LSB is CH0.
 * @param pQdt the base address of the QDT instance.

 * @return uint8_t the value of CHNF.
 */
LOCAL_INLINE uint8_t QDT_HWA_GetCHNF(const QDT_Type *const pQdt)
{
    uint8_t u8TmpVal = (pQdt->SC & QDT_SC_CHNF_MASK) >> QDT_SC_CHNF_SHIFT;
    return u8TmpVal;
}


/**
 * @brief Clear CHNF.
 * Channel (n) Flag
 * Same as CSnC[CHF].
 * MSB is CH3, LSB is CH0.
 * @param pQdt the base address of the QDT instance.

 */
LOCAL_INLINE void QDT_HWA_ClearCHNF(QDT_Type *const pQdt)
{
    pQdt->SC &= ~QDT_SC_CHNF_MASK;
}


/**
 * @brief Get the value of TOF.
 * Timer Overflow Flag
 * When the QDT counter (also is position counter) passes the value in the MOD register, this bit asserted.
 * The TOF bit is cleared by reading the SC register while TOF is set and then writing a 0 to TOF bit. Writing a 1 to TOF has no effect.
 * If another QDT overflow occurs between the read and write operations, the write operation has no effect; therefore, TOF remains set indicating an overflow has occurred. In this case, a TOF interrupt request is not lost due to the clearing sequence for a previous TOF.
 * 0b - QDT counter has not overflowed. 
 * 1b - QDT counter has overflowed.
 * @param pQdt the base address of the QDT instance.

 * @return uint8_t the value of TOF.
 */
LOCAL_INLINE uint8_t QDT_HWA_GetTOF(const QDT_Type *const pQdt)
{
    uint8_t u8TmpVal = (pQdt->SC & QDT_SC_TOF_MASK) >> QDT_SC_TOF_SHIFT;
    return u8TmpVal;
}


/**
 * @brief Clear TOF.
 * Timer Overflow Flag
 * When the QDT counter (also is position counter) passes the value in the MOD register, this bit asserted.
 * The TOF bit is cleared by reading the SC register while TOF is set and then writing a 0 to TOF bit. Writing a 1 to TOF has no effect.
 * If another QDT overflow occurs between the read and write operations, the write operation has no effect; therefore, TOF remains set indicating an overflow has occurred. In this case, a TOF interrupt request is not lost due to the clearing sequence for a previous TOF.
 * 0b - QDT counter has not overflowed. 
 * 1b - QDT counter has overflowed.
 * @param pQdt the base address of the QDT instance.

 */
LOCAL_INLINE void QDT_HWA_ClearTOF(QDT_Type *const pQdt)
{
    pQdt->SC &= ~QDT_SC_TOF_MASK;
}


/**
 * @brief Get the value of TOIE.
 * Timer Overflow Interrupt Enable
 * 0b - Disable TOF interrupts. 
 * 1b - Enable TOF interrupts. An interrupt is generated when TOF asserted.
 * @param pQdt the base address of the QDT instance.

 * @return uint8_t the value of TOIE.
 */
LOCAL_INLINE uint8_t QDT_HWA_GetTOIE(const QDT_Type *const pQdt)
{
    uint8_t u8TmpVal = (pQdt->SC & QDT_SC_TOIE_MASK) >> QDT_SC_TOIE_SHIFT;
    return u8TmpVal;
}


/**
 * @brief Set TOIE.
 * Timer Overflow Interrupt Enable
 * 0b - Disable TOF interrupts. 
 * 1b - Enable TOF interrupts. An interrupt is generated when TOF asserted.
 * @param pQdt the base address of the QDT instance.

 * @param uint8_t u8Value TOIE value.
 */
LOCAL_INLINE void QDT_HWA_SetTOIE(QDT_Type *const pQdt, uint8_t u8Value)
{
    pQdt->SC = (pQdt->SC & ~QDT_SC_TOIE_MASK) | QDT_SC_TOIE(u8Value);
}



/**
 * @brief Get the value of WPDIS.
 * Write Protection Disable
 * When write protection is enabled (WPDIS = 0), write protected bits cannot be written. When write protection is disabled (WPDIS = 1), write protected bits can be written. The WPDIS bit is the negation of the WPEN bit. WPDIS is cleared when 1 is written to WPEN. WPDIS is set when WPEN bit is read as a 1 and then 1 is written to WPDIS. Writing 0 to WPDIS has no effect.
 * @param pQdt the base address of the QDT instance.

 * @return uint8_t the value of WPDIS.
 */
LOCAL_INLINE uint8_t QDT_HWA_GetWPDIS(const QDT_Type *const pQdt)
{
    uint8_t u8TmpVal = (pQdt->SC & QDT_SC_WPDIS_MASK) >> QDT_SC_WPDIS_SHIFT;
    return u8TmpVal;
}


/**
 * @brief Set WPDIS.
 * Write Protection Disable
 * When write protection is enabled (WPDIS = 0), write protected bits cannot be written. When write protection is disabled (WPDIS = 1), write protected bits can be written. The WPDIS bit is the negation of the WPEN bit. WPDIS is cleared when 1 is written to WPEN. WPDIS is set when WPEN bit is read as a 1 and then 1 is written to WPDIS. Writing 0 to WPDIS has no effect.
 * @param pQdt the base address of the QDT instance.

 * @param uint8_t u8Value WPDIS value.
 */
LOCAL_INLINE void QDT_HWA_SetWPDIS(QDT_Type *const pQdt, uint8_t u8Value)
{
    pQdt->SC = (pQdt->SC & ~QDT_SC_WPDIS_MASK) | QDT_SC_WPDIS(u8Value);
}

/**
 * @brief Disable the Write protection.
 * @param pQdt the base address of the QDT instance.
 */
LOCAL_INLINE void QDT_HWA_DisableWP(QDT_Type *const pQdt)
{
    pQdt->SC = (pQdt->SC | QDT_SC_WPDIS_MASK) & ~QDT_SC_WPEN_MASK;
}

/**
 * @brief Get the value of WPEN.
 * Write Protection Enable
 * The WPEN bit is the negation of the WPDIS bit. WPEN is set when 1 is written to it. WPEN is cleared when WPEN bit is read as a 1 and then 1 is written to WPDIS. Writing 0 to WPEN has no effect.
 * 0b - Write protection is disabled. Write protected bits can be written. 
 * 1b - Write protection is enabled. Write protected bits cannot be written.
 * @param pQdt the base address of the QDT instance.

 * @return uint8_t the value of WPEN.
 */
LOCAL_INLINE uint8_t QDT_HWA_GetWPEN(const QDT_Type *const pQdt)
{
    uint8_t u8TmpVal = (pQdt->SC & QDT_SC_WPEN_MASK) >> QDT_SC_WPEN_SHIFT;
    return u8TmpVal;
}


/**
 * @brief Set WPEN.
 * Write Protection Enable
 * The WPEN bit is the negation of the WPDIS bit. WPEN is set when 1 is written to it. WPEN is cleared when WPEN bit is read as a 1 and then 1 is written to WPDIS. Writing 0 to WPEN has no effect.
 * 0b - Write protection is disabled. Write protected bits can be written. 
 * 1b - Write protection is enabled. Write protected bits cannot be written.
 * @param pQdt the base address of the QDT instance.

 * @param uint8_t u8Value WPEN value.
 */
LOCAL_INLINE void QDT_HWA_SetWPEN(QDT_Type *const pQdt, uint8_t u8Value)
{
    pQdt->SC = (pQdt->SC & ~QDT_SC_WPEN_MASK) | QDT_SC_WPEN(u8Value);
}

/**
 * @brief Enable the Write protection.
 * @param pQdt the base address of the QDT instance.
 */
LOCAL_INLINE void QDT_HWA_EnableWP(QDT_Type *const pQdt)
{
    pQdt->SC = (pQdt->SC & ~QDT_SC_WPDIS_MASK) | QDT_SC_WPEN_MASK;
}

/**
 * @brief Get the value of DBG.
 * Debug Mode
 * Selects the QDT behavior in Debug Mode.
 * This field is write protected (depends on WPDIS/WPEN).
 * 0b - All counters in QDT are stopped.
 * 1b - QDT works as function mode.
 * @param pQdt the base address of the QDT instance.

 * @return uint8_t the value of DBG.
 */
LOCAL_INLINE uint8_t QDT_HWA_GetDBG(const QDT_Type *const pQdt)
{
    uint8_t u8TmpVal = (pQdt->SC & QDT_SC_DBG_MASK) >> QDT_SC_DBG_SHIFT;
    return u8TmpVal;
}


/**
 * @brief Set DBG.
 * Debug Mode
 * Selects the QDT behavior in Debug Mode.
 * This field is write protected (depends on WPDIS/WPEN).
 * 0b - All counters in QDT are stopped.
 * 1b - QDT works as function mode.
 * @param pQdt the base address of the QDT instance.

 * @param uint8_t u8Value DBG value.
 */
LOCAL_INLINE void QDT_HWA_SetDBG(QDT_Type *const pQdt, uint8_t u8Value)
{
    pQdt->SC = (pQdt->SC & ~QDT_SC_DBG_MASK) | QDT_SC_DBG(u8Value);
}



/**
 * @brief Get the value of MTRIGCTRL.
 * Match Trigger Control
 * Match Trigger Control controls the pulsing of the match trigger output signal.
 * 0b - Match Trigger pulses when a match occurs between the position counters (POS) and the corresponding channel value (CV)
 * 1b - Match Trigger pulses when the POSCNT, REVCNT, or POSDCNT are read
 * @param pQdt the base address of the QDT instance.

 * @return uint8_t the value of MTRIGCTRL.
 */
LOCAL_INLINE uint8_t QDT_HWA_GetMTRIGCTRL(const QDT_Type *const pQdt)
{
    uint8_t u8TmpVal = (pQdt->SC & QDT_SC_MTRIGCTRL_MASK) >> QDT_SC_MTRIGCTRL_SHIFT;
    return u8TmpVal;
}


/**
 * @brief Set MTRIGCTRL.
 * Match Trigger Control
 * Match Trigger Control controls the pulsing of the match trigger output signal.
 * 0b - Match Trigger pulses when a match occurs between the position counters (POS) and the corresponding channel value (CV)
 * 1b - Match Trigger pulses when the POSCNT, REVCNT, or POSDCNT are read
 * @param pQdt the base address of the QDT instance.

 * @param uint8_t u8Value MTRIGCTRL value.
 */
LOCAL_INLINE void QDT_HWA_SetMTRIGCTRL(QDT_Type *const pQdt, uint8_t u8Value)
{
    pQdt->SC = (pQdt->SC & ~QDT_SC_MTRIGCTRL_MASK) | QDT_SC_MTRIGCTRL(u8Value);
}



/**
 * @brief Get the value of QUADIR.
 * QDT Counter Direction In Quadrature Decoder Mode
 * Indicates the counting direction.
 * 0b - QDT counter decrement. 
 * 1b - QDT counter increment.
 * @param pQdt the base address of the QDT instance.

 * @return uint8_t the value of QUADIR.
 */
LOCAL_INLINE uint8_t QDT_HWA_GetQUADIR(const QDT_Type *const pQdt)
{
    uint8_t u8TmpVal = (pQdt->SC & QDT_SC_QUADIR_MASK) >> QDT_SC_QUADIR_SHIFT;
    return u8TmpVal;
}



/**
 * @brief Get the value of TOFDIR.
 * Timer Overflow Direction In Quadrature Decoder Mode
 * Indicates if the TOF bit was set on the top or the bottom of counting.
 * 0b - TOF bit was set on the bottom of counting. QDT counter decrement and counter changes from CNTIN to MOD.
 * 1b - TOF bit was set on the top of counting. QDT counter increment and counter changes from MOD to CNTIN.
 * @param pQdt the base address of the QDT instance.

 * @return uint8_t the value of TOFDIR.
 */
LOCAL_INLINE uint8_t QDT_HWA_GetTOFDIR(const QDT_Type *const pQdt)
{
    uint8_t u8TmpVal = (pQdt->SC & QDT_SC_TOFDIR_MASK) >> QDT_SC_TOFDIR_SHIFT;
    return u8TmpVal;
}



/**
 * @brief Get the value of QUADMODE.
 * Quadrature Decoder Mode
 * Selects the encoding mode used in the Quadrature Decoder mode.
 * 0b - Phase A and phase B encoding mode.
 * 1b - Count and direction encoding mode.
 * @param pQdt the base address of the QDT instance.

 * @return uint8_t the value of QUADMODE.
 */
LOCAL_INLINE uint8_t QDT_HWA_GetQUADMODE(const QDT_Type *const pQdt)
{
    uint8_t u8TmpVal = (pQdt->SC & QDT_SC_QUADMODE_MASK) >> QDT_SC_QUADMODE_SHIFT;
    return u8TmpVal;
}


/**
 * @brief Set QUADMODE.
 * Quadrature Decoder Mode
 * Selects the encoding mode used in the Quadrature Decoder mode.
 * 0b - Phase A and phase B encoding mode.
 * 1b - Count and direction encoding mode.
 * @param pQdt the base address of the QDT instance.

 * @param uint8_t u8Value QUADMODE value.
 */
LOCAL_INLINE void QDT_HWA_SetQUADMODE(QDT_Type *const pQdt, uint8_t u8Value)
{
    pQdt->SC = (pQdt->SC & ~QDT_SC_QUADMODE_MASK) | QDT_SC_QUADMODE(u8Value);
}



/**
 * @brief Get the value of QUADEN.
 * Quadrature Decoder Mode Enable
 * Enables the Quadrature Decoder mode. In this mode, the phase A and B input signals control the QDT counter. this mode has precedence over the other modes.
 * This field is write protected (depends on WPDIS/WPEN).
 * 0b - Quadrature Decoder mode is disabled. 
 * 1b - Quadrature Decoder mode is enabled.
 * @param pQdt the base address of the QDT instance.

 * @return uint8_t the value of QUADEN.
 */
LOCAL_INLINE uint8_t QDT_HWA_GetQUADEN(const QDT_Type *const pQdt)
{
    uint8_t u8TmpVal = (pQdt->SC & QDT_SC_QUADEN_MASK) >> QDT_SC_QUADEN_SHIFT;
    return u8TmpVal;
}


/**
 * @brief Set QUADEN.
 * Quadrature Decoder Mode Enable
 * Enables the Quadrature Decoder mode. In this mode, the phase A and B input signals control the QDT counter. this mode has precedence over the other modes.
 * This field is write protected (depends on WPDIS/WPEN).
 * 0b - Quadrature Decoder mode is disabled. 
 * 1b - Quadrature Decoder mode is enabled.
 * @param pQdt the base address of the QDT instance.

 * @param uint8_t u8Value QUADEN value.
 */
LOCAL_INLINE void QDT_HWA_SetQUADEN(QDT_Type *const pQdt, uint8_t u8Value)
{
    pQdt->SC = (pQdt->SC & ~QDT_SC_QUADEN_MASK) | QDT_SC_QUADEN(u8Value);
}



/**
 * @brief Get the value of CLKS.
 * Clock Source Selection
 * This field is write protected (depends on WPDIS/WPEN).
 * 00b - No clock selected. 
 * 01b - QDT input clock
 * 10b - Reserved 
 * 11b - External pin input clock
 * @param pQdt the base address of the QDT instance.

 * @return uint8_t the value of CLKS.
 */
LOCAL_INLINE uint8_t QDT_HWA_GetCLKS(const QDT_Type *const pQdt)
{
    uint8_t u8TmpVal = (pQdt->SC & QDT_SC_CLKS_MASK) >> QDT_SC_CLKS_SHIFT;
    return u8TmpVal;
}


/**
 * @brief Set CLKS.
 * Clock Source Selection
 * This field is write protected (depends on WPDIS/WPEN).
 * 00b - No clock selected. 
 * 01b - QDT input clock
 * 10b - Reserved 
 * 11b - External pin input clock
 * @param pQdt the base address of the QDT instance.

 * @param uint8_t u8Value CLKS value.
 */
LOCAL_INLINE void QDT_HWA_SetCLKS(QDT_Type *const pQdt, uint8_t u8Value)
{
    pQdt->SC = (pQdt->SC & ~QDT_SC_CLKS_MASK) | QDT_SC_CLKS(u8Value);
}



/**
 * @brief Get the value of PS.
 * Prescale Setting
 * This field would affect the QDT counter clock frequency.
 * This field is write protected (depends on WPDIS/WPEN).
 * 000b - Divide by 1
 * 001b - Divide by 2
 * ...
 * 111b - Divide by 128
 * @param pQdt the base address of the QDT instance.

 * @return uint8_t the value of PS.
 */
LOCAL_INLINE uint8_t QDT_HWA_GetPS(const QDT_Type *const pQdt)
{
    uint8_t u8TmpVal = (pQdt->SC & QDT_SC_PS_MASK) >> QDT_SC_PS_SHIFT;
    return u8TmpVal;
}


/**
 * @brief Set PS.
 * Prescale Setting
 * This field would affect the QDT counter clock frequency.
 * This field is write protected (depends on WPDIS/WPEN).
 * 000b - Divide by 1
 * 001b - Divide by 2
 * ...
 * 111b - Divide by 128
 * @param pQdt the base address of the QDT instance.

 * @param uint8_t u8Value PS value.
 */
LOCAL_INLINE void QDT_HWA_SetPS(QDT_Type *const pQdt, uint8_t u8Value)
{
    pQdt->SC = (pQdt->SC & ~QDT_SC_PS_MASK) | QDT_SC_PS(u8Value);
}





/**
 * @brief Get the value of SYNCMODE.
 * CV SYNC MODE
 * This field is write protected (depends on WPDIS/WPEN).
 * This field define different synchronization behavior, for more information, please refer to Function Description chapter
 * @param pQdt the base address of the QDT instance.

 * @return uint8_t the value of SYNCMODE.
 */
LOCAL_INLINE uint8_t QDT_HWA_GetSYNCMODE(const QDT_Type *const pQdt)
{
    uint8_t u8TmpVal = (pQdt->SYNC & QDT_SYNC_SYNCMODE_MASK) >> QDT_SYNC_SYNCMODE_SHIFT;
    return u8TmpVal;
}


/**
 * @brief Set SYNCMODE.
 * CV SYNC MODE
 * This field is write protected (depends on WPDIS/WPEN).
 * This field define different synchronization behavior, for more information, please refer to Function Description chapter
 * @param pQdt the base address of the QDT instance.

 * @param uint8_t u8Value SYNCMODE value.
 */
LOCAL_INLINE void QDT_HWA_SetSYNCMODE(QDT_Type *const pQdt, uint8_t u8Value)
{
    pQdt->SYNC = (pQdt->SYNC & ~QDT_SYNC_SYNCMODE_MASK) | QDT_SYNC_SYNCMODE(u8Value);
}



/**
 * @brief Get the value of TRIG_UPHOLD.
 * Hardware Trigger Update Hold Registers
 * • When Hardware Trigger Update Hold Registers is set (=1), it allows the TRIGGER input to cause an update of the POSCNTH, REVCNTH and POSDCNTH registers
 * • When Hardware Trigger Update Hold Registers is clear (=0), the hold registers (POSCNTH, REVCNTH and POSDCNTH) are not updated by the TRIGGER input
 * Updating the Position Difference Counter Hold Register (POSDH) will also cause the Position Difference Counter Register (POSD) to be cleared.
 * 0b - Disable updates of hold registers on the rising edge of TRIGGER input signal
 * 1b - Enable updates of hold registers on the rising edge of TRIGGER input signal
 * @param pQdt the base address of the QDT instance.

 * @return uint8_t the value of TRIG_UPHOLD.
 */
LOCAL_INLINE uint8_t QDT_HWA_GetTRIG_UPHOLD(const QDT_Type *const pQdt)
{
    uint8_t u8TmpVal = (pQdt->SYNC & QDT_SYNC_TRIG_UPHOLD_MASK) >> QDT_SYNC_TRIG_UPHOLD_SHIFT;
    return u8TmpVal;
}


/**
 * @brief Set TRIG_UPHOLD.
 * Hardware Trigger Update Hold Registers
 * • When Hardware Trigger Update Hold Registers is set (=1), it allows the TRIGGER input to cause an update of the POSCNTH, REVCNTH and POSDCNTH registers
 * • When Hardware Trigger Update Hold Registers is clear (=0), the hold registers (POSCNTH, REVCNTH and POSDCNTH) are not updated by the TRIGGER input
 * Updating the Position Difference Counter Hold Register (POSDH) will also cause the Position Difference Counter Register (POSD) to be cleared.
 * 0b - Disable updates of hold registers on the rising edge of TRIGGER input signal
 * 1b - Enable updates of hold registers on the rising edge of TRIGGER input signal
 * @param pQdt the base address of the QDT instance.

 * @param uint8_t u8Value TRIG_UPHOLD value.
 */
LOCAL_INLINE void QDT_HWA_SetTRIG_UPHOLD(QDT_Type *const pQdt, uint8_t u8Value)
{
    pQdt->SYNC = (pQdt->SYNC & ~QDT_SYNC_TRIG_UPHOLD_MASK) | QDT_SYNC_TRIG_UPHOLD(u8Value);
}



/**
 * @brief Get the value of TRIG_RSTCNT.
 * Hardware Trigger Reset Counter
 * Allow Hardware TRIGGER input event to reset POSCNT, REVCNT and POSDCNT
 * 0b - Hardware Trigger input event will not reset the counters.
 * 1b - Hardware Trigger input event will reset the counters.
 * @param pQdt the base address of the QDT instance.

 * @return uint8_t the value of TRIG_RSTCNT.
 */
LOCAL_INLINE uint8_t QDT_HWA_GetTRIG_RSTCNT(const QDT_Type *const pQdt)
{
    uint8_t u8TmpVal = (pQdt->SYNC & QDT_SYNC_TRIG_RSTCNT_MASK) >> QDT_SYNC_TRIG_RSTCNT_SHIFT;
    return u8TmpVal;
}


/**
 * @brief Set TRIG_RSTCNT.
 * Hardware Trigger Reset Counter
 * Allow Hardware TRIGGER input event to reset POSCNT, REVCNT and POSDCNT
 * 0b - Hardware Trigger input event will not reset the counters.
 * 1b - Hardware Trigger input event will reset the counters.
 * @param pQdt the base address of the QDT instance.

 * @param uint8_t u8Value TRIG_RSTCNT value.
 */
LOCAL_INLINE void QDT_HWA_SetTRIG_RSTCNT(QDT_Type *const pQdt, uint8_t u8Value)
{
    pQdt->SYNC = (pQdt->SYNC & ~QDT_SYNC_TRIG_RSTCNT_MASK) | QDT_SYNC_TRIG_RSTCNT(u8Value);
}



/**
 * @brief Get the value of TRIG0.
 * Synchronization Hardware Trigger Input 0
 * Enables hardware trigger 0 to the synchronization and reset. Hardware trigger 0 occurs when a rising edge is detected at the trigger 0 input signal.
 * 0b - Trigger is disabled.
 * 1b - Trigger is enabled.
 * @param pQdt the base address of the QDT instance.

 * @return uint8_t the value of TRIG0.
 */
LOCAL_INLINE uint8_t QDT_HWA_GetTRIG0(const QDT_Type *const pQdt)
{
    uint8_t u8TmpVal = (pQdt->SYNC & QDT_SYNC_TRIG0_MASK) >> QDT_SYNC_TRIG0_SHIFT;
    return u8TmpVal;
}


/**
 * @brief Set TRIG0.
 * Synchronization Hardware Trigger Input 0
 * Enables hardware trigger 0 to the synchronization and reset. Hardware trigger 0 occurs when a rising edge is detected at the trigger 0 input signal.
 * 0b - Trigger is disabled.
 * 1b - Trigger is enabled.
 * @param pQdt the base address of the QDT instance.

 * @param uint8_t u8Value TRIG0 value.
 */
LOCAL_INLINE void QDT_HWA_SetTRIG0(QDT_Type *const pQdt, uint8_t u8Value)
{
    pQdt->SYNC = (pQdt->SYNC & ~QDT_SYNC_TRIG0_MASK) | QDT_SYNC_TRIG0(u8Value);
}



/**
 * @brief Get the value of SW_RSTCNT.
 * SW Reset Counter
 * Allow SW event to reset POSCNT, REVCNT and POSDCNT
 * 0b - SW event will only reset the POSCNT.
 * 1b - SW event will reset the POSCNT, REVCNT and POSDCNT.
 * @param pQdt the base address of the QDT instance.

 * @return uint8_t the value of SW_RSTCNT.
 */
LOCAL_INLINE uint8_t QDT_HWA_GetSW_RSTCNT(const QDT_Type *const pQdt)
{
    uint8_t u8TmpVal = (pQdt->SYNC & QDT_SYNC_SW_RSTCNT_MASK) >> QDT_SYNC_SW_RSTCNT_SHIFT;
    return u8TmpVal;
}


/**
 * @brief Set SW_RSTCNT.
 * SW Reset Counter
 * Allow SW event to reset POSCNT, REVCNT and POSDCNT
 * 0b - SW event will only reset the POSCNT.
 * 1b - SW event will reset the POSCNT, REVCNT and POSDCNT.
 * @param pQdt the base address of the QDT instance.

 * @param uint8_t u8Value SW_RSTCNT value.
 */
LOCAL_INLINE void QDT_HWA_SetSW_RSTCNT(QDT_Type *const pQdt, uint8_t u8Value)
{
    pQdt->SYNC = (pQdt->SYNC & ~QDT_SYNC_SW_RSTCNT_MASK) | QDT_SYNC_SW_RSTCNT(u8Value);
}



/**
 * @brief Get the value of SWSYNC.
 * Synchronization Software Trigger
 * Selects the software trigger as the synchronization trigger. The software trigger happens when a 1 is written to SWSYNC bit. It will be cleared automatic.
 * 0b - Software trigger is not selected. 
 * 1b - Software trigger is selected.
 * @param pQdt the base address of the QDT instance.

 * @return uint8_t the value of SWSYNC.
 */
LOCAL_INLINE uint8_t QDT_HWA_GetSWSYNC(const QDT_Type *const pQdt)
{
    uint8_t u8TmpVal = (pQdt->SYNC & QDT_SYNC_SWSYNC_MASK) >> QDT_SYNC_SWSYNC_SHIFT;
    return u8TmpVal;
}


/**
 * @brief Set SWSYNC.
 * Synchronization Software Trigger
 * Selects the software trigger as the synchronization trigger. The software trigger happens when a 1 is written to SWSYNC bit. It will be cleared automatic.
 * 0b - Software trigger is not selected. 
 * 1b - Software trigger is selected.
 * @param pQdt the base address of the QDT instance.

 * @param uint8_t u8Value SWSYNC value.
 */
LOCAL_INLINE void QDT_HWA_SetSWSYNC(QDT_Type *const pQdt, uint8_t u8Value)
{
    pQdt->SYNC = (pQdt->SYNC & ~QDT_SYNC_SWSYNC_MASK) | QDT_SYNC_SWSYNC(u8Value);
}





/**
 * @brief Get the value of PHZPOL.
 * Phase Z Input Polarity
 * Selects the polarity for ICDM pair channel input.
 * This field is write protected (depends on WPDIS/WPEN).
 * 0b - Low-active for ICDM. 
 * 1b - High-active for ICDM. 
 * @param pQdt the base address of the QDT instance.

 * @return uint8_t the value of PHZPOL.
 */
LOCAL_INLINE uint8_t QDT_HWA_GetPHZPOL(const QDT_Type *const pQdt)
{
    uint8_t u8TmpVal = (pQdt->POL & QDT_POL_PHZPOL_MASK) >> QDT_POL_PHZPOL_SHIFT;
    return u8TmpVal;
}


/**
 * @brief Set PHZPOL.
 * Phase Z Input Polarity
 * Selects the polarity for ICDM pair channel input.
 * This field is write protected (depends on WPDIS/WPEN).
 * 0b - Low-active for ICDM. 
 * 1b - High-active for ICDM. 
 * @param pQdt the base address of the QDT instance.

 * @param uint8_t u8Value PHZPOL value.
 */
LOCAL_INLINE void QDT_HWA_SetPHZPOL(QDT_Type *const pQdt, uint8_t u8Value)
{
    pQdt->POL = (pQdt->POL & ~QDT_POL_PHZPOL_MASK) | QDT_POL_PHZPOL(u8Value);
}



/**
 * @brief Get the value of PHBPOL.
 * Phase B Input Polarity
 * Selects the polarity for the quadrature decoder phase B input.
 * This field is write protected (depends on WPDIS/WPEN).
 * 0b - Normal polarity. 
 * 1b - Inverted polarity. 
 *        Phase B input signal is inverted before identifying the rising and falling edges of this signal.
 * @param pQdt the base address of the QDT instance.

 * @return uint8_t the value of PHBPOL.
 */
LOCAL_INLINE uint8_t QDT_HWA_GetPHBPOL(const QDT_Type *const pQdt)
{
    uint8_t u8TmpVal = (pQdt->POL & QDT_POL_PHBPOL_MASK) >> QDT_POL_PHBPOL_SHIFT;
    return u8TmpVal;
}


/**
 * @brief Set PHBPOL.
 * Phase B Input Polarity
 * Selects the polarity for the quadrature decoder phase B input.
 * This field is write protected (depends on WPDIS/WPEN).
 * 0b - Normal polarity. 
 * 1b - Inverted polarity. 
 *        Phase B input signal is inverted before identifying the rising and falling edges of this signal.
 * @param pQdt the base address of the QDT instance.

 * @param uint8_t u8Value PHBPOL value.
 */
LOCAL_INLINE void QDT_HWA_SetPHBPOL(QDT_Type *const pQdt, uint8_t u8Value)
{
    pQdt->POL = (pQdt->POL & ~QDT_POL_PHBPOL_MASK) | QDT_POL_PHBPOL(u8Value);
}



/**
 * @brief Get the value of PHAPOL.
 * Phase A Input Polarity
 * Selects the polarity for the quadrature decoder phase A input.
 * Selects the polarity for ICDM pair channel input.
 * This field is write protected (depends on WPDIS/WPEN).
 * 0b - Normal polarity for phase A; Low-active for ICDM. 
 * 1b - Inverted polarity for phase A; High-active for ICDM. 
 *        Phase A input signal is inverted before identifying the rising and falling edges of this signal.
 * @param pQdt the base address of the QDT instance.

 * @return uint8_t the value of PHAPOL.
 */
LOCAL_INLINE uint8_t QDT_HWA_GetPHAPOL(const QDT_Type *const pQdt)
{
    uint8_t u8TmpVal = (pQdt->POL & QDT_POL_PHAPOL_MASK) >> QDT_POL_PHAPOL_SHIFT;
    return u8TmpVal;
}


/**
 * @brief Set PHAPOL.
 * Phase A Input Polarity
 * Selects the polarity for the quadrature decoder phase A input.
 * Selects the polarity for ICDM pair channel input.
 * This field is write protected (depends on WPDIS/WPEN).
 * 0b - Normal polarity for phase A; Low-active for ICDM. 
 * 1b - Inverted polarity for phase A; High-active for ICDM. 
 *        Phase A input signal is inverted before identifying the rising and falling edges of this signal.
 * @param pQdt the base address of the QDT instance.

 * @param uint8_t u8Value PHAPOL value.
 */
LOCAL_INLINE void QDT_HWA_SetPHAPOL(QDT_Type *const pQdt, uint8_t u8Value)
{
    pQdt->POL = (pQdt->POL & ~QDT_POL_PHAPOL_MASK) | QDT_POL_PHAPOL(u8Value);
}

/**
 * @brief Set PHxPOL.
 * Phase x Input Polarity
 * Selects the polarity for the quadrature decoder phase X input.
 * Selects the polarity for ICDM pair channel input.
 * This field is write protected (depends on WPDIS/WPEN).
 * 0b - Normal polarity for phase X; Low-active for ICDM. 
 * 1b - Inverted polarity for phase X; High-active for ICDM. 
 *        Phase X input signal is inverted before identifying the rising and falling edges of this signal.
 * @param pQdt the base address of the QDT instance.
 * @param u8Channel QDT Channel.
 * @param uint8_t u8Value PHXPOL value.
 */
LOCAL_INLINE void QDT_HWA_SetPHXPOL(QDT_Type *const pQdt, uint8_t u8Channel, uint8_t u8Value)
{
    pQdt->POL = (pQdt->POL & ~(QDT_POL_PHAPOL_MASK << u8Channel)) | (QDT_POL_PHAPOL(u8Value) << u8Channel);
}

/**
 * @brief Get PHxPOL value.
 * Phase x Input Polarity
 * Selects the polarity for the quadrature decoder phase X input.
 * Selects the polarity for ICDM pair channel input.
 * This field is write protected (depends on WPDIS/WPEN).
 * 0b - Normal polarity for phase X; Low-active for ICDM. 
 * 1b - Inverted polarity for phase X; High-active for ICDM. 
 *        Phase X input signal is inverted before identifying the rising and falling edges of this signal.
 * @param pQdt the base address of the QDT instance.
 * @param u8Channel QDT Channel.
 * @return uint8_t u8Value PHXPOL value.
 */
LOCAL_INLINE uint8_t QDT_HWA_GetPHXPOL(QDT_Type *const pQdt, uint8_t u8Channel)
{
    uint8_t u8TmpVal = (uint8_t)((pQdt->POL & (QDT_POL_PHAPOL_MASK << u8Channel)) >> (QDT_POL_PHAPOL_SHIFT << u8Channel));
    return u8TmpVal;
}

/**
 * @brief Get the value of HOMEGFVAL.
 * HOME Input Filter
 * Selects the filter value for the HOME input. The filter is disabled when the value is zero.
 * The filter value is HOMEGFVAL*4
 * @param pQdt the base address of the QDT instance.

 * @return uint8_t the value of HOMEGFVAL.
 */
LOCAL_INLINE uint8_t QDT_HWA_GetHOMEGFVAL(const QDT_Type *const pQdt)
{
    uint8_t u8TmpVal = (pQdt->FILTER & QDT_FILTER_HOMEGFVAL_MASK) >> QDT_FILTER_HOMEGFVAL_SHIFT;
    return u8TmpVal;
}


/**
 * @brief Set HOMEGFVAL.
 * HOME Input Filter
 * Selects the filter value for the HOME input. The filter is disabled when the value is zero.
 * The filter value is HOMEGFVAL*4
 * @param pQdt the base address of the QDT instance.

 * @param uint8_t u8Value HOMEGFVAL value.
 */
LOCAL_INLINE void QDT_HWA_SetHOMEGFVAL(QDT_Type *const pQdt, uint8_t u8Value)
{
    pQdt->FILTER = (pQdt->FILTER & ~QDT_FILTER_HOMEGFVAL_MASK) | QDT_FILTER_HOMEGFVAL(u8Value);
}



/**
 * @brief Get the value of PHZGFVAL.
 * PHZ Input Filter
 * Selects the filter value for the PHZ input. The filter is disabled when the value is zero.
 * The filter value is PHZGFVAL*4
 * @param pQdt the base address of the QDT instance.

 * @return uint8_t the value of PHZGFVAL.
 */
LOCAL_INLINE uint8_t QDT_HWA_GetPHZGFVAL(const QDT_Type *const pQdt)
{
    uint8_t u8TmpVal = (pQdt->FILTER & QDT_FILTER_PHZGFVAL_MASK) >> QDT_FILTER_PHZGFVAL_SHIFT;
    return u8TmpVal;
}


/**
 * @brief Set PHZGFVAL.
 * PHZ Input Filter
 * Selects the filter value for the PHZ input. The filter is disabled when the value is zero.
 * The filter value is PHZGFVAL*4
 * @param pQdt the base address of the QDT instance.

 * @param uint8_t u8Value PHZGFVAL value.
 */
LOCAL_INLINE void QDT_HWA_SetPHZGFVAL(QDT_Type *const pQdt, uint8_t u8Value)
{
    pQdt->FILTER = (pQdt->FILTER & ~QDT_FILTER_PHZGFVAL_MASK) | QDT_FILTER_PHZGFVAL(u8Value);
}



/**
 * @brief Get the value of PHBGFVAL.
 * PHB Input Filter
 * Selects the filter value for the PHB input. The filter is disabled when the value is zero.
 * The filter value is PHBGFVAL*4
 * @param pQdt the base address of the QDT instance.

 * @return uint8_t the value of PHBGFVAL.
 */
LOCAL_INLINE uint8_t QDT_HWA_GetPHBGFVAL(const QDT_Type *const pQdt)
{
    uint8_t u8TmpVal = (pQdt->FILTER & QDT_FILTER_PHBGFVAL_MASK) >> QDT_FILTER_PHBGFVAL_SHIFT;
    return u8TmpVal;
}


/**
 * @brief Set PHBGFVAL.
 * PHB Input Filter
 * Selects the filter value for the PHB input. The filter is disabled when the value is zero.
 * The filter value is PHBGFVAL*4
 * @param pQdt the base address of the QDT instance.

 * @param uint8_t u8Value PHBGFVAL value.
 */
LOCAL_INLINE void QDT_HWA_SetPHBGFVAL(QDT_Type *const pQdt, uint8_t u8Value)
{
    pQdt->FILTER = (pQdt->FILTER & ~QDT_FILTER_PHBGFVAL_MASK) | QDT_FILTER_PHBGFVAL(u8Value);
}



/**
 * @brief Get the value of PHAGFVAL.
 * PHA Input Filter
 * Selects the filter value for the PHA input. The filter is disabled when the value is zero.
 * The filter value is PHAGFVAL*4
 * @param pQdt the base address of the QDT instance.

 * @return uint8_t the value of PHAGFVAL.
 */
LOCAL_INLINE uint8_t QDT_HWA_GetPHAGFVAL(const QDT_Type *const pQdt)
{
    uint8_t u8TmpVal = (pQdt->FILTER & QDT_FILTER_PHAGFVAL_MASK) >> QDT_FILTER_PHAGFVAL_SHIFT;
    return u8TmpVal;
}


/**
 * @brief Set PHAGFVAL.
 * PHA Input Filter
 * Selects the filter value for the PHA input. The filter is disabled when the value is zero.
 * The filter value is PHAGFVAL*4
 * @param pQdt the base address of the QDT instance.

 * @param uint8_t u8Value PHAGFVAL value.
 */
LOCAL_INLINE void QDT_HWA_SetPHAGFVAL(QDT_Type *const pQdt, uint8_t u8Value)
{
    pQdt->FILTER = (pQdt->FILTER & ~QDT_FILTER_PHAGFVAL_MASK) | QDT_FILTER_PHAGFVAL(u8Value);
}



/**
 * @brief Get the value of FLTPS.
 * Filter Prescaler
 * HOME/PHZ/PHB/PHA input glitch filters clock prescaler
 * Writing to the bits FLTPS has immediate effect.
 * 0000b - Divide by 1 
 * 0001b - Divide by 2
 * ...
 * 1111b - Divide by 16
 * @param pQdt the base address of the QDT instance.

 * @return uint8_t the value of FLTPS.
 */
LOCAL_INLINE uint8_t QDT_HWA_GetFLTPS(const QDT_Type *const pQdt)
{
    uint8_t u8TmpVal = (pQdt->FILTER & QDT_FILTER_FLTPS_MASK) >> QDT_FILTER_FLTPS_SHIFT;
    return u8TmpVal;
}


/**
 * @brief Set FLTPS.
 * Filter Prescaler
 * HOME/PHZ/PHB/PHA input glitch filters clock prescaler
 * Writing to the bits FLTPS has immediate effect.
 * 0000b - Divide by 1 
 * 0001b - Divide by 2
 * ...
 * 1111b - Divide by 16
 * @param pQdt the base address of the QDT instance.

 * @param uint8_t u8Value FLTPS value.
 */
LOCAL_INLINE void QDT_HWA_SetFLTPS(QDT_Type *const pQdt, uint8_t u8Value)
{
    pQdt->FILTER = (pQdt->FILTER & ~QDT_FILTER_FLTPS_MASK) | QDT_FILTER_FLTPS(u8Value);
}





/**
 * @brief Get the value of WDOGVAL.
 * WDOG Timeout Value
 * WDOG is disabled if WDOGVAL = 0
 * @param pQdt the base address of the QDT instance.

 * @return uint16_t the value of WDOGVAL.
 */
LOCAL_INLINE uint16_t QDT_HWA_GetWDOGVAL(const QDT_Type *const pQdt)
{
    uint16_t u16TmpVal = (pQdt->WDOG & QDT_WDOG_WDOGVAL_MASK) >> QDT_WDOG_WDOGVAL_SHIFT;
    return u16TmpVal;
}


/**
 * @brief Set WDOGVAL.
 * WDOG Timeout Value
 * WDOG is disabled if WDOGVAL = 0
 * @param pQdt the base address of the QDT instance.

 * @param uint16_t u8Value WDOGVAL value.
 */
LOCAL_INLINE void QDT_HWA_SetWDOGVAL(QDT_Type *const pQdt, uint16_t u16Value)
{
    pQdt->WDOG = (pQdt->WDOG & ~QDT_WDOG_WDOGVAL_MASK) | QDT_WDOG_WDOGVAL(u16Value);
}



/**
 * @brief Get the value of WDOGF.
 * WDOG Timerout Flag
 * When the WDOG counter passes the value in the WDOGVAL register, this bit asserted.
 * The WDOGF bit is cleared by reading the WDOG register while WDOGF is set and then writing a 0 to WDOGF bit. Writing a 1 to WDOGF has no effect.
 * If another WDOG Timeout occurs between the read and write operations, the write operation has no effect; therefore, WDOGF remains set indicating an overflow has occurred. In this case, a WDOGF interrupt request is not lost due to the clearing sequence for a previous WDOGF.
 * 0b - WODG counter has not timeout. 
 * 1b - WDOG counter has timeout.
 * @param pQdt the base address of the QDT instance.

 * @return uint8_t the value of WDOGF.
 */
LOCAL_INLINE uint8_t QDT_HWA_GetWDOGF(const QDT_Type *const pQdt)
{
    uint8_t u8TmpVal = (pQdt->WDOG & QDT_WDOG_WDOGF_MASK) >> QDT_WDOG_WDOGF_SHIFT;
    return u8TmpVal;
}


/**
 * @brief Clear WDOGF.
 * WDOG Timerout Flag
 * When the WDOG counter passes the value in the WDOGVAL register, this bit asserted.
 * The WDOGF bit is cleared by reading the WDOG register while WDOGF is set and then writing a 0 to WDOGF bit. Writing a 1 to WDOGF has no effect.
 * If another WDOG Timeout occurs between the read and write operations, the write operation has no effect; therefore, WDOGF remains set indicating an overflow has occurred. In this case, a WDOGF interrupt request is not lost due to the clearing sequence for a previous WDOGF.
 * 0b - WODG counter has not timeout. 
 * 1b - WDOG counter has timeout.
 * @param pQdt the base address of the QDT instance.

 */
LOCAL_INLINE void QDT_HWA_ClearWDOGF(QDT_Type *const pQdt)
{
    pQdt->WDOG &= ~QDT_WDOG_WDOGF_MASK;
}


/**
 * @brief Get the value of WDOGIE.
 * WDOG Timerout Interrupt Enable
 * 0b - Disable WDOGF interrupts. 
 * 1b - Enable WDOGF interrupts. An interrupt is generated when WDOGF asserted.
 * @param pQdt the base address of the QDT instance.

 * @return uint8_t the value of WDOGIE.
 */
LOCAL_INLINE uint8_t QDT_HWA_GetWDOGIE(const QDT_Type *const pQdt)
{
    uint8_t u8TmpVal = (pQdt->WDOG & QDT_WDOG_WDOGIE_MASK) >> QDT_WDOG_WDOGIE_SHIFT;
    return u8TmpVal;
}


/**
 * @brief Set WDOGIE.
 * WDOG Timerout Interrupt Enable
 * 0b - Disable WDOGF interrupts. 
 * 1b - Enable WDOGF interrupts. An interrupt is generated when WDOGF asserted.
 * @param pQdt the base address of the QDT instance.

 * @param uint8_t u8Value WDOGIE value.
 */
LOCAL_INLINE void QDT_HWA_SetWDOGIE(QDT_Type *const pQdt, uint8_t u8Value)
{
    pQdt->WDOG = (pQdt->WDOG & ~QDT_WDOG_WDOGIE_MASK) | QDT_WDOG_WDOGIE(u8Value);
}



/**
 * @brief Get the value of WDOGEN.
 * WDOG Enable
 * @param pQdt the base address of the QDT instance.

 * @return uint8_t the value of WDOGEN.
 */
LOCAL_INLINE uint8_t QDT_HWA_GetWDOGEN(const QDT_Type *const pQdt)
{
    uint8_t u8TmpVal = (pQdt->WDOG & QDT_WDOG_WDOGEN_MASK) >> QDT_WDOG_WDOGEN_SHIFT;
    return u8TmpVal;
}


/**
 * @brief Set WDOGEN.
 * WDOG Enable
 * @param pQdt the base address of the QDT instance.

 * @param uint8_t u8Value WDOGEN value.
 */
LOCAL_INLINE void QDT_HWA_SetWDOGEN(QDT_Type *const pQdt, uint8_t u8Value)
{
    pQdt->WDOG = (pQdt->WDOG & ~QDT_WDOG_WDOGEN_MASK) | QDT_WDOG_WDOGEN(u8Value);
}





/**
 * @brief Get the value of ICEXP_NUM_ICM_ECNT.
 * Edge number counter in even channel (ICM_ECNT), read, write 8'h5a clear
 * Expect number of edge in odd channel (ICEXP_NUM) read-write (rw)
 * This field is write protected (depends on WPDIS/WPEN).
 * @param pQdt the base address of the QDT instance.
* @param u8Channel QDT Channel.
 * @return uint8_t the value of ICEXP_NUM_ICM_ECNT.
 */
LOCAL_INLINE uint8_t QDT_HWA_GetICEXP_NUM_ICM_ECNT(const QDT_Type *const pQdt, uint8_t u8Channel)
{
    uint8_t u8TmpVal = (pQdt->Channel[u8Channel].CSC & QDT_CSC_ICEXP_NUM_ICM_ECNT_MASK) >> QDT_CSC_ICEXP_NUM_ICM_ECNT_SHIFT;
    return u8TmpVal;
}

/**
 * @brief Clear CSC register.
 * @param pQdt the base address of the QDT instance.
 * @param u8Channel QDT Channel.
 */
LOCAL_INLINE void QDT_HWA_ClearCSC(QDT_Type *const pQdt, uint8_t u8Channel)
{
    pQdt->Channel[u8Channel].CSC = 0U;
}

/**
 * @brief Set ICEXP_NUM_ICM_ECNT.
 * Edge number counter in even channel (ICM_ECNT), read, write 8'h5a clear
 * Expect number of edge in odd channel (ICEXP_NUM) read-write (rw)
 * This field is write protected (depends on WPDIS/WPEN).
 * @param pQdt the base address of the QDT instance.
* @param u8Channel QDT Channel.
 * @param uint8_t u8Value ICEXP_NUM_ICM_ECNT value.
 */
LOCAL_INLINE void QDT_HWA_SetICEXP_NUM_ICM_ECNT(QDT_Type *const pQdt, uint8_t u8Channel, uint8_t u8Value)
{
    pQdt->Channel[u8Channel].CSC = (pQdt->Channel[u8Channel].CSC & ~QDT_CSC_ICEXP_NUM_ICM_ECNT_MASK) | QDT_CSC_ICEXP_NUM_ICM_ECNT(u8Value);
}



/**
 * @brief Get the value of ICM_SIG_REG.
 * Re-start a measurement in Single Measurement Mode
 * Valid in EVEN Channel
 * @param pQdt the base address of the QDT instance.
* @param u8Channel QDT Channel.
 * @return uint8_t the value of ICM_SIG_REG.
 */
LOCAL_INLINE uint8_t QDT_HWA_GetICM_SIG_REG(const QDT_Type *const pQdt, uint8_t u8Channel)
{
    uint8_t u8TmpVal = (pQdt->Channel[u8Channel].CSC & QDT_CSC_ICM_SIG_REG_MASK) >> QDT_CSC_ICM_SIG_REG_SHIFT;
    return u8TmpVal;
}


/**
 * @brief Set ICM_SIG_REG.
 * Re-start a measurement in Single Measurement Mode
 * Valid in EVEN Channel
 * @param pQdt the base address of the QDT instance.
* @param u8Channel QDT Channel.
 * @param uint8_t u8Value ICM_SIG_REG value.
 */
LOCAL_INLINE void QDT_HWA_SetICM_SIG_REG(QDT_Type *const pQdt, uint8_t u8Channel, uint8_t u8Value)
{
    pQdt->Channel[u8Channel].CSC = (pQdt->Channel[u8Channel].CSC & ~QDT_CSC_ICM_SIG_REG_MASK) | QDT_CSC_ICM_SIG_REG(u8Value);
}



/**
 * @brief Get the value of ICDPM_START.
 * Start in ICDM & ICPM 
 * (value in ODD Channel is the same as EVEN)
 * This field is write protected (depends on WPDIS/WPEN).
 * 0b – the channel starts measuring after the first edge is detected.
 * 1b – the measurement starts immediately after activating the channel by ICDM=1 or ICPM=1.
 * @param pQdt the base address of the QDT instance.
* @param u8Channel QDT Channel.
 * @return uint8_t the value of ICDPM_START.
 */
LOCAL_INLINE uint8_t QDT_HWA_GetICDPM_START(const QDT_Type *const pQdt, uint8_t u8Channel)
{
    uint8_t u8TmpVal = (pQdt->Channel[u8Channel].CSC & QDT_CSC_ICDPM_START_MASK) >> QDT_CSC_ICDPM_START_SHIFT;
    return u8TmpVal;
}


/**
 * @brief Set ICDPM_START.
 * Start in ICDM & ICPM 
 * (value in ODD Channel is the same as EVEN)
 * This field is write protected (depends on WPDIS/WPEN).
 * 0b – the channel starts measuring after the first edge is detected.
 * 1b – the measurement starts immediately after activating the channel by ICDM=1 or ICPM=1.
 * @param pQdt the base address of the QDT instance.
* @param u8Channel QDT Channel.
 * @param uint8_t u8Value ICDPM_START value.
 */
LOCAL_INLINE void QDT_HWA_SetICDPM_START(QDT_Type *const pQdt, uint8_t u8Channel, uint8_t u8Value)
{
    pQdt->Channel[u8Channel].CSC = (pQdt->Channel[u8Channel].CSC & ~QDT_CSC_ICDPM_START_MASK) | QDT_CSC_ICDPM_START(u8Value);
}



/**
 * @brief Get the value of ICM_CONT.
 * The measurement is single or continuous 
 * (value in ODD Channel is the same as EVEN)
 * This field is write protected (depends on WPDIS/WPEN).
 * 0b – single mode.
 * 1b – continuous mode.
 * @param pQdt the base address of the QDT instance.
* @param u8Channel QDT Channel.
 * @return uint8_t the value of ICM_CONT.
 */
LOCAL_INLINE uint8_t QDT_HWA_GetICM_CONT(const QDT_Type *const pQdt, uint8_t u8Channel)
{
    uint8_t u8TmpVal = (pQdt->Channel[u8Channel].CSC & QDT_CSC_ICM_CONT_MASK) >> QDT_CSC_ICM_CONT_SHIFT;
    return u8TmpVal;
}


/**
 * @brief Set ICM_CONT.
 * The measurement is single or continuous 
 * (value in ODD Channel is the same as EVEN)
 * This field is write protected (depends on WPDIS/WPEN).
 * 0b – single mode.
 * 1b – continuous mode.
 * @param pQdt the base address of the QDT instance.
* @param u8Channel QDT Channel.
 * @param uint8_t u8Value ICM_CONT value.
 */
LOCAL_INLINE void QDT_HWA_SetICM_CONT(QDT_Type *const pQdt, uint8_t u8Channel, uint8_t u8Value)
{
    pQdt->Channel[u8Channel].CSC = (pQdt->Channel[u8Channel].CSC & ~QDT_CSC_ICM_CONT_MASK) | QDT_CSC_ICM_CONT(u8Value);
}



/**
 * @brief Get the value of ICM_MODE.
 * Channel Input Measurement Mode 
 * (value in ODD Channel is the same as EVEN)
 * This field is write protected (depends on WPDIS/WPEN).
 * 001b – select ICDM mode.
 * 010b – select ICPM mode.
 * 011b – select ICENM mode.
 * 100b – select ICEXPENM mode.
 * @param pQdt the base address of the QDT instance.
* @param u8Channel QDT Channel.
 * @return uint8_t the value of ICM_MODE.
 */
LOCAL_INLINE uint8_t QDT_HWA_GetICM_MODE(const QDT_Type *const pQdt, uint8_t u8Channel)
{
    uint8_t u8TmpVal = (pQdt->Channel[u8Channel].CSC & QDT_CSC_ICM_MODE_MASK) >> QDT_CSC_ICM_MODE_SHIFT;
    return u8TmpVal;
}


/**
 * @brief Set ICM_MODE.
 * Channel Input Measurement Mode 
 * (value in ODD Channel is the same as EVEN)
 * This field is write protected (depends on WPDIS/WPEN).
 * 001b – select ICDM mode.
 * 010b – select ICPM mode.
 * 011b – select ICENM mode.
 * 100b – select ICEXPENM mode.
 * @param pQdt the base address of the QDT instance.
* @param u8Channel QDT Channel.
 * @param uint8_t u8Value ICM_MODE value.
 */
LOCAL_INLINE void QDT_HWA_SetICM_MODE(QDT_Type *const pQdt, uint8_t u8Channel, uint8_t u8Value)
{
    pQdt->Channel[u8Channel].CSC = (pQdt->Channel[u8Channel].CSC & ~QDT_CSC_ICM_MODE_MASK) | QDT_CSC_ICM_MODE(u8Value);
}



/**
 * @brief Get the value of REVMODE.
 * Match point is POSCNT or REVCNT
 * 0b – Match point is POSCNT (CV==POSCNT). 
 * 1b – Match point is REVCNT (CV==REVCNT).
 * @param pQdt the base address of the QDT instance.
* @param u8Channel QDT Channel.
 * @return uint8_t the value of REVMODE.
 */
LOCAL_INLINE uint8_t QDT_HWA_GetREVMODE(const QDT_Type *const pQdt, uint8_t u8Channel)
{
    uint8_t u8TmpVal = (pQdt->Channel[u8Channel].CSC & QDT_CSC_REVMODE_MASK) >> QDT_CSC_REVMODE_SHIFT;
    return u8TmpVal;
}


/**
 * @brief Set REVMODE.
 * Match point is POSCNT or REVCNT
 * 0b – Match point is POSCNT (CV==POSCNT). 
 * 1b – Match point is REVCNT (CV==REVCNT).
 * @param pQdt the base address of the QDT instance.
* @param u8Channel QDT Channel.
 * @param uint8_t u8Value REVMODE value.
 */
LOCAL_INLINE void QDT_HWA_SetREVMODE(QDT_Type *const pQdt, uint8_t u8Channel, uint8_t u8Value)
{
    pQdt->Channel[u8Channel].CSC = (pQdt->Channel[u8Channel].CSC & ~QDT_CSC_REVMODE_MASK) | QDT_CSC_REVMODE(u8Value);
}



/**
 * @brief Get the value of CHTRIG.
 * Channel (n) Match Trigger Enable
 * Enables the generation of the match Trigger when QDT counter (also is POSCNT) = CV if channel is in quad mode.
 * This field is write protected (depends on WPDIS/WPEN).
 * 0b - The generation of this match Trigger is disabled. 
 * 1b - The generation of this match Trigger is enabled.
 * @param pQdt the base address of the QDT instance.
* @param u8Channel QDT Channel.
 * @return uint8_t the value of CHTRIG.
 */
LOCAL_INLINE uint8_t QDT_HWA_GetCHTRIG(const QDT_Type *const pQdt, uint8_t u8Channel)
{
    uint8_t u8TmpVal = (pQdt->Channel[u8Channel].CSC & QDT_CSC_CHTRIG_MASK) >> QDT_CSC_CHTRIG_SHIFT;
    return u8TmpVal;
}


/**
 * @brief Set CHTRIG.
 * Channel (n) Match Trigger Enable
 * Enables the generation of the match Trigger when QDT counter (also is POSCNT) = CV if channel is in quad mode.
 * This field is write protected (depends on WPDIS/WPEN).
 * 0b - The generation of this match Trigger is disabled. 
 * 1b - The generation of this match Trigger is enabled.
 * @param pQdt the base address of the QDT instance.
* @param u8Channel QDT Channel.
 * @param uint8_t u8Value CHTRIG value.
 */
LOCAL_INLINE void QDT_HWA_SetCHTRIG(QDT_Type *const pQdt, uint8_t u8Channel, uint8_t u8Value)
{
    pQdt->Channel[u8Channel].CSC = (pQdt->Channel[u8Channel].CSC & ~QDT_CSC_CHTRIG_MASK) | QDT_CSC_CHTRIG(u8Value);
}



/**
 * @brief Get the value of CHIS.
 * Channel (n) Input State
 * The CHIS bit has the value of the channel (n) input before the double-sampling.
 * 0b - The channel (n) input is zero. 
 * 1b - The channel (n) input is one.
 * @param pQdt the base address of the QDT instance.
* @param u8Channel QDT Channel.
 * @return uint8_t the value of CHIS.
 */
LOCAL_INLINE uint8_t QDT_HWA_GetCHIS(const QDT_Type *const pQdt, uint8_t u8Channel)
{
    uint8_t u8TmpVal = (pQdt->Channel[u8Channel].CSC & QDT_CSC_CHIS_MASK) >> QDT_CSC_CHIS_SHIFT;
    return u8TmpVal;
}



/**
 * @brief Get the value of FLTCHIS.
 * Channel (n) Input Filter State
 * The CHIS bit has the value of the channel (n) input after the double-sampling and the filtering (if the channel (n) filter is enabled).
 * 0b - The channel (n) input is zero. 
 * 1b - The channel (n) input is one.
 * @param pQdt the base address of the QDT instance.
* @param u8Channel QDT Channel.
 * @return uint8_t the value of FLTCHIS.
 */
LOCAL_INLINE uint8_t QDT_HWA_GetFLTCHIS(const QDT_Type *const pQdt, uint8_t u8Channel)
{
    uint8_t u8TmpVal = (pQdt->Channel[u8Channel].CSC & QDT_CSC_FLTCHIS_MASK) >> QDT_CSC_FLTCHIS_SHIFT;
    return u8TmpVal;
}



/**
 * @brief Get the value of CHF.
 * Channel (n) Flag
 * Set by hardware when an event occurs on the channel (n) if channel is in input capture mode. 
 * Also set by hardware when channel value is equal to POSCNT (REVMODE=0) or REVCNT (REVMODE=1) if channel is in quad mode. 
 * CHF is cleared by reading the CSC register while CHF is set and then writing a 0 to the CHF bit. 
 * Writing a 1 to CHF has no effect.
 * @param pQdt the base address of the QDT instance.
* @param u8Channel QDT Channel.
 * @return uint8_t the value of CHF.
 */
LOCAL_INLINE uint8_t QDT_HWA_GetCHF(const QDT_Type *const pQdt, uint8_t u8Channel)
{
    uint8_t u8TmpVal = (pQdt->Channel[u8Channel].CSC & QDT_CSC_CHF_MASK) >> QDT_CSC_CHF_SHIFT;
    return u8TmpVal;
}


/**
 * @brief Clear CHF.
 * Channel (n) Flag
 * Set by hardware when an event occurs on the channel (n) if channel is in input capture mode. 
 * Also set by hardware when channel value is equal to POSCNT (REVMODE=0) or REVCNT (REVMODE=1) if channel is in quad mode. 
 * CHF is cleared by reading the CSC register while CHF is set and then writing a 0 to the CHF bit. 
 * Writing a 1 to CHF has no effect.
 * @param pQdt the base address of the QDT instance.
* @param u8Channel QDT Channel.
 */
LOCAL_INLINE void QDT_HWA_ClearCHF(QDT_Type *const pQdt, uint8_t u8Channel)
{
    pQdt->Channel[u8Channel].CSC &= ~QDT_CSC_CHF_MASK;
}


/**
 * @brief Get the value of CHIE.
 * Channel (n) Interrupt Enable
 * 0b - Disable channel (n) interrupt.
 * 1b - Enable channel (n) interrupt.
 * @param pQdt the base address of the QDT instance.
* @param u8Channel QDT Channel.
 * @return uint8_t the value of CHIE.
 */
LOCAL_INLINE uint8_t QDT_HWA_GetCHIE(const QDT_Type *const pQdt, uint8_t u8Channel)
{
    uint8_t u8TmpVal = (pQdt->Channel[u8Channel].CSC & QDT_CSC_CHIE_MASK) >> QDT_CSC_CHIE_SHIFT;
    return u8TmpVal;
}


/**
 * @brief Set CHIE.
 * Channel (n) Interrupt Enable
 * 0b - Disable channel (n) interrupt.
 * 1b - Enable channel (n) interrupt.
 * @param pQdt the base address of the QDT instance.
* @param u8Channel QDT Channel.
 * @param uint8_t u8Value CHIE value.
 */
LOCAL_INLINE void QDT_HWA_SetCHIE(QDT_Type *const pQdt, uint8_t u8Channel, uint8_t u8Value)
{
    pQdt->Channel[u8Channel].CSC = (pQdt->Channel[u8Channel].CSC & ~QDT_CSC_CHIE_MASK) | QDT_CSC_CHIE(u8Value);
}



/**
 * @brief Get the value of ELSB.
 * Channel (n) Edge or Level Select
 * This field is write protected (depends on WPDIS/WPEN).
 * @param pQdt the base address of the QDT instance.
* @param u8Channel QDT Channel.
 * @return uint8_t the value of ELSB.
 */
LOCAL_INLINE uint8_t QDT_HWA_GetELSB(const QDT_Type *const pQdt, uint8_t u8Channel)
{
    uint8_t u8TmpVal = (pQdt->Channel[u8Channel].CSC & QDT_CSC_ELSB_MASK) >> QDT_CSC_ELSB_SHIFT;
    return u8TmpVal;
}


/**
 * @brief Set ELSB.
 * Channel (n) Edge or Level Select
 * This field is write protected (depends on WPDIS/WPEN).
 * @param pQdt the base address of the QDT instance.
* @param u8Channel QDT Channel.
 * @param uint8_t u8Value ELSB value.
 */
LOCAL_INLINE void QDT_HWA_SetELSB(QDT_Type *const pQdt, uint8_t u8Channel, uint8_t u8Value)
{
    pQdt->Channel[u8Channel].CSC = (pQdt->Channel[u8Channel].CSC & ~QDT_CSC_ELSB_MASK) | QDT_CSC_ELSB(u8Value);
}



/**
 * @brief Get the value of ELSA.
 * Channel (n) Edge or Level Select
 * This field is write protected (depends on WPDIS/WPEN).
 * @param pQdt the base address of the QDT instance.
* @param u8Channel QDT Channel.
 * @return uint8_t the value of ELSA.
 */
LOCAL_INLINE uint8_t QDT_HWA_GetELSA(const QDT_Type *const pQdt, uint8_t u8Channel)
{
    uint8_t u8TmpVal = (pQdt->Channel[u8Channel].CSC & QDT_CSC_ELSA_MASK) >> QDT_CSC_ELSA_SHIFT;
    return u8TmpVal;
}


/**
 * @brief Set ELSA.
 * Channel (n) Edge or Level Select
 * This field is write protected (depends on WPDIS/WPEN).
 * @param pQdt the base address of the QDT instance.
* @param u8Channel QDT Channel.
 * @param uint8_t u8Value ELSA value.
 */
LOCAL_INLINE void QDT_HWA_SetELSA(QDT_Type *const pQdt, uint8_t u8Channel, uint8_t u8Value)
{
    pQdt->Channel[u8Channel].CSC = (pQdt->Channel[u8Channel].CSC & ~QDT_CSC_ELSA_MASK) | QDT_CSC_ELSA(u8Value);
}



/**
 * @brief Get the value of ICRST.
 * QDT counter reset is driven by the selected event of the channel (n) in the Input Capture mode. 
 * This field is write protected (depends on WPDIS/WPEN).
 * 0b - QDT counter is not reset when the selected channel (n) input event is detected. 
 * 1b - QDT counter is reset when the selected channel (n) input event is detected.
 * @param pQdt the base address of the QDT instance.
* @param u8Channel QDT Channel.
 * @return uint8_t the value of ICRST.
 */
LOCAL_INLINE uint8_t QDT_HWA_GetICRST(const QDT_Type *const pQdt, uint8_t u8Channel)
{
    uint8_t u8TmpVal = (pQdt->Channel[u8Channel].CSC & QDT_CSC_ICRST_MASK) >> QDT_CSC_ICRST_SHIFT;
    return u8TmpVal;
}


/**
 * @brief Set ICRST.
 * QDT counter reset is driven by the selected event of the channel (n) in the Input Capture mode. 
 * This field is write protected (depends on WPDIS/WPEN).
 * 0b - QDT counter is not reset when the selected channel (n) input event is detected. 
 * 1b - QDT counter is reset when the selected channel (n) input event is detected.
 * @param pQdt the base address of the QDT instance.
* @param u8Channel QDT Channel.
 * @param uint8_t u8Value ICRST value.
 */
LOCAL_INLINE void QDT_HWA_SetICRST(QDT_Type *const pQdt, uint8_t u8Channel, uint8_t u8Value)
{
    pQdt->Channel[u8Channel].CSC = (pQdt->Channel[u8Channel].CSC & ~QDT_CSC_ICRST_MASK) | QDT_CSC_ICRST(u8Value);
}





/**
 * @brief Get the value of CV.
 * Channel Value
 * Captured QDT counter value of the input modes or the match value for the quadrature decoder modes
 * @param pQdt the base address of the QDT instance.
* @param u8Channel QDT Channel.
 * @return uint32_t the value of CV.
 */
LOCAL_INLINE uint32_t QDT_HWA_GetCV(const QDT_Type *const pQdt, uint8_t u8Channel)
{
    uint32_t u32TmpVal = (pQdt->Channel[u8Channel].CV & QDT_CV_CV_MASK) >> QDT_CV_CV_SHIFT;
    return u32TmpVal;
}


/**
 * @brief Set CV.
 * Channel Value
 * Captured QDT counter value of the input modes or the match value for the quadrature decoder modes
 * @param pQdt the base address of the QDT instance.
* @param u8Channel QDT Channel.
 * @param uint32_t u8Value CV value.
 */
LOCAL_INLINE void QDT_HWA_SetCV(QDT_Type *const pQdt, uint8_t u8Channel, uint32_t u32Value)
{
    pQdt->Channel[u8Channel].CV = (pQdt->Channel[u8Channel].CV & ~QDT_CV_CV_MASK) | QDT_CV_CV(u32Value);
}





/**
 * @brief Get the value of REVCNT.
 * Revolution Counter
 * @param pQdt the base address of the QDT instance.

 * @return uint16_t the value of REVCNT.
 */
LOCAL_INLINE uint16_t QDT_HWA_GetREVCNT(const QDT_Type *const pQdt)
{
    uint16_t u16TmpVal = (pQdt->REVCNT & QDT_REVCNT_REVCNT_MASK) >> QDT_REVCNT_REVCNT_SHIFT;
    return u16TmpVal;
}





/**
 * @brief Get the value of REVCNT_HOLD.
 * Revolution Hold Counter
 * @param pQdt the base address of the QDT instance.

 * @return uint16_t the value of REVCNT_HOLD.
 */
LOCAL_INLINE uint16_t QDT_HWA_GetREVCNT_HOLD(const QDT_Type *const pQdt)
{
    uint16_t u16TmpVal = (pQdt->REVCNT_HOLD & QDT_REVCNT_HOLD_REVCNT_HOLD_MASK) >> QDT_REVCNT_HOLD_REVCNT_HOLD_SHIFT;
    return u16TmpVal;
}





/**
 * @brief Get the value of POSCNT.
 * Position Counter
 * Write action will reset Position Counter
 * @param pQdt the base address of the QDT instance.

 * @return uint32_t the value of POSCNT.
 */
LOCAL_INLINE uint32_t QDT_HWA_GetPOSCNT(const QDT_Type *const pQdt)
{
    uint32_t u32TmpVal = (pQdt->POSCNT & QDT_POSCNT_POSCNT_MASK) >> QDT_POSCNT_POSCNT_SHIFT;
    return u32TmpVal;
}


/**
 * @brief Set POSCNT.
 * Position Counter
 * Write action will reset Position Counter
 * @param pQdt the base address of the QDT instance.

 * @param uint32_t u8Value POSCNT value.
 */
LOCAL_INLINE void QDT_HWA_SetPOSCNT(QDT_Type *const pQdt, uint32_t u8Value)
{
    pQdt->POSCNT = (pQdt->POSCNT & ~QDT_POSCNT_POSCNT_MASK) | QDT_POSCNT_POSCNT(u8Value);
}





/**
 * @brief Get the value of POSCNT_HOLD.
 * Position Hold Counter
 * @param pQdt the base address of the QDT instance.

 * @return uint32_t the value of POSCNT_HOLD.
 */
LOCAL_INLINE uint32_t QDT_HWA_GetPOSCNT_HOLD(const QDT_Type *const pQdt)
{
    uint32_t u32TmpVal = (pQdt->POSCNT_HOLD & QDT_POSCNT_HOLD_POSCNT_HOLD_MASK) >> QDT_POSCNT_HOLD_POSCNT_HOLD_SHIFT;
    return u32TmpVal;
}





/**
 * @brief Get the value of POSDCNT.
 * Position Difference Counter
 * @param pQdt the base address of the QDT instance.

 * @return uint16_t the value of POSDCNT.
 */
LOCAL_INLINE uint16_t QDT_HWA_GetPOSDCNT(const QDT_Type *const pQdt)
{
    uint16_t u16TmpVal = (pQdt->POSDCNT & QDT_POSDCNT_POSDCNT_MASK) >> QDT_POSDCNT_POSDCNT_SHIFT;
    return u16TmpVal;
}





/**
 * @brief Get the value of POSDCNT_HOLD.
 * Position Difference Hold Counter
 * @param pQdt the base address of the QDT instance.

 * @return uint16_t the value of POSDCNT_HOLD.
 */
LOCAL_INLINE uint16_t QDT_HWA_GetPOSDCNT_HOLD(const QDT_Type *const pQdt)
{
    uint16_t u16TmpVal = (pQdt->POSDCNT_HOLD & QDT_POSDCNT_HOLD_POSDCNT_HOLD_MASK) >> QDT_POSDCNT_HOLD_POSDCNT_HOLD_SHIFT;
    return u16TmpVal;
}





/**
 * @brief Get the value of LECNT.
 * Last PHA/B Edge Time Counter
 * @param pQdt the base address of the QDT instance.

 * @return uint16_t the value of LECNT.
 */
LOCAL_INLINE uint16_t QDT_HWA_GetLECNT(const QDT_Type *const pQdt)
{
    uint16_t u16TmpVal = (pQdt->LECNT & QDT_LECNT_LECNT_MASK) >> QDT_LECNT_LECNT_SHIFT;
    return u16TmpVal;
}





/**
 * @brief Get the value of LECNT_HOLD.
 * Last PHA/B Edge Time Hold Counter
 * @param pQdt the base address of the QDT instance.

 * @return uint16_t the value of LECNT_HOLD.
 */
LOCAL_INLINE uint16_t QDT_HWA_GetLECNT_HOLD(const QDT_Type *const pQdt)
{
    uint16_t u16TmpVal = (pQdt->LECNT_HOLD & QDT_LECNT_HOLD_LECNT_HOLD_MASK) >> QDT_LECNT_HOLD_LECNT_HOLD_SHIFT;
    return u16TmpVal;
}





/**
 * @brief Get the value of POSDTMRCNT.
 * Position Difference Time Counter
 * @param pQdt the base address of the QDT instance.

 * @return uint16_t the value of POSDTMRCNT.
 */
LOCAL_INLINE uint16_t QDT_HWA_GetPOSDTMRCNT(const QDT_Type *const pQdt)
{
    uint16_t u16TmpVal = (pQdt->POSDTMRCNT & QDT_POSDTMRCNT_POSDTMRCNT_MASK) >> QDT_POSDTMRCNT_POSDTMRCNT_SHIFT;
    return u16TmpVal;
}





/**
 * @brief Get the value of POSDTMRCNT_HOLD.
 * Position Difference Time Hold Counter
 * @param pQdt the base address of the QDT instance.

 * @return uint16_t the value of POSDTMRCNT_HOLD.
 */
LOCAL_INLINE uint16_t QDT_HWA_GetPOSDTMRCNT_HOLD(const QDT_Type *const pQdt)
{
    uint16_t u16TmpVal = (pQdt->POSDTMRCNT_HOLD & QDT_POSDTMRCNT_HOLD_POSDTMRCNT_HOLD_MASK) >> QDT_POSDTMRCNT_HOLD_POSDTMRCNT_HOLD_SHIFT;
    return u16TmpVal;
}

#endif


/** @}*/

#endif /* _HWA_QDT_H_ */
