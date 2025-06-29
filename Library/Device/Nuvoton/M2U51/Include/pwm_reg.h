/**************************************************************************//**
 * @file     pwm_reg.h
 * @version  V1.00
 * @brief    SPI register definition header file
 *
 * SPDX-License-Identifier: Apache-2.0
 * @copyright (C) 2017-2020 Nuvoton Technology Corp. All rights reserved.
 *****************************************************************************/
#ifndef __PWM_REG_H__
#define __PWM_REG_H__

#if defined ( __CC_ARM   )
#pragma anon_unions
#endif

/**
   @addtogroup REGISTER Control Register
   @{
*/

/*---------------------- Pulse Width Modulation Controller -------------------------*/
/**
    @addtogroup PWM Pulse Width Modulation Controller(PWM)
    Memory Mapped Structure for PWM Controller
@{ */

typedef struct
{
    /**
     * @var CAPDAT_T::RCAPDAT
     * Offset: 0x20C~0x238  PWM Rising Capture Data Register 0~5
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[15:0]  |RCAPDAT   |PWM Rising Capture Data (Read Only)
     * |        |          |When rising capture condition happened, the PWM counter value will be saved in this register.
     * @var CAPDAT_T::FCAPDAT
     * Offset: 0x210  PWM Falling Capture Data Register 0~5
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[15:0]  |FCAPDAT   |PWWM Falling Capture Data (Read Only)
     * |        |          |When falling capture condition happened, the PWWM counter value will be saved in this register.
     */
    __IO uint32_t RCAPDAT; /*!< [0x20C/0x214/0x21C/0x224/0x22C/0x234] PWM Rising Capture Data Register 0~5 */
    __IO uint32_t FCAPDAT; /*!< [0x210/0x218/0x220/0x228/0x230/0x238] PWM Falling Capture Data Register 0~5 */
} CAPDAT_T;

typedef struct
{

    /**
     * @var PWM_T::CTL0
     * Offset: 0x00  PWM Control Register 0
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |CTRLDn    |Center Load Enable Bits
     * |        |          |In up-down counter type, PERIOD will load to PBUF at the end point of each period
     * |        |          |CMPDAT will load to CMPBUF at the center point of a period
     * |[16]    |IMMLDENn  |Immediately Load Enable Bits
     * |        |          |0 = PERIOD will load to PBUF at the end point of each period
     * |        |          |CMPDAT will load to CMPBUF at the end point or center point of each period by setting CTRLD bit.
     * |        |          |1 = PERIOD/CMPDAT will load to PBUF and CMPBUF immediately when software update PERIOD/CMPDAT.
     * |        |          |Note: If IMMLDENn is enabled, WINLDENn and CTRLDn will be invalid.
     * |[30]    |DBGHALT   |ICE Debug Mode Counter Halt (Write Protect)
     * |        |          |If counter halt is enabled, PWM all counters will keep current value until exit ICE debug mode.
     * |        |          |0 = ICE debug mode counter halt Disable.
     * |        |          |1 = ICE debug mode counter halt Enable.
     * |        |          |Note: This bit is write protected. Refer to SYS_REGLCTL register.
     * |[31]    |DBGTRIOFF |ICE Debug Mode Acknowledge Disable Bit (Write Protect)
     * |        |          |0 = ICE debug mode acknowledgement effects PWM output.
     * |        |          |PWM pin will be forced as tri-state while ICE debug mode acknowledged.
     * |        |          |1 = ICE debug mode acknowledgement disabled.
     * |        |          |PWM pin will keep output no matter ICE debug mode acknowledged or not.
     * |        |          |Note: This bit is write protected. Refer to SYS_REGLCTL register.
     * @var PWM_T::CTL1
     * Offset: 0x04  PWM Control Register 1
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[1:0]   |CNTTYPE0  |PWM Counter Behavior Type 0
     * |        |          |The two bits control channel1 and channel0
     * |        |          |00 = Up counter type (supported in capture mode).
     * |        |          |01 = Down count type (supported in capture mode).
     * |        |          |10 = Up-down counter type.
     * |        |          |11 = Reserved.
     * |[5:4]   |CNTTYPE2  |PWM Counter Behavior Type 2
     * |        |          |The two bits control channel3 and channel2
     * |        |          |00 = Up counter type (supported in capture mode).
     * |        |          |01 = Down count type (supported in capture mode).
     * |        |          |10 = Up-down counter type.
     * |        |          |11 = Reserved.
     * |[9:8]   |CNTTYPE4  |PWM Counter Behavior Type 4
     * |        |          |The two bits control channel5 and channel4
     * |        |          |00 = Up counter type (supported in capture mode).
     * |        |          |01 = Down count type (supported in capture mode).
     * |        |          |10 = Up-down counter type.
     * |        |          |11 = Reserved.
     * |[26:24] |OUTMODEn  |PWM Output Mode
     * |        |          |Each bit n controls the output mode of corresponding PWM channel n.
     * |        |          |0 = PWM independent mode.
     * |        |          |1 = PWM complementary mode.
     * |        |          |Note: When operating in group function, these bits must all set to the same mode.
     * @var PWM_T::CLKSRC
     * Offset: 0x10  PWM Clock Source Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[2:0]   |ECLKSRC0  |PWM_CH01 External Clock Source Select
     * |        |          |000 = PWMx_CLK, x denotes 0 or 1.
     * |        |          |001 = TIMER0 overflow.
     * |        |          |010 = TIMER1 overflow.
     * |        |          |011 = TIMER2 overflow.
     * |        |          |100 = TIMER3 overflow.
     * |        |          |Others = Reserved.
     * |[10:8]  |ECLKSRC2  |PWM_CH23 External Clock Source Select
     * |        |          |000 = PWMx_CLK, x denotes 0 or 1.
     * |        |          |001 = TIMER0 overflow.
     * |        |          |010 = TIMER1 overflow.
     * |        |          |011 = TIMER2 overflow.
     * |        |          |100 = TIMER3 overflow.
     * |        |          |Others = Reserved.
     * |[18:16] |ECLKSRC4  |PWM_CH45 External Clock Source Select
     * |        |          |000 = PWMx_CLK, x denotes 0 or 1.
     * |        |          |001 = TIMER0 overflow.
     * |        |          |010 = TIMER1 overflow.
     * |        |          |011 = TIMER2 overflow.
     * |        |          |100 = TIMER3 overflow.
     * |        |          |Others = Reserved.
     * @var PWM_T::CLKPSC0_1
     * Offset: 0x14  PWM Clock Prescale Register 0/1
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[11:0]  |CLKPSC    |PWM Counter Clock Prescale
     * |        |          |The clock of PWM counter is decided by clock prescaler
     * |        |          |Each PWM pair share one PWM counter clock prescaler
     * |        |          |The clock of PWM counter is divided by (CLKPSC+ 1)
     * @var PWM_T::CLKPSC2_3
     * Offset: 0x18  PWM Clock Prescale Register 2/3
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[11:0]  |CLKPSC    |PWM Counter Clock Prescale
     * |        |          |The clock of PWM counter is decided by clock prescaler
     * |        |          |Each PWM pair share one PWM counter clock prescaler
     * |        |          |The clock of PWM counter is divided by (CLKPSC+ 1)
     * @var PWM_T::CLKPSC4_5
     * Offset: 0x1C  PWM Clock Prescale Register 4/5
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[11:0]  |CLKPSC    |PWM Counter Clock Prescale
     * |        |          |The clock of PWM counter is decided by clock prescaler
     * |        |          |Each PWM pair share one PWM counter clock prescaler
     * |        |          |The clock of PWM counter is divided by (CLKPSC+ 1)
     * @var PWM_T::CNTEN
     * Offset: 0x20  PWM Counter Enable Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |CNTEN0    |PWM Counter Enable Bit 0
     * |        |          |0 = PWM Counter and clock prescaler Stop Running.
     * |        |          |1 = PWM Counter and clock prescaler Start Running.
     * |[2]     |CNTEN2    |PWM Counter Enable Bit 2
     * |        |          |0 = PWM Counter and clock prescaler Stop Running.
     * |        |          |1 = PWM Counter and clock prescaler Start Running.
     * |[4]     |CNTEN4    |PWM Counter Enable Bit 4
     * |        |          |0 = PWM Counter and clock prescaler Stop Running.
     * |        |          |1 = PWM Counter and clock prescaler Start Running.
     * @var PWM_T::CNTCLR
     * Offset: 0x24  PWM Clear Counter Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |CNTCLR0   |Clear PWM Counter Control Bit 0
     * |        |          |It is automatically cleared by hardware.
     * |        |          |0 = No effect.
     * |        |          |1 = Clear 16-bit PWM counter to 0000H.
     * |[2]     |CNTCLR2   |Clear PWM Counter Control Bit 2
     * |        |          |It is automatically cleared by hardware.
     * |        |          |0 = No effect.
     * |        |          |1 = Clear 16-bit PWM counter to 0000H.
     * |[4]     |CNTCLR4   |Clear PWM Counter Control Bit 4
     * |        |          |It is automatically cleared by hardware.
     * |        |          |0 = No effect.
     * |        |          |1 = Clear 16-bit PWM counter to 0000H.
     * @var PWM_T::PERIOD[6]
     * Offset: 0x30~0x44  PWM Period Register 0, 2, 4
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[15:0]  |PERIOD    |PWM Period Register
     * |        |          |Up-Count mode: In this mode, PWM counter counts from 0 to PERIOD, and restarts from 0.
     * |        |          |Down-Count mode: In this mode, PWM counter counts from PERIOD to 0, and restarts from PERIOD.
     * |        |          |PWM period time = (PERIOD+1) * PWM_CLK period.
     * |        |          |Up-Down-Count mode: In this mode, PWM counter counts from 0 to PERIOD, then decrements to 0 and repeats again.
     * |        |          |PWM period time = 2 * PERIOD * PWM_CLK period.
     * @var PWM_T::CMPDAT[6]
     * Offset: 0x50~0x64  PWM Comparator Register 0~5
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[15:0]  |CMP       |PWM Comparator Register
     * |        |          |CMP is used to compare with CNTR to generate PWM waveform, interrupt and trigger EADC.
     * |        |          |In independent mode, PWM_CMPDAT0~5 denote as 6 independent PWM_CH0~5 compared point.
     * |        |          |In complementary mode, PWM_CMPDAT0, 2, 4 denote as first compared point, and PWM_CMPDAT1, 3, 5 denote as second compared point for the corresponding 3 complementary pairs PWM_CH0 and PWM_CH1, PWM_CH2 and PWM_CH3, PWM_CH4 and PWM_CH5.
     * @var PWM_T::DTCTL0_1
     * Offset: 0x70  PWM Dead-time Control Register 0/1
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[11:0]  |DTCNT     |Dead-time Counter (Write Protect)
     * |        |          |The dead-time can be calculated from the following formula:
     * |        |          |DTCKSEL=0: Dead-time = (DTCNT[11:0]+1) * PWM_CLK period.
     * |        |          |DTCKSEL=1: Dead-time = (DTCNT[11:0]+1) * PWM_CLK period * (CLKPSC+1).
     * |        |          |Note: This bit is write protected. Refer to SYS_REGLCTL register.
     * |[16]    |DTEN      |Enable Dead-time Insertion for PWM Pair (Write Protect)
     * |        |          |Dead-time insertion is only active when this pair of complementary PWM is enabled
     * |        |          |If dead- time insertion is inactive, the outputs of pin pair are complementary without any delay.
     * |        |          |0 = Dead-time insertion Disabled on the pin pair.
     * |        |          |1 = Dead-time insertion Enabled on the pin pair.
     * |        |          |Note: This bit is write protected. Refer to SYS_REGLCTL register.
     * |        |          |Note: PWM pair means PWM_CH0, PWM_CH1 are a pair, PWM_CH2, PWM_CH3 are a pair and PWM_CH4, PWM_CH5 are a pair.
     * |[24]    |DTCKSEL   |Dead-time Clock Select (Write Protect)
     * |        |          |0 = Dead-time clock source from PWM_CLK.
     * |        |          |1 = Dead-time clock source from prescaler output.
     * |        |          |Note: This bit is write protected. Refer to SYS_REGLCTL register.
     * @var PWM_T::DTCTL2_3
     * Offset: 0x74  PWM Dead-time Control Register 2/3
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[11:0]  |DTCNT     |Dead-time Counter (Write Protect)
     * |        |          |The dead-time can be calculated from the following formula:
     * |        |          |DTCKSEL=0: Dead-time = (DTCNT[11:0]+1) * PWM_CLK period.
     * |        |          |DTCKSEL=1: Dead-time = (DTCNT[11:0]+1) * PWM_CLK period * (CLKPSC+1).
     * |        |          |Note: This bit is write protected. Refer to SYS_REGLCTL register.
     * |[16]    |DTEN      |Enable Dead-time Insertion for PWM Pair (Write Protect)
     * |        |          |Dead-time insertion is only active when this pair of complementary PWM is enabled
     * |        |          |If dead- time insertion is inactive, the outputs of pin pair are complementary without any delay.
     * |        |          |0 = Dead-time insertion Disabled on the pin pair.
     * |        |          |1 = Dead-time insertion Enabled on the pin pair.
     * |        |          |Note: This bit is write protected. Refer to SYS_REGLCTL register.
     * |        |          |Note: PWM pair means PWM_CH0, PWM_CH1 are a pair, PWM_CH2, PWM_CH3 are a pair and PWM_CH4, PWM_CH5 are a pair.
     * |[24]    |DTCKSEL   |Dead-time Clock Select (Write Protect)
     * |        |          |0 = Dead-time clock source from PWM_CLK.
     * |        |          |1 = Dead-time clock source from prescaler output.
     * |        |          |Note: This bit is write protected. Refer to SYS_REGLCTL register.
     * @var PWM_T::DTCTL4_5
     * Offset: 0x78  PWM Dead-time Control Register 4/5
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[11:0]  |DTCNT     |Dead-time Counter (Write Protect)
     * |        |          |The dead-time can be calculated from the following formula:
     * |        |          |DTCKSEL=0: Dead-time = (DTCNT[11:0]+1) * PWM_CLK period.
     * |        |          |DTCKSEL=1: Dead-time = (DTCNT[11:0]+1) * PWM_CLK period * (CLKPSC+1).
     * |        |          |Note: This bit is write protected. Refer to SYS_REGLCTL register.
     * |[16]    |DTEN      |Enable Dead-time Insertion for PWM Pair (Write Protect)
     * |        |          |Dead-time insertion is only active when this pair of complementary PWM is enabled
     * |        |          |If dead- time insertion is inactive, the outputs of pin pair are complementary without any delay.
     * |        |          |0 = Dead-time insertion Disabled on the pin pair.
     * |        |          |1 = Dead-time insertion Enabled on the pin pair.
     * |        |          |Note: This bit is write protected. Refer to SYS_REGLCTL register.
     * |        |          |Note: PWM pair means PWM_CH0, PWM_CH1 are a pair, PWM_CH2, PWM_CH3 are a pair and PWM_CH4, PWM_CH5 are a pair.
     * |[24]    |DTCKSEL   |Dead-time Clock Select (Write Protect)
     * |        |          |0 = Dead-time clock source from PWM_CLK.
     * |        |          |1 = Dead-time clock source from prescaler output.
     * |        |          |Note: This bit is write protected. Refer to SYS_REGLCTL register.
     * @var PWM_T::CNT[6]
     * Offset: 0x90~0xA4  PWM Counter Register 0, 2, 4
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[15:0]  |CNT       |PWM Data Register (Read Only)
     * |        |          |User can monitor CNTR to know the current value in 16-bit period counter.
     * |[16]    |DIRF      |PWM Direction Indicator Flag (Read Only)
     * |        |          |0 = Counter is counting down.
     * |        |          |1 = Counter is counting up.
     * @var PWM_T::WGCTL0
     * Offset: 0xB0  PWM Generation Register 0
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[1:0]   |ZPCTL0    |PWM Zero Point Control
     * |        |          |00 = Do nothing.
     * |        |          |01 = PWM zero point output Low.
     * |        |          |10 = PWM zero point output High.
     * |        |          |11 = PWM zero point output Toggle.
     * |        |          |Note: PWM can control output level when PWM counter counts to 0.
     * |[3:2]   |ZPCTL1    |PWM Zero Point Control
     * |        |          |00 = Do nothing.
     * |        |          |01 = PWM zero point output Low.
     * |        |          |10 = PWM zero point output High.
     * |        |          |11 = PWM zero point output Toggle.
     * |        |          |Note: PWM can control output level when PWM counter counts to 0.
     * |[5:4]   |ZPCTL2    |PWM Zero Point Control
     * |        |          |00 = Do nothing.
     * |        |          |01 = PWM zero point output Low.
     * |        |          |10 = PWM zero point output High.
     * |        |          |11 = PWM zero point output Toggle.
     * |        |          |Note: PWM can control output level when PWM counter counts to 0.
     * |[7:6]   |ZPCTL3    |PWM Zero Point Control
     * |        |          |00 = Do nothing.
     * |        |          |01 = PWM zero point output Low.
     * |        |          |10 = PWM zero point output High.
     * |        |          |11 = PWM zero point output Toggle.
     * |        |          |Note: PWM can control output level when PWM counter counts to 0.
     * |[9:8]   |ZPCTL4    |PWM Zero Point Control
     * |        |          |00 = Do nothing.
     * |        |          |01 = PWM zero point output Low.
     * |        |          |10 = PWM zero point output High.
     * |        |          |11 = PWM zero point output Toggle.
     * |        |          |Note: PWM can control output level when PWM counter counts to 0.
     * |[11:10] |ZPCTL5    |PWM Zero Point Control
     * |        |          |00 = Do nothing.
     * |        |          |01 = PWM zero point output Low.
     * |        |          |10 = PWM zero point output High.
     * |        |          |11 = PWM zero point output Toggle.
     * |        |          |Note: PWM can control output level when PWM counter counts to 0.
     * |[17:16] |PRDPCTL0  |PWM Period/Center Point Control
     * |        |          |00 = Do nothing.
     * |        |          |01 = PWM period/center point output Low.
     * |        |          |10 = PWM period/center point output High.
     * |        |          |11 = PWM period/center point output Toggle.
     * |        |          |Note 1: PWM can control output level when PWM counter counts to (PERIODn+1).
     * |        |          |Note 2: This bit is center point control when PWM counter operating in up-down counter type.
     * |[19:18] |PRDPCTL1  |PWM Period/Center Point Control
     * |        |          |00 = Do nothing.
     * |        |          |01 = PWM period/center point output Low.
     * |        |          |10 = PWM period/center point output High.
     * |        |          |11 = PWM period/center point output Toggle.
     * |        |          |Note 1: PWM can control output level when PWM counter counts to (PERIODn+1).
     * |        |          |Note 2: This bit is center point control when PWM counter operating in up-down counter type.
     * |[21:20] |PRDPCTL2  |PWM Period/Center Point Control
     * |        |          |00 = Do nothing.
     * |        |          |01 = PWM period/center point output Low.
     * |        |          |10 = PWM period/center point output High.
     * |        |          |11 = PWM period/center point output Toggle.
     * |        |          |Note 1: PWM can control output level when PWM counter counts to (PERIODn+1).
     * |        |          |Note 2: This bit is center point control when PWM counter operating in up-down counter type.
     * |[23:22] |PRDPCTL3  |PWM Period/Center Point Control
     * |        |          |00 = Do nothing.
     * |        |          |01 = PWM period/center point output Low.
     * |        |          |10 = PWM period/center point output High.
     * |        |          |11 = PWM period/center point output Toggle.
     * |        |          |Note 1: PWM can control output level when PWM counter counts to (PERIODn+1).
     * |        |          |Note 2: This bit is center point control when PWM counter operating in up-down counter type.
     * |[25:24] |PRDPCTL4  |PWM Period/Center Point Control
     * |        |          |00 = Do nothing.
     * |        |          |01 = PWM period/center point output Low.
     * |        |          |10 = PWM period/center point output High.
     * |        |          |11 = PWM period/center point output Toggle.
     * |        |          |Note 1: PWM can control output level when PWM counter counts to (PERIODn+1).
     * |        |          |Note 2: This bit is center point control when PWM counter operating in up-down counter type.
     * |[27:26] |PRDPCTL5  |PWM Period/Center Point Control
     * |        |          |00 = Do nothing.
     * |        |          |01 = PWM period/center point output Low.
     * |        |          |10 = PWM period/center point output High.
     * |        |          |11 = PWM period/center point output Toggle.
     * |        |          |Note 1: PWM can control output level when PWM counter counts to (PERIODn+1).
     * |        |          |Note 2: This bit is center point control when PWM counter operating in up-down counter type.
     * @var PWM_T::WGCTL1
     * Offset: 0xB4  PWM Generation Register 1
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[1:0]   |CMPUCTL0  |PWM Compare Up Point Control
     * |        |          |00 = Do nothing.
     * |        |          |01 = PWM compare up point output Low.
     * |        |          |10 = PWM compare up point output High.
     * |        |          |11 = PWM compare up point output Toggle.
     * |        |          |Note 1: PWM can control output level when PWM counter counts up to CMPDAT.
     * |        |          |Note 2: In complementary mode, CMPUCTL1, 3, 5 is used as another CMPUCTL for channel 0, 2, 4.
     * |[3:2]   |CMPUCTL1  |PWM Compare Up Point Control
     * |        |          |00 = Do nothing.
     * |        |          |01 = PWM compare up point output Low.
     * |        |          |10 = PWM compare up point output High.
     * |        |          |11 = PWM compare up point output Toggle.
     * |        |          |Note 1: PWM can control output level when PWM counter counts up to CMPDAT.
     * |        |          |Note 2: In complementary mode, CMPUCTL1, 3, 5 is used as another CMPUCTL for channel 0, 2, 4.
     * |[5:4]   |CMPUCTL2  |PWM Compare Up Point Control
     * |        |          |00 = Do nothing.
     * |        |          |01 = PWM compare up point output Low.
     * |        |          |10 = PWM compare up point output High.
     * |        |          |11 = PWM compare up point output Toggle.
     * |        |          |Note 1: PWM can control output level when PWM counter counts up to CMPDAT.
     * |        |          |Note 2: In complementary mode, CMPUCTL1, 3, 5 is used as another CMPUCTL for channel 0, 2, 4.
     * |[7:6]   |CMPUCTL3  |PWM Compare Up Point Control
     * |        |          |00 = Do nothing.
     * |        |          |01 = PWM compare up point output Low.
     * |        |          |10 = PWM compare up point output High.
     * |        |          |11 = PWM compare up point output Toggle.
     * |        |          |Note 1: PWM can control output level when PWM counter counts up to CMPDAT.
     * |        |          |Note 2: In complementary mode, CMPUCTL1, 3, 5 is used as another CMPUCTL for channel 0, 2, 4.
     * |[9:8]   |CMPUCTL4  |PWM Compare Up Point Control
     * |        |          |00 = Do nothing.
     * |        |          |01 = PWM compare up point output Low.
     * |        |          |10 = PWM compare up point output High.
     * |        |          |11 = PWM compare up point output Toggle.
     * |        |          |Note 1: PWM can control output level when PWM counter counts up to CMPDAT.
     * |        |          |Note 2: In complementary mode, CMPUCTL1, 3, 5 is used as another CMPUCTL for channel 0, 2, 4.
     * |[11:10] |CMPUCTL5  |PWM Compare Up Point Control
     * |        |          |00 = Do nothing.
     * |        |          |01 = PWM compare up point output Low.
     * |        |          |10 = PWM compare up point output High.
     * |        |          |11 = PWM compare up point output Toggle.
     * |        |          |Note 1: PWM can control output level when PWM counter counts up to CMPDAT.
     * |        |          |Note 2: In complementary mode, CMPUCTL1, 3, 5 is used as another CMPUCTL for channel 0, 2, 4.
     * |[17:16] |CMPDCTL0  |PWM Compare Down Point Control
     * |        |          |00 = Do nothing.
     * |        |          |01 = PWM compare down point output Low.
     * |        |          |10 = PWM compare down point output High.
     * |        |          |11 = PWM compare down point output Toggle.
     * |        |          |Note 1: PWM can control output level when PWM counter counts down to CMPDAT.
     * |        |          |Note 2: In complementary mode, CMPDCTL1, 3, 5 is used as another CMPDCTL for channel 0, 2, 4.
     * |[19:18] |CMPDCTL1  |PWM Compare Down Point Control
     * |        |          |00 = Do nothing.
     * |        |          |01 = PWM compare down point output Low.
     * |        |          |10 = PWM compare down point output High.
     * |        |          |11 = PWM compare down point output Toggle.
     * |        |          |Note 1: PWM can control output level when PWM counter counts down to CMPDAT.
     * |        |          |Note 2: In complementary mode, CMPDCTL1, 3, 5 is used as another CMPDCTL for channel 0, 2, 4.
     * |[21:20] |CMPDCTL2  |PWM Compare Down Point Control
     * |        |          |00 = Do nothing.
     * |        |          |01 = PWM compare down point output Low.
     * |        |          |10 = PWM compare down point output High.
     * |        |          |11 = PWM compare down point output Toggle.
     * |        |          |Note 1: PWM can control output level when PWM counter counts down to CMPDAT.
     * |        |          |Note 2: In complementary mode, CMPDCTL1, 3, 5 is used as another CMPDCTL for channel 0, 2, 4.
     * |[23:22] |CMPDCTL3  |PWM Compare Down Point Control
     * |        |          |00 = Do nothing.
     * |        |          |01 = PWM compare down point output Low.
     * |        |          |10 = PWM compare down point output High.
     * |        |          |11 = PWM compare down point output Toggle.
     * |        |          |Note 1: PWM can control output level when PWM counter counts down to CMPDAT.
     * |        |          |Note 2: In complementary mode, CMPDCTL1, 3, 5 is used as another CMPDCTL for channel 0, 2, 4.
     * |[25:24] |CMPDCTL4  |PWM Compare Down Point Control
     * |        |          |00 = Do nothing.
     * |        |          |01 = PWM compare down point output Low.
     * |        |          |10 = PWM compare down point output High.
     * |        |          |11 = PWM compare down point output Toggle.
     * |        |          |Note 1: PWM can control output level when PWM counter counts down to CMPDAT.
     * |        |          |Note 2: In complementary mode, CMPDCTL1, 3, 5 is used as another CMPDCTL for channel 0, 2, 4.
     * |[27:26] |CMPDCTL5  |PWM Compare Down Point Control
     * |        |          |00 = Do nothing.
     * |        |          |01 = PWM compare down point output Low.
     * |        |          |10 = PWM compare down point output High.
     * |        |          |11 = PWM compare down point output Toggle.
     * |        |          |Note 1: PWM can control output level when PWM counter counts down to CMPDAT.
     * |        |          |Note 2: In complementary mode, CMPDCTL1, 3, 5 is used as another CMPDCTL for channel 0, 2, 4.
     * @var PWM_T::MSKEN
     * Offset: 0xB8  PWM Mask Enable Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |MSKEN0    |PWM Mask Enable Bits
     * |        |          |The PWM output signal will be masked when this bit is enabled
     * |        |          |The corresponding PWM channel n will output MSKDATn (PWM_MSK[5:0]) data.
     * |        |          |0 = PWM output signal is non-masked.
     * |        |          |1 = PWM output signal is masked and output MSKDATn data.
     * |[1]     |MSKEN1    |PWM Mask Enable Bits
     * |        |          |The PWM output signal will be masked when this bit is enabled
     * |        |          |The corresponding PWM channel n will output MSKDATn (PWM_MSK[5:0]) data.
     * |        |          |0 = PWM output signal is non-masked.
     * |        |          |1 = PWM output signal is masked and output MSKDATn data.
     * |[2]     |MSKEN2    |PWM Mask Enable Bits
     * |        |          |The PWM output signal will be masked when this bit is enabled
     * |        |          |The corresponding PWM channel n will output MSKDATn (PWM_MSK[5:0]) data.
     * |        |          |0 = PWM output signal is non-masked.
     * |        |          |1 = PWM output signal is masked and output MSKDATn data.
     * |[3]     |MSKEN3    |PWM Mask Enable Bits
     * |        |          |The PWM output signal will be masked when this bit is enabled
     * |        |          |The corresponding PWM channel n will output MSKDATn (PWM_MSK[5:0]) data.
     * |        |          |0 = PWM output signal is non-masked.
     * |        |          |1 = PWM output signal is masked and output MSKDATn data.
     * |[4]     |MSKEN4    |PWM Mask Enable Bits
     * |        |          |The PWM output signal will be masked when this bit is enabled
     * |        |          |The corresponding PWM channel n will output MSKDATn (PWM_MSK[5:0]) data.
     * |        |          |0 = PWM output signal is non-masked.
     * |        |          |1 = PWM output signal is masked and output MSKDATn data.
     * |[5]     |MSKEN5    |PWM Mask Enable Bits
     * |        |          |The PWM output signal will be masked when this bit is enabled
     * |        |          |The corresponding PWM channel n will output MSKDATn (PWM_MSK[5:0]) data.
     * |        |          |0 = PWM output signal is non-masked.
     * |        |          |1 = PWM output signal is masked and output MSKDATn data.
     * @var PWM_T::MSK
     * Offset: 0xBC  PWM Mask Data Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |MSKDAT0   |PWM Mask Data Bit
     * |        |          |This data bit control the state of PWMn output pin, if corresponding mask function is enabled
     * |        |          |Each bit n controls the corresponding PWM channel n.
     * |        |          |0 = Output logic low to PWM channel n.
     * |        |          |1 = Output logic high to PWM channel n.
     * |[1]     |MSKDAT1   |PWM Mask Data Bit
     * |        |          |This data bit control the state of PWMn output pin, if corresponding mask function is enabled
     * |        |          |Each bit n controls the corresponding PWM channel n.
     * |        |          |0 = Output logic low to PWM channel n.
     * |        |          |1 = Output logic high to PWM channel n.
     * |[2]     |MSKDAT2   |PWM Mask Data Bit
     * |        |          |This data bit control the state of PWMn output pin, if corresponding mask function is enabled
     * |        |          |Each bit n controls the corresponding PWM channel n.
     * |        |          |0 = Output logic low to PWM channel n.
     * |        |          |1 = Output logic high to PWM channel n.
     * |[3]     |MSKDAT3   |PWM Mask Data Bit
     * |        |          |This data bit control the state of PWMn output pin, if corresponding mask function is enabled
     * |        |          |Each bit n controls the corresponding PWM channel n.
     * |        |          |0 = Output logic low to PWM channel n.
     * |        |          |1 = Output logic high to PWM channel n.
     * |[4]     |MSKDAT4   |PWM Mask Data Bit
     * |        |          |This data bit control the state of PWMn output pin, if corresponding mask function is enabled
     * |        |          |Each bit n controls the corresponding PWM channel n.
     * |        |          |0 = Output logic low to PWM channel n.
     * |        |          |1 = Output logic high to PWM channel n.
     * |[5]     |MSKDAT5   |PWM Mask Data Bit
     * |        |          |This data bit control the state of PWMn output pin, if corresponding mask function is enabled
     * |        |          |Each bit n controls the corresponding PWM channel n.
     * |        |          |0 = Output logic low to PWM channel n.
     * |        |          |1 = Output logic high to PWM channel n.
     * @var PWM_T::BNF
     * Offset: 0xC0  PWM Brake Noise Filter Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |BRK0NFEN  |PWM Brake 0 Noise Filter Enable Bit
     * |        |          |0 = Noise filter of PWM Brake 0 Disabled.
     * |        |          |1 = Noise filter of PWM Brake 0 Enabled.
     * |[3:1]   |BRK0FSEL  |Brake 0 Edge Detector Filter Clock Selection
     * |        |          |000 = Filter clock = HCLK.
     * |        |          |001 = Filter clock = HCLK/2.
     * |        |          |010 = Filter clock = HCLK/4.
     * |        |          |011 = Filter clock = HCLK/8.
     * |        |          |100 = Filter clock = HCLK/16.
     * |        |          |101 = Filter clock = HCLK/32.
     * |        |          |110 = Filter clock = HCLK/64.
     * |        |          |111 = Filter clock = HCLK/128.
     * |[6:4]   |BRK0FCNT  |Brake 0 Edge Detector Filter Count
     * |        |          |The register bits control the Brake0 filter counter to count from 0 to BRK1FCNT.
     * |[7]     |BRK0PINV  |Brake 0 Pin Inverse
     * |        |          |0 = brake pin event will be detected if PWMx_BRAKE0 pin status transfer from low to high in edge-detect, or pin status is high in level-detect.
     * |        |          |1 = brake pin event will be detected if PWMx_BRAKE0 pin status transfer from high to low in edge-detect, or pin status is low in level-detect.
     * |[8]     |BRK1NFEN  |PWM Brake 1 Noise Filter Enable Bit
     * |        |          |0 = Noise filter of PWM Brake 1 Disabled.
     * |        |          |1 = Noise filter of PWM Brake 1 Enabled.
     * |[11:9]  |BRK1FSEL  |Brake 1 Edge Detector Filter Clock Selection
     * |        |          |000 = Filter clock = HCLK.
     * |        |          |001 = Filter clock = HCLK/2.
     * |        |          |010 = Filter clock = HCLK/4.
     * |        |          |011 = Filter clock = HCLK/8.
     * |        |          |100 = Filter clock = HCLK/16.
     * |        |          |101 = Filter clock = HCLK/32.
     * |        |          |110 = Filter clock = HCLK/64.
     * |        |          |111 = Filter clock = HCLK/128.
     * |[14:12] |BRK1FCNT  |Brake 1 Edge Detector Filter Count
     * |        |          |The register bits control the Brake1 filter counter to count from 0 to BRK1FCNT.
     * |[15]    |BRK1PINV  |Brake 1 Pin Inverse
     * |        |          |0 = brake pin event will be detected if PWMx_BRAKE1 pin status transfer from low to high in edge-detect, or pin status is high in level-detect.
     * |        |          |1 = brake pin event will be detected if PWMx_BRAKE1 pin status transfer from high to low in edge-detect, or pin status is low in level-detect.
     * @var PWM_T::FAILBRK
     * Offset: 0xC4  PWM System Fail Brake Control Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |CSSBRKEN  |Clock Security System Detection Trigger PWM Brake Function Enable Bit
     * |        |          |0 = Brake Function triggered by CSS detection Disabled.
     * |        |          |1 = Brake Function triggered by CSS detection Enabled.
     * |[1]     |BODBRKEN  |Brown-out Detection Trigger PWM Brake Function Enable Bit
     * |        |          |0 = Brake Function triggered by BOD Disabled.
     * |        |          |1 = Brake Function triggered by BOD Enabled.
     * |[3]     |CORBRKEN  |Core Lockup Detection Trigger PWM Brake Function Enable Bit
     * |        |          |0 = Brake Function triggered by Core lockup detection Disabled.
     * |        |          |1 = Brake Function triggered by Core lockup detection Enabled.
     * @var PWM_T::BRKCTL0_1
     * Offset: 0xC8  PWM Brake Edge Detect Control Register 0/1
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |CPO0EBEN  |Enable ACMP0_O Digital Output As Edge-detect Brake Source (Write Protect)
     * |        |          |0 = ACMP0_O as edge-detect brake source Disabled.
     * |        |          |1 = ACMP0_O as edge-detect brake source Enabled.
     * |        |          |Note: This register is write protected. Refer toSYS_REGLCTL register.
     * |[1]     |CPO1EBEN  |Enable ACMP1_O Digital Output As Edge-detect Brake Source (Write Protect)
     * |        |          |0 = ACMP1_O as edge-detect brake source Disabled.
     * |        |          |1 = ACMP1_O as edge-detect brake source Enabled.
     * |        |          |Note: This register is write protected. Refer toSYS_REGLCTL register.
     * |[4]     |BRKP0EEN  |Enable PWMx_BRAKE0 Pin As Edge-detect Brake Source (Write Protect)
     * |        |          |0 = BKP0 pin as edge-detect brake source Disabled.
     * |        |          |1 = BKP0 pin as edge-detect brake source Enabled.
     * |        |          |Note: This bit is write protected. Refer to SYS_REGLCTL register.
     * |[5]     |BRKP1EEN  |Enable PWMx_BRAKE1 Pin As Edge-detect Brake Source (Write Protect)
     * |        |          |0 = BKP1 pin as edge-detect brake source Disabled.
     * |        |          |1 = BKP1 pin as edge-detect brake source Enabled.
     * |        |          |Note: This bit is write protected. Refer to SYS_REGLCTL register.
     * |[7]     |SYSEBEN   |Enable System Fail As Edge-detect Brake Source (Write Protect)
     * |        |          |0 = System Fail condition as edge-detect brake source Disabled.
     * |        |          |1 = System Fail condition as edge-detect brake source Enabled.
     * |        |          |Note: This bit is write protected. Refer to SYS_REGLCTL register.
     * |[8]     |CPO0LBEN  |Enable ACMP0_O Digital Output As Level-detect Brake Source (Write Protect)
     * |        |          |0 = ACMP0_O as level-detect brake source Disabled.
     * |        |          |1 = ACMP0_O as level-detect brake source Enabled.
     * |        |          |Note: This register is write protected. Refer toSYS_REGLCTL register.
     * |[9]     |CPO1LBEN  |Enable ACMP1_O Digital Output As Level-detect Brake Source (Write Protect)
     * |        |          |0 = ACMP1_O as level-detect brake source Disabled.
     * |        |          |1 = ACMP1_O as level-detect brake source Enabled.
     * |        |          |Note: This register is write protected. Refer toSYS_REGLCTL register.
     * |[12]    |BRKP0LEN  |Enable BKP0 Pin As Level-detect Brake Source (Write Protect)
     * |        |          |0 = PWMx_BRAKE0 pin as level-detect brake source Disabled.
     * |        |          |1 = PWMx_BRAKE0 pin as level-detect brake source Enabled.
     * |        |          |Note: This bit is write protected. Refer to SYS_REGLCTL register.
     * |[13]    |BRKP1LEN  |Enable BKP1 Pin As Level-detect Brake Source (Write Protect)
     * |        |          |0 = PWMx_BRAKE1 pin as level-detect brake source Disabled.
     * |        |          |1 = PWMx_BRAKE1 pin as level-detect brake source Enabled.
     * |        |          |Note: This bit is write protected. Refer to SYS_REGLCTL register.
     * |[14]    |VBSNLBEN  |Reserved.
     * |[15]    |SYSLBEN   |Enable System Fail As Level-detect Brake Source (Write Protect)
     * |        |          |0 = System Fail condition as level-detect brake source Disabled.
     * |        |          |1 = System Fail condition as level-detect brake source Enabled.
     * |        |          |Note: This bit is write protected. Refer to SYS_REGLCTL register.
     * |[17:16] |BRKAEVEN  |PWM Brake Action Select for Even Channel (Write Protect)
     * |        |          |00 = PWM even channel level-detect or edge-detect brake function not affect channel output.
     * |        |          |01 = PWM even channel output tri-state when level-detect or edge-detect brake happened.
     * |        |          |10 = PWM even channel output low level when level-detect or edge-detect brake happened.
     * |        |          |11 = PWM even channel output high level when level-detect or edge-detect brake happened.
     * |        |          |Note: These bits are write protected. Refer to SYS_REGLCTL register.
     * |[19:18] |BRKAODD   |PWM Brake Action Select for Odd Channel (Write Protect)
     * |        |          |00 = PWM odd channel level-detect or edge-detect brake function not affect channel output.
     * |        |          |01 = PWM odd channel output tri-state when level-detect or edge-detect brake happened.
     * |        |          |10 = PWM odd channel output low level when level-detect or edge-detect brake happened.
     * |        |          |11 = PWM odd channel output high level when level-detect or edge-detect brake happened.
     * |        |          |Note: These bits are write protected. Refer to SYS_REGLCTL register.
     * @var PWM_T::BRKCTL2_3
     * Offset: 0xCC  PWM Brake Edge Detect Control Register 2/3
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |CPO0EBEN  |Enable ACMP0_O Digital Output As Edge-detect Brake Source (Write Protect)
     * |        |          |0 = ACMP0_O as edge-detect brake source Disabled.
     * |        |          |1 = ACMP0_O as edge-detect brake source Enabled.
     * |        |          |Note: This register is write protected. Refer toSYS_REGLCTL register.
     * |[1]     |CPO1EBEN  |Enable ACMP1_O Digital Output As Edge-detect Brake Source (Write Protect)
     * |        |          |0 = ACMP1_O as edge-detect brake source Disabled.
     * |        |          |1 = ACMP1_O as edge-detect brake source Enabled.
     * |        |          |Note: This register is write protected. Refer toSYS_REGLCTL register.
     * |[4]     |BRKP0EEN  |Enable PWMx_BRAKE0 Pin As Edge-detect Brake Source (Write Protect)
     * |        |          |0 = BKP0 pin as edge-detect brake source Disabled.
     * |        |          |1 = BKP0 pin as edge-detect brake source Enabled.
     * |        |          |Note: This bit is write protected. Refer to SYS_REGLCTL register.
     * |[5]     |BRKP1EEN  |Enable PWMx_BRAKE1 Pin As Edge-detect Brake Source (Write Protect)
     * |        |          |0 = BKP1 pin as edge-detect brake source Disabled.
     * |        |          |1 = BKP1 pin as edge-detect brake source Enabled.
     * |        |          |Note: This bit is write protected. Refer to SYS_REGLCTL register.
     * |[7]     |SYSEBEN   |Enable System Fail As Edge-detect Brake Source (Write Protect)
     * |        |          |0 = System Fail condition as edge-detect brake source Disabled.
     * |        |          |1 = System Fail condition as edge-detect brake source Enabled.
     * |        |          |Note: This bit is write protected. Refer to SYS_REGLCTL register.
     * |[8]     |CPO0LBEN  |Enable ACMP0_O Digital Output As Level-detect Brake Source (Write Protect)
     * |        |          |0 = ACMP0_O as level-detect brake source Disabled.
     * |        |          |1 = ACMP0_O as level-detect brake source Enabled.
     * |        |          |Note: This register is write protected. Refer toSYS_REGLCTL register.
     * |[9]     |CPO1LBEN  |Enable ACMP1_O Digital Output As Level-detect Brake Source (Write Protect)
     * |        |          |0 = ACMP1_O as level-detect brake source Disabled.
     * |        |          |1 = ACMP1_O as level-detect brake source Enabled.
     * |        |          |Note: This register is write protected. Refer toSYS_REGLCTL register.
     * |[12]    |BRKP0LEN  |Enable BKP0 Pin As Level-detect Brake Source (Write Protect)
     * |        |          |0 = PWMx_BRAKE0 pin as level-detect brake source Disabled.
     * |        |          |1 = PWMx_BRAKE0 pin as level-detect brake source Enabled.
     * |        |          |Note: This bit is write protected. Refer to SYS_REGLCTL register.
     * |[13]    |BRKP1LEN  |Enable BKP1 Pin As Level-detect Brake Source (Write Protect)
     * |        |          |0 = PWMx_BRAKE1 pin as level-detect brake source Disabled.
     * |        |          |1 = PWMx_BRAKE1 pin as level-detect brake source Enabled.
     * |        |          |Note: This bit is write protected. Refer to SYS_REGLCTL register.
     * |[14]    |VBSNLBEN  |Reserved.
     * |[15]    |SYSLBEN   |Enable System Fail As Level-detect Brake Source (Write Protect)
     * |        |          |0 = System Fail condition as level-detect brake source Disabled.
     * |        |          |1 = System Fail condition as level-detect brake source Enabled.
     * |        |          |Note: This bit is write protected. Refer to SYS_REGLCTL register.
     * |[17:16] |BRKAEVEN  |PWM Brake Action Select for Even Channel (Write Protect)
     * |        |          |00 = PWM even channel level-detect or edge-detect brake function not affect channel output.
     * |        |          |01 = PWM even channel output tri-state when level-detect or edge-detect brake happened.
     * |        |          |10 = PWM even channel output low level when level-detect or edge-detect brake happened.
     * |        |          |11 = PWM even channel output high level when level-detect or edge-detect brake happened.
     * |        |          |Note: These bits are write protected. Refer to SYS_REGLCTL register.
     * |[19:18] |BRKAODD   |PWM Brake Action Select for Odd Channel (Write Protect)
     * |        |          |00 = PWM odd channel level-detect or edge-detect brake function not affect channel output.
     * |        |          |01 = PWM odd channel output tri-state when level-detect or edge-detect brake happened.
     * |        |          |10 = PWM odd channel output low level when level-detect or edge-detect brake happened.
     * |        |          |11 = PWM odd channel output high level when level-detect or edge-detect brake happened.
     * |        |          |Note: These bits are write protected. Refer to SYS_REGLCTL register.
     * @var PWM_T::BRKCTL4_5
     * Offset: 0xD0  PWM Brake Edge Detect Control Register 4/5
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |CPO0EBEN  |Enable ACMP0_O Digital Output As Edge-detect Brake Source (Write Protect)
     * |        |          |0 = ACMP0_O as edge-detect brake source Disabled.
     * |        |          |1 = ACMP0_O as edge-detect brake source Enabled.
     * |        |          |Note: This register is write protected. Refer toSYS_REGLCTL register.
     * |[1]     |CPO1EBEN  |Enable ACMP1_O Digital Output As Edge-detect Brake Source (Write Protect)
     * |        |          |0 = ACMP1_O as edge-detect brake source Disabled.
     * |        |          |1 = ACMP1_O as edge-detect brake source Enabled.
     * |        |          |Note: This register is write protected. Refer toSYS_REGLCTL register.
     * |[4]     |BRKP0EEN  |Enable PWMx_BRAKE0 Pin As Edge-detect Brake Source (Write Protect)
     * |        |          |0 = BKP0 pin as edge-detect brake source Disabled.
     * |        |          |1 = BKP0 pin as edge-detect brake source Enabled.
     * |        |          |Note: This bit is write protected. Refer to SYS_REGLCTL register.
     * |[5]     |BRKP1EEN  |Enable PWMx_BRAKE1 Pin As Edge-detect Brake Source (Write Protect)
     * |        |          |0 = BKP1 pin as edge-detect brake source Disabled.
     * |        |          |1 = BKP1 pin as edge-detect brake source Enabled.
     * |        |          |Note: This bit is write protected. Refer to SYS_REGLCTL register.
     * |[7]     |SYSEBEN   |Enable System Fail As Edge-detect Brake Source (Write Protect)
     * |        |          |0 = System Fail condition as edge-detect brake source Disabled.
     * |        |          |1 = System Fail condition as edge-detect brake source Enabled.
     * |        |          |Note: This bit is write protected. Refer to SYS_REGLCTL register.
     * |[8]     |CPO0LBEN  |Enable ACMP0_O Digital Output As Level-detect Brake Source (Write Protect)
     * |        |          |0 = ACMP0_O as level-detect brake source Disabled.
     * |        |          |1 = ACMP0_O as level-detect brake source Enabled.
     * |        |          |Note: This register is write protected. Refer toSYS_REGLCTL register.
     * |[9]     |CPO1LBEN  |Enable ACMP1_O Digital Output As Level-detect Brake Source (Write Protect)
     * |        |          |0 = ACMP1_O as level-detect brake source Disabled.
     * |        |          |1 = ACMP1_O as level-detect brake source Enabled.
     * |        |          |Note: This register is write protected. Refer toSYS_REGLCTL register.
     * |[12]    |BRKP0LEN  |Enable BKP0 Pin As Level-detect Brake Source (Write Protect)
     * |        |          |0 = PWMx_BRAKE0 pin as level-detect brake source Disabled.
     * |        |          |1 = PWMx_BRAKE0 pin as level-detect brake source Enabled.
     * |        |          |Note: This bit is write protected. Refer to SYS_REGLCTL register.
     * |[13]    |BRKP1LEN  |Enable BKP1 Pin As Level-detect Brake Source (Write Protect)
     * |        |          |0 = PWMx_BRAKE1 pin as level-detect brake source Disabled.
     * |        |          |1 = PWMx_BRAKE1 pin as level-detect brake source Enabled.
     * |        |          |Note: This bit is write protected. Refer to SYS_REGLCTL register.
     * |[14]    |VBSNLBEN  |Reserved.
     * |[15]    |SYSLBEN   |Enable System Fail As Level-detect Brake Source (Write Protect)
     * |        |          |0 = System Fail condition as level-detect brake source Disabled.
     * |        |          |1 = System Fail condition as level-detect brake source Enabled.
     * |        |          |Note: This bit is write protected. Refer to SYS_REGLCTL register.
     * |[17:16] |BRKAEVEN  |PWM Brake Action Select for Even Channel (Write Protect)
     * |        |          |00 = PWM even channel level-detect or edge-detect brake function not affect channel output.
     * |        |          |01 = PWM even channel output tri-state when level-detect or edge-detect brake happened.
     * |        |          |10 = PWM even channel output low level when level-detect or edge-detect brake happened.
     * |        |          |11 = PWM even channel output high level when level-detect or edge-detect brake happened.
     * |        |          |Note: These bits are write protected. Refer to SYS_REGLCTL register.
     * |[19:18] |BRKAODD   |PWM Brake Action Select for Odd Channel (Write Protect)
     * |        |          |00 = PWM odd channel level-detect or edge-detect brake function not affect channel output.
     * |        |          |01 = PWM odd channel output tri-state when level-detect or edge-detect brake happened.
     * |        |          |10 = PWM odd channel output low level when level-detect or edge-detect brake happened.
     * |        |          |11 = PWM odd channel output high level when level-detect or edge-detect brake happened.
     * |        |          |Note: These bits are write protected. Refer to SYS_REGLCTL register.
     * @var PWM_T::POLCTL
     * Offset: 0xD4  PWM Pin Polar Inverse Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |PINV0     |PWM PIN Polar Inverse Control
     * |        |          |The register controls polarity state of PWM output.
     * |        |          |0 = PWM output polar inverse Disabled.
     * |        |          |1 = PWM output polar inverse Enabled.
     * |[1]     |PINV1     |PWM PIN Polar Inverse Control
     * |        |          |The register controls polarity state of PWM output.
     * |        |          |0 = PWM output polar inverse Disabled.
     * |        |          |1 = PWM output polar inverse Enabled.
     * |[2]     |PINV2     |PWM PIN Polar Inverse Control
     * |        |          |The register controls polarity state of PWM output.
     * |        |          |0 = PWM output polar inverse Disabled.
     * |        |          |1 = PWM output polar inverse Enabled.
     * |[3]     |PINV3     |PWM PIN Polar Inverse Control
     * |        |          |The register controls polarity state of PWM output.
     * |        |          |0 = PWM output polar inverse Disabled.
     * |        |          |1 = PWM output polar inverse Enabled.
     * |[4]     |PINV4     |PWM PIN Polar Inverse Control
     * |        |          |The register controls polarity state of PWM output.
     * |        |          |0 = PWM output polar inverse Disabled.
     * |        |          |1 = PWM output polar inverse Enabled.
     * |[5]     |PINV5     |PWM PIN Polar Inverse Control
     * |        |          |The register controls polarity state of PWM output.
     * |        |          |0 = PWM output polar inverse Disabled.
     * |        |          |1 = PWM output polar inverse Enabled.
     * @var PWM_T::POEN
     * Offset: 0xD8  PWM Output Enable Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |POEN0     |PWM Pin Output Enable Bits
     * |        |          |0 = PWM pin at tri-state.
     * |        |          |1 = PWM pin in output mode.
     * |[1]     |POEN1     |PWM Pin Output Enable Bits
     * |        |          |0 = PWM pin at tri-state.
     * |        |          |1 = PWM pin in output mode.
     * |[2]     |POEN2     |PWM Pin Output Enable Bits
     * |        |          |0 = PWM pin at tri-state.
     * |        |          |1 = PWM pin in output mode.
     * |[3]     |POEN3     |PWM Pin Output Enable Bits
     * |        |          |0 = PWM pin at tri-state.
     * |        |          |1 = PWM pin in output mode.
     * |[4]     |POEN4     |PWM Pin Output Enable Bits
     * |        |          |0 = PWM pin at tri-state.
     * |        |          |1 = PWM pin in output mode.
     * |[5]     |POEN5     |PWM Pin Output Enable Bits
     * |        |          |0 = PWM pin at tri-state.
     * |        |          |1 = PWM pin in output mode.
     * @var PWM_T::SWBRK
     * Offset: 0xDC  PWM Software Brake Control Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |BRKETRG0  |PWM Edge Brake Software Trigger (Write Only) (Write Protect)
     * |        |          |Write 1 to this bit will trigger Edge brake, and set BRKEIFn to 1 in PWM_INTSTS1 register.
     * |        |          |Note: This bit is write protected. Refer to SYS_REGLCTL register.
     * |[1]     |BRKETRG2  |PWM Edge Brake Software Trigger (Write Only) (Write Protect)
     * |        |          |Write 1 to this bit will trigger Edge brake, and set BRKEIFn to 1 in PWM_INTSTS1 register.
     * |        |          |Note: This bit is write protected. Refer to SYS_REGLCTL register.
     * |[2]     |BRKETRG4  |PWM Edge Brake Software Trigger (Write Only) (Write Protect)
     * |        |          |Write 1 to this bit will trigger Edge brake, and set BRKEIFn to 1 in PWM_INTSTS1 register.
     * |        |          |Note: This bit is write protected. Refer to SYS_REGLCTL register.
     * |[8]     |BRKLTRG0  |PWM Level Brake Software Trigger (Write Only) (Write Protect)
     * |        |          |Write 1 to this bit will trigger level brake, and set BRKLIFn to 1 in PWM_INTSTS1 register.
     * |        |          |Note: This bit is write protected. Refer to SYS_REGLCTL register.
     * |[9]     |BRKLTRG2  |PWM Level Brake Software Trigger (Write Only) (Write Protect)
     * |        |          |Write 1 to this bit will trigger level brake, and set BRKLIFn to 1 in PWM_INTSTS1 register.
     * |        |          |Note: This bit is write protected. Refer to SYS_REGLCTL register.
     * |[10]    |BRKLTRG4  |PWM Level Brake Software Trigger (Write Only) (Write Protect)
     * |        |          |Write 1 to this bit will trigger level brake, and set BRKLIFn to 1 in PWM_INTSTS1 register.
     * |        |          |Note: This bit is write protected. Refer to SYS_REGLCTL register.
     * @var PWM_T::INTEN0
     * Offset: 0xE0  PWM Interrupt Enable Register 0
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |ZIEN0     |PWM Zero Point Interrupt Enable Bit 0
     * |        |          |0 = Zero point interrupt Disabled.
     * |        |          |1 = Zero point interrupt Enabled.
     * |        |          |Note: Odd channels will read always 0 at complementary mode.
     * |[2]     |ZIEN2     |PWM Zero Point Interrupt Enable Bit 2
     * |        |          |0 = Zero point interrupt Disabled.
     * |        |          |1 = Zero point interrupt Enabled.
     * |        |          |Note: Odd channels will read always 0 at complementary mode.
     * |[4]     |ZIEN4     |PWM Zero Point Interrupt Enable Bit 4
     * |        |          |0 = Zero point interrupt Disabled.
     * |        |          |1 = Zero point interrupt Enabled.
     * |        |          |Note: Odd channels will read always 0 at complementary mode.
     * |[8]     |PIEN0     |PWM Period Point Interrupt Enable Bit 0
     * |        |          |0 = Period point interrupt Disabled.
     * |        |          |1 = Period point interrupt Enabled.
     * |        |          |Note: When up-down counter type, period point means center point.
     * |[10]    |PIEN2     |PWM Period Point Interrupt Enable Bit 2
     * |        |          |0 = Period point interrupt Disabled.
     * |        |          |1 = Period point interrupt Enabled.
     * |        |          |Note: When up-down counter type, period point means center point.
     * |[12]    |PIEN4     |PWM Period Point Interrupt Enable Bit 4
     * |        |          |0 = Period point interrupt Disabled.
     * |        |          |1 = Period point interrupt Enabled.
     * |        |          |Note: When up-down counter type, period point means center point.
     * |[16]    |CMPUIEN0  |PWM Compare Up Count Interrupt Enable Bits
     * |        |          |Each bit n controls the corresponding PWM channel n.
     * |        |          |0 = Compare up count interrupt Disabled.
     * |        |          |1 = Compare up count interrupt Enabled.
     * |        |          |Note: In complementary mode, CMPUIEN1, 3, 5 is used as another CMPUIEN for channel 0, 2, 4.
     * |[17]    |CMPUIEN1  |PWM Compare Up Count Interrupt Enable Bits
     * |        |          |Each bit n controls the corresponding PWM channel n.
     * |        |          |0 = Compare up count interrupt Disabled.
     * |        |          |1 = Compare up count interrupt Enabled.
     * |        |          |Note: In complementary mode, CMPUIEN1, 3, 5 is used as another CMPUIEN for channel 0, 2, 4.
     * |[18]    |CMPUIEN2  |PWM Compare Up Count Interrupt Enable Bits
     * |        |          |Each bit n controls the corresponding PWM channel n.
     * |        |          |0 = Compare up count interrupt Disabled.
     * |        |          |1 = Compare up count interrupt Enabled.
     * |        |          |Note: In complementary mode, CMPUIEN1, 3, 5 is used as another CMPUIEN for channel 0, 2, 4.
     * |[19]    |CMPUIEN3  |PWM Compare Up Count Interrupt Enable Bits
     * |        |          |Each bit n controls the corresponding PWM channel n.
     * |        |          |0 = Compare up count interrupt Disabled.
     * |        |          |1 = Compare up count interrupt Enabled.
     * |        |          |Note: In complementary mode, CMPUIEN1, 3, 5 is used as another CMPUIEN for channel 0, 2, 4.
     * |[20]    |CMPUIEN4  |PWM Compare Up Count Interrupt Enable Bits
     * |        |          |Each bit n controls the corresponding PWM channel n.
     * |        |          |0 = Compare up count interrupt Disabled.
     * |        |          |1 = Compare up count interrupt Enabled.
     * |        |          |Note: In complementary mode, CMPUIEN1, 3, 5 is used as another CMPUIEN for channel 0, 2, 4.
     * |[21]    |CMPUIEN5  |PWM Compare Up Count Interrupt Enable Bits
     * |        |          |Each bit n controls the corresponding PWM channel n.
     * |        |          |0 = Compare up count interrupt Disabled.
     * |        |          |1 = Compare up count interrupt Enabled.
     * |        |          |Note: In complementary mode, CMPUIEN1, 3, 5 is used as another CMPUIEN for channel 0, 2, 4.
     * |[24]    |CMPDIEN0  |PWM Compare Down Count Interrupt Enable Bits
     * |        |          |0 = Compare down count interrupt Disabled.
     * |        |          |1 = Compare down count interrupt Enabled.
     * |        |          |Note: In complementary mode, CMPDIEN1, 3, 5 is used as another CMPDIEN for channel 0, 2, 4.
     * |[25]    |CMPDIEN1  |PWM Compare Down Count Interrupt Enable Bits
     * |        |          |0 = Compare down count interrupt Disabled.
     * |        |          |1 = Compare down count interrupt Enabled.
     * |        |          |Note: In complementary mode, CMPDIEN1, 3, 5 is used as another CMPDIEN for channel 0, 2, 4.
     * |[26]    |CMPDIEN2  |PWM Compare Down Count Interrupt Enable Bits
     * |        |          |0 = Compare down count interrupt Disabled.
     * |        |          |1 = Compare down count interrupt Enabled.
     * |        |          |Note: In complementary mode, CMPDIEN1, 3, 5 is used as another CMPDIEN for channel 0, 2, 4.
     * |[27]    |CMPDIEN3  |PWM Compare Down Count Interrupt Enable Bits
     * |        |          |0 = Compare down count interrupt Disabled.
     * |        |          |1 = Compare down count interrupt Enabled.
     * |        |          |Note: In complementary mode, CMPDIEN1, 3, 5 is used as another CMPDIEN for channel 0, 2, 4.
     * |[28]    |CMPDIEN4  |PWM Compare Down Count Interrupt Enable Bits
     * |        |          |0 = Compare down count interrupt Disabled.
     * |        |          |1 = Compare down count interrupt Enabled.
     * |        |          |Note: In complementary mode, CMPDIEN1, 3, 5 is used as another CMPDIEN for channel 0, 2, 4.
     * |[29]    |CMPDIEN5  |PWM Compare Down Count Interrupt Enable Bits
     * |        |          |0 = Compare down count interrupt Disabled.
     * |        |          |1 = Compare down count interrupt Enabled.
     * |        |          |Note: In complementary mode, CMPDIEN1, 3, 5 is used as another CMPDIEN for channel 0, 2, 4.
     * @var PWM_T::INTEN1
     * Offset: 0xE4  PWM Interrupt Enable Register 1
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |BRKEIEN0_1|PWM Edge-detect Brake Interrupt Enable for Channel0/1 (Write Protect)
     * |        |          |0 = Edge-detect Brake interrupt for channel0/1 Disabled.
     * |        |          |1 = Edge-detect Brake interrupt for channel0/1 Enabled.
     * |        |          |Note: This bit is write protected. Refer to SYS_REGLCTL register.
     * |[1]     |BRKEIEN2_3|PWM Edge-detect Brake Interrupt Enable for Channel2/3 (Write Protect)
     * |        |          |0 = Edge-detect Brake interrupt for channel2/3 Disabled.
     * |        |          |1 = Edge-detect Brake interrupt for channel2/3 Enabled.
     * |        |          |Note: This bit is write protected. Refer to SYS_REGLCTL register.
     * |[2]     |BRKEIEN4_5|PWM Edge-detect Brake Interrupt Enable for Channel4/5 (Write Protect)
     * |        |          |0 = Edge-detect Brake interrupt for channel4/5 Disabled.
     * |        |          |1 = Edge-detect Brake interrupt for channel4/5 Enabled.
     * |        |          |Note: This bitr is write protected. Refer to SYS_REGLCTL register.
     * |[8]     |BRKLIEN0_1|PWM Level-detect Brake Interrupt Enable for Channel0/1 (Write Protect)
     * |        |          |0 = Level-detect Brake interrupt for channel0/1 Disabled.
     * |        |          |1 = Level-detect Brake interrupt for channel0/1 Enabled.
     * |        |          |Note: This bit is write protected. Refer to SYS_REGLCTL register.
     * |[9]     |BRKLIEN2_3|PWM Level-detect Brake Interrupt Enable for Channel2/3 (Write Protect)
     * |        |          |0 = Level-detect Brake interrupt for channel2/3 Disabled.
     * |        |          |1 = Level-detect Brake interrupt for channel2/3 Enabled.
     * |        |          |Note: This bit is write protected. Refer to SYS_REGLCTL register.
     * |[10]    |BRKLIEN4_5|PWM Level-detect Brake Interrupt Enable for Channel4/5 (Write Protect)
     * |        |          |0 = Level-detect Brake interrupt for channel4/5 Disabled.
     * |        |          |1 = Level-detect Brake interrupt for channel4/5 Enabled.
     * |        |          |Note: This bit is write protected. Refer to SYS_REGLCTL register.
     * @var PWM_T::INTSTS0
     * Offset: 0xE8  PWM Interrupt Flag Register 0
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |ZIF0      |PWM Zero Point Interrupt Flag 0
     * |        |          |This bit is set by hardware when PWM_CH0 counter reaches 0.
     * |        |          |Note: This bit can be cleared to 0 by software writing 1.
     * |[2]     |ZIF2      |PWM Zero Point Interrupt Flag 2
     * |        |          |This bit is set by hardware when PWM_CH2 counter reaches 0.
     * |        |          |Note: This bit can be cleared to 0 by software writing 1.
     * |[4]     |ZIF4      |PWM Zero Point Interrupt Flag 4
     * |        |          |This bit is set by hardware when PWM_CH4 counter reaches 0.
     * |        |          |Note: This bit can be cleared to 0 by software writing 1.
     * |[8]     |PIF0      |PWM Period Point Interrupt Flag 0
     * |        |          |This bit is set by hardware when PWM_CH0 counter reaches PWM_PERIOD0.
     * |        |          |Note: This bit can be cleared to 0 by software writing 1.
     * |[10]    |PIF2      |PWM Period Point Interrupt Flag 2
     * |        |          |This bit is set by hardware when PWM_CH2 counter reaches PWM_PERIOD2.
     * |        |          |Note: This bit can be cleared to 0 by software writing 1.
     * |[12]    |PIF4      |PWM Period Point Interrupt Flag 4
     * |        |          |This bit is set by hardware when PWM_CH4 counter reaches PWM_PERIOD4.
     * |        |          |Note: This bit can be cleared to 0 by software writing 1.
     * |[21:16] |CMPUIFn   |PWM Compare Up Count Interrupt Flag
     * |        |          |Flag is set by hardware when PWM counter up count and reaches PWM_CMPDATn, software can clear this bit by writing 1 to it.
     * |        |          |Note: In complementary mode, CMPUIF1, 3, 5 is used as another CMPUIF for channel 0, 2, 4.
     * |[24]    |CMPDIF0   |PWM Compare Down Count Interrupt Flag
     * |        |          |Flag is set by hardware when PWM counter down count and reaches PWM_CMPDATn, software can clear this bit by writing 1 to it.
     * |        |          |Note: In complementary mode, CMPDIF1, 3, 5 is used as another CMPDIF for channel 0, 2, 4.
     * |[25]    |CMPDIF1   |PWM Compare Down Count Interrupt Flag
     * |        |          |Flag is set by hardware when PWM counter down count and reaches PWM_CMPDATn, software can clear this bit by writing 1 to it.
     * |        |          |Note: In complementary mode, CMPDIF1, 3, 5 is used as another CMPDIF for channel 0, 2, 4.
     * |[26]    |CMPDIF2   |PWM Compare Down Count Interrupt Flag
     * |        |          |Flag is set by hardware when PWM counter down count and reaches PWM_CMPDATn, software can clear this bit by writing 1 to it.
     * |        |          |Note: In complementary mode, CMPDIF1, 3, 5 is used as another CMPDIF for channel 0, 2, 4.
     * |[27]    |CMPDIF3   |PWM Compare Down Count Interrupt Flag
     * |        |          |Flag is set by hardware when PWM counter down count and reaches PWM_CMPDATn, software can clear this bit by writing 1 to it.
     * |        |          |Note: In complementary mode, CMPDIF1, 3, 5 is used as another CMPDIF for channel 0, 2, 4.
     * |[28]    |CMPDIF4   |PWM Compare Down Count Interrupt Flag
     * |        |          |Flag is set by hardware when PWM counter down count and reaches PWM_CMPDATn, software can clear this bit by writing 1 to it.
     * |        |          |Note: In complementary mode, CMPDIF1, 3, 5 is used as another CMPDIF for channel 0, 2, 4.
     * |[29]    |CMPDIF5   |PWM Compare Down Count Interrupt Flag
     * |        |          |Flag is set by hardware when PWM counter down count and reaches PWM_CMPDATn, software can clear this bit by writing 1 to it.
     * |        |          |Note: In complementary mode, CMPDIF1, 3, 5 is used as another CMPDIF for channel 0, 2, 4.
     * @var PWM_T::INTSTS1
     * Offset: 0xEC  PWM Interrupt Flag Register 1
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |BRKEIF0   |PWM Channel n Edge-detect Brake Interrupt Flag (Write Protect)
     * |        |          |0 = PWM channel n edge-detect brake event do not happened.
     * |        |          |1 = When PWM channel n edge-detect brake event happened, this bit is set to 1, writing 1 to clear.
     * |        |          |Note: This bit is write protected. Refer to SYS_REGLCTL register.
     * |[1]     |BRKEIF1   |PWM Channel n Edge-detect Brake Interrupt Flag (Write Protect)
     * |        |          |0 = PWM channel n edge-detect brake event do not happened.
     * |        |          |1 = When PWM channel n edge-detect brake event happened, this bit is set to 1, writing 1 to clear.
     * |        |          |Note: This bit is write protected. Refer to SYS_REGLCTL register.
     * |[2]     |BRKEIF2   |PWM Channel n Edge-detect Brake Interrupt Flag (Write Protect)
     * |        |          |0 = PWM channel n edge-detect brake event do not happened.
     * |        |          |1 = When PWM channel n edge-detect brake event happened, this bit is set to 1, writing 1 to clear.
     * |        |          |Note: This bit is write protected. Refer to SYS_REGLCTL register.
     * |[3]     |BRKEIF3   |PWM Channel n Edge-detect Brake Interrupt Flag (Write Protect)
     * |        |          |0 = PWM channel n edge-detect brake event do not happened.
     * |        |          |1 = When PWM channel n edge-detect brake event happened, this bit is set to 1, writing 1 to clear.
     * |        |          |Note: This bit is write protected. Refer to SYS_REGLCTL register.
     * |[4]     |BRKEIF4   |PWM Channel n Edge-detect Brake Interrupt Flag (Write Protect)
     * |        |          |0 = PWM channel n edge-detect brake event do not happened.
     * |        |          |1 = When PWM channel n edge-detect brake event happened, this bit is set to 1, writing 1 to clear.
     * |        |          |Note: This bit is write protected. Refer to SYS_REGLCTL register.
     * |[5]     |BRKEIF5   |PWM Channel n Edge-detect Brake Interrupt Flag (Write Protect)
     * |        |          |0 = PWM channel n edge-detect brake event do not happened.
     * |        |          |1 = When PWM channel n edge-detect brake event happened, this bit is set to 1, writing 1 to clear.
     * |        |          |Note: This bit is write protected. Refer to SYS_REGLCTL register.
     * |[8]     |BRKLIF0   |PWM Channel n Level-detect Brake Interrupt Flag (Write Protect)
     * |        |          |0 = PWM channel n level-detect brake event do not happened.
     * |        |          |1 = When PWM channel n level-detect brake event happened, this bit is set to 1, writing 1 to clear.
     * |        |          |Note: This bit is write protected. Refer to SYS_REGLCTL register.
     * |[9]     |BRKLIF1   |PWM Channel n Level-detect Brake Interrupt Flag (Write Protect)
     * |        |          |0 = PWM channel n level-detect brake event do not happened.
     * |        |          |1 = When PWM channel n level-detect brake event happened, this bit is set to 1, writing 1 to clear.
     * |        |          |Note: This bit is write protected. Refer to SYS_REGLCTL register.
     * |[10]    |BRKLIF2   |PWM Channel n Level-detect Brake Interrupt Flag (Write Protect)
     * |        |          |0 = PWM channel n level-detect brake event do not happened.
     * |        |          |1 = When PWM channel n level-detect brake event happened, this bit is set to 1, writing 1 to clear.
     * |        |          |Note: This bit is write protected. Refer to SYS_REGLCTL register.
     * |[11]    |BRKLIF3   |PWM Channel n Level-detect Brake Interrupt Flag (Write Protect)
     * |        |          |0 = PWM channel n level-detect brake event do not happened.
     * |        |          |1 = When PWM channel n level-detect brake event happened, this bit is set to 1, writing 1 to clear.
     * |        |          |Note: This bit is write protected. Refer to SYS_REGLCTL register.
     * |[12]    |BRKLIF4   |PWM Channel n Level-detect Brake Interrupt Flag (Write Protect)
     * |        |          |0 = PWM channel n level-detect brake event do not happened.
     * |        |          |1 = When PWM channel n level-detect brake event happened, this bit is set to 1, writing 1 to clear.
     * |        |          |Note: This bit is write protected. Refer to SYS_REGLCTL register.
     * |[13]    |BRKLIF5   |PWM Channel n Level-detect Brake Interrupt Flag (Write Protect)
     * |        |          |0 = PWM channel n level-detect brake event do not happened.
     * |        |          |1 = When PWM channel n level-detect brake event happened, this bit is set to 1, writing 1 to clear.
     * |        |          |Note: This bit is write protected. Refer to SYS_REGLCTL register.
     * |[16]    |BRKESTS0  |PWM Channel n Edge-detect Brake Status (Read Only)
     * |        |          |0 = PWM channel n edge-detect brake state is released.
     * |        |          |1 = When PWM channel n edge-detect brake detects a falling edge of any enabled brake source; this flag will be set to indicate the PWM channel n at brake state.
     * |        |          |Note: This bit is read only and auto cleared by hardware
     * |        |          |When edge-detect brake interrupt flag is cleared, PWM will release brake state until current PWM period finished
     * |        |          |The PWM waveform will start output from next full PWM period.
     * |[17]    |BRKESTS1  |PWM Channel n Edge-detect Brake Status (Read Only)
     * |        |          |0 = PWM channel n edge-detect brake state is released.
     * |        |          |1 = When PWM channel n edge-detect brake detects a falling edge of any enabled brake source; this flag will be set to indicate the PWM channel n at brake state.
     * |        |          |Note: This bit is read only and auto cleared by hardware
     * |        |          |When edge-detect brake interrupt flag is cleared, PWM will release brake state until current PWM period finished
     * |        |          |The PWM waveform will start output from next full PWM period.
     * |[18]    |BRKESTS2  |PWM Channel n Edge-detect Brake Status (Read Only)
     * |        |          |0 = PWM channel n edge-detect brake state is released.
     * |        |          |1 = When PWM channel n edge-detect brake detects a falling edge of any enabled brake source; this flag will be set to indicate the PWM channel n at brake state.
     * |        |          |Note: This bit is read only and auto cleared by hardware
     * |        |          |When edge-detect brake interrupt flag is cleared, PWM will release brake state until current PWM period finished
     * |        |          |The PWM waveform will start output from next full PWM period.
     * |[19]    |BRKESTS3  |PWM Channel n Edge-detect Brake Status (Read Only)
     * |        |          |0 = PWM channel n edge-detect brake state is released.
     * |        |          |1 = When PWM channel n edge-detect brake detects a falling edge of any enabled brake source; this flag will be set to indicate the PWM channel n at brake state.
     * |        |          |Note: This bit is read only and auto cleared by hardware
     * |        |          |When edge-detect brake interrupt flag is cleared, PWM will release brake state until current PWM period finished
     * |        |          |The PWM waveform will start output from next full PWM period.
     * |[20]    |BRKESTS4  |PWM Channel n Edge-detect Brake Status (Read Only)
     * |        |          |0 = PWM channel n edge-detect brake state is released.
     * |        |          |1 = When PWM channel n edge-detect brake detects a falling edge of any enabled brake source; this flag will be set to indicate the PWM channel n at brake state.
     * |        |          |Note: This bit is read only and auto cleared by hardware
     * |        |          |When edge-detect brake interrupt flag is cleared, PWM will release brake state until current PWM period finished
     * |        |          |The PWM waveform will start output from next full PWM period.
     * |[21]    |BRKESTS5  |PWM Channel n Edge-detect Brake Status (Read Only)
     * |        |          |0 = PWM channel n edge-detect brake state is released.
     * |        |          |1 = When PWM channel n edge-detect brake detects a falling edge of any enabled brake source; this flag will be set to indicate the PWM channel n at brake state.
     * |        |          |Note: This bit is read only and auto cleared by hardware
     * |        |          |When edge-detect brake interrupt flag is cleared, PWM will release brake state until current PWM period finished
     * |        |          |The PWM waveform will start output from next full PWM period.
     * |[24]    |BRKLSTS0  |PWM Channel n Level-detect Brake Status (Read Only)
     * |        |          |0 = PWM channel n level-detect brake state is released.
     * |        |          |1 = When PWM channel n level-detect brake detects a falling edge of any enabled brake source; this flag will be set to indicate the PWM channel n at brake state.
     * |        |          |Note: This bit is read only and auto cleared by hardware
     * |        |          |When enabled brake source return to high level, PWM will release brake state until current PWM period finished
     * |        |          |The PWM waveform will start output from next full PWM period.
     * |[25]    |BRKLSTS1  |PWM Channel n Level-detect Brake Status (Read Only)
     * |        |          |0 = PWM channel n level-detect brake state is released.
     * |        |          |1 = When PWM channel n level-detect brake detects a falling edge of any enabled brake source; this flag will be set to indicate the PWM channel n at brake state.
     * |        |          |Note: This bit is read only and auto cleared by hardware
     * |        |          |When enabled brake source return to high level, PWM will release brake state until current PWM period finished
     * |        |          |The PWM waveform will start output from next full PWM period.
     * |[26]    |BRKLSTS2  |PWM Channel n Level-detect Brake Status (Read Only)
     * |        |          |0 = PWM channel n level-detect brake state is released.
     * |        |          |1 = When PWM channel n level-detect brake detects a falling edge of any enabled brake source; this flag will be set to indicate the PWM channel n at brake state.
     * |        |          |Note: This bit is read only and auto cleared by hardware
     * |        |          |When enabled brake source return to high level, PWM will release brake state until current PWM period finished
     * |        |          |The PWM waveform will start output from next full PWM period.
     * |[27]    |BRKLSTS3  |PWM Channel n Level-detect Brake Status (Read Only)
     * |        |          |0 = PWM channel n level-detect brake state is released.
     * |        |          |1 = When PWM channel n level-detect brake detects a falling edge of any enabled brake source; this flag will be set to indicate the PWM channel n at brake state.
     * |        |          |Note: This bit is read only and auto cleared by hardware
     * |        |          |When enabled brake source return to high level, PWM will release brake state until current PWM period finished
     * |        |          |The PWM waveform will start output from next full PWM period.
     * |[28]    |BRKLSTS4  |PWM Channel n Level-detect Brake Status (Read Only)
     * |        |          |0 = PWM channel n level-detect brake state is released.
     * |        |          |1 = When PWM channel n level-detect brake detects a falling edge of any enabled brake source; this flag will be set to indicate the PWM channel n at brake state.
     * |        |          |Note: This bit is read only and auto cleared by hardware
     * |        |          |When enabled brake source return to high level, PWM will release brake state until current PWM period finished
     * |        |          |The PWM waveform will start output from next full PWM period.
     * |[29]    |BRKLSTS5  |PWM Channel n Level-detect Brake Status (Read Only)
     * |        |          |0 = PWM channel n level-detect brake state is released.
     * |        |          |1 = When PWM channel n level-detect brake detects a falling edge of any enabled brake source; this flag will be set to indicate the PWM channel n at brake state.
     * |        |          |Note: This bit is read only and auto cleared by hardware
     * |        |          |When enabled brake source return to high level, PWM will release brake state until current PWM period finished
     * |        |          |The PWM waveform will start output from next full PWM period.
     * @var PWM_T::ADCTS0
     * Offset: 0xF8  PWM Trigger ADC Source Select Register 0
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[3:0]   |TRGSEL0   |PWM_CH0 Trigger ADC Source Select
     * |        |          |0000 = PWM_CH0 zero point.
     * |        |          |0001 = PWM_CH0 period point.
     * |        |          |0010 = PWM_CH0 zero or period point.
     * |        |          |0011 = PWM_CH0 up-count CMPDAT point.
     * |        |          |0100 = PWM_CH0 down-count CMPDAT point.
     * |        |          |0101 = Reserved.
     * |        |          |0110 = Reserved.
     * |        |          |0111 = Reserved.
     * |        |          |1000 = PWM_CH1 up-count CMPDAT point.
     * |        |          |1001 = PWM_CH1 down-count CMPDAT point.
     * |        |          |Others = reserved.
     * |[7]     |TRGEN0    |PWM_CH0 Trigger ADC Enable Bit
     * |        |          |0 = PWM_CH0 Trigger ADC function Disabled.
     * |        |          |1 = PWM_CH0 Trigger ADC function Enabled.
     * |[11:8]  |TRGSEL1   |PWM_CH1 Trigger ADC Source Select
     * |        |          |0000 = PWM_CH0 zero point.
     * |        |          |0001 = PWM_CH0 period point.
     * |        |          |0010 = PWM_CH0 zero or period point.
     * |        |          |0011 = PWM_CH0 up-count CMPDAT point.
     * |        |          |0100 = PWM_CH0 down-count CMPDAT point.
     * |        |          |0101 = Reserved.
     * |        |          |0110 = Reserved.
     * |        |          |0111 = Reserved.
     * |        |          |1000 = PWM_CH1 up-count CMPDAT point.
     * |        |          |1001 = PWM_CH1 down-count CMPDAT point.
     * |        |          |Others = reserved.
     * |[15]    |TRGEN1    |PWM_CH1 Trigger ADC Enable Bit
     * |        |          |0 = PWM_CH1 Trigger ADC function Disabled.
     * |        |          |1 = PWM_CH1 Trigger ADC function Enabled.
     * |[19:16] |TRGSEL2   |PWM_CH2 Trigger ADC Source Select
     * |        |          |0000 = PWM_CH2 zero point.
     * |        |          |0001 = PWM_CH2 period point.
     * |        |          |0010 = PWM_CH2 zero or period point.
     * |        |          |0011 = PWM_CH2 up-count CMPDAT point.
     * |        |          |0100 = PWM_CH2 down-count CMPDAT point.
     * |        |          |0101 = Reserved.
     * |        |          |0110 = Reserved.
     * |        |          |0111 = Reserved.
     * |        |          |1000 = PWM_CH3 up-count CMPDAT point.
     * |        |          |1001 = PWM_CH3 down-count CMPDAT point.
     * |        |          |Others = reserved.
     * |[23]    |TRGEN2    |PWM_CH2 Trigger ADC Enable Bit
     * |        |          |0 = PWM_CH2 Trigger ADC function Disabled.
     * |        |          |1 = PWM_CH2 Trigger ADC function Enabled.
     * |[27:24] |TRGSEL3   |PWM_CH3 Trigger ADC Source Select
     * |        |          |0000 = PWM_CH2 zero point.
     * |        |          |0001 = PWM_CH2 period point.
     * |        |          |0010 = PWM_CH2 zero or period point.
     * |        |          |0011 = PWM_CH2 up-count CMPDAT point.
     * |        |          |0100 = PWM_CH2 down-count CMPDAT point.
     * |        |          |0101 = Reserved.
     * |        |          |0110 = Reserved.
     * |        |          |0111 = Reserved.
     * |        |          |1000 = PWM_CH3 up-count CMPDAT point.
     * |        |          |1001 = PWM_CH3 down-count CMPDAT point.
     * |        |          |Others = reserved.
     * |[31]    |TRGEN3    |PWM_CH3 Trigger ADC Enable Bit
     * |        |          |0 = PWM_CH3 Trigger ADC function Disabled.
     * |        |          |1 = PWM_CH3 Trigger ADC function Enabled.
     * @var PWM_T::ADCTS1
     * Offset: 0xFC  PWM Trigger ADC Source Select Register 1
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[3:0]   |TRGSEL4   |PWM_CH4 Trigger ADC Source Select
     * |        |          |0000 = PWM_CH4 zero point.
     * |        |          |0001 = PWM_CH4 period point.
     * |        |          |0010 = PWM_CH4 zero or period point.
     * |        |          |0011 = PWM_CH4 up-count CMPDAT point.
     * |        |          |0100 = PWM_CH4 down-count CMPDAT point.
     * |        |          |0101 = Reserved.
     * |        |          |0110 = Reserved.
     * |        |          |0111 = Reserved.
     * |        |          |1000 = PWM_CH5 up-count CMPDAT point.
     * |        |          |1001 = PWM_CH5 down-count CMPDAT point.
     * |        |          |Others = reserved.
     * |[7]     |TRGEN4    |PWM_CH4 Trigger ADC Enable Bit
     * |        |          |0 = PWM_CH4 Trigger ADC function Disabled.
     * |        |          |1 = PWM_CH4 Trigger ADC function Enabled.
     * |[11:8]  |TRGSEL5   |PWM_CH5 Trigger ADC Source Select
     * |        |          |0000 = PWM_CH4 zero point.
     * |        |          |0001 = PWM_CH4 period point.
     * |        |          |0010 = PWM_CH4 zero or period point.
     * |        |          |0011 = PWM_CH4 up-count CMPDAT point.
     * |        |          |0100 = PWM_CH4 down-count CMPDAT point.
     * |        |          |0101 = Reserved.
     * |        |          |0110 = Reserved.
     * |        |          |0111 = Reserved.
     * |        |          |1000 = PWM_CH5 up-count CMPDAT point.
     * |        |          |1001 = PWM_CH5 down-count CMPDAT point.
     * |        |          |Others = reserved.
     * |[15]    |TRGEN5    |PWM_CH5 Trigger ADC Enable Bit
     * |        |          |0 = PWM_CH5 Trigger ADC function Disabled.
     * |        |          |1 = PWM_CH5 Trigger ADC function Enabled.
     * @var PWM_T::SSCTL
     * Offset: 0x110  PWM Synchronous Start Control Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |SSEN0     |PWM Synchronous Start Function Enable Bit 0
     * |        |          |When synchronous start function is enabled, the PWM_CH0 counter enable bit (CNTEN0) can be enabled by writing PWM synchronous start trigger bit (CNTSEN).
     * |        |          |0 = PWM synchronous start function Disabled.
     * |        |          |1 = PWM synchronous start function Enabled.
     * |[2]     |SSEN2     |PWM Synchronous Start Function Enable Bit 2
     * |        |          |When synchronous start function is enabled, the PWM_CH2 counter enable bit (CNTEN2) can be enabled by writing PWM synchronous start trigger bit (CNTSEN).
     * |        |          |0 = PWM synchronous start function Disabled.
     * |        |          |1 = PWM synchronous start function Enabled.
     * |[4]     |SSEN4     |PWM Synchronous Start Function Enable Bit 4
     * |        |          |When synchronous start function is enabled, the PWM_CH4 counter enable bit (CNTEN4) can be enabled by writing PWM synchronous start trigger bit (CNTSEN).
     * |        |          |0 = PWM synchronous start function Disabled.
     * |        |          |1 = PWM synchronous start function Enabled.
     * |[9:8]   |SSRC      |PWM Synchronous Start Source Select Bits
     * |        |          |00 = Synchronous start source come from PWM0.
     * |        |          |10 = Synchronous start source come from BPWM0.
     * |        |          |11 = Reserved.
     * @var PWM_T::SSTRG
     * Offset: 0x114  PWM Synchronous Start Trigger Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |CNTSEN    |PWM Counter Synchronous Start Enable (Write Only)
     * |        |          |PWM counter synchronous enable function is used to make selected PWM channels (include PWM0_CHx) start counting at the same time.
     * |        |          |Writing this bit to 1 will also set the counter enable bit (CNTENn, n = 0, 2, 4) if correlated PWM channel counter synchronous start function is enabled.
     * @var PWM_T::STATUS
     * Offset: 0x120  PWM Status Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |CNTMAX0   |Time-base Counter 0 Equal to 0xFFFF Latched Flag
     * |        |          |0 = indicates the time-base counter never reached its maximum value 0xFFFF.
     * |        |          |1 = indicates the time-base counter reached its maximum value.
     * |        |          |Note: This bit can be cleared by software writing 1.
     * |[2]     |CNTMAX2   |Time-base Counter 2 Equal to 0xFFFF Latched Flag
     * |        |          |0 = indicates the time-base counter never reached its maximum value 0xFFFF.
     * |        |          |1 = indicates the time-base counter reached its maximum value.
     * |        |          |Note: This bit can be cleared by software writing 1.
     * |[4]     |CNTMAX4   |Time-base Counter 4 Equal to 0xFFFF Latched Flag
     * |        |          |0 = The time-base counter never reached its maximum value 0xFFFF.
     * |        |          |1 = The time-base counter reached its maximum value.
     * |        |          |Note: This bit can be cleared by software writing 1.
     * |[16]    |ADCTRG0   |ADC Start of Conversion Status
     * |        |          |Each bit n controls the corresponding PWM channel n.
     * |        |          |0 = No ADC start of conversion trigger event has occurred.
     * |        |          |1 = An ADC start of conversion trigger event has occurred.
     * |        |          |Note: This bit can be cleared by software write 1.
     * |[17]    |ADCTRG1   |ADC Start of Conversion Status
     * |        |          |Each bit n controls the corresponding PWM channel n.
     * |        |          |0 = No ADC start of conversion trigger event has occurred.
     * |        |          |1 = An ADC start of conversion trigger event has occurred.
     * |        |          |Note: This bit can be cleared by software write 1.
     * |[18]    |ADCTRG2   |ADC Start of Conversion Status
     * |        |          |Each bit n controls the corresponding PWM channel n.
     * |        |          |0 = No ADC start of conversion trigger event has occurred.
     * |        |          |1 = An ADC start of conversion trigger event has occurred.
     * |        |          |Note: This bit can be cleared by software write 1.
     * |[19]    |ADCTRG3   |ADC Start of Conversion Status
     * |        |          |Each bit n controls the corresponding PWM channel n.
     * |        |          |0 = No ADC start of conversion trigger event has occurred.
     * |        |          |1 = An ADC start of conversion trigger event has occurred.
     * |        |          |Note: This bit can be cleared by software write 1.
     * |[20]    |ADCTRG4   |ADC Start of Conversion Status
     * |        |          |Each bit n controls the corresponding PWM channel n.
     * |        |          |0 = No ADC start of conversion trigger event has occurred.
     * |        |          |1 = An ADC start of conversion trigger event has occurred.
     * |        |          |Note: This bit can be cleared by software write 1.
     * |[21]    |ADCTRG5   |ADC Start of Conversion Status
     * |        |          |Each bit n controls the corresponding PWM channel n.
     * |        |          |0 = No ADC start of conversion trigger event has occurred.
     * |        |          |1 = An ADC start of conversion trigger event has occurred.
     * |        |          |Note: This bit can be cleared by software write 1.
     * @var PWM_T::IFA[6]
     * Offset: 0x130  PWM Interrupt Flag Accumulator Register 0/2/4
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[7:0]   |IFACNT    |PWM_CHn Interrupt Flag Counter
     * |        |          |The register sets the count number which defines (IFACNT+1) times of PWM_CHn period occurs to set bit IFAIFn to request the PWM period interrupt
     * |        |          |PWM flag will be set in every IFACNT[15:0] times of PWM period.
     * |[24]    |STPMOD    |PWM_CHn Accumulator Stop Mode Enable Bits
     * |        |          |0 = PWM_CHn Stop Mode Disable.
     * |        |          |1 = PWM_CHn Stop Mode Enable.
     * |[29:28] |IFASEL    |PWM_CHn Interrupt Flag Accumulator Source Select
     * |        |          |00 = PWM_CHn zero point.
     * |        |          |01 = PWM_CHn period in channel n.
     * |        |          |10 = PWM_CHn up-count compared point.
     * |        |          |11 = PWM_CHn down-count compared point.
     * |[31]    |IFAEN     |PWM_CHn Interrupt Flag Accumulator Enable Bits
     * |        |          |0 = PWM_CHn interrupt flag accumulator Disabled.
     * |        |          |1 = PWM_CHn interrupt flag accumulator Enabled.
     * @var PWM_T::AINTSTS
     * Offset: 0x150  PWM Accumulator Interrupt Flag Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |IFAIF0    |PWM_CH0 Interrupt Flag Accumulator Interrupt Flag
     * |        |          |Flag is set by hardware when condition match IFASEL in PWM_IFAn register, software can clear this bit by writing 1 to it.
     * |[2]     |IFAIF2    |PWM_CH2 Interrupt Flag Accumulator Interrupt Flag
     * |        |          |Flag is set by hardware when condition match IFASEL in PWM_IFAn register, software can clear this bit by writing 1 to it.
     * |[4]     |IFAIF4    |PWM_CH4 Interrupt Flag Accumulator Interrupt Flag
     * |        |          |Flag is set by hardware when condition match IFASEL in PWM_IFAn register, software can clear this bit by writing 1 to it.
     * @var PWM_T::AINTEN
     * Offset: 0x154  PWM Accumulator Interrupt Enable Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |IFAIEN0   |PWM_CH0 Interrupt Flag Accumulator Interrupt Enable Bits
     * |        |          |0 = Interrupt Flag accumulator interrupt Disabled.
     * |        |          |1 = Interrupt Flag accumulator interrupt Enabled.
     * |[2]     |IFAIEN2   |PWM_CH2 Interrupt Flag Accumulator Interrupt Enable Bits
     * |        |          |0 = Interrupt Flag accumulator interrupt Disabled.
     * |        |          |1 = Interrupt Flag accumulator interrupt Enabled.
     * |[4]     |IFAIEN4   |PWM_CH4 Interrupt Flag Accumulator Interrupt Enable Bits
     * |        |          |0 = Interrupt Flag accumulator interrupt Disabled.
     * |        |          |1 = Interrupt Flag accumulator interrupt Enabled.
     * @var PWM_T::APDMACTL
     * Offset: 0x158  PWM Accumulator PDMA Control Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |APDMAEN0  |Channel n Accumulator PDMA Enable Bits
     * |        |          |0 = Channel n PDMA function Disabled.
     * |        |          |1 = Channel n PDMA function Enabled for the channel n to trigger PDMA to transfer memory data to register.
     * |[1]     |APDMAEN1  |Channel n Accumulator PDMA Enable Bits
     * |        |          |0 = Channel n PDMA function Disabled.
     * |        |          |1 = Channel n PDMA function Enabled for the channel n to trigger PDMA to transfer memory data to register.
     * |[2]     |APDMAEN2  |Channel n Accumulator PDMA Enable Bits
     * |        |          |0 = Channel n PDMA function Disabled.
     * |        |          |1 = Channel n PDMA function Enabled for the channel n to trigger PDMA to transfer memory data to register.
     * |[3]     |APDMAEN3  |Channel n Accumulator PDMA Enable Bits
     * |        |          |0 = Channel n PDMA function Disabled.
     * |        |          |1 = Channel n PDMA function Enabled for the channel n to trigger PDMA to transfer memory data to register.
     * |[4]     |APDMAEN4  |Channel n Accumulator PDMA Enable Bits
     * |        |          |0 = Channel n PDMA function Disabled.
     * |        |          |1 = Channel n PDMA function Enabled for the channel n to trigger PDMA to transfer memory data to register.
     * |[5]     |APDMAEN5  |Channel n Accumulator PDMA Enable Bits
     * |        |          |0 = Channel n PDMA function Disabled.
     * |        |          |1 = Channel n PDMA function Enabled for the channel n to trigger PDMA to transfer memory data to register.
     * @var PWM_T::CAPINEN
     * Offset: 0x200  PWM Capture Input Enable Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |CAPINEN0  |Capture Input Enable Bits
     * |        |          |0 = PWM Channel capture input path Disabled
     * |        |          |The input of PWM channel capture function is always regarded as 0.
     * |        |          |1 = PWM Channel capture input path Enabled
     * |        |          |The input of PWM channel capture function comes from correlative multifunction pin.
     * |[1]     |CAPINEN1  |Capture Input Enable Bits
     * |        |          |0 = PWM Channel capture input path Disabled
     * |        |          |The input of PWM channel capture function is always regarded as 0.
     * |        |          |1 = PWM Channel capture input path Enabled
     * |        |          |The input of PWM channel capture function comes from correlative multifunction pin.
     * |[2]     |CAPINEN2  |Capture Input Enable Bits
     * |        |          |0 = PWM Channel capture input path Disabled
     * |        |          |The input of PWM channel capture function is always regarded as 0.
     * |        |          |1 = PWM Channel capture input path Enabled
     * |        |          |The input of PWM channel capture function comes from correlative multifunction pin.
     * |[3]     |CAPINEN3  |Capture Input Enable Bits
     * |        |          |0 = PWM Channel capture input path Disabled
     * |        |          |The input of PWM channel capture function is always regarded as 0.
     * |        |          |1 = PWM Channel capture input path Enabled
     * |        |          |The input of PWM channel capture function comes from correlative multifunction pin.
     * |[4]     |CAPINEN4  |Capture Input Enable Bits
     * |        |          |0 = PWM Channel capture input path Disabled
     * |        |          |The input of PWM channel capture function is always regarded as 0.
     * |        |          |1 = PWM Channel capture input path Enabled
     * |        |          |The input of PWM channel capture function comes from correlative multifunction pin.
     * |[5]     |CAPINEN5  |Capture Input Enable Bits
     * |        |          |0 = PWM Channel capture input path Disabled
     * |        |          |The input of PWM channel capture function is always regarded as 0.
     * |        |          |1 = PWM Channel capture input path Enabled
     * |        |          |The input of PWM channel capture function comes from correlative multifunction pin.
     * @var PWM_T::CAPCTL
     * Offset: 0x204  PWM Capture Control Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |CAPEN0    |Capture Function Enable Bits
     * |        |          |0 = Capture function Disabled. RCAPDAT/FCAPDAT register will not be updated.
     * |        |          |1 = Capture function Enabled
     * |        |          |Capture latched the PWM counter value when detected rising or falling edge of input signal and saved to RCAPDAT (Rising latch) and FCAPDAT (Falling latch).
     * |[1]     |CAPEN1    |Capture Function Enable Bits
     * |        |          |0 = Capture function Disabled. RCAPDAT/FCAPDAT register will not be updated.
     * |        |          |1 = Capture function Enabled
     * |        |          |Capture latched the PWM counter value when detected rising or falling edge of input signal and saved to RCAPDAT (Rising latch) and FCAPDAT (Falling latch).
     * |[2]     |CAPEN2    |Capture Function Enable Bits
     * |        |          |0 = Capture function Disabled. RCAPDAT/FCAPDAT register will not be updated.
     * |        |          |1 = Capture function Enabled
     * |        |          |Capture latched the PWM counter value when detected rising or falling edge of input signal and saved to RCAPDAT (Rising latch) and FCAPDAT (Falling latch).
     * |[3]     |CAPEN3    |Capture Function Enable Bits
     * |        |          |0 = Capture function Disabled. RCAPDAT/FCAPDAT register will not be updated.
     * |        |          |1 = Capture function Enabled
     * |        |          |Capture latched the PWM counter value when detected rising or falling edge of input signal and saved to RCAPDAT (Rising latch) and FCAPDAT (Falling latch).
     * |[4]     |CAPEN4    |Capture Function Enable Bits
     * |        |          |0 = Capture function Disabled. RCAPDAT/FCAPDAT register will not be updated.
     * |        |          |1 = Capture function Enabled
     * |        |          |Capture latched the PWM counter value when detected rising or falling edge of input signal and saved to RCAPDAT (Rising latch) and FCAPDAT (Falling latch).
     * |[5]     |CAPEN5    |Capture Function Enable Bits
     * |        |          |0 = Capture function Disabled. RCAPDAT/FCAPDAT register will not be updated.
     * |        |          |1 = Capture function Enabled
     * |        |          |Capture latched the PWM counter value when detected rising or falling edge of input signal and saved to RCAPDAT (Rising latch) and FCAPDAT (Falling latch).
     * |[8]     |CAPINV0   |Capture Inverter Enable Bits
     * |        |          |0 = Capture source inverter Disabled.
     * |        |          |1 = Capture source inverter Enabled. Reverse the input signal from GPIO.
     * |[9]     |CAPINV1   |Capture Inverter Enable Bits
     * |        |          |0 = Capture source inverter Disabled.
     * |        |          |1 = Capture source inverter Enabled. Reverse the input signal from GPIO.
     * |[10]    |CAPINV2   |Capture Inverter Enable Bits
     * |        |          |0 = Capture source inverter Disabled.
     * |        |          |1 = Capture source inverter Enabled. Reverse the input signal from GPIO.
     * |[11]    |CAPINV3   |Capture Inverter Enable Bits
     * |        |          |0 = Capture source inverter Disabled.
     * |        |          |1 = Capture source inverter Enabled. Reverse the input signal from GPIO.
     * |[12]    |CAPINV4   |Capture Inverter Enable Bits
     * |        |          |0 = Capture source inverter Disabled.
     * |        |          |1 = Capture source inverter Enabled. Reverse the input signal from GPIO.
     * |[13]    |CAPINV5   |Capture Inverter Enable Bits
     * |        |          |0 = Capture source inverter Disabled.
     * |        |          |1 = Capture source inverter Enabled. Reverse the input signal from GPIO.
     * |[16]    |RCRLDEN0  |Rising Capture Reload Enable Bits
     * |        |          |0 = Rising capture reload counter Disabled.
     * |        |          |1 = Rising capture reload counter Enabled.
     * |[17]    |RCRLDEN1  |Rising Capture Reload Enable Bits
     * |        |          |0 = Rising capture reload counter Disabled.
     * |        |          |1 = Rising capture reload counter Enabled.
     * |[18]    |RCRLDEN2  |Rising Capture Reload Enable Bits
     * |        |          |0 = Rising capture reload counter Disabled.
     * |        |          |1 = Rising capture reload counter Enabled.
     * |[19]    |RCRLDEN3  |Rising Capture Reload Enable Bits
     * |        |          |0 = Rising capture reload counter Disabled.
     * |        |          |1 = Rising capture reload counter Enabled.
     * |[20]    |RCRLDEN4  |Rising Capture Reload Enable Bits
     * |        |          |0 = Rising capture reload counter Disabled.
     * |        |          |1 = Rising capture reload counter Enabled.
     * |[21]    |RCRLDEN5  |Rising Capture Reload Enable Bits
     * |        |          |0 = Rising capture reload counter Disabled.
     * |        |          |1 = Rising capture reload counter Enabled.
     * |[24]    |FCRLDEN0  |Falling Capture Reload Enable Bits
     * |        |          |0 = Falling capture reload counter Disabled.
     * |        |          |1 = Falling capture reload counter Enabled.
     * |[25]    |FCRLDEN1  |Falling Capture Reload Enable Bits
     * |        |          |0 = Falling capture reload counter Disabled.
     * |        |          |1 = Falling capture reload counter Enabled.
     * |[26]    |FCRLDEN2  |Falling Capture Reload Enable Bits
     * |        |          |0 = Falling capture reload counter Disabled.
     * |        |          |1 = Falling capture reload counter Enabled.
     * |[27]    |FCRLDEN3  |Falling Capture Reload Enable Bits
     * |        |          |0 = Falling capture reload counter Disabled.
     * |        |          |1 = Falling capture reload counter Enabled.
     * |[28]    |FCRLDEN4  |Falling Capture Reload Enable Bits
     * |        |          |0 = Falling capture reload counter Disabled.
     * |        |          |1 = Falling capture reload counter Enabled.
     * |[29]    |FCRLDEN5  |Falling Capture Reload Enable Bits
     * |        |          |0 = Falling capture reload counter Disabled.
     * |        |          |1 = Falling capture reload counter Enabled.
     * @var PWM_T::CAPSTS
     * Offset: 0x208  PWM Capture Status Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |CRLIFOV0  |Capture Rising Latch Interrupt Flag Overrun Status (Read Only)
     * |        |          |This flag indicates if rising latch happened when the corresponding CRLIF is 1.
     * |        |          |Note: This bit will be cleared automatically when user clear corresponding CRLIF.
     * |[1]     |CRLIFOV1  |Capture Rising Latch Interrupt Flag Overrun Status (Read Only)
     * |        |          |This flag indicates if rising latch happened when the corresponding CRLIF is 1.
     * |        |          |Note: This bit will be cleared automatically when user clear corresponding CRLIF.
     * |[2]     |CRLIFOV2  |Capture Rising Latch Interrupt Flag Overrun Status (Read Only)
     * |        |          |This flag indicates if rising latch happened when the corresponding CRLIF is 1.
     * |        |          |Note: This bit will be cleared automatically when user clear corresponding CRLIF.
     * |[3]     |CRLIFOV3  |Capture Rising Latch Interrupt Flag Overrun Status (Read Only)
     * |        |          |This flag indicates if rising latch happened when the corresponding CRLIF is 1.
     * |        |          |Note: This bit will be cleared automatically when user clear corresponding CRLIF.
     * |[4]     |CRLIFOV4  |Capture Rising Latch Interrupt Flag Overrun Status (Read Only)
     * |        |          |This flag indicates if rising latch happened when the corresponding CRLIF is 1.
     * |        |          |Note: This bit will be cleared automatically when user clear corresponding CRLIF.
     * |[5]     |CRLIFOV5  |Capture Rising Latch Interrupt Flag Overrun Status (Read Only)
     * |        |          |This flag indicates if rising latch happened when the corresponding CRLIF is 1.
     * |        |          |Note: This bit will be cleared automatically when user clear corresponding CRLIF.
     * |[8]     |CFLIFOV0  |Capture Falling Latch Interrupt Flag Overrun Status (Read Only)
     * |        |          |This flag indicates if falling latch happened when the corresponding CFLIF is 1.
     * |        |          |Note: This bit will be cleared automatically when user clear corresponding CFLIF.
     * |[9]     |CFLIFOV1  |Capture Falling Latch Interrupt Flag Overrun Status (Read Only)
     * |        |          |This flag indicates if falling latch happened when the corresponding CFLIF is 1.
     * |        |          |Note: This bit will be cleared automatically when user clear corresponding CFLIF.
     * |[10]    |CFLIFOV2  |Capture Falling Latch Interrupt Flag Overrun Status (Read Only)
     * |        |          |This flag indicates if falling latch happened when the corresponding CFLIF is 1.
     * |        |          |Note: This bit will be cleared automatically when user clear corresponding CFLIF.
     * |[11]    |CFLIFOV3  |Capture Falling Latch Interrupt Flag Overrun Status (Read Only)
     * |        |          |This flag indicates if falling latch happened when the corresponding CFLIF is 1.
     * |        |          |Note: This bit will be cleared automatically when user clear corresponding CFLIF.
     * |[12]    |CFLIFOV4  |Capture Falling Latch Interrupt Flag Overrun Status (Read Only)
     * |        |          |This flag indicates if falling latch happened when the corresponding CFLIF is 1.
     * |        |          |Note: This bit will be cleared automatically when user clear corresponding CFLIF.
     * |[13]    |CFLIFOV5  |Capture Falling Latch Interrupt Flag Overrun Status (Read Only)
     * |        |          |This flag indicates if falling latch happened when the corresponding CFLIF is 1.
     * |        |          |Note: This bit will be cleared automatically when user clear corresponding CFLIF.
     * @var PWM_T::RCAPDAT0
     * Offset: 0x20C  PWM Rising Capture Data Register 0
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[15:0]  |RCAPDAT   |PWM Rising Capture Data Register (Read Only)
     * |        |          |When rising capture condition happened, the PWM counter value will be saved in this register.
     * @var PWM_T::FCAPDAT0
     * Offset: 0x210  PWM Falling Capture Data Register 0
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[15:0]  |FCAPDAT   |PWM Falling Capture Data Register (Read Only)
     * |        |          |When falling capture condition happened, the PWM counter value will be saved in this register.
     * @var PWM_T::RCAPDAT1
     * Offset: 0x214  PWM Rising Capture Data Register 1
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[15:0]  |RCAPDAT   |PWM Rising Capture Data Register (Read Only)
     * |        |          |When rising capture condition happened, the PWM counter value will be saved in this register.
     * @var PWM_T::FCAPDAT1
     * Offset: 0x218  PWM Falling Capture Data Register 1
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[15:0]  |FCAPDAT   |PWM Falling Capture Data Register (Read Only)
     * |        |          |When falling capture condition happened, the PWM counter value will be saved in this register.
     * @var PWM_T::RCAPDAT2
     * Offset: 0x21C  PWM Rising Capture Data Register 2
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[15:0]  |RCAPDAT   |PWM Rising Capture Data Register (Read Only)
     * |        |          |When rising capture condition happened, the PWM counter value will be saved in this register.
     * @var PWM_T::FCAPDAT2
     * Offset: 0x220  PWM Falling Capture Data Register 2
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[15:0]  |FCAPDAT   |PWM Falling Capture Data Register (Read Only)
     * |        |          |When falling capture condition happened, the PWM counter value will be saved in this register.
     * @var PWM_T::RCAPDAT3
     * Offset: 0x224  PWM Rising Capture Data Register 3
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[15:0]  |RCAPDAT   |PWM Rising Capture Data Register (Read Only)
     * |        |          |When rising capture condition happened, the PWM counter value will be saved in this register.
     * @var PWM_T::FCAPDAT3
     * Offset: 0x228  PWM Falling Capture Data Register 3
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[15:0]  |FCAPDAT   |PWM Falling Capture Data Register (Read Only)
     * |        |          |When falling capture condition happened, the PWM counter value will be saved in this register.
     * @var PWM_T::RCAPDAT4
     * Offset: 0x22C  PWM Rising Capture Data Register 4
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[15:0]  |RCAPDAT   |PWM Rising Capture Data Register (Read Only)
     * |        |          |When rising capture condition happened, the PWM counter value will be saved in this register.
     * @var PWM_T::FCAPDAT4
     * Offset: 0x230  PWM Falling Capture Data Register 4
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[15:0]  |FCAPDAT   |PWM Falling Capture Data Register (Read Only)
     * |        |          |When falling capture condition happened, the PWM counter value will be saved in this register.
     * @var PWM_T::RCAPDAT5
     * Offset: 0x234  PWM Rising Capture Data Register 5
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[15:0]  |RCAPDAT   |PWM Rising Capture Data Register (Read Only)
     * |        |          |When rising capture condition happened, the PWM counter value will be saved in this register.
     * @var PWM_T::FCAPDAT5
     * Offset: 0x238  PWM Falling Capture Data Register 5
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[15:0]  |FCAPDAT   |PWM Falling Capture Data Register (Read Only)
     * |        |          |When falling capture condition happened, the PWM counter value will be saved in this register.
     * @var PWM_T::PDMACTL
     * Offset: 0x23C  PWM PDMA Control Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |CHEN0_1   |Channel 0/1 PDMA Enable Bit
     * |        |          |0 = Channel 0/1 PDMA function Disabled.
     * |        |          |1 = Channel 0/1 PDMA function Enabled for the channel 0/1 captured data and transfer to memory.
     * |        |          |Note: If the PDMA function is not supported, this bit field will become invalid.
     * |[2:1]   |CAPMOD0_1 |Select PWM_RCAPDAT0/1 or PWM_FCAPDAT0/1 to Do PDMA Transfer
     * |        |          |00 = Reserved.
     * |        |          |01 = PWM_RCAPDAT0/1.
     * |        |          |10 = PWM_FCAPDAT0/1.
     * |        |          |11 = Both PWM_RCAPDAT0/1 and PWM_FCAPDAT0/1.
     * |        |          |Note: If the PDMA function is not supported, this bit field will become invalid.
     * |[3]     |CAPORD0_1 |Capture Channel 0/1 Rising/Falling Order
     * |        |          |Set this bit to determine whether the PWM_RCAPDAT0/1 or PWM_FCAPDAT0/1 is the first captured data transferred to memory through PDMA when CAPMOD0_1 =11.
     * |        |          |0 = PWM_FCAPDAT0/1 is the first captured data to memory.
     * |        |          |1 = PWM_RCAPDAT0/1 is the first captured data to memory.
     * |        |          |Note: If the PDMA function is not supported, this bit field will become invalid.
     * |[4]     |CHSEL0_1  |Select Channel 0/1 to Do PDMA Transfer
     * |        |          |0 = Channel0.
     * |        |          |1 = Channel1.
     * |        |          |Note: If the PDMA function is not supported, this bit field will become invalid.
     * |[8]     |CHEN2_3   |Channel 2/3 PDMA Enable Bit
     * |        |          |0 = Channel 2/3 PDMA function Disabled.
     * |        |          |1 = Channel 2/3 PDMA function Enabled for the channel 2/3 captured data and transfer to memory.
     * |        |          |Note: If the PDMA function is not supported, this bit field will become invalid.
     * |[10:9]  |CAPMOD2_3 |Select PWM_RCAPDAT2/3 or PWM_FCAODAT2/3 to Do PDMA Transfer
     * |        |          |00 = Reserved.
     * |        |          |01 = PWM_RCAPDAT2/3.
     * |        |          |10 = PWM_FCAPDAT2/3.
     * |        |          |11 = Both PWM_RCAPDAT2/3 and PWM_FCAPDAT2/3.
     * |        |          |Note: If the PDMA function is not supported, this bit field will become invalid.
     * |[11]    |CAPORD2_3 |Capture Channel 2/3 Rising/Falling Order
     * |        |          |Set this bit to determine whether the PWM_RCAPDAT2/3 or PWM_FCAPDAT2/3 is the first captured data transferred to memory through PDMA when CAPMOD2_3 =11.
     * |        |          |0 = PWM_FCAPDAT2/3 is the first captured data to memory.
     * |        |          |1 = PWM_RCAPDAT2/3 is the first captured data to memory.
     * |        |          |Note: If the PDMA function is not supported, this bit field will become invalid.
     * |[12]    |CHSEL2_3  |Select Channel 2/3 to Do PDMA Transfer
     * |        |          |0 = Channel2.
     * |        |          |1 = Channel3.
     * |        |          |Note: If the PDMA function is not supported, this bit field will become invalid.
     * |[16]    |CHEN4_5   |Channel 4/5 PDMA Enable Bit
     * |        |          |0 = Channel 4/5 PDMA function Disabled.
     * |        |          |1 = Channel 4/5 PDMA function Enabled for the channel 4/5 captured data and transfer to memory.
     * |        |          |Note: If the PDMA function is not supported, this bit field will become invalid.
     * |[18:17] |CAPMOD4_5 |Select PWM_RCAPDAT4/5 or PWM_FCAPDAT4/5 to Do PDMA Transfer
     * |        |          |00 = Reserved.
     * |        |          |01 = PWM_RCAPDAT4/5.
     * |        |          |10 = PWM_FCAPDAT4/5.
     * |        |          |11 = Both PWM_RCAPDAT4/5 and PWM_FCAPDAT4/5.
     * |        |          |Note: If the PDMA function is not supported, this bit field will become invalid.
     * |[19]    |CAPORD4_5 |Capture Channel 4/5 Rising/Falling Order
     * |        |          |Set this bit to determine whether the PWM_RCAPDAT4/5 or PWM_FCAPDAT4/5 is the first captured data transferred to memory through PDMA when CAPMOD4_5 =11.
     * |        |          |0 = PWM_FCAPDAT4/5 is the first captured data to memory.
     * |        |          |1 = PWM_RCAPDAT4/5 is the first captured data to memory.
     * |        |          |Note: If the PDMA function is not supported, this bit field will become invalid.
     * |[20]    |CHSEL4_5  |Select Channel 4/5 to Do PDMA Transfer
     * |        |          |0 = Channel4.
     * |        |          |1 = Channel5.
     * |        |          |Note: If the PDMA function is not supported, this bit field will become invalid.
     * @var PWM_T::PDMACAP0_1
     * Offset: 0x240  PWM Capture Channel 01 PDMA Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[15:0]  |CAPBUF    |PWM Capture PDMA Register (Read Only)
     * |        |          |This register is used as a buffer to transfer PWM capture rising or falling data to memory by PDMA.
     * |        |          |Note: If the PDMA function is not supported, this bit field will become invalid.
     * @var PWM_T::PDMACAP2_3
     * Offset: 0x244  PWM Capture Channel 23 PDMA Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[15:0]  |CAPBUF    |PWM Capture PDMA Register (Read Only)
     * |        |          |This register is used as a buffer to transfer PWM capture rising or falling data to memory by PDMA.
     * |        |          |Note: If the PDMA function is not supported, this bit field will become invalid.
     * @var PWM_T::PDMACAP4_5
     * Offset: 0x248  PWM Capture Channel 45 PDMA Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[15:0]  |CAPBUF    |PWM Capture PDMA Register (Read Only)
     * |        |          |This register is used as a buffer to transfer PWM capture rising or falling data to memory by PDMA.
     * |        |          |Note: If the PDMA function is not supported, this bit field will become invalid.
     * @var PWM_T::CAPIEN
     * Offset: 0x250  PWM Capture Interrupt Enable Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |CAPRIEN0  |PWM Capture Rising Latch Interrupt Enable Bits
     * |        |          |0 = Capture rising edge latch interrupt Disabled.
     * |        |          |1 = Capture rising edge latch interrupt Enabled.
     * |[1]     |CAPRIEN1  |PWM Capture Rising Latch Interrupt Enable Bits
     * |        |          |0 = Capture rising edge latch interrupt Disabled.
     * |        |          |1 = Capture rising edge latch interrupt Enabled.
     * |[2]     |CAPRIEN2  |PWM Capture Rising Latch Interrupt Enable Bits
     * |        |          |0 = Capture rising edge latch interrupt Disabled.
     * |        |          |1 = Capture rising edge latch interrupt Enabled.
     * |[3]     |CAPRIEN3  |PWM Capture Rising Latch Interrupt Enable Bits
     * |        |          |0 = Capture rising edge latch interrupt Disabled.
     * |        |          |1 = Capture rising edge latch interrupt Enabled.
     * |[4]     |CAPRIEN4  |PWM Capture Rising Latch Interrupt Enable Bits
     * |        |          |0 = Capture rising edge latch interrupt Disabled.
     * |        |          |1 = Capture rising edge latch interrupt Enabled.
     * |[5]     |CAPRIEN5  |PWM Capture Rising Latch Interrupt Enable Bits
     * |        |          |0 = Capture rising edge latch interrupt Disabled.
     * |        |          |1 = Capture rising edge latch interrupt Enabled.
     * |[8]     |CAPFIEN0  |PWM Capture Falling Latch Interrupt Enable Bits
     * |        |          |0 = Capture falling edge latch interrupt Disabled.
     * |        |          |1 = Capture falling edge latch interrupt Enabled.
     * |[9]     |CAPFIEN1  |PWM Capture Falling Latch Interrupt Enable Bits
     * |        |          |0 = Capture falling edge latch interrupt Disabled.
     * |        |          |1 = Capture falling edge latch interrupt Enabled.
     * |[10]    |CAPFIEN2  |PWM Capture Falling Latch Interrupt Enable Bits
     * |        |          |0 = Capture falling edge latch interrupt Disabled.
     * |        |          |1 = Capture falling edge latch interrupt Enabled.
     * |[11]    |CAPFIEN3  |PWM Capture Falling Latch Interrupt Enable Bits
     * |        |          |0 = Capture falling edge latch interrupt Disabled.
     * |        |          |1 = Capture falling edge latch interrupt Enabled.
     * |[12]    |CAPFIEN4  |PWM Capture Falling Latch Interrupt Enable Bits
     * |        |          |0 = Capture falling edge latch interrupt Disabled.
     * |        |          |1 = Capture falling edge latch interrupt Enabled.
     * |[13]    |CAPFIEN5  |PWM Capture Falling Latch Interrupt Enable Bits
     * |        |          |0 = Capture falling edge latch interrupt Disabled.
     * |        |          |1 = Capture falling edge latch interrupt Enabled.
     * @var PWM_T::CAPIF
     * Offset: 0x254  PWM Capture Interrupt Flag Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |CRLIF0    |PWM Capture Rising Latch Interrupt Flag
     * |        |          |0 = No capture rising latch condition happened.
     * |        |          |1 = Capture rising latch condition happened, this flag will be set to high.
     * |        |          |Note 1: When Capture with PDMA operating, CAPIF corresponding channel CRLIF will be cleared by hardware after PDMA transfer data.
     * |        |          |Note 2: This bit is cleared by writing 1 to it.
     * |[1]     |CRLIF1    |PWM Capture Rising Latch Interrupt Flag
     * |        |          |0 = No capture rising latch condition happened.
     * |        |          |1 = Capture rising latch condition happened, this flag will be set to high.
     * |        |          |Note 1: When Capture with PDMA operating, CAPIF corresponding channel CRLIF will be cleared by hardware after PDMA transfer data.
     * |        |          |Note 2: This bit is cleared by writing 1 to it.
     * |[2]     |CRLIF2    |PWM Capture Rising Latch Interrupt Flag
     * |        |          |0 = No capture rising latch condition happened.
     * |        |          |1 = Capture rising latch condition happened, this flag will be set to high.
     * |        |          |Note 1: When Capture with PDMA operating, CAPIF corresponding channel CRLIF will be cleared by hardware after PDMA transfer data.
     * |        |          |Note 2: This bit is cleared by writing 1 to it.
     * |[3]     |CRLIF3    |PWM Capture Rising Latch Interrupt Flag
     * |        |          |0 = No capture rising latch condition happened.
     * |        |          |1 = Capture rising latch condition happened, this flag will be set to high.
     * |        |          |Note 1: When Capture with PDMA operating, CAPIF corresponding channel CRLIF will be cleared by hardware after PDMA transfer data.
     * |        |          |Note 2: This bit is cleared by writing 1 to it.
     * |[4]     |CRLIF4    |PWM Capture Rising Latch Interrupt Flag
     * |        |          |0 = No capture rising latch condition happened.
     * |        |          |1 = Capture rising latch condition happened, this flag will be set to high.
     * |        |          |Note 1: When Capture with PDMA operating, CAPIF corresponding channel CRLIF will be cleared by hardware after PDMA transfer data.
     * |        |          |Note 2: This bit is cleared by writing 1 to it.
     * |[5]     |CRLIF5    |PWM Capture Rising Latch Interrupt Flag
     * |        |          |0 = No capture rising latch condition happened.
     * |        |          |1 = Capture rising latch condition happened, this flag will be set to high.
     * |        |          |Note 1: When Capture with PDMA operating, CAPIF corresponding channel CRLIF will be cleared by hardware after PDMA transfer data.
     * |        |          |Note 2: This bit is cleared by writing 1 to it.
     * |[8]     |CFLIF0    |PWM Capture Falling Latch Interrupt Flag
     * |        |          |0 = No capture falling latch condition happened.
     * |        |          |1 = Capture falling latch condition happened, this flag will be set to high.
     * |        |          |Note 1: When Capture with PDMA operating, CAPIF corresponding channel CFLIF will be cleared by hardware after PDMA transfer data.
     * |        |          |Note 2: This bit is cleared by writing 1 to it.
     * |[9]     |CFLIF1    |PWM Capture Falling Latch Interrupt Flag
     * |        |          |0 = No capture falling latch condition happened.
     * |        |          |1 = Capture falling latch condition happened, this flag will be set to high.
     * |        |          |Note 1: When Capture with PDMA operating, CAPIF corresponding channel CFLIF will be cleared by hardware after PDMA transfer data.
     * |        |          |Note 2: This bit is cleared by writing 1 to it.
     * |[10]    |CFLIF2    |PWM Capture Falling Latch Interrupt Flag
     * |        |          |0 = No capture falling latch condition happened.
     * |        |          |1 = Capture falling latch condition happened, this flag will be set to high.
     * |        |          |Note 1: When Capture with PDMA operating, CAPIF corresponding channel CFLIF will be cleared by hardware after PDMA transfer data.
     * |        |          |Note 2: This bit is cleared by writing 1 to it.
     * |[11]    |CFLIF3    |PWM Capture Falling Latch Interrupt Flag
     * |        |          |0 = No capture falling latch condition happened.
     * |        |          |1 = Capture falling latch condition happened, this flag will be set to high.
     * |        |          |Note 1: When Capture with PDMA operating, CAPIF corresponding channel CFLIF will be cleared by hardware after PDMA transfer data.
     * |        |          |Note 2: This bit is cleared by writing 1 to it.
     * |[12]    |CFLIF4    |PWM Capture Falling Latch Interrupt Flag
     * |        |          |0 = No capture falling latch condition happened.
     * |        |          |1 = Capture falling latch condition happened, this flag will be set to high.
     * |        |          |Note 1: When Capture with PDMA operating, CAPIF corresponding channel CFLIF will be cleared by hardware after PDMA transfer data.
     * |        |          |Note 2: This bit is cleared by writing 1 to it.
     * |[13]    |CFLIF5    |PWM Capture Falling Latch Interrupt Flag
     * |        |          |0 = No capture falling latch condition happened.
     * |        |          |1 = Capture falling latch condition happened, this flag will be set to high.
     * |        |          |Note 1: When Capture with PDMA operating, CAPIF corresponding channel CFLIF will be cleared by hardware after PDMA transfer data.
     * |        |          |Note 2: This bit is cleared by writing 1 to it.
     * @var PWM_T::CAPNF[6]
     * Offset: 0x258  PWM Capture Input Noise Filter Register 0~5
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |CAPNFEN   |Capture Noise Filter Enable
     * |        |          |0 = Capture Noise Filter function Disabled.
     * |        |          |1 = Capture Noise Filter function Enabled.
     * |[6:4]   |CAPNFSEL  |Capture Edge Detector Noise Filter Clock Selection
     * |        |          |000 = Filter clock = PCLK.
     * |        |          |001 = Filter clock = PCLK/2.
     * |        |          |010 = Filter clock = PCLK/4.
     * |        |          |011 = Filter clock = PCLK/8.
     * |        |          |100 = Filter clock = PCLK/16.
     * |        |          |101 = Filter clock = PCLK/32.
     * |        |          |110 = Filter clock = PCLK/64.
     * |        |          |111 = Filter clock = PCLK/128.
     * |[10:8]  |CAPNFCNT  |Capture Edge Detector Noise Filter Count
     * |        |          |The register bits control the capture filter counter to count from 0 to CAPNFCNT.
     * @var PWM_T::EXTETCTL0
     * Offset: 0x270  PWM External Event Trigger Control Register 0
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |EXTETEN   |External Event Trigger Enable Bit
     * |        |          |0 = External Event Trigger function Disabled.
     * |        |          |1 = External Event Trigger function Enabled.
     * |[5:4]   |CNTACTS   |Counter Action Selection
     * |        |          |00 = Counter reset.
     * |        |          |01 = Counter start.
     * |        |          |10 = Counter reset and start.
     * |        |          |11 = Reseved.
     * |[11:8]  |EXTTRGS   |External Trigger Selection
     * |        |          |0000 = INT0.
     * |        |          |0001 = INT1.
     * |        |          |0010 = INT2.
     * |        |          |0011 = INT3.
     * |        |          |0100 = INT4.
     * |        |          |0101 = INT5.
     * |        |          |0110 = INT6.
     * |        |          |0111 = INT7.
     * |        |          |Other = Resrved.
     * @var PWM_T::EXTETCTL2
     * Offset: 0x278  PWM External Event Trigger Control Register 2
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |EXTETEN   |External Event Trigger Enable Bit
     * |        |          |0 = External Event Trigger function Disabled.
     * |        |          |1 = External Event Trigger function Enabled.
     * |[5:4]   |CNTACTS   |Counter Action Selection
     * |        |          |00 = Counter reset.
     * |        |          |01 = Counter start.
     * |        |          |10 = Counter reset and start.
     * |        |          |11 = Reseved.
     * |[11:8]  |EXTTRGS   |External Trigger Selection
     * |        |          |0000 = INT0.
     * |        |          |0001 = INT1.
     * |        |          |0010 = INT2.
     * |        |          |0011 = INT3.
     * |        |          |0100 = INT4.
     * |        |          |0101 = INT5.
     * |        |          |0110 = INT6.
     * |        |          |0111 = INT7.
     * |        |          |Other = Resrved.
     * @var PWM_T::EXTETCTL4
     * Offset: 0x280  PWM External Event Trigger Control Register 4
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |EXTETEN   |External Event Trigger Enable Bit
     * |        |          |0 = External Event Trigger function Disabled.
     * |        |          |1 = External Event Trigger function Enabled.
     * |[5:4]   |CNTACTS   |Counter Action Selection
     * |        |          |00 = Counter reset.
     * |        |          |01 = Counter start.
     * |        |          |10 = Counter reset and start.
     * |        |          |11 = Reseved.
     * |[11:8]  |EXTTRGS   |External Trigger Selection
     * |        |          |0000 = INT0.
     * |        |          |0001 = INT1.
     * |        |          |0010 = INT2.
     * |        |          |0011 = INT3.
     * |        |          |0100 = INT4.
     * |        |          |0101 = INT5.
     * |        |          |0110 = INT6.
     * |        |          |0111 = INT7.
     * |        |          |Other = Resrved.
     * @var PWM_T::SWEOFCTL
     * Offset: 0x288  PWM Software Event Output Force Control Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[1:0]   |OUTACTS0  |Output Action Selection
     * |        |          |00 = Do nothing.
     * |        |          |01 = PWM output Low.
     * |        |          |10 = PWM output High.
     * |        |          |11 = PWM output Toggle.
     * |[3:2]   |OUTACTS1  |Output Action Selection
     * |        |          |00 = Do nothing.
     * |        |          |01 = PWM output Low.
     * |        |          |10 = PWM output High.
     * |        |          |11 = PWM output Toggle.
     * |[5:4]   |OUTACTS2  |Output Action Selection
     * |        |          |00 = Do nothing.
     * |        |          |01 = PWM output Low.
     * |        |          |10 = PWM output High.
     * |        |          |11 = PWM output Toggle.
     * |[7:6]   |OUTACTS3  |Output Action Selection
     * |        |          |00 = Do nothing.
     * |        |          |01 = PWM output Low.
     * |        |          |10 = PWM output High.
     * |        |          |11 = PWM output Toggle.
     * |[9:8]   |OUTACTS4  |Output Action Selection
     * |        |          |00 = Do nothing.
     * |        |          |01 = PWM output Low.
     * |        |          |10 = PWM output High.
     * |        |          |11 = PWM output Toggle.
     * |[11:10] |OUTACTS5  |Output Action Selection
     * |        |          |00 = Do nothing.
     * |        |          |01 = PWM output Low.
     * |        |          |10 = PWM output High.
     * |        |          |11 = PWM output Toggle.
     * @var PWM_T::SWEOFTRG
     * Offset: 0x28C  PWM Software Event Output Force Trigger Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |SWETRG0   |Software Event Trigger
     * |        |          |Write 1 to this bit will change PWM output status according to OUTACTSn in PWMx_SWEOFCTL setting.
     * |        |          |Note: This bit will auto cleared by hardware.
     * |[1]     |SWETRG1   |Software Event Trigger
     * |        |          |Write 1 to this bit will change PWM output status according to OUTACTSn in PWMx_SWEOFCTL setting.
     * |        |          |Note: This bit will auto cleared by hardware.
     * |[2]     |SWETRG2   |Software Event Trigger
     * |        |          |Write 1 to this bit will change PWM output status according to OUTACTSn in PWMx_SWEOFCTL setting.
     * |        |          |Note: This bit will auto cleared by hardware.
     * |[3]     |SWETRG3   |Software Event Trigger
     * |        |          |Write 1 to this bit will change PWM output status according to OUTACTSn in PWMx_SWEOFCTL setting.
     * |        |          |Note: This bit will auto cleared by hardware.
     * |[4]     |SWETRG4   |Software Event Trigger
     * |        |          |Write 1 to this bit will change PWM output status according to OUTACTSn in PWMx_SWEOFCTL setting.
     * |        |          |Note: This bit will auto cleared by hardware.
     * |[5]     |SWETRG5   |Software Event Trigger
     * |        |          |Write 1 to this bit will change PWM output status according to OUTACTSn in PWMx_SWEOFCTL setting.
     * |        |          |Note: This bit will auto cleared by hardware.
     * @var PWM_T::PBUF0
     * Offset: 0x304  PWM PERIOD0 Buffer
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[15:0]  |PBUF      |PWM Period Register Buffer (Read Only)
     * |        |          |Used as PERIOD active register.
     * @var PWM_T::PBUF2
     * Offset: 0x30C  PWM PERIOD2 Buffer
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[15:0]  |PBUF      |PWM Period Register Buffer (Read Only)
     * |        |          |Used as PERIOD active register.
     * @var PWM_T::PBUF4
     * Offset: 0x314  PWM PERIOD4 Buffer
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[15:0]  |PBUF      |PWM Period Register Buffer (Read Only)
     * |        |          |Used as PERIOD active register.
     * @var PWM_T::CMPBUF[6]
     * Offset: 0x31C~0x330  PWM CMPDAT0~5 Buffer
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[15:0]  |CMPBUF    |PWM Comparator Register Buffer (Read Only)
     * |        |          |Used as CMP active register.
     */
    __IO uint32_t CTL0;                  /*!< [0x0000] PWM Control Register 0                                           */
    __IO uint32_t CTL1;                  /*!< [0x0004] PWM Control Register 1                                           */
    __I  uint32_t RESERVE0[2];
    __IO uint32_t CLKSRC;                /*!< [0x0010] PWM Clock Source Register                                        */
    __IO uint32_t CLKPSC0_1;             /*!< [0x0014] PWM Clock Prescale Register 0/1                                  */
    __IO uint32_t CLKPSC2_3;             /*!< [0x0018] PWM Clock Prescale Register 2/3                                  */
    __IO uint32_t CLKPSC4_5;             /*!< [0x001c] PWM Clock Prescale Register 4/5                                  */
    __IO uint32_t CNTEN;                 /*!< [0x0020] PWM Counter Enable Register                                      */
    __IO uint32_t CNTCLR;                /*!< [0x0024] PWM Clear Counter Register                                       */
    __I  uint32_t RESERVE1[2];
    __IO uint32_t PERIOD[6];            /*!< [0x0030~0x0044] PWM Period Register 0/2/4                                  */
    __I  uint32_t RESERVE2[2];
    __IO uint32_t CMPDAT[6];             /*!< [0x0050~0x0064] PWM Comparator Register 0~5                               */
    __I  uint32_t RESERVE3[2];
    __IO uint32_t DTCTL0_1;              /*!< [0x0070] PWM Dead-time Control Register 0/1                               */
    __IO uint32_t DTCTL2_3;              /*!< [0x0074] PWM Dead-time Control Register 2/3                               */
    __IO uint32_t DTCTL4_5;              /*!< [0x0078] PWM Dead-time Control Register 4/5                               */
    __I  uint32_t RESERVE4[5];
    __I  uint32_t CNT[6];                /*!< [0x0090~0x00a4] PWM Counter Register 0/2/4                                */
    __I  uint32_t RESERVE5[2];
    __IO uint32_t WGCTL0;                /*!< [0x00b0] PWM Generation Register 0                                        */
    __IO uint32_t WGCTL1;                /*!< [0x00b4] PWM Generation Register 1                                        */
    __IO uint32_t MSKEN;                 /*!< [0x00b8] PWM Mask Enable Register                                         */
    __IO uint32_t MSK;                   /*!< [0x00bc] PWM Mask Data Register                                           */
    __IO uint32_t BNF;                   /*!< [0x00c0] PWM Brake Noise Filter Register                                  */
    __IO uint32_t FAILBRK;               /*!< [0x00c4] PWM System Fail Brake Control Register                           */
    __IO uint32_t BRKCTL0_1;             /*!< [0x00c8] PWM Brake Edge Detect Control Register 0/1                       */
    __IO uint32_t BRKCTL2_3;             /*!< [0x00cc] PWM Brake Edge Detect Control Register 2/3                       */
    __IO uint32_t BRKCTL4_5;             /*!< [0x00d0] PWM Brake Edge Detect Control Register 4/5                       */
    __IO uint32_t POLCTL;                /*!< [0x00d4] PWM Pin Polar Inverse Register                                   */
    __IO uint32_t POEN;                  /*!< [0x00d8] PWM Output Enable Register                                       */
    __O  uint32_t SWBRK;                 /*!< [0x00dc] PWM Software Brake Control Register                              */
    __IO uint32_t INTEN0;                /*!< [0x00e0] PWM Interrupt Enable Register 0                                  */
    __IO uint32_t INTEN1;                /*!< [0x00e4] PWM Interrupt Enable Register 1                                  */
    __IO uint32_t INTSTS0;               /*!< [0x00e8] PWM Interrupt Flag Register 0                                    */
    __IO uint32_t INTSTS1;               /*!< [0x00ec] PWM Interrupt Flag Register 1                                    */
    __I  uint32_t RESERVE10[2];
    __IO uint32_t ADCTS0;                /*!< [0x00f8] PWM Trigger ADC Source Select Register 0                         */
    __IO uint32_t ADCTS1;                /*!< [0x00fc] PWM Trigger ADC Source Select Register 1                         */
    __I  uint32_t RESERVE11[4];
    __IO uint32_t SSCTL;                 /*!< [0x0110] PWM Synchronous Start Control Register                           */
    __O  uint32_t SSTRG;                 /*!< [0x0114] PWM Synchronous Start Trigger Register                           */
    __I  uint32_t RESERVE12[2];
    __IO uint32_t STATUS;                /*!< [0x0120] PWM Status Register                                              */
    __I  uint32_t RESERVE13[3];
    __IO uint32_t IFA[6];                /*!< [0x0130] EPWM Interrupt Flag Accumulator Register 0~5                     */
    __I  uint32_t RESERVE16[2];
    __IO uint32_t AINTSTS;               /*!< [0x0150] PWM Accumulator Interrupt Flag Register                          */
    __IO uint32_t AINTEN;                /*!< [0x0154] PWM Accumulator Interrupt Enable Register                        */
    __IO uint32_t APDMACTL;              /*!< [0x0158] PWM Accumulator PDMA Control Register                            */
    __I  uint32_t RESERVE17[41];
    __IO uint32_t CAPINEN;               /*!< [0x0200] PWM Capture Input Enable Register                                */
    __IO uint32_t CAPCTL;                /*!< [0x0204] PWM Capture Control Register                                     */
    __I  uint32_t CAPSTS;                /*!< [0x0208] PWM Capture Status Register                                      */
    __I  uint32_t RCAPDAT0;              /*!< [0x020c] PWM Rising Capture Data Register 0                               */
    __I  uint32_t FCAPDAT0;              /*!< [0x0210] PWM Falling Capture Data Register 0                              */
    __I  uint32_t RCAPDAT1;              /*!< [0x0214] PWM Rising Capture Data Register 1                               */
    __I  uint32_t FCAPDAT1;              /*!< [0x0218] PWM Falling Capture Data Register 1                              */
    __I  uint32_t RCAPDAT2;              /*!< [0x021c] PWM Rising Capture Data Register 2                               */
    __I  uint32_t FCAPDAT2;              /*!< [0x0220] PWM Falling Capture Data Register 2                              */
    __I  uint32_t RCAPDAT3;              /*!< [0x0224] PWM Rising Capture Data Register 3                               */
    __I  uint32_t FCAPDAT3;              /*!< [0x0228] PWM Falling Capture Data Register 3                              */
    __I  uint32_t RCAPDAT4;              /*!< [0x022c] PWM Rising Capture Data Register 4                               */
    __I  uint32_t FCAPDAT4;              /*!< [0x0230] PWM Falling Capture Data Register 4                              */
    __I  uint32_t RCAPDAT5;              /*!< [0x0234] PWM Rising Capture Data Register 5                               */
    __I  uint32_t FCAPDAT5;              /*!< [0x0238] PWM Falling Capture Data Register 5                              */
    __IO uint32_t PDMACTL;               /*!< [0x023c] PWM PDMA Control Register                                        */
    __I  uint32_t PDMACAP0_1;            /*!< [0x0240] PWM Capture Channel 01 PDMA Register                             */
    __I  uint32_t PDMACAP2_3;            /*!< [0x0244] PWM Capture Channel 23 PDMA Register                             */
    __I  uint32_t PDMACAP4_5;            /*!< [0x0248] PWM Capture Channel 45 PDMA Register                             */
    __I  uint32_t RESERVE18[1];
    __IO uint32_t CAPIEN;                /*!< [0x0250] PWM Capture Interrupt Enable Register                            */
    __IO uint32_t CAPIF;                 /*!< [0x0254] PWM Capture Interrupt Flag Register                              */
    __IO uint32_t CAPNF[6];              /*!< [0x0258] PWM Capture Input Noise Filter Register                          */
    __IO uint32_t EXTETCTL0;             /*!< [0x0270] PWM External Event Trigger Control Register 0                    */
    __I  uint32_t RESERVE19[1];
    __IO uint32_t EXTETCTL2;             /*!< [0x0278] PWM External Event Trigger Control Register 2                    */
    __I  uint32_t RESERVE20[1];
    __IO uint32_t EXTETCTL4;             /*!< [0x0280] PWM External Event Trigger Control Register 4                    */
    __I  uint32_t RESERVE21[1];
    __IO uint32_t SWEOFCTL;              /*!< [0x0288] PWM Software Event Output Force Control Register                 */
    __IO uint32_t SWEOFTRG;              /*!< [0x028c] PWM Software Event Output Force Trigger Register                 */
    __I  uint32_t RESERVE22[29];
    __I  uint32_t PBUF0;                 /*!< [0x0304] PWM PERIOD0 Buffer                                               */
    __I  uint32_t RESERVE23[1];
    __I  uint32_t PBUF2;                 /*!< [0x030c] PWM PERIOD2 Buffer                                               */
    __I  uint32_t RESERVE24[1];
    __I  uint32_t PBUF4;                 /*!< [0x0314] PWM PERIOD4 Buffer                                               */
    __I  uint32_t RESERVE25[1];
    __I  uint32_t CMPBUF[6];             /*!< [0x031c] PWM CMPDAT0~5 Buffer                                             */
} PWM_T;

/**
    @addtogroup PWM_CONST PWM Bit Field Definition
    Constant Definitions for PWM Controller
@{ */

#define PWM_CTL0_CTRLD0_Pos              (0)                                               /*!< PWM_T::CTL0: CTRLD0 Position           */
#define PWM_CTL0_CTRLD0_Msk              (0x1ul << PWM_CTL0_CTRLD0_Pos)                    /*!< PWM_T::CTL0: CTRLD0 Mask               */

#define PWM_CTL0_CTRLD1_Pos              (1)                                               /*!< PWM_T::CTL0: CTRLD1 Position           */
#define PWM_CTL0_CTRLD1_Msk              (0x1ul << PWM_CTL0_CTRLD1_Pos)                    /*!< PWM_T::CTL0: CTRLD1 Mask               */

#define PWM_CTL0_CTRLD2_Pos              (2)                                               /*!< PWM_T::CTL0: CTRLD2 Position           */
#define PWM_CTL0_CTRLD2_Msk              (0x1ul << PWM_CTL0_CTRLD2_Pos)                    /*!< PWM_T::CTL0: CTRLD2 Mask               */

#define PWM_CTL0_CTRLD3_Pos              (3)                                               /*!< PWM_T::CTL0: CTRLD3 Position           */
#define PWM_CTL0_CTRLD3_Msk              (0x1ul << PWM_CTL0_CTRLD3_Pos)                    /*!< PWM_T::CTL0: CTRLD3 Mask               */

#define PWM_CTL0_CTRLD4_Pos              (4)                                               /*!< PWM_T::CTL0: CTRLD4 Position           */
#define PWM_CTL0_CTRLD4_Msk              (0x1ul << PWM_CTL0_CTRLD4_Pos)                    /*!< PWM_T::CTL0: CTRLD4 Mask               */

#define PWM_CTL0_CTRLD5_Pos              (5)                                               /*!< PWM_T::CTL0: CTRLD5 Position           */
#define PWM_CTL0_CTRLD5_Msk              (0x1ul << PWM_CTL0_CTRLD5_Pos)                    /*!< PWM_T::CTL0: CTRLD5 Mask               */

#define PWM_CTL0_IMMLDEN0_Pos            (16)                                              /*!< PWM_T::CTL0: IMMLDEN0 Position         */
#define PWM_CTL0_IMMLDEN0_Msk            (0x1ul << PWM_CTL0_IMMLDEN0_Pos)                  /*!< PWM_T::CTL0: IMMLDEN0 Mask             */

#define PWM_CTL0_IMMLDEN1_Pos            (17)                                              /*!< PWM_T::CTL0: IMMLDEN1 Position         */
#define PWM_CTL0_IMMLDEN1_Msk            (0x1ul << PWM_CTL0_IMMLDEN1_Pos)                  /*!< PWM_T::CTL0: IMMLDEN1 Mask             */

#define PWM_CTL0_IMMLDEN2_Pos            (18)                                              /*!< PWM_T::CTL0: IMMLDEN2 Position         */
#define PWM_CTL0_IMMLDEN2_Msk            (0x1ul << PWM_CTL0_IMMLDEN2_Pos)                  /*!< PWM_T::CTL0: IMMLDEN2 Mask             */

#define PWM_CTL0_IMMLDEN3_Pos            (19)                                              /*!< PWM_T::CTL0: IMMLDEN3 Position         */
#define PWM_CTL0_IMMLDEN3_Msk            (0x1ul << PWM_CTL0_IMMLDEN3_Pos)                  /*!< PWM_T::CTL0: IMMLDEN3 Mask             */

#define PWM_CTL0_IMMLDEN4_Pos            (20)                                              /*!< PWM_T::CTL0: IMMLDEN4 Position         */
#define PWM_CTL0_IMMLDEN4_Msk            (0x1ul << PWM_CTL0_IMMLDEN4_Pos)                  /*!< PWM_T::CTL0: IMMLDEN4 Mask             */

#define PWM_CTL0_IMMLDEN5_Pos            (21)                                              /*!< PWM_T::CTL0: IMMLDEN5 Position         */
#define PWM_CTL0_IMMLDEN5_Msk            (0x1ul << PWM_CTL0_IMMLDEN5_Pos)                  /*!< PWM_T::CTL0: IMMLDEN5 Mask             */

#define PWM_CTL0_DBGHALT_Pos             (30)                                              /*!< PWM_T::CTL0: DBGHALT Position          */
#define PWM_CTL0_DBGHALT_Msk             (0x1ul << PWM_CTL0_DBGHALT_Pos)                   /*!< PWM_T::CTL0: DBGHALT Mask              */

#define PWM_CTL0_DBGTRIOFF_Pos           (31)                                              /*!< PWM_T::CTL0: DBGTRIOFF Position        */
#define PWM_CTL0_DBGTRIOFF_Msk           (0x1ul << PWM_CTL0_DBGTRIOFF_Pos)                 /*!< PWM_T::CTL0: DBGTRIOFF Mask            */

#define PWM_CTL1_CNTTYPE0_Pos            (0)                                               /*!< PWM_T::CTL1: CNTTYPE0 Position         */
#define PWM_CTL1_CNTTYPE0_Msk            (0x3ul << PWM_CTL1_CNTTYPE0_Pos)                  /*!< PWM_T::CTL1: CNTTYPE0 Mask             */

#define PWM_CTL1_CNTTYPE2_Pos            (4)                                               /*!< PWM_T::CTL1: CNTTYPE2 Position         */
#define PWM_CTL1_CNTTYPE2_Msk            (0x3ul << PWM_CTL1_CNTTYPE2_Pos)                  /*!< PWM_T::CTL1: CNTTYPE2 Mask             */

#define PWM_CTL1_CNTTYPE4_Pos            (8)                                               /*!< PWM_T::CTL1: CNTTYPE4 Position         */
#define PWM_CTL1_CNTTYPE4_Msk            (0x3ul << PWM_CTL1_CNTTYPE4_Pos)                  /*!< PWM_T::CTL1: CNTTYPE4 Mask             */
#define PWM_CTL1_OUTMODE0_Pos            (24)                                              /*!< PWM_T::CTL1: OUTMODE0 Position         */
#define PWM_CTL1_OUTMODE0_Msk            (0x1ul << PWM_CTL1_OUTMODE0_Pos)                  /*!< PWM_T::CTL1: OUTMODE0 Mask             */

#define PWM_CTL1_OUTMODE2_Pos            (25)                                              /*!< PWM_T::CTL1: OUTMODE2 Position         */
#define PWM_CTL1_OUTMODE2_Msk            (0x1ul << PWM_CTL1_OUTMODE2_Pos)                  /*!< PWM_T::CTL1: OUTMODE2 Mask             */

#define PWM_CTL1_OUTMODE4_Pos            (26)                                              /*!< PWM_T::CTL1: OUTMODE4 Position         */
#define PWM_CTL1_OUTMODE4_Msk            (0x1ul << PWM_CTL1_OUTMODE4_Pos)                  /*!< PWM_T::CTL1: OUTMODE4 Mask             */

#define PWM_CLKSRC_ECLKSRC0_Pos          (0)                                               /*!< PWM_T::CLKSRC: ECLKSRC0 Position       */
#define PWM_CLKSRC_ECLKSRC0_Msk          (0x7ul << PWM_CLKSRC_ECLKSRC0_Pos)                /*!< PWM_T::CLKSRC: ECLKSRC0 Mask           */

#define PWM_CLKSRC_ECLKSRC2_Pos          (8)                                               /*!< PWM_T::CLKSRC: ECLKSRC2 Position       */
#define PWM_CLKSRC_ECLKSRC2_Msk          (0x7ul << PWM_CLKSRC_ECLKSRC2_Pos)                /*!< PWM_T::CLKSRC: ECLKSRC2 Mask           */

#define PWM_CLKSRC_ECLKSRC4_Pos          (16)                                              /*!< PWM_T::CLKSRC: ECLKSRC4 Position       */
#define PWM_CLKSRC_ECLKSRC4_Msk          (0x7ul << PWM_CLKSRC_ECLKSRC4_Pos)                /*!< PWM_T::CLKSRC: ECLKSRC4 Mask           */

#define PWM_CLKPSC0_1_CLKPSC_Pos         (0)                                               /*!< PWM_T::CLKPSC0_1: CLKPSC Position      */
#define PWM_CLKPSC0_1_CLKPSC_Msk         (0xffful << PWM_CLKPSC0_1_CLKPSC_Pos)             /*!< PWM_T::CLKPSC0_1: CLKPSC Mask          */

#define PWM_CLKPSC2_3_CLKPSC_Pos         (0)                                               /*!< PWM_T::CLKPSC2_3: CLKPSC Position      */
#define PWM_CLKPSC2_3_CLKPSC_Msk         (0xffful << PWM_CLKPSC2_3_CLKPSC_Pos)             /*!< PWM_T::CLKPSC2_3: CLKPSC Mask          */

#define PWM_CLKPSC4_5_CLKPSC_Pos         (0)                                               /*!< PWM_T::CLKPSC4_5: CLKPSC Position      */
#define PWM_CLKPSC4_5_CLKPSC_Msk         (0xffful << PWM_CLKPSC4_5_CLKPSC_Pos)             /*!< PWM_T::CLKPSC4_5: CLKPSC Mask          */

#define PWM_CNTEN_CNTEN0_Pos             (0)                                               /*!< PWM_T::CNTEN: CNTEN0 Position          */
#define PWM_CNTEN_CNTEN0_Msk             (0x1ul << PWM_CNTEN_CNTEN0_Pos)                   /*!< PWM_T::CNTEN: CNTEN0 Mask              */

#define PWM_CNTEN_CNTEN2_Pos             (2)                                               /*!< PWM_T::CNTEN: CNTEN2 Position          */
#define PWM_CNTEN_CNTEN2_Msk             (0x1ul << PWM_CNTEN_CNTEN2_Pos)                   /*!< PWM_T::CNTEN: CNTEN2 Mask              */

#define PWM_CNTEN_CNTEN4_Pos             (4)                                               /*!< PWM_T::CNTEN: CNTEN4 Position          */
#define PWM_CNTEN_CNTEN4_Msk             (0x1ul << PWM_CNTEN_CNTEN4_Pos)                   /*!< PWM_T::CNTEN: CNTEN4 Mask              */

#define PWM_CNTCLR_CNTCLR0_Pos           (0)                                               /*!< PWM_T::CNTCLR: CNTCLR0 Position        */
#define PWM_CNTCLR_CNTCLR0_Msk           (0x1ul << PWM_CNTCLR_CNTCLR0_Pos)                 /*!< PWM_T::CNTCLR: CNTCLR0 Mask            */

#define PWM_CNTCLR_CNTCLR2_Pos           (2)                                               /*!< PWM_T::CNTCLR: CNTCLR2 Position        */
#define PWM_CNTCLR_CNTCLR2_Msk           (0x1ul << PWM_CNTCLR_CNTCLR2_Pos)                 /*!< PWM_T::CNTCLR: CNTCLR2 Mask            */

#define PWM_CNTCLR_CNTCLR4_Pos           (4)                                               /*!< PWM_T::CNTCLR: CNTCLR4 Position        */
#define PWM_CNTCLR_CNTCLR4_Msk           (0x1ul << PWM_CNTCLR_CNTCLR4_Pos)                 /*!< PWM_T::CNTCLR: CNTCLR4 Mask            */

#define PWM_PERIOD0_PERIOD_Pos           (0)                                               /*!< PWM_T::PERIOD0: PERIOD Position        */
#define PWM_PERIOD0_PERIOD_Msk           (0xfffful << PWM_PERIOD0_PERIOD_Pos)              /*!< PWM_T::PERIOD0: PERIOD Mask            */

#define PWM_PERIOD2_PERIOD_Pos           (0)                                               /*!< PWM_T::PERIOD2: PERIOD Position        */
#define PWM_PERIOD2_PERIOD_Msk           (0xfffful << PWM_PERIOD2_PERIOD_Pos)              /*!< PWM_T::PERIOD2: PERIOD Mask            */

#define PWM_PERIOD4_PERIOD_Pos           (0)                                               /*!< PWM_T::PERIOD4: PERIOD Position        */
#define PWM_PERIOD4_PERIOD_Msk           (0xfffful << PWM_PERIOD4_PERIOD_Pos)              /*!< PWM_T::PERIOD4: PERIOD Mask            */

#define PWM_CMPDAT0_CMP_Pos              (0)                                               /*!< PWM_T::CMPDAT0: CMP Position           */
#define PWM_CMPDAT0_CMP_Msk              (0xfffful << PWM_CMPDAT0_CMP_Pos)                 /*!< PWM_T::CMPDAT0: CMP Mask               */

#define PWM_CMPDAT1_CMP_Pos              (0)                                               /*!< PWM_T::CMPDAT1: CMP Position           */
#define PWM_CMPDAT1_CMP_Msk              (0xfffful << PWM_CMPDAT1_CMP_Pos)                 /*!< PWM_T::CMPDAT1: CMP Mask               */

#define PWM_CMPDAT2_CMP_Pos              (0)                                               /*!< PWM_T::CMPDAT2: CMP Position           */
#define PWM_CMPDAT2_CMP_Msk              (0xfffful << PWM_CMPDAT2_CMP_Pos)                 /*!< PWM_T::CMPDAT2: CMP Mask               */

#define PWM_CMPDAT3_CMP_Pos              (0)                                               /*!< PWM_T::CMPDAT3: CMP Position           */
#define PWM_CMPDAT3_CMP_Msk              (0xfffful << PWM_CMPDAT3_CMP_Pos)                 /*!< PWM_T::CMPDAT3: CMP Mask               */

#define PWM_CMPDAT4_CMP_Pos              (0)                                               /*!< PWM_T::CMPDAT4: CMP Position           */
#define PWM_CMPDAT4_CMP_Msk              (0xfffful << PWM_CMPDAT4_CMP_Pos)                 /*!< PWM_T::CMPDAT4: CMP Mask               */

#define PWM_CMPDAT5_CMP_Pos              (0)                                               /*!< PWM_T::CMPDAT5: CMP Position           */
#define PWM_CMPDAT5_CMP_Msk              (0xfffful << PWM_CMPDAT5_CMP_Pos)                 /*!< PWM_T::CMPDAT5: CMP Mask               */

#define PWM_DTCTL0_1_DTCNT_Pos           (0)                                               /*!< PWM_T::DTCTL0_1: DTCNT Position        */
#define PWM_DTCTL0_1_DTCNT_Msk           (0xffful << PWM_DTCTL0_1_DTCNT_Pos)               /*!< PWM_T::DTCTL0_1: DTCNT Mask            */

#define PWM_DTCTL0_1_DTEN_Pos            (16)                                              /*!< PWM_T::DTCTL0_1: DTEN Position         */
#define PWM_DTCTL0_1_DTEN_Msk            (0x1ul << PWM_DTCTL0_1_DTEN_Pos)                  /*!< PWM_T::DTCTL0_1: DTEN Mask             */

#define PWM_DTCTL0_1_DTCKSEL_Pos         (24)                                              /*!< PWM_T::DTCTL0_1: DTCKSEL Position      */
#define PWM_DTCTL0_1_DTCKSEL_Msk         (0x1ul << PWM_DTCTL0_1_DTCKSEL_Pos)               /*!< PWM_T::DTCTL0_1: DTCKSEL Mask          */

#define PWM_DTCTL2_3_DTCNT_Pos           (0)                                               /*!< PWM_T::DTCTL2_3: DTCNT Position        */
#define PWM_DTCTL2_3_DTCNT_Msk           (0xffful << PWM_DTCTL2_3_DTCNT_Pos)               /*!< PWM_T::DTCTL2_3: DTCNT Mask            */

#define PWM_DTCTL2_3_DTEN_Pos            (16)                                              /*!< PWM_T::DTCTL2_3: DTEN Position         */
#define PWM_DTCTL2_3_DTEN_Msk            (0x1ul << PWM_DTCTL2_3_DTEN_Pos)                  /*!< PWM_T::DTCTL2_3: DTEN Mask             */

#define PWM_DTCTL2_3_DTCKSEL_Pos         (24)                                              /*!< PWM_T::DTCTL2_3: DTCKSEL Position      */
#define PWM_DTCTL2_3_DTCKSEL_Msk         (0x1ul << PWM_DTCTL2_3_DTCKSEL_Pos)               /*!< PWM_T::DTCTL2_3: DTCKSEL Mask          */

#define PWM_DTCTL4_5_DTCNT_Pos           (0)                                               /*!< PWM_T::DTCTL4_5: DTCNT Position        */
#define PWM_DTCTL4_5_DTCNT_Msk           (0xffful << PWM_DTCTL4_5_DTCNT_Pos)               /*!< PWM_T::DTCTL4_5: DTCNT Mask            */

#define PWM_DTCTL4_5_DTEN_Pos            (16)                                              /*!< PWM_T::DTCTL4_5: DTEN Position         */
#define PWM_DTCTL4_5_DTEN_Msk            (0x1ul << PWM_DTCTL4_5_DTEN_Pos)                  /*!< PWM_T::DTCTL4_5: DTEN Mask             */

#define PWM_DTCTL4_5_DTCKSEL_Pos         (24)                                              /*!< PWM_T::DTCTL4_5: DTCKSEL Position      */
#define PWM_DTCTL4_5_DTCKSEL_Msk         (0x1ul << PWM_DTCTL4_5_DTCKSEL_Pos)               /*!< PWM_T::DTCTL4_5: DTCKSEL Mask          */

#define PWM_CNT_CNT_Pos                  (0)                                               /*!< PWM_T::CNT: CNT Position               */
#define PWM_CNT_CNT_Msk                  (0xfffful << PWM_CNT_CNT_Pos)                     /*!< PWM_T::CNT: CNT Mask                   */

#define PWM_CNT_DIRF_Pos                 (16)                                              /*!< PWM_T::CNT: DIRF Position             */
#define PWM_CNT_DIRF_Msk                 (0x1ul << PWM_CNT_DIRF_Pos)                       /*!< PWM_T::CNT: DIRF Mask                 */

#define PWM_WGCTL0_ZPCTL0_Pos            (0)                                               /*!< PWM_T::WGCTL0: ZPCTL0 Position         */
#define PWM_WGCTL0_ZPCTL0_Msk            (0x3ul << PWM_WGCTL0_ZPCTL0_Pos)                  /*!< PWM_T::WGCTL0: ZPCTL0 Mask             */

#define PWM_WGCTL0_ZPCTL1_Pos            (2)                                               /*!< PWM_T::WGCTL0: ZPCTL1 Position         */
#define PWM_WGCTL0_ZPCTL1_Msk            (0x3ul << PWM_WGCTL0_ZPCTL1_Pos)                  /*!< PWM_T::WGCTL0: ZPCTL1 Mask             */

#define PWM_WGCTL0_ZPCTL2_Pos            (4)                                               /*!< PWM_T::WGCTL0: ZPCTL2 Position         */
#define PWM_WGCTL0_ZPCTL2_Msk            (0x3ul << PWM_WGCTL0_ZPCTL2_Pos)                  /*!< PWM_T::WGCTL0: ZPCTL2 Mask             */

#define PWM_WGCTL0_ZPCTL3_Pos            (6)                                               /*!< PWM_T::WGCTL0: ZPCTL3 Position         */
#define PWM_WGCTL0_ZPCTL3_Msk            (0x3ul << PWM_WGCTL0_ZPCTL3_Pos)                  /*!< PWM_T::WGCTL0: ZPCTL3 Mask             */

#define PWM_WGCTL0_ZPCTL4_Pos            (8)                                               /*!< PWM_T::WGCTL0: ZPCTL4 Position         */
#define PWM_WGCTL0_ZPCTL4_Msk            (0x3ul << PWM_WGCTL0_ZPCTL4_Pos)                  /*!< PWM_T::WGCTL0: ZPCTL4 Mask             */

#define PWM_WGCTL0_ZPCTL5_Pos            (10)                                              /*!< PWM_T::WGCTL0: ZPCTL5 Position         */
#define PWM_WGCTL0_ZPCTL5_Msk            (0x3ul << PWM_WGCTL0_ZPCTL5_Pos)                  /*!< PWM_T::WGCTL0: ZPCTL5 Mask             */

#define PWM_WGCTL0_PRDPCTL0_Pos          (16)                                              /*!< PWM_T::WGCTL0: PRDPCTL0 Position       */
#define PWM_WGCTL0_PRDPCTL0_Msk          (0x3ul << PWM_WGCTL0_PRDPCTL0_Pos)                /*!< PWM_T::WGCTL0: PRDPCTL0 Mask           */

#define PWM_WGCTL0_PRDPCTL1_Pos          (18)                                              /*!< PWM_T::WGCTL0: PRDPCTL1 Position       */
#define PWM_WGCTL0_PRDPCTL1_Msk          (0x3ul << PWM_WGCTL0_PRDPCTL1_Pos)                /*!< PWM_T::WGCTL0: PRDPCTL1 Mask           */

#define PWM_WGCTL0_PRDPCTL2_Pos          (20)                                              /*!< PWM_T::WGCTL0: PRDPCTL2 Position       */
#define PWM_WGCTL0_PRDPCTL2_Msk          (0x3ul << PWM_WGCTL0_PRDPCTL2_Pos)                /*!< PWM_T::WGCTL0: PRDPCTL2 Mask           */

#define PWM_WGCTL0_PRDPCTL3_Pos          (22)                                              /*!< PWM_T::WGCTL0: PRDPCTL3 Position       */
#define PWM_WGCTL0_PRDPCTL3_Msk          (0x3ul << PWM_WGCTL0_PRDPCTL3_Pos)                /*!< PWM_T::WGCTL0: PRDPCTL3 Mask           */

#define PWM_WGCTL0_PRDPCTL4_Pos          (24)                                              /*!< PWM_T::WGCTL0: PRDPCTL4 Position       */
#define PWM_WGCTL0_PRDPCTL4_Msk          (0x3ul << PWM_WGCTL0_PRDPCTL4_Pos)                /*!< PWM_T::WGCTL0: PRDPCTL4 Mask           */

#define PWM_WGCTL0_PRDPCTL5_Pos          (26)                                              /*!< PWM_T::WGCTL0: PRDPCTL5 Position       */
#define PWM_WGCTL0_PRDPCTL5_Msk          (0x3ul << PWM_WGCTL0_PRDPCTL5_Pos)                /*!< PWM_T::WGCTL0: PRDPCTL5 Mask           */

#define PWM_WGCTL1_CMPUCTL0_Pos          (0)                                               /*!< PWM_T::WGCTL1: CMPUCTL0 Position       */
#define PWM_WGCTL1_CMPUCTL0_Msk          (0x3ul << PWM_WGCTL1_CMPUCTL0_Pos)                /*!< PWM_T::WGCTL1: CMPUCTL0 Mask           */

#define PWM_WGCTL1_CMPUCTL1_Pos          (2)                                               /*!< PWM_T::WGCTL1: CMPUCTL1 Position       */
#define PWM_WGCTL1_CMPUCTL1_Msk          (0x3ul << PWM_WGCTL1_CMPUCTL1_Pos)                /*!< PWM_T::WGCTL1: CMPUCTL1 Mask           */

#define PWM_WGCTL1_CMPUCTL2_Pos          (4)                                               /*!< PWM_T::WGCTL1: CMPUCTL2 Position       */
#define PWM_WGCTL1_CMPUCTL2_Msk          (0x3ul << PWM_WGCTL1_CMPUCTL2_Pos)                /*!< PWM_T::WGCTL1: CMPUCTL2 Mask           */

#define PWM_WGCTL1_CMPUCTL3_Pos          (6)                                               /*!< PWM_T::WGCTL1: CMPUCTL3 Position       */
#define PWM_WGCTL1_CMPUCTL3_Msk          (0x3ul << PWM_WGCTL1_CMPUCTL3_Pos)                /*!< PWM_T::WGCTL1: CMPUCTL3 Mask           */

#define PWM_WGCTL1_CMPUCTL4_Pos          (8)                                               /*!< PWM_T::WGCTL1: CMPUCTL4 Position       */
#define PWM_WGCTL1_CMPUCTL4_Msk          (0x3ul << PWM_WGCTL1_CMPUCTL4_Pos)                /*!< PWM_T::WGCTL1: CMPUCTL4 Mask           */

#define PWM_WGCTL1_CMPUCTL5_Pos          (10)                                              /*!< PWM_T::WGCTL1: CMPUCTL5 Position       */
#define PWM_WGCTL1_CMPUCTL5_Msk          (0x3ul << PWM_WGCTL1_CMPUCTL5_Pos)                /*!< PWM_T::WGCTL1: CMPUCTL5 Mask           */

#define PWM_WGCTL1_CMPDCTL0_Pos          (16)                                              /*!< PWM_T::WGCTL1: CMPDCTL0 Position       */
#define PWM_WGCTL1_CMPDCTL0_Msk          (0x3ul << PWM_WGCTL1_CMPDCTL0_Pos)                /*!< PWM_T::WGCTL1: CMPDCTL0 Mask           */

#define PWM_WGCTL1_CMPDCTL1_Pos          (18)                                              /*!< PWM_T::WGCTL1: CMPDCTL1 Position       */
#define PWM_WGCTL1_CMPDCTL1_Msk          (0x3ul << PWM_WGCTL1_CMPDCTL1_Pos)                /*!< PWM_T::WGCTL1: CMPDCTL1 Mask           */

#define PWM_WGCTL1_CMPDCTL2_Pos          (20)                                              /*!< PWM_T::WGCTL1: CMPDCTL2 Position       */
#define PWM_WGCTL1_CMPDCTL2_Msk          (0x3ul << PWM_WGCTL1_CMPDCTL2_Pos)                /*!< PWM_T::WGCTL1: CMPDCTL2 Mask           */

#define PWM_WGCTL1_CMPDCTL3_Pos          (22)                                              /*!< PWM_T::WGCTL1: CMPDCTL3 Position       */
#define PWM_WGCTL1_CMPDCTL3_Msk          (0x3ul << PWM_WGCTL1_CMPDCTL3_Pos)                /*!< PWM_T::WGCTL1: CMPDCTL3 Mask           */

#define PWM_WGCTL1_CMPDCTL4_Pos          (24)                                              /*!< PWM_T::WGCTL1: CMPDCTL4 Position       */
#define PWM_WGCTL1_CMPDCTL4_Msk          (0x3ul << PWM_WGCTL1_CMPDCTL4_Pos)                /*!< PWM_T::WGCTL1: CMPDCTL4 Mask           */

#define PWM_WGCTL1_CMPDCTL5_Pos          (26)                                              /*!< PWM_T::WGCTL1: CMPDCTL5 Position       */
#define PWM_WGCTL1_CMPDCTL5_Msk          (0x3ul << PWM_WGCTL1_CMPDCTL5_Pos)                /*!< PWM_T::WGCTL1: CMPDCTL5 Mask           */

#define PWM_MSKEN_MSKEN0_Pos             (0)                                               /*!< PWM_T::MSKEN: MSKEN0 Position          */
#define PWM_MSKEN_MSKEN0_Msk             (0x1ul << PWM_MSKEN_MSKEN0_Pos)                   /*!< PWM_T::MSKEN: MSKEN0 Mask              */

#define PWM_MSKEN_MSKEN1_Pos             (1)                                               /*!< PWM_T::MSKEN: MSKEN1 Position          */
#define PWM_MSKEN_MSKEN1_Msk             (0x1ul << PWM_MSKEN_MSKEN1_Pos)                   /*!< PWM_T::MSKEN: MSKEN1 Mask              */

#define PWM_MSKEN_MSKEN2_Pos             (2)                                               /*!< PWM_T::MSKEN: MSKEN2 Position          */
#define PWM_MSKEN_MSKEN2_Msk             (0x1ul << PWM_MSKEN_MSKEN2_Pos)                   /*!< PWM_T::MSKEN: MSKEN2 Mask              */

#define PWM_MSKEN_MSKEN3_Pos             (3)                                               /*!< PWM_T::MSKEN: MSKEN3 Position          */
#define PWM_MSKEN_MSKEN3_Msk             (0x1ul << PWM_MSKEN_MSKEN3_Pos)                   /*!< PWM_T::MSKEN: MSKEN3 Mask              */

#define PWM_MSKEN_MSKEN4_Pos             (4)                                               /*!< PWM_T::MSKEN: MSKEN4 Position          */
#define PWM_MSKEN_MSKEN4_Msk             (0x1ul << PWM_MSKEN_MSKEN4_Pos)                   /*!< PWM_T::MSKEN: MSKEN4 Mask              */

#define PWM_MSKEN_MSKEN5_Pos             (5)                                               /*!< PWM_T::MSKEN: MSKEN5 Position          */
#define PWM_MSKEN_MSKEN5_Msk             (0x1ul << PWM_MSKEN_MSKEN5_Pos)                   /*!< PWM_T::MSKEN: MSKEN5 Mask              */

#define PWM_MSK_MSKDAT0_Pos              (0)                                               /*!< PWM_T::MSK: MSKDAT0 Position           */
#define PWM_MSK_MSKDAT0_Msk              (0x1ul << PWM_MSK_MSKDAT0_Pos)                    /*!< PWM_T::MSK: MSKDAT0 Mask               */

#define PWM_MSK_MSKDAT1_Pos              (1)                                               /*!< PWM_T::MSK: MSKDAT1 Position           */
#define PWM_MSK_MSKDAT1_Msk              (0x1ul << PWM_MSK_MSKDAT1_Pos)                    /*!< PWM_T::MSK: MSKDAT1 Mask               */

#define PWM_MSK_MSKDAT2_Pos              (2)                                               /*!< PWM_T::MSK: MSKDAT2 Position           */
#define PWM_MSK_MSKDAT2_Msk              (0x1ul << PWM_MSK_MSKDAT2_Pos)                    /*!< PWM_T::MSK: MSKDAT2 Mask               */

#define PWM_MSK_MSKDAT3_Pos              (3)                                               /*!< PWM_T::MSK: MSKDAT3 Position           */
#define PWM_MSK_MSKDAT3_Msk              (0x1ul << PWM_MSK_MSKDAT3_Pos)                    /*!< PWM_T::MSK: MSKDAT3 Mask               */

#define PWM_MSK_MSKDAT4_Pos              (4)                                               /*!< PWM_T::MSK: MSKDAT4 Position           */
#define PWM_MSK_MSKDAT4_Msk              (0x1ul << PWM_MSK_MSKDAT4_Pos)                    /*!< PWM_T::MSK: MSKDAT4 Mask               */

#define PWM_MSK_MSKDAT5_Pos              (5)                                               /*!< PWM_T::MSK: MSKDAT5 Position           */
#define PWM_MSK_MSKDAT5_Msk              (0x1ul << PWM_MSK_MSKDAT5_Pos)                    /*!< PWM_T::MSK: MSKDAT5 Mask               */

#define PWM_BNF_BRK0NFEN_Pos             (0)                                               /*!< PWM_T::BNF: BRK0NFEN Position          */
#define PWM_BNF_BRK0NFEN_Msk             (0x1ul << PWM_BNF_BRK0NFEN_Pos)                   /*!< PWM_T::BNF: BRK0NFEN Mask              */

#define PWM_BNF_BRK0FSEL_Pos             (1)                                               /*!< PWM_T::BNF: BRK0FSEL Position          */
#define PWM_BNF_BRK0FSEL_Msk             (0x7ul << PWM_BNF_BRK0FSEL_Pos)                   /*!< PWM_T::BNF: BRK0FSEL Mask              */

#define PWM_BNF_BRK0FCNT_Pos             (4)                                               /*!< PWM_T::BNF: BRK0FCNT Position          */
#define PWM_BNF_BRK0FCNT_Msk             (0x7ul << PWM_BNF_BRK0FCNT_Pos)                   /*!< PWM_T::BNF: BRK0FCNT Mask              */

#define PWM_BNF_BRK0PINV_Pos             (7)                                               /*!< PWM_T::BNF: BRK0PINV Position          */
#define PWM_BNF_BRK0PINV_Msk             (0x1ul << PWM_BNF_BRK0PINV_Pos)                   /*!< PWM_T::BNF: BRK0PINV Mask              */

#define PWM_BNF_BRK1NFEN_Pos             (8)                                               /*!< PWM_T::BNF: BRK1NFEN Position          */
#define PWM_BNF_BRK1NFEN_Msk             (0x1ul << PWM_BNF_BRK1NFEN_Pos)                   /*!< PWM_T::BNF: BRK1NFEN Mask              */

#define PWM_BNF_BRK1FSEL_Pos             (9)                                               /*!< PWM_T::BNF: BRK1FSEL Position          */
#define PWM_BNF_BRK1FSEL_Msk             (0x7ul << PWM_BNF_BRK1FSEL_Pos)                   /*!< PWM_T::BNF: BRK1FSEL Mask              */

#define PWM_BNF_BRK1FCNT_Pos             (12)                                              /*!< PWM_T::BNF: BRK1FCNT Position          */
#define PWM_BNF_BRK1FCNT_Msk             (0x7ul << PWM_BNF_BRK1FCNT_Pos)                   /*!< PWM_T::BNF: BRK1FCNT Mask              */

#define PWM_BNF_BRK1PINV_Pos             (15)                                              /*!< PWM_T::BNF: BRK1PINV Position          */
#define PWM_BNF_BRK1PINV_Msk             (0x1ul << PWM_BNF_BRK1PINV_Pos)                   /*!< PWM_T::BNF: BRK1PINV Mask              */

#define PWM_BNF_BK0SRC_Pos               (16)                                              /*!< PWM_T::BNF: BK0SRC Position            */
#define PWM_BNF_BK0SRC_Msk               (0x1ul << PWM_BNF_BK0SRC_Pos)                     /*!< PWM_T::BNF: BK0SRC Mask                */

#define PWM_BNF_BK1SRC_Pos               (24)                                              /*!< PWM_T::BNF: BK1SRC Position            */
#define PWM_BNF_BK1SRC_Msk               (0x1ul << PWM_BNF_BK1SRC_Pos)                     /*!< PWM_T::BNF: BK1SRC Mask                */

#define PWM_FAILBRK_CSSBRKEN_Pos         (0)                                               /*!< PWM_T::FAILBRK: CSSBRKEN Position      */
#define PWM_FAILBRK_CSSBRKEN_Msk         (0x1ul << PWM_FAILBRK_CSSBRKEN_Pos)               /*!< PWM_T::FAILBRK: CSSBRKEN Mask          */

#define PWM_FAILBRK_BODBRKEN_Pos         (1)                                               /*!< PWM_T::FAILBRK: BODBRKEN Position      */
#define PWM_FAILBRK_BODBRKEN_Msk         (0x1ul << PWM_FAILBRK_BODBRKEN_Pos)               /*!< PWM_T::FAILBRK: BODBRKEN Mask          */

#define PWM_FAILBRK_CORBRKEN_Pos         (3)                                               /*!< PWM_T::FAILBRK: CORBRKEN Position      */
#define PWM_FAILBRK_CORBRKEN_Msk         (0x1ul << PWM_FAILBRK_CORBRKEN_Pos)               /*!< PWM_T::FAILBRK: CORBRKEN Mask          */

#define PWM_BRKCTL0_1_CPO0EBEN_Pos       (0)                                               /*!< PWM_T::BRKCTL0_1: CPO0EBEN Position    */
#define PWM_BRKCTL0_1_CPO0EBEN_Msk       (0x1ul << PWM_BRKCTL0_1_CPO0EBEN_Pos)             /*!< PWM_T::BRKCTL0_1: CPO0EBEN Mask        */

#define PWM_BRKCTL0_1_CPO1EBEN_Pos       (1)                                               /*!< PWM_T::BRKCTL0_1: CPO1EBEN Position    */
#define PWM_BRKCTL0_1_CPO1EBEN_Msk       (0x1ul << PWM_BRKCTL0_1_CPO1EBEN_Pos)             /*!< PWM_T::BRKCTL0_1: CPO1EBEN Mask        */

#define PWM_BRKCTL0_1_BRKP0EEN_Pos       (4)                                               /*!< PWM_T::BRKCTL0_1: BRKP0EEN Position    */
#define PWM_BRKCTL0_1_BRKP0EEN_Msk       (0x1ul << PWM_BRKCTL0_1_BRKP0EEN_Pos)             /*!< PWM_T::BRKCTL0_1: BRKP0EEN Mask        */

#define PWM_BRKCTL0_1_BRKP1EEN_Pos       (5)                                               /*!< PWM_T::BRKCTL0_1: BRKP1EEN Position    */
#define PWM_BRKCTL0_1_BRKP1EEN_Msk       (0x1ul << PWM_BRKCTL0_1_BRKP1EEN_Pos)             /*!< PWM_T::BRKCTL0_1: BRKP1EEN Mask        */

#define PWM_BRKCTL0_1_SYSEBEN_Pos        (7)                                               /*!< PWM_T::BRKCTL0_1: SYSEBEN Position     */
#define PWM_BRKCTL0_1_SYSEBEN_Msk        (0x1ul << PWM_BRKCTL0_1_SYSEBEN_Pos)              /*!< PWM_T::BRKCTL0_1: SYSEBEN Mask         */

#define PWM_BRKCTL0_1_CPO0LBEN_Pos       (8)                                               /*!< PWM_T::BRKCTL0_1: CPO0LBEN Position    */
#define PWM_BRKCTL0_1_CPO0LBEN_Msk       (0x1ul << PWM_BRKCTL0_1_CPO0LBEN_Pos)             /*!< PWM_T::BRKCTL0_1: CPO0LBEN Mask        */

#define PWM_BRKCTL0_1_CPO1LBEN_Pos       (9)                                               /*!< PWM_T::BRKCTL0_1: CPO1LBEN Position    */
#define PWM_BRKCTL0_1_CPO1LBEN_Msk       (0x1ul << PWM_BRKCTL0_1_CPO1LBEN_Pos)             /*!< PWM_T::BRKCTL0_1: CPO1LBEN Mask        */

#define PWM_BRKCTL0_1_BRKP0LEN_Pos       (12)                                              /*!< PWM_T::BRKCTL0_1: BRKP0LEN Position    */
#define PWM_BRKCTL0_1_BRKP0LEN_Msk       (0x1ul << PWM_BRKCTL0_1_BRKP0LEN_Pos)             /*!< PWM_T::BRKCTL0_1: BRKP0LEN Mask        */

#define PWM_BRKCTL0_1_BRKP1LEN_Pos       (13)                                              /*!< PWM_T::BRKCTL0_1: BRKP1LEN Position    */
#define PWM_BRKCTL0_1_BRKP1LEN_Msk       (0x1ul << PWM_BRKCTL0_1_BRKP1LEN_Pos)             /*!< PWM_T::BRKCTL0_1: BRKP1LEN Mask        */

#define PWM_BRKCTL0_1_VBSNLBEN_Pos       (14)                                              /*!< PWM_T::BRKCTL0_1: VBSNLBEN Position    */
#define PWM_BRKCTL0_1_VBSNLBEN_Msk       (0x1ul << PWM_BRKCTL0_1_VBSNLBEN_Pos)             /*!< PWM_T::BRKCTL0_1: VBSNLBEN Mask        */

#define PWM_BRKCTL0_1_SYSLBEN_Pos        (15)                                              /*!< PWM_T::BRKCTL0_1: SYSLBEN Position     */
#define PWM_BRKCTL0_1_SYSLBEN_Msk        (0x1ul << PWM_BRKCTL0_1_SYSLBEN_Pos)              /*!< PWM_T::BRKCTL0_1: SYSLBEN Mask         */

#define PWM_BRKCTL0_1_BRKAEVEN_Pos       (16)                                              /*!< PWM_T::BRKCTL0_1: BRKAEVEN Position    */
#define PWM_BRKCTL0_1_BRKAEVEN_Msk       (0x3ul << PWM_BRKCTL0_1_BRKAEVEN_Pos)             /*!< PWM_T::BRKCTL0_1: BRKAEVEN Mask        */

#define PWM_BRKCTL0_1_BRKAODD_Pos        (18)                                              /*!< PWM_T::BRKCTL0_1: BRKAODD Position     */
#define PWM_BRKCTL0_1_BRKAODD_Msk        (0x3ul << PWM_BRKCTL0_1_BRKAODD_Pos)              /*!< PWM_T::BRKCTL0_1: BRKAODD Mask         */

#define PWM_BRKCTL2_3_CPO0EBEN_Pos       (0)                                               /*!< PWM_T::BRKCTL2_3: CPO0EBEN Position    */
#define PWM_BRKCTL2_3_CPO0EBEN_Msk       (0x1ul << PWM_BRKCTL2_3_CPO0EBEN_Pos)             /*!< PWM_T::BRKCTL2_3: CPO0EBEN Mask        */

#define PWM_BRKCTL2_3_CPO1EBEN_Pos       (1)                                               /*!< PWM_T::BRKCTL2_3: CPO1EBEN Position    */
#define PWM_BRKCTL2_3_CPO1EBEN_Msk       (0x1ul << PWM_BRKCTL2_3_CPO1EBEN_Pos)             /*!< PWM_T::BRKCTL2_3: CPO1EBEN Mask        */

#define PWM_BRKCTL2_3_BRKP0EEN_Pos       (4)                                               /*!< PWM_T::BRKCTL2_3: BRKP0EEN Position    */
#define PWM_BRKCTL2_3_BRKP0EEN_Msk       (0x1ul << PWM_BRKCTL2_3_BRKP0EEN_Pos)             /*!< PWM_T::BRKCTL2_3: BRKP0EEN Mask        */

#define PWM_BRKCTL2_3_BRKP1EEN_Pos       (5)                                               /*!< PWM_T::BRKCTL2_3: BRKP1EEN Position    */
#define PWM_BRKCTL2_3_BRKP1EEN_Msk       (0x1ul << PWM_BRKCTL2_3_BRKP1EEN_Pos)             /*!< PWM_T::BRKCTL2_3: BRKP1EEN Mask        */

#define PWM_BRKCTL2_3_SYSEBEN_Pos        (7)                                               /*!< PWM_T::BRKCTL2_3: SYSEBEN Position     */
#define PWM_BRKCTL2_3_SYSEBEN_Msk        (0x1ul << PWM_BRKCTL2_3_SYSEBEN_Pos)              /*!< PWM_T::BRKCTL2_3: SYSEBEN Mask         */

#define PWM_BRKCTL2_3_CPO0LBEN_Pos       (8)                                               /*!< PWM_T::BRKCTL2_3: CPO0LBEN Position    */
#define PWM_BRKCTL2_3_CPO0LBEN_Msk       (0x1ul << PWM_BRKCTL2_3_CPO0LBEN_Pos)             /*!< PWM_T::BRKCTL2_3: CPO0LBEN Mask        */

#define PWM_BRKCTL2_3_CPO1LBEN_Pos       (9)                                               /*!< PWM_T::BRKCTL2_3: CPO1LBEN Position    */
#define PWM_BRKCTL2_3_CPO1LBEN_Msk       (0x1ul << PWM_BRKCTL2_3_CPO1LBEN_Pos)             /*!< PWM_T::BRKCTL2_3: CPO1LBEN Mask        */

#define PWM_BRKCTL2_3_BRKP0LEN_Pos       (12)                                              /*!< PWM_T::BRKCTL2_3: BRKP0LEN Position    */
#define PWM_BRKCTL2_3_BRKP0LEN_Msk       (0x1ul << PWM_BRKCTL2_3_BRKP0LEN_Pos)             /*!< PWM_T::BRKCTL2_3: BRKP0LEN Mask        */

#define PWM_BRKCTL2_3_BRKP1LEN_Pos       (13)                                              /*!< PWM_T::BRKCTL2_3: BRKP1LEN Position    */
#define PWM_BRKCTL2_3_BRKP1LEN_Msk       (0x1ul << PWM_BRKCTL2_3_BRKP1LEN_Pos)             /*!< PWM_T::BRKCTL2_3: BRKP1LEN Mask        */

#define PWM_BRKCTL2_3_VBSNLBEN_Pos       (14)                                              /*!< PWM_T::BRKCTL2_3: VBSNLBEN Position    */
#define PWM_BRKCTL2_3_VBSNLBEN_Msk       (0x1ul << PWM_BRKCTL2_3_VBSNLBEN_Pos)             /*!< PWM_T::BRKCTL2_3: VBSNLBEN Mask        */

#define PWM_BRKCTL2_3_SYSLBEN_Pos        (15)                                              /*!< PWM_T::BRKCTL2_3: SYSLBEN Position     */
#define PWM_BRKCTL2_3_SYSLBEN_Msk        (0x1ul << PWM_BRKCTL2_3_SYSLBEN_Pos)              /*!< PWM_T::BRKCTL2_3: SYSLBEN Mask         */

#define PWM_BRKCTL2_3_BRKAEVEN_Pos       (16)                                              /*!< PWM_T::BRKCTL2_3: BRKAEVEN Position    */
#define PWM_BRKCTL2_3_BRKAEVEN_Msk       (0x3ul << PWM_BRKCTL2_3_BRKAEVEN_Pos)             /*!< PWM_T::BRKCTL2_3: BRKAEVEN Mask        */

#define PWM_BRKCTL2_3_BRKAODD_Pos        (18)                                              /*!< PWM_T::BRKCTL2_3: BRKAODD Position     */
#define PWM_BRKCTL2_3_BRKAODD_Msk        (0x3ul << PWM_BRKCTL2_3_BRKAODD_Pos)              /*!< PWM_T::BRKCTL2_3: BRKAODD Mask         */

#define PWM_BRKCTL4_5_CPO0EBEN_Pos       (0)                                               /*!< PWM_T::BRKCTL4_5: CPO0EBEN Position    */
#define PWM_BRKCTL4_5_CPO0EBEN_Msk       (0x1ul << PWM_BRKCTL4_5_CPO0EBEN_Pos)             /*!< PWM_T::BRKCTL4_5: CPO0EBEN Mask        */

#define PWM_BRKCTL4_5_CPO1EBEN_Pos       (1)                                               /*!< PWM_T::BRKCTL4_5: CPO1EBEN Position    */
#define PWM_BRKCTL4_5_CPO1EBEN_Msk       (0x1ul << PWM_BRKCTL4_5_CPO1EBEN_Pos)             /*!< PWM_T::BRKCTL4_5: CPO1EBEN Mask        */

#define PWM_BRKCTL4_5_BRKP0EEN_Pos       (4)                                               /*!< PWM_T::BRKCTL4_5: BRKP0EEN Position    */
#define PWM_BRKCTL4_5_BRKP0EEN_Msk       (0x1ul << PWM_BRKCTL4_5_BRKP0EEN_Pos)             /*!< PWM_T::BRKCTL4_5: BRKP0EEN Mask        */

#define PWM_BRKCTL4_5_BRKP1EEN_Pos       (5)                                               /*!< PWM_T::BRKCTL4_5: BRKP1EEN Position    */
#define PWM_BRKCTL4_5_BRKP1EEN_Msk       (0x1ul << PWM_BRKCTL4_5_BRKP1EEN_Pos)             /*!< PWM_T::BRKCTL4_5: BRKP1EEN Mask        */

#define PWM_BRKCTL4_5_SYSEBEN_Pos        (7)                                               /*!< PWM_T::BRKCTL4_5: SYSEBEN Position     */
#define PWM_BRKCTL4_5_SYSEBEN_Msk        (0x1ul << PWM_BRKCTL4_5_SYSEBEN_Pos)              /*!< PWM_T::BRKCTL4_5: SYSEBEN Mask         */

#define PWM_BRKCTL4_5_CPO0LBEN_Pos       (8)                                               /*!< PWM_T::BRKCTL4_5: CPO0LBEN Position    */
#define PWM_BRKCTL4_5_CPO0LBEN_Msk       (0x1ul << PWM_BRKCTL4_5_CPO0LBEN_Pos)             /*!< PWM_T::BRKCTL4_5: CPO0LBEN Mask        */

#define PWM_BRKCTL4_5_CPO1LBEN_Pos       (9)                                               /*!< PWM_T::BRKCTL4_5: CPO1LBEN Position    */
#define PWM_BRKCTL4_5_CPO1LBEN_Msk       (0x1ul << PWM_BRKCTL4_5_CPO1LBEN_Pos)             /*!< PWM_T::BRKCTL4_5: CPO1LBEN Mask        */

#define PWM_BRKCTL4_5_BRKP0LEN_Pos       (12)                                              /*!< PWM_T::BRKCTL4_5: BRKP0LEN Position    */
#define PWM_BRKCTL4_5_BRKP0LEN_Msk       (0x1ul << PWM_BRKCTL4_5_BRKP0LEN_Pos)             /*!< PWM_T::BRKCTL4_5: BRKP0LEN Mask        */

#define PWM_BRKCTL4_5_BRKP1LEN_Pos       (13)                                              /*!< PWM_T::BRKCTL4_5: BRKP1LEN Position    */
#define PWM_BRKCTL4_5_BRKP1LEN_Msk       (0x1ul << PWM_BRKCTL4_5_BRKP1LEN_Pos)             /*!< PWM_T::BRKCTL4_5: BRKP1LEN Mask        */

#define PWM_BRKCTL4_5_VBSNLBEN_Pos       (14)                                              /*!< PWM_T::BRKCTL4_5: VBSNLBEN Position    */
#define PWM_BRKCTL4_5_VBSNLBEN_Msk       (0x1ul << PWM_BRKCTL4_5_VBSNLBEN_Pos)             /*!< PWM_T::BRKCTL4_5: VBSNLBEN Mask        */

#define PWM_BRKCTL4_5_SYSLBEN_Pos        (15)                                              /*!< PWM_T::BRKCTL4_5: SYSLBEN Position     */
#define PWM_BRKCTL4_5_SYSLBEN_Msk        (0x1ul << PWM_BRKCTL4_5_SYSLBEN_Pos)              /*!< PWM_T::BRKCTL4_5: SYSLBEN Mask         */

#define PWM_BRKCTL4_5_BRKAEVEN_Pos       (16)                                              /*!< PWM_T::BRKCTL4_5: BRKAEVEN Position    */
#define PWM_BRKCTL4_5_BRKAEVEN_Msk       (0x3ul << PWM_BRKCTL4_5_BRKAEVEN_Pos)             /*!< PWM_T::BRKCTL4_5: BRKAEVEN Mask        */

#define PWM_BRKCTL4_5_BRKAODD_Pos        (18)                                              /*!< PWM_T::BRKCTL4_5: BRKAODD Position     */
#define PWM_BRKCTL4_5_BRKAODD_Msk        (0x3ul << PWM_BRKCTL4_5_BRKAODD_Pos)              /*!< PWM_T::BRKCTL4_5: BRKAODD Mask         */

#define PWM_POLCTL_PINV0_Pos             (0)                                               /*!< PWM_T::POLCTL: PINV0 Position          */
#define PWM_POLCTL_PINV0_Msk             (0x1ul << PWM_POLCTL_PINV0_Pos)                   /*!< PWM_T::POLCTL: PINV0 Mask              */

#define PWM_POLCTL_PINV1_Pos             (1)                                               /*!< PWM_T::POLCTL: PINV1 Position          */
#define PWM_POLCTL_PINV1_Msk             (0x1ul << PWM_POLCTL_PINV1_Pos)                   /*!< PWM_T::POLCTL: PINV1 Mask              */

#define PWM_POLCTL_PINV2_Pos             (2)                                               /*!< PWM_T::POLCTL: PINV2 Position          */
#define PWM_POLCTL_PINV2_Msk             (0x1ul << PWM_POLCTL_PINV2_Pos)                   /*!< PWM_T::POLCTL: PINV2 Mask              */

#define PWM_POLCTL_PINV3_Pos             (3)                                               /*!< PWM_T::POLCTL: PINV3 Position          */
#define PWM_POLCTL_PINV3_Msk             (0x1ul << PWM_POLCTL_PINV3_Pos)                   /*!< PWM_T::POLCTL: PINV3 Mask              */

#define PWM_POLCTL_PINV4_Pos             (4)                                               /*!< PWM_T::POLCTL: PINV4 Position          */
#define PWM_POLCTL_PINV4_Msk             (0x1ul << PWM_POLCTL_PINV4_Pos)                   /*!< PWM_T::POLCTL: PINV4 Mask              */

#define PWM_POLCTL_PINV5_Pos             (5)                                               /*!< PWM_T::POLCTL: PINV5 Position          */
#define PWM_POLCTL_PINV5_Msk             (0x1ul << PWM_POLCTL_PINV5_Pos)                   /*!< PWM_T::POLCTL: PINV5 Mask              */

#define PWM_POEN_POEN0_Pos               (0)                                               /*!< PWM_T::POEN: POEN0 Position            */
#define PWM_POEN_POEN0_Msk               (0x1ul << PWM_POEN_POEN0_Pos)                     /*!< PWM_T::POEN: POEN0 Mask                */

#define PWM_POEN_POEN1_Pos               (1)                                               /*!< PWM_T::POEN: POEN1 Position            */
#define PWM_POEN_POEN1_Msk               (0x1ul << PWM_POEN_POEN1_Pos)                     /*!< PWM_T::POEN: POEN1 Mask                */

#define PWM_POEN_POEN2_Pos               (2)                                               /*!< PWM_T::POEN: POEN2 Position            */
#define PWM_POEN_POEN2_Msk               (0x1ul << PWM_POEN_POEN2_Pos)                     /*!< PWM_T::POEN: POEN2 Mask                */

#define PWM_POEN_POEN3_Pos               (3)                                               /*!< PWM_T::POEN: POEN3 Position            */
#define PWM_POEN_POEN3_Msk               (0x1ul << PWM_POEN_POEN3_Pos)                     /*!< PWM_T::POEN: POEN3 Mask                */

#define PWM_POEN_POEN4_Pos               (4)                                               /*!< PWM_T::POEN: POEN4 Position            */
#define PWM_POEN_POEN4_Msk               (0x1ul << PWM_POEN_POEN4_Pos)                     /*!< PWM_T::POEN: POEN4 Mask                */

#define PWM_POEN_POEN5_Pos               (5)                                               /*!< PWM_T::POEN: POEN5 Position            */
#define PWM_POEN_POEN5_Msk               (0x1ul << PWM_POEN_POEN5_Pos)                     /*!< PWM_T::POEN: POEN5 Mask                */

#define PWM_SWBRK_BRKETRG0_Pos           (0)                                               /*!< PWM_T::SWBRK: BRKETRG0 Position        */
#define PWM_SWBRK_BRKETRG0_Msk           (0x1ul << PWM_SWBRK_BRKETRG0_Pos)                 /*!< PWM_T::SWBRK: BRKETRG0 Mask            */

#define PWM_SWBRK_BRKETRG2_Pos           (1)                                               /*!< PWM_T::SWBRK: BRKETRG2 Position        */
#define PWM_SWBRK_BRKETRG2_Msk           (0x1ul << PWM_SWBRK_BRKETRG2_Pos)                 /*!< PWM_T::SWBRK: BRKETRG2 Mask            */

#define PWM_SWBRK_BRKETRG4_Pos           (2)                                               /*!< PWM_T::SWBRK: BRKETRG4 Position        */
#define PWM_SWBRK_BRKETRG4_Msk           (0x1ul << PWM_SWBRK_BRKETRG4_Pos)                 /*!< PWM_T::SWBRK: BRKETRG4 Mask            */

#define PWM_SWBRK_BRKLTRG0_Pos           (8)                                               /*!< PWM_T::SWBRK: BRKLTRG0 Position        */
#define PWM_SWBRK_BRKLTRG0_Msk           (0x1ul << PWM_SWBRK_BRKLTRG0_Pos)                 /*!< PWM_T::SWBRK: BRKLTRG0 Mask            */

#define PWM_SWBRK_BRKLTRG2_Pos           (9)                                               /*!< PWM_T::SWBRK: BRKLTRG2 Position        */
#define PWM_SWBRK_BRKLTRG2_Msk           (0x1ul << PWM_SWBRK_BRKLTRG2_Pos)                 /*!< PWM_T::SWBRK: BRKLTRG2 Mask            */

#define PWM_SWBRK_BRKLTRG4_Pos           (10)                                              /*!< PWM_T::SWBRK: BRKLTRG4 Position        */
#define PWM_SWBRK_BRKLTRG4_Msk           (0x1ul << PWM_SWBRK_BRKLTRG4_Pos)                 /*!< PWM_T::SWBRK: BRKLTRG4 Mask            */

#define PWM_INTEN0_ZIEN0_Pos             (0)                                               /*!< PWM_T::INTEN0: ZIEN0 Position          */
#define PWM_INTEN0_ZIEN0_Msk             (0x1ul << PWM_INTEN0_ZIEN0_Pos)                   /*!< PWM_T::INTEN0: ZIEN0 Mask              */

#define PWM_INTEN0_ZIEN2_Pos             (2)                                               /*!< PWM_T::INTEN0: ZIEN2 Position          */
#define PWM_INTEN0_ZIEN2_Msk             (0x1ul << PWM_INTEN0_ZIEN2_Pos)                   /*!< PWM_T::INTEN0: ZIEN2 Mask              */

#define PWM_INTEN0_ZIEN4_Pos             (4)                                               /*!< PWM_T::INTEN0: ZIEN4 Position          */
#define PWM_INTEN0_ZIEN4_Msk             (0x1ul << PWM_INTEN0_ZIEN4_Pos)                   /*!< PWM_T::INTEN0: ZIEN4 Mask              */

#define PWM_INTEN0_PIEN0_Pos             (8)                                               /*!< PWM_T::INTEN0: PIEN0 Position          */
#define PWM_INTEN0_PIEN0_Msk             (0x1ul << PWM_INTEN0_PIEN0_Pos)                   /*!< PWM_T::INTEN0: PIEN0 Mask              */

#define PWM_INTEN0_PIEN2_Pos             (10)                                              /*!< PWM_T::INTEN0: PIEN2 Position          */
#define PWM_INTEN0_PIEN2_Msk             (0x1ul << PWM_INTEN0_PIEN2_Pos)                   /*!< PWM_T::INTEN0: PIEN2 Mask              */

#define PWM_INTEN0_PIEN4_Pos             (12)                                              /*!< PWM_T::INTEN0: PIEN4 Position          */
#define PWM_INTEN0_PIEN4_Msk             (0x1ul << PWM_INTEN0_PIEN4_Pos)                   /*!< PWM_T::INTEN0: PIEN4 Mask              */

#define PWM_INTEN0_CMPUIEN0_Pos          (16)                                              /*!< PWM_T::INTEN0: CMPUIEN0 Position       */
#define PWM_INTEN0_CMPUIEN0_Msk          (0x1ul << PWM_INTEN0_CMPUIEN0_Pos)                /*!< PWM_T::INTEN0: CMPUIEN0 Mask           */

#define PWM_INTEN0_CMPUIEN1_Pos          (17)                                              /*!< PWM_T::INTEN0: CMPUIEN1 Position       */
#define PWM_INTEN0_CMPUIEN1_Msk          (0x1ul << PWM_INTEN0_CMPUIEN1_Pos)                /*!< PWM_T::INTEN0: CMPUIEN1 Mask           */

#define PWM_INTEN0_CMPUIEN2_Pos          (18)                                              /*!< PWM_T::INTEN0: CMPUIEN2 Position       */
#define PWM_INTEN0_CMPUIEN2_Msk          (0x1ul << PWM_INTEN0_CMPUIEN2_Pos)                /*!< PWM_T::INTEN0: CMPUIEN2 Mask           */

#define PWM_INTEN0_CMPUIEN3_Pos          (19)                                              /*!< PWM_T::INTEN0: CMPUIEN3 Position       */
#define PWM_INTEN0_CMPUIEN3_Msk          (0x1ul << PWM_INTEN0_CMPUIEN3_Pos)                /*!< PWM_T::INTEN0: CMPUIEN3 Mask           */

#define PWM_INTEN0_CMPUIEN4_Pos          (20)                                              /*!< PWM_T::INTEN0: CMPUIEN4 Position       */
#define PWM_INTEN0_CMPUIEN4_Msk          (0x1ul << PWM_INTEN0_CMPUIEN4_Pos)                /*!< PWM_T::INTEN0: CMPUIEN4 Mask           */

#define PWM_INTEN0_CMPUIEN5_Pos          (21)                                              /*!< PWM_T::INTEN0: CMPUIEN5 Position       */
#define PWM_INTEN0_CMPUIEN5_Msk          (0x1ul << PWM_INTEN0_CMPUIEN5_Pos)                /*!< PWM_T::INTEN0: CMPUIEN5 Mask           */

#define PWM_INTEN0_CMPDIEN0_Pos          (24)                                              /*!< PWM_T::INTEN0: CMPDIEN0 Position       */
#define PWM_INTEN0_CMPDIEN0_Msk          (0x1ul << PWM_INTEN0_CMPDIEN0_Pos)                /*!< PWM_T::INTEN0: CMPDIEN0 Mask           */

#define PWM_INTEN0_CMPDIEN1_Pos          (25)                                              /*!< PWM_T::INTEN0: CMPDIEN1 Position       */
#define PWM_INTEN0_CMPDIEN1_Msk          (0x1ul << PWM_INTEN0_CMPDIEN1_Pos)                /*!< PWM_T::INTEN0: CMPDIEN1 Mask           */

#define PWM_INTEN0_CMPDIEN2_Pos          (26)                                              /*!< PWM_T::INTEN0: CMPDIEN2 Position       */
#define PWM_INTEN0_CMPDIEN2_Msk          (0x1ul << PWM_INTEN0_CMPDIEN2_Pos)                /*!< PWM_T::INTEN0: CMPDIEN2 Mask           */

#define PWM_INTEN0_CMPDIEN3_Pos          (27)                                              /*!< PWM_T::INTEN0: CMPDIEN3 Position       */
#define PWM_INTEN0_CMPDIEN3_Msk          (0x1ul << PWM_INTEN0_CMPDIEN3_Pos)                /*!< PWM_T::INTEN0: CMPDIEN3 Mask           */

#define PWM_INTEN0_CMPDIEN4_Pos          (28)                                              /*!< PWM_T::INTEN0: CMPDIEN4 Position       */
#define PWM_INTEN0_CMPDIEN4_Msk          (0x1ul << PWM_INTEN0_CMPDIEN4_Pos)                /*!< PWM_T::INTEN0: CMPDIEN4 Mask           */

#define PWM_INTEN0_CMPDIEN5_Pos          (29)                                              /*!< PWM_T::INTEN0: CMPDIEN5 Position       */
#define PWM_INTEN0_CMPDIEN5_Msk          (0x1ul << PWM_INTEN0_CMPDIEN5_Pos)                /*!< PWM_T::INTEN0: CMPDIEN5 Mask           */

#define PWM_INTEN1_BRKEIEN0_1_Pos        (0)                                               /*!< PWM_T::INTEN1: BRKEIEN0_1 Position     */
#define PWM_INTEN1_BRKEIEN0_1_Msk        (0x1ul << PWM_INTEN1_BRKEIEN0_1_Pos)              /*!< PWM_T::INTEN1: BRKEIEN0_1 Mask         */

#define PWM_INTEN1_BRKEIEN2_3_Pos        (1)                                               /*!< PWM_T::INTEN1: BRKEIEN2_3 Position     */
#define PWM_INTEN1_BRKEIEN2_3_Msk        (0x1ul << PWM_INTEN1_BRKEIEN2_3_Pos)              /*!< PWM_T::INTEN1: BRKEIEN2_3 Mask         */

#define PWM_INTEN1_BRKEIEN4_5_Pos        (2)                                               /*!< PWM_T::INTEN1: BRKEIEN4_5 Position     */
#define PWM_INTEN1_BRKEIEN4_5_Msk        (0x1ul << PWM_INTEN1_BRKEIEN4_5_Pos)              /*!< PWM_T::INTEN1: BRKEIEN4_5 Mask         */

#define PWM_INTEN1_BRKLIEN0_1_Pos        (8)                                               /*!< PWM_T::INTEN1: BRKLIEN0_1 Position     */
#define PWM_INTEN1_BRKLIEN0_1_Msk        (0x1ul << PWM_INTEN1_BRKLIEN0_1_Pos)              /*!< PWM_T::INTEN1: BRKLIEN0_1 Mask         */

#define PWM_INTEN1_BRKLIEN2_3_Pos        (9)                                               /*!< PWM_T::INTEN1: BRKLIEN2_3 Position     */
#define PWM_INTEN1_BRKLIEN2_3_Msk        (0x1ul << PWM_INTEN1_BRKLIEN2_3_Pos)              /*!< PWM_T::INTEN1: BRKLIEN2_3 Mask         */

#define PWM_INTEN1_BRKLIEN4_5_Pos        (10)                                              /*!< PWM_T::INTEN1: BRKLIEN4_5 Position     */
#define PWM_INTEN1_BRKLIEN4_5_Msk        (0x1ul << PWM_INTEN1_BRKLIEN4_5_Pos)              /*!< PWM_T::INTEN1: BRKLIEN4_5 Mask         */

#define PWM_INTSTS0_ZIF0_Pos             (0)                                               /*!< PWM_T::INTSTS0: ZIF0 Position          */
#define PWM_INTSTS0_ZIF0_Msk             (0x1ul << PWM_INTSTS0_ZIF0_Pos)                   /*!< PWM_T::INTSTS0: ZIF0 Mask              */

#define PWM_INTSTS0_ZIF2_Pos             (2)                                               /*!< PWM_T::INTSTS0: ZIF2 Position          */
#define PWM_INTSTS0_ZIF2_Msk             (0x1ul << PWM_INTSTS0_ZIF2_Pos)                   /*!< PWM_T::INTSTS0: ZIF2 Mask              */

#define PWM_INTSTS0_ZIF4_Pos             (4)                                               /*!< PWM_T::INTSTS0: ZIF4 Position          */
#define PWM_INTSTS0_ZIF4_Msk             (0x1ul << PWM_INTSTS0_ZIF4_Pos)                   /*!< PWM_T::INTSTS0: ZIF4 Mask              */

#define PWM_INTSTS0_PIF0_Pos             (8)                                               /*!< PWM_T::INTSTS0: PIF0 Position          */
#define PWM_INTSTS0_PIF0_Msk             (0x1ul << PWM_INTSTS0_PIF0_Pos)                   /*!< PWM_T::INTSTS0: PIF0 Mask              */

#define PWM_INTSTS0_PIF2_Pos             (10)                                              /*!< PWM_T::INTSTS0: PIF2 Position          */
#define PWM_INTSTS0_PIF2_Msk             (0x1ul << PWM_INTSTS0_PIF2_Pos)                   /*!< PWM_T::INTSTS0: PIF2 Mask              */

#define PWM_INTSTS0_PIF4_Pos             (12)                                              /*!< PWM_T::INTSTS0: PIF4 Position          */
#define PWM_INTSTS0_PIF4_Msk             (0x1ul << PWM_INTSTS0_PIF4_Pos)                   /*!< PWM_T::INTSTS0: PIF4 Mask              */

#define PWM_INTSTS0_CMPUIF0_Pos          (16)                                              /*!< PWM_T::INTSTS0: CMPUIF0 Position       */
#define PWM_INTSTS0_CMPUIF0_Msk          (0x3ful << PWM_INTSTS0_CMPUIF0_Pos)               /*!< PWM_T::INTSTS0: CMPUIF0 Mask           */

#define PWM_INTSTS0_CMPDIF0_Pos          (24)                                              /*!< PWM_T::INTSTS0: CMPDIF0 Position       */
#define PWM_INTSTS0_CMPDIF0_Msk          (0x1ul << PWM_INTSTS0_CMPDIF0_Pos)                /*!< PWM_T::INTSTS0: CMPDIF0 Mask           */

#define PWM_INTSTS0_CMPDIF1_Pos          (25)                                              /*!< PWM_T::INTSTS0: CMPDIF1 Position       */
#define PWM_INTSTS0_CMPDIF1_Msk          (0x1ul << PWM_INTSTS0_CMPDIF1_Pos)                /*!< PWM_T::INTSTS0: CMPDIF1 Mask           */

#define PWM_INTSTS0_CMPDIF2_Pos          (26)                                              /*!< PWM_T::INTSTS0: CMPDIF2 Position       */
#define PWM_INTSTS0_CMPDIF2_Msk          (0x1ul << PWM_INTSTS0_CMPDIF2_Pos)                /*!< PWM_T::INTSTS0: CMPDIF2 Mask           */

#define PWM_INTSTS0_CMPDIF3_Pos          (27)                                              /*!< PWM_T::INTSTS0: CMPDIF3 Position       */
#define PWM_INTSTS0_CMPDIF3_Msk          (0x1ul << PWM_INTSTS0_CMPDIF3_Pos)                /*!< PWM_T::INTSTS0: CMPDIF3 Mask           */

#define PWM_INTSTS0_CMPDIF4_Pos          (28)                                              /*!< PWM_T::INTSTS0: CMPDIF4 Position       */
#define PWM_INTSTS0_CMPDIF4_Msk          (0x1ul << PWM_INTSTS0_CMPDIF4_Pos)                /*!< PWM_T::INTSTS0: CMPDIF4 Mask           */

#define PWM_INTSTS0_CMPDIF5_Pos          (29)                                              /*!< PWM_T::INTSTS0: CMPDIF5 Position       */
#define PWM_INTSTS0_CMPDIF5_Msk          (0x1ul << PWM_INTSTS0_CMPDIF5_Pos)                /*!< PWM_T::INTSTS0: CMPDIF5 Mask           */

#define PWM_INTSTS1_BRKEIF0_Pos          (0)                                               /*!< PWM_T::INTSTS1: BRKEIF0 Position       */
#define PWM_INTSTS1_BRKEIF0_Msk          (0x1ul << PWM_INTSTS1_BRKEIF0_Pos)                /*!< PWM_T::INTSTS1: BRKEIF0 Mask           */

#define PWM_INTSTS1_BRKEIF1_Pos          (1)                                               /*!< PWM_T::INTSTS1: BRKEIF1 Position       */
#define PWM_INTSTS1_BRKEIF1_Msk          (0x1ul << PWM_INTSTS1_BRKEIF1_Pos)                /*!< PWM_T::INTSTS1: BRKEIF1 Mask           */

#define PWM_INTSTS1_BRKEIF2_Pos          (2)                                               /*!< PWM_T::INTSTS1: BRKEIF2 Position       */
#define PWM_INTSTS1_BRKEIF2_Msk          (0x1ul << PWM_INTSTS1_BRKEIF2_Pos)                /*!< PWM_T::INTSTS1: BRKEIF2 Mask           */

#define PWM_INTSTS1_BRKEIF3_Pos          (3)                                               /*!< PWM_T::INTSTS1: BRKEIF3 Position       */
#define PWM_INTSTS1_BRKEIF3_Msk          (0x1ul << PWM_INTSTS1_BRKEIF3_Pos)                /*!< PWM_T::INTSTS1: BRKEIF3 Mask           */

#define PWM_INTSTS1_BRKEIF4_Pos          (4)                                               /*!< PWM_T::INTSTS1: BRKEIF4 Position       */
#define PWM_INTSTS1_BRKEIF4_Msk          (0x1ul << PWM_INTSTS1_BRKEIF4_Pos)                /*!< PWM_T::INTSTS1: BRKEIF4 Mask           */

#define PWM_INTSTS1_BRKEIF5_Pos          (5)                                               /*!< PWM_T::INTSTS1: BRKEIF5 Position       */
#define PWM_INTSTS1_BRKEIF5_Msk          (0x1ul << PWM_INTSTS1_BRKEIF5_Pos)                /*!< PWM_T::INTSTS1: BRKEIF5 Mask           */

#define PWM_INTSTS1_BRKLIF0_Pos          (8)                                               /*!< PWM_T::INTSTS1: BRKLIF0 Position       */
#define PWM_INTSTS1_BRKLIF0_Msk          (0x1ul << PWM_INTSTS1_BRKLIF0_Pos)                /*!< PWM_T::INTSTS1: BRKLIF0 Mask           */

#define PWM_INTSTS1_BRKLIF1_Pos          (9)                                               /*!< PWM_T::INTSTS1: BRKLIF1 Position       */
#define PWM_INTSTS1_BRKLIF1_Msk          (0x1ul << PWM_INTSTS1_BRKLIF1_Pos)                /*!< PWM_T::INTSTS1: BRKLIF1 Mask           */

#define PWM_INTSTS1_BRKLIF2_Pos          (10)                                              /*!< PWM_T::INTSTS1: BRKLIF2 Position       */
#define PWM_INTSTS1_BRKLIF2_Msk          (0x1ul << PWM_INTSTS1_BRKLIF2_Pos)                /*!< PWM_T::INTSTS1: BRKLIF2 Mask           */

#define PWM_INTSTS1_BRKLIF3_Pos          (11)                                              /*!< PWM_T::INTSTS1: BRKLIF3 Position       */
#define PWM_INTSTS1_BRKLIF3_Msk          (0x1ul << PWM_INTSTS1_BRKLIF3_Pos)                /*!< PWM_T::INTSTS1: BRKLIF3 Mask           */

#define PWM_INTSTS1_BRKLIF4_Pos          (12)                                              /*!< PWM_T::INTSTS1: BRKLIF4 Position       */
#define PWM_INTSTS1_BRKLIF4_Msk          (0x1ul << PWM_INTSTS1_BRKLIF4_Pos)                /*!< PWM_T::INTSTS1: BRKLIF4 Mask           */

#define PWM_INTSTS1_BRKLIF5_Pos          (13)                                              /*!< PWM_T::INTSTS1: BRKLIF5 Position       */
#define PWM_INTSTS1_BRKLIF5_Msk          (0x1ul << PWM_INTSTS1_BRKLIF5_Pos)                /*!< PWM_T::INTSTS1: BRKLIF5 Mask           */

#define PWM_INTSTS1_BRKESTS0_Pos         (16)                                              /*!< PWM_T::INTSTS1: BRKESTS0 Position      */
#define PWM_INTSTS1_BRKESTS0_Msk         (0x1ul << PWM_INTSTS1_BRKESTS0_Pos)               /*!< PWM_T::INTSTS1: BRKESTS0 Mask          */

#define PWM_INTSTS1_BRKESTS1_Pos         (17)                                              /*!< PWM_T::INTSTS1: BRKESTS1 Position      */
#define PWM_INTSTS1_BRKESTS1_Msk         (0x1ul << PWM_INTSTS1_BRKESTS1_Pos)               /*!< PWM_T::INTSTS1: BRKESTS1 Mask          */

#define PWM_INTSTS1_BRKESTS2_Pos         (18)                                              /*!< PWM_T::INTSTS1: BRKESTS2 Position      */
#define PWM_INTSTS1_BRKESTS2_Msk         (0x1ul << PWM_INTSTS1_BRKESTS2_Pos)               /*!< PWM_T::INTSTS1: BRKESTS2 Mask          */

#define PWM_INTSTS1_BRKESTS3_Pos         (19)                                              /*!< PWM_T::INTSTS1: BRKESTS3 Position      */
#define PWM_INTSTS1_BRKESTS3_Msk         (0x1ul << PWM_INTSTS1_BRKESTS3_Pos)               /*!< PWM_T::INTSTS1: BRKESTS3 Mask          */

#define PWM_INTSTS1_BRKESTS4_Pos         (20)                                              /*!< PWM_T::INTSTS1: BRKESTS4 Position      */
#define PWM_INTSTS1_BRKESTS4_Msk         (0x1ul << PWM_INTSTS1_BRKESTS4_Pos)               /*!< PWM_T::INTSTS1: BRKESTS4 Mask          */

#define PWM_INTSTS1_BRKESTS5_Pos         (21)                                              /*!< PWM_T::INTSTS1: BRKESTS5 Position      */
#define PWM_INTSTS1_BRKESTS5_Msk         (0x1ul << PWM_INTSTS1_BRKESTS5_Pos)               /*!< PWM_T::INTSTS1: BRKESTS5 Mask          */

#define PWM_INTSTS1_BRKLSTS0_Pos         (24)                                              /*!< PWM_T::INTSTS1: BRKLSTS0 Position      */
#define PWM_INTSTS1_BRKLSTS0_Msk         (0x1ul << PWM_INTSTS1_BRKLSTS0_Pos)               /*!< PWM_T::INTSTS1: BRKLSTS0 Mask          */

#define PWM_INTSTS1_BRKLSTS1_Pos         (25)                                              /*!< PWM_T::INTSTS1: BRKLSTS1 Position      */
#define PWM_INTSTS1_BRKLSTS1_Msk         (0x1ul << PWM_INTSTS1_BRKLSTS1_Pos)               /*!< PWM_T::INTSTS1: BRKLSTS1 Mask          */

#define PWM_INTSTS1_BRKLSTS2_Pos         (26)                                              /*!< PWM_T::INTSTS1: BRKLSTS2 Position      */
#define PWM_INTSTS1_BRKLSTS2_Msk         (0x1ul << PWM_INTSTS1_BRKLSTS2_Pos)               /*!< PWM_T::INTSTS1: BRKLSTS2 Mask          */

#define PWM_INTSTS1_BRKLSTS3_Pos         (27)                                              /*!< PWM_T::INTSTS1: BRKLSTS3 Position      */
#define PWM_INTSTS1_BRKLSTS3_Msk         (0x1ul << PWM_INTSTS1_BRKLSTS3_Pos)               /*!< PWM_T::INTSTS1: BRKLSTS3 Mask          */

#define PWM_INTSTS1_BRKLSTS4_Pos         (28)                                              /*!< PWM_T::INTSTS1: BRKLSTS4 Position      */
#define PWM_INTSTS1_BRKLSTS4_Msk         (0x1ul << PWM_INTSTS1_BRKLSTS4_Pos)               /*!< PWM_T::INTSTS1: BRKLSTS4 Mask          */

#define PWM_INTSTS1_BRKLSTS5_Pos         (29)                                              /*!< PWM_T::INTSTS1: BRKLSTS5 Position      */
#define PWM_INTSTS1_BRKLSTS5_Msk         (0x1ul << PWM_INTSTS1_BRKLSTS5_Pos)               /*!< PWM_T::INTSTS1: BRKLSTS5 Mask          */

#define PWM_ADCTS0_TRGSEL0_Pos           (0)                                               /*!< PWM_T::ADCTS0: TRGSEL0 Position        */
#define PWM_ADCTS0_TRGSEL0_Msk           (0xful << PWM_ADCTS0_TRGSEL0_Pos)                 /*!< PWM_T::ADCTS0: TRGSEL0 Mask            */

#define PWM_ADCTS0_TRGEN0_Pos            (7)                                               /*!< PWM_T::ADCTS0: TRGEN0 Position         */
#define PWM_ADCTS0_TRGEN0_Msk            (0x1ul << PWM_ADCTS0_TRGEN0_Pos)                  /*!< PWM_T::ADCTS0: TRGEN0 Mask             */

#define PWM_ADCTS0_TRGSEL1_Pos           (8)                                               /*!< PWM_T::ADCTS0: TRGSEL1 Position        */
#define PWM_ADCTS0_TRGSEL1_Msk           (0xful << PWM_ADCTS0_TRGSEL1_Pos)                 /*!< PWM_T::ADCTS0: TRGSEL1 Mask            */

#define PWM_ADCTS0_TRGEN1_Pos            (15)                                              /*!< PWM_T::ADCTS0: TRGEN1 Position         */
#define PWM_ADCTS0_TRGEN1_Msk            (0x1ul << PWM_ADCTS0_TRGEN1_Pos)                  /*!< PWM_T::ADCTS0: TRGEN1 Mask             */

#define PWM_ADCTS0_TRGSEL2_Pos           (16)                                              /*!< PWM_T::ADCTS0: TRGSEL2 Position        */
#define PWM_ADCTS0_TRGSEL2_Msk           (0xful << PWM_ADCTS0_TRGSEL2_Pos)                 /*!< PWM_T::ADCTS0: TRGSEL2 Mask            */

#define PWM_ADCTS0_TRGEN2_Pos            (23)                                              /*!< PWM_T::ADCTS0: TRGEN2 Position         */
#define PWM_ADCTS0_TRGEN2_Msk            (0x1ul << PWM_ADCTS0_TRGEN2_Pos)                  /*!< PWM_T::ADCTS0: TRGEN2 Mask             */

#define PWM_ADCTS0_TRGSEL3_Pos           (24)                                              /*!< PWM_T::ADCTS0: TRGSEL3 Position        */
#define PWM_ADCTS0_TRGSEL3_Msk           (0xful << PWM_ADCTS0_TRGSEL3_Pos)                 /*!< PWM_T::ADCTS0: TRGSEL3 Mask            */

#define PWM_ADCTS0_TRGEN3_Pos            (31)                                              /*!< PWM_T::ADCTS0: TRGEN3 Position         */
#define PWM_ADCTS0_TRGEN3_Msk            (0x1ul << PWM_ADCTS0_TRGEN3_Pos)                  /*!< PWM_T::ADCTS0: TRGEN3 Mask             */

#define PWM_ADCTS1_TRGSEL4_Pos           (0)                                               /*!< PWM_T::ADCTS1: TRGSEL4 Position        */
#define PWM_ADCTS1_TRGSEL4_Msk           (0xful << PWM_ADCTS1_TRGSEL4_Pos)                 /*!< PWM_T::ADCTS1: TRGSEL4 Mask            */

#define PWM_ADCTS1_TRGEN4_Pos            (7)                                               /*!< PWM_T::ADCTS1: TRGEN4 Position         */
#define PWM_ADCTS1_TRGEN4_Msk            (0x1ul << PWM_ADCTS1_TRGEN4_Pos)                  /*!< PWM_T::ADCTS1: TRGEN4 Mask             */

#define PWM_ADCTS1_TRGSEL5_Pos           (8)                                               /*!< PWM_T::ADCTS1: TRGSEL5 Position        */
#define PWM_ADCTS1_TRGSEL5_Msk           (0xful << PWM_ADCTS1_TRGSEL5_Pos)                 /*!< PWM_T::ADCTS1: TRGSEL5 Mask            */

#define PWM_ADCTS1_TRGEN5_Pos            (15)                                              /*!< PWM_T::ADCTS1: TRGEN5 Position         */
#define PWM_ADCTS1_TRGEN5_Msk            (0x1ul << PWM_ADCTS1_TRGEN5_Pos)                  /*!< PWM_T::ADCTS1: TRGEN5 Mask             */

#define PWM_SSCTL_SSEN0_Pos              (0)                                               /*!< PWM_T::SSCTL: SSEN0 Position           */
#define PWM_SSCTL_SSEN0_Msk              (0x1ul << PWM_SSCTL_SSEN0_Pos)                    /*!< PWM_T::SSCTL: SSEN0 Mask               */

#define PWM_SSCTL_SSEN2_Pos              (2)                                               /*!< PWM_T::SSCTL: SSEN2 Position           */
#define PWM_SSCTL_SSEN2_Msk              (0x1ul << PWM_SSCTL_SSEN2_Pos)                    /*!< PWM_T::SSCTL: SSEN2 Mask               */

#define PWM_SSCTL_SSEN4_Pos              (4)                                               /*!< PWM_T::SSCTL: SSEN4 Position           */
#define PWM_SSCTL_SSEN4_Msk              (0x1ul << PWM_SSCTL_SSEN4_Pos)                    /*!< PWM_T::SSCTL: SSEN4 Mask               */

#define PWM_SSCTL_SSRC_Pos               (8)                                               /*!< PWM_T::SSCTL: SSRC Position            */
#define PWM_SSCTL_SSRC_Msk               (0x3ul << PWM_SSCTL_SSRC_Pos)                     /*!< PWM_T::SSCTL: SSRC Mask                */

#define PWM_SSTRG_CNTSEN_Pos             (0)                                               /*!< PWM_T::SSTRG: CNTSEN Position          */
#define PWM_SSTRG_CNTSEN_Msk             (0x1ul << PWM_SSTRG_CNTSEN_Pos)                   /*!< PWM_T::SSTRG: CNTSEN Mask              */

#define PWM_STATUS_CNTMAX0_Pos           (0)                                               /*!< PWM_T::STATUS: CNTMAX0 Position        */
#define PWM_STATUS_CNTMAX0_Msk           (0x1ul << PWM_STATUS_CNTMAX0_Pos)                 /*!< PWM_T::STATUS: CNTMAX0 Mask            */

#define PWM_STATUS_CNTMAX2_Pos           (2)                                               /*!< PWM_T::STATUS: CNTMAX2 Position        */
#define PWM_STATUS_CNTMAX2_Msk           (0x1ul << PWM_STATUS_CNTMAX2_Pos)                 /*!< PWM_T::STATUS: CNTMAX2 Mask            */

#define PWM_STATUS_CNTMAX4_Pos           (4)                                               /*!< PWM_T::STATUS: CNTMAX4 Position        */
#define PWM_STATUS_CNTMAX4_Msk           (0x1ul << PWM_STATUS_CNTMAX4_Pos)                 /*!< PWM_T::STATUS: CNTMAX4 Mask            */

#define PWM_STATUS_ADCTRG0_Pos           (16)                                              /*!< PWM_T::STATUS: ADCTRG0 Position        */
#define PWM_STATUS_ADCTRG0_Msk           (0x1ul << PWM_STATUS_ADCTRG0_Pos)                 /*!< PWM_T::STATUS: ADCTRG0 Mask            */

#define PWM_STATUS_ADCTRG1_Pos           (17)                                              /*!< PWM_T::STATUS: ADCTRG1 Position        */
#define PWM_STATUS_ADCTRG1_Msk           (0x1ul << PWM_STATUS_ADCTRG1_Pos)                 /*!< PWM_T::STATUS: ADCTRG1 Mask            */

#define PWM_STATUS_ADCTRG2_Pos           (18)                                              /*!< PWM_T::STATUS: ADCTRG2 Position        */
#define PWM_STATUS_ADCTRG2_Msk           (0x1ul << PWM_STATUS_ADCTRG2_Pos)                 /*!< PWM_T::STATUS: ADCTRG2 Mask            */

#define PWM_STATUS_ADCTRG3_Pos           (19)                                              /*!< PWM_T::STATUS: ADCTRG3 Position        */
#define PWM_STATUS_ADCTRG3_Msk           (0x1ul << PWM_STATUS_ADCTRG3_Pos)                 /*!< PWM_T::STATUS: ADCTRG3 Mask            */

#define PWM_STATUS_ADCTRG4_Pos           (20)                                              /*!< PWM_T::STATUS: ADCTRG4 Position        */
#define PWM_STATUS_ADCTRG4_Msk           (0x1ul << PWM_STATUS_ADCTRG4_Pos)                 /*!< PWM_T::STATUS: ADCTRG4 Mask            */

#define PWM_STATUS_ADCTRG5_Pos           (21)                                              /*!< PWM_T::STATUS: ADCTRG5 Position        */
#define PWM_STATUS_ADCTRG5_Msk           (0x1ul << PWM_STATUS_ADCTRG5_Pos)                 /*!< PWM_T::STATUS: ADCTRG5 Mask            */

#define PWM_IFA0_IFACNT_Pos              (0)                                               /*!< PWM_T::IFA0: IFACNT Position           */
#define PWM_IFA0_IFACNT_Msk              (0xfful << PWM_IFA0_IFACNT_Pos)                   /*!< PWM_T::IFA0: IFACNT Mask               */

#define PWM_IFA0_STPMOD_Pos              (24)                                              /*!< PWM_T::IFA0: STPMOD Position           */
#define PWM_IFA0_STPMOD_Msk              (0x1ul << PWM_IFA0_STPMOD_Pos)                    /*!< PWM_T::IFA0: STPMOD Mask               */

#define PWM_IFA0_IFASEL_Pos              (28)                                              /*!< PWM_T::IFA0: IFASEL Position           */
#define PWM_IFA0_IFASEL_Msk              (0x3ul << PWM_IFA0_IFASEL_Pos)                    /*!< PWM_T::IFA0: IFASEL Mask               */

#define PWM_IFA0_IFAEN_Pos               (31)                                              /*!< PWM_T::IFA0: IFAEN Position            */
#define PWM_IFA0_IFAEN_Msk               (0x1ul << PWM_IFA0_IFAEN_Pos)                     /*!< PWM_T::IFA0: IFAEN Mask                */

#define PWM_IFA2_IFACNT_Pos              (0)                                               /*!< PWM_T::IFA2: IFACNT Position           */
#define PWM_IFA2_IFACNT_Msk              (0xfful << PWM_IFA2_IFACNT_Pos)                   /*!< PWM_T::IFA2: IFACNT Mask               */

#define PWM_IFA2_STPMOD_Pos              (24)                                              /*!< PWM_T::IFA2: STPMOD Position           */
#define PWM_IFA2_STPMOD_Msk              (0x1ul << PWM_IFA2_STPMOD_Pos)                    /*!< PWM_T::IFA2: STPMOD Mask               */

#define PWM_IFA2_IFASEL_Pos              (28)                                              /*!< PWM_T::IFA2: IFASEL Position           */
#define PWM_IFA2_IFASEL_Msk              (0x3ul << PWM_IFA2_IFASEL_Pos)                    /*!< PWM_T::IFA2: IFASEL Mask               */

#define PWM_IFA2_IFAEN_Pos               (31)                                              /*!< PWM_T::IFA2: IFAEN Position            */
#define PWM_IFA2_IFAEN_Msk               (0x1ul << PWM_IFA2_IFAEN_Pos)                     /*!< PWM_T::IFA2: IFAEN Mask                */

#define PWM_IFA4_IFACNT_Pos              (0)                                               /*!< PWM_T::IFA4: IFACNT Position           */
#define PWM_IFA4_IFACNT_Msk              (0xfful << PWM_IFA4_IFACNT_Pos)                   /*!< PWM_T::IFA4: IFACNT Mask               */

#define PWM_IFA4_STPMOD_Pos              (24)                                              /*!< PWM_T::IFA4: STPMOD Position           */
#define PWM_IFA4_STPMOD_Msk              (0x1ul << PWM_IFA4_STPMOD_Pos)                    /*!< PWM_T::IFA4: STPMOD Mask               */

#define PWM_IFA4_IFASEL_Pos              (28)                                              /*!< PWM_T::IFA4: IFASEL Position           */
#define PWM_IFA4_IFASEL_Msk              (0x3ul << PWM_IFA4_IFASEL_Pos)                    /*!< PWM_T::IFA4: IFASEL Mask               */

#define PWM_IFA4_IFAEN_Pos               (31)                                              /*!< PWM_T::IFA4: IFAEN Position            */
#define PWM_IFA4_IFAEN_Msk               (0x1ul << PWM_IFA4_IFAEN_Pos)                     /*!< PWM_T::IFA4: IFAEN Mask                */

#define PWM_AINTSTS_IFAIF0_Pos           (0)                                               /*!< PWM_T::AINTSTS: IFAIF0 Position        */
#define PWM_AINTSTS_IFAIF0_Msk           (0x1ul << PWM_AINTSTS_IFAIF0_Pos)                 /*!< PWM_T::AINTSTS: IFAIF0 Mask            */

#define PWM_AINTSTS_IFAIF2_Pos           (2)                                               /*!< PWM_T::AINTSTS: IFAIF2 Position        */
#define PWM_AINTSTS_IFAIF2_Msk           (0x1ul << PWM_AINTSTS_IFAIF2_Pos)                 /*!< PWM_T::AINTSTS: IFAIF2 Mask            */

#define PWM_AINTSTS_IFAIF4_Pos           (4)                                               /*!< PWM_T::AINTSTS: IFAIF4 Position        */
#define PWM_AINTSTS_IFAIF4_Msk           (0x1ul << PWM_AINTSTS_IFAIF4_Pos)                 /*!< PWM_T::AINTSTS: IFAIF4 Mask            */

#define PWM_AINTEN_IFAIEN0_Pos           (0)                                               /*!< PWM_T::AINTEN: IFAIEN0 Position        */
#define PWM_AINTEN_IFAIEN0_Msk           (0x1ul << PWM_AINTEN_IFAIEN0_Pos)                 /*!< PWM_T::AINTEN: IFAIEN0 Mask            */

#define PWM_AINTEN_IFAIEN2_Pos           (2)                                               /*!< PWM_T::AINTEN: IFAIEN2 Position        */
#define PWM_AINTEN_IFAIEN2_Msk           (0x1ul << PWM_AINTEN_IFAIEN2_Pos)                 /*!< PWM_T::AINTEN: IFAIEN2 Mask            */

#define PWM_AINTEN_IFAIEN4_Pos           (4)                                               /*!< PWM_T::AINTEN: IFAIEN4 Position        */
#define PWM_AINTEN_IFAIEN4_Msk           (0x1ul << PWM_AINTEN_IFAIEN4_Pos)                 /*!< PWM_T::AINTEN: IFAIEN4 Mask            */

#define PWM_APDMACTL_APDMAEN0_Pos        (0)                                               /*!< PWM_T::APDMACTL: APDMAEN0 Position     */
#define PWM_APDMACTL_APDMAEN0_Msk        (0x1ul << PWM_APDMACTL_APDMAEN0_Pos)              /*!< PWM_T::APDMACTL: APDMAEN0 Mask         */

#define PWM_APDMACTL_APDMAEN1_Pos        (1)                                               /*!< PWM_T::APDMACTL: APDMAEN1 Position     */
#define PWM_APDMACTL_APDMAEN1_Msk        (0x1ul << PWM_APDMACTL_APDMAEN1_Pos)              /*!< PWM_T::APDMACTL: APDMAEN1 Mask         */

#define PWM_APDMACTL_APDMAEN2_Pos        (2)                                               /*!< PWM_T::APDMACTL: APDMAEN2 Position     */
#define PWM_APDMACTL_APDMAEN2_Msk        (0x1ul << PWM_APDMACTL_APDMAEN2_Pos)              /*!< PWM_T::APDMACTL: APDMAEN2 Mask         */

#define PWM_APDMACTL_APDMAEN3_Pos        (3)                                               /*!< PWM_T::APDMACTL: APDMAEN3 Position     */
#define PWM_APDMACTL_APDMAEN3_Msk        (0x1ul << PWM_APDMACTL_APDMAEN3_Pos)              /*!< PWM_T::APDMACTL: APDMAEN3 Mask         */

#define PWM_APDMACTL_APDMAEN4_Pos        (4)                                               /*!< PWM_T::APDMACTL: APDMAEN4 Position     */
#define PWM_APDMACTL_APDMAEN4_Msk        (0x1ul << PWM_APDMACTL_APDMAEN4_Pos)              /*!< PWM_T::APDMACTL: APDMAEN4 Mask         */

#define PWM_APDMACTL_APDMAEN5_Pos        (5)                                               /*!< PWM_T::APDMACTL: APDMAEN5 Position     */
#define PWM_APDMACTL_APDMAEN5_Msk        (0x1ul << PWM_APDMACTL_APDMAEN5_Pos)              /*!< PWM_T::APDMACTL: APDMAEN5 Mask         */

#define PWM_CAPINEN_CAPINEN0_Pos         (0)                                               /*!< PWM_T::CAPINEN: CAPINEN0 Position      */
#define PWM_CAPINEN_CAPINEN0_Msk         (0x1ul << PWM_CAPINEN_CAPINEN0_Pos)               /*!< PWM_T::CAPINEN: CAPINEN0 Mask          */

#define PWM_CAPINEN_CAPINEN1_Pos         (1)                                               /*!< PWM_T::CAPINEN: CAPINEN1 Position      */
#define PWM_CAPINEN_CAPINEN1_Msk         (0x1ul << PWM_CAPINEN_CAPINEN1_Pos)               /*!< PWM_T::CAPINEN: CAPINEN1 Mask          */

#define PWM_CAPINEN_CAPINEN2_Pos         (2)                                               /*!< PWM_T::CAPINEN: CAPINEN2 Position      */
#define PWM_CAPINEN_CAPINEN2_Msk         (0x1ul << PWM_CAPINEN_CAPINEN2_Pos)               /*!< PWM_T::CAPINEN: CAPINEN2 Mask          */

#define PWM_CAPINEN_CAPINEN3_Pos         (3)                                               /*!< PWM_T::CAPINEN: CAPINEN3 Position      */
#define PWM_CAPINEN_CAPINEN3_Msk         (0x1ul << PWM_CAPINEN_CAPINEN3_Pos)               /*!< PWM_T::CAPINEN: CAPINEN3 Mask          */

#define PWM_CAPINEN_CAPINEN4_Pos         (4)                                               /*!< PWM_T::CAPINEN: CAPINEN4 Position      */
#define PWM_CAPINEN_CAPINEN4_Msk         (0x1ul << PWM_CAPINEN_CAPINEN4_Pos)               /*!< PWM_T::CAPINEN: CAPINEN4 Mask          */

#define PWM_CAPINEN_CAPINEN5_Pos         (5)                                               /*!< PWM_T::CAPINEN: CAPINEN5 Position      */
#define PWM_CAPINEN_CAPINEN5_Msk         (0x1ul << PWM_CAPINEN_CAPINEN5_Pos)               /*!< PWM_T::CAPINEN: CAPINEN5 Mask          */

#define PWM_CAPCTL_CAPEN0_Pos            (0)                                               /*!< PWM_T::CAPCTL: CAPEN0 Position         */
#define PWM_CAPCTL_CAPEN0_Msk            (0x1ul << PWM_CAPCTL_CAPEN0_Pos)                  /*!< PWM_T::CAPCTL: CAPEN0 Mask             */

#define PWM_CAPCTL_CAPEN1_Pos            (1)                                               /*!< PWM_T::CAPCTL: CAPEN1 Position         */
#define PWM_CAPCTL_CAPEN1_Msk            (0x1ul << PWM_CAPCTL_CAPEN1_Pos)                  /*!< PWM_T::CAPCTL: CAPEN1 Mask             */

#define PWM_CAPCTL_CAPEN2_Pos            (2)                                               /*!< PWM_T::CAPCTL: CAPEN2 Position         */
#define PWM_CAPCTL_CAPEN2_Msk            (0x1ul << PWM_CAPCTL_CAPEN2_Pos)                  /*!< PWM_T::CAPCTL: CAPEN2 Mask             */

#define PWM_CAPCTL_CAPEN3_Pos            (3)                                               /*!< PWM_T::CAPCTL: CAPEN3 Position         */
#define PWM_CAPCTL_CAPEN3_Msk            (0x1ul << PWM_CAPCTL_CAPEN3_Pos)                  /*!< PWM_T::CAPCTL: CAPEN3 Mask             */

#define PWM_CAPCTL_CAPEN4_Pos            (4)                                               /*!< PWM_T::CAPCTL: CAPEN4 Position         */
#define PWM_CAPCTL_CAPEN4_Msk            (0x1ul << PWM_CAPCTL_CAPEN4_Pos)                  /*!< PWM_T::CAPCTL: CAPEN4 Mask             */

#define PWM_CAPCTL_CAPEN5_Pos            (5)                                               /*!< PWM_T::CAPCTL: CAPEN5 Position         */
#define PWM_CAPCTL_CAPEN5_Msk            (0x1ul << PWM_CAPCTL_CAPEN5_Pos)                  /*!< PWM_T::CAPCTL: CAPEN5 Mask             */

#define PWM_CAPCTL_CAPINV0_Pos           (8)                                               /*!< PWM_T::CAPCTL: CAPINV0 Position        */
#define PWM_CAPCTL_CAPINV0_Msk           (0x1ul << PWM_CAPCTL_CAPINV0_Pos)                 /*!< PWM_T::CAPCTL: CAPINV0 Mask            */

#define PWM_CAPCTL_CAPINV1_Pos           (9)                                               /*!< PWM_T::CAPCTL: CAPINV1 Position        */
#define PWM_CAPCTL_CAPINV1_Msk           (0x1ul << PWM_CAPCTL_CAPINV1_Pos)                 /*!< PWM_T::CAPCTL: CAPINV1 Mask            */

#define PWM_CAPCTL_CAPINV2_Pos           (10)                                              /*!< PWM_T::CAPCTL: CAPINV2 Position        */
#define PWM_CAPCTL_CAPINV2_Msk           (0x1ul << PWM_CAPCTL_CAPINV2_Pos)                 /*!< PWM_T::CAPCTL: CAPINV2 Mask            */

#define PWM_CAPCTL_CAPINV3_Pos           (11)                                              /*!< PWM_T::CAPCTL: CAPINV3 Position        */
#define PWM_CAPCTL_CAPINV3_Msk           (0x1ul << PWM_CAPCTL_CAPINV3_Pos)                 /*!< PWM_T::CAPCTL: CAPINV3 Mask            */

#define PWM_CAPCTL_CAPINV4_Pos           (12)                                              /*!< PWM_T::CAPCTL: CAPINV4 Position        */
#define PWM_CAPCTL_CAPINV4_Msk           (0x1ul << PWM_CAPCTL_CAPINV4_Pos)                 /*!< PWM_T::CAPCTL: CAPINV4 Mask            */

#define PWM_CAPCTL_CAPINV5_Pos           (13)                                              /*!< PWM_T::CAPCTL: CAPINV5 Position        */
#define PWM_CAPCTL_CAPINV5_Msk           (0x1ul << PWM_CAPCTL_CAPINV5_Pos)                 /*!< PWM_T::CAPCTL: CAPINV5 Mask            */

#define PWM_CAPCTL_RCRLDEN0_Pos          (16)                                              /*!< PWM_T::CAPCTL: RCRLDEN0 Position       */
#define PWM_CAPCTL_RCRLDEN0_Msk          (0x1ul << PWM_CAPCTL_RCRLDEN0_Pos)                /*!< PWM_T::CAPCTL: RCRLDEN0 Mask           */

#define PWM_CAPCTL_RCRLDEN1_Pos          (17)                                              /*!< PWM_T::CAPCTL: RCRLDEN1 Position       */
#define PWM_CAPCTL_RCRLDEN1_Msk          (0x1ul << PWM_CAPCTL_RCRLDEN1_Pos)                /*!< PWM_T::CAPCTL: RCRLDEN1 Mask           */

#define PWM_CAPCTL_RCRLDEN2_Pos          (18)                                              /*!< PWM_T::CAPCTL: RCRLDEN2 Position       */
#define PWM_CAPCTL_RCRLDEN2_Msk          (0x1ul << PWM_CAPCTL_RCRLDEN2_Pos)                /*!< PWM_T::CAPCTL: RCRLDEN2 Mask           */

#define PWM_CAPCTL_RCRLDEN3_Pos          (19)                                              /*!< PWM_T::CAPCTL: RCRLDEN3 Position       */
#define PWM_CAPCTL_RCRLDEN3_Msk          (0x1ul << PWM_CAPCTL_RCRLDEN3_Pos)                /*!< PWM_T::CAPCTL: RCRLDEN3 Mask           */

#define PWM_CAPCTL_RCRLDEN4_Pos          (20)                                              /*!< PWM_T::CAPCTL: RCRLDEN4 Position       */
#define PWM_CAPCTL_RCRLDEN4_Msk          (0x1ul << PWM_CAPCTL_RCRLDEN4_Pos)                /*!< PWM_T::CAPCTL: RCRLDEN4 Mask           */

#define PWM_CAPCTL_RCRLDEN5_Pos          (21)                                              /*!< PWM_T::CAPCTL: RCRLDEN5 Position       */
#define PWM_CAPCTL_RCRLDEN5_Msk          (0x1ul << PWM_CAPCTL_RCRLDEN5_Pos)                /*!< PWM_T::CAPCTL: RCRLDEN5 Mask           */

#define PWM_CAPCTL_FCRLDEN0_Pos          (24)                                              /*!< PWM_T::CAPCTL: FCRLDEN0 Position       */
#define PWM_CAPCTL_FCRLDEN0_Msk          (0x1ul << PWM_CAPCTL_FCRLDEN0_Pos)                /*!< PWM_T::CAPCTL: FCRLDEN0 Mask           */

#define PWM_CAPCTL_FCRLDEN1_Pos          (25)                                              /*!< PWM_T::CAPCTL: FCRLDEN1 Position       */
#define PWM_CAPCTL_FCRLDEN1_Msk          (0x1ul << PWM_CAPCTL_FCRLDEN1_Pos)                /*!< PWM_T::CAPCTL: FCRLDEN1 Mask           */

#define PWM_CAPCTL_FCRLDEN2_Pos          (26)                                              /*!< PWM_T::CAPCTL: FCRLDEN2 Position       */
#define PWM_CAPCTL_FCRLDEN2_Msk          (0x1ul << PWM_CAPCTL_FCRLDEN2_Pos)                /*!< PWM_T::CAPCTL: FCRLDEN2 Mask           */

#define PWM_CAPCTL_FCRLDEN3_Pos          (27)                                              /*!< PWM_T::CAPCTL: FCRLDEN3 Position       */
#define PWM_CAPCTL_FCRLDEN3_Msk          (0x1ul << PWM_CAPCTL_FCRLDEN3_Pos)                /*!< PWM_T::CAPCTL: FCRLDEN3 Mask           */

#define PWM_CAPCTL_FCRLDEN4_Pos          (28)                                              /*!< PWM_T::CAPCTL: FCRLDEN4 Position       */
#define PWM_CAPCTL_FCRLDEN4_Msk          (0x1ul << PWM_CAPCTL_FCRLDEN4_Pos)                /*!< PWM_T::CAPCTL: FCRLDEN4 Mask           */

#define PWM_CAPCTL_FCRLDEN5_Pos          (29)                                              /*!< PWM_T::CAPCTL: FCRLDEN5 Position       */
#define PWM_CAPCTL_FCRLDEN5_Msk          (0x1ul << PWM_CAPCTL_FCRLDEN5_Pos)                /*!< PWM_T::CAPCTL: FCRLDEN5 Mask           */

#define PWM_CAPSTS_CRLIFOV0_Pos          (0)                                               /*!< PWM_T::CAPSTS: CRLIFOV0 Position       */
#define PWM_CAPSTS_CRLIFOV0_Msk          (0x1ul << PWM_CAPSTS_CRLIFOV0_Pos)                /*!< PWM_T::CAPSTS: CRLIFOV0 Mask           */

#define PWM_CAPSTS_CRLIFOV1_Pos          (1)                                               /*!< PWM_T::CAPSTS: CRLIFOV1 Position       */
#define PWM_CAPSTS_CRLIFOV1_Msk          (0x1ul << PWM_CAPSTS_CRLIFOV1_Pos)                /*!< PWM_T::CAPSTS: CRLIFOV1 Mask           */

#define PWM_CAPSTS_CRLIFOV2_Pos          (2)                                               /*!< PWM_T::CAPSTS: CRLIFOV2 Position       */
#define PWM_CAPSTS_CRLIFOV2_Msk          (0x1ul << PWM_CAPSTS_CRLIFOV2_Pos)                /*!< PWM_T::CAPSTS: CRLIFOV2 Mask           */

#define PWM_CAPSTS_CRLIFOV3_Pos          (3)                                               /*!< PWM_T::CAPSTS: CRLIFOV3 Position       */
#define PWM_CAPSTS_CRLIFOV3_Msk          (0x1ul << PWM_CAPSTS_CRLIFOV3_Pos)                /*!< PWM_T::CAPSTS: CRLIFOV3 Mask           */

#define PWM_CAPSTS_CRLIFOV4_Pos          (4)                                               /*!< PWM_T::CAPSTS: CRLIFOV4 Position       */
#define PWM_CAPSTS_CRLIFOV4_Msk          (0x1ul << PWM_CAPSTS_CRLIFOV4_Pos)                /*!< PWM_T::CAPSTS: CRLIFOV4 Mask           */

#define PWM_CAPSTS_CRLIFOV5_Pos          (5)                                               /*!< PWM_T::CAPSTS: CRLIFOV5 Position       */
#define PWM_CAPSTS_CRLIFOV5_Msk          (0x1ul << PWM_CAPSTS_CRLIFOV5_Pos)                /*!< PWM_T::CAPSTS: CRLIFOV5 Mask           */

#define PWM_CAPSTS_CFLIFOV0_Pos          (8)                                               /*!< PWM_T::CAPSTS: CFLIFOV0 Position       */
#define PWM_CAPSTS_CFLIFOV0_Msk          (0x1ul << PWM_CAPSTS_CFLIFOV0_Pos)                /*!< PWM_T::CAPSTS: CFLIFOV0 Mask           */

#define PWM_CAPSTS_CFLIFOV1_Pos          (9)                                               /*!< PWM_T::CAPSTS: CFLIFOV1 Position       */
#define PWM_CAPSTS_CFLIFOV1_Msk          (0x1ul << PWM_CAPSTS_CFLIFOV1_Pos)                /*!< PWM_T::CAPSTS: CFLIFOV1 Mask           */

#define PWM_CAPSTS_CFLIFOV2_Pos          (10)                                              /*!< PWM_T::CAPSTS: CFLIFOV2 Position       */
#define PWM_CAPSTS_CFLIFOV2_Msk          (0x1ul << PWM_CAPSTS_CFLIFOV2_Pos)                /*!< PWM_T::CAPSTS: CFLIFOV2 Mask           */

#define PWM_CAPSTS_CFLIFOV3_Pos          (11)                                              /*!< PWM_T::CAPSTS: CFLIFOV3 Position       */
#define PWM_CAPSTS_CFLIFOV3_Msk          (0x1ul << PWM_CAPSTS_CFLIFOV3_Pos)                /*!< PWM_T::CAPSTS: CFLIFOV3 Mask           */

#define PWM_CAPSTS_CFLIFOV4_Pos          (12)                                              /*!< PWM_T::CAPSTS: CFLIFOV4 Position       */
#define PWM_CAPSTS_CFLIFOV4_Msk          (0x1ul << PWM_CAPSTS_CFLIFOV4_Pos)                /*!< PWM_T::CAPSTS: CFLIFOV4 Mask           */

#define PWM_CAPSTS_CFLIFOV5_Pos          (13)                                              /*!< PWM_T::CAPSTS: CFLIFOV5 Position       */
#define PWM_CAPSTS_CFLIFOV5_Msk          (0x1ul << PWM_CAPSTS_CFLIFOV5_Pos)                /*!< PWM_T::CAPSTS: CFLIFOV5 Mask           */

#define PWM_RCAPDAT0_RCAPDAT_Pos         (0)                                               /*!< PWM_T::RCAPDAT0: RCAPDAT Position      */
#define PWM_RCAPDAT0_RCAPDAT_Msk         (0xfffful << PWM_RCAPDAT0_RCAPDAT_Pos)            /*!< PWM_T::RCAPDAT0: RCAPDAT Mask          */

#define PWM_FCAPDAT0_FCAPDAT_Pos         (0)                                               /*!< PWM_T::FCAPDAT0: FCAPDAT Position      */
#define PWM_FCAPDAT0_FCAPDAT_Msk         (0xfffful << PWM_FCAPDAT0_FCAPDAT_Pos)            /*!< PWM_T::FCAPDAT0: FCAPDAT Mask          */

#define PWM_RCAPDAT1_RCAPDAT_Pos         (0)                                               /*!< PWM_T::RCAPDAT1: RCAPDAT Position      */
#define PWM_RCAPDAT1_RCAPDAT_Msk         (0xfffful << PWM_RCAPDAT1_RCAPDAT_Pos)            /*!< PWM_T::RCAPDAT1: RCAPDAT Mask          */

#define PWM_FCAPDAT1_FCAPDAT_Pos         (0)                                               /*!< PWM_T::FCAPDAT1: FCAPDAT Position      */
#define PWM_FCAPDAT1_FCAPDAT_Msk         (0xfffful << PWM_FCAPDAT1_FCAPDAT_Pos)            /*!< PWM_T::FCAPDAT1: FCAPDAT Mask          */

#define PWM_RCAPDAT2_RCAPDAT_Pos         (0)                                               /*!< PWM_T::RCAPDAT2: RCAPDAT Position      */
#define PWM_RCAPDAT2_RCAPDAT_Msk         (0xfffful << PWM_RCAPDAT2_RCAPDAT_Pos)            /*!< PWM_T::RCAPDAT2: RCAPDAT Mask          */

#define PWM_FCAPDAT2_FCAPDAT_Pos         (0)                                               /*!< PWM_T::FCAPDAT2: FCAPDAT Position      */
#define PWM_FCAPDAT2_FCAPDAT_Msk         (0xfffful << PWM_FCAPDAT2_FCAPDAT_Pos)            /*!< PWM_T::FCAPDAT2: FCAPDAT Mask          */

#define PWM_RCAPDAT3_RCAPDAT_Pos         (0)                                               /*!< PWM_T::RCAPDAT3: RCAPDAT Position      */
#define PWM_RCAPDAT3_RCAPDAT_Msk         (0xfffful << PWM_RCAPDAT3_RCAPDAT_Pos)            /*!< PWM_T::RCAPDAT3: RCAPDAT Mask          */

#define PWM_FCAPDAT3_FCAPDAT_Pos         (0)                                               /*!< PWM_T::FCAPDAT3: FCAPDAT Position      */
#define PWM_FCAPDAT3_FCAPDAT_Msk         (0xfffful << PWM_FCAPDAT3_FCAPDAT_Pos)            /*!< PWM_T::FCAPDAT3: FCAPDAT Mask          */

#define PWM_RCAPDAT4_RCAPDAT_Pos         (0)                                               /*!< PWM_T::RCAPDAT4: RCAPDAT Position      */
#define PWM_RCAPDAT4_RCAPDAT_Msk         (0xfffful << PWM_RCAPDAT4_RCAPDAT_Pos)            /*!< PWM_T::RCAPDAT4: RCAPDAT Mask          */

#define PWM_FCAPDAT4_FCAPDAT_Pos         (0)                                               /*!< PWM_T::FCAPDAT4: FCAPDAT Position      */
#define PWM_FCAPDAT4_FCAPDAT_Msk         (0xfffful << PWM_FCAPDAT4_FCAPDAT_Pos)            /*!< PWM_T::FCAPDAT4: FCAPDAT Mask          */

#define PWM_RCAPDAT5_RCAPDAT_Pos         (0)                                               /*!< PWM_T::RCAPDAT5: RCAPDAT Position      */
#define PWM_RCAPDAT5_RCAPDAT_Msk         (0xfffful << PWM_RCAPDAT5_RCAPDAT_Pos)            /*!< PWM_T::RCAPDAT5: RCAPDAT Mask          */

#define PWM_FCAPDAT5_FCAPDAT_Pos         (0)                                               /*!< PWM_T::FCAPDAT5: FCAPDAT Position      */
#define PWM_FCAPDAT5_FCAPDAT_Msk         (0xfffful << PWM_FCAPDAT5_FCAPDAT_Pos)            /*!< PWM_T::FCAPDAT5: FCAPDAT Mask          */

#define PWM_PDMACTL_CHEN0_1_Pos          (0)                                               /*!< PWM_T::PDMACTL: CHEN0_1 Position       */
#define PWM_PDMACTL_CHEN0_1_Msk          (0x1ul << PWM_PDMACTL_CHEN0_1_Pos)                /*!< PWM_T::PDMACTL: CHEN0_1 Mask           */

#define PWM_PDMACTL_CAPMOD0_1_Pos        (1)                                               /*!< PWM_T::PDMACTL: CAPMOD0_1 Position     */
#define PWM_PDMACTL_CAPMOD0_1_Msk        (0x3ul << PWM_PDMACTL_CAPMOD0_1_Pos)              /*!< PWM_T::PDMACTL: CAPMOD0_1 Mask         */

#define PWM_PDMACTL_CAPORD0_1_Pos        (3)                                               /*!< PWM_T::PDMACTL: CAPORD0_1 Position     */
#define PWM_PDMACTL_CAPORD0_1_Msk        (0x1ul << PWM_PDMACTL_CAPORD0_1_Pos)              /*!< PWM_T::PDMACTL: CAPORD0_1 Mask         */

#define PWM_PDMACTL_CHSEL0_1_Pos         (4)                                               /*!< PWM_T::PDMACTL: CHSEL0_1 Position      */
#define PWM_PDMACTL_CHSEL0_1_Msk         (0x1ul << PWM_PDMACTL_CHSEL0_1_Pos)               /*!< PWM_T::PDMACTL: CHSEL0_1 Mask          */

#define PWM_PDMACTL_CHEN2_3_Pos          (8)                                               /*!< PWM_T::PDMACTL: CHEN2_3 Position       */
#define PWM_PDMACTL_CHEN2_3_Msk          (0x1ul << PWM_PDMACTL_CHEN2_3_Pos)                /*!< PWM_T::PDMACTL: CHEN2_3 Mask           */

#define PWM_PDMACTL_CAPMOD2_3_Pos        (9)                                               /*!< PWM_T::PDMACTL: CAPMOD2_3 Position     */
#define PWM_PDMACTL_CAPMOD2_3_Msk        (0x3ul << PWM_PDMACTL_CAPMOD2_3_Pos)              /*!< PWM_T::PDMACTL: CAPMOD2_3 Mask         */

#define PWM_PDMACTL_CAPORD2_3_Pos        (11)                                              /*!< PWM_T::PDMACTL: CAPORD2_3 Position     */
#define PWM_PDMACTL_CAPORD2_3_Msk        (0x1ul << PWM_PDMACTL_CAPORD2_3_Pos)              /*!< PWM_T::PDMACTL: CAPORD2_3 Mask         */

#define PWM_PDMACTL_CHSEL2_3_Pos         (12)                                              /*!< PWM_T::PDMACTL: CHSEL2_3 Position      */
#define PWM_PDMACTL_CHSEL2_3_Msk         (0x1ul << PWM_PDMACTL_CHSEL2_3_Pos)               /*!< PWM_T::PDMACTL: CHSEL2_3 Mask          */

#define PWM_PDMACTL_CHEN4_5_Pos          (16)                                              /*!< PWM_T::PDMACTL: CHEN4_5 Position       */
#define PWM_PDMACTL_CHEN4_5_Msk          (0x1ul << PWM_PDMACTL_CHEN4_5_Pos)                /*!< PWM_T::PDMACTL: CHEN4_5 Mask           */

#define PWM_PDMACTL_CAPMOD4_5_Pos        (17)                                              /*!< PWM_T::PDMACTL: CAPMOD4_5 Position     */
#define PWM_PDMACTL_CAPMOD4_5_Msk        (0x3ul << PWM_PDMACTL_CAPMOD4_5_Pos)              /*!< PWM_T::PDMACTL: CAPMOD4_5 Mask         */

#define PWM_PDMACTL_CAPORD4_5_Pos        (19)                                              /*!< PWM_T::PDMACTL: CAPORD4_5 Position     */
#define PWM_PDMACTL_CAPORD4_5_Msk        (0x1ul << PWM_PDMACTL_CAPORD4_5_Pos)              /*!< PWM_T::PDMACTL: CAPORD4_5 Mask         */

#define PWM_PDMACTL_CHSEL4_5_Pos         (20)                                              /*!< PWM_T::PDMACTL: CHSEL4_5 Position      */
#define PWM_PDMACTL_CHSEL4_5_Msk         (0x1ul << PWM_PDMACTL_CHSEL4_5_Pos)               /*!< PWM_T::PDMACTL: CHSEL4_5 Mask          */

#define PWM_PDMACAP0_1_CAPBUF_Pos        (0)                                               /*!< PWM_T::PDMACAP0_1: CAPBUF Position     */
#define PWM_PDMACAP0_1_CAPBUF_Msk        (0xfffful << PWM_PDMACAP0_1_CAPBUF_Pos)           /*!< PWM_T::PDMACAP0_1: CAPBUF Mask         */

#define PWM_PDMACAP2_3_CAPBUF_Pos        (0)                                               /*!< PWM_T::PDMACAP2_3: CAPBUF Position     */
#define PWM_PDMACAP2_3_CAPBUF_Msk        (0xfffful << PWM_PDMACAP2_3_CAPBUF_Pos)           /*!< PWM_T::PDMACAP2_3: CAPBUF Mask         */

#define PWM_PDMACAP4_5_CAPBUF_Pos        (0)                                               /*!< PWM_T::PDMACAP4_5: CAPBUF Position     */
#define PWM_PDMACAP4_5_CAPBUF_Msk        (0xfffful << PWM_PDMACAP4_5_CAPBUF_Pos)           /*!< PWM_T::PDMACAP4_5: CAPBUF Mask         */

#define PWM_CAPIEN_CAPRIEN0_Pos          (0)                                               /*!< PWM_T::CAPIEN: CAPRIEN0 Position       */
#define PWM_CAPIEN_CAPRIEN0_Msk          (0x1ul << PWM_CAPIEN_CAPRIEN0_Pos)                /*!< PWM_T::CAPIEN: CAPRIEN0 Mask           */

#define PWM_CAPIEN_CAPRIEN1_Pos          (1)                                               /*!< PWM_T::CAPIEN: CAPRIEN1 Position       */
#define PWM_CAPIEN_CAPRIEN1_Msk          (0x1ul << PWM_CAPIEN_CAPRIEN1_Pos)                /*!< PWM_T::CAPIEN: CAPRIEN1 Mask           */

#define PWM_CAPIEN_CAPRIEN2_Pos          (2)                                               /*!< PWM_T::CAPIEN: CAPRIEN2 Position       */
#define PWM_CAPIEN_CAPRIEN2_Msk          (0x1ul << PWM_CAPIEN_CAPRIEN2_Pos)                /*!< PWM_T::CAPIEN: CAPRIEN2 Mask           */

#define PWM_CAPIEN_CAPRIEN3_Pos          (3)                                               /*!< PWM_T::CAPIEN: CAPRIEN3 Position       */
#define PWM_CAPIEN_CAPRIEN3_Msk          (0x1ul << PWM_CAPIEN_CAPRIEN3_Pos)                /*!< PWM_T::CAPIEN: CAPRIEN3 Mask           */

#define PWM_CAPIEN_CAPRIEN4_Pos          (4)                                               /*!< PWM_T::CAPIEN: CAPRIEN4 Position       */
#define PWM_CAPIEN_CAPRIEN4_Msk          (0x1ul << PWM_CAPIEN_CAPRIEN4_Pos)                /*!< PWM_T::CAPIEN: CAPRIEN4 Mask           */

#define PWM_CAPIEN_CAPRIEN5_Pos          (5)                                               /*!< PWM_T::CAPIEN: CAPRIEN5 Position       */
#define PWM_CAPIEN_CAPRIEN5_Msk          (0x1ul << PWM_CAPIEN_CAPRIEN5_Pos)                /*!< PWM_T::CAPIEN: CAPRIEN5 Mask           */

#define PWM_CAPIEN_CAPFIEN0_Pos          (8)                                               /*!< PWM_T::CAPIEN: CAPFIEN0 Position       */
#define PWM_CAPIEN_CAPFIEN0_Msk          (0x1ul << PWM_CAPIEN_CAPFIEN0_Pos)                /*!< PWM_T::CAPIEN: CAPFIEN0 Mask           */

#define PWM_CAPIEN_CAPFIEN1_Pos          (9)                                               /*!< PWM_T::CAPIEN: CAPFIEN1 Position       */
#define PWM_CAPIEN_CAPFIEN1_Msk          (0x1ul << PWM_CAPIEN_CAPFIEN1_Pos)                /*!< PWM_T::CAPIEN: CAPFIEN1 Mask           */

#define PWM_CAPIEN_CAPFIEN2_Pos          (10)                                              /*!< PWM_T::CAPIEN: CAPFIEN2 Position       */
#define PWM_CAPIEN_CAPFIEN2_Msk          (0x1ul << PWM_CAPIEN_CAPFIEN2_Pos)                /*!< PWM_T::CAPIEN: CAPFIEN2 Mask           */

#define PWM_CAPIEN_CAPFIEN3_Pos          (11)                                              /*!< PWM_T::CAPIEN: CAPFIEN3 Position       */
#define PWM_CAPIEN_CAPFIEN3_Msk          (0x1ul << PWM_CAPIEN_CAPFIEN3_Pos)                /*!< PWM_T::CAPIEN: CAPFIEN3 Mask           */

#define PWM_CAPIEN_CAPFIEN4_Pos          (12)                                              /*!< PWM_T::CAPIEN: CAPFIEN4 Position       */
#define PWM_CAPIEN_CAPFIEN4_Msk          (0x1ul << PWM_CAPIEN_CAPFIEN4_Pos)                /*!< PWM_T::CAPIEN: CAPFIEN4 Mask           */

#define PWM_CAPIEN_CAPFIEN5_Pos          (13)                                              /*!< PWM_T::CAPIEN: CAPFIEN5 Position       */
#define PWM_CAPIEN_CAPFIEN5_Msk          (0x1ul << PWM_CAPIEN_CAPFIEN5_Pos)                /*!< PWM_T::CAPIEN: CAPFIEN5 Mask           */

#define PWM_CAPIF_CRLIF0_Pos             (0)                                               /*!< PWM_T::CAPIF: CRLIF0 Position          */
#define PWM_CAPIF_CRLIF0_Msk             (0x1ul << PWM_CAPIF_CRLIF0_Pos)                   /*!< PWM_T::CAPIF: CRLIF0 Mask              */

#define PWM_CAPIF_CRLIF1_Pos             (1)                                               /*!< PWM_T::CAPIF: CRLIF1 Position          */
#define PWM_CAPIF_CRLIF1_Msk             (0x1ul << PWM_CAPIF_CRLIF1_Pos)                   /*!< PWM_T::CAPIF: CRLIF1 Mask              */

#define PWM_CAPIF_CRLIF2_Pos             (2)                                               /*!< PWM_T::CAPIF: CRLIF2 Position          */
#define PWM_CAPIF_CRLIF2_Msk             (0x1ul << PWM_CAPIF_CRLIF2_Pos)                   /*!< PWM_T::CAPIF: CRLIF2 Mask              */

#define PWM_CAPIF_CRLIF3_Pos             (3)                                               /*!< PWM_T::CAPIF: CRLIF3 Position          */
#define PWM_CAPIF_CRLIF3_Msk             (0x1ul << PWM_CAPIF_CRLIF3_Pos)                   /*!< PWM_T::CAPIF: CRLIF3 Mask              */

#define PWM_CAPIF_CRLIF4_Pos             (4)                                               /*!< PWM_T::CAPIF: CRLIF4 Position          */
#define PWM_CAPIF_CRLIF4_Msk             (0x1ul << PWM_CAPIF_CRLIF4_Pos)                   /*!< PWM_T::CAPIF: CRLIF4 Mask              */

#define PWM_CAPIF_CRLIF5_Pos             (5)                                               /*!< PWM_T::CAPIF: CRLIF5 Position          */
#define PWM_CAPIF_CRLIF5_Msk             (0x1ul << PWM_CAPIF_CRLIF5_Pos)                   /*!< PWM_T::CAPIF: CRLIF5 Mask              */

#define PWM_CAPIF_CFLIF0_Pos             (8)                                               /*!< PWM_T::CAPIF: CFLIF0 Position          */
#define PWM_CAPIF_CFLIF0_Msk             (0x1ul << PWM_CAPIF_CFLIF0_Pos)                   /*!< PWM_T::CAPIF: CFLIF0 Mask              */

#define PWM_CAPIF_CFLIF1_Pos             (9)                                               /*!< PWM_T::CAPIF: CFLIF1 Position          */
#define PWM_CAPIF_CFLIF1_Msk             (0x1ul << PWM_CAPIF_CFLIF1_Pos)                   /*!< PWM_T::CAPIF: CFLIF1 Mask              */

#define PWM_CAPIF_CFLIF2_Pos             (10)                                              /*!< PWM_T::CAPIF: CFLIF2 Position          */
#define PWM_CAPIF_CFLIF2_Msk             (0x1ul << PWM_CAPIF_CFLIF2_Pos)                   /*!< PWM_T::CAPIF: CFLIF2 Mask              */

#define PWM_CAPIF_CFLIF3_Pos             (11)                                              /*!< PWM_T::CAPIF: CFLIF3 Position          */
#define PWM_CAPIF_CFLIF3_Msk             (0x1ul << PWM_CAPIF_CFLIF3_Pos)                   /*!< PWM_T::CAPIF: CFLIF3 Mask              */

#define PWM_CAPIF_CFLIF4_Pos             (12)                                              /*!< PWM_T::CAPIF: CFLIF4 Position          */
#define PWM_CAPIF_CFLIF4_Msk             (0x1ul << PWM_CAPIF_CFLIF4_Pos)                   /*!< PWM_T::CAPIF: CFLIF4 Mask              */

#define PWM_CAPIF_CFLIF5_Pos             (13)                                              /*!< PWM_T::CAPIF: CFLIF5 Position          */
#define PWM_CAPIF_CFLIF5_Msk             (0x1ul << PWM_CAPIF_CFLIF5_Pos)                   /*!< PWM_T::CAPIF: CFLIF5 Mask              */

#define PWM_CAPNF0_CAPNFEN_Pos           (0)                                               /*!< PWM_T::CAPNF0: CAPNFEN Position        */
#define PWM_CAPNF0_CAPNFEN_Msk           (0x1ul << PWM_CAPNF0_CAPNFEN_Pos)                 /*!< PWM_T::CAPNF0: CAPNFEN Mask            */

#define PWM_CAPNF0_CAPNFSEL_Pos          (4)                                               /*!< PWM_T::CAPNF0: CAPNFSEL Position       */
#define PWM_CAPNF0_CAPNFSEL_Msk          (0x7ul << PWM_CAPNF0_CAPNFSEL_Pos)                /*!< PWM_T::CAPNF0: CAPNFSEL Mask           */

#define PWM_CAPNF0_CAPNFCNT_Pos          (8)                                               /*!< PWM_T::CAPNF0: CAPNFCNT Position       */
#define PWM_CAPNF0_CAPNFCNT_Msk          (0x7ul << PWM_CAPNF0_CAPNFCNT_Pos)                /*!< PWM_T::CAPNF0: CAPNFCNT Mask           */

#define PWM_CAPNF1_CAPNFEN_Pos           (0)                                               /*!< PWM_T::CAPNF1: CAPNFEN Position        */
#define PWM_CAPNF1_CAPNFEN_Msk           (0x1ul << PWM_CAPNF1_CAPNFEN_Pos)                 /*!< PWM_T::CAPNF1: CAPNFEN Mask            */

#define PWM_CAPNF1_CAPNFSEL_Pos          (4)                                               /*!< PWM_T::CAPNF1: CAPNFSEL Position       */
#define PWM_CAPNF1_CAPNFSEL_Msk          (0x7ul << PWM_CAPNF1_CAPNFSEL_Pos)                /*!< PWM_T::CAPNF1: CAPNFSEL Mask           */

#define PWM_CAPNF1_CAPNFCNT_Pos          (8)                                               /*!< PWM_T::CAPNF1: CAPNFCNT Position       */
#define PWM_CAPNF1_CAPNFCNT_Msk          (0x7ul << PWM_CAPNF1_CAPNFCNT_Pos)                /*!< PWM_T::CAPNF1: CAPNFCNT Mask           */

#define PWM_CAPNF2_CAPNFEN_Pos           (0)                                               /*!< PWM_T::CAPNF2: CAPNFEN Position        */
#define PWM_CAPNF2_CAPNFEN_Msk           (0x1ul << PWM_CAPNF2_CAPNFEN_Pos)                 /*!< PWM_T::CAPNF2: CAPNFEN Mask            */

#define PWM_CAPNF2_CAPNFSEL_Pos          (4)                                               /*!< PWM_T::CAPNF2: CAPNFSEL Position       */
#define PWM_CAPNF2_CAPNFSEL_Msk          (0x7ul << PWM_CAPNF2_CAPNFSEL_Pos)                /*!< PWM_T::CAPNF2: CAPNFSEL Mask           */

#define PWM_CAPNF2_CAPNFCNT_Pos          (8)                                               /*!< PWM_T::CAPNF2: CAPNFCNT Position       */
#define PWM_CAPNF2_CAPNFCNT_Msk          (0x7ul << PWM_CAPNF2_CAPNFCNT_Pos)                /*!< PWM_T::CAPNF2: CAPNFCNT Mask           */

#define PWM_CAPNF3_CAPNFEN_Pos           (0)                                               /*!< PWM_T::CAPNF3: CAPNFEN Position        */
#define PWM_CAPNF3_CAPNFEN_Msk           (0x1ul << PWM_CAPNF3_CAPNFEN_Pos)                 /*!< PWM_T::CAPNF3: CAPNFEN Mask            */

#define PWM_CAPNF3_CAPNFSEL_Pos          (4)                                               /*!< PWM_T::CAPNF3: CAPNFSEL Position       */
#define PWM_CAPNF3_CAPNFSEL_Msk          (0x7ul << PWM_CAPNF3_CAPNFSEL_Pos)                /*!< PWM_T::CAPNF3: CAPNFSEL Mask           */

#define PWM_CAPNF3_CAPNFCNT_Pos          (8)                                               /*!< PWM_T::CAPNF3: CAPNFCNT Position       */
#define PWM_CAPNF3_CAPNFCNT_Msk          (0x7ul << PWM_CAPNF3_CAPNFCNT_Pos)                /*!< PWM_T::CAPNF3: CAPNFCNT Mask           */

#define PWM_CAPNF4_CAPNFEN_Pos           (0)                                               /*!< PWM_T::CAPNF4: CAPNFEN Position        */
#define PWM_CAPNF4_CAPNFEN_Msk           (0x1ul << PWM_CAPNF4_CAPNFEN_Pos)                 /*!< PWM_T::CAPNF4: CAPNFEN Mask            */

#define PWM_CAPNF4_CAPNFSEL_Pos          (4)                                               /*!< PWM_T::CAPNF4: CAPNFSEL Position       */
#define PWM_CAPNF4_CAPNFSEL_Msk          (0x7ul << PWM_CAPNF4_CAPNFSEL_Pos)                /*!< PWM_T::CAPNF4: CAPNFSEL Mask           */

#define PWM_CAPNF4_CAPNFCNT_Pos          (8)                                               /*!< PWM_T::CAPNF4: CAPNFCNT Position       */
#define PWM_CAPNF4_CAPNFCNT_Msk          (0x7ul << PWM_CAPNF4_CAPNFCNT_Pos)                /*!< PWM_T::CAPNF4: CAPNFCNT Mask           */

#define PWM_CAPNF5_CAPNFEN_Pos           (0)                                               /*!< PWM_T::CAPNF5: CAPNFEN Position        */
#define PWM_CAPNF5_CAPNFEN_Msk           (0x1ul << PWM_CAPNF5_CAPNFEN_Pos)                 /*!< PWM_T::CAPNF5: CAPNFEN Mask            */

#define PWM_CAPNF5_CAPNFSEL_Pos          (4)                                               /*!< PWM_T::CAPNF5: CAPNFSEL Position       */
#define PWM_CAPNF5_CAPNFSEL_Msk          (0x7ul << PWM_CAPNF5_CAPNFSEL_Pos)                /*!< PWM_T::CAPNF5: CAPNFSEL Mask           */

#define PWM_CAPNF5_CAPNFCNT_Pos          (8)                                               /*!< PWM_T::CAPNF5: CAPNFCNT Position       */
#define PWM_CAPNF5_CAPNFCNT_Msk          (0x7ul << PWM_CAPNF5_CAPNFCNT_Pos)                /*!< PWM_T::CAPNF5: CAPNFCNT Mask           */

#define PWM_EXTETCTL0_EXTETEN_Pos        (0)                                               /*!< PWM_T::EXTETCTL0: EXTETEN Position     */
#define PWM_EXTETCTL0_EXTETEN_Msk        (0x1ul << PWM_EXTETCTL0_EXTETEN_Pos)              /*!< PWM_T::EXTETCTL0: EXTETEN Mask         */

#define PWM_EXTETCTL0_CNTACTS_Pos        (4)                                               /*!< PWM_T::EXTETCTL0: CNTACTS Position     */
#define PWM_EXTETCTL0_CNTACTS_Msk        (0x3ul << PWM_EXTETCTL0_CNTACTS_Pos)              /*!< PWM_T::EXTETCTL0: CNTACTS Mask         */

#define PWM_EXTETCTL0_EXTTRGS_Pos        (8)                                               /*!< PWM_T::EXTETCTL0: EXTTRGS Position     */
#define PWM_EXTETCTL0_EXTTRGS_Msk        (0xful << PWM_EXTETCTL0_EXTTRGS_Pos)              /*!< PWM_T::EXTETCTL0: EXTTRGS Mask         */

#define PWM_EXTETCTL2_EXTETEN_Pos        (0)                                               /*!< PWM_T::EXTETCTL2: EXTETEN Position     */
#define PWM_EXTETCTL2_EXTETEN_Msk        (0x1ul << PWM_EXTETCTL2_EXTETEN_Pos)              /*!< PWM_T::EXTETCTL2: EXTETEN Mask         */

#define PWM_EXTETCTL2_CNTACTS_Pos        (4)                                               /*!< PWM_T::EXTETCTL2: CNTACTS Position     */
#define PWM_EXTETCTL2_CNTACTS_Msk        (0x3ul << PWM_EXTETCTL2_CNTACTS_Pos)              /*!< PWM_T::EXTETCTL2: CNTACTS Mask         */

#define PWM_EXTETCTL2_EXTTRGS_Pos        (8)                                               /*!< PWM_T::EXTETCTL2: EXTTRGS Position     */
#define PWM_EXTETCTL2_EXTTRGS_Msk        (0xful << PWM_EXTETCTL2_EXTTRGS_Pos)              /*!< PWM_T::EXTETCTL2: EXTTRGS Mask         */

#define PWM_EXTETCTL4_EXTETEN_Pos        (0)                                               /*!< PWM_T::EXTETCTL4: EXTETEN Position     */
#define PWM_EXTETCTL4_EXTETEN_Msk        (0x1ul << PWM_EXTETCTL4_EXTETEN_Pos)              /*!< PWM_T::EXTETCTL4: EXTETEN Mask         */

#define PWM_EXTETCTL4_CNTACTS_Pos        (4)                                               /*!< PWM_T::EXTETCTL4: CNTACTS Position     */
#define PWM_EXTETCTL4_CNTACTS_Msk        (0x3ul << PWM_EXTETCTL4_CNTACTS_Pos)              /*!< PWM_T::EXTETCTL4: CNTACTS Mask         */

#define PWM_EXTETCTL4_EXTTRGS_Pos        (8)                                               /*!< PWM_T::EXTETCTL4: EXTTRGS Position     */
#define PWM_EXTETCTL4_EXTTRGS_Msk        (0xful << PWM_EXTETCTL4_EXTTRGS_Pos)              /*!< PWM_T::EXTETCTL4: EXTTRGS Mask         */

#define PWM_SWEOFCTL_OUTACTS0_Pos        (0)                                               /*!< PWM_T::SWEOFCTL: OUTACTS0 Position     */
#define PWM_SWEOFCTL_OUTACTS0_Msk        (0x3ul << PWM_SWEOFCTL_OUTACTS0_Pos)              /*!< PWM_T::SWEOFCTL: OUTACTS0 Mask         */

#define PWM_SWEOFCTL_OUTACTS1_Pos        (2)                                               /*!< PWM_T::SWEOFCTL: OUTACTS1 Position     */
#define PWM_SWEOFCTL_OUTACTS1_Msk        (0x3ul << PWM_SWEOFCTL_OUTACTS1_Pos)              /*!< PWM_T::SWEOFCTL: OUTACTS1 Mask         */

#define PWM_SWEOFCTL_OUTACTS2_Pos        (4)                                               /*!< PWM_T::SWEOFCTL: OUTACTS2 Position     */
#define PWM_SWEOFCTL_OUTACTS2_Msk        (0x3ul << PWM_SWEOFCTL_OUTACTS2_Pos)              /*!< PWM_T::SWEOFCTL: OUTACTS2 Mask         */

#define PWM_SWEOFCTL_OUTACTS3_Pos        (6)                                               /*!< PWM_T::SWEOFCTL: OUTACTS3 Position     */
#define PWM_SWEOFCTL_OUTACTS3_Msk        (0x3ul << PWM_SWEOFCTL_OUTACTS3_Pos)              /*!< PWM_T::SWEOFCTL: OUTACTS3 Mask         */

#define PWM_SWEOFCTL_OUTACTS4_Pos        (8)                                               /*!< PWM_T::SWEOFCTL: OUTACTS4 Position     */
#define PWM_SWEOFCTL_OUTACTS4_Msk        (0x3ul << PWM_SWEOFCTL_OUTACTS4_Pos)              /*!< PWM_T::SWEOFCTL: OUTACTS4 Mask         */

#define PWM_SWEOFCTL_OUTACTS5_Pos        (10)                                              /*!< PWM_T::SWEOFCTL: OUTACTS5 Position     */
#define PWM_SWEOFCTL_OUTACTS5_Msk        (0x3ul << PWM_SWEOFCTL_OUTACTS5_Pos)              /*!< PWM_T::SWEOFCTL: OUTACTS5 Mask         */

#define PWM_SWEOFTRG_SWETRG0_Pos         (0)                                               /*!< PWM_T::SWEOFTRG: SWETRG0 Position      */
#define PWM_SWEOFTRG_SWETRG0_Msk         (0x1ul << PWM_SWEOFTRG_SWETRG0_Pos)               /*!< PWM_T::SWEOFTRG: SWETRG0 Mask          */

#define PWM_SWEOFTRG_SWETRG1_Pos         (1)                                               /*!< PWM_T::SWEOFTRG: SWETRG1 Position      */
#define PWM_SWEOFTRG_SWETRG1_Msk         (0x1ul << PWM_SWEOFTRG_SWETRG1_Pos)               /*!< PWM_T::SWEOFTRG: SWETRG1 Mask          */

#define PWM_SWEOFTRG_SWETRG2_Pos         (2)                                               /*!< PWM_T::SWEOFTRG: SWETRG2 Position      */
#define PWM_SWEOFTRG_SWETRG2_Msk         (0x1ul << PWM_SWEOFTRG_SWETRG2_Pos)               /*!< PWM_T::SWEOFTRG: SWETRG2 Mask          */

#define PWM_SWEOFTRG_SWETRG3_Pos         (3)                                               /*!< PWM_T::SWEOFTRG: SWETRG3 Position      */
#define PWM_SWEOFTRG_SWETRG3_Msk         (0x1ul << PWM_SWEOFTRG_SWETRG3_Pos)               /*!< PWM_T::SWEOFTRG: SWETRG3 Mask          */

#define PWM_SWEOFTRG_SWETRG4_Pos         (4)                                               /*!< PWM_T::SWEOFTRG: SWETRG4 Position      */
#define PWM_SWEOFTRG_SWETRG4_Msk         (0x1ul << PWM_SWEOFTRG_SWETRG4_Pos)               /*!< PWM_T::SWEOFTRG: SWETRG4 Mask          */

#define PWM_SWEOFTRG_SWETRG5_Pos         (5)                                               /*!< PWM_T::SWEOFTRG: SWETRG5 Position      */
#define PWM_SWEOFTRG_SWETRG5_Msk         (0x1ul << PWM_SWEOFTRG_SWETRG5_Pos)               /*!< PWM_T::SWEOFTRG: SWETRG5 Mask          */

#define PWM_PBUF0_PBUF_Pos               (0)                                               /*!< PWM_T::PBUF0: PBUF Position            */
#define PWM_PBUF0_PBUF_Msk               (0xfffful << PWM_PBUF0_PBUF_Pos)                  /*!< PWM_T::PBUF0: PBUF Mask                */

#define PWM_PBUF2_PBUF_Pos               (0)                                               /*!< PWM_T::PBUF2: PBUF Position            */
#define PWM_PBUF2_PBUF_Msk               (0xfffful << PWM_PBUF2_PBUF_Pos)                  /*!< PWM_T::PBUF2: PBUF Mask                */

#define PWM_PBUF4_PBUF_Pos               (0)                                               /*!< PWM_T::PBUF4: PBUF Position            */
#define PWM_PBUF4_PBUF_Msk               (0xfffful << PWM_PBUF4_PBUF_Pos)                  /*!< PWM_T::PBUF4: PBUF Mask                */

#define PWM_CMPBUF0_CMPBUF_Pos           (0)                                               /*!< PWM_T::CMPBUF0: CMPBUF Position        */
#define PWM_CMPBUF0_CMPBUF_Msk           (0xfffful << PWM_CMPBUF0_CMPBUF_Pos)              /*!< PWM_T::CMPBUF0: CMPBUF Mask            */

#define PWM_CMPBUF1_CMPBUF_Pos           (0)                                               /*!< PWM_T::CMPBUF1: CMPBUF Position        */
#define PWM_CMPBUF1_CMPBUF_Msk           (0xfffful << PWM_CMPBUF1_CMPBUF_Pos)              /*!< PWM_T::CMPBUF1: CMPBUF Mask            */

#define PWM_CMPBUF2_CMPBUF_Pos           (0)                                               /*!< PWM_T::CMPBUF2: CMPBUF Position        */
#define PWM_CMPBUF2_CMPBUF_Msk           (0xfffful << PWM_CMPBUF2_CMPBUF_Pos)              /*!< PWM_T::CMPBUF2: CMPBUF Mask            */

#define PWM_CMPBUF3_CMPBUF_Pos           (0)                                               /*!< PWM_T::CMPBUF3: CMPBUF Position        */
#define PWM_CMPBUF3_CMPBUF_Msk           (0xfffful << PWM_CMPBUF3_CMPBUF_Pos)              /*!< PWM_T::CMPBUF3: CMPBUF Mask            */

#define PWM_CMPBUF4_CMPBUF_Pos           (0)                                               /*!< PWM_T::CMPBUF4: CMPBUF Position        */
#define PWM_CMPBUF4_CMPBUF_Msk           (0xfffful << PWM_CMPBUF4_CMPBUF_Pos)              /*!< PWM_T::CMPBUF4: CMPBUF Mask            */

#define PWM_CMPBUF5_CMPBUF_Pos           (0)                                               /*!< PWM_T::CMPBUF5: CMPBUF Position        */
#define PWM_CMPBUF5_CMPBUF_Msk           (0xfffful << PWM_CMPBUF5_CMPBUF_Pos)              /*!< PWM_T::CMPBUF5: CMPBUF Mask            */

/**@}*/ /* PWM_CONST */
/**@}*/ /* end of PWM register group */
/**@}*/ /* end of REGISTER group */

#if defined ( __CC_ARM   )
#pragma no_anon_unions
#endif

#endif /* __PWM_REG_H__ */