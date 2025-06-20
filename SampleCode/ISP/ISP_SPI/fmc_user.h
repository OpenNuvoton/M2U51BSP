/***************************************************************************//**
 * @file     fmc_user.h
 * @brief    M2U51 series FMC driver header file
 * @version  2.0.0
 *
 * SPDX-License-Identifier: Apache-2.0
 * @copyright (C) 2016 Nuvoton Technology Corp. All rights reserved.
 ******************************************************************************/
#ifndef FMC_USER_H
#define FMC_USER_H

#include "targetdev.h"

extern int FMC_Proc(uint32_t u32Cmd, uint32_t addr_start, uint32_t addr_end, uint32_t *data);


#define Config0         FMC_CONFIG_BASE
#define Config1         (FMC_CONFIG_BASE+4)

#define ISPGO           0x01


/**
 * @brief       Read 32-bit Data from specified address of flash
 *
 * @param[in]   u32addr  Flash address include APROM, LDROM, Data Flash, and CONFIG
 *
 * @return      The data of specified address
 *
 * @details     To read word data from Flash include APROM, LDROM, Data Flash, and CONFIG.
 *
 * @note
 *              Please make sure that Register Write-Protection Function has been disabled
 *              before using this function. User can check the status of
 *              Register Write-Protection Function with DrvSYS_IsProtectedRegLocked().
 */
#define FMC_Read_User(u32Addr, data) (FMC_Proc(FMC_ISPCMD_READ, u32Addr, (u32Addr) + 4, data))

/**
 * @brief      Flash page erase
 *
 * @param[in]  u32addr  Flash address including APROM, LDROM, Data Flash, and CONFIG
 *
 * @details    To do flash page erase. The target address could be APROM, LDROM, Data Flash, or CONFIG.
 *             The page size is 512 bytes.
 *
 * @note
 *             Please make sure that Register Write-Protection Function has been disabled
 *             before using this function. User can check the status of
 *             Register Write-Protection Function with DrvSYS_IsProtectedRegLocked().
 */
#define FMC_Erase_User(u32Addr) (FMC_Proc(FMC_ISPCMD_PAGE_ERASE, u32Addr, (u32Addr) + 4, 0))

#define ReadData(addr_start, addr_end, data) (FMC_Proc(FMC_ISPCMD_READ, addr_start, addr_end, data))
#define WriteData(addr_start, addr_end, data) (FMC_Proc(FMC_ISPCMD_PROGRAM, addr_start, addr_end, data))
#define EraseAP(addr_start, size) (FMC_Proc(FMC_ISPCMD_PAGE_ERASE, addr_start, (addr_start) + (size), NULL))

extern void UpdateConfig(uint32_t *data, uint32_t *res);

#endif

