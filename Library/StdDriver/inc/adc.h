/**************************************************************************//**
 * @file     adc.h
 * @version  V1.00
 * @brief    M2U51 Series ADC Driver Header File
 *
 * SPDX-License-Identifier: Apache-2.0
 * @copyright (C) 2024 Nuvoton Technology Corp. All rights reserved.
 *****************************************************************************/
#ifndef __ADC_H__
#define __ADC_H__

#ifdef __cplusplus
extern "C"
{
#endif

/** @addtogroup Standard_Driver Standard Driver
    @{
*/

/** @addtogroup ADC_Driver ADC Driver
    @{
*/

/** @addtogroup ADC_EXPORTED_CONSTANTS ADC Exported Constants
    @{
*/

/*--------------------------------------------------------------------------*/
/*  ADCR Constant Definitions                                               */
/*--------------------------------------------------------------------------*/
#define ADC_ADCR_ADEN_CONVERTER_DISABLE (0UL<<ADC_ADCR_ADEN_Pos)     /*!< ADC converter disable \hideinitializer */
#define ADC_ADCR_ADEN_CONVERTER_ENABLE  (1UL<<ADC_ADCR_ADEN_Pos)     /*!< ADC converter enable  \hideinitializer */

#define ADC_ADCR_ADMD_SINGLE            (0UL<<ADC_ADCR_ADMD_Pos)     /*!< Single mode           \hideinitializer */
#define ADC_ADCR_ADMD_BURST             (1UL<<ADC_ADCR_ADMD_Pos)     /*!< Burst mode            \hideinitializer */
#define ADC_ADCR_ADMD_SINGLE_CYCLE      (2UL<<ADC_ADCR_ADMD_Pos)     /*!< Single cycle scan mode    \hideinitializer */
#define ADC_ADCR_ADMD_CONTINUOUS        (3UL<<ADC_ADCR_ADMD_Pos)     /*!< Continuous scan mode      \hideinitializer */

#define ADC_ADCR_TRGEN_DISABLE          (0UL<<ADC_ADCR_TRGEN_Pos)    /*!< Disable triggering of A/D conversion by external STADC pin or PWM     \hideinitializer */
#define ADC_ADCR_TRGEN_ENABLE           (1UL<<ADC_ADCR_TRGEN_Pos)    /*!< Enable triggering of A/D conversion by external STADC pin or PWM      \hideinitializer */

#define ADC_ADCR_TRGS_STADC             (0UL<<ADC_ADCR_TRGS_Pos)     /*!< A/D conversion is started by external STADC pin   \hideinitializer */
#define ADC_ADCR_TRGS_TIMER             (1UL<<ADC_ADCR_TRGS_Pos)     /*!< A/D conversion is started by Timer    \hideinitializer */
#define ADC_ADCR_TRGS_BPWM              (2UL<<ADC_ADCR_TRGS_Pos)     /*!< A/D conversion is started by BPWM     \hideinitializer */
#define ADC_ADCR_TRGS_PWM               (3UL<<ADC_ADCR_TRGS_Pos)     /*!< A/D conversion is started by PWM      \hideinitializer */
#define ADC_ADCR_TRGS_ACMP0             (8UL<<ADC_ADCR_TRGS_Pos)     /*!< A/D conversion is started by ACMP0    \hideinitializer */
#define ADC_ADCR_TRGS_ACMP1             (9UL<<ADC_ADCR_TRGS_Pos)     /*!< A/D conversion is started by ACMP1    \hideinitializer */

#define ADC_ADCR_TRGCOND_LOW_LEVEL      (0UL<<ADC_ADCR_TRGCOND_Pos)  /*!< STADC Low level active    \hideinitializer */
#define ADC_ADCR_TRGCOND_HIGH_LEVEL     (1UL<<ADC_ADCR_TRGCOND_Pos)  /*!< STADC High level active   \hideinitializer */
#define ADC_ADCR_TRGCOND_FALLING_EDGE   (2UL<<ADC_ADCR_TRGCOND_Pos)  /*!< STADC Falling edge active \hideinitializer */
#define ADC_ADCR_TRGCOND_RISING_EDGE    (3UL<<ADC_ADCR_TRGCOND_Pos)  /*!< STADC Rising edge active  \hideinitializer */

#define ADC_ADCR_ACMPTES_BOTH_EDGE      (0UL<<ADC_ADCR_ACMPTES_Pos)  /*!< ACMP Both edge active \hideinitializer */
#define ADC_ADCR_ACMPTES_RISING_EDGE    (1UL<<ADC_ADCR_ACMPTES_Pos)  /*!< ACMP Rising edge active  \hideinitializer */
#define ADC_ADCR_ACMPTES_FALLING_EDGE   (2UL<<ADC_ADCR_ACMPTES_Pos)  /*!< ACMP Falling edge active \hideinitializer */

/*--------------------------------------------------------------------------*/
/* ADCMPR Constant Definitions                                              */
/*--------------------------------------------------------------------------*/
#define ADC_ADCMPR_CMPD(x)                    ((x) << ADC_ADCMPR_CMPD_Pos)          /*!< Compare value for compare function     \hideinitializer */
#define ADC_ADCMPR_CMPMATCNT(x)               (((x)-1) << ADC_ADCMPR_CMPMCNT_Pos) /*!< Match count for compare function       \hideinitializer */
#define ADC_ADCMPR_CMPCH(x)                   ((x) << ADC_ADCMPR_CMPCH_Pos)         /*!< Compare channel for compare function   \hideinitializer */
#define ADC_ADCMPR_CMPCOND_LESS_THAN          (0<<ADC_ADCMPR_CMPCOND_Pos)           /*!< The compare condition is "less than"   \hideinitializer */
#define ADC_ADCMPR_CMPCOND_GREATER_OR_EQUAL   (1<<ADC_ADCMPR_CMPCOND_Pos)           /*!< The compare condition is "greater than or equal to"    \hideinitializer */
#define ADC_ADCMPR_CMPIE_INTERRUPT_ENABLE     (ADC_ADCMPR_CMPIE_Msk)                /*!< The compare function interrupt enable  \hideinitializer */

/*--------------------------------------------------------------------------*/
/* ADC Interrupt Constant Definitions                                       */
/*--------------------------------------------------------------------------*/
#define ADC_ADF_INT         (ADC_ADSR0_ADF_Msk)          /*!< ADC convert complete interrupt    \hideinitializer */
#define ADC_CMP0_INT        (ADC_ADSR0_CMPF0_Msk)        /*!< ADC comparator 0 interrupt        \hideinitializer */
#define ADC_CMP1_INT        (ADC_ADSR0_CMPF1_Msk)        /*!< ADC comparator 1 interrupt        \hideinitializer */

/*--------------------------------------------------------------------------*/
/* ADC Operation Mode Constant Definitions                                  */
/*--------------------------------------------------------------------------*/
#define ADC_SINGLE_MODE         0   /*!< ADC single mode            \hideinitializer */
#define ADC_BURST_MODE          1   /*!< ADC burst mode             \hideinitializer */
#define ADC_SINGLE_CYCLE_MODE   2   /*!< ADC single-cycle scan mode \hideinitializer */
#define ADC_CONTINUOUS_MODE     3   /*!< ADC continuous scan mode   \hideinitializer */

/*--------------------------------------------------------------------------*/
/* ADC Trigger Condition Constant Definitions                               */
/*--------------------------------------------------------------------------*/
#define ADC_LOW_LEVEL           0   /*!< ADC external trigger condition is low level trigger     \hideinitializer */
#define ADC_HIGH_LEVEL          1   /*!< ADC external trigger condition is high level trigger    \hideinitializer */
#define ADC_FALLING_EDGE        2   /*!< ADC external trigger condition is falling edge trigger  \hideinitializer */
#define ADC_RISING_EDGE         3   /*!< ADC external trigger condition is rising edge trigger   \hideinitializer */

/*--------------------------------------------------------------------------*/
/* ADC Compare Condition Constant Definitions                               */
/*--------------------------------------------------------------------------*/
#define ADC_LESS_THAN          0    /*!< ADC compare condition is "less than the compare value"                  \hideinitializer */
#define ADC_GREATER_OR_EQUAL   1    /*!< ADC compare condition is "greater than or equal to the compare value"   \hideinitializer */

/*--------------------------------------------------------------------------*/
/*  AUTOCTL Constant Definitions                                            */
/*--------------------------------------------------------------------------*/
#define ADC_AUTOCTL_AUTO_DISABLE    (0UL<<ADC_AUTOCTL_AUTOEN_Pos)   /*!< ADC automatic operation mode disable \hideinitializer */
#define ADC_AUTOCTL_AUTO_ENABLE     (1UL<<ADC_AUTOCTL_AUTOEN_Pos)   /*!< ADC automatic operation mode enable  \hideinitializer */

#define ADC_AUTOCTL_TRIGEN_DISABLE  (0UL<<ADC_AUTOCTL_TRIGEN_Pos)   /*!< Disable automatic operation mode triggering of A/D conversion by TRIGSEL   \hideinitializer */
#define ADC_AUTOCTL_TRIGEN_ENABLE   (1UL<<ADC_AUTOCTL_TRIGEN_Pos)   /*!< Enable automatic operation mode triggering of A/D conversion by TRIGSEL    \hideinitializer */

#define ADC_AUTOCTL_TRIGSEL_SOFTWARE  (0xFFUL)                      /*!< ADC Automatic Operation Trigger Source Select is Software      \hideinitializer */
#define ADC_AUTOCTL_TRIGSEL_TIMER0  (0UL<<ADC_AUTOCTL_TRIGSEL_Pos)  /*!< Automatic operation mode A/D conversion is started by Timer0   \hideinitializer */
#define ADC_AUTOCTL_TRIGSEL_TIMER1  (1UL<<ADC_AUTOCTL_TRIGSEL_Pos)  /*!< Automatic operation mode A/D conversion is started by Timer1   \hideinitializer */
#define ADC_AUTOCTL_TRIGSEL_TIMER2  (2UL<<ADC_AUTOCTL_TRIGSEL_Pos)  /*!< Automatic operation mode A/D conversion is started by Timer2   \hideinitializer */
#define ADC_AUTOCTL_TRIGSEL_TIMER3  (3UL<<ADC_AUTOCTL_TRIGSEL_Pos)  /*!< Automatic operation mode A/D conversion is started by Timer3   \hideinitializer */
#define ADC_AUTOCTL_TRIGSEL_WKIOA0  (4UL<<ADC_AUTOCTL_TRIGSEL_Pos)  /*!< Automatic operation mode A/D conversion is started by WKIOA0   \hideinitializer */
#define ADC_AUTOCTL_TRIGSEL_WKIOB0  (5UL<<ADC_AUTOCTL_TRIGSEL_Pos)  /*!< Automatic operation mode A/D conversion is started by WKIOB0   \hideinitializer */
#define ADC_AUTOCTL_TRIGSEL_WKIOC0  (6UL<<ADC_AUTOCTL_TRIGSEL_Pos)  /*!< Automatic operation mode A/D conversion is started by WKIOC0   \hideinitializer */
#define ADC_AUTOCTL_TRIGSEL_WKIOD0  (7UL<<ADC_AUTOCTL_TRIGSEL_Pos)  /*!< Automatic operation mode A/D conversion is started by WKIOD0   \hideinitializer */
#define ADC_AUTOCTL_TRIGSEL_ACMP0   (8UL<<ADC_AUTOCTL_TRIGSEL_Pos)  /*!< Automatic operation mode A/D conversion is started by ACMP0    \hideinitializer */
#define ADC_AUTOCTL_TRIGSEL_ACMP1   (9UL<<ADC_AUTOCTL_TRIGSEL_Pos)  /*!< Automatic operation mode A/D conversion is started by ACMP1    \hideinitializer */

#define ADC_AUTOCTL_ADWK            (ADC_AUTOCTL_ADWKEN_Msk)        /*!< Enable ADC automatic operation mode wakeup by A/D conversion end \hideinitializer */
#define ADC_AUTOCTL_CMP0WK          (ADC_AUTOCTL_CMP0WKEN_Msk)      /*!< Enable ADC automatic operation mode wakeup by CMP0 \hideinitializer */
#define ADC_AUTOCTL_CMP1WK          (ADC_AUTOCTL_CMP1WKEN_Msk)      /*!< Enable ADC automatic operation mode wakeup by CMP1 \hideinitializer */

/*--------------------------------------------------------------------------*/
/*  AUTOSTS Constant Definitions                                            */
/*--------------------------------------------------------------------------*/
#define ADC_AUTOSTS_ADWK_FLAG       (ADC_AUTOSTS_ADWKF_Msk)         /*!< ADC automatic operation mode wakeup flag by A/D conversion end \hideinitializer */
#define ADC_AUTOSTS_CMP0WK_FLAG     (ADC_AUTOSTS_CMP0WKF_Msk)       /*!< Enable ADC automatic operation mode wakeup flag by CMP0 \hideinitializer */
#define ADC_AUTOSTS_CMP1WK_FLAG     (ADC_AUTOSTS_CMP1WKF_Msk)       /*!< Enable ADC automatic operation mode wakeup flag by CMP1 \hideinitializer */

/*--------------------------------------------------------------------------*/
/* Define Error Code                                                        */
/*--------------------------------------------------------------------------*/
#define ADC_TIMEOUT_ERR     (-1)    /*!< ADC operation abort due to timeout error \hideinitializer */

/*@}*/ /* end of group ADC_EXPORTED_CONSTANTS */

/** @addtogroup ADC_EXPORTED_MACROS ADC Exported Macros
  @{
*/
/**
  * @brief Get conversion data of specified channel.
  * @param[in] adc The pointer of the specified ADC module.
  * @param[in] u32ChNum ADC Channel, valid value are from 0 to 18.
  * @return  16-bit data.
  * @details Read RSLT bit field to get conversion data.
  * \hideinitializer
  */
#define ADC_GET_CONVERSION_DATA(adc, u32ChNum) ((adc)->ADDR[(u32ChNum)] & ADC_ADDR_RSLT_Msk)

/**
  * @brief Return the user-specified interrupt flags.
  * @param[in] adc The pointer of the specified ADC module.
  * @param[in] u32Mask The combination of following interrupt status bits. Each bit corresponds to a interrupt status.
  *                    Valid values are:
  *                     - \ref ADC_ADF_INT          :Convert complete interrupt flag.
  *                     - \ref ADC_CMP0_INT         :Comparator 0 interrupt flag.
  *                     - \ref ADC_CMP1_INT         :Comparator 1 interrupt flag.
  * @return  User specified interrupt flags.
  * @details Get the status of the ADC interrupt flag.
  * \hideinitializer
  */
#define ADC_GET_INT_FLAG(adc, u32Mask) ((adc)->ADSR0 & (u32Mask))

/**
  * @brief This macro clear the selected interrupt status bits.
  * @param[in] adc The pointer of the specified ADC module.
  * @param[in] u32Mask The combination of following interrupt status bits. Each bit corresponds to a interrupt status.
  *                    Valid values are:
  *                     - \ref ADC_ADF_INT          :Convert complete interrupt flag.
  *                     - \ref ADC_CMP0_INT         :Comparator 0 interrupt flag.
  *                     - \ref ADC_CMP1_INT         :Comparator 1 interrupt flag.
  * @return  None
  * @details ADF/CMPF0/CMPF1 can be cleared by writing 1 to itself.
  * \hideinitializer
  */
#define ADC_CLR_INT_FLAG(adc, u32Mask) ((adc)->ADSR0 = (u32Mask))

/**
  * @brief Get the busy state of ADC.
  * @param[in] adc The pointer of the specified ADC module.
  * @retval 0 ADC is not busy.
  * @retval 1 ADC is busy.
  * @details ADSR0[7] BUSY bit is a mirror of ADCR[11] ADST bit.
  * \hideinitializer
  */
#define ADC_IS_BUSY(adc) ((adc)->ADSR0 & ADC_ADSR0_BUSY_Msk ? 1 : 0)

/**
  * @brief Check if the ADC conversion data is over written or not.
  * @param[in] adc The pointer of the specified ADC module.
  * @param[in] u32ChNum ADC Channel, valid value are from 0 to 18.
  * @retval 0 ADC data is not overrun.
  * @retval 1 ADC data is overrun.
  * @details ADSR2[31:0] OVERRUN bits are the mirror of ADDR0~31[16] OVERRUN bits.
  * \hideinitializer
  */
#define ADC_IS_DATA_OVERRUN(adc, u32ChNum) (((adc)->ADSR2 & (1<<(u32ChNum))) ? 1 : 0)

/**
  * @brief Check if the ADC conversion data is valid or not.
  * @param[in] adc The pointer of the specified ADC module.
  * @param[in] u32ChNum ADC Channel, valid value are from 0 to 18.
  * @retval 0 ADC data is not valid.
  * @retval 1 ADC data is valid.
  * @details VALID is set to 1 when corresponding channel analog input conversion is completed and cleared by hardware after ADDR register is read.
  * \hideinitializer
  */
#define ADC_IS_DATA_VALID(adc, u32ChNum) ((adc)->ADSR1 & (0x1<<(u32ChNum)) ? 1 : 0)

/**
  * @brief Power down ADC module.
  * @param[in] adc The pointer of the specified ADC module.
  * @return None
  * @details Disable A/D converter analog circuit for saving power consumption.
  * \hideinitializer
  */
#define ADC_POWER_DOWN(adc) ((adc)->ADCR &= ~ADC_ADCR_ADEN_Msk)

/**
  * @brief Power on ADC module.
  * @param[in] adc The pointer of the specified ADC module.
  * @return None
  * @details Before starting A/D conversion function, ADEN bit should be set to 1.
  * \hideinitializer
  */
#define ADC_POWER_ON(adc) ((adc)->ADCR |= ADC_ADCR_ADEN_Msk)

/**
  * @brief Configure the comparator 0 and enable it.
  * @param[in] adc The pointer of the specified ADC module.
  * @param[in] u32ChNum  Specifies the source channel, valid value are from 0 to 18.
  * @param[in] u32Condition Specifies the compare condition. Valid values are:
  *                          - \ref ADC_ADCMPR_CMPCOND_LESS_THAN            :The compare condition is "less than the compare value".
  *                          - \ref ADC_ADCMPR_CMPCOND_GREATER_OR_EQUAL     :The compare condition is "greater than or equal to the compare value".
  * @param[in] u32Data Specifies the compare value, valid value are between 0 ~ 0xFFF.
  * @param[in] u32MatchCount Specifies the match count setting, valid values are between 1~16.
  * @return None
  * @details For example, ADC_ENABLE_CMP0(ADC, 5, ADC_ADCMPR_CMPCOND_GREATER_OR_EQUAL, 0x800, 10);
  *          means ADC will assert comparator 0 flag if channel 5 conversion result is greater than or
  *          equal to 0x800 for 10 times continuously.
  * \hideinitializer
  */
#define ADC_ENABLE_CMP0(adc, \
                        u32ChNum, \
                        u32Condition, \
                        u32Data, \
                        u32MatchCount) ((adc)->ADCMPR[0] = ((u32ChNum) << ADC_ADCMPR_CMPCH_Pos) | \
                                                           (u32Condition) | \
                                                           ((u32Data) << ADC_ADCMPR_CMPD_Pos) | \
                                                           (((u32MatchCount) - 1) << ADC_ADCMPR_CMPMCNT_Pos) |\
                                                           ADC_ADCMPR_CMPEN_Msk)

/**
  * @brief Disable comparator 0
  * @param[in] adc The pointer of the specified ADC module
  * @return None
  * @details Set CMPEN (ADCMPR0[0]) to 0 and reset comparator 0 configurations to disable ADC compare function.
  * \hideinitializer
  */
#define ADC_DISABLE_CMP0(adc) ((adc)->ADCMPR[0] = 0)

/**
  * @brief Configure the comparator 1 and enable it.
  * @param[in] adc The pointer of the specified ADC module.
  * @param[in] u32ChNum  Specifies the source channel, valid value are from 0 to 18.
  * @param[in] u32Condition Specifies the compare condition. Valid values are:
  *                          - \ref ADC_ADCMPR_CMPCOND_LESS_THAN            :The compare condition is "less than the compare value".
  *                          - \ref ADC_ADCMPR_CMPCOND_GREATER_OR_EQUAL     :The compare condition is "greater than or equal to the compare value".
  * @param[in] u32Data Specifies the compare value, valid value are between 0 ~ 0xFFF.
  * @param[in] u32MatchCount Specifies the match count setting, valid values are between 1~16.
  * @return None
  * @details For example, ADC_ENABLE_CMP1(ADC, 5, ADC_ADCMPR_CMPCOND_GREATER_OR_EQUAL, 0x800, 10);
  *          means ADC will assert comparator 1 flag if channel 5 conversion result is greater than or
  *          equal to 0x800 for 10 times continuously.
  * \hideinitializer
  */
#define ADC_ENABLE_CMP1(adc, \
                        u32ChNum, \
                        u32Condition, \
                        u32Data, \
                        u32MatchCount) ((adc)->ADCMPR[1] = ((u32ChNum) << ADC_ADCMPR_CMPCH_Pos) | \
                                                           (u32Condition) | \
                                                           ((u32Data) << ADC_ADCMPR_CMPD_Pos) | \
                                                           (((u32MatchCount) - 1) << ADC_ADCMPR_CMPMCNT_Pos) |\
                                                           ADC_ADCMPR_CMPEN_Msk)

/**
  * @brief Disable comparator 1.
  * @param[in] adc The pointer of the specified ADC module.
  * @return None
  * @details Set CMPEN (ADCMPR1[0]) to 0 and reset comparator 1 configurations to disable ADC compare function.
  * \hideinitializer
  */
#define ADC_DISABLE_CMP1(adc) ((adc)->ADCMPR[1] = 0)

/**
  * @brief Enable the compare window mode.
  * @param[in] adc The pointer of the specified ADC module.
  * @param[in] u32CMP Specifies the compare register, valid value are 0.
  * @return None
  * @details CMPF0 will be set when both ADC_CMP0 and ADC_CMP1 compared condition matched.
  * \hideinitializer
  */
#define ADC_ENABLE_CMP_WINDOW_MODE(adc, u32CMP) ((adc)->ADCMPR[(u32CMP)] |= ADC_ADCMPR_CMPWEN_Msk)

/**
  * @brief Disable the compare window mode.
  * @param[in] adc The pointer of the specified ADC module.
  * @param[in] u32CMP Specifies the compare register, valid value are 0.
  * @return None
  * @details Disable the compare window mode for specified ADC module.
  * \hideinitializer
  */
#define ADC_DISABLE_CMP_WINDOW_MODE(adc, u32CMP) ((adc)->ADCMPR[(u32CMP)] &= ~ADC_ADCMPR_CMPWEN_Msk)

/**
  * @brief Set ADC input channel.
  * @param[in] adc The pointer of the specified ADC module.
  * @param[in] u32Mask  Channel enable bit. Each bit corresponds to a input channel. Bit 0 is channel 0, bit 1 is channel 1..., bit 15 is channel 15.
  * @return None
  * @details Enabled channel will be converted while ADC starts.
  * @note In single mode, ADC can only convert 1 channel. If more than 1 channel are enabled, only the channel with smallest number will be converted.
  * \hideinitializer
  */
#define ADC_SET_INPUT_CHANNEL(adc, u32Mask) ((adc)->ADCHER = ((adc)->ADCHER & ~ADC_ADCHER_CHEN_Msk) | (u32Mask))

/**
  * @brief Start the A/D conversion.
  * @param[in] adc The pointer of the specified ADC module.
  * @return None
  * @details Set ADST bit to 1 to start the A/D conversion.
  * \hideinitializer
  */
#define ADC_START_CONV(adc) ((adc)->ADCR |= ADC_ADCR_ADST_Msk)

/**
  * @brief Stop the A/D conversion.
  * @param[in] adc The pointer of the specified ADC module.
  * @return None
  * @details ADST will be cleared to 0 by hardware automatically at the ends of single mode and single-cycle scan mode.
  *          In continuous scan mode and burst mode, A/D conversion is continuously performed until software writes 0 to this bit.
  * @note When the ADST bit is cleared to 0, the ADST bit must be kept at 0 at least one ADC peripheral clock period
  *       before setting it to 1 again, otherwise the A/D converter may not work.
  *       If ADST bit is cleared to 0 when ADC is in converting, the BUSY bit will be cleared to 0 immediately,
  *       ADC will terminate the current conversion and enter idle state directly.
  * \hideinitializer
  */
#define ADC_STOP_CONV(adc) ((adc)->ADCR &= ~ADC_ADCR_ADST_Msk)

/**
  * @brief Enable PDMA transfer.
  * @param[in] adc The pointer of the specified ADC module
  * @return None
  * @details Enable PDMA to transfer the conversion data.
  * @note While enable PDMA transfer, software must set ADIE = 0 to disable interrupt.
  * \hideinitializer
  */
#define ADC_ENABLE_PDMA(adc) ((adc)->ADCR |= ADC_ADCR_PTEN_Msk)

/**
  * @brief Disable PDMA transfer.
  * @param[in] adc The pointer of the specified ADC module
  * @return None
  * @details Disable PDMA to transfer the conversion data.
  * \hideinitializer
  */
#define ADC_DISABLE_PDMA(adc) ((adc)->ADCR &= ~ADC_ADCR_PTEN_Msk)

/**
  * @brief Get PDMA current transfer data
  * @param[in] adc The pointer of the specified ADC module.
  * @return  PDMA current transfer data
  * \hideinitializer
  */
#define ADC_GET_PDMA_DATA(adc) ((adc)->ADPDMA & ADC_ADPDMA_CURDAT_Msk)

/**
  * @brief Enable the interrupt(s) selected by u32Mask parameter.
  * @param[in] adc The pointer of the specified ADC module
  * @param[in] u32Mask The combination of interrupt status bits listed below. Each bit
  *                    corresponds to a interrupt status. This parameter decides which
  *                    interrupts will be enabled.
  *                     - \ref ADC_ADF_INT    :ADC convert complete interrupt
  *                     - \ref ADC_CMP0_INT   :ADC comparator 0 interrupt
  *                     - \ref ADC_CMP1_INT   :ADC comparator 1 interrupt
  * @return None
  * \hideinitializer
  */
#define ADC_ENABLE_INT  ADC_EnableInt

/**
  * @brief Disable the interrupt(s) selected by u32Mask parameter.
  * @param[in] adc The pointer of the specified ADC module
  * @param[in] u32Mask The combination of interrupt status bits listed below. Each bit
  *                    corresponds to a interrupt status. This parameter decides which
  *                    interrupts will be disabled.
  *                     - \ref ADC_ADF_INT     :ADC convert complete interrupt
  *                     - \ref ADC_CMP0_INT    :ADC comparator 0 interrupt
  *                     - \ref ADC_CMP1_INT    :ADC comparator 1 interrupt
  * @return None
  * \hideinitializer
  */
#define ADC_DISABLE_INT ADC_DisableInt

/**
  * @brief This macro is used to enable ADC automatic operation mode.
  * @param[in]  adc The pointer of the specified ADC module.
  * @return     None
  * @details    This macro will set AUTOEN bit of ADC_AUTOCTL register to enable ADC automatic operation mode.
  * \hideinitializer
  */
#define ADC_AUTO_ENABLE(adc)    ((adc)->AUTOCTL |=  (ADC_AUTOCTL_AUTOEN_Msk))

/**
  * @brief This macro is used to disable ADC automatic operation mode.
  * @param[in]  adc The pointer of the specified ADC module.
  * @return     None
  * @details    This macro will set AUTOEN bit of ADC_AUTOCTL register to disable ADC automatic operation mode.
  * \hideinitializer
  */
#define ADC_AUTO_DISABLE(adc)   ((adc)->AUTOCTL &= ~(ADC_AUTOCTL_AUTOEN_Msk))

/**
  * @brief Return the user-specified wakeup flags.
  * @param[in] adc The pointer of the specified ADC module.
  * @param[in] u32Mask The combination of following wakeup status bits. Each bit corresponds to a wakeup status.
  *                    Valid values are:
  *                     - \ref ADC_AUTOSTS_ADWK_FLAG    :Convert complete wakeup flag.
  *                     - \ref ADC_AUTOSTS_CMP0WK_FLAG  :Comparator 0 wakeup flag.
  *                     - \ref ADC_AUTOSTS_CMP1WK_FLAG  :Comparator 1 wakeup flag.
  * @return  User specified wakeup flags.
  * @details Get the status of the ADC wakeup flag.
  * \hideinitializer
  */
#define ADC_AUTO_GET_WAKEUP_FLAG(adc, u32Mask) ((adc)->AUTOSTS & (u32Mask))

/**
  * @brief This macro clear the selected wakeup status bits.
  * @param[in] adc The pointer of the specified ADC module.
  * @param[in] u32Mask The combination of following wakeup status bits. Each bit corresponds to a wakeup status.
  *                    Valid values are:
  *                     - \ref ADC_AUTOSTS_ADWK_FLAG    :Convert complete wakeup flag.
  *                     - \ref ADC_AUTOSTS_CMP0WK_FLAG  :Comparator 0 wakeup flag.
  *                     - \ref ADC_AUTOSTS_CMP1WK_FLAG  :Comparator 1 wakeup flag.
  * @return  None
  * \hideinitializer
  */
#define ADC_AUTO_CLR_WAKEUP_FLAG(adc, u32Mask) ((adc)->AUTOSTS = (u32Mask))

/*@}*/ /* end of group ADC_EXPORTED_MACROS */

extern int32_t g_ADC_i32ErrCode;

/** @addtogroup ADC_EXPORTED_FUNCTIONS ADC Exported Functions
  @{
*/
void ADC_Open (ADC_T *adc,
               uint32_t u32InputMode,
               uint32_t u32OpMode,
               uint32_t u32ChMask);
void ADC_Close(ADC_T *adc);
void ADC_EnableHWTrigger     (ADC_T *adc, uint32_t u32Source, uint32_t u32Param);
void ADC_DisableHWTrigger    (ADC_T *adc);
void ADC_EnableInt           (ADC_T *adc, uint32_t u32Mask);
void ADC_DisableInt          (ADC_T *adc, uint32_t u32Mask);
void ADC_SetExtendSampleTime (ADC_T *adc,
                              uint32_t u32ModuleNum,
                              uint32_t u32ExtendSampleTime);

void ADC_SelectAutoOperationMode(ADC_T *adc, uint32_t u32TrigSel);
void ADC_AutoEnableHWTrigger    (ADC_T *adc, uint32_t u32Source, uint32_t u32Param);
void ADC_AutoDisableHWTrigger   (ADC_T *adc);
void ADC_AutoEnableWakeup       (ADC_T *adc, uint32_t u32Mask);
void ADC_AutoDisableWakeup      (ADC_T *adc, uint32_t u32Mask);

/*@}*/ /* end of group ADC_EXPORTED_FUNCTIONS */

/*@}*/ /* end of group ADC_Driver */

/*@}*/ /* end of group Standard_Driver */

#ifdef __cplusplus
}
#endif

#endif //__ADC_H__

/*** (C) COPYRIGHT 2024 Nuvoton Technology Corp. ***/
