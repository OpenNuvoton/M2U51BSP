/****************************************************************************
 * @file     main.c
 * @version  V3.00
 * @brief    Transmit and receive UART data with PDMA.
 *
 * SPDX-License-Identifier: Apache-2.0
 * @copyright (C) 2025 Nuvoton Technology Corp. All rights reserved.
 ******************************************************************************/
#include <stdio.h>
#include "NuMicro.h"

//#define ENABLE_PDMA_INTERRUPT
#define PDMA_TEST_LENGTH   128

/*---------------------------------------------------------------------------------------------------------*/
/* Global variables                                                                                        */
/*---------------------------------------------------------------------------------------------------------*/
uint8_t g_u8Tx_Buffer[PDMA_TEST_LENGTH] = {0};
uint8_t g_u8Rx_Buffer[PDMA_TEST_LENGTH] = {0};

volatile uint32_t u32IsTestOver = 0;

/*---------------------------------------------------------------------------------------------------------*/
/* Define functions prototype                                                                              */
/*---------------------------------------------------------------------------------------------------------*/
void USCI_UART_PDMATest(void);

void PDMA0_IRQHandler(void)
{
    uint32_t status = PDMA_GET_INT_STATUS(PDMA0);

    if (status & 0x1)   /* abort */
    {
        printf("target abort interrupt !!\n");
        if (PDMA_GET_ABORT_STS(PDMA0) & 0x4)
            u32IsTestOver = 2;
        PDMA_CLR_ABORT_FLAG(PDMA0,PDMA_GET_ABORT_STS(PDMA0));
    }
    else if (status & 0x2)     /* done */
    {
        if ( (PDMA_GET_TD_STS(PDMA0) & (1 << 0)) && (PDMA_GET_TD_STS(PDMA0) & (1 << 1)) )
        {
            u32IsTestOver = 1;
            PDMA_CLR_TD_FLAG(PDMA0,PDMA_GET_TD_STS(PDMA0));
        }
    }
    else if (status & 0x300)     /* channel 2 timeout */
    {
        printf("timeout interrupt !!\n");
        u32IsTestOver = 3;
        PDMA_CLR_TMOUT_FLAG(PDMA0,0);
        PDMA_CLR_TMOUT_FLAG(PDMA0,1);
    }
    else
        printf("unknown interrupt !!\n");
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

    /* Set PCLK0/PCLK1 to HCLK/2 */
    CLK->PCLKDIV = (CLK_PCLKDIV_APB0DIV_DIV2 | CLK_PCLKDIV_APB1DIV_DIV2);

    /* Update System Core Clock */
    /* User can use SystemCoreClockUpdate() to calculate SystemCoreClock and cyclesPerUs automatically. */
    SystemCoreClockUpdate();

    /* Switch UART0 clock source to HIRC */
    CLK_SetModuleClock(UART0_MODULE, CLK_CLKSEL2_UART0SEL_HIRC, CLK_CLKDIV_UART0(1));

    /* Enable UART clock */
    CLK_EnableModuleClock(UART0_MODULE);

    /* Enable USCI clock */
    CLK_EnableModuleClock(USCI0_MODULE);

    /* Enable PDMA0 module clock */
    CLK_EnableModuleClock(PDMA0_MODULE);

    /* Set PB multi-function pins for UART0 RXD=PB.12 and TXD=PB.13 */
    Uart0DefaultMPF();

    /* Set PA multi-function pins for USCI0_DAT0(PA.10) and USCI0_DAT1(PA.9) */
    SYS->GPA_MFPH &= ~(SYS_GPA_MFPH_PA9MFP_Msk | SYS_GPA_MFPH_PA10MFP_Msk);
    SYS->GPA_MFPH |= (SYS_GPA_MFPH_PA9MFP_USCI0_DAT1 |SYS_GPA_MFPH_PA10MFP_USCI0_DAT0);

    /* Lock protected registers */
    SYS_LockReg();
}

void UART0_Init(void)
{
    /* Configure UART0 and set UART0 baud rate */
    UART_Open(UART0, 115200);
}

void USCI0_Init(void)
{
    /* Configure USCI0 as UART mode */
    UUART_Open(UUART0, 115200);
}

void PDMA_Init(void)
{
    /* Open PDMA Channel */
    PDMA_Open(PDMA0,1 << 0); // Channel 0 for UUART0 TX
    PDMA_Open(PDMA0,1 << 1); // Channel 1 for UUART0 RX
    // Select basic mode
    PDMA_SetTransferMode(PDMA0,0, PDMA_USCI0_TX, 0, 0);
    PDMA_SetTransferMode(PDMA0,1, PDMA_USCI0_RX, 0, 0);
    // Set data width and transfer count
    PDMA_SetTransferCnt(PDMA0,0, PDMA_WIDTH_8, PDMA_TEST_LENGTH);
    PDMA_SetTransferCnt(PDMA0,1, PDMA_WIDTH_8, PDMA_TEST_LENGTH);
    //Set PDMA Transfer Address
    PDMA_SetTransferAddr(PDMA0,0, ((uint32_t) (&g_u8Tx_Buffer[0])), PDMA_SAR_INC, (uint32_t)(&(UUART0->TXDAT)), PDMA_DAR_FIX);
    PDMA_SetTransferAddr(PDMA0,1, (uint32_t)(&(UUART0->RXDAT)), PDMA_SAR_FIX, ((uint32_t) (&g_u8Rx_Buffer[0])), PDMA_DAR_INC);
    //Select Single Request
    PDMA_SetBurstType(PDMA0,0, PDMA_REQ_SINGLE, 0);
    PDMA_SetBurstType(PDMA0,1, PDMA_REQ_SINGLE, 0);
    //Set timeout
    //PDMA_SetTimeOut(PDMA0, 0, 0, 0x5555);
    //PDMA_SetTimeOut(PDMA0, 1, 0, 0x5555);

#ifdef ENABLE_PDMA_INTERRUPT
    PDMA_EnableInt(PDMA0, 0, PDMA_INT_TRANS_DONE);
    PDMA_EnableInt(PDMA0, 1, PDMA_INT_TRANS_DONE);
    NVIC_EnableIRQ(PDMA0_IRQn);
    u32IsTestOver = 0;
#endif
}

/*---------------------------------------------------------------------------------------------------------*/
/*  Main Function                                                                                          */
/*---------------------------------------------------------------------------------------------------------*/
int32_t main(void)
{
    /* Init System, peripheral clock and multi-function I/O */
    SYS_Init();

    /* Init UART0 for printf */
    UART0_Init();

    /* Init USCI0 */
    USCI0_Init();

    /*---------------------------------------------------------------------------------------------------------*/
    /* SAMPLE CODE                                                                                             */
    /*---------------------------------------------------------------------------------------------------------*/

    printf("\n\nCPU @ %d Hz\n", SystemCoreClock);

    printf("\nUSCI UART Sample Program\n");

    /* USCI UART sample function */
    USCI_UART_PDMATest();

    while(1);

}

/*---------------------------------------------------------------------------------------------------------*/
/*  USCI UART Function Test                                                                                */
/*---------------------------------------------------------------------------------------------------------*/
void USCI_UART_PDMATest(void)
{
    uint32_t i;

    printf("+-----------------------------------------------------------+\n");
    printf("|  USCI UART PDMA Test                                      |\n");
    printf("+-----------------------------------------------------------+\n");
    printf("|  Description :                                            |\n");
    printf("|    The sample code will demo USCI_UART PDMA function      |\n");
    printf("|    Please connect USCI0_UART_TX and USCI0_UART_RX pin.    |\n");
    printf("+-----------------------------------------------------------+\n");
    printf("Please press any key to start test. \n\n");

    getchar();

    for (i = 0; i < PDMA_TEST_LENGTH; i++)
    {
        g_u8Tx_Buffer[i] = i;
        g_u8Rx_Buffer[i] = 0xff;
    }

    /* PDMA reset */
    UUART0->PDMACTL |= UUART_PDMACTL_PDMARST_Msk;
    while( UUART0->PDMACTL & UUART_PDMACTL_PDMARST_Msk );

    PDMA_Init();

    /* Enable UART DMA Tx and Rx */
    UUART0->PDMACTL = UUART_PDMACTL_TXPDMAEN_Msk | UUART_PDMACTL_RXPDMAEN_Msk | UUART_PDMACTL_PDMAEN_Msk;

#ifdef ENABLE_PDMA_INTERRUPT
    while(u32IsTestOver == 0);

    if (u32IsTestOver == 1)
        printf("test done...\n");
    else if (u32IsTestOver == 2)
        printf("target abort...\n");
    else if (u32IsTestOver == 3)
        printf("timeout...\n");
#else
    while( (!(PDMA_GET_TD_STS(PDMA0)&PDMA_TDSTS_TDIF0_Msk) || (!(PDMA_GET_TD_STS(PDMA0)&PDMA_TDSTS_TDIF1_Msk))) );

    PDMA_CLR_TD_FLAG(PDMA0,PDMA_TDSTS_TDIF0_Msk|PDMA_TDSTS_TDIF1_Msk);
#endif

    for (i=0; i<PDMA_TEST_LENGTH; i++)
    {
        if(g_u8Rx_Buffer[i] != i)
        {
            printf("\n Receive Data Compare Error !!");
            while(1);
        }

    }

    printf("\nUART PDMA test Pass.\n");

}
