/****************************************************************************
 * @file     main.c
 * @version  V3.00
 * @brief    Use RTC alarm interrupt event to wake up system.
 * SPDX-License-Identifier: Apache-2.0
 * @copyright (C) 2016 Nuvoton Technology Corp. All rights reserved.
 ******************************************************************************/
#include <stdio.h>
#include "NuMicro.h"

/*---------------------------------------------------------------------------------------------------------*/
/* Global Interface Variables Declarations                                                                 */
/*---------------------------------------------------------------------------------------------------------*/
extern int IsDebugFifoEmpty(void);
volatile uint8_t g_u8IsRTCAlarmINT = 0;

/**
 * @brief       IRQ Handler for RTC Interrupt
 *
 * @param       None
 *
 * @return      None
 *
 * @details     The RTC_IRQHandler is default IRQ of RTC, declared in startup_M2351.s.
 */
void RTC_IRQHandler(void)
{
    /* To check if RTC alarm interrupt occurred */
    if(RTC_GET_ALARM_INT_FLAG() == 1)
    {
        /* Clear RTC alarm interrupt flag */
        RTC_CLEAR_ALARM_INT_FLAG();

        g_u8IsRTCAlarmINT++;
    }
}

void SYS_Init(void)
{
    /* Unlock protected registers */
    SYS_UnlockReg();

    /* Enable LXT */
    CLK_EnableXtalRC(CLK_PWRCTL_LXTEN_Msk);

    /* Enable HIRC */
    CLK_EnableXtalRC(CLK_PWRCTL_HIRCEN_Msk);

    /* Waiting for HIRC clock ready */
    CLK_WaitClockReady(CLK_STATUS_HIRCSTB_Msk);

    /* Waiting for LXT clock ready */
    CLK_WaitClockReady(CLK_STATUS_LXTSTB_Msk);

    /* Switch the core clock to 40MHz from the MIRC */
    CLK_SetCoreClock(FREQ_40MHZ);

    /* Set both PCLK0 and PCLK1 as HCLK/2 */
    CLK->PCLKDIV = (CLK_PCLKDIV_APB0DIV_DIV2 | CLK_PCLKDIV_APB1DIV_DIV2);

    /* Switch UART0 clock source to HIRC */
    CLK_SetModuleClock(UART0_MODULE, CLK_CLKSEL2_UART0SEL_HIRC, CLK_CLKDIV_UART0(1));

    /* Enable UART clock */
    CLK_EnableModuleClock(UART0_MODULE);

    /* Enable RTC clock */
    CLK_EnableModuleClock(RTC_MODULE);

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

int main(void)
{
    S_RTC_TIME_DATA_T sWriteRTC, sReadRTC;

    /* Init System, peripheral clock and multi-function I/O */
    SYS_Init();

    /* Init UART for printf */
    UART0_Init();

    printf("\n\nCPU @ %dHz\n", SystemCoreClock);
    printf("+-------------------------------------+\n");
    printf("|    RTC Alarm Wake-up Sample Code    |\n");
    printf("+-------------------------------------+\n\n");

    /* Open RTC */
    sWriteRTC.u32Year       = 2025;
    sWriteRTC.u32Month      = 3;
    sWriteRTC.u32Day        = 15;
    sWriteRTC.u32DayOfWeek  = RTC_SATURDAY;
    sWriteRTC.u32Hour       = 23;
    sWriteRTC.u32Minute     = 59;
    sWriteRTC.u32Second     = 50;
    sWriteRTC.u32TimeScale  = RTC_CLOCK_24;

    if(RTC_Open(&sWriteRTC) != 0)
    {
        printf("\n RTC initial fail!!");
        printf("\n Please check h/w setting!!");
        while(1);
    }

    /* Set RTC alarm date/time */
    sWriteRTC.u32Year       = 2025;
    sWriteRTC.u32Month      = 3;
    sWriteRTC.u32Day        = 15;
    sWriteRTC.u32DayOfWeek  = RTC_SATURDAY;
    sWriteRTC.u32Hour       = 23;
    sWriteRTC.u32Minute     = 59;
    sWriteRTC.u32Second     = 55;
    RTC_SetAlarmDateAndTime(&sWriteRTC);

    /* Enable RTC alarm interrupt and wake-up function will be enabled also */
    RTC_DisableInt(RTC_INTEN_TICKIEN_Msk);
    RTC_EnableInt(RTC_INTEN_ALMIEN_Msk);

    /* Enable RTC NVIC */
    NVIC_EnableIRQ(RTC_IRQn);

    printf("# Set RTC current date/time: 2025/03/15 23:59:50.\n");
    printf("# Set RTC alarm date/time:   2025/03/15 23:59:55.\n");
    printf("# Wait system waken-up by RTC alarm interrupt event.\n");

    g_u8IsRTCAlarmINT = 0;

    /* System enter to Power-down */
    /* To program PWRCTL register, it needs to disable register protection first. */
    SYS_UnlockReg();
    printf("\nSystem enter to power-down mode ...\n");
    /* To check if all the debug messages are finished */
    while(IsDebugFifoEmpty() == 0);
    CLK_PowerDown();

    while(g_u8IsRTCAlarmINT == 0);

    /* Read current RTC date/time */
    RTC_GetDateAndTime(&sReadRTC);
    printf("System has been waken-up and current date/time is:\n");
    printf("    %d/%02d/%02d %02d:%02d:%02d\n",
           sReadRTC.u32Year, sReadRTC.u32Month, sReadRTC.u32Day, sReadRTC.u32Hour, sReadRTC.u32Minute, sReadRTC.u32Second);


    printf("\n\n");
    printf("# Set next RTC alarm date/time: 2025/03/16 00:00:05.\n");
    printf("# Wait system waken-up by RTC alarm interrupt event.\n");
    RTC_SetAlarmDate(2025, 03, 16);
    RTC_SetAlarmTime(0, 0, 5, RTC_CLOCK_24, 0);

    g_u8IsRTCAlarmINT = 0;

    /* System enter to Power-down */
    /* To program PWRCTL register, it needs to disable register protection first. */
    SYS_UnlockReg();
    printf("\nSystem enter to power-down mode ...\n");
    /* To check if all the debug messages are finished */
    while(IsDebugFifoEmpty() == 0);
    CLK_PowerDown();

    while(g_u8IsRTCAlarmINT == 0);

    /* Read current RTC date/time */
    RTC_GetDateAndTime(&sReadRTC);
    printf("System has been waken-up and current date/time is:\n");
    printf("    %d/%02d/%02d %02d:%02d:%02d\n",
           sReadRTC.u32Year, sReadRTC.u32Month, sReadRTC.u32Day, sReadRTC.u32Hour, sReadRTC.u32Minute, sReadRTC.u32Second);

    printf("\n RTC Alarm Wake-up Test End !!\n");

    while(1)
    {
        ;
    }
}

/*** (C) COPYRIGHT 2016 Nuvoton Technology Corp. ***/
