/**************************************************************************//**
 * @file     main.c
 * @version  V3.00
 * @brief    Change system clock to different MIRC frequency and output system clock to CLKO pin.
 *
 * SPDX-License-Identifier: Apache-2.0
 * @copyright (C) 2025 Nuvoton Technology Corp. All rights reserved.
 ******************************************************************************/
#include "stdio.h"
#include "NuMicro.h"

#define SIGNATURE       0x125ab234
#define FLAG_ADDR       0x200007FC

/*------------------------------------------*/
/*  Brown Out Detector IRQ Handler          */
/*------------------------------------------*/
void BOD_IRQHandler(void)
{
    /* Clear BOD Interrupt Flag */
    SYS_CLEAR_BOD_INT_FLAG();

    printf("Brown Out is Detected\n");
}

/*------------------------------------------*/
/*  Simple calculation test function        */
/*------------------------------------------*/
#define PI_NUM  256
int32_t f[PI_NUM + 1];
uint32_t piTbl[19] =
{
    3141,
    5926,
    5358,
    9793,
    2384,
    6264,
    3383,
    2795,
    288,
    4197,
    1693,
    9937,
    5105,
    8209,
    7494,
    4592,
    3078,
    1640,
    6284
};

int32_t piResult[19];

int32_t pi(void)
{
    int32_t i, i32Err;
    int32_t a = 10000, b = 0, c = PI_NUM, d = 0, e = 0, g = 0;

    for(; b - c;)
        f[b++] = a / 5;

    i = 0;
    for(; d = 0, g = c * 2; c -= 14, piResult[i++] = e + d / a, e = d % a)
    {
        if(i == 19)
            break;

        for(b = c; d += f[b] * a, f[b] = d % --g, d /= g--, --b; d *= b);
    }
    i32Err = 0;
    for(i = 0; i < 19; i++)
    {
        if(piTbl[i] != piResult[i])
            i32Err = -1;
    }

    return i32Err;
}

void Delay(uint32_t x)
{
    int32_t i;

    for(i = 0; i < x; i++)
    {
        __NOP();
        __NOP();
    }
}

uint32_t g_au32MIRCSetting[] =
{
    FREQ_1MHZ,  /* MIRC = 1MHz,  HCLK = MIRC/1  */
    FREQ_12MHZ, /* MIRC = 12MHz, HCLK = MIRC/1  */
    FREQ_40MHZ  /* MIRC = 40MHz, HCLK = MIRC/1  */
};

void SYS_MIRC_Test(void)
{
    int32_t  i;

    /*------------------------------------------*/
    /* MIRC clock configuration test            */
    /*------------------------------------------*/

    printf("\n-------------------------[ Test MIRC ]----------------------------\n");
    printf("  Select HCLK clock source from MIRC/1.\n");
    printf("  Please measure HCLK on CLKO pin (PB.14) by scope ...\n");

    for(i = 0; i < sizeof(g_au32MIRCSetting) / sizeof(g_au32MIRCSetting[0]) ; i++)
    {
        /* Select HCLK clock source from MIRC.
           MIRC will be configured to specified frequency.
        */
        CLK_SetCoreClock(g_au32MIRCSetting[i]);

        printf("  Change system clock to %d Hz and calculate Pi .............. ", SystemCoreClock);

        /* Output HCLK to CKO, CKO Clock = HCLK / 1 */
        CLK_EnableCKO(CLK_CLKSEL1_CLKOSEL_HCLK, 0, 1);

        /* The delay loop is used to check if the CPU speed is increasing */
        Delay(0x1000000);

        if(pi())
        {
            printf("[FAIL]\n");
        }
        else
        {
            printf("[OK]\n");
        }

        /* Disable CLKO clock */
        CLK_DisableCKO();
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

    /* Update System Core Clock */
    /* User can use SystemCoreClockUpdate() to calculate SystemCoreClock and CyclesPerUs automatically. */
    SystemCoreClockUpdate();

    /* Switch UART0 clock source to HIRC */
    CLK_SetModuleClock(UART0_MODULE, CLK_CLKSEL2_UART0SEL_HIRC, CLK_CLKDIV_UART0(1));

    /* Enable UART clock */
    CLK_EnableModuleClock(UART0_MODULE);

    /*----------------------------------------------*/
    /* Init I/O Multi-function                      */
    /*----------------------------------------------*/
    /* Set multi-function pins for UART0 RXD(PB.12) and TXD(PB.13) */
    Uart0DefaultMPF();

    /* Set PB multi-function pins for CLKO(PB.14) */
    SYS->GPB_MFPH = (SYS->GPB_MFPH & ~(SYS_GPB_MFPH_PB14MFP_Msk)) |
                    (SYS_GPB_MFPH_PB14MFP_CLKO);
    /* Enable CLKO to output HCLK/1 */
    CLK_EnableCKO(CLK_CLKSEL1_CLKOSEL_HCLK, 0, 1);

    /* Lock protected registers */
    SYS_LockReg();
}

/*----------------------------------------------------------------------*/
/* Init UART0                                                           */
/*----------------------------------------------------------------------*/
void UART0_Init(void)
{
    /* Reset UART0 */
    SYS_ResetModule(UART0_RST);

    /* Configure UART0 and set UART0 baud rate */
    UART_Open(UART0, 115200);
}

int32_t main(void)
{
    uint32_t u32data;

    /* Init System, IP clock and multi-function I/O. */
    SYS_Init();

    /* Init UART0 for printf */
    UART0_Init();

    printf("\n\nCPU @ %dHz\n", SystemCoreClock);
    printf("+---------------------------------------+\n");
    printf("|      System Driver Sample Code        |\n");
    printf("+---------------------------------------+\n");

    if(M32(FLAG_ADDR) == SIGNATURE)
    {
        printf("  CPU Reset success!\n");
        M32(FLAG_ADDR) = 0;
        printf("  Press any key to continue ...\n");
        getchar();
    }

    /*---------------------------------------------------------------------------------------------------------*/
    /* Misc system function test                                                                               */
    /*---------------------------------------------------------------------------------------------------------*/

    /* Read Part Device ID */
    printf("Product ID 0x%x\n", SYS->PDID);

    /* Get reset source from last operation */
    u32data = SYS_GetResetSrc();
    printf("Reset Source 0x%x\n", u32data);

    /* Clear reset source */
    SYS_ClearResetSrc(u32data);

    /* Unlock protected registers for Brown-Out Detector settings */
    SYS_UnlockReg();

    /* Check if the write-protected registers are unlocked before BOD setting and CPU Reset */
    if(SYS_IsRegLocked() == 0)
    {
        printf("Protected Address is Unlocked\n");
    }

    /* Enable Brown-Out Detector and Low Voltage Reset function, and set Brown-Out Detector voltage 2.4V */
    SYS_EnableBOD(SYS_BODCTL_BOD_INTERRUPT_EN, SYS_BODCTL_BODVL_2_4V);

    /* Enable BOD interrupt */
    NVIC_EnableIRQ(BOD_IRQn);

    /* Run MIRC Test */
    SYS_MIRC_Test();

    /* Write a signature work to SRAM to check if it is reset by software */
    M32(FLAG_ADDR) = SIGNATURE;
    printf("\n\n  >>> Reset CPU <<<\n");

    /* Wait for message send out */
    UART_WAIT_TX_EMPTY(UART0);

    /* Select HCLK clock source as HIRC and HCLK source divider as 1 */
    CLK_SetHCLK(CLK_CLKSEL0_HCLKSEL_HIRC, CLK_HCLKDIV_HCLK(1));

    /* Disable MIRC */
    CLK_DisableMIRC();

    /* Reset CPU */
    SYS_ResetCPU();
}
