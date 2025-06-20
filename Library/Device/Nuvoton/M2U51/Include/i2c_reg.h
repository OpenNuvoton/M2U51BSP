/**************************************************************************//**
 * @file     i2c_reg.h
 * @version  V1.00
 * @brief    I2C register definition header file
 *
 * SPDX-License-Identifier: Apache-2.0
 * @copyright (C) 2025 Nuvoton Technology Corp. All rights reserved.
 *****************************************************************************/
#ifndef __I2C_REG_H__
#define __I2C_REG_H__

#if defined ( __CC_ARM   )
#pragma anon_unions
#endif

/** @addtogroup REGISTER Control Register

  @{

*/


/*---------------------- Inter-IC Bus Controller -------------------------*/
/**
    @addtogroup I2C Inter-IC Bus Controller(I2C)
    Memory Mapped Structure for I2C Controller
@{ */

typedef struct
{


    /**
     * @var I2C_T::CTL0
     * Offset: 0x00  I2C Control Register 0
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[2]     |AA        |Assert Acknowledge Control
     * |        |          |When AA =1 prior to address or data is received, an acknowledged (low level to SDA) will be returned during the acknowledge clock pulse on the SCL line when 1.) A slave is acknowledging the address sent from master, 2.) The receiver devices are acknowledging the data sent by transmitter
     * |        |          |When AA=0 prior to address or data received, a Not acknowledged (high level to SDA) will be returned during the acknowledge clock pulse on the SCL line
     * |[3]     |SI        |I2C Interrupt Flag
     * |        |          |When a new I2C state is present in the I2C_STATUS0 register, the SI flag is set by hardware
     * |        |          |If bit INTEN (I2C_CTL0 [7]) is set, the I2C interrupt is requested
     * |        |          |SI must be cleared by software
     * |        |          |Clear SI by writing 1 to this bit.
     * |        |          |For ACKMEN is set in slave read mode, the SI flag is set in 8th clock period for user to confirm the acknowledge bit and 9th clock period for user to read the data in the data buffer.
     * |[4]     |STO       |I2C STOP Control
     * |        |          |In Master mode, setting STO to transmit a STOP condition to bus then I2C controller will check the bus condition if a STOP condition is detected
     * |        |          |This bit will be cleared by hardware automatically.
     * |[5]     |STA       |I2C START Control
     * |        |          |Setting STA to logic 1 to enter Master mode, the I2C hardware sends a START or repeat START condition to bus when the bus is free
     * |        |          |This bit will be cleared by hardware automatically.
     * |[6]     |I2CEN     |I2C Controller Enable Bit
     * |        |          |Set to enable I2C serial function controller
     * |        |          |When I2CEN=1 the I2C serial function enable
     * |        |          |The multi-function pin function must set to SDA, and SCL of I2C function first.
     * |        |          |0 = I2C controller Disabled.
     * |        |          |1 = I2C controller Enabled.
     * |[7]     |INTEN     |Enable Interrupt
     * |        |          |0 = I2C interrupt Disabled.
     * |        |          |1 = I2C interrupt Enabled.
     * @var I2C_T::ADDR0
     * Offset: 0x04  I2C Slave Address Register0
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |GC        |General Call Function
     * |        |          |0 = General Call Function Disabled.
     * |        |          |1 = General Call Function Enabled.
     * |[10:1]  |ADDR      |I2C Address
     * |        |          |The content of this register is irrelevant when I2C is in Master mode
     * |        |          |In the slave mode, the seven most significant bits must be loaded with the chip's own address
     * |        |          |The I2C hardware will react if either of the address is matched.
     * |        |          |Note: When software set 10'h000, the address cannot be used.
     * @var I2C_T::DAT
     * Offset: 0x08  I2C Data Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[7:0]   |DAT       |I2C Data
     * |        |          |Bit [7:0] is located with the 8-bit transferred/received data of I2C serial port.
     * @var I2C_T::STATUS0
     * Offset: 0x0C  I2C Status Register 0
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[7:0]   |STATUS    |I2C Status
     * |        |          |The three least significant bits are always 0
     * |        |          |The five most significant bits contain the status code
     * |        |          |There are 28 possible status codes
     * |        |          |When the content of I2C_STATUS0 is F8H, no serial interrupt is requested
     * |        |          |Others I2C_STATUS0 values correspond to defined I2C states
     * |        |          |When each of these states is entered, a status interrupt is requested (SI = 1)
     * |        |          |A valid status code is present in I2C_STATUS0 one cycle after SI is set by hardware and is still present one cycle after SI has been reset by software
     * |        |          |In addition, states 00H stands for a Bus Error
     * |        |          |A Bus Error occurs when a START or STOP condition is present at an illegal position in the formation frame
     * |        |          |Example of illegal position are during the serial transfer of an address byte, a data byte or an acknowledge bit.
     * @var I2C_T::CLKDIV
     * Offset: 0x10  I2C Clock Divided Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[9:0]   |DIVIDER   |I2C Clock Divided
     * |        |          |Indicates the I2C clock rate: Data Baud Rate of I2C = (system clock) / (4x (DIVIDER+1)).
     * |        |          |Note: The minimum value of DIVIDER is 4.
     * |[15:12] |NFCNT     |Noise Filter Count
     * |        |          |The register bits control the input filter width
     * |        |          |If the pulse width is narrower than the setting((3+N)*PCLK), it will be ignored.
     * |        |          |0 : filter width 3*PCLK
     * |        |          |1 : filter width 4*PCLK
     * |        |          |N : filter width (3+N)*PCKL
     * |        |          |Note: Filter width Min :3*PCLK, Max : 18*PCLK
     * @var I2C_T::TOCTL
     * Offset: 0x14  I2C Time-out Control Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |TOIF      |Time-out Flag
     * |        |          |This bit is set by hardware when I2C time-out happened and it can interrupt CPU if I2C interrupt enable bit (INTEN) is set to 1.
     * |        |          |Note: Software can write 1 to clear this bit.
     * |[1]     |TOCDIV4   |Time-out Counter Input Clock Divided by 4
     * |        |          |When enabled, the time-out period is extended 4 times.
     * |        |          |0 = Time-out period is extend 4 times Disabled.
     * |        |          |1 = Time-out period is extend 4 times Enabled.
     * |[2]     |TOCEN     |Time-out Counter Enable Bit
     * |        |          |When enabled, the 14-bit time-out counter will start counting when SI is cleared
     * |        |          |Setting flag SI to '1' will reset counter and re-start up counting after SI is cleared.
     * |        |          |0 = Time-out counter Disabled.
     * |        |          |1 = Time-out counter Enabled.
     * |[3]     |TOBAUD    |Time-out Counter Input Clock Using Baud Rate Frequency
     * |        |          |When enabled, the time-out counter is using baud rate.
     * |        |          |0 = Time-out counter is using PCLK or PCLK/4.
     * |        |          |1 = Time-out counter is using I&sup2;C baud rate.
     * |[8]     |TONIDLE   |Time-out Counter Disable in IDLE State
     * |        |          |When set 1,Time-out counter will stop.
     * |        |          |0 = Timeout counter enable when in IDLE state
     * |        |          |1 = Timeout counter disable when in IDLE state
     * @var I2C_T::ADDR1
     * Offset: 0x18  I2C Slave Address Register1
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |GC        |General Call Function
     * |        |          |0 = General Call Function Disabled.
     * |        |          |1 = General Call Function Enabled.
     * |[10:1]  |ADDR      |I2C Address
     * |        |          |The content of this register is irrelevant when I2C is in Master mode
     * |        |          |In the slave mode, the seven most significant bits must be loaded with the chip's own address
     * |        |          |The I2C hardware will react if either of the address is matched.
     * |        |          |Note: When software set 10'h000, the address cannot be used.
     * @var I2C_T::ADDR2
     * Offset: 0x1C  I2C Slave Address Register2
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |GC        |General Call Function
     * |        |          |0 = General Call Function Disabled.
     * |        |          |1 = General Call Function Enabled.
     * |[10:1]  |ADDR      |I2C Address
     * |        |          |The content of this register is irrelevant when I2C is in Master mode
     * |        |          |In the slave mode, the seven most significant bits must be loaded with the chip's own address
     * |        |          |The I2C hardware will react if either of the address is matched.
     * |        |          |Note: When software set 10'h000, the address cannot be used.
     * @var I2C_T::ADDR3
     * Offset: 0x20  I2C Slave Address Register3
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |GC        |General Call Function
     * |        |          |0 = General Call Function Disabled.
     * |        |          |1 = General Call Function Enabled.
     * |[10:1]  |ADDR      |I2C Address
     * |        |          |The content of this register is irrelevant when I2C is in Master mode
     * |        |          |In the slave mode, the seven most significant bits must be loaded with the chip's own address
     * |        |          |The I2C hardware will react if either of the address is matched.
     * |        |          |Note: When software set 10'h000, the address cannot be used.
     * @var I2C_T::ADDRMSK0
     * Offset: 0x24  I2C Slave Address Mask Register0
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[10:1]  |ADDRMSK   |I2C Address Mask
     * |        |          |0 = Mask Disabled (the received corresponding register bit should be exact the same as address register.).
     * |        |          |1 = Mask Enabled (the received corresponding address bit is don't care.).
     * |        |          |I2C bus controllers support multiple address recognition with four address mask register
     * |        |          |When the bit in the address mask register is set to one, it means the received corresponding address bit is don't-care
     * |        |          |If the bit is set to zero, that means the received corresponding register bit should be exact the same as address register.
     * |        |          |Note: The wake-up function cannot use address mask in 10-bit mode.
     * @var I2C_T::ADDRMSK1
     * Offset: 0x28  I2C Slave Address Mask Register1
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[10:1]  |ADDRMSK   |I2C Address Mask
     * |        |          |0 = Mask Disabled (the received corresponding register bit should be exact the same as address register.).
     * |        |          |1 = Mask Enabled (the received corresponding address bit is don't care.).
     * |        |          |I2C bus controllers support multiple address recognition with four address mask register
     * |        |          |When the bit in the address mask register is set to one, it means the received corresponding address bit is don't-care
     * |        |          |If the bit is set to zero, that means the received corresponding register bit should be exact the same as address register.
     * |        |          |Note: The wake-up function cannot use address mask in 10-bit mode.
     * @var I2C_T::ADDRMSK2
     * Offset: 0x2C  I2C Slave Address Mask Register2
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[10:1]  |ADDRMSK   |I2C Address Mask
     * |        |          |0 = Mask Disabled (the received corresponding register bit should be exact the same as address register.).
     * |        |          |1 = Mask Enabled (the received corresponding address bit is don't care.).
     * |        |          |I2C bus controllers support multiple address recognition with four address mask register
     * |        |          |When the bit in the address mask register is set to one, it means the received corresponding address bit is don't-care
     * |        |          |If the bit is set to zero, that means the received corresponding register bit should be exact the same as address register.
     * |        |          |Note: The wake-up function cannot use address mask in 10-bit mode.
     * @var I2C_T::ADDRMSK3
     * Offset: 0x30  I2C Slave Address Mask Register3
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[10:1]  |ADDRMSK   |I2C Address Mask
     * |        |          |0 = Mask Disabled (the received corresponding register bit should be exact the same as address register.).
     * |        |          |1 = Mask Enabled (the received corresponding address bit is don't care.).
     * |        |          |I2C bus controllers support multiple address recognition with four address mask register
     * |        |          |When the bit in the address mask register is set to one, it means the received corresponding address bit is don't-care
     * |        |          |If the bit is set to zero, that means the received corresponding register bit should be exact the same as address register.
     * |        |          |Note: The wake-up function cannot use address mask in 10-bit mode.
     * @var I2C_T::WKCTL
     * Offset: 0x3C  I2C Wake-up Control Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |WKEN      |I2C Wake-up Enable Bit
     * |        |          |0 = I2C wake-up function Disabled.
     * |        |          |1= I2C wake-up function Enabled.
     * |[7]     |NHDBUSEN  |I2C No Hold BUS Enable Bit
     * |        |          |0 = I2C hold bus after wake-up.
     * |        |          |1= I2C don't hold bus after wake-up.
     * |        |          |Note: The I2C controller could respond when WKIF event is not clear, it may cause error data transmitted or received
     * |        |          |If data transmitted or received when WKIF event is not clear, user must reset I2C controller and execute the original operation again.
     * @var I2C_T::WKSTS
     * Offset: 0x40  I2C Wake-up Status Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |WKIF      |I2C Wake-up Flag
     * |        |          |When chip is woken up from Power-down mode by I2C, this bit is set to 1
     * |        |          |Software can write 1 to clear this bit.
     * |[1]     |WKAKDONE  |Wakeup Address Frame Acknowledge Bit Done
     * |        |          |0 = The ACK bit cycle of address match frame isn't done.
     * |        |          |1 = The ACK bit cycle of address match frame is done in power-down.
     * |        |          |Note: This bit can't release WKIF. Software can write 1 to clear this bit.
     * |[2]     |WRSTSWK   |Read/Write Status Bit in Address Wakeup Frame
     * |        |          |0 = Write command be record on the address match wakeup frame.
     * |        |          |1 = Read command be record on the address match wakeup frame.
     * |        |          |Note: This bit will be cleared when software can write 1 to WKAKDONE bit.
     * @var I2C_T::CTL1
     * Offset: 0x44  I2C Control Register 1
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |TXPDMAEN  |PDMA Transmit Channel Available
     * |        |          |0 = Transmit PDMA function Disabled.
     * |        |          |1 = Transmit PDMA function Enabled.
     * |[1]     |RXPDMAEN  |PDMA Receive Channel Available
     * |        |          |0 = Receive PDMA function Disabled.
     * |        |          |1 = Receive PDMA function Enabled.
     * |[2]     |PDMARST   |PDMA Reset
     * |        |          |0 = No effect.
     * |        |          |1 = Reset the I2C request to PDMA.
     * |[3]     |OVRIEN    |I2C Over Run Interrupt Control Bit
     * |        |          |Setting OVRIEN to logic 1 will send a interrupt to system when the TWOBUFEN bit is enabled and there is over run event in received buffer.
     * |[4]     |UDRIEN    |I2C Under Run Interrupt Control Bit
     * |        |          |Setting UDRIEN to logic 1 will send a interrupt to system when the TWOBUFEN bit is enabled and there is under run event happened in transmitted buffer.
     * |[5]     |TWOBUFEN  |Two-level Buffer Enable Bit
     * |        |          |0 = Two-level buffer Disabled.
     * |        |          |1 = Two-level buffer Enabled.
     * |        |          |Set to enable the two-level buffer for I2C transmitted or received buffer
     * |        |          |It is used to improve the performance of the I2C bus
     * |[6]     |BUFRST    |Two-level Buffer Reset
     * |        |          |0 = No effect.
     * |        |          |1 = Reset the related counters, two-level buffer state machine, and the content of data buffer.
     * |[7]     |NSTRETCH  |No Stretch on the I2C Bus
     * |        |          |0 = The I2C SCL bus is stretched by hardware if the SI is not cleared in master mode.
     * |        |          |1 = The I2C SCL bus is not stretched by hardware if the SI is not cleared in master mode.
     * |[8]     |PDMASTR   |PDMA Stretch Bit
     * |        |          |0 = I2C send STOP automatically after PDMA transfer done. (only master TX)
     * |        |          |1 = I2C SCL bus is stretched by hardware after PDMA transfer done if the SI is not cleared
     * |        |          |(only master TX)
     * |[9]     |ADDR10EN  |Address 10-bit Function Enable Bit
     * |        |          |0 = Address match 10-bit function Disabled.
     * |        |          |1 = Address match 10-bit function Enabled.
     * |[10]    |SWITCHEN  |SCL And SDA Pin Switch Enable Bit
     * |        |          |0 = I2C use original pin configuration.
     * |        |          |1 = I2C switch SCL and SDA pin configuration.
     * |        |          |Note: Original pin configuration table is shown in Basic Configuration chapter.
     * |[17:16] |DPBITSEL  |Data Phase Bit Count Select
     * |        |          |00 = DPCIF never set by hardware.
     * |        |          |01 = When I2C is transfer data and bit count equal to 6, DPCIF will be set by hardware.
     * |        |          |10 = When I2C is transfer data and bit count equal to 7, DPCIF will be set by hardware.
     * |        |          |11 = When I2C is transfer data and bit count equal to 8, DPCIF will be set by hardware.
     * |[20]    |DPCINTEN  |Data Phase Count Interrupt Enable Bit
     * |        |          |0 = Data Phase Count Interrupt Disabled.
     * |        |          |1 = Data Phase Count Interrupt Enabled.
     * |[21]    |SRCINTEN  |Slave Read Command Interrupt Enable Bit
     * |        |          |0 = Slave Read Command Interrupt Disabled.
     * |        |          |1 = Slave Read Command Interrupt Enabled.
     * @var I2C_T::STATUS1
     * Offset: 0x48  I2C Status Register 1
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |ADMAT0    |I2C Address 0 Match Status
     * |        |          |When address 0 is matched, hardware will inform which address used
     * |        |          |This bit will set to 1, and software can write 1 to clear this bit.
     * |[1]     |ADMAT1    |I2C Address 1 Match Status
     * |        |          |When address 1 is matched, hardware will inform which address used
     * |        |          |This bit will set to 1, and software can write 1 to clear this bit.
     * |[2]     |ADMAT2    |I2C Address 2 Match Status
     * |        |          |When address 2 is matched, hardware will inform which address used
     * |        |          |This bit will set to 1, and software can write 1 to clear this bit.
     * |[3]     |ADMAT3    |I2C Address 3 Match Status
     * |        |          |When address 3 is matched, hardware will inform which address used
     * |        |          |This bit will set to 1, and software can write 1 to clear this bit.
     * |[4]     |FULL      |TWO-LEVEL BUFFER FULL
     * |        |          |This bit indicates two-level buffer TX or RX full or not when the TWOBUFEN = 1.
     * |        |          |This bit is set when POINTER is equal to 2
     * |        |          |Note: This bit is read only.
     * |[5]     |EMPTY     |TWO-LEVEL BUFFER EMPTY
     * |        |          |This bit indicates two-level buffer TX or RX empty or not when the TWOBUFEN = 1.
     * |        |          |This bit is set when POINTER is equal to 0.
     * |        |          |Note: This bit is read only.
     * |[6]     |OVR       |I2C Over Run Status Bit
     * |        |          |This bit indicates the received two-level buffer TX or RX is over run when the TWOBUFEN = 1.
     * |        |          |Note: This bit is read only.
     * |[7]     |UDR       |I2C Under Run Status Bit
     * |        |          |This bit indicates the transmitted two-level buffer TX or RX is under run when the TWOBUFEN = 1.
     * |        |          |Note: This bit is read only.
     * |[8]     |ONBUSY    |On Bus Busy (Read Only)
     * |        |          |Indicates that a communication is in progress on the bus
     * |        |          |It is set by hardware when a START condition is detected
     * |        |          |It is cleared by hardware when a STOP condition is detected.
     * |        |          |0 = The bus is IDLE (both SCL and SDA High).
     * |        |          |1 = The bus is busy.
     * |[20]    |DPCIF     |Data Phase Count Interrupt Flag
     * |        |          |This bit is set by hardware when I2C transfer bit count equal to DPBITSEL setting
     * |        |          |This bit is cleared by write 1 to it.
     * |[21]    |SARCIF    |Slave Address Read Command Interrupt Flag
     * |        |          |This bit is set by hardware when I2C receive address match read command.
     * |        |          |This bit is cleared by write 1 to it.
     * @var I2C_T::TMCTL
     * Offset: 0x4C  I2C Timing Configure Control Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[8:0]   |STCTL     |Setup Time Configure Control
     * |        |          |This field is used to generate a delay timing between SDA falling edge and SCL rising edge in transmission mode.
     * |        |          |The delay setup time is numbers of peripheral clock = STCTL x PCLK.
     * |        |          |Note: Setup time setting should not make SCL output less than three PCLKs.
     * |[24:16] |HTCTL     |Hold Time Configure Control
     * |        |          |This field is used to generate the delay timing between SCL falling edge and SDA rising edge in transmission mode.
     * |        |          |The delay hold time is numbers of peripheral clock = HTCTL x PCLK.
     * @var I2C_T::BUSCTL
     * Offset: 0x50  I2C Bus Management Control Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |ACKMEN    |Acknowledge Control by Manual
     * |        |          |In order to allow ACK control in slave reception including the command and data, slave byte control mode must be enabled by setting the ACKMEN bit.
     * |        |          |0 = Slave byte control Disabled.
     * |        |          |1 = Slave byte control Enabled
     * |        |          |The 9th bit can response the ACK or NACK according the received data by user
     * |        |          |When the byte is received, stretching the SCL signal low between the 8th and 9th SCL pulse.
     * |        |          |Note: If the BMDEN =1 and this bit is enabled, the information of I2C_STATUS0 will be fixed as 0xF0 in slave receive condition.
     * |[1]     |PECEN     |Packet Error Checking Calculation Enable Bit
     * |        |          |0 = Packet Error Checking Calculation Disabled.
     * |        |          |1 = Packet Error Checking Calculation Enabled.
     * |        |          |Note: When I2C enter power-down mode, the bit should be enabled after wake-up if needed PEC calculation.
     * |[2]     |BMDEN     |Bus Management Device Default Address Enable Bit
     * |        |          |0 = Device default address Disable
     * |        |          |When the address 0'b1100001x comes and either BMDEN or ACKMEN is disabled, the device responses NACK.
     * |        |          |1 = Device default address Enabled
     * |        |          |When the address 0'b1100001x comes and both BMDEN and ACKMEN are enabled, the device responses ACK.
     * |[3]     |BMHEN     |Bus Management Host Enable Bit
     * |        |          |0 = Host function Disabled.
     * |        |          |1 = Host function Enabled.
     * |[4]     |ALERTEN   |Bus Management Alert Enable Bit
     * |        |          |Device Mode (BMHEN =0).
     * |        |          |0 = Release the BM_ALERT pin high and Alert Response Header disabled: 0001100x followed by NACK if both of BMDEN and ACKMEN are enabled.
     * |        |          |1 = Drive BM_ALERT pin low and Alert Response Address Header enables: 0001100x followed by ACK if both of BMDEN and ACKMEN are enabled.
     * |        |          |Host Mode (BMHEN =1).
     * |        |          |0 = BM_ALERT pin not supported.
     * |        |          |1 = BM_ALERT pin supported.
     * |[5]     |SCTLOSTS  |Suspend/Control Data Output Status
     * |        |          |0 = The output of SUSCON pin is low.
     * |        |          |1 = The output of SUSCON pin is high.
     * |[6]     |SCTLOEN   |Suspend or Control Pin Output Enable Bit
     * |        |          |0 = The SUSCON pin in input.
     * |        |          |1 = The output enable is active on the SUSCON pin.
     * |[7]     |BUSEN     |BUS Enable Bit
     * |        |          |0 = The system management function Disabled.
     * |        |          |1 = The system management function Enabled.
     * |        |          |Note: When the bit is enabled, the internal 14-bit counter is used to calculate the time out event of clock low condition.
     * |[8]     |PECTXEN   |Packet Error Checking Byte Transmission/Reception
     * |        |          |0 = No PEC transfer.
     * |        |          |1 = PEC transmission is requested.
     * |        |          |Note: 1.This bit has no effect in slave mode when ACKMEN =0.
     * |[9]     |TIDLE     |Timer Check in Idle State
     * |        |          |The BUSTOUT is used to calculate the time-out of clock low in bus active and the idle period in bus Idle
     * |        |          |This bit is used to define which condition is enabled.
     * |        |          |0 = BUSTOUT is used to calculate the clock low period in bus active.
     * |        |          |1 = BUSTOUT is used to calculate the IDLE period in bus Idle.
     * |        |          |Note: The BUSY (I2C_BUSSTS[0]) indicate the current bus state.
     * |[10]    |PECCLR    |PEC Clear at Repeat Start
     * |        |          |The calculation of PEC starts when PECEN is set to 1 and it is cleared when the STA or STO bit is detected
     * |        |          |This PECCLR bit is used to enable the condition of REPEAT START can clear the PEC calculation.
     * |        |          |0 = PEC calculation is cleared by "Repeat Start" function Disabled.
     * |        |          |1 = PEC calculation is cleared by "Repeat Start" function Enabled.
     * |[11]    |ACKM9SI   |Acknowledge Manual Enable Extra SI Interrupt
     * |        |          |0 = There is no SI interrupt in the 9th clock cycle when the BUSEN =1 and ACKMEN =1.
     * |        |          |1 = There is SI interrupt in the 9th clock cycle when the BUSEN =1 and ACKMEN =1.
     * |[12]    |BCDIEN    |Packet Error Checking Byte Count Done Interrupt Enable Bit
     * |        |          |0 = Byte count done interrupt Disabled.
     * |        |          |1 = Byte count done interrupt Enabled.
     * |        |          |Note: This bit is used in PECEN =1.
     * |[13]    |PECDIEN   |Packet Error Checking Byte Transfer Done Interrupt Enable Bit
     * |        |          |0 = PEC transfer done interrupt Disabled.
     * |        |          |1 = PEC transfer done interrupt Enabled.
     * |        |          |Note: This bit is used in PECEN =1.
     * @var I2C_T::BUSTCTL
     * Offset: 0x54  I2C Bus Management Timer Control Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |BUSTOEN   |Bus Time Out Enable Bit
     * |        |          |0 = Bus clock low time-out detection Disabled.
     * |        |          |1 = Bus clock low time-out detection Enabled (bus clock is low for more than BUSTO (I2C_BUSTOUT[7:0]) (in TIDLE=0) or high more than BUSTO (in TIDLE =1)
     * |[1]     |CLKTOEN   |Cumulative Clock Low Time Out Enable Bit
     * |        |          |0 = Cumulative clock low time-out detection Disabled.
     * |        |          |1 = Cumulative clock low time-out detection Enabled.
     * |        |          |For Master, it calculates the period from START to ACK
     * |        |          |For Slave, it calculates the period from START to STOP
     * |[2]     |BUSTOIEN  |Time-out Interrupt Enable Bit
     * |        |          |BUSY =1.
     * |        |          |0 = SCL low time-out interrupt Disabled.
     * |        |          |1 = SCL low time-out interrupt Enabled.
     * |        |          |BUSY =0.
     * |        |          |0 = Bus IDLE time-out interrupt Disabled.
     * |        |          |1 = Bus IDLE time-out interrupt Enabled.
     * |[3]     |CLKTOIEN  |Extended Clock Time Out Interrupt Enable Bit
     * |        |          |0 = Clock time out interrupt Disabled.
     * |        |          |1 = Clock time out interrupt Enabled.
     * |[4]     |TORSTEN   |Time Out Reset Enable Bit
     * |        |          |0 = I2C state machine reset Disabled.
     * |        |          |1 = I2C state machine reset Enabled. (The clock and data bus will be released to high)
     * @var I2C_T::BUSSTS
     * Offset: 0x58  I2C Bus Management Status Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |BUSY      |Bus Busy (Read Only)
     * |        |          |Indicates that a communication is in progress on the bus
     * |        |          |It is set by hardware when a START condition is detected
     * |        |          |It is cleared by hardware when a STOP condition is detected
     * |        |          |0 = Bus is IDLE (both SCL and SDA High).
     * |        |          |1 = Bus is busy.
     * |        |          |Note: This bit is read only.
     * |[1]     |BCDONE    |Byte Count Transmission/Receive Done
     * |        |          |0 = Byte count transmission/ receive is not finished when the PECEN is set.
     * |        |          |1 = Byte count transmission/ receive is finished when the PECEN is set.
     * |        |          |Note: Software can write 1 to clear this bit.
     * |[2]     |PECERR    |PEC Error in Reception
     * |        |          |0 = PEC value equal the received PEC data packet.
     * |        |          |1 = PEC value doesn't match the receive PEC data packet.
     * |        |          |Note: Software can write 1 to clear this bit.
     * |[3]     |ALERT     |SMBus Alert Status
     * |        |          |Device Mode (BMHEN =0).
     * |        |          |0 = SMBALERT pin state is low.
     * |        |          |1 = SMBALERT pin state is high.
     * |        |          |Host Mode (BMHEN =1).
     * |        |          |0 = No SMBALERT event.
     * |        |          |1 = There is SMBALERT event (falling edge) is detected in SMALERT pin when the BMHEN = 1 (SMBus host configuration) and the ALERTEN = 1.
     * |        |          |Note: 1. The SMBALERT pin is an open-drain pin, the pull-high resistor is must in the system. 2. Software can write 1 to clear this bit.
     * |[4]     |SCTLDIN   |Bus Suspend or Control Signal Input Status (Read Only)
     * |        |          |0 = The input status of SUSCON pin is 0.
     * |        |          |1 = The input status of SUSCON pin is 1.
     * |        |          |Note: This bit is read only.
     * |[5]     |BUSTO     |Bus Time-out Status
     * |        |          |0 = There is no any time-out or external clock time-out.
     * |        |          |1 = A time-out or external clock time-out occurred.
     * |        |          |In bus busy, the bit indicates the total clock low time-out event occurred; otherwise, it indicates the bus idle time-out event occurred.
     * |        |          |Note: Software can write 1 to clear this bit.
     * |[6]     |CLKTO     |Clock Low Cumulate Time-out Status
     * |        |          |0 = Cumulative clock low is no any time-out.
     * |        |          |1 = Cumulative clock low time-out occurred.
     * |        |          |Note: Software can write 1 to clear this bit.
     * |[7]     |PECDONE   |PEC Byte Transmission/Receive Done
     * |        |          |0 = PEC transmission/ receive is not finished when the PECEN is set.
     * |        |          |1 = PEC transmission/ receive is finished when the PECEN is set.
     * |        |          |Note: Software can write 1 to clear this bit.
     * @var I2C_T::PKTSIZE
     * Offset: 0x5C  I2C Packet Error Checking Byte Number Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[8:0]   |PLDSIZE   |Transfer Byte Number
     * |        |          |The transmission or receive byte number in one transaction when the PECEN is set
     * |        |          |The maximum transaction or receive byte is 256 Bytes.
     * |        |          |Note: The byte number counting includes address, command code, and data frame.
     * @var I2C_T::PKTCRC
     * Offset: 0x60  I2C Packet Error Checking Byte Value Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[7:0]   |PECCRC    |Packet Error Checking Byte Value
     * |        |          |This byte indicates the packet error checking content after transmission or receive byte count by using the C(x) = x8 + x2 + x + 1
     * |        |          |It is read only.
     * @var I2C_T::BUSTOUT
     * Offset: 0x64  I2C Bus Management Timer Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[7:0]   |BUSTO     |Bus Management Time-out Value
     * |        |          |Indicates the bus time-out value in bus is IDLE or SCL low.
     * |        |          |Note: If the user wants to revise the value of BUSTOUT, the TORSTEN (I2C_BUSTCTL[4]) bit shall be set to 1 and cleared to 0 first when the BUSEN(I2C_BUSCTL[7]) is set.
     * @var I2C_T::CLKTOUT
     * Offset: 0x68  I2C Bus Management Clock Low Timer Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[7:0]   |CLKTO     |Bus Clock Low Timer
     * |        |          |The field is used to configure the cumulative clock extension time-out.
     * |        |          |Note: If the user wants to revise the value of CLKTOUT, the TORSTEN bit shall be set to 1 and cleared to 0 first when the BUSEN is set.
     * @var I2C_T::AUTOCTL
     * Offset: 0x70  I2C Automatic Operation Control Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[3:0]   |TGSRCSEL  |Auto-operation Trigger Source Select
     * |        |          |0000 = Auto-operation Trigger Source from TMR0.
     * |        |          |0001 = Auto-operation Trigger Source from TMR1.
     * |        |          |0010 = Auto-operation Trigger Source from TMR2.
     * |        |          |0011 = Auto-operation Trigger Source from TMR3.
     * |        |          |0100 = Auto-operation Trigger Source from WKIOA0(GPA0).
     * |        |          |0101 = Auto-operation Trigger Source from WKIOB0(GPB0).
     * |        |          |0110 = Auto-operation Trigger Source from WKIOC0(GPC0).
     * |        |          |0111 = Auto-operation Trigger Source from WKIOD0(GPD0).
     * |        |          |1000 = Auto-operation Trigger Source from Software setting SWTRG(I2C_AUTOCTL[31]) to 1.
     * |        |          |1001~1111 = Reserved.
     * |[4]     |TRGEN     |Trigger Source Enable bit
     * |        |          |0 = I&sup2;C trigger source disable.
     * |        |          |1 = I&sup2;C trigger source enable.
     * |[5]     |TXWKEN    |TX Transfer Count Match Wakeup Enable bit
     * |        |          |0 = Power off after TX transfer count matches TXCNT.
     * |        |          |1 = Wakeup after TX transfer count matches TXCNT.
     * |[6]     |RXWKEN    |RX Transfer Count Match Wakeup Enable bit
     * |        |          |0 = Power off after RX transfer count matches RXCNT.
     * |        |          |1 = Wakeup after RX transfer count matches RXCNT.
     * |[7]     |NACKWKEN  |Receive Slave NACK Wakeup Enable bit
     * |        |          |0 = Stop after receiving NACK.
     * |        |          |1 = Wakeup after receiving NACK.
     * |[10:8]  |AUTOMODE  |Auto-operation Mode Select
     * |        |          |000 = No auto-operation.
     * |        |          |001 = Auto TXPDMA transfer mode.
     * |        |          |010 = Auto RXPDMA transfer mode.
     * |        |          |011 = Random Read mode, repeat start between TX/RX.
     * |        |          |100 = Random Read mode, stop and start between TX/RX.
     * |        |          |Others = Reserved.
     * |        |          |Note: Use TXWKEN(I2C_AUTOCTL[5]) to wakeup system when using auto TXPDMA transfer mode AUTOMODE(I2C_AUTOCTL[10:8]) in power-down mode.
     * |[31]    |SWTRG     |Auto-operation Mode Software Trigger Bit
     * |        |          |0 = No operation.
     * |        |          |1 = Software trigger auto-operattion.
     * |        |          |Note: TGSRCSEL(I2C_AUTOCTL[3:0]) need to be set to 0x8 first
     * |        |          |This bit will be cleared by hardware automatically.
     * @var I2C_T::AUTOSTS
     * Offset: 0x74  I2C Automatic Operation Status Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |TXWKF     |TX Transfer Count Match Wakeup Flag
     * |        |          |When chip is woken up from Power-down mode by I2C TX transfer count match, this bit is set to 1
     * |        |          |Software can write 1 to clear this bit.
     * |[1]     |RXWKF     |RX Transfer Count Match Wakeup Flag
     * |        |          |When chip is woken up from Power-down mode by I2C RX transfer count match, this bit is set to 1
     * |        |          |Software can write 1 to clear this bit.
     * |[2]     |ERRORWKF  |Error Condition Wakeup Flag
     * |        |          |When chip is woken up from Power-down mode by I2C receiving NACK from slave, running into bus error or arbitration lost, this bit is set to 1
     * |        |          |Software can write 1 to clear this bit.
     * |[8]     |TXFINISH  |Automatic Operation TX Finish Flag
     * |        |          |AOFINISH is set when finishing one round of auto operation(Automode = 1), but it will not issue interrupt
     * |        |          |Software can write 1 to clear this bit.
     * |[9]     |RXFINISH  |Automatic Operation RX Finish Flag
     * |        |          |RXFINISH is set when finishing one round of auto operation(Automode = 2/3/4), but it will not issue interrupt
     * |        |          |Software can write 1 to clear this bit.
     * |[10]    |ERRORIF   |ERROR Interrupt Flag
     * |        |          |When I2C receiving NACK from slave, running into bus error or arbitration lost, this bit is set to 1
     * |        |          |Software can write 1 to clear this bit.
     * |[24]    |AOFINISH  |Automatic Operation Finish Flag
     * |        |          |AOFINISH is set when finishing one round of auto operation, but it will not issue interrupt
     * |        |          |Software can write 1 to clear this bit.
     * |[31]    |BUSY      |Busy Flag
     * |        |          |When chip is woken up and this bit is set to 1
     * |        |          |It means that there were one or more requests from trigger source during transfer
     * |        |          |Software can write 1 to clear this bit.
     * @var I2C_T::AUTOCNT
     * Offset: 0x78  I2C Automatic Operation Transfer Count Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[7:0]   |TXCNT     |TX Transfer Count
     * |        |          |Bit [7:0] is set for TXPDMA and Random Read transfer mode
     * |        |          |TXCNT represents the required number of the transfer, the real transfer count is TXCNT + 1
     * |        |          |The maximum transfer count is 255 + 1.
     * |[23:16] |RXCNT     |RX Transfer Count
     * |        |          |Bit [23:16] is set for RXPDMA and Random Read transfer mode
     * |        |          |RXCNT represents the required number of the transfer, the real transfer count is RXCNT + 1
     * |        |          |The maximum transfer count is 255 + 1.
     */
    __IO uint32_t CTL0;                  /*!< [0x0000] I2C Control Register 0                                           */
    __IO uint32_t ADDR0;                 /*!< [0x0004] I2C Slave Address Register0                                      */
    __IO uint32_t DAT;                   /*!< [0x0008] I2C Data Register                                                */
    __I  uint32_t STATUS0;               /*!< [0x000c] I2C Status Register 0                                            */
    __IO uint32_t CLKDIV;                /*!< [0x0010] I2C Clock Divided Register                                       */
    __IO uint32_t TOCTL;                 /*!< [0x0014] I2C Time-out Control Register                                    */
    __IO uint32_t ADDR1;                 /*!< [0x0018] I2C Slave Address Register1                                      */
    __IO uint32_t ADDR2;                 /*!< [0x001c] I2C Slave Address Register2                                      */
    __IO uint32_t ADDR3;                 /*!< [0x0020] I2C Slave Address Register3                                      */
    __IO uint32_t ADDRMSK0;              /*!< [0x0024] I2C Slave Address Mask Register0                                 */
    __IO uint32_t ADDRMSK1;              /*!< [0x0028] I2C Slave Address Mask Register1                                 */
    __IO uint32_t ADDRMSK2;              /*!< [0x002c] I2C Slave Address Mask Register2                                 */
    __IO uint32_t ADDRMSK3;              /*!< [0x0030] I2C Slave Address Mask Register3                                 */
    __I  uint32_t RESERVE0[2];
    __IO uint32_t WKCTL;                 /*!< [0x003c] I2C Wake-up Control Register                                     */
    __IO uint32_t WKSTS;                 /*!< [0x0040] I2C Wake-up Status Register                                      */
    __IO uint32_t CTL1;                  /*!< [0x0044] I2C Control Register 1                                           */
    __IO uint32_t STATUS1;               /*!< [0x0048] I2C Status Register 1                                            */
    __IO uint32_t TMCTL;                 /*!< [0x004c] I2C Timing Configure Control Register                            */
    __IO uint32_t BUSCTL;                /*!< [0x0050] I2C Bus Management Control Register                              */
    __IO uint32_t BUSTCTL;               /*!< [0x0054] I2C Bus Management Timer Control Register                        */
    __IO uint32_t BUSSTS;                /*!< [0x0058] I2C Bus Management Status Register                               */
    __IO uint32_t PKTSIZE;               /*!< [0x005c] I2C Packet Error Checking Byte Number Register                   */
    __I  uint32_t PKTCRC;                /*!< [0x0060] I2C Packet Error Checking Byte Value Register                    */
    __IO uint32_t BUSTOUT;               /*!< [0x0064] I2C Bus Management Timer Register                                */
    __IO uint32_t CLKTOUT;               /*!< [0x0068] I2C Bus Management Clock Low Timer Register                      */
    __I  uint32_t RESERVE1[1];
    __IO uint32_t AUTOCTL;               /*!< [0x0070] I2C Automatic Operation Control Register                         */
    __IO uint32_t AUTOSTS;               /*!< [0x0074] I2C Automatic Operation Status Register                          */
    __IO uint32_t AUTOCNT;               /*!< [0x0078] I2C Automatic Operation Transfer Count Register                  */

} I2C_T;

/**
    @addtogroup I2C_CONST I2C Bit Field Definition
    Constant Definitions for I2C Controller
@{ */

#define I2C_CTL0_AA_Pos                  (2)                                               /*!< I2C_T::CTL0: AA Position               */
#define I2C_CTL0_AA_Msk                  (0x1ul << I2C_CTL0_AA_Pos)                        /*!< I2C_T::CTL0: AA Mask                   */

#define I2C_CTL0_SI_Pos                  (3)                                               /*!< I2C_T::CTL0: SI Position               */
#define I2C_CTL0_SI_Msk                  (0x1ul << I2C_CTL0_SI_Pos)                        /*!< I2C_T::CTL0: SI Mask                   */

#define I2C_CTL0_STO_Pos                 (4)                                               /*!< I2C_T::CTL0: STO Position              */
#define I2C_CTL0_STO_Msk                 (0x1ul << I2C_CTL0_STO_Pos)                       /*!< I2C_T::CTL0: STO Mask                  */

#define I2C_CTL0_STA_Pos                 (5)                                               /*!< I2C_T::CTL0: STA Position              */
#define I2C_CTL0_STA_Msk                 (0x1ul << I2C_CTL0_STA_Pos)                       /*!< I2C_T::CTL0: STA Mask                  */

#define I2C_CTL0_I2CEN_Pos               (6)                                               /*!< I2C_T::CTL0: I2CEN Position            */
#define I2C_CTL0_I2CEN_Msk               (0x1ul << I2C_CTL0_I2CEN_Pos)                     /*!< I2C_T::CTL0: I2CEN Mask                */

#define I2C_CTL0_INTEN_Pos               (7)                                               /*!< I2C_T::CTL0: INTEN Position            */
#define I2C_CTL0_INTEN_Msk               (0x1ul << I2C_CTL0_INTEN_Pos)                     /*!< I2C_T::CTL0: INTEN Mask                */

#define I2C_ADDR0_GC_Pos                 (0)                                               /*!< I2C_T::ADDR0: GC Position              */
#define I2C_ADDR0_GC_Msk                 (0x1ul << I2C_ADDR0_GC_Pos)                       /*!< I2C_T::ADDR0: GC Mask                  */

#define I2C_ADDR0_ADDR_Pos               (1)                                               /*!< I2C_T::ADDR0: ADDR Position            */
#define I2C_ADDR0_ADDR_Msk               (0x3fful << I2C_ADDR0_ADDR_Pos)                   /*!< I2C_T::ADDR0: ADDR Mask                */

#define I2C_DAT_DAT_Pos                  (0)                                               /*!< I2C_T::DAT: DAT Position               */
#define I2C_DAT_DAT_Msk                  (0xfful << I2C_DAT_DAT_Pos)                       /*!< I2C_T::DAT: DAT Mask                   */

#define I2C_STATUS0_STATUS_Pos           (0)                                               /*!< I2C_T::STATUS0: STATUS Position        */
#define I2C_STATUS0_STATUS_Msk           (0xfful << I2C_STATUS0_STATUS_Pos)                /*!< I2C_T::STATUS0: STATUS Mask            */

#define I2C_CLKDIV_DIVIDER_Pos           (0)                                               /*!< I2C_T::CLKDIV: DIVIDER Position        */
#define I2C_CLKDIV_DIVIDER_Msk           (0x3fful << I2C_CLKDIV_DIVIDER_Pos)               /*!< I2C_T::CLKDIV: DIVIDER Mask            */

#define I2C_CLKDIV_NFCNT_Pos             (12)                                              /*!< I2C_T::CLKDIV: NFCNT Position          */
#define I2C_CLKDIV_NFCNT_Msk             (0xful << I2C_CLKDIV_NFCNT_Pos)                   /*!< I2C_T::CLKDIV: NFCNT Mask              */

#define I2C_TOCTL_TOIF_Pos               (0)                                               /*!< I2C_T::TOCTL: TOIF Position            */
#define I2C_TOCTL_TOIF_Msk               (0x1ul << I2C_TOCTL_TOIF_Pos)                     /*!< I2C_T::TOCTL: TOIF Mask                */

#define I2C_TOCTL_TOCDIV4_Pos            (1)                                               /*!< I2C_T::TOCTL: TOCDIV4 Position         */
#define I2C_TOCTL_TOCDIV4_Msk            (0x1ul << I2C_TOCTL_TOCDIV4_Pos)                  /*!< I2C_T::TOCTL: TOCDIV4 Mask             */

#define I2C_TOCTL_TOCEN_Pos              (2)                                               /*!< I2C_T::TOCTL: TOCEN Position           */
#define I2C_TOCTL_TOCEN_Msk              (0x1ul << I2C_TOCTL_TOCEN_Pos)                    /*!< I2C_T::TOCTL: TOCEN Mask               */

#define I2C_TOCTL_TOBAUD_Pos             (3)                                               /*!< I2C_T::TOCTL: TOBAUD Position          */
#define I2C_TOCTL_TOBAUD_Msk             (0x1ul << I2C_TOCTL_TOBAUD_Pos)                   /*!< I2C_T::TOCTL: TOBAUD Mask              */

#define I2C_TOCTL_TONIDLE_Pos            (8)                                               /*!< I2C_T::TOCTL: TONIDLE Position         */
#define I2C_TOCTL_TONIDLE_Msk            (0x1ul << I2C_TOCTL_TONIDLE_Pos)                  /*!< I2C_T::TOCTL: TONIDLE Mask             */

#define I2C_ADDR1_GC_Pos                 (0)                                               /*!< I2C_T::ADDR1: GC Position              */
#define I2C_ADDR1_GC_Msk                 (0x1ul << I2C_ADDR1_GC_Pos)                       /*!< I2C_T::ADDR1: GC Mask                  */

#define I2C_ADDR1_ADDR_Pos               (1)                                               /*!< I2C_T::ADDR1: ADDR Position            */
#define I2C_ADDR1_ADDR_Msk               (0x3fful << I2C_ADDR1_ADDR_Pos)                   /*!< I2C_T::ADDR1: ADDR Mask                */

#define I2C_ADDR2_GC_Pos                 (0)                                               /*!< I2C_T::ADDR2: GC Position              */
#define I2C_ADDR2_GC_Msk                 (0x1ul << I2C_ADDR2_GC_Pos)                       /*!< I2C_T::ADDR2: GC Mask                  */

#define I2C_ADDR2_ADDR_Pos               (1)                                               /*!< I2C_T::ADDR2: ADDR Position            */
#define I2C_ADDR2_ADDR_Msk               (0x3fful << I2C_ADDR2_ADDR_Pos)                   /*!< I2C_T::ADDR2: ADDR Mask                */

#define I2C_ADDR3_GC_Pos                 (0)                                               /*!< I2C_T::ADDR3: GC Position              */
#define I2C_ADDR3_GC_Msk                 (0x1ul << I2C_ADDR3_GC_Pos)                       /*!< I2C_T::ADDR3: GC Mask                  */

#define I2C_ADDR3_ADDR_Pos               (1)                                               /*!< I2C_T::ADDR3: ADDR Position            */
#define I2C_ADDR3_ADDR_Msk               (0x3fful << I2C_ADDR3_ADDR_Pos)                   /*!< I2C_T::ADDR3: ADDR Mask                */

#define I2C_ADDRMSK0_ADDRMSK_Pos         (1)                                               /*!< I2C_T::ADDRMSK0: ADDRMSK Position      */
#define I2C_ADDRMSK0_ADDRMSK_Msk         (0x3fful << I2C_ADDRMSK0_ADDRMSK_Pos)             /*!< I2C_T::ADDRMSK0: ADDRMSK Mask          */

#define I2C_ADDRMSK1_ADDRMSK_Pos         (1)                                               /*!< I2C_T::ADDRMSK1: ADDRMSK Position      */
#define I2C_ADDRMSK1_ADDRMSK_Msk         (0x3fful << I2C_ADDRMSK1_ADDRMSK_Pos)             /*!< I2C_T::ADDRMSK1: ADDRMSK Mask          */

#define I2C_ADDRMSK2_ADDRMSK_Pos         (1)                                               /*!< I2C_T::ADDRMSK2: ADDRMSK Position      */
#define I2C_ADDRMSK2_ADDRMSK_Msk         (0x3fful << I2C_ADDRMSK2_ADDRMSK_Pos)             /*!< I2C_T::ADDRMSK2: ADDRMSK Mask          */

#define I2C_ADDRMSK3_ADDRMSK_Pos         (1)                                               /*!< I2C_T::ADDRMSK3: ADDRMSK Position      */
#define I2C_ADDRMSK3_ADDRMSK_Msk         (0x3fful << I2C_ADDRMSK3_ADDRMSK_Pos)             /*!< I2C_T::ADDRMSK3: ADDRMSK Mask          */

#define I2C_WKCTL_WKEN_Pos               (0)                                               /*!< I2C_T::WKCTL: WKEN Position            */
#define I2C_WKCTL_WKEN_Msk               (0x1ul << I2C_WKCTL_WKEN_Pos)                     /*!< I2C_T::WKCTL: WKEN Mask                */

#define I2C_WKCTL_NHDBUSEN_Pos           (7)                                               /*!< I2C_T::WKCTL: NHDBUSEN Position        */
#define I2C_WKCTL_NHDBUSEN_Msk           (0x1ul << I2C_WKCTL_NHDBUSEN_Pos)                 /*!< I2C_T::WKCTL: NHDBUSEN Mask            */

#define I2C_WKSTS_WKIF_Pos               (0)                                               /*!< I2C_T::WKSTS: WKIF Position            */
#define I2C_WKSTS_WKIF_Msk               (0x1ul << I2C_WKSTS_WKIF_Pos)                     /*!< I2C_T::WKSTS: WKIF Mask                */

#define I2C_WKSTS_WKAKDONE_Pos           (1)                                               /*!< I2C_T::WKSTS: WKAKDONE Position        */
#define I2C_WKSTS_WKAKDONE_Msk           (0x1ul << I2C_WKSTS_WKAKDONE_Pos)                 /*!< I2C_T::WKSTS: WKAKDONE Mask            */

#define I2C_WKSTS_WRSTSWK_Pos            (2)                                               /*!< I2C_T::WKSTS: WRSTSWK Position         */
#define I2C_WKSTS_WRSTSWK_Msk            (0x1ul << I2C_WKSTS_WRSTSWK_Pos)                  /*!< I2C_T::WKSTS: WRSTSWK Mask             */

#define I2C_CTL1_TXPDMAEN_Pos            (0)                                               /*!< I2C_T::CTL1: TXPDMAEN Position         */
#define I2C_CTL1_TXPDMAEN_Msk            (0x1ul << I2C_CTL1_TXPDMAEN_Pos)                  /*!< I2C_T::CTL1: TXPDMAEN Mask             */

#define I2C_CTL1_RXPDMAEN_Pos            (1)                                               /*!< I2C_T::CTL1: RXPDMAEN Position         */
#define I2C_CTL1_RXPDMAEN_Msk            (0x1ul << I2C_CTL1_RXPDMAEN_Pos)                  /*!< I2C_T::CTL1: RXPDMAEN Mask             */

#define I2C_CTL1_PDMARST_Pos             (2)                                               /*!< I2C_T::CTL1: PDMARST Position          */
#define I2C_CTL1_PDMARST_Msk             (0x1ul << I2C_CTL1_PDMARST_Pos)                   /*!< I2C_T::CTL1: PDMARST Mask              */

#define I2C_CTL1_OVRIEN_Pos              (3)                                               /*!< I2C_T::CTL1: OVRIEN Position           */
#define I2C_CTL1_OVRIEN_Msk              (0x1ul << I2C_CTL1_OVRIEN_Pos)                    /*!< I2C_T::CTL1: OVRIEN Mask               */

#define I2C_CTL1_UDRIEN_Pos              (4)                                               /*!< I2C_T::CTL1: UDRIEN Position           */
#define I2C_CTL1_UDRIEN_Msk              (0x1ul << I2C_CTL1_UDRIEN_Pos)                    /*!< I2C_T::CTL1: UDRIEN Mask               */

#define I2C_CTL1_TWOBUFEN_Pos            (5)                                               /*!< I2C_T::CTL1: TWOBUFEN Position         */
#define I2C_CTL1_TWOBUFEN_Msk            (0x1ul << I2C_CTL1_TWOBUFEN_Pos)                  /*!< I2C_T::CTL1: TWOBUFEN Mask             */

#define I2C_CTL1_BUFRST_Pos              (6)                                               /*!< I2C_T::CTL1: BUFRST Position           */
#define I2C_CTL1_BUFRST_Msk              (0x1ul << I2C_CTL1_BUFRST_Pos)                    /*!< I2C_T::CTL1: BUFRST Mask               */

#define I2C_CTL1_NSTRETCH_Pos            (7)                                               /*!< I2C_T::CTL1: NSTRETCH Position         */
#define I2C_CTL1_NSTRETCH_Msk            (0x1ul << I2C_CTL1_NSTRETCH_Pos)                  /*!< I2C_T::CTL1: NSTRETCH Mask             */

#define I2C_CTL1_PDMASTR_Pos             (8)                                               /*!< I2C_T::CTL1: PDMASTR Position          */
#define I2C_CTL1_PDMASTR_Msk             (0x1ul << I2C_CTL1_PDMASTR_Pos)                   /*!< I2C_T::CTL1: PDMASTR Mask              */

#define I2C_CTL1_ADDR10EN_Pos            (9)                                               /*!< I2C_T::CTL1: ADDR10EN Position         */
#define I2C_CTL1_ADDR10EN_Msk            (0x1ul << I2C_CTL1_ADDR10EN_Pos)                  /*!< I2C_T::CTL1: ADDR10EN Mask             */

#define I2C_CTL1_SWITCHEN_Pos            (10)                                              /*!< I2C_T::CTL1: SWITCHEN Position         */
#define I2C_CTL1_SWITCHEN_Msk            (0x1ul << I2C_CTL1_SWITCHEN_Pos)                  /*!< I2C_T::CTL1: SWITCHEN Mask             */

#define I2C_CTL1_DPBITSEL_Pos            (16)                                              /*!< I2C_T::CTL1: DPBITSEL Position         */
#define I2C_CTL1_DPBITSEL_Msk            (0x3ul << I2C_CTL1_DPBITSEL_Pos)                  /*!< I2C_T::CTL1: DPBITSEL Mask             */

#define I2C_CTL1_DPCINTEN_Pos            (20)                                              /*!< I2C_T::CTL1: DPCINTEN Position         */
#define I2C_CTL1_DPCINTEN_Msk            (0x1ul << I2C_CTL1_DPCINTEN_Pos)                  /*!< I2C_T::CTL1: DPCINTEN Mask             */

#define I2C_CTL1_SRCINTEN_Pos            (21)                                              /*!< I2C_T::CTL1: SRCINTEN Position         */
#define I2C_CTL1_SRCINTEN_Msk            (0x1ul << I2C_CTL1_SRCINTEN_Pos)                  /*!< I2C_T::CTL1: SRCINTEN Mask             */

#define I2C_STATUS1_ADMAT0_Pos           (0)                                               /*!< I2C_T::STATUS1: ADMAT0 Position        */
#define I2C_STATUS1_ADMAT0_Msk           (0x1ul << I2C_STATUS1_ADMAT0_Pos)                 /*!< I2C_T::STATUS1: ADMAT0 Mask            */

#define I2C_STATUS1_ADMAT1_Pos           (1)                                               /*!< I2C_T::STATUS1: ADMAT1 Position        */
#define I2C_STATUS1_ADMAT1_Msk           (0x1ul << I2C_STATUS1_ADMAT1_Pos)                 /*!< I2C_T::STATUS1: ADMAT1 Mask            */

#define I2C_STATUS1_ADMAT2_Pos           (2)                                               /*!< I2C_T::STATUS1: ADMAT2 Position        */
#define I2C_STATUS1_ADMAT2_Msk           (0x1ul << I2C_STATUS1_ADMAT2_Pos)                 /*!< I2C_T::STATUS1: ADMAT2 Mask            */

#define I2C_STATUS1_ADMAT3_Pos           (3)                                               /*!< I2C_T::STATUS1: ADMAT3 Position        */
#define I2C_STATUS1_ADMAT3_Msk           (0x1ul << I2C_STATUS1_ADMAT3_Pos)                 /*!< I2C_T::STATUS1: ADMAT3 Mask            */

#define I2C_STATUS1_FULL_Pos             (4)                                               /*!< I2C_T::STATUS1: FULL Position          */
#define I2C_STATUS1_FULL_Msk             (0x1ul << I2C_STATUS1_FULL_Pos)                   /*!< I2C_T::STATUS1: FULL Mask              */

#define I2C_STATUS1_EMPTY_Pos            (5)                                               /*!< I2C_T::STATUS1: EMPTY Position         */
#define I2C_STATUS1_EMPTY_Msk            (0x1ul << I2C_STATUS1_EMPTY_Pos)                  /*!< I2C_T::STATUS1: EMPTY Mask             */

#define I2C_STATUS1_OVR_Pos              (6)                                               /*!< I2C_T::STATUS1: OVR Position           */
#define I2C_STATUS1_OVR_Msk              (0x1ul << I2C_STATUS1_OVR_Pos)                    /*!< I2C_T::STATUS1: OVR Mask               */

#define I2C_STATUS1_UDR_Pos              (7)                                               /*!< I2C_T::STATUS1: UDR Position           */
#define I2C_STATUS1_UDR_Msk              (0x1ul << I2C_STATUS1_UDR_Pos)                    /*!< I2C_T::STATUS1: UDR Mask               */

#define I2C_STATUS1_ONBUSY_Pos           (8)                                               /*!< I2C_T::STATUS1: ONBUSY Position        */
#define I2C_STATUS1_ONBUSY_Msk           (0x1ul << I2C_STATUS1_ONBUSY_Pos)                 /*!< I2C_T::STATUS1: ONBUSY Mask            */

#define I2C_STATUS1_DPCIF_Pos            (20)                                              /*!< I2C_T::STATUS1: DPCIF Position         */
#define I2C_STATUS1_DPCIF_Msk            (0x1ul << I2C_STATUS1_DPCIF_Pos)                  /*!< I2C_T::STATUS1: DPCIF Mask             */

#define I2C_STATUS1_SARCIF_Pos           (21)                                              /*!< I2C_T::STATUS1: SARCIF Position        */
#define I2C_STATUS1_SARCIF_Msk           (0x1ul << I2C_STATUS1_SARCIF_Pos)                 /*!< I2C_T::STATUS1: SARCIF Mask            */

#define I2C_TMCTL_STCTL_Pos              (0)                                               /*!< I2C_T::TMCTL: STCTL Position           */
#define I2C_TMCTL_STCTL_Msk              (0x1fful << I2C_TMCTL_STCTL_Pos)                  /*!< I2C_T::TMCTL: STCTL Mask               */

#define I2C_TMCTL_HTCTL_Pos              (16)                                              /*!< I2C_T::TMCTL: HTCTL Position           */
#define I2C_TMCTL_HTCTL_Msk              (0x1fful << I2C_TMCTL_HTCTL_Pos)                  /*!< I2C_T::TMCTL: HTCTL Mask               */

#define I2C_BUSCTL_ACKMEN_Pos            (0)                                               /*!< I2C_T::BUSCTL: ACKMEN Position         */
#define I2C_BUSCTL_ACKMEN_Msk            (0x1ul << I2C_BUSCTL_ACKMEN_Pos)                  /*!< I2C_T::BUSCTL: ACKMEN Mask             */

#define I2C_BUSCTL_PECEN_Pos             (1)                                               /*!< I2C_T::BUSCTL: PECEN Position          */
#define I2C_BUSCTL_PECEN_Msk             (0x1ul << I2C_BUSCTL_PECEN_Pos)                   /*!< I2C_T::BUSCTL: PECEN Mask              */

#define I2C_BUSCTL_BMDEN_Pos             (2)                                               /*!< I2C_T::BUSCTL: BMDEN Position          */
#define I2C_BUSCTL_BMDEN_Msk             (0x1ul << I2C_BUSCTL_BMDEN_Pos)                   /*!< I2C_T::BUSCTL: BMDEN Mask              */

#define I2C_BUSCTL_BMHEN_Pos             (3)                                               /*!< I2C_T::BUSCTL: BMHEN Position          */
#define I2C_BUSCTL_BMHEN_Msk             (0x1ul << I2C_BUSCTL_BMHEN_Pos)                   /*!< I2C_T::BUSCTL: BMHEN Mask              */

#define I2C_BUSCTL_ALERTEN_Pos           (4)                                               /*!< I2C_T::BUSCTL: ALERTEN Position        */
#define I2C_BUSCTL_ALERTEN_Msk           (0x1ul << I2C_BUSCTL_ALERTEN_Pos)                 /*!< I2C_T::BUSCTL: ALERTEN Mask            */

#define I2C_BUSCTL_SCTLOSTS_Pos          (5)                                               /*!< I2C_T::BUSCTL: SCTLOSTS Position       */
#define I2C_BUSCTL_SCTLOSTS_Msk          (0x1ul << I2C_BUSCTL_SCTLOSTS_Pos)                /*!< I2C_T::BUSCTL: SCTLOSTS Mask           */

#define I2C_BUSCTL_SCTLOEN_Pos           (6)                                               /*!< I2C_T::BUSCTL: SCTLOEN Position        */
#define I2C_BUSCTL_SCTLOEN_Msk           (0x1ul << I2C_BUSCTL_SCTLOEN_Pos)                 /*!< I2C_T::BUSCTL: SCTLOEN Mask            */

#define I2C_BUSCTL_BUSEN_Pos             (7)                                               /*!< I2C_T::BUSCTL: BUSEN Position          */
#define I2C_BUSCTL_BUSEN_Msk             (0x1ul << I2C_BUSCTL_BUSEN_Pos)                   /*!< I2C_T::BUSCTL: BUSEN Mask              */

#define I2C_BUSCTL_PECTXEN_Pos           (8)                                               /*!< I2C_T::BUSCTL: PECTXEN Position        */
#define I2C_BUSCTL_PECTXEN_Msk           (0x1ul << I2C_BUSCTL_PECTXEN_Pos)                 /*!< I2C_T::BUSCTL: PECTXEN Mask            */

#define I2C_BUSCTL_TIDLE_Pos             (9)                                               /*!< I2C_T::BUSCTL: TIDLE Position          */
#define I2C_BUSCTL_TIDLE_Msk             (0x1ul << I2C_BUSCTL_TIDLE_Pos)                   /*!< I2C_T::BUSCTL: TIDLE Mask              */

#define I2C_BUSCTL_PECCLR_Pos            (10)                                              /*!< I2C_T::BUSCTL: PECCLR Position         */
#define I2C_BUSCTL_PECCLR_Msk            (0x1ul << I2C_BUSCTL_PECCLR_Pos)                  /*!< I2C_T::BUSCTL: PECCLR Mask             */

#define I2C_BUSCTL_ACKM9SI_Pos           (11)                                              /*!< I2C_T::BUSCTL: ACKM9SI Position        */
#define I2C_BUSCTL_ACKM9SI_Msk           (0x1ul << I2C_BUSCTL_ACKM9SI_Pos)                 /*!< I2C_T::BUSCTL: ACKM9SI Mask            */

#define I2C_BUSCTL_BCDIEN_Pos            (12)                                              /*!< I2C_T::BUSCTL: BCDIEN Position         */
#define I2C_BUSCTL_BCDIEN_Msk            (0x1ul << I2C_BUSCTL_BCDIEN_Pos)                  /*!< I2C_T::BUSCTL: BCDIEN Mask             */

#define I2C_BUSCTL_PECDIEN_Pos           (13)                                              /*!< I2C_T::BUSCTL: PECDIEN Position        */
#define I2C_BUSCTL_PECDIEN_Msk           (0x1ul << I2C_BUSCTL_PECDIEN_Pos)                 /*!< I2C_T::BUSCTL: PECDIEN Mask            */

#define I2C_BUSTCTL_BUSTOEN_Pos          (0)                                               /*!< I2C_T::BUSTCTL: BUSTOEN Position       */
#define I2C_BUSTCTL_BUSTOEN_Msk          (0x1ul << I2C_BUSTCTL_BUSTOEN_Pos)                /*!< I2C_T::BUSTCTL: BUSTOEN Mask           */

#define I2C_BUSTCTL_CLKTOEN_Pos          (1)                                               /*!< I2C_T::BUSTCTL: CLKTOEN Position       */
#define I2C_BUSTCTL_CLKTOEN_Msk          (0x1ul << I2C_BUSTCTL_CLKTOEN_Pos)                /*!< I2C_T::BUSTCTL: CLKTOEN Mask           */

#define I2C_BUSTCTL_BUSTOIEN_Pos         (2)                                               /*!< I2C_T::BUSTCTL: BUSTOIEN Position      */
#define I2C_BUSTCTL_BUSTOIEN_Msk         (0x1ul << I2C_BUSTCTL_BUSTOIEN_Pos)               /*!< I2C_T::BUSTCTL: BUSTOIEN Mask          */

#define I2C_BUSTCTL_CLKTOIEN_Pos         (3)                                               /*!< I2C_T::BUSTCTL: CLKTOIEN Position      */
#define I2C_BUSTCTL_CLKTOIEN_Msk         (0x1ul << I2C_BUSTCTL_CLKTOIEN_Pos)               /*!< I2C_T::BUSTCTL: CLKTOIEN Mask          */

#define I2C_BUSTCTL_TORSTEN_Pos          (4)                                               /*!< I2C_T::BUSTCTL: TORSTEN Position       */
#define I2C_BUSTCTL_TORSTEN_Msk          (0x1ul << I2C_BUSTCTL_TORSTEN_Pos)                /*!< I2C_T::BUSTCTL: TORSTEN Mask           */

#define I2C_BUSSTS_BUSY_Pos              (0)                                               /*!< I2C_T::BUSSTS: BUSY Position           */
#define I2C_BUSSTS_BUSY_Msk              (0x1ul << I2C_BUSSTS_BUSY_Pos)                    /*!< I2C_T::BUSSTS: BUSY Mask               */

#define I2C_BUSSTS_BCDONE_Pos            (1)                                               /*!< I2C_T::BUSSTS: BCDONE Position         */
#define I2C_BUSSTS_BCDONE_Msk            (0x1ul << I2C_BUSSTS_BCDONE_Pos)                  /*!< I2C_T::BUSSTS: BCDONE Mask             */

#define I2C_BUSSTS_PECERR_Pos            (2)                                               /*!< I2C_T::BUSSTS: PECERR Position         */
#define I2C_BUSSTS_PECERR_Msk            (0x1ul << I2C_BUSSTS_PECERR_Pos)                  /*!< I2C_T::BUSSTS: PECERR Mask             */

#define I2C_BUSSTS_ALERT_Pos             (3)                                               /*!< I2C_T::BUSSTS: ALERT Position          */
#define I2C_BUSSTS_ALERT_Msk             (0x1ul << I2C_BUSSTS_ALERT_Pos)                   /*!< I2C_T::BUSSTS: ALERT Mask              */

#define I2C_BUSSTS_SCTLDIN_Pos           (4)                                               /*!< I2C_T::BUSSTS: SCTLDIN Position        */
#define I2C_BUSSTS_SCTLDIN_Msk           (0x1ul << I2C_BUSSTS_SCTLDIN_Pos)                 /*!< I2C_T::BUSSTS: SCTLDIN Mask            */

#define I2C_BUSSTS_BUSTO_Pos             (5)                                               /*!< I2C_T::BUSSTS: BUSTO Position          */
#define I2C_BUSSTS_BUSTO_Msk             (0x1ul << I2C_BUSSTS_BUSTO_Pos)                   /*!< I2C_T::BUSSTS: BUSTO Mask              */

#define I2C_BUSSTS_CLKTO_Pos             (6)                                               /*!< I2C_T::BUSSTS: CLKTO Position          */
#define I2C_BUSSTS_CLKTO_Msk             (0x1ul << I2C_BUSSTS_CLKTO_Pos)                   /*!< I2C_T::BUSSTS: CLKTO Mask              */

#define I2C_BUSSTS_PECDONE_Pos           (7)                                               /*!< I2C_T::BUSSTS: PECDONE Position        */
#define I2C_BUSSTS_PECDONE_Msk           (0x1ul << I2C_BUSSTS_PECDONE_Pos)                 /*!< I2C_T::BUSSTS: PECDONE Mask            */

#define I2C_PKTSIZE_PLDSIZE_Pos          (0)                                               /*!< I2C_T::PKTSIZE: PLDSIZE Position       */
#define I2C_PKTSIZE_PLDSIZE_Msk          (0x1fful << I2C_PKTSIZE_PLDSIZE_Pos)              /*!< I2C_T::PKTSIZE: PLDSIZE Mask           */

#define I2C_PKTCRC_PECCRC_Pos            (0)                                               /*!< I2C_T::PKTCRC: PECCRC Position         */
#define I2C_PKTCRC_PECCRC_Msk            (0xfful << I2C_PKTCRC_PECCRC_Pos)                 /*!< I2C_T::PKTCRC: PECCRC Mask             */

#define I2C_BUSTOUT_BUSTO_Pos            (0)                                               /*!< I2C_T::BUSTOUT: BUSTO Position         */
#define I2C_BUSTOUT_BUSTO_Msk            (0xfful << I2C_BUSTOUT_BUSTO_Pos)                 /*!< I2C_T::BUSTOUT: BUSTO Mask             */

#define I2C_CLKTOUT_CLKTO_Pos            (0)                                               /*!< I2C_T::CLKTOUT: CLKTO Position         */
#define I2C_CLKTOUT_CLKTO_Msk            (0xfful << I2C_CLKTOUT_CLKTO_Pos)                 /*!< I2C_T::CLKTOUT: CLKTO Mask             */

#define I2C_AUTOCTL_TGSRCSEL_Pos         (0)                                               /*!< I2C_T::AUTOCTL: TGSRCSEL Position      */
#define I2C_AUTOCTL_TGSRCSEL_Msk         (0xful << I2C_AUTOCTL_TGSRCSEL_Pos)               /*!< I2C_T::AUTOCTL: TGSRCSEL Mask          */

#define I2C_AUTOCTL_TRGEN_Pos            (4)                                               /*!< I2C_T::AUTOCTL: TRGEN Position         */
#define I2C_AUTOCTL_TRGEN_Msk            (0x1ul << I2C_AUTOCTL_TRGEN_Pos)                  /*!< I2C_T::AUTOCTL: TRGEN Mask             */

#define I2C_AUTOCTL_TXWKEN_Pos           (5)                                               /*!< I2C_T::AUTOCTL: TXWKEN Position        */
#define I2C_AUTOCTL_TXWKEN_Msk           (0x1ul << I2C_AUTOCTL_TXWKEN_Pos)                 /*!< I2C_T::AUTOCTL: TXWKEN Mask            */

#define I2C_AUTOCTL_RXWKEN_Pos           (6)                                               /*!< I2C_T::AUTOCTL: RXWKEN Position        */
#define I2C_AUTOCTL_RXWKEN_Msk           (0x1ul << I2C_AUTOCTL_RXWKEN_Pos)                 /*!< I2C_T::AUTOCTL: RXWKEN Mask            */

#define I2C_AUTOCTL_NACKWKEN_Pos         (7)                                               /*!< I2C_T::AUTOCTL: NACKWKEN Position      */
#define I2C_AUTOCTL_NACKWKEN_Msk         (0x1ul << I2C_AUTOCTL_NACKWKEN_Pos)               /*!< I2C_T::AUTOCTL: NACKWKEN Mask          */

#define I2C_AUTOCTL_AUTOMODE_Pos         (8)                                               /*!< I2C_T::AUTOCTL: AUTOMODE Position      */
#define I2C_AUTOCTL_AUTOMODE_Msk         (0x7ul << I2C_AUTOCTL_AUTOMODE_Pos)               /*!< I2C_T::AUTOCTL: AUTOMODE Mask          */

#define I2C_AUTOCTL_SWTRG_Pos            (31)                                              /*!< I2C_T::AUTOCTL: SWTRG Position         */
#define I2C_AUTOCTL_SWTRG_Msk            (0x1ul << I2C_AUTOCTL_SWTRG_Pos)                  /*!< I2C_T::AUTOCTL: SWTRG Mask             */

#define I2C_AUTOSTS_TXWKF_Pos            (0)                                               /*!< I2C_T::AUTOSTS: TXWKF Position         */
#define I2C_AUTOSTS_TXWKF_Msk            (0x1ul << I2C_AUTOSTS_TXWKF_Pos)                  /*!< I2C_T::AUTOSTS: TXWKF Mask             */

#define I2C_AUTOSTS_RXWKF_Pos            (1)                                               /*!< I2C_T::AUTOSTS: RXWKF Position         */
#define I2C_AUTOSTS_RXWKF_Msk            (0x1ul << I2C_AUTOSTS_RXWKF_Pos)                  /*!< I2C_T::AUTOSTS: RXWKF Mask             */

#define I2C_AUTOSTS_ERRORWKF_Pos         (2)                                               /*!< I2C_T::AUTOSTS: ERRORWKF Position      */
#define I2C_AUTOSTS_ERRORWKF_Msk         (0x1ul << I2C_AUTOSTS_ERRORWKF_Pos)               /*!< I2C_T::AUTOSTS: ERRORWKF Mask          */

#define I2C_AUTOSTS_TXFINISH_Pos         (8)                                               /*!< I2C_T::AUTOSTS: TXFINISH Position      */
#define I2C_AUTOSTS_TXFINISH_Msk         (0x1ul << I2C_AUTOSTS_TXFINISH_Pos)               /*!< I2C_T::AUTOSTS: TXFINISH Mask          */

#define I2C_AUTOSTS_RXFINISH_Pos         (9)                                               /*!< I2C_T::AUTOSTS: RXFINISH Position      */
#define I2C_AUTOSTS_RXFINISH_Msk         (0x1ul << I2C_AUTOSTS_RXFINISH_Pos)               /*!< I2C_T::AUTOSTS: RXFINISH Mask          */

#define I2C_AUTOSTS_ERRORIF_Pos          (10)                                              /*!< I2C_T::AUTOSTS: ERRORIF Position       */
#define I2C_AUTOSTS_ERRORIF_Msk          (0x1ul << I2C_AUTOSTS_ERRORIF_Pos)                /*!< I2C_T::AUTOSTS: ERRORIF Mask           */

#define I2C_AUTOSTS_AOFINISH_Pos         (24)                                              /*!< I2C_T::AUTOSTS: AOFINISH Position      */
#define I2C_AUTOSTS_AOFINISH_Msk         (0x1ul << I2C_AUTOSTS_AOFINISH_Pos)               /*!< I2C_T::AUTOSTS: AOFINISH Mask          */

#define I2C_AUTOSTS_BUSY_Pos             (31)                                              /*!< I2C_T::AUTOSTS: BUSY Position          */
#define I2C_AUTOSTS_BUSY_Msk             (0x1ul << I2C_AUTOSTS_BUSY_Pos)                   /*!< I2C_T::AUTOSTS: BUSY Mask              */

#define I2C_AUTOCNT_TXCNT_Pos            (0)                                               /*!< I2C_T::AUTOCNT: TXCNT Position         */
#define I2C_AUTOCNT_TXCNT_Msk            (0xfful << I2C_AUTOCNT_TXCNT_Pos)                 /*!< I2C_T::AUTOCNT: TXCNT Mask             */

#define I2C_AUTOCNT_RXCNT_Pos            (16)                                              /*!< I2C_T::AUTOCNT: RXCNT Position         */
#define I2C_AUTOCNT_RXCNT_Msk            (0xfful << I2C_AUTOCNT_RXCNT_Pos)                 /*!< I2C_T::AUTOCNT: RXCNT Mask             */

/**@}*/ /* I2C_CONST */
/**@}*/ /* end of I2C register group */
/**@}*/ /* end of REGISTER group */

#if defined ( __CC_ARM   )
#pragma no_anon_unions
#endif

#endif /* __I2C_REG_H__ */
