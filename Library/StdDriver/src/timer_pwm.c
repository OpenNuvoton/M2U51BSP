/**************************************************************************//**
 * @file     timer_pwm.c
 * @version  V3.01
 * @brief    Timer PWM Controller(Timer PWM) driver source file
 *
 * SPDX-License-Identifier: Apache-2.0
 * @copyright (C) 2020 Nuvoton Technology Corp. All rights reserved.
 *****************************************************************************/
#include "NuMicro.h"


/** @addtogroup Standard_Driver Standard Driver
  @{
*/

/** @addtogroup TIMER_PWM_Driver TIMER PWM Driver
  @{
*/

/** @addtogroup TIMER_PWM_EXPORTED_FUNCTIONS TIMER PWM Exported Functions
  @{
*/

/**
  * @brief      Configure TPWM Output Frequency and Duty Cycle
  *
  * @param[in]  timer           The pointer of the specified Timer module. It could be TIMER0, TIMER1, TIMER2, TIMER3.
  * @param[in]  u32Frequency    Target generator frequency.
  * @param[in]  u32DutyCycle    Target generator duty cycle percentage. Valid range are between 0~100. 10 means 10%, 20 means 20%...
  *
  * @return     Nearest frequency clock in nano second
  *
  * @details    This API is used to configure TPWM output frequency and duty cycle in up count type and auto-reload operation mode.
  * @note       This API is only available if Timer PWM counter clock source is from TMRx_CLK.
  */
uint32_t TPWM_ConfigOutputFreqAndDuty(TIMER_T *timer, uint32_t u32Frequency, uint32_t u32DutyCycle)
{
    uint32_t u32PWMClockFreq, u32TargetFreq;
    uint32_t u32Prescaler = 0x100UL, u32Period, u32CMP;
    uint32_t u32Src;
    const uint32_t au32Clk[] = {0UL, __MIRC, __HIRC, __LIRC, __LXT, 0UL};

    if(timer == TIMER0)
    {
        u32Src = (CLK->CLKSEL1 & CLK_CLKSEL1_TMR0SEL_Msk) >> CLK_CLKSEL1_TMR0SEL_Pos;
    }
    else if(timer == TIMER1)
    {
        u32Src = (CLK->CLKSEL1 & CLK_CLKSEL1_TMR1SEL_Msk) >> CLK_CLKSEL1_TMR1SEL_Pos;
    }
    else if(timer == TIMER2)
    {
        u32Src = (CLK->CLKSEL1 & CLK_CLKSEL1_TMR2SEL_Msk) >> CLK_CLKSEL1_TMR2SEL_Pos;
    }
    else      /* Timer 3 */
    {
        u32Src = (CLK->CLKSEL1 & CLK_CLKSEL1_TMR3SEL_Msk) >> CLK_CLKSEL1_TMR3SEL_Pos;
    }

    if(u32Src == 0UL)
    {
        if ((timer == TIMER0) || (timer == TIMER1))
        {
            u32PWMClockFreq = CLK_GetPCLK0Freq();
        }
        else
        {
            u32PWMClockFreq = CLK_GetPCLK1Freq();
        }
    }
    else
    {
        u32PWMClockFreq = au32Clk[u32Src];
    }

    /* Calculate u8PERIOD and u8PSC */
    for (u32Prescaler = 1; u32Prescaler <= 0x100UL; u32Prescaler++)
    {
        u32Period = (u32PWMClockFreq / u32Prescaler) / u32Frequency;

        /* If target u32Period is larger than 0x10000, need to use a larger prescaler */
        if (u32Period > 0x10000UL)
            continue;

        break;
    }

    if (u32Prescaler == 0x101UL)
    {
        u32Prescaler = 0x100UL;
        u32Period = 0x10000UL;
    }

    /* Store return value here 'cos we're gonna change u32Prescaler & u32Period to the real value to fill into register */
    u32TargetFreq = (u32PWMClockFreq / u32Prescaler) / u32Period;

    /* Set PWM to auto-reload mode */
    timer->PWMCTL = (timer->PWMCTL & ~TIMER_PWMCTL_CNTMODE_Msk) | (TPWM_AUTO_RELOAD_MODE << TIMER_PWMCTL_CNTMODE_Pos);

    /* Convert to real register value */
    TPWM_SET_PRESCALER(timer, (u32Prescaler - 1UL));

    TPWM_SET_PERIOD(timer, (u32Period - 1UL));

    if (u32DutyCycle)
    {
        u32CMP = (u32DutyCycle * u32Period) / 100UL;
    }
    else
    {
        u32CMP = 0UL;
    }

    TPWM_SET_CMPDAT(timer, u32CMP);
    return (u32TargetFreq);
}

/**
  * @brief      Enable TPWM Counter
  *
  * @param[in]  timer       The pointer of the specified Timer module. It could be TIMER0, TIMER1, TIMER2, TIMER3.
  *
  * @return     None
  *
  * @details    This function is used to enable TPWM generator and start counter counting.
  */
void TPWM_EnableCounter(TIMER_T *timer)
{
    timer->PWMCTL |= TIMER_PWMCTL_CNTEN_Msk;
}

/**
  * @brief      Disable TPWM Generator
  *
  * @param[in]  timer       The pointer of the specified Timer module. It could be TIMER0, TIMER1, TIMER2, TIMER3.
  *
  * @return     None
  *
  * @details This function is used to disable TPWM counter immediately by clear CNTEN (TIMERx_PWMCTL[0]) bit.
  */
void TPWM_DisableCounter(TIMER_T *timer)
{
    timer->PWMCTL &= ~TIMER_PWMCTL_CNTEN_Msk;
}

/**
  * @brief      Enable TPWM Trigger ADC/PDMA
  *
  * @param[in]  timer           The pointer of the specified Timer module. It could be TIMER0, TIMER1, TIMER2, TIMER3.
  * @param[in]  u32TargetMask   The mask of modules (ADC/PDMA) trigger by TPWM, the combination of:
  *                                 - \ref TIMER_PWMTRGCTL_PWMTRGADC_Msk
  *                                 - \ref TIMER_PWMTRGCTL_PWMTRGPDMA_Msk
  * @param[in]  u32Condition    The condition to trigger ADC/PDMA. It could be one of following conditions:
  *                                 - \ref TPWM_TRIGGER_AT_PERIOD_POINT
  *                                 - \ref TPWM_TRIGGER_AT_COMPARE_POINT
  *                                 - \ref TPWM_TRIGGER_AT_PERIOD_OR_COMPARE_POINT
  * @return     None
  *
  * @details    This function is used to enable specified counter event to trigger ADC/PDMA
  */
void TPWM_EnableTrigger(TIMER_T *timer, uint32_t u32TargetMask, uint32_t u32Condition)
{
    timer->PWMTRGCTL &= ~(TIMER_PWMTRGCTL_PWMTRGADC_Msk | TIMER_PWMTRGCTL_PWMTRGPDMA_Msk | TIMER_PWMTRGCTL_TRGSEL_Msk);
    timer->PWMTRGCTL |= (u32TargetMask) | (u32Condition);
}

/**
  * @brief      Disable Trigger ADC/PDMA
  *
  * @param[in]  timer       The pointer of the specified Timer module. It could be TIMER0, TIMER1, TIMER2, TIMER3.
  * @param[in]  u32TargetMask   The mask of modules (ADC/PDMA) trigger by TPWM, the combination of:
  *                                 - \ref TIMER_PWMTRGCTL_PWMTRGADC_Msk
  *                                 - \ref TIMER_PWMTRGCTL_PWMTRGPDMA_Msk
  *
  * @return     None
  *
  * @details    This function is used to disable counter event to trigger ADC/PDMA
  */
void TPWM_DisableTrigger(TIMER_T *timer, uint32_t u32TargetMask)
{
    timer->PWMTRGCTL &= ~(u32TargetMask);
}

/**
  * @brief      Enable Interrupt Flag Accumulator
  * @param[in]  timer           The pointer of the specified Timer module. It could be TIMER0, TIMER1, TIMER2, TIMER3.
  * @param[in]  u32IntFlagCnt   Interrupt flag counter. Valid values are between 0~65535.
  * @param[in]  u32IntAccSrc    Interrupt flag accumulator source selection.
  *                                 - \ref TPWM_IFA_PERIOD_POINT
  *                                 - \ref TPWM_IFA_COMPARE_UP_COUNT_POINT
  * @return     None
  * @details    This function is used to enable interrupt flag accumulator.
  */
void TPWM_EnableAcc(TIMER_T *timer, uint32_t u32IntFlagCnt, uint32_t u32IntAccSrc)
{
    timer->PWMIFA = (((timer)->PWMIFA & ~(TIMER_PWMIFA_IFACNT_Msk | TIMER_PWMIFA_IFASEL_Msk | TIMER_PWMIFA_STPMOD_Msk))
                     | (TIMER_PWMIFA_IFAEN_Msk | (u32IntFlagCnt << TIMER_PWMIFA_IFACNT_Pos) | (u32IntAccSrc << TIMER_PWMIFA_IFASEL_Pos)));
}

/**
  * @brief      Disable Interrupt Flag Accumulator
  * @param[in]  timer       The pointer of the specified Timer module. It could be TIMER0, TIMER1, TIMER2, TIMER3.
  * @return     None
  * @details    This function is used to disable interrupt flag accumulator.
  */
void TPWM_DisableAcc(TIMER_T *timer)
{
    timer->PWMIFA &= ~TIMER_PWMIFA_IFAEN_Msk;
}

/**
  * @brief      Enable Interrupt Flag Accumulator Interrupt Function
  * @param[in]  timer       The pointer of the specified Timer module. It could be TIMER0, TIMER1, TIMER2, TIMER3.
  * @return     None
  * @details    This function is used to enable interrupt flag accumulator interrupt.
  */
void TPWM_EnableAccInt(TIMER_T *timer)
{
    timer->PWMAINTEN |= TIMER_PWMAINTEN_IFAIEN_Msk;
}

/**
  * @brief      Disable Interrupt Flag Accumulator Interrupt Function
  * @param[in]  timer       The pointer of the specified Timer module. It could be TIMER0, TIMER1, TIMER2, TIMER3.
  * @return     None
  * @details    This function is used to disable interrupt flag accumulator interrupt.
  */
void TPWM_DisableAccInt(TIMER_T *timer)
{
    timer->PWMAINTEN &= ~TIMER_PWMAINTEN_IFAIEN_Msk;
}

/**
  * @brief      Clear Interrupt Flag Accumulator Interrupt Flag
  * @param[in]  timer       The pointer of the specified Timer module. It could be TIMER0, TIMER1, TIMER2, TIMER3.
  * @return     None
  * @details    This function is used to clear interrupt flag accumulator interrupt.
  */
void TPWM_ClearAccInt(TIMER_T *timer)
{
    timer->PWMAINTSTS = TIMER_PWMAINTSTS_IFAIF_Msk;
}

/**
  * @brief      Get Interrupt Flag Accumulator Interrupt Flag
  * @param[in]  timer       The pointer of the specified Timer module. It could be TIMER0, TIMER1, TIMER2, TIMER3.
  * @retval     0   Accumulator interrupt did not occur
  * @retval     1   Accumulator interrupt occurred
  * @details    This function is used to get interrupt flag accumulator interrupt.
  */
uint32_t TPWM_GetAccInt(TIMER_T *timer)
{
    return (((timer)->PWMAINTSTS & TIMER_PWMAINTSTS_IFAIF_Msk)? 1UL : 0UL);
}

/**
  * @brief      Enable Accumulator Interrupt Trigger PDMA
  * @param[in]  timer       The pointer of the specified Timer module. It could be TIMER0, TIMER1, TIMER2, TIMER3.
  * @return     None
  * @details    This function is used to enable accumulator interrupt trigger PDMA transfer.
  */
void TPWM_EnableAccPDMA(TIMER_T *timer)
{
    timer->PWMAPDMACTL |= TIMER_PWMAPDMACTL_APDMAEN_Msk;
}

/**
  * @brief      Disable Accumulator Interrupt Trigger PDMA
  * @param[in]  timer       The pointer of the specified Timer module. It could be TIMER0, TIMER1, TIMER2, TIMER3.
  * @return     None
  * @details    This function is used to disable accumulator interrupt trigger PDMA transfer.
  */
void TPWM_DisableAccPDMA(TIMER_T *timer)
{
    timer->PWMAPDMACTL &= ~TIMER_PWMAPDMACTL_APDMAEN_Msk;
}

/**
  * @brief      Enable Interrupt Flag Accumulator Stop Mode
  * @param[in]  timer       The pointer of the specified Timer module. It could be TIMER0, TIMER1, TIMER2, TIMER3.
  * @return     None
  * @details    This function is used to enable interrupt flag accumulator event to stop PWM counting.
  */
void TPWM_EnableAccStopMode(TIMER_T *timer)
{
    timer->PWMIFA |= TIMER_PWMIFA_STPMOD_Msk;
}

/**
  * @brief      Disable Interrupt Flag Accumulator Stop Mode
  * @param[in]  timer       The pointer of the specified Timer module. It could be TIMER0, TIMER1, TIMER2, TIMER3.
  * @return     None
  * @details    This function is used to disable interrupt flag accumulator event to stop PWM counting.
  */
void TPWM_DisableAccStopMode(TIMER_T *timer)
{
    timer->PWMIFA &= ~TIMER_PWMIFA_STPMOD_Msk;
}

/*@}*/ /* end of group TIMER_PWM_EXPORTED_FUNCTIONS */

/*@}*/ /* end of group TIMER_PWM_Driver */

/*@}*/ /* end of group Standard_Driver */

/*** (C) COPYRIGHT 2020 Nuvoton Technology Corp. ***/
