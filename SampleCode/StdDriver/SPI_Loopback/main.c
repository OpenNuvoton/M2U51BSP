/******************************************************************************
 * @file     main.c
 * @version  V1.00
 * $Revision: 2 $
 * $Date: 20/08/11 2:29p $
 * @brief    Implement SPI Master loop back transfer. This sample code needs to
 *           connect MISO_0 pin and MOSI_0 pin together. It will compare the
 *           received data with transmitted data.
 *
 * @note
 * SPDX-License-Identifier: Apache-2.0
 * Copyright (C) 2020 Nuvoton Technology Corp. All rights reserved.
 *
*****************************************************************************/
#include <stdio.h>
#include "NuMicro.h"

#define TEST_CYCLE      0x1000
#define DATA_COUNT      64
#define SPI_CLK_FREQ    2000000


uint32_t g_au32SourceData[DATA_COUNT];
uint32_t g_au32DestinationData[DATA_COUNT];

/* Function prototype declaration */
void SYS_Init(void);
void SPI_Init(void);

/* ------------- */
/* Main function */
/* ------------- */
int main(void)
{
    uint32_t u32DataCount, u32TestCycle, u32Err;
    uint32_t u32TimeOutCount;

    /* Unlock protected registers */
    SYS_UnlockReg();

    /* Init System, IP clock and multi-function I/O. */
    SYS_Init();

    /* Lock protected registers */
    SYS_LockReg();

    /* Configure UART0: 115200, 8-bit word, no parity bit, 1 stop bit. */
    UART_Open(UART0, 115200);

    /* Init SPI */
    SPI_Init();

    printf("\n\n");
    printf("+--------------------------------------------------------------------+\n");
    printf("|                   SPI Driver Sample Code                           |\n");
    printf("+--------------------------------------------------------------------+\n");
    printf("\n");
    printf("\nThis sample code demonstrates SPI0 self loop back data transfer.\n");
    printf(" SPI0 configuration:\n");
    printf("     Master mode; data width 32 bits.\n");
    printf(" I/O connection:\n");
    printf("     SPI0_MOSI(PA.0) <--> SPI0_MISO(PA.1) \n");
    printf("\nSPI0 Loopback test \n\n");

    printf("Please hit any key to start test.\n\n");
    getchar();

    u32Err = 0;
    for(u32TestCycle = 0; u32TestCycle < TEST_CYCLE; u32TestCycle++)
    {
        /* set the source data and clear the destination buffer */
        for(u32DataCount = 0; u32DataCount < DATA_COUNT; u32DataCount++)
        {
            g_au32SourceData[u32DataCount] = u32DataCount;
            g_au32DestinationData[u32DataCount] = 0;
        }

        u32DataCount = 0;

        if((u32TestCycle & 0x1FF) == 0)
        {
            putchar('.');
        }

        while(1)
        {
            /* setup timeout */
            u32TimeOutCount = SystemCoreClock;

            /* Write to TX register */
            SPI_WRITE_TX(SPI0, g_au32SourceData[u32DataCount]);

            /* Check SPI0 busy status */
            while(SPI_IS_BUSY(SPI0))
            {
                if(u32TimeOutCount == 0)
                {
                    printf("\nSomething is wrong, please check if pin connection is correct. \n");
                    while(1);
                }
                u32TimeOutCount--;
            }

            /* Read received data */
            g_au32DestinationData[u32DataCount] = SPI_READ_RX(SPI0);
            u32DataCount++;
            if(u32DataCount >= DATA_COUNT)
                break;
        }

        /*  Check the received data */
        for(u32DataCount = 0; u32DataCount < DATA_COUNT; u32DataCount++)
        {
            if(g_au32DestinationData[u32DataCount] != g_au32SourceData[u32DataCount])
                u32Err = 1;
        }

        if(u32Err)
            break;
    }

    if(u32Err)
        printf(" [FAIL]\n\n");
    else
        printf(" [PASS]\n\n");

    /* Close SPI0 */
    SPI_Close(SPI0);

    while(1);
}

void SYS_Init(void)
{
    /*---------------------------------------------------------------------------------------------------------*/
    /* Init System Clock                                                                                       */
    /*---------------------------------------------------------------------------------------------------------*/
    /* Unlock protected registers */
    SYS_UnlockReg();

    /* Enable HIRC */
    CLK_EnableXtalRC(CLK_PWRCTL_HIRCEN_Msk);

    /* Waiting for HIRC clock ready */
    CLK_WaitClockReady(CLK_STATUS_HIRCSTB_Msk);

    /* Switch the core clock to 40MHz from the MIRC */
    CLK_SetCoreClock(FREQ_40MHZ);

    /* Set PCLK0/PCLK1 to HCLK/2 */
    CLK->PCLKDIV = (CLK_PCLKDIV_APB0DIV_DIV2 | CLK_PCLKDIV_APB1DIV_DIV2);

    /* Update System Core Clock */
    /* User can use SystemCoreClockUpdate() to calculate SystemCoreClock and CyclesPerUs automatically. */
    SystemCoreClockUpdate();

    /* Select UART clock source from HIRC */
    CLK_SetModuleClock(UART0_MODULE, CLK_CLKSEL2_UART0SEL_HIRC, CLK_CLKDIV_UART0(1));

    /* Enable UART peripheral clock */
    CLK_EnableModuleClock(UART0_MODULE);

    /* Enable SPI0 peripheral clock */
    CLK_EnableModuleClock(SPI0_MODULE);

    /*---------------------------------------------------------------------------------------------------------*/
    /* Init I/O Multi-function                                                                                 */
    /*---------------------------------------------------------------------------------------------------------*/
    /* Set PB multi-function pins for UART0 RXD=PB.12 and TXD=PB.13 */
    Uart0DefaultMPF();

    /* Setup SPI0 multi-function pins */
    /* PA.3 is SPI0_SS,   PA.2 is SPI0_CLK,
       PA.1 is SPI0_MISO, PA.0 is SPI0_MOSI*/
    SYS->GPA_MFPL = (SYS->GPA_MFPL & ~(SYS_GPA_MFPL_PA3MFP_Msk |
                                       SYS_GPA_MFPL_PA2MFP_Msk |
                                       SYS_GPA_MFPL_PA1MFP_Msk |
                                       SYS_GPA_MFPL_PA0MFP_Msk)) |
                    (SYS_GPA_MFPL_PA3MFP_SPI0_SS |
                     SYS_GPA_MFPL_PA2MFP_SPI0_CLK |
                     SYS_GPA_MFPL_PA1MFP_SPI0_MISO |
                     SYS_GPA_MFPL_PA0MFP_SPI0_MOSI);

    /* Update System Core Clock */
    /* User can use SystemCoreClockUpdate() to calculate SystemCoreClock and CyclesPerUs automatically. */
    SystemCoreClockUpdate();
}

void SPI_Init(void)
{
    /*---------------------------------------------------------------------------------------------------------*/
    /* Init SPI                                                                                                */
    /*---------------------------------------------------------------------------------------------------------*/
    /* Configure as a master, clock idle low, 32-bit transaction, drive output on falling clock edge and latch input on rising edge. */
    /* Set IP clock divider. SPI clock rate = 2MHz */
    SPI_Open(SPI0, SPI_MASTER, SPI_MODE_0, 32, SPI_CLK_FREQ);

    /* Enable the automatic hardware slave select function. Select the SS pin and configure as low-active. */
    SPI_EnableAutoSS(SPI0, SPI_SS, SPI_SS_ACTIVE_LOW);
}

/*** (C) COPYRIGHT 2016 Nuvoton Technology Corp. ***/
