/**************************************************************************//**
 * @file     main.c
 * @version  V3.00
 * @brief    Show how a 10-bit address slave receives data from a master.
 *           This sample code needs to work with USCI_I2C_Master_10bit.
 *
 * SPDX-License-Identifier: Apache-2.0
 * @copyright (C) 2025 Nuvoton Technology Corp. All rights reserved.
*****************************************************************************/
#include <stdio.h>
#include "NuMicro.h"

#define SLV_10BIT_ADDR (0x1E<<2)             //1111+0xx+r/w

/*---------------------------------------------------------------------------------------------------------*/
/* Global variables                                                                                        */
/*---------------------------------------------------------------------------------------------------------*/
uint8_t g_u8SlvData[256];
uint8_t g_au8SlvRxData[4];
volatile uint32_t slave_buff_addr;
volatile uint16_t g_u16SlvRcvAddr;
volatile uint8_t g_u8SlvDataLen;

volatile enum UI2C_SLAVE_EVENT s_Event;

typedef void (*UI2C_FUNC)(uint32_t u32Status);

volatile static UI2C_FUNC s_UI2C0HandlerFn = NULL;


void USCI0_IRQHandler(void)
{
    uint32_t u32Status;

    //UI2C0 Interrupt
    u32Status = UI2C_GET_PROT_STATUS(UI2C0);
    if(s_UI2C0HandlerFn != NULL)
    {
        s_UI2C0HandlerFn(u32Status);
    }
}

/*---------------------------------------------------------------------------------------------------------*/
/*  USCI_I2C0 TRx Callback Function                                                                        */
/*---------------------------------------------------------------------------------------------------------*/
void UI2C_SlaveTRx(uint32_t u32Status)
{
    uint32_t temp;

    if((u32Status & UI2C_PROTSTS_STARIF_Msk) == UI2C_PROTSTS_STARIF_Msk)
    {
        /* Clear START INT Flag */
        UI2C_CLR_PROT_INT_FLAG(UI2C0, UI2C_PROTSTS_STARIF_Msk);

        /* Event process */
        g_u8SlvDataLen = 0;
        s_Event = SLAVE_H_RD_ADDRESS_ACK;

        UI2C_SET_CONTROL_REG(UI2C0, (UI2C_CTL_PTRG | UI2C_CTL_AA));
    }
    else if((u32Status & UI2C_PROTSTS_ACKIF_Msk) == UI2C_PROTSTS_ACKIF_Msk)
    {
        /* Clear ACK INT Flag */
        UI2C_CLR_PROT_INT_FLAG(UI2C0, UI2C_PROTSTS_ACKIF_Msk);

        /* Event process */
        if(s_Event == SLAVE_H_WR_ADDRESS_ACK)
        {
            g_u8SlvDataLen = 0;

            s_Event = SLAVE_L_WR_ADDRESS_ACK;
            g_u16SlvRcvAddr = (uint8_t)UI2C_GET_DATA(UI2C0);
        }
        else if(s_Event == SLAVE_H_RD_ADDRESS_ACK)
        {
            g_u8SlvDataLen = 0;

            UI2C_SET_DATA(UI2C0, g_u8SlvData[slave_buff_addr]);
            slave_buff_addr++;
            g_u16SlvRcvAddr = (uint8_t)UI2C_GET_DATA(UI2C0);
        }
        else if(s_Event == SLAVE_L_WR_ADDRESS_ACK)
        {
            g_u8SlvDataLen = 0;
            if((UI2C0->PROTSTS & UI2C_PROTSTS_SLAREAD_Msk) == UI2C_PROTSTS_SLAREAD_Msk)
            {
                UI2C_SET_DATA(UI2C0, g_u8SlvData[slave_buff_addr]);
                slave_buff_addr++;
            }
            else
            {
                s_Event = SLAVE_GET_DATA;
            }
            g_u16SlvRcvAddr = (uint8_t)UI2C_GET_DATA(UI2C0);
            g_u16SlvRcvAddr = (uint8_t)UI2C_GET_DATA(UI2C0);
        }
        else if(s_Event == SLAVE_L_RD_ADDRESS_ACK)
        {
            UI2C_SET_DATA(UI2C0, g_u8SlvData[slave_buff_addr]);
            slave_buff_addr++;
        }
        else if(s_Event == SLAVE_GET_DATA)
        {
            temp = UI2C_GET_DATA(UI2C0);
            g_au8SlvRxData[g_u8SlvDataLen] = temp;
            g_u8SlvDataLen++;

            if(g_u8SlvDataLen == 2)
            {
                slave_buff_addr = (g_au8SlvRxData[0] << 8) + g_au8SlvRxData[1];
            }
            if(g_u8SlvDataLen == 3)
            {
                g_u8SlvData[slave_buff_addr] = g_au8SlvRxData[2];
                g_u8SlvDataLen = 0;
            }
        }

        UI2C_SET_CONTROL_REG(UI2C0, (UI2C_CTL_PTRG | UI2C_CTL_AA));
    }
    else if((u32Status & UI2C_PROTSTS_NACKIF_Msk) == UI2C_PROTSTS_NACKIF_Msk)
    {
        /* Clear NACK INT Flag */
        UI2C_CLR_PROT_INT_FLAG(UI2C0, UI2C_PROTSTS_NACKIF_Msk);

        /* Event process */
        g_u8SlvDataLen = 0;
        s_Event = SLAVE_L_WR_ADDRESS_ACK;

        UI2C_SET_CONTROL_REG(UI2C0, (UI2C_CTL_PTRG | UI2C_CTL_AA));
    }
    else if((u32Status & UI2C_PROTSTS_STORIF_Msk) == UI2C_PROTSTS_STORIF_Msk)
    {
        /* Clear STOP INT Flag */
        UI2C_CLR_PROT_INT_FLAG(UI2C0, UI2C_PROTSTS_STORIF_Msk);

        /* Event process */
        g_u8SlvDataLen = 0;
        s_Event = SLAVE_L_WR_ADDRESS_ACK;

        UI2C_SET_CONTROL_REG(UI2C0, (UI2C_CTL_PTRG | UI2C_CTL_AA));
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

    /* Enable GPIO clock */
    CLK_EnableModuleClock(GPA_MODULE);

    /* Set PB multi-function pins for UART0 RXD=PB.12 and TXD=PB.13 */
    Uart0DefaultMPF();

    /* Set UI2C0 multi-function pins */
    SYS->GPA_MFPH = (SYS->GPA_MFPH & ~(SYS_GPA_MFPH_PA11MFP_Msk | SYS_GPA_MFPH_PA10MFP_Msk)) |
                    (SYS_GPA_MFPH_PA11MFP_USCI0_CLK | SYS_GPA_MFPH_PA10MFP_USCI0_DAT0);

    /* USCI_I2C pin enable schmitt trigger */
    PA->SMTEN |= GPIO_SMTEN_SMTEN10_Msk | GPIO_SMTEN_SMTEN11_Msk;

    /* Lock protected registers */
    SYS_LockReg();
}

void UI2C0_Init(uint32_t u32ClkSpeed)
{
    /* Open USCI_I2C0 and set clock to 100k */
    UI2C_Open(UI2C0, u32ClkSpeed);

    /* Enable I2C1 10-bit address mode */
    UI2C_ENABLE_10BIT_ADDR_MODE(UI2C0);

    /* Get USCI_I2C0 Bus Clock */
    printf("UI2C0 clock %d Hz\n", UI2C_GetBusClockFreq(UI2C0));

    /* Set USCI_I2C0 Slave Addresses */
    UI2C_SetSlaveAddr(UI2C0, 0, 0x115, UI2C_GCMODE_DISABLE);   /* Slave Address : 0x115 */
    UI2C_SetSlaveAddr(UI2C0, 1, 0x135, UI2C_GCMODE_DISABLE);   /* Slave Address : 0x135 */

    /* Set USCI_I2C0 Slave Addresses Mask */
    UI2C_SetSlaveAddrMask(UI2C0, 0, 0x01);                    /* Slave Address : 0x1 */
    UI2C_SetSlaveAddrMask(UI2C0, 1, 0x04);                    /* Slave Address : 0x4 */

    /* Enable UI2C0 protocol interrupt */
    UI2C_ENABLE_PROT_INT(UI2C0, (UI2C_PROTIEN_ACKIEN_Msk | UI2C_PROTIEN_NACKIEN_Msk | UI2C_PROTIEN_STORIEN_Msk | UI2C_PROTIEN_STARIEN_Msk));
    NVIC_EnableIRQ(USCI0_IRQn);
}

int main()
{
    uint32_t i;

    /* Init System, IP clock and multi-function I/O. */
    SYS_Init();

    /* Init UART for print message */
    UART_Open(UART0, 115200);

    /*
        This sample code sets USCI_I2C bus clock to 100kHz. Then, Master accesses Slave with Byte Write
        and Byte Read operations, and check if the read data is equal to the programmed data.
    */

    printf("+-------------------------------------------------------+\n");
    printf("|  USCI_I2C Driver Sample Code for Master access 10-bit |\n");
    printf("|  address (Slave). This sample code needs work with    |\n");
    printf("|  USCI_I2C_Master_10bit sample code.                   |\n");
    printf("|      UI2C_Master(UI2C0) < - > UI2C_Slave(UI2C0)       |\n");
    printf("|  This sample code requires two boards for testing     |\n");
    printf("+-------------------------------------------------------+\n");

    printf("\n");
    printf("Configure UI2C0 as Slave.\n");
    printf("The I/O connection for UI2C0:\n");
    printf("UI2C0_SDA(PA10), UI2C0_SCL(PA11)\n");

    /* Init USCI_I2C0 */
    UI2C0_Init(100000);

    s_Event = SLAVE_L_WR_ADDRESS_ACK;
    UI2C_SET_CONTROL_REG(UI2C0, (UI2C_CTL_PTRG | UI2C_CTL_AA));

    for(i = 0; i < 0x100; i++)
        g_u8SlvData[i] = 0;

    /* UI2C0 function to Slave receive/transmit data */
    s_UI2C0HandlerFn = UI2C_SlaveTRx;

    while(1);
}

/*** (C) COPYRIGHT 2025 Nuvoton Technology Corp. ***/
