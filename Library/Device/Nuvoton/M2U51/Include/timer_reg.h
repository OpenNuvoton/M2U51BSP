/**************************************************************************//**
 * @file     timer_reg.h
 * @version  V1.00
 * @brief    TIMER register definition header file
 *
 * SPDX-License-Identifier: Apache-2.0
 * @copyright (C) 2017-2020 Nuvoton Technology Corp. All rights reserved.
 *****************************************************************************/
#ifndef __TIMER_REG_H__
#define __TIMER_REG_H__

#if defined ( __CC_ARM   )
#pragma anon_unions
#endif

/**
    @addtogroup REGISTER Control Register
    @{
*/

/**
    @addtogroup TIMER Timer Controller (TIMER)
    Memory Mapped Structure for TIMER Controller
@{ */

typedef struct
{
    /**
     * @var TIMER_T::CTL
     * Offset: 0x00  Timer Control Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[7:0]   |PSC       |Prescale Counter
     * |        |          |Timer input clock or event source is divided by (PSC+1) before it is fed to the timer up counter
     * |        |          |If this field is 0 (PSC = 0), then there is no scaling.
     * |        |          |Note: Update prescale counter value will reset internal 8-bit prescale counter and 24-bit up counter value.
     * |[15]    |FUNCSEL   |Function Selection
     * |        |          |0 = Timer controller is used as timer function.
     * |        |          |1 = Timer controller is used as PWM function.
     * |[16]    |PDCLKEN   |Power-down Engine Clock Enable
     * |        |          |0 = Disable engine clock in power-down mode.
     * |        |          |1 = Enable engine clock in power-down mode.
     * |[19]    |INTRGEN   |Inter-timer Trigger Mode Enable Bit
     * |        |          |Setting this bit will enable the inter-timer trigger capture function.
     * |        |          |The Timer0/2 will be in event counter mode and counting with external clock source or event
     * |        |          |Also, Timer1/3 will be in trigger-counting mode of capture function.
     * |        |          |0 = Inter-Timer Trigger Capture mode Disabled.
     * |        |          |1 = Inter-Timer Trigger Capture mode Enabled.
     * |        |          |Note: For Timer1/3, this bit is ineffective and the read back value is always 0.
     * |[20]    |PERIOSEL  |Periodic Mode Behavior Selection Enable Bit
     * |        |          |0 = The behavior selection in periodic mode is Disabled.
     * |        |          |When user updates CMPDAT while timer is running in periodic mode,
     * |        |          |CNT will be reset to default value.
     * |        |          |1 = The behavior selection in periodic mode is Enabled.
     * |        |          |When user updates CMPDAT while timer is running in periodic mode, the limitations as bellows list,
     * |        |          |If updated CMPDAT value > CNT, CMPDAT will be updated and CNT keep running continually.
     * |        |          |If updated CMPDAT value = CNT, timer time-out interrupt will be asserted immediately.
     * |        |          |If updated CMPDAT value < CNT, CNT will be reset to default value.
     * |[21]    |TGLPINSEL |Toggle-output Pin Select
     * |        |          |0 = Toggle mode output to TMx (Timer Event Counter Pin).
     * |        |          |1 = Toggle mode output to TMx_EXT (Timer External Capture Pin).
     * |[22]    |CAPSRC    |Capture Pin Source Selection
     * |        |          |0 = Capture Function source is from TMx_EXT (x= 0~3) pin.
     * |        |          |1 = Capture Function source is from internal ACMP output signal, internal clock (MIRC, LIRC, HIRC), or external clock (LXT).
     * |        |          |Note: When CAPSRC = 1,User can set INTERCAPSEL (TIMERx_EXTCTL[10:8]) to decide which internal ACMP output signal or which clock is as timer capture source.
     * |[23]    |WKEN      |Wake-up Function Enable Bit
     * |        |          |If this bit is set to 1, while timer interrupt flag TIF (TIMERx_INTSTS[0]) is 1 and INTEN (TIMERx_CTL[29]) is enabled, the timer interrupt signal will generate a wake-up trigger event to CPU.
     * |        |          |0 = Wake-up function Disabled if timer interrupt signal generated.
     * |        |          |1 = Wake-up function Enabled if timer interrupt signal generated.
     * |[24]    |EXTCNTEN  |Event Counter Mode Enable Bit
     * |        |          |This bit is for external counting pin function enabled.
     * |        |          |0 = Event counter mode Disabled.
     * |        |          |1 = Event counter mode Enabled.
     * |        |          |Note: When timer is used as an event counter, this bit should be set to 1.
     * |[25]    |ACTSTS    |Timer Active Status Bit (Read Only)
     * |        |          |This bit indicates the 24-bit up counter status.
     * |        |          |0 = 24-bit up counter is not active.
     * |        |          |1 = 24-bit up counter is active.
     * |        |          |Note: This bit may active when CNT 0 transition to CNT 1.
     * |[28:27] |OPMODE    |Timer Counting Mode Select
     * |        |          |00 = The timer controller is operated in One-shot mode.
     * |        |          |01 = The timer controller is operated in Periodic mode.
     * |        |          |10 = The timer controller is operated in Toggle-output mode.
     * |        |          |11 = The timer controller is operated in Continuous Counting mode.
     * |[29]    |INTEN     |Timer Interrupt Enable Bit
     * |        |          |0 = Timer time-out interrupt Disabled.
     * |        |          |1 = Timer time-out interrupt Enabled.
     * |        |          |Note: If this bit is enabled, when the timer time-out interrupt flag TIF is set to 1, the timer interrupt signal is generated and inform to CPU.
     * |[30]    |CNTEN     |Timer Counting Enable Bit
     * |        |          |0 = Stops/Suspends counting.
     * |        |          |1 = Starts counting.
     * |        |          |Note1: In stop status, and then set CNTEN to 1 will enable the 24-bit up counter to keep counting from the last stop counting value.
     * |        |          |Note2: This bit is auto-cleared by hardware in one-shot mode (TIMER_CTL[28:27] = 00) when the timer time-out interrupt flag TIF (TIMERx_INTSTS[0]) is generated.
     * |        |          |Note3: Set enable/disable this bit needs 2 * TMR_CLK period to become active, user can read ACTSTS (TIMERx_CTL[25]) to check enable/disable command is completed or not.
     * |[31]    |ICEDEBUG  |ICE Debug Mode Acknowledge Disable Bit (Write Protect)
     * |        |          |0 = ICE debug mode acknowledgement effects TIMER counting.
     * |        |          |TIMER counter will be held while CPU is held by ICE.
     * |        |          |1 = ICE debug mode acknowledgement Disabled.
     * |        |          |TIMER counter will keep going no matter CPU is held by ICE or not.
     * |        |          |Note: This bit is write protected. Refer to the SYS_REGLCTL register.
     * @var TIMER_T::CMP
     * Offset: 0x04  Timer Comparator Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[23:0]  |CMPDAT    |Timer Comparator Value
     * |        |          |CMPDAT is a 24-bit compared value register
     * |        |          |When the internal 24-bit up counter value is equal to CMPDAT value, the TIF (TIMERx_INTSTS[0] Timer Interrupt Flag) will set to 1.
     * |        |          |Time-out period = (Period of timer clock input) * (8-bit PSC + 1) * (24-bit CMPDAT).
     * |        |          |Note1: Never write 0x0 or 0x1 in CMPDAT field, or the core will run into unknown state.
     * |        |          |Note2: When timer is operating at continuous counting mode, the 24-bit up counter will keep counting continuously even if user writes a new value into CMPDAT field
     * |        |          |But if timer is operating at other modes, the 24-bit up counter will restart counting from 0 and using newest CMPDAT value to be the timer compared value while user writes a new value into CMPDAT field.
     * @var TIMER_T::INTSTS
     * Offset: 0x08  Timer Interrupt Status Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |TIF       |Timer Interrupt Flag
     * |        |          |This bit indicates the interrupt flag status of Timer while 24-bit timer up counter CNT (TIMERx_CNT[23:0]) value reaches to CMPDAT (TIMERx_CMP[23:0]) value.
     * |        |          |0 = No effect.
     * |        |          |1 = CNT value matches the CMPDAT value.
     * |        |          |Note: This bit is cleared by writing 1 to it.
     * |[1]     |TWKF      |Timer Wake-up Flag
     * |        |          |This bit indicates the interrupt wake-up flag status of timer.
     * |        |          |0 = Timer does not cause CPU wake-up.
     * |        |          |1 = CPU wake-up from Idle or Power-down mode if timer time-out interrupt signal generated.
     * |        |          |Note: This bit is cleared by writing 1 to it.
     * @var TIMER_T::CNT
     * Offset: 0x0C  Timer Data Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[23:0]  |CNT       |Timer Data Register
     * |        |          |Read operation.
     * |        |          |Read this register to get CNT value. For example:
     * |        |          |If EXTCNTEN (TIMERx_CTL[24] ) is 0, user can read CNT value for getting current 24-bit counter value.
     * |        |          |If EXTCNTEN (TIMERx_CTL[24] ) is 1, user can read CNT value for getting current 24-bit event input counter value.
     * |        |          |Write operation.
     * |        |          |Writing any value to this register will reset current CNT value to 0 and reload internal 8-bit prescale counter.
     * |[31]    |RSTACT    |Timer Data Register Reset Active (Read Only)
     * |        |          |This bit indicates if the counter reset operation active.
     * |        |          |When user writes this CNT register, timer starts to reset its internal 24-bit timer up-counter to 0 and reload 8-bit pre-scale counter
     * |        |          |At the same time, timer set this flag to 1 to indicate the counter reset operation is in progress
     * |        |          |Once the counter reset operation done, timer clear this bit to 0 automatically.
     * |        |          |0 = Reset operation is done.
     * |        |          |1 = Reset operation triggered by writing TIMERx_CNT is in progress.
     * @var TIMER_T::CAP
     * Offset: 0x10  Timer Capture Data Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[23:0]  |CAPDAT    |Timer Capture Data Register
     * |        |          |When CAPEN (TIMERx_EXTCTL[3]) bit is set and a transition on TMx_EXT pin matched the CAPEDGE (TIMERx_EXTCTL[14:12]) setting, CAPIF (TIMERx_EINTSTS[0]) will set to 1 and the current timer counter value CNT (TIMERx_CNT[23:0]) will be auto-loaded into this CAPDAT field.
     * @var TIMER_T::EXTCTL
     * Offset: 0x14  Timer External Control Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |CNTPHASE  |Timer External Count Phase
     * |        |          |This bit indicates the detection phase of external counting pin TMx (x= 0~3).
     * |        |          |0 = A falling edge of external counting pin will be counted.
     * |        |          |1 = A rising edge of external counting pin will be counted.
     * |[3]     |CAPEN     |Timer Capture Enable Bit
     * |        |          |This bit enables the capture input function.
     * |        |          |0 =Capture source Disabled.
     * |        |          |1 =Capture source Enabled.
     * |        |          |Note: When CAPEN is 1, user can set INTERCAPSEL (TIMERx_EXTCTL [10:8]) to select capture source.
     * |[4]     |CAPFUNCS  |Capture Function Selection
     * |        |          |0 = External Capture Mode Enabled.
     * |        |          |1 = External Reset Mode Enabled.
     * |        |          |Note1: When CAPFUNCS is 0, transition on TMx_EXT (x= 0~3) pin is using to save current 24-bit timer counter value (CNT value) to CAPDAT field.
     * |        |          |Note2: When CAPFUNCS is 1, transition on TMx_EXT (x= 0~3) pin is using to save current 24-bit timer counter value (CNT value) to CAPDAT field then CNT value will be reset immediately.
     * |[5]     |CAPIEN    |Timer External Capture Interrupt Enable Bit
     * |        |          |0 = TMx_EXT (x= 0~3) pin, ACMP, internal clock, or external clock detection Interrupt Disabled.
     * |        |          |1 = TMx_EXT (x= 0~3) pin, ACMP, internal clock, or external clock detection Interrupt Enabled.
     * |        |          |Note: CAPIEN is used to enable timer external interrupt
     * |        |          |If CAPIEN enabled, timer will rise an interrupt when CAPIF (TIMERx_EINTSTS[0]) is 1.
     * |        |          |For example, while CAPIEN = 1, CAPEN = 1, and CAPEDGE = 00, a 1 to 0 transition on the TMx_EXT (x= 0~3) pin, ACMP, internal clock, or external clock will cause the CAPIF to be set then the interrupt signal is generated and sent to NVIC to inform CPU.
     * |[6]     |CAPDBEN   |Timer External Capture Pin De-bounce Enable Bit
     * |        |          |0 = TMx_EXT (x= 0~3) pin de-bounce or ACMP output de-bounce Disabled.
     * |        |          |1 = TMx_EXT (x= 0~3) pin de-bounce or ACMP output de-bounce Enabled.
     * |        |          |Note: If this bit is enabled, the edge detection of TMx_EXT pin or ACMP output is detected with de-bounce circuit.
     * |[7]     |CNTDBEN   |Timer Counter Pin De-bounce Enable Bit
     * |        |          |0 = TMx (x= 0~3) pin de-bounce Disabled.
     * |        |          |1 = TMx (x= 0~3) pin de-bounce Enabled.
     * |        |          |Note: If this bit is enabled, the edge detection of TMx pin is detected with de-bounce circuit.
     * |[10:8]  |INTERCAPSEL|Internal Capture Source Select
     * |        |          |000 = Capture Function source is from internal ACMP0 output signal.
     * |        |          |001 = Capture Function source is from internal ACMP1 output signal.
     * |        |          |010 = Reserved.
     * |        |          |011 = Capture Function source is from LXT.
     * |        |          |100 = Capture Function source is from HIRC.
     * |        |          |101 = Capture Function source is from LIRC.
     * |        |          |110 = Capture Function source is from MIRC.
     * |        |          |Note: these bits only available when CAPSRC (TIMERx_CTL[22]) is 1.
     * |[14:12] |CAPEDGE   |Timer External Capture Pin Edge Detect
     * |        |          |When first capture event is generated, the CNT (TIMERx_CNT[23:0]) will be reset to 0 and first CAPDAT (TIMERx_CAP[23:0]) should be to 0.
     * |        |          |000 = Capture event occurred when detect falling edge transfer on TMx_EXT (x= 0~3) pin.
     * |        |          |001 = Capture event occurred when detect rising edge transfer on TMx_EXT (x= 0~3) pin.
     * |        |          |010 = Capture event occurred when detect both falling and rising edge transfer on TMx_EXT (x= 0~3) pin, and first capture event occurred at falling edge transfer.
     * |        |          |011 = Capture event occurred when detect both rising and falling edge transfer on TMx_EXT (x= 0~3) pin, and first capture event occurred at rising edge transfer.
     * |        |          |110 = First capture event occurred at falling edge, follows capture events are at rising edge transfer on TMx_EXT (x= 0~3) pin.
     * |        |          |111 = First capture event occurred at rising edge, follows capture events are at falling edge transfer on TMx_EXT (x= 0~3) pin.
     * |        |          |100, 101 = Reserved.
     * |        |          |Note: Set CAPSRC (TIMERx_CTL[22]) and INTERCAPSEL (TIMERx_EXTCTL[10:8]) to select capture source.
     * |[18:16] |ECNTSSEL  |Event Counter Source Selection to Trigger Event Counter Function
     * |        |          |000 = Event Counter input source is from external TMx (x= 0~3) pin.
     * |        |          |010 = Event Counter input source is from internal ACMP0 output signal.
     * |        |          |011 = Event Counter input source is from internal ACMP1 output signal.
     * |        |          |101~111 = Reserved.
     * |[31:28] |CAPDIVSCL |Timer Capture Source Divider Scale
     * |        |          |This bits indicate the divide scale for capture source divider
     * |        |          |0000 = Capture source/1.
     * |        |          |0001 = Capture source/2.
     * |        |          |0010 = Capture source/4.
     * |        |          |0011 = Capture source/8.
     * |        |          |0100 = Capture source/16.
     * |        |          |0101 = Capture source/32.
     * |        |          |0110 = Capture source/64.
     * |        |          |0111 = Capture source/128.
     * |        |          |1000 = Capture source/256.
     * |        |          |1001~1111 = Reserved.
     * |        |          |Note: Set INTERCAPSEL (TIMERx_EXTCTL[10:8]) and CAPSRC (TIMERx_CTL[22]) to select capture source.
     * @var TIMER_T::EINTSTS
     * Offset: 0x18  Timer External Interrupt Status Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |CAPIF     |Timer External Capture Interrupt Flag
     * |        |          |This bit indicates the timer external capture interrupt flag status.
     * |        |          |0 = TMx_EXT (x= 0~3) pin, ACMP, internal clock, or external clock interrupt did not occur.
     * |        |          |1 = TMx_EXT (x= 0~3) pin, ACMP, internal clock, or external clock interrupt occurred.
     * |        |          |Note1: This bit is cleared by writing 1 to it.
     * |        |          |Note 2: When CAPEN (TIMERx_EXTCTL[3]) bit is set, CAPFUNCS (TIMERx_EXTCTL[4]) bit is 0, and a transition on TMx_EXT (x= 0~3) pin, ACMP, internal clock, or external clock matched the CAPEDGE (TIMERx_EXTCTL[2:1]) setting, this bit will set to 1 by hardware.
     * |        |          |Note3: There is a new incoming capture event detected before CPU clearing the CAPIF status
     * |        |          |If the above condition occurred, the Timer will keep register TIMERx_CAP unchanged and drop the new capture value.
     * |[1]     |CAPIFOV   |Capture Latch Interrupt Flag Overrun Status (Read Only)
     * |        |          |0 = Capture latch happened when the corresponding CAPIF is 0.
     * |        |          |1 = Capture latch happened when the corresponding CAPIF is 1.
     * |        |          |Note: This bit will be cleared automatically when user clear corresponding CAPIF.
     * @var TIMER_T::TRGCTL
     * Offset: 0x1C  Timer Trigger Control Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |TRGSSEL   |Trigger Source Select Bit
     * |        |          |This bit is used to select internal trigger source is form timer time-out interrupt signal or capture interrupt signal.
     * |        |          |0 = Time-out interrupt signal is used to internal trigger PWM, BPWM, PDMA and ADC.
     * |        |          |1 = Capture interrupt signal is used to internal trigger PWM, BPWM, PDMA and ADC.
     * |[1]     |TRGPWM    |Trigger PWM/BPWM Enable Bit
     * |        |          |If this bit is set to 1, each timer time-out event or capture event can be as PWM/BPWM counter clock source.
     * |        |          |0 = Timer interrupt trigger PWM/BPWM Disabled.
     * |        |          |1 = Timer interrupt trigger PWM/BPWM Enabled.
     * |        |          |Note: If TRGSSEL (TIMERx_TRGCTL[0]) = 0, time-out interrupt signal as PWM/BPWM counter clock source.
     * |        |          |If TRGSSEL (TIMERx_TRGCTL[0]) = 1, capture interrupt signal as PWM/BPWM counter clock source.
     * |        |          |Note: User can't set this bit to enable trigger PWM/BPWM function when doing auto operation mode.
     * |[2]     |TRGADC    |Trigger ADC Enable Bit
     * |        |          |If this bit is set to 1, each timer time-out event or capture event can be triggered ADC conversion.
     * |        |          |0 = Timer interrupt trigger ADC Disabled.
     * |        |          |1 = Timer interrupt trigger ADC Enabled.
     * |        |          |Note: If TRGSSEL (TIMERx_TRGCTL[0]) = 0, time-out interrupt signal will trigger ADC conversion.
     * |        |          |If TRGSSEL (TIMERx_TRGCTL[0]) = 1, capture interrupt signal will trigger ADC conversion.
     * |        |          |Note: User can't set this bit to enable trigger ADC function when doing auto operation mode.
     * |[4]     |TRGPDMA   |Trigger PDMA Enable Bit
     * |        |          |If this bit is set to 1, each timer time-out event or capture event can be triggered PDMA transfer.
     * |        |          |0 = Timer interrupt trigger PDMA Disabled.
     * |        |          |1 = Timer interrupt trigger PDMA Enabled.
     * |        |          |Note: If TRGSSEL (TIMERx_TRGCTL[0]) = 0, time-out interrupt signal will trigger PDMA transfer.
     * |        |          |If TRGSSEL (TIMERx_TRGCTL[0]) = 1, capture interrupt signal will trigger PDMA transfer.
     * |        |          |Note: User can't set this bit to enable trigger PDMA function when doing auto operation mode.
     * @var TIMER_T::CAPNF
     * Offset: 0x24  Timer Capture Input Noise Filter Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |CAPNFEN   |Capture Noise Filter Enable
     * |        |          |0 = Capture Noise Filter function Disabled.
     * |        |          |1 = Capture Noise Filter function Enabled.
     * |[6:4]   |CAPNFSEL  |Capture Edge Detector Noise Filter Clock Selection
     * |        |          |000 = Noise filter clock is TMRx_CLK.
     * |        |          |001 = Noise filter clock is TMRx_CLK/2.
     * |        |          |010 = Noise filter clock is TMRx_CLK/4.
     * |        |          |011 = Noise filter clock is TMRx_CLK/8.
     * |        |          |100 = Noise filter clock is TMRx_CLK/16.
     * |        |          |101 = Noise filter clock is TMRx_CLK/32.
     * |        |          |110 = Noise filter clock is TMRx_CLK/64.
     * |        |          |111 = Noise filter clock is TMRx_CLK/128.
     * |[10:8]  |CAPNFCNT  |Capture Edge Detector Noise Filter Count
     * |        |          |These bits control the capture filter counter to count from 0 to CAPNFCNT.
     * @var TIMER_T::ATRGCTL
     * Offset: 0x28  Timer Auto Operation Trigger Control Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |ATRGSSEL  |Auto Operation Trigger Source Select Bit
     * |        |          |This bit is used to select internal trigger source is form timer time-out interrupt signal or capture interrupt signal.
     * |        |          |0 = Time-out interrupt signal is used to internal trigger I2C, SPI, UART, PDMA and ADC.
     * |        |          |1 = Capture interrupt signal is used to internal trigger I2C, SPI, UART, PDMA and ADC.
     * |[4]     |ATRGPDMA  |Auto Operation Trigger PDMA Enable Bit
     * |        |          |If this bit is set to 1, each timer time-out event or capture event can be triggered PDMA transfer.
     * |        |          |0 = Timer interrupt trigger PDMA Disabled.
     * |        |          |1 = Timer interrupt trigger PDMA Enabled.
     * |        |          |Note: If ATRGSSEL (TIMERx_TRGCTL[0]) = 0, time-out interrupt signal will trigger PDMA transfer.
     * |        |          |If ATRGSSEL (TIMERx_TRGCTL[0]) = 1, capture interrupt signal will trigger PDMA transfer.
     * |[9]     |ATRGEN    |Auto Operation Trigger IPs Enable Bit
     * |        |          |If this bit is set to 1, each timer time-out event or capture event can trigger IPs in auto operation mode.
     * |        |          |0 = Timer interrupt trigger IPs Disabled.
     * |        |          |1 = Timer interrupt trigger IPs Enabled.
     * |        |          |Note: If ATRGSSEL (TMRx_ATRGCTL[0]) = 0, time-out interrupt signal will trigger IPs conversion.
     * |        |          |Note: If ATRGSSEL (TMRx_ATRGCTL[0]) = 1, capture interrupt signal will trigger IPs conversion.
     * @var TIMER_T::PWMCTL
     * Offset: 0x40  Timer PWM Control Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |CNTEN     |PWM Counter Enable Bit
     * |        |          |0 = PWM counter and clock prescale Stop Running.
     * |        |          |1 = PWM counter and clock prescale Start Running.
     * |[3]     |CNTMODE   |PWM Counter Mode
     * |        |          |0 = Auto-reload mode.
     * |        |          |1 = One-shot mode.
     * |[12]    |PWMINTWKEN|PWM Interrupt Wake-up Enable Bit
     * |        |          |If PWM interrupt occurs when chip is in Power-down mode, PWMINTWKEN can determine whether chip wake-up occurs or not.
     * |        |          |0 = PWM interrupt wake-up Disabled.
     * |        |          |1 = PWM interrupt wake-up Enabled.
     * |[30]    |DBGHALT   |ICE Debug Mode Counter Halt (Write Protect)
     * |        |          |If debug mode counter halt is enabled, PWM counter will keep current value until exit ICE debug mode.
     * |        |          |0 = ICE debug mode counter halt Disabled.
     * |        |          |1 = ICE debug mode counter halt Enabled.
     * |        |          |Note: This bit is write protected. Refer to SYS_REGLCTL control register.
     * |[31]    |DBGTRIOFF |ICE Debug Mode Acknowledge Disable Bit (Write Protect)
     * |        |          |0 = ICE debug mode acknowledgement effects PWM output.
     * |        |          |PWM output pin will be forced as tri-state while ICE debug mode acknowledged.
     * |        |          |1 = ICE debug mode acknowledgement disabled.
     * |        |          |PWM output pin will keep output no matter ICE debug mode acknowledged or not.
     * |        |          |Note: This bit is write protected. Refer to SYS_REGLCTL control register.
     * @var TIMER_T::PWMCLKPSC
     * Offset: 0x44  Timer PWM Counter Clock Pre-scale Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[7:0]   |CLKPSC    |PWM Counter Clock Pre-scale
     * |        |          |The active clock of PWM counter is decided by counter clock prescale and divided by (CLKPSC + 1)
     * |        |          |If CLKPSC is 0, then there is no scaling in PWM counter clock source.
     * @var TIMER_T::PWMCNTCLR
     * Offset: 0x48  Timer PWM Clear Counter Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |CNTCLR    |Clear PWM Counter Control Bit
     * |        |          |0 = No effect.
     * |        |          |1 = Write 1 to clear 16-bit PWM counter to 0x0000 in up count type.
     * |        |          |Note: When user write this bit to 1, PWM counter will be cleared after (CLKPSC+16) TMRx_CLK cycles.
     * @var TIMER_T::PWMPERIOD
     * Offset: 0x4C  Timer PWM Period Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[15:0]  |PERIOD    |PWM Period Register
     * |        |          |In up count type: PWM counter counts from 0 to PERIOD, and restarts from 0.
     * |        |          |In up count type:
     * |        |          |PWM period time = (PERIOD + 1) * (CLKPSC + 1) * TMRx_PWMCLK.
     * @var TIMER_T::PWMCMPDAT
     * Offset: 0x50  Timer PWM Comparator Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[15:0]  |CMP       |PWM Comparator Register
     * |        |          |PWM CMP is used to compare with PWM CNT to generate PWM output waveform, interrupt events and trigger ADC, and PDMA start conversion.
     * @var TIMER_T::PWMCNT
     * Offset: 0x54  Timer PWM Counter Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[15:0]  |CNT       |PWM Counter Value Register (Read Only)
     * |        |          |User can monitor CNT to know the current counter value in 16-bit period counter.
     * @var TIMER_T::PWMPOLCTL
     * Offset: 0x58  Timer PWM Pin Output Polar Control Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |PINV      |PWMx Output Pin Polar Control Bit
     * |        |          |The bit is used to control polarity state of PWMx_OUT pin.
     * |        |          |0 = PWMx_OUT pin polar inverse Disabled.
     * |        |          |1 = PWMx_OUT polar inverse Enabled.
     * |        |          |Note: Set POSEL (TIMERx_PWMPOCTL[8]) to select TMx or TMx_EXT as PWMx output pin.
     * @var TIMER_T::PWMPOCTL
     * Offset: 0x5C  Timer PWM Pin Output Control Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |POEN      |PWMx Output Pin Enable Bit
     * |        |          |0 = PWMx_OUT pin at tri-state mode.
     * |        |          |1 = PWMx_OUT pin in output mode.
     * |        |          |Note: Set POSEL (TIMERx_PWMPOCTL[8]) to select TMx or TMx_EXT as PWMx output pin.
     * |[8]     |POSEL     |PWM Output Pin Select
     * |        |          |0 = PWMx_OUT pin is TMx.
     * |        |          |1 = PWMx_OUT pin is TMx_EXT.
     * @var TIMER_T::PWMINTEN0
     * Offset: 0x60  Timer PWM Interrupt Enable Register 0
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[1]     |PIEN      |PWM Period Point Interrupt Enable Bit
     * |        |          |0 = Period point interrupt Disabled.
     * |        |          |1 = Period point interrupt Enabled.
     * |[2]     |CMPUIEN   |PWM Compare Up Count Interrupt Enable Bit
     * |        |          |0 = Compare up count interrupt Disabled.
     * |        |          |1 = Compare up count interrupt Enabled.
     * @var TIMER_T::PWMINTSTS0
     * Offset: 0x64  Timer PWM Interrupt Status Register 0
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[1]     |PIF       |PWM Period Point Interrupt Flag
     * |        |          |This bit is set by hardware when TIMERx_PWM counter reaches PERIOD.
     * |        |          |Note: This bit is cleared by writing 1 to it.
     * |[2]     |CMPUIF    |PWM Compare Up Count Interrupt Flag
     * |        |          |This bit is set by hardware when TIMERx_PWM counter in up count direction and reaches CMP.
     * |        |          |Note: If CMP equal to PERIOD, there is no CMPUIF flag in up count type
     * |        |          |Note2: This bit is cleared by writing 1 to it.
     * @var TIMER_T::PWMTRGCTL
     * Offset: 0x68  Timer PWM Trigger Control Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[1:0]   |TRGSEL    |PWM Counter Event Source Select to Trigger Conversion
     * |        |          |00 = Trigger conversion at period point (PIF).
     * |        |          |01 = Trigger conversion at compare up count point (CMPUIF).
     * |        |          |10 = Trigger conversion at period or compare up count point (PIF or CMPUIF).
     * |        |          |11 = Reserved.
     * |[7]     |PWMTRGADC |PWM Counter Event Trigger ADC Conversion Enable Bit
     * |        |          |0 = PWM counter event trigger ADC conversion Disabled.
     * |        |          |1 = PWM counter event trigger ADC conversion Enabled.
     * |        |          |Note: Set TRGSEL (TIMERx_PWMTRGCTL[1:0]) to select PWM trigger conversion source.
     * |        |          |Nore: User can't set this bit to enable trigger ADC function when doing auto operation mode.
     * |[9]     |PWMTRGPDMA|PWM Counter Event Trigger PDMA Conversion Enable Bit
     * |        |          |If this bit is set to 1, PWM can trigger PDMA conversion.
     * |        |          |0 = PWM trigger PDMA Disabled.
     * |        |          |1 = PWM trigger PDMA Enabled.
     * |        |          |Note: Set TRGSEL (TIMERx_PWMTRGCTL[1:0]) to select PWM trigger conversion source.
     * |        |          |Note: User can't set this bit to enable trigger PDMA function when doing auto operation mode.
     * @var TIMER_T::PWMSTATUS
     * Offset: 0x6C  Timer PWM Status Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |CNTMAXF   |PWM Counter Equal to 0xFFFF Flag
     * |        |          |0 = The PWM counter value never reached its maximum value 0xFFFF.
     * |        |          |1 = The PWM counter value has reached its maximum value.
     * |        |          |Note: This bit is cleared by writing 1 to it.
     * |[8]     |PWMINTWKF |PWM Interrupt Wake-up Flag
     * |        |          |0 = PWM interrupt wake-up has not occurred.
     * |        |          |1 = PWM interrupt wake-up has occurred.
     * |        |          |Note: This bit is cleared by writing 1 to it.
     * |[16]    |ADCTRGF   |Trigger ADC Start Conversion Flag
     * |        |          |0 = PWM counter event trigger ADC start conversion is not occurred.
     * |        |          |1 = PWM counter event trigger ADC start conversion has occurred.
     * |        |          |Note: This bit is cleared by writing 1 to it.
     * |[18]    |PDMATRGF  |Trigger PDMA Start Conversion Flag
     * |        |          |0 = PWM counter event trigger PDMA start conversion has not occurred.
     * |        |          |1 = PWM counter event trigger PDMA start conversion has occurred.
     * |        |          |Note: This bit is cleared by writing 1 to it.
     * @var TIMER_T::PWMPBUF
     * Offset: 0x70  Timer PWM Period Buffer Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[15:0]  |PBUF      |PWM Period Buffer Register (Read Only)
     * |        |          |Used as PERIOD active register.
     * @var TIMER_T::PWMCMPBUF
     * Offset: 0x74  Timer PWM Comparator Buffer Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[15:0]  |CMPBUF    |PWM Comparator Buffer Register (Read Only)
     * |        |          |Used as CMP active register.
     * @var TIMER_T::PWMIFA
     * Offset: 0xA8  Timer PWM Interrupt Flag Accumulator Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[15:0]  |IFACNT    |PWM Interrupt Flag Accumulator Counter
     * |        |          |This field sets the count number which defines (IFACNT+1) times of specify PWM interrupt occurs to set IFAIF bit to request the PWM accumulator interrupt.
     * |        |          |PWM accumulator flag (IFAIF) will be set in every (IFACNT+1) times during the the PWM counter operation.
     * |[24]    |STPMOD    |PWM Accumulator Stop Mode Enable Bit
     * |        |          |0 = PWM interrupt accumulator event to stop counting Disabled.
     * |        |          |1 = PWM interrupt accumulator event to stop counting Enabled.
     * |[29:28] |IFASEL    |PWM Interrupt Flag Accumulator Source Select
     * |        |          |01 = Accumulate at each PWM period point.
     * |        |          |10 = Accumulate at each PWM up-count compared point.
     * |[31]    |IFAEN     |PWM Interrupt Flag Accumulator Enable Bit
     * |        |          |0 = PWM interrupt flag accumulator function Disabled.
     * |        |          |1 = PWM interrupt flag accumulator function Enabled.
     * @var TIMER_T::PWMAINTSTS
     * Offset: 0xAC  Timer PWM Accumulator Interrupt Flag Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |IFAIF     |PWM Interrupt Flag Accumulator Interrupt Flag
     * |        |          |This bit is set by hardware when the accumulator value reaches (IFACNT+1)
     * |        |          |Note1: This bit is cleared by writing 1 to it.
     * |        |          |Note 2: If APDMAEN (TIMERx_PWMAPDMACTL[0]) is set, this bit will be auto clear after PDMA transfer done.
     * @var TIMER_T::PWMAINTEN
     * Offset: 0xB0  Timer PWM Accumulator Interrupt Enable Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |IFAIEN    |PWM Interrupt Flag Accumulator Interrupt Enable Bit
     * |        |          |0 = Interrupt Flag Accumulator interrupt Disabled.
     * |        |          |1 = Interrupt Flag Accumulator interrupt Enabled.
     * @var TIMER_T::PWMAPDMACTL
     * Offset: 0xB4  Timer PWM Accumulator PDMA Control Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |APDMAEN   |PWM Accumulator PDMA Enable Bit
     * |        |          |0 = PWM interrupt accumulator event to trigger PDMA transfer Disabled.
     * |        |          |1 = PWM interrupt accumulator event to trigger PDMA transfer Enabled.
     * |        |          |Note: User should set TIMER_PWMIFA before enable this bit.
     * |[1]     |AEPDMA    |Accumulator Every IFACNT PDMA Mode Enable Bit
     * |        |          |If this bit is set to 1, PWM can trigger PDMA in every duty when user uses Accumulator PDMA Function
     * |        |          |0 = Trigger PDMA Accumulator Mode Disabled.
     * |        |          |1 = Trigger PDMA Accumulator Mode Enabled.
     * |        |          |Note1: User should set APDMAEN to 1 first when using this mode.
     * |        |          |Note2: User should set TIMER_PWMIFA before enable this bit.
     * @var TIMER_T::PWMATRGCTL
     * Offset: 0xB8  Timer PWM Auto Operation Trigger Control Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[1:0]   |ATRGSEL   |PWM Auto Operation Counter Event Source Select to Trigger Conversion
     * |        |          |00 = Trigger conversion at period point (PIF).
     * |        |          |01 = Trigger conversion at compare up count point (CMPUIF).
     * |        |          |10 = Trigger conversion at period or compare up count point (PIF or CMPUIF).
     * |        |          |11 = Reserved.
     * |[2]     |PWMATRGEN |PWM Auto Operation Trigger IPs Enable Bit
     * |        |          |If this bit is set to 1, each timer time-out event can trigger IPs.
     * |        |          |0 = Timer PWM counter event trigger IPs Disabled.
     * |        |          |1 = Timer PWM counter event trigger IPs Enabled.
     * |[9]     |PWMATRGPDMA|PWM Auto Operation Counter Event Trigger PDMA Conversion Enable Bit
     * |        |          |If this bit is set to 1, PWM can trigger PDMA conversion.
     * |        |          |0 = PWM trigger PDMA Disabled.
     * |        |          |1 = PWM trigger PDMA Enabled.
     * |        |          |Note: Set ATRGSEL (TIMERx_PWMATRGCTL[1:0]) to select PWM trigger conversion source.
     */
    __IO uint32_t CTL;                  /*!< [0x0000] Timer Control Register                                */
    __IO uint32_t CMP;                  /*!< [0x0004] Timer Comparator Register                             */
    __IO uint32_t INTSTS;               /*!< [0x0008] Timer Interrupt Status Register                       */
    __IO uint32_t CNT;                  /*!< [0x000c] Timer Data Register                                   */
    __I  uint32_t CAP;                  /*!< [0x0010] Timer Capture Data Register                           */
    __IO uint32_t EXTCTL;               /*!< [0x0014] Timer External Control Register                       */
    __IO uint32_t EINTSTS;              /*!< [0x0018] Timer External Interrupt Status Register              */
    __IO uint32_t TRGCTL;               /*!< [0x001c] Timer Trigger Control Register                        */
    __I  uint32_t RESERVE0[1];
    __IO uint32_t CAPNF;                /*!< [0x0024] Timer Capture Input Noise Filter Register             */
    __IO uint32_t ATRGCTL;              /*!< [0x0028] Timer Auto Operation Trigger Control Register         */
    __I  uint32_t RESERVE1[5];
    __IO uint32_t PWMCTL;               /*!< [0x0040] Timer PWM Control Register                            */
    __IO uint32_t PWMCLKPSC;            /*!< [0x0044] Timer PWM Counter Clock Pre-scale Register            */
    __IO uint32_t PWMCNTCLR;            /*!< [0x0048] Timer PWM Clear Counter Register                      */
    __IO uint32_t PWMPERIOD;            /*!< [0x004c] Timer PWM Period Register                             */
    __IO uint32_t PWMCMPDAT;            /*!< [0x0050] Timer PWM Comparator Register                         */
    __I  uint32_t PWMCNT;               /*!< [0x0054] Timer PWM Counter Register                            */
    __IO uint32_t PWMPOLCTL;            /*!< [0x0058] Timer PWM Pin Output Polar Control Register           */
    __IO uint32_t PWMPOCTL;             /*!< [0x005c] Timer PWM Pin Output Control Register                 */
    __IO uint32_t PWMINTEN0;            /*!< [0x0060] Timer PWM Interrupt Enable Register 0                 */
    __IO uint32_t PWMINTSTS0;           /*!< [0x0064] Timer PWM Interrupt Status Register 0                 */
    __IO uint32_t PWMTRGCTL;            /*!< [0x0068] Timer PWM Trigger Control Register                    */
    __IO uint32_t PWMSTATUS;            /*!< [0x006c] Timer PWM Status Register                             */
    __I  uint32_t PWMPBUF;              /*!< [0x0070] Timer PWM Period Buffer Register                      */
    __I  uint32_t PWMCMPBUF;            /*!< [0x0074] Timer PWM Comparator Buffer Register                  */
    __I  uint32_t RESERVE2[12];
    __IO uint32_t PWMIFA;               /*!< [0x00a8] Timer PWM Interrupt Flag Accumulator Register         */
    __IO uint32_t PWMAINTSTS;           /*!< [0x00ac] Timer PWM Accumulator Interrupt Flag Register         */
    __IO uint32_t PWMAINTEN;            /*!< [0x00b0] Timer PWM Accumulator Interrupt Enable Register       */
    __IO uint32_t PWMAPDMACTL;          /*!< [0x00b4] Timer PWM Accumulator PDMA Control Register           */
    __IO uint32_t PWMATRGCTL;           /*!< [0x00b8] Timer PWM Auto Operation Trigger Control Register     */
} TIMER_T;

/**
    @addtogroup TIMER_CONST TIMER Bit Field Definition
    Constant Definitions for TIMER Controller
@{ */

#define TIMER_CTL_PSC_Pos               (0)                                         /*!< TIMER_T::CTL: PSC Position                 */
#define TIMER_CTL_PSC_Msk               (0xfful << TIMER_CTL_PSC_Pos)               /*!< TIMER_T::CTL: PSC Mask                     */

#define TIMER_CTL_FUNCSEL_Pos           (15)                                        /*!< TIMER_T::CTL: FUNCSEL Position             */
#define TIMER_CTL_FUNCSEL_Msk           (0x1ul << TIMER_CTL_FUNCSEL_Pos)            /*!< TIMER_T::CTL: FUNCSEL Mask                 */

#define TIMER_CTL_PDCLKEN_Pos           (16)                                        /*!< TIMER_T::CTL: PDCLKEN Position             */
#define TIMER_CTL_PDCLKEN_Msk           (0x1ul << TIMER_CTL_PDCLKEN_Pos)            /*!< TIMER_T::CTL: PDCLKEN Mask                 */

#define TIMER_CTL_INTRGEN_Pos           (19)                                        /*!< TIMER_T::CTL: INTRGEN Position             */
#define TIMER_CTL_INTRGEN_Msk           (0x1ul << TIMER_CTL_INTRGEN_Pos)            /*!< TIMER_T::CTL: INTRGEN Mask                 */

#define TIMER_CTL_PERIOSEL_Pos          (20)                                        /*!< TIMER_T::CTL: PERIOSEL Position            */
#define TIMER_CTL_PERIOSEL_Msk          (0x1ul << TIMER_CTL_PERIOSEL_Pos)           /*!< TIMER_T::CTL: PERIOSEL Mask                */

#define TIMER_CTL_TGLPINSEL_Pos         (21)                                        /*!< TIMER_T::CTL: TGLPINSEL Position           */
#define TIMER_CTL_TGLPINSEL_Msk         (0x1ul << TIMER_CTL_TGLPINSEL_Pos)          /*!< TIMER_T::CTL: TGLPINSEL Mask               */

#define TIMER_CTL_CAPSRC_Pos            (22)                                        /*!< TIMER_T::CTL: CAPSRC Position              */
#define TIMER_CTL_CAPSRC_Msk            (0x1ul << TIMER_CTL_CAPSRC_Pos)             /*!< TIMER_T::CTL: CAPSRC Mask                  */

#define TIMER_CTL_WKEN_Pos              (23)                                        /*!< TIMER_T::CTL: WKEN Position                */
#define TIMER_CTL_WKEN_Msk              (0x1ul << TIMER_CTL_WKEN_Pos)               /*!< TIMER_T::CTL: WKEN Mask                    */

#define TIMER_CTL_EXTCNTEN_Pos          (24)                                        /*!< TIMER_T::CTL: EXTCNTEN Position            */
#define TIMER_CTL_EXTCNTEN_Msk          (0x1ul << TIMER_CTL_EXTCNTEN_Pos)           /*!< TIMER_T::CTL: EXTCNTEN Mask                */

#define TIMER_CTL_ACTSTS_Pos            (25)                                        /*!< TIMER_T::CTL: ACTSTS Position              */
#define TIMER_CTL_ACTSTS_Msk            (0x1ul << TIMER_CTL_ACTSTS_Pos)             /*!< TIMER_T::CTL: ACTSTS Mask                  */

#define TIMER_CTL_OPMODE_Pos            (27)                                        /*!< TIMER_T::CTL: OPMODE Position              */
#define TIMER_CTL_OPMODE_Msk            (0x3ul << TIMER_CTL_OPMODE_Pos)             /*!< TIMER_T::CTL: OPMODE Mask                  */

#define TIMER_CTL_INTEN_Pos             (29)                                        /*!< TIMER_T::CTL: INTEN Position               */
#define TIMER_CTL_INTEN_Msk             (0x1ul << TIMER_CTL_INTEN_Pos)              /*!< TIMER_T::CTL: INTEN Mask                   */

#define TIMER_CTL_CNTEN_Pos             (30)                                        /*!< TIMER_T::CTL: CNTEN Position               */
#define TIMER_CTL_CNTEN_Msk             (0x1ul << TIMER_CTL_CNTEN_Pos)              /*!< TIMER_T::CTL: CNTEN Mask                   */

#define TIMER_CTL_ICEDEBUG_Pos          (31)                                        /*!< TIMER_T::CTL: ICEDEBUG Position            */
#define TIMER_CTL_ICEDEBUG_Msk          (0x1ul << TIMER_CTL_ICEDEBUG_Pos)           /*!< TIMER_T::CTL: ICEDEBUG Mask                */

#define TIMER_CMP_CMPDAT_Pos            (0)                                         /*!< TIMER_T::CMP: CMPDAT Position              */
#define TIMER_CMP_CMPDAT_Msk            (0xfffffful << TIMER_CMP_CMPDAT_Pos)        /*!< TIMER_T::CMP: CMPDAT Mask                  */

#define TIMER_INTSTS_TIF_Pos            (0)                                         /*!< TIMER_T::INTSTS: TIF Position              */
#define TIMER_INTSTS_TIF_Msk            (0x1ul << TIMER_INTSTS_TIF_Pos)             /*!< TIMER_T::INTSTS: TIF Mask                  */

#define TIMER_INTSTS_TWKF_Pos           (1)                                         /*!< TIMER_T::INTSTS: TWKF Position             */
#define TIMER_INTSTS_TWKF_Msk           (0x1ul << TIMER_INTSTS_TWKF_Pos)            /*!< TIMER_T::INTSTS: TWKF Mask                 */

#define TIMER_CNT_CNT_Pos               (0)                                         /*!< TIMER_T::CNT: CNT Position                 */
#define TIMER_CNT_CNT_Msk               (0xfffffful << TIMER_CNT_CNT_Pos)           /*!< TIMER_T::CNT: CNT Mask                     */

#define TIMER_CNT_RSTACT_Pos            (31)                                        /*!< TIMER_T::CNT: RSTACT Position              */
#define TIMER_CNT_RSTACT_Msk            (0x1ul << TIMER_CNT_RSTACT_Pos)             /*!< TIMER_T::CNT: RSTACT Mask                  */

#define TIMER_CAP_CAPDAT_Pos            (0)                                         /*!< TIMER_T::CAP: CAPDAT Position              */
#define TIMER_CAP_CAPDAT_Msk            (0xfffffful << TIMER_CAP_CAPDAT_Pos)        /*!< TIMER_T::CAP: CAPDAT Mask                  */

#define TIMER_EXTCTL_CNTPHASE_Pos       (0)                                         /*!< TIMER_T::EXTCTL: CNTPHASE Position         */
#define TIMER_EXTCTL_CNTPHASE_Msk       (0x1ul << TIMER_EXTCTL_CNTPHASE_Pos)        /*!< TIMER_T::EXTCTL: CNTPHASE Mask             */

#define TIMER_EXTCTL_CAPEN_Pos          (3)                                         /*!< TIMER_T::EXTCTL: CAPEN Position            */
#define TIMER_EXTCTL_CAPEN_Msk          (0x1ul << TIMER_EXTCTL_CAPEN_Pos)           /*!< TIMER_T::EXTCTL: CAPEN Mask                */

#define TIMER_EXTCTL_CAPFUNCS_Pos       (4)                                         /*!< TIMER_T::EXTCTL: CAPFUNCS Position         */
#define TIMER_EXTCTL_CAPFUNCS_Msk       (0x1ul << TIMER_EXTCTL_CAPFUNCS_Pos)        /*!< TIMER_T::EXTCTL: CAPFUNCS Mask             */

#define TIMER_EXTCTL_CAPIEN_Pos         (5)                                         /*!< TIMER_T::EXTCTL: CAPIEN Position           */
#define TIMER_EXTCTL_CAPIEN_Msk         (0x1ul << TIMER_EXTCTL_CAPIEN_Pos)          /*!< TIMER_T::EXTCTL: CAPIEN Mask               */

#define TIMER_EXTCTL_CAPDBEN_Pos        (6)                                         /*!< TIMER_T::EXTCTL: CAPDBEN Position          */
#define TIMER_EXTCTL_CAPDBEN_Msk        (0x1ul << TIMER_EXTCTL_CAPDBEN_Pos)         /*!< TIMER_T::EXTCTL: CAPDBEN Mask              */

#define TIMER_EXTCTL_CNTDBEN_Pos        (7)                                         /*!< TIMER_T::EXTCTL: CNTDBEN Position          */
#define TIMER_EXTCTL_CNTDBEN_Msk        (0x1ul << TIMER_EXTCTL_CNTDBEN_Pos)         /*!< TIMER_T::EXTCTL: CNTDBEN Mask              */

#define TIMER_EXTCTL_INTERCAPSEL_Pos    (8)                                         /*!< TIMER_T::EXTCTL: INTERCAPSEL Position      */
#define TIMER_EXTCTL_INTERCAPSEL_Msk    (0x7ul << TIMER_EXTCTL_INTERCAPSEL_Pos)     /*!< TIMER_T::EXTCTL: INTERCAPSEL Mask          */

#define TIMER_EXTCTL_CAPEDGE_Pos        (12)                                        /*!< TIMER_T::EXTCTL: CAPEDGE Position          */
#define TIMER_EXTCTL_CAPEDGE_Msk        (0x7ul << TIMER_EXTCTL_CAPEDGE_Pos)         /*!< TIMER_T::EXTCTL: CAPEDGE Mask              */

#define TIMER_EXTCTL_ECNTSSEL_Pos       (16)                                        /*!< TIMER_T::EXTCTL: ECNTSSEL Position         */
#define TIMER_EXTCTL_ECNTSSEL_Msk       (0x7ul << TIMER_EXTCTL_ECNTSSEL_Pos)        /*!< TIMER_T::EXTCTL: ECNTSSEL Mask             */

#define TIMER_EXTCTL_CAPDIVSCL_Pos      (28)                                        /*!< TIMER_T::EXTCTL: CAPDIVSCL Position        */
#define TIMER_EXTCTL_CAPDIVSCL_Msk      (0xful << TIMER_EXTCTL_CAPDIVSCL_Pos)       /*!< TIMER_T::EXTCTL: CAPDIVSCL Mask            */

#define TIMER_EINTSTS_CAPIF_Pos         (0)                                         /*!< TIMER_T::EINTSTS: CAPIF Position           */
#define TIMER_EINTSTS_CAPIF_Msk         (0x1ul << TIMER_EINTSTS_CAPIF_Pos)          /*!< TIMER_T::EINTSTS: CAPIF Mask               */

#define TIMER_EINTSTS_CAPIFOV_Pos       (1)                                         /*!< TIMER_T::EINTSTS: CAPIFOV Position         */
#define TIMER_EINTSTS_CAPIFOV_Msk       (0x1ul << TIMER_EINTSTS_CAPIFOV_Pos)        /*!< TIMER_T::EINTSTS: CAPIFOV Mask             */

#define TIMER_TRGCTL_TRGSSEL_Pos        (0)                                         /*!< TIMER_T::TRGCTL: TRGSSEL Position          */
#define TIMER_TRGCTL_TRGSSEL_Msk        (0x1ul << TIMER_TRGCTL_TRGSSEL_Pos)         /*!< TIMER_T::TRGCTL: TRGSSEL Mask              */

#define TIMER_TRGCTL_TRGPWM_Pos         (1)                                         /*!< TIMER_T::TRGCTL: TRGPWM Position           */
#define TIMER_TRGCTL_TRGPWM_Msk         (0x1ul << TIMER_TRGCTL_TRGPWM_Pos)          /*!< TIMER_T::TRGCTL: TRGPWM Mask               */

#define TIMER_TRGCTL_TRGADC_Pos         (2)                                         /*!< TIMER_T::TRGCTL: TRGADC Position           */
#define TIMER_TRGCTL_TRGADC_Msk         (0x1ul << TIMER_TRGCTL_TRGADC_Pos)          /*!< TIMER_T::TRGCTL: TRGADC Mask               */

#define TIMER_TRGCTL_TRGPDMA_Pos        (4)                                         /*!< TIMER_T::TRGCTL: TRGPDMA Position          */
#define TIMER_TRGCTL_TRGPDMA_Msk        (0x1ul << TIMER_TRGCTL_TRGPDMA_Pos)         /*!< TIMER_T::TRGCTL: TRGPDMA Mask              */

#define TIMER_CAPNF_CAPNFEN_Pos         (0)                                         /*!< TIMER_T::CAPNF: CAPNFEN Position           */
#define TIMER_CAPNF_CAPNFEN_Msk         (0x1ul << TIMER_CAPNF_CAPNFEN_Pos)          /*!< TIMER_T::CAPNF: CAPNFEN Mask               */

#define TIMER_CAPNF_CAPNFSEL_Pos        (4)                                         /*!< TIMER_T::CAPNF: CAPNFSEL Position          */
#define TIMER_CAPNF_CAPNFSEL_Msk        (0x7ul << TIMER_CAPNF_CAPNFSEL_Pos)         /*!< TIMER_T::CAPNF: CAPNFSEL Mask              */

#define TIMER_CAPNF_CAPNFCNT_Pos        (8)                                         /*!< TIMER_T::CAPNF: CAPNFCNT Position          */
#define TIMER_CAPNF_CAPNFCNT_Msk        (0x7ul << TIMER_CAPNF_CAPNFCNT_Pos)         /*!< TIMER_T::CAPNF: CAPNFCNT Mask              */

#define TIMER_ATRGCTL_ATRGSSEL_Pos      (0)                                         /*!< TIMER_T::ATRGCTL: ATRGSSEL Position        */
#define TIMER_ATRGCTL_ATRGSSEL_Msk      (0x1ul << TIMER_ATRGCTL_ATRGSSEL_Pos)       /*!< TIMER_T::ATRGCTL: ATRGSSEL Mask            */

#define TIMER_ATRGCTL_ATRGPDMA_Pos      (4)                                         /*!< TIMER_T::ATRGCTL: ATRGPDMA Position        */
#define TIMER_ATRGCTL_ATRGPDMA_Msk      (0x1ul << TIMER_ATRGCTL_ATRGPDMA_Pos)       /*!< TIMER_T::ATRGCTL: ATRGPDMA Mask            */

#define TIMER_ATRGCTL_ATRGEN_Pos        (9)                                         /*!< TIMER_T::ATRGCTL: ATRGEN Position          */
#define TIMER_ATRGCTL_ATRGEN_Msk        (0x1ul << TIMER_ATRGCTL_ATRGEN_Pos)         /*!< TIMER_T::ATRGCTL: ATRGEN Mask              */

#define TIMER_PWMCTL_CNTEN_Pos          (0)                                         /*!< TIMER_T::PWMCTL: CNTEN Position            */
#define TIMER_PWMCTL_CNTEN_Msk          (0x1ul << TIMER_PWMCTL_CNTEN_Pos)           /*!< TIMER_T::PWMCTL: CNTEN Mask                */

#define TIMER_PWMCTL_CNTMODE_Pos        (3)                                         /*!< TIMER_T::PWMCTL: CNTMODE Position          */
#define TIMER_PWMCTL_CNTMODE_Msk        (0x1ul << TIMER_PWMCTL_CNTMODE_Pos)         /*!< TIMER_T::PWMCTL: CNTMODE Mask              */

#define TIMER_PWMCTL_PWMINTWKEN_Pos     (12)                                        /*!< TIMER_T::PWMCTL: PWMINTWKEN Position       */
#define TIMER_PWMCTL_PWMINTWKEN_Msk     (0x1ul << TIMER_PWMCTL_PWMINTWKEN_Pos)      /*!< TIMER_T::PWMCTL: PWMINTWKEN Mask           */

#define TIMER_PWMCTL_DBGHALT_Pos        (30)                                        /*!< TIMER_T::PWMCTL: DBGHALT Position          */
#define TIMER_PWMCTL_DBGHALT_Msk        (0x1ul << TIMER_PWMCTL_DBGHALT_Pos)         /*!< TIMER_T::PWMCTL: DBGHALT Mask              */

#define TIMER_PWMCTL_DBGTRIOFF_Pos      (31)                                        /*!< TIMER_T::PWMCTL: DBGTRIOFF Position        */
#define TIMER_PWMCTL_DBGTRIOFF_Msk      (0x1ul << TIMER_PWMCTL_DBGTRIOFF_Pos)       /*!< TIMER_T::PWMCTL: DBGTRIOFF Mask            */

#define TIMER_PWMCLKPSC_CLKPSC_Pos      (0)                                         /*!< TIMER_T::PWMCLKPSC: CLKPSC Position        */
#define TIMER_PWMCLKPSC_CLKPSC_Msk      (0xfful << TIMER_PWMCLKPSC_CLKPSC_Pos)      /*!< TIMER_T::PWMCLKPSC: CLKPSC Mask            */

#define TIMER_PWMCNTCLR_CNTCLR_Pos      (0)                                         /*!< TIMER_T::PWMCNTCLR: CNTCLR Position        */
#define TIMER_PWMCNTCLR_CNTCLR_Msk      (0x1ul << TIMER_PWMCNTCLR_CNTCLR_Pos)       /*!< TIMER_T::PWMCNTCLR: CNTCLR Mask            */

#define TIMER_PWMPERIOD_PERIOD_Pos      (0)                                         /*!< TIMER_T::PWMPERIOD: PERIOD Position        */
#define TIMER_PWMPERIOD_PERIOD_Msk      (0xfffful << TIMER_PWMPERIOD_PERIOD_Pos)    /*!< TIMER_T::PWMPERIOD: PERIOD Mask            */

#define TIMER_PWMCMPDAT_CMP_Pos         (0)                                         /*!< TIMER_T::PWMCMPDAT: CMP Position           */
#define TIMER_PWMCMPDAT_CMP_Msk         (0xfffful << TIMER_PWMCMPDAT_CMP_Pos)       /*!< TIMER_T::PWMCMPDAT: CMP Mask               */

#define TIMER_PWMCNT_CNT_Pos            (0)                                         /*!< TIMER_T::PWMCNT: CNT Position              */
#define TIMER_PWMCNT_CNT_Msk            (0xfffful << TIMER_PWMCNT_CNT_Pos)          /*!< TIMER_T::PWMCNT: CNT Mask                  */

#define TIMER_PWMPOLCTL_PINV_Pos        (0)                                         /*!< TIMER_T::PWMPOLCTL: PINV Position          */
#define TIMER_PWMPOLCTL_PINV_Msk        (0x1ul << TIMER_PWMPOLCTL_PINV_Pos)         /*!< TIMER_T::PWMPOLCTL: PINV Mask              */

#define TIMER_PWMPOCTL_POEN_Pos         (0)                                         /*!< TIMER_T::PWMPOCTL: POEN Position           */
#define TIMER_PWMPOCTL_POEN_Msk         (0x1ul << TIMER_PWMPOCTL_POEN_Pos)          /*!< TIMER_T::PWMPOCTL: POEN Mask               */

#define TIMER_PWMPOCTL_POSEL_Pos        (8)                                         /*!< TIMER_T::PWMPOCTL: POSEL Position          */
#define TIMER_PWMPOCTL_POSEL_Msk        (0x1ul << TIMER_PWMPOCTL_POSEL_Pos)         /*!< TIMER_T::PWMPOCTL: POSEL Mask              */

#define TIMER_PWMINTEN0_PIEN_Pos        (1)                                         /*!< TIMER_T::PWMINTEN0: PIEN Position          */
#define TIMER_PWMINTEN0_PIEN_Msk        (0x1ul << TIMER_PWMINTEN0_PIEN_Pos)         /*!< TIMER_T::PWMINTEN0: PIEN Mask              */

#define TIMER_PWMINTEN0_CMPUIEN_Pos     (2)                                         /*!< TIMER_T::PWMINTEN0: CMPUIEN Position       */
#define TIMER_PWMINTEN0_CMPUIEN_Msk     (0x1ul << TIMER_PWMINTEN0_CMPUIEN_Pos)      /*!< TIMER_T::PWMINTEN0: CMPUIEN Mask           */

#define TIMER_PWMINTSTS0_PIF_Pos        (1)                                         /*!< TIMER_T::PWMINTSTS0: PIF Position          */
#define TIMER_PWMINTSTS0_PIF_Msk        (0x1ul << TIMER_PWMINTSTS0_PIF_Pos)         /*!< TIMER_T::PWMINTSTS0: PIF Mask              */

#define TIMER_PWMINTSTS0_CMPUIF_Pos     (2)                                         /*!< TIMER_T::PWMINTSTS0: CMPUIF Position       */
#define TIMER_PWMINTSTS0_CMPUIF_Msk     (0x1ul << TIMER_PWMINTSTS0_CMPUIF_Pos)      /*!< TIMER_T::PWMINTSTS0: CMPUIF Mask           */

#define TIMER_PWMTRGCTL_TRGSEL_Pos      (0)                                         /*!< TIMER_T::PWMTRGCTL: TRGSEL Position        */
#define TIMER_PWMTRGCTL_TRGSEL_Msk      (0x3ul << TIMER_PWMTRGCTL_TRGSEL_Pos)       /*!< TIMER_T::PWMTRGCTL: TRGSEL Mask            */

#define TIMER_PWMTRGCTL_PWMTRGADC_Pos   (7)                                         /*!< TIMER_T::PWMTRGCTL: PWMTRGADC Position     */
#define TIMER_PWMTRGCTL_PWMTRGADC_Msk   (0x1ul << TIMER_PWMTRGCTL_PWMTRGADC_Pos)    /*!< TIMER_T::PWMTRGCTL: PWMTRGADC Mask         */

#define TIMER_PWMTRGCTL_PWMTRGPDMA_Pos  (9)                                         /*!< TIMER_T::PWMTRGCTL: PWMTRGPDMA Position    */
#define TIMER_PWMTRGCTL_PWMTRGPDMA_Msk  (0x1ul << TIMER_PWMTRGCTL_PWMTRGPDMA_Pos)   /*!< TIMER_T::PWMTRGCTL: PWMTRGPDMA Mask        */

#define TIMER_PWMSTATUS_CNTMAXF_Pos     (0)                                         /*!< TIMER_T::PWMSTATUS: CNTMAXF Position       */
#define TIMER_PWMSTATUS_CNTMAXF_Msk     (0x1ul << TIMER_PWMSTATUS_CNTMAXF_Pos)      /*!< TIMER_T::PWMSTATUS: CNTMAXF Mask           */

#define TIMER_PWMSTATUS_PWMINTWKF_Pos   (8)                                         /*!< TIMER_T::PWMSTATUS: PWMINTWKF Position     */
#define TIMER_PWMSTATUS_PWMINTWKF_Msk   (0x1ul << TIMER_PWMSTATUS_PWMINTWKF_Pos)    /*!< TIMER_T::PWMSTATUS: PWMINTWKF Mask         */

#define TIMER_PWMSTATUS_ADCTRGF_Pos     (16)                                        /*!< TIMER_T::PWMSTATUS: ADCTRGF Position       */
#define TIMER_PWMSTATUS_ADCTRGF_Msk     (0x1ul << TIMER_PWMSTATUS_ADCTRGF_Pos)      /*!< TIMER_T::PWMSTATUS: ADCTRGF Mask           */

#define TIMER_PWMSTATUS_PDMATRGF_Pos    (18)                                        /*!< TIMER_T::PWMSTATUS: PDMATRGF Position      */
#define TIMER_PWMSTATUS_PDMATRGF_Msk    (0x1ul << TIMER_PWMSTATUS_PDMATRGF_Pos)     /*!< TIMER_T::PWMSTATUS: PDMATRGF Mask          */

#define TIMER_PWMPBUF_PBUF_Pos          (0)                                         /*!< TIMER_T::PWMPBUF: PBUF Position            */
#define TIMER_PWMPBUF_PBUF_Msk          (0xfffful << TIMER_PWMPBUF_PBUF_Pos)        /*!< TIMER_T::PWMPBUF: PBUF Mask                */

#define TIMER_PWMCMPBUF_CMPBUF_Pos      (0)                                         /*!< TIMER_T::PWMCMPBUF: CMPBUF Position        */
#define TIMER_PWMCMPBUF_CMPBUF_Msk      (0xfffful << TIMER_PWMCMPBUF_CMPBUF_Pos)    /*!< TIMER_T::PWMCMPBUF: CMPBUF Mask            */

#define TIMER_PWMIFA_IFACNT_Pos         (0)                                         /*!< TIMER_T::PWMIFA: IFACNT Position           */
#define TIMER_PWMIFA_IFACNT_Msk         (0xfffful << TIMER_PWMIFA_IFACNT_Pos)       /*!< TIMER_T::PWMIFA: IFACNT Mask               */

#define TIMER_PWMIFA_STPMOD_Pos         (24)                                        /*!< TIMER_T::PWMIFA: STPMOD Position           */
#define TIMER_PWMIFA_STPMOD_Msk         (0x1ul << TIMER_PWMIFA_STPMOD_Pos)          /*!< TIMER_T::PWMIFA: STPMOD Mask               */

#define TIMER_PWMIFA_IFASEL_Pos         (28)                                        /*!< TIMER_T::PWMIFA: IFASEL Position           */
#define TIMER_PWMIFA_IFASEL_Msk         (0x3ul << TIMER_PWMIFA_IFASEL_Pos)          /*!< TIMER_T::PWMIFA: IFASEL Mask               */

#define TIMER_PWMIFA_IFAEN_Pos          (31)                                        /*!< TIMER_T::PWMIFA: IFAEN Position            */
#define TIMER_PWMIFA_IFAEN_Msk          (0x1ul << TIMER_PWMIFA_IFAEN_Pos)           /*!< TIMER_T::PWMIFA: IFAEN Mask                */

#define TIMER_PWMAINTSTS_IFAIF_Pos      (0)                                         /*!< TIMER_T::PWMAINTSTS: IFAIF Position        */
#define TIMER_PWMAINTSTS_IFAIF_Msk      (0x1ul << TIMER_PWMAINTSTS_IFAIF_Pos)       /*!< TIMER_T::PWMAINTSTS: IFAIF Mask            */

#define TIMER_PWMAINTEN_IFAIEN_Pos      (0)                                         /*!< TIMER_T::PWMAINTEN: IFAIEN Position        */
#define TIMER_PWMAINTEN_IFAIEN_Msk      (0x1ul << TIMER_PWMAINTEN_IFAIEN_Pos)       /*!< TIMER_T::PWMAINTEN: IFAIEN Mask            */

#define TIMER_PWMAPDMACTL_APDMAEN_Pos   (0)                                         /*!< TIMER_T::PWMAPDMACTL: APDMAEN Position     */
#define TIMER_PWMAPDMACTL_APDMAEN_Msk   (0x1ul << TIMER_PWMAPDMACTL_APDMAEN_Pos)    /*!< TIMER_T::PWMAPDMACTL: APDMAEN Mask         */

#define TIMER_PWMAPDMACTL_AEPDMA_Pos    (1)                                         /*!< TIMER_T::PWMAPDMACTL: AEPDMA Position      */
#define TIMER_PWMAPDMACTL_AEPDMA_Msk    (0x1ul << TIMER_PWMAPDMACTL_AEPDMA_Pos)     /*!< TIMER_T::PWMAPDMACTL: AEPDMA Mask          */

#define TIMER_PWMATRGCTL_ATRGSEL_Pos    (0)                                         /*!< TIMER_T::PWMATRGCTL: ATRGSEL Position      */
#define TIMER_PWMATRGCTL_ATRGSEL_Msk    (0x3ul << TIMER_PWMATRGCTL_ATRGSEL_Pos)     /*!< TIMER_T::PWMATRGCTL: ATRGSEL Mask          */

#define TIMER_PWMATRGCTL_PWMATRGEN_Pos  (2)                                         /*!< TIMER_T::PWMATRGCTL: PWMATRGEN Position    */
#define TIMER_PWMATRGCTL_PWMATRGEN_Msk  (0x1ul << TIMER_PWMATRGCTL_PWMATRGEN_Pos)   /*!< TIMER_T::PWMATRGCTL: PWMATRGEN Mask        */

#define TIMER_PWMATRGCTL_PWMATRGPDMA_Pos    (9)                                         /*!< TIMER_T::PWMATRGCTL: PWMATRGPDMA Position  */
#define TIMER_PWMATRGCTL_PWMATRGPDMA_Msk    (0x1ul << TIMER_PWMATRGCTL_PWMATRGPDMA_Pos) /*!< TIMER_T::PWMATRGCTL: PWMATRGPDMA Mask      */

/**@}*/ /* TIMER_CONST */
/**@}*/ /* end of TIMER register group */
/**@}*/ /* end of REGISTER group */

#if defined ( __CC_ARM   )
#pragma no_anon_unions
#endif

#endif /* __TIMER_REG_H__ */
