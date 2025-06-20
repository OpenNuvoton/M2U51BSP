/**************************************************************************//**
 * @file     main.c
 * @version  V1.01
 * @brief    Demonstrate output different duty waveform in Timer0~Timer3 PWM.
 *
 * SPDX-License-Identifier: Apache-2.0
 * @copyright (C) 2019 Nuvoton Technology Corp. All rights reserved.
 ******************************************************************************/
#include <stdio.h>
#include "NuMicro.h"


#if defined (__GNUC__) && !defined(__ARMCC_VERSION) && defined(OS_USE_SEMIHOSTING)
extern void initialise_monitor_handles(void);
#endif

void SYS_Init(void)
{
    /* Unlock protected registers */
    SYS_UnlockReg();

    /* Enable HIRC */
    CLK_EnableXtalRC(CLK_PWRCTL_HIRCEN_Msk);

    /* Waiting for HIRC clock ready */
    CLK_WaitClockReady(CLK_STATUS_HIRCSTB_Msk);

    /* Switch the core clock to 40 MHz from the MIRC */
    CLK_SetCoreClock(FREQ_40MHZ);

    /* Set PCLK0/PCLK1 to HCLK/2 */
    CLK->PCLKDIV = (CLK_PCLKDIV_APB0DIV_DIV2 | CLK_PCLKDIV_APB1DIV_DIV2);

    /* Update System Core Clock */
    /* User can use SystemCoreClockUpdate() to calculate SystemCoreClock. */
    SystemCoreClockUpdate();

    /* Enable peripheral clock */
    CLK_EnableModuleClock(UART0_MODULE);
    CLK_EnableModuleClock(TMR0_MODULE);
    CLK_EnableModuleClock(TMR1_MODULE);
    CLK_EnableModuleClock(TMR2_MODULE);
    CLK_EnableModuleClock(TMR3_MODULE);

    /* Peripheral clock source */
    CLK_SetModuleClock(UART0_MODULE, CLK_CLKSEL2_UART0SEL_HIRC, CLK_CLKDIV_UART0(1));
    CLK_SetModuleClock(TMR0_MODULE, CLK_CLKSEL1_TMR0SEL_PCLK0, 0);
    CLK_SetModuleClock(TMR1_MODULE, CLK_CLKSEL1_TMR1SEL_PCLK0, 0);
    CLK_SetModuleClock(TMR2_MODULE, CLK_CLKSEL1_TMR2SEL_PCLK1, 0);
    CLK_SetModuleClock(TMR3_MODULE, CLK_CLKSEL1_TMR3SEL_PCLK1, 0);

    /* Set multi-function pins for UART0 RXD(PB.12) and TXD(PB.13) */
    Uart0DefaultMPF();

    /* Set Timer0~4 PWM output pins */
    SYS->GPB_MFPL =  (SYS->GPB_MFPL & ~(SYS_GPB_MFPL_PB3MFP_Msk | SYS_GPB_MFPL_PB2MFP_Msk |
                                        SYS_GPB_MFPL_PB5MFP_Msk | SYS_GPB_MFPL_PB4MFP_Msk)) | \
                     (SYS_GPB_MFPL_PB3MFP_TM2 | SYS_GPB_MFPL_PB2MFP_TM3 | \
                      SYS_GPB_MFPL_PB5MFP_TM0 | SYS_GPB_MFPL_PB4MFP_TM1);

    /* Lock protected registers */
    SYS_LockReg();
}

int main(void)
{
#if defined (__GNUC__) && !defined(__ARMCC_VERSION) && defined(OS_USE_SEMIHOSTING)
    initialise_monitor_handles();
#endif

    /* Init System, IP clock and multi-function I/O
       In the end of SYS_Init() will issue SYS_LockReg()
       to lock protected register. If user want to write
       protected register, please issue SYS_UnlockReg()
       to unlock protected register if necessary */
    SYS_Init();

    /* Configure UART0 and set UART0 Baudrate */
    UART_Open(UART0, 115200);

    printf("+-------------------------------------------------+\n");
    printf("|    Timer0~Timer3 PWM Output Duty Sample Code    |\n");
    printf("+-------------------------------------------------+\n\n");

    printf("# Timer0 PWM_CH0 output frequency is 18000 Hz and duty is 50%%.\n");
    printf("# Timer1 PWM_CH0 output frequency is 10000 Hz and duty is 10%%.\n");
    printf("# Timer2 PWM_CH0 output frequency is  9000 Hz and duty is 75%%.\n");
    printf("# Timer3 PWM_CH0 output frequency is  4000 Hz and duty is 20%%.\n");
    printf("# I/O configuration:\n");
    printf("    - Timer0 PWM_CH0 on PB.5\n");
    printf("    - Timer1 PWM_CH0 on PB.4\n");
    printf("    - Timer2 PWM_CH0 on PB.3\n");
    printf("    - Timer3 PWM_CH0 on PB.2\n\n");

    /* Change Timer to PWM counter mode */
    TPWM_ENABLE_PWM_MODE(TIMER0);
    TPWM_ENABLE_PWM_MODE(TIMER1);
    TPWM_ENABLE_PWM_MODE(TIMER2);
    TPWM_ENABLE_PWM_MODE(TIMER3);

    /* Enable output of PWM_CH0 */
    TPWM_ENABLE_OUTPUT(TIMER0, TPWM_CH0);
    TPWM_ENABLE_OUTPUT(TIMER1, TPWM_CH0);
    TPWM_ENABLE_OUTPUT(TIMER2, TPWM_CH0);
    TPWM_ENABLE_OUTPUT(TIMER3, TPWM_CH0);

    /* Set Timer0 PWM output frequency is 18000 Hz, duty 50% in up count type */
    if (TPWM_ConfigOutputFreqAndDuty(TIMER0, 18000, 50) != 18000)
    {
        printf("Set the frequency different from the user\n");
    }

    /* Set Timer1 PWM output frequency is 10000 Hz, duty 10% in up count type */
    if (TPWM_ConfigOutputFreqAndDuty(TIMER1, 10000, 10) != 10000)
    {
        printf("Set the frequency different from the user\n");
    }

    /* Set Timer2 PWM output frequency is 9000 Hz, duty 75% in up count type */
    if (TPWM_ConfigOutputFreqAndDuty(TIMER2, 9000, 75) != 9000)
    {
        printf("Set the frequency different from the user\n");
    }

    /* Set Timer3 PWM output frequency is 4000 Hz, duty 20% in up count type */
    if (TPWM_ConfigOutputFreqAndDuty(TIMER3, 4000, 20) != 4000)
    {
        printf("Set the frequency different from the user\n");
    }

    /* Start Timer PWM counter */
    TPWM_START_COUNTER(TIMER0);
    TPWM_START_COUNTER(TIMER1);
    TPWM_START_COUNTER(TIMER2);
    TPWM_START_COUNTER(TIMER3);

    printf("*** Check Timer0~Timer3 PWM_CH0 output waveform by oscilloscope ***\n");

    while (1);
}

/*** (C) COPYRIGHT 2019 Nuvoton Technology Corp. ***/
