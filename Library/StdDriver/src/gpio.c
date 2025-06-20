/**************************************************************************//**
 * @file     gpio.c
 * @version  V1.00
 * @brief    M2U51 series GPIO driver source file
 *
 * SPDX-License-Identifier: Apache-2.0
 * @copyright (C) 2024 Nuvoton Technology Corp. All rights reserved.
*****************************************************************************/

#include "NuMicro.h"

/** @addtogroup Standard_Driver Standard Driver
  @{
*/

/** @addtogroup GPIO_Driver GPIO Driver
  @{
*/

/** @addtogroup GPIO_EXPORTED_FUNCTIONS GPIO Exported Functions
  @{
*/

/**
  * @brief      Set GPIO operation mode
  *
  * @param[in]  port        GPIO port. It could be \ref PA, \ref PB, \ref PC, \ref PD, \ref PE, \ref PF, \ref PG or \ref PH.
  * @param[in]  u32PinMask  The single or multiple pins of specified GPIO port.
  *                         - It could be \ref BIT0 ~ \ref BIT15 for PA, PB, PD and PE port.
  *                         - It could be \ref BIT0 ~ \ref BIT14 for PC and PF GPIO port.
  *                         - It could be \ref BIT2 ~ \ref BIT4  for PG GPIO port.
  *                         - It could be \ref BIT8 ~ \ref BIT9  for PH GPIO port.
  * @param[in]  u32Mode     Operation mode.  It could be \n
  *                         - \ref GPIO_MODE_INPUT
  *                         - \ref GPIO_MODE_OUTPUT
  *                         - \ref GPIO_MODE_OPEN_DRAIN
  *                         - \ref GPIO_MODE_QUASI
  *
  * @return     None
  *
  * @details    This function is used to set specified GPIO operation mode.
  */
void GPIO_SetMode(GPIO_T *port, uint32_t u32PinMask, uint32_t u32Mode)
{
    uint32_t i;

    for(i = 0ul; i < GPIO_PIN_MAX; i++)
    {
        if((u32PinMask & (1ul << i))==(1ul << i))
        {
            port->MODE = (port->MODE & ~(0x3ul << (i << 1))) | (u32Mode << (i << 1));
        }
    }
}

/**
  * @brief      Enable GPIO interrupt
  *
  * @param[in]  port        GPIO port. It could be \ref PA, \ref PB, \ref PC, \ref PD, \ref PE, \ref PF, \ref PG or \ref PH.
  * @param[in]  u32Pin      The pin of specified GPIO port.
  *                         - It could be 0 ~ 15 for PA, PB, PD and PE port.
  *                         - It could be 0 ~ 14 for PC and PF GPIO port.
  *                         - It could be 2 ~ 4  for PG GPIO port.
  *                         - It could be 8 ~ 9  for PH GPIO port.
  * @param[in]  u32IntAttribs   The interrupt attribute of specified GPIO pin. It could be \n
  *                             - \ref GPIO_INT_RISING
  *                             - \ref GPIO_INT_FALLING
  *                             - \ref GPIO_INT_BOTH_EDGE
  *                             - \ref GPIO_INT_HIGH
  *                             - \ref GPIO_INT_LOW
  *
  * @return     None
  *
  * @details    This function is used to enable specified GPIO pin interrupt.
  */
void GPIO_EnableInt(GPIO_T *port, uint32_t u32Pin, uint32_t u32IntAttribs)
{
    port->INTTYPE = (port->INTTYPE&~(1ul<<u32Pin)) | (((u32IntAttribs >> 24) & 0xFFUL) << u32Pin);
    port->INTEN = (port->INTEN&~(0x00010001ul<<u32Pin)) | ((u32IntAttribs & 0xFFFFFFUL) << u32Pin);
}

/**
  * @brief      Disable GPIO interrupt
  *
  * @param[in]  port    GPIO port. It could be \ref PA, \ref PB, \ref PC, \ref PD, \ref PE, \ref PF, \ref PG or \ref PH.
  * @param[in]  u32Pin  The pin of specified GPIO port.
  *                     - It could be 0 ~ 15 for PA, PB, PD and PE port.
  *                     - It could be 0 ~ 14 for PC and PF GPIO port.
  *                     - It could be 2 ~ 4  for PG GPIO port.
  *                     - It could be 8 ~ 9  for PH GPIO port.
  *
  * @return     None
  *
  * @details    This function is used to disable specified GPIO pin interrupt.
  */
void GPIO_DisableInt(GPIO_T *port, uint32_t u32Pin)
{
    port->INTTYPE &= ~(1UL << u32Pin);
    port->INTEN &= ~((0x00010001UL) << u32Pin);
}

/**
 * @brief       Set GPIO slew rate control
 *
 * @param[in]   port        GPIO port. It could be \ref PA, \ref PB, \ref PC, \ref PD, \ref PE, \ref PF, \ref PG or \ref PH.
 * @param[in]   u32PinMask  The single or multiple pins of specified GPIO port.
 *                          - It could be \ref BIT0 ~ \ref BIT15 for PA, PB, PD and PE port.
 *                          - It could be \ref BIT0 ~ \ref BIT14 for PC and PF GPIO port.
 *                          - It could be \ref BIT2 ~ \ref BIT4  for PG GPIO port.
 *                          - It could be \ref BIT8 ~ \ref BIT9  for PH GPIO port.
 * @param[in]   u32Mode     Slew rate mode.
 *                          - \ref GPIO_SLEWCTL_NORMAL
 *                          - \ref GPIO_SLEWCTL_HIGH
 *
 * @return      None
 *
 * @details     This function is used to set specified GPIO operation mode.
 */
void GPIO_SetSlewCtl(GPIO_T *port, uint32_t u32PinMask, uint32_t u32Mode)
{
    uint32_t i;

    for(i = 0ul; i < GPIO_PIN_MAX; i++)
    {
        if(u32PinMask & (1ul << i))
        {
            port->SLEWCTL = (port->SLEWCTL & ~(0x3ul << (i << 1))) | (u32Mode << (i << 1));
        }
    }
}

/**
  * @brief      Set GPIO Pull-up and Pull-down control
  *
  * @param[in]  port        GPIO port. It could be \ref PA, \ref PB, \ref PC, \ref PD, \ref PE, \ref PF, \ref PG or \ref PH.
  * @param[in]  u32PinMask  The single or multiple pins of specified GPIO port.
  *                         - It could be \ref BIT0 ~ \ref BIT15 for PA, PB, PD and PE port.
  *                         - It could be \ref BIT0 ~ \ref BIT14 for PC and PF GPIO port.
  *                         - It could be \ref BIT2 ~ \ref BIT4  for PG GPIO port.
  *                         - It could be \ref BIT8 ~ \ref BIT9  for PH GPIO port.
  * @param[in]  u32Mode     The pin mode of specified GPIO pin. It could be
  *                         - \ref GPIO_PUSEL_DISABLE
  *                         - \ref GPIO_PUSEL_PULL_UP
  *                         - \ref GPIO_PUSEL_PULL_DOWN
  *
  * @return     None
  *
  * @details    Set the pin mode of specified GPIO pin.
  */
void GPIO_SetPullCtl(GPIO_T *port, uint32_t u32PinMask, uint32_t u32Mode)
{
    uint32_t i;

    for(i = 0ul; i < GPIO_PIN_MAX; i++)
    {
        if(u32PinMask & (1ul << i))
        {
            port->PUSEL = (port->PUSEL & ~(0x3ul << (i << 1))) | (u32Mode << (i << 1));
        }
    }
}

/**
  * @brief      Enable GPIO Auto Operation mode
  *
  * @param[in]  u32PortMask The GPIO port mask to enable auto operation mode. It could be
  *                         - \ref GPIO_AUTO_ALL
  *                         - \ref GPIO_AUTO_PA
  *                         - \ref GPIO_AUTO_PB
  *                         - \ref GPIO_AUTO_PC
  *                         - \ref GPIO_AUTO_PD
  *                         - \ref GPIO_AUTO_PE
  *                         - \ref GPIO_AUTO_PF
  *                         - \ref GPIO_AUTO_PG
  *                         - \ref GPIO_AUTO_PH
  *
  * @return     None
  *
  * @details    This function is used to enable specified GPIO auto operation mode.
  */
void GPIO_EnableAuto(uint32_t u32PortMask)
{
    GPIO->AUTOCTL |= (GPIO_AUTOCTL_PDMAAOEN_Msk | u32PortMask);
}

/**
  * @brief      Disable GPIO Auto Operation mode
  *
  * @param[in]  u32PortMask The GPIO port mask to disable auto operation mode. It could be
  *                         - \ref GPIO_AUTO_ALL
  *                         - \ref GPIO_AUTO_PA
  *                         - \ref GPIO_AUTO_PB
  *                         - \ref GPIO_AUTO_PC
  *                         - \ref GPIO_AUTO_PD
  *                         - \ref GPIO_AUTO_PE
  *                         - \ref GPIO_AUTO_PF
  *                         - \ref GPIO_AUTO_PG
  *                         - \ref GPIO_AUTO_PH
  *
  * @return     None
  *
  * @details    This function is used to disable specified GPIO auto operation mode.
  */
void GPIO_DisableAuto(uint32_t u32PortMask)
{
    GPIO->AUTOCTL &= ~(u32PortMask);

    if ((GPIO->AUTOCTL & GPIO_AUTO_ALL) == 0)
        GPIO->AUTOCTL &= ~(GPIO_AUTOCTL_PDMAAOEN_Msk);
}

/*@}*/ /* end of group GPIO_EXPORTED_FUNCTIONS */

/*@}*/ /* end of group GPIO_Driver */

/*@}*/ /* end of group Standard_Driver */

/*** (C) COPYRIGHT 2024 Nuvoton Technology Corp. ***/
