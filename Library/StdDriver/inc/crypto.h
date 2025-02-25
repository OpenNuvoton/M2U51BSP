/**************************************************************************//**
 * @file     crypto.h
 * @version  V3.00
 * @brief    Cryptographic Accelerator driver header file
 *
 * @copyright SPDX-License-Identifier: Apache-2.0
 * @copyright Copyright (C) 2020 Nuvoton Technology Corp. All rights reserved.
 ******************************************************************************/
#ifndef __CRPT_H__
#define __CRPT_H__

#ifdef __cplusplus
extern "C"
{
#endif

/** @addtogroup Standard_Driver Standard Driver
  @{
*/

/** @addtogroup CRPT_Driver CRYPTO Driver
  @{
*/


/** @addtogroup CRPT_EXPORTED_CONSTANTS CRPT Exported Constants
  @{
*/

#define AES_KEY_SIZE_128        (0UL)     /*!< AES select 128-bit key length           \hideinitializer */
#define AES_KEY_SIZE_192        (1UL)     /*!< AES select 192-bit key length           \hideinitializer */
#define AES_KEY_SIZE_256        (2UL)     /*!< AES select 256-bit key length           \hideinitializer */

#define AES_MODE_ECB            (0UL)     /*!< AES select ECB mode                     \hideinitializer */
#define AES_MODE_CBC            (1UL)     /*!< AES select CBC mode                     \hideinitializer */
#define AES_MODE_CFB            (2UL)     /*!< AES select CFB mode                     \hideinitializer */
#define AES_MODE_OFB            (3UL)     /*!< AES select OFB mode                     \hideinitializer */
#define AES_MODE_CTR            (4UL)     /*!< AES select CTR mode                     \hideinitializer */
#define AES_MODE_CBC_CS1        (0x10UL)  /*!< AES select CBC CS1 mode                 \hideinitializer */
#define AES_MODE_CBC_CS2        (0x11UL)  /*!< AES select CBC CS2 mode                 \hideinitializer */
#define AES_MODE_CBC_CS3        (0x12UL)  /*!< AES select CBC CS3 mode                 \hideinitializer */
#define AES_MODE_GCM            (0x20UL)
#define AES_MODE_GHASH          (0x21UL)
#define AES_MODE_CCM            (0x22UL)

#define AES_NO_SWAP             (0UL)     /*!< AES do not swap input and output data   \hideinitializer */
#define AES_OUT_SWAP            (1UL)     /*!< AES swap output data                    \hideinitializer */
#define AES_IN_SWAP             (2UL)     /*!< AES swap input data                     \hideinitializer */
#define AES_IN_OUT_SWAP         (3UL)     /*!< AES swap both input and output data     \hideinitializer */

#define CRYPTO_DMA_FIRST        (0x4UL)   /*!< Do first encrypt/decrypt in DMA cascade \hideinitializer */
#define CRYPTO_DMA_ONE_SHOT     (0x5UL)   /*!< Do one shot encrypt/decrypt with DMA      \hideinitializer */
#define CRYPTO_DMA_CONTINUE     (0x6UL)   /*!< Do continuous encrypt/decrypt in DMA cascade \hideinitializer */
#define CRYPTO_DMA_LAST         (0x7UL)   /*!< Do last encrypt/decrypt in DMA cascade          \hideinitializer */


/**@}*/ /* end of group CRPT_EXPORTED_CONSTANTS */


/** @addtogroup CRPT_EXPORTED_MACROS CRPT Exported Macros
  @{
*/

/*----------------------------------------------------------------------------------------------*/
/*  Macros                                                                                      */
/*----------------------------------------------------------------------------------------------*/

/**
  * @brief This macro enables AES interrupt.
  * @param crpt     Specified crypto module
  * @return None
  * \hideinitializer
  */
#define AES_ENABLE_INT(crpt)        ((crpt)->INTEN |= (CRPT_INTEN_AESIEN_Msk|CRPT_INTEN_AESEIEN_Msk))

/**
  * @brief This macro disables AES interrupt.
  * @param crpt     Specified crypto module
  * @return None
  * \hideinitializer
  */
#define AES_DISABLE_INT(crpt)       ((crpt)->INTEN &= ~(CRPT_INTEN_AESIEN_Msk|CRPT_INTEN_AESEIEN_Msk))

/**
  * @brief This macro gets AES interrupt flag.
  * @param crpt     Specified crypto module
  * @return AES interrupt flag.
  * \hideinitializer
  */
#define AES_GET_INT_FLAG(crpt)      ((crpt)->INTSTS & (CRPT_INTSTS_AESIF_Msk|CRPT_INTSTS_AESEIF_Msk))

/**
  * @brief This macro clears AES interrupt flag.
  * @param crpt     Specified crypto module
  * @return None
  * \hideinitializer
  */
#define AES_CLR_INT_FLAG(crpt)      ((crpt)->INTSTS = (CRPT_INTSTS_AESIF_Msk|CRPT_INTSTS_AESEIF_Msk))

/**
  * @brief This macro enables AES key protection.
  * @param crpt     Specified crypto module
  * @return None
  * \hideinitializer
  */
#define AES_ENABLE_KEY_PROTECT(crpt)  ((crpt)->AES_CTL |= CRPT_AES_CTL_KEYPRT_Msk)

/**
  * @brief This macro disables AES key protection.
  * @param crpt     Specified crypto module
  * @return None
  * \hideinitializer
  */
#define AES_DISABLE_KEY_PROTECT(crpt) ((crpt)->AES_CTL = ((crpt)->AES_CTL & ~CRPT_AES_CTL_KEYPRT_Msk) | (0x16UL<<CRPT_AES_CTL_KEYUNPRT_Pos)); \
                                      ((crpt)->AES_CTL &= ~CRPT_AES_CTL_KEYPRT_Msk)

/**@}*/ /* end of group CRPT_EXPORTED_MACROS */


/** @addtogroup CRPT_EXPORTED_FUNCTIONS CRPT Exported Functions
  @{
*/

/*---------------------------------------------------------------------------------------------------------*/
/*  Functions                                                                                      */
/*---------------------------------------------------------------------------------------------------------*/
void AES_Open(CRPT_T *crpt, uint32_t u32Channel, uint32_t u32EncDec, uint32_t u32OpMode, uint32_t u32KeySize, uint32_t u32SwapType);
void AES_Start(CRPT_T *crpt, int32_t u32Channel, uint32_t u32DMAMode);
void AES_SetKey(CRPT_T *crpt, uint32_t u32Channel, uint32_t au32Keys[], uint32_t u32KeySize);
void AES_SetInitVect(CRPT_T *crpt, uint32_t u32Channel, uint32_t au32IV[]);
void AES_SetDMATransfer(CRPT_T *crpt, uint32_t u32Channel, uint32_t u32SrcAddr, uint32_t u32DstAddr, uint32_t u32TransCnt);

/**@}*/ /* end of group CRPT_EXPORTED_FUNCTIONS */

/**@}*/ /* end of group CRPT_Driver */

/**@}*/ /* end of group Standard_Driver */

#ifdef __cplusplus
}
#endif

#endif  /* __CRPT_H__ */

