/******************************************************************************
 * @file     main.c
 * @version  V1.00
 * $Revision: 23 $
 * $Date: 18/07/23 9:23a $
 * @brief    Demonstrate how to reload the WWDT counter value without resetting the MCU.
 *
 * @note
 * SPDX-License-Identifier: Apache-2.0
 * Copyright (C) 2018 Nuvoton Technology Corp. All rights reserved.
 *****************************************************************************/

#include <stdio.h>
#include "NuMicro.h"

#define RELOAD_CONDITION  3
/*---------------------------------------------------------------------------------------------------------*/
/* Global Interface Variables Declarations                                                                 */
/*---------------------------------------------------------------------------------------------------------*/
extern int IsDebugFifoEmpty(void);

void UserAlgorithm(void)
{
    printf("-> Reload WWDT counter (%d) in UserAlgorithm()\n",WWDT->CNT);

    while(!IsDebugFifoEmpty());

    /* To reload the WWDT counter value to 0x3F */
    WWDT_RELOAD_COUNTER();
    /* Algorithm */
    PA0 ^= 1;
}

void Delay_ms(uint32_t ms)
{
    uint32_t i;
    uint32_t cnt = 0;

    printf("\nDelay %d ms before UserAlgorithm()\n",ms);
    printf("WWDT Counter\n");

    for(i=0 ; i<ms ; i++)
    {
        CLK_SysTickDelay(1000);

        if(WWDT->CNT != cnt)
        {
            cnt = WWDT->CNT;
            printf("%2d ",WWDT->CNT);
        }
    }
}


volatile uint8_t g_u32WWDTINTCounts;

/**
 * @brief       IRQ Handler for WWDT Interrupt
 *
 * @param       None
 *
 * @return      None
 *
 * @details     The WDT_IRQHandler is default IRQ of WWDT
 */
void WDT_IRQHandler(void)
{
    if(WWDT_GET_INT_FLAG() == 1)
    {
        /* Clear WWDT compare match interrupt flag */
        WWDT_CLEAR_INT_FLAG();

        g_u32WWDTINTCounts++;

        printf("\nWWDT compare match interrupt occurred. (Interrupt Count %d)\n", g_u32WWDTINTCounts);
    }
}

void SYS_Init(void)
{
    /* Unlock protected registers */
    SYS_UnlockReg();

    /* Enable HIRC */
    CLK_EnableXtalRC(CLK_PWRCTL_HIRCEN_Msk);

    /* Waiting for HIRC clock ready */
    CLK_WaitClockReady(CLK_STATUS_HIRCSTB_Msk);

    /* Switch the core clock to 40MHz from the MIRC */
    CLK_SetCoreClock(FREQ_40MHZ);

    /* Set both PCLK0 and PCLK1 as HCLK/2 */
    CLK->PCLKDIV = (CLK_PCLKDIV_APB0DIV_DIV2 | CLK_PCLKDIV_APB1DIV_DIV2);

    /* Switch UART0 clock source to HIRC */
    CLK_SetModuleClock(UART0_MODULE, CLK_CLKSEL2_UART0SEL_HIRC, CLK_CLKDIV_UART0(1));

    /* Switch WWDT clock source to HCLK/2048 */
    CLK_SetModuleClock(WWDT_MODULE, CLK_CLKSEL1_WWDTSEL_HCLK_DIV2048, 0);

    /* Enable UART clock */
    CLK_EnableModuleClock(UART0_MODULE);

    /* Enable WWDT clock */
    CLK_EnableModuleClock(WWDT_MODULE);

    /* Update System Core Clock */
    /* User can use SystemCoreClockUpdate() to calculate SystemCoreClock and CyclesPerUs automatically. */
    SystemCoreClockUpdate();

    /*----------------------------------------------------------------------*/
    /* Init I/O Multi-function                                              */
    /*----------------------------------------------------------------------*/
    /* Set multi-function pins for UART0 RXD(PB.12) and TXD(PB.13) */
    Uart0DefaultMPF();

    /* Lock protected registers */
    SYS_LockReg();
}

void UART0_Init(void)
{
    /*---------------------------------------------------------------------------------------------------------*/
    /* Init UART                                                                                               */
    /*---------------------------------------------------------------------------------------------------------*/
    /* Reset UART module */
    SYS_ResetModule(UART0_RST);

    /* Configure UART0 and set UART0 Baudrate */
    UART_Open(UART0, 115200);
}
/*---------------------------------------------------------------------------------------------------------*/
/*  MAIN function                                                                                          */
/*---------------------------------------------------------------------------------------------------------*/
int main(void)
{
    double dTimeOutPeriodTime;
    double dCompareMatchPeriodTime;

    /* Init System, peripheral clock and multi-function I/O */
    SYS_Init();

    /* Init UART0 to 115200-8n1 for print message */
    UART0_Init();

    printf("\n\nCPU @ %d Hz\n", SystemCoreClock);
    printf("+------------------------------------------------+\n");
    printf("|         WWDT Reload Counter Sample Code        |\n");
    printf("+------------------------------------------------+\n\n");

    printf(" Test Condition :\n");
    printf(" Condition 1 - Reload before the WWDT window region \n");
    printf(" Condition 2 - Reload after the WWDT window region  \n");
    printf(" Condition 3 - Reload inside the WWDT window region \n\n");

    /* To check if system has been reset by WWDT time-out reset or not */
    if(WWDT_GET_RESET_FLAG() == 1)
    {
        printf("*** System has been reset by WWDT time-out reset event. [WWDT_CTL: 0x%08X] ***\n\n", WWDT->CTL);
        WWDT_CLEAR_RESET_FLAG();
        while(1);
    }

    /* WWDT clock source is HCLK / 2048 */
    dTimeOutPeriodTime      = (((double)(1000000 * 2048) / (double)SystemCoreClock) * 1024) * 64 / 1000;
    dCompareMatchPeriodTime = (((double)(1000000 * 2048) / (double)SystemCoreClock) * 1024) * 32 / 1000;

    printf("# WWDT Settings: \n");
    printf("    - Clock source is HCLK/2048 (%d Hz)    \n", SystemCoreClock / 2048);
    printf("    - WWDT counter prescale period is 1024  \n");
    printf("    - Interrupt enable                      \n");
    printf("    - Window Compare value is 32            \n");
    printf("      WWDT time-out period is 1024 * (64 * WWDT_CLK)      = %.2f ms\n", dTimeOutPeriodTime);
    printf("      WWDT compare match period is 1024 * (32 * WWDT_CLK) = %.2f ms\n\n", dCompareMatchPeriodTime);

    printf("# System will generate first WWDT compare match interrupt event after %.2f ms.\n", dCompareMatchPeriodTime);
    printf("    1.) use PA.0 high/low period to check reload WWDT counter period time\n");
    printf("    2.) reload WWDT counter value to avoid WWDT time-out reset\n");
    printf("        when interrupt counter value is less than 11.\n");
    printf("    3.) do not reload WWDT counter value to generate WWDT time-out reset system event\n");
    printf("        when interrupt counts large than 10.\n\n");

    /* Use PA.0 to check reload WWDT counter period time */
    GPIO_SetMode(PA, BIT0,GPIO_MODE_OUTPUT);
    PA0 = 1;

    /* Enable WWDT NVIC */
    NVIC_EnableIRQ(WDT_IRQn);

    g_u32WWDTINTCounts = 0;

    printf("[WWDT_CTL: 0x%08X]\n\n", WWDT->CTL);
    printf("WWDT Counter 63                       32                        0\n");
    printf("              +------------------------+------------------------+\n");
    printf("Timeline (ms) 0                     %.2f                  %.2f\n", dCompareMatchPeriodTime, dTimeOutPeriodTime);
    printf("              |   Reset When Reload    |   WWDT Window Region   |  WWDT Time-Out Reset\n\n");

#if RELOAD_CONDITION == 1
    printf("Test Condition 1 - Reload before the WWDT window region \n");
#elif RELOAD_CONDITION == 2
    printf("Test Condition 2 - Reload after the WWDT window region  \n");
#elif RELOAD_CONDITION == 3
    printf("Test Condition 3 - Reload inside the WWDT window region \n");
#endif

    printf("\n* Reload WWDT counter in UserAlgorithm()\n");

    /*
        WWDT max time-out period is 1024*(64*WWDT_CLK) = 2796.2 ms
        WWDT compare value is 32 = 1024*(32*WWDT_CLK) = 1398.1 ms
        Enable WWDT compare match interrupt
    */
    /* Note: WWDT_CTL register can be written only once after chip is powered on or reset */
    WWDT_Open(WWDT_PRESCALER_1024, 32, TRUE);

    while(1)
    {
#if RELOAD_CONDITION == 1
        /* Reload before the WWDT window region */
        /* CNTDAT > CMPDAT, Write RLDCNT 0x5AA5 to reload WWWDT counter will reset system */
        /* Delay_ms < 1398.1 ms */
        Delay_ms((uint32_t) dCompareMatchPeriodTime / 2);
#elif RELOAD_CONDITION == 2
        /* Reload after the WWDT window region */
        /* Wait CNTDAT count to 0, System reset immediately */
        /* Delay_ms > 2796.2 ms */
        Delay_ms((uint32_t) dTimeOutPeriodTime + 1);
#elif RELOAD_CONDITION == 3
        if(g_u32WWDTINTCounts > 10)
        {
            /* Reload after the WWDT window region */
            /* Wait CNTDAT count to 0, System reset immediately */
            Delay_ms((uint32_t) dTimeOutPeriodTime + 1);
        }
        else
        {
            /* Reload inside the WWDT window region */
            /* CNTDAT <= CMPDAT, Write RLDCNT 0x5AA5 will reload CNTDAT to 0x3F */
            /* 2796.2 ms > Delay_ms > 1398.1 ms */
            Delay_ms((uint32_t) dCompareMatchPeriodTime + 1);
        }
#endif

        UserAlgorithm();
    }
}

/*** (C) COPYRIGHT 2018 Nuvoton Technology Corp. ***/
