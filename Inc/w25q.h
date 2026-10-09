/*
 * Copyright (c) 2026 Maxim Pekurin
 * Licensed under the MIT License.
 */

#ifndef W25Q_H
#define W25Q_H

#ifdef __cplusplus
extern "C" {
#endif

#include "main.h"

/* --- Configuration Defaults --- */

// Default timeout for commands (can be overridden in main.h or preprocessor)
#ifndef W25Q_TIMEOUT_VALUE
  #define W25Q_TIMEOUT_VALUE 5000U
#endif

// Default Flash Bank for OSPI (can be overridden)
// Has no effect on QSPI implementation
#ifndef W25Q_OSPI_FLASH_ID
  #define W25Q_OSPI_FLASH_ID HAL_OSPI_FLASH_ID_1
#endif

// Addressing mode: 24-bit by default, which reaches the first 16MB only.
// Define W25Q_32BIT_MODE (in main.h or preprocessor) for 32-bit addressing, needed to reach memory above 16MB
// (256Mb chips and larger, e.g. W25Q512JV). The chip must then be put in 4-byte address mode with
// W25Q_Enter4BytesMode after each reset.
#if defined(W25Q_24BIT_MODE) && defined(W25Q_32BIT_MODE)
  #error "W25Q_24BIT_MODE and W25Q_32BIT_MODE are exclusive"
#endif

/* --- Flash Geometry --- */

#define W25Q_FLASH_BASE           0x00000000U
#define W25Q_PAGE_SIZE            256U
#define W25Q_SECTOR_SIZE          4096U
#define W25Q_32KB_BLOCK_SIZE      32768U
#define W25Q_64KB_BLOCK_SIZE      65536U
#define W25Q_PAGE_ADDR_MASK       0xFFFFFF00U
#define W25Q_SECTOR_ADDR_MASK     0xFFFFF000U
#define W25Q_32KB_BLOCK_ADDR_MASK 0xFFFF8000U
#define W25Q_64KB_BLOCK_ADDR_MASK 0xFFFF0000U

/* --- Status Register Definitions --- */

// Bits definition for status register 1
// This list doesn't include bits [6:2] as they depend on the chip used
// In some datasheets the SRP bit is named SRP0, however it performs the same function
#define W25Q_SR1_BUSY_POS  (0U)
#define W25Q_SR1_BUSY_MASK (1U << W25Q_SR1_BUSY_POS)
#define W25Q_SR1_BUSY      W25Q_SR1_BUSY_MASK
#define W25Q_SR1_WEL_POS   (1U)
#define W25Q_SR1_WEL_MASK  (1U << W25Q_SR1_WEL_POS)
#define W25Q_SR1_WEL       W25Q_SR1_WEL_MASK
#define W25Q_SR1_SRP_POS   (7U)
#define W25Q_SR1_SRP_MASK  (1U << W25Q_SR1_SRP_POS)
#define W25Q_SR1_SRP       W25Q_SR1_SRP_MASK

// Bits definition for status register 2
// The SFDP bit is only available on some chips
// In some datasheets the SRL bit is named SRP1, however it performs the same function
#define W25Q_SR2_SRL_POS   (0U)
#define W25Q_SR2_SRL_MASK  (1U << W25Q_SR2_SRL_POS)
#define W25Q_SR2_SRL       W25Q_SR2_SRL_MASK
#define W25Q_SR2_QE_POS    (1U)
#define W25Q_SR2_QE_MASK   (1U << W25Q_SR2_QE_POS)
#define W25Q_SR2_QE        W25Q_SR2_QE_MASK
#define W25Q_SR2_SFDP_POS  (2U)
#define W25Q_SR2_SFDP_MASK (1U << W25Q_SR2_SFDP_POS)
#define W25Q_SR2_SFDP      W25Q_SR2_SFDP_MASK
#define W25Q_SR2_LB1_POS   (3U)
#define W25Q_SR2_LB1_MASK  (1U << W25Q_SR2_LB1_POS)
#define W25Q_SR2_LB1       W25Q_SR2_LB1_MASK
#define W25Q_SR2_LB2_POS   (4U)
#define W25Q_SR2_LB2_MASK  (1U << W25Q_SR2_LB2_POS)
#define W25Q_SR2_LB2       W25Q_SR2_LB2_MASK
#define W25Q_SR2_LB3_POS   (5U)
#define W25Q_SR2_LB3_MASK  (1U << W25Q_SR2_LB3_POS)
#define W25Q_SR2_LB3       W25Q_SR2_LB3_MASK
#define W25Q_SR2_CMP_POS   (6U)
#define W25Q_SR2_CMP_MASK  (1U << W25Q_SR2_CMP_POS)
#define W25Q_SR2_CMP       W25Q_SR2_CMP_MASK
#define W25Q_SR2_SUS_POS   (7U)
#define W25Q_SR2_SUS_MASK  (1U << W25Q_SR2_SUS_POS)
#define W25Q_SR2_SUS       W25Q_SR2_SUS_MASK

// Bits definition for status register 3
// The HOLD bit is only available on some chips
// The ADS and ADP bits are only available on chips with 256Mb of memory or more
#define W25Q_SR3_ADS_POS   (0U)
#define W25Q_SR3_ADS_MASK  (1U << W25Q_SR3_ADS_POS)
#define W25Q_SR3_ADS       W25Q_SR3_ADS_MASK
#define W25Q_SR3_ADP_POS   (1U)
#define W25Q_SR3_ADP_MASK  (1U << W25Q_SR3_ADP_POS)
#define W25Q_SR3_ADP       W25Q_SR3_ADP_MASK
#define W25Q_SR3_WPS_POS   (2U)
#define W25Q_SR3_WPS_MASK  (1U << W25Q_SR3_WPS_POS)
#define W25Q_SR3_WPS       W25Q_SR3_WPS_MASK
#define W25Q_SR3_DRV0_POS  (5U)
#define W25Q_SR3_DRV0_MASK (1U << W25Q_SR3_DRV0_POS)
#define W25Q_SR3_DRV0      W25Q_SR3_DRV0_MASK
#define W25Q_SR3_DRV1_POS  (6U)
#define W25Q_SR3_DRV1_MASK (1U << W25Q_SR3_DRV1_POS)
#define W25Q_SR3_DRV1      W25Q_SR3_DRV1_MASK
#define W25Q_SR3_HOLD_POS  (7U)
#define W25Q_SR3_HOLD_MASK (1U << W25Q_SR3_HOLD_POS)
#define W25Q_SR3_HOLD      W25Q_SR3_HOLD_MASK

/* --- Public Types --- */

typedef enum {
  W25Q_SR1 = 1U,
  W25Q_SR2 = 2U,
  W25Q_SR3 = 3U
} W25Q_StatusRegTypeDef;

typedef enum
{
  W25Q_WRAP_MODE_NONE      = 0x10U, // W[6:4] = 001
  W25Q_WRAP_MODE_8_BYTES   = 0x00U, // W[6:4] = 000
  W25Q_WRAP_MODE_16_BYTES  = 0x20U, // W[6:4] = 010
  W25Q_WRAP_MODE_32_BYTES  = 0x40U, // W[6:4] = 100
  W25Q_WRAP_MODE_64_BYTES  = 0x60U  // W[6:4] = 110
} W25Q_WrapModeTypeDef;

typedef enum
{
  W25Q_STATE_READY, // Ready to receive a command
  W25Q_STATE_BUSY,  // The BUSY bit is set or a transfer is ongoing
  W25Q_STATE_ERROR  // An OSPI/QSPI error happened
} W25Q_StateTypeDef;

#if defined(HAL_OSPI_MODULE_ENABLED)
  #define xSPI_HandleTypeDef OSPI_HandleTypeDef
#elif defined(HAL_QSPI_MODULE_ENABLED)
  #define xSPI_HandleTypeDef QSPI_HandleTypeDef
#endif

/* --- Public Function Prototypes --- */

HAL_StatusTypeDef W25Q_WriteEnable(xSPI_HandleTypeDef *hxspi);
HAL_StatusTypeDef W25Q_VolatileSrWriteEnable(xSPI_HandleTypeDef *hxspi);
HAL_StatusTypeDef W25Q_WriteDisable(xSPI_HandleTypeDef *hxspi);
HAL_StatusTypeDef W25Q_ReadStatusRegister(xSPI_HandleTypeDef *hxspi, W25Q_StatusRegTypeDef RegIndex, uint8_t *pRegValue);
HAL_StatusTypeDef W25Q_WriteStatusRegister(xSPI_HandleTypeDef *hxspi, W25Q_StatusRegTypeDef RegIndex, uint8_t RegValue);
HAL_StatusTypeDef W25Q_ReadData_DMA(xSPI_HandleTypeDef *hxspi, uint32_t Address, uint32_t Size, void *pData);
HAL_StatusTypeDef W25Q_FastRead_DMA(xSPI_HandleTypeDef *hxspi, uint32_t Address, uint32_t Size, void *pData);
HAL_StatusTypeDef W25Q_FastReadDualOutput_DMA(xSPI_HandleTypeDef *hxspi, uint32_t Address, uint32_t Size, void *pData);
HAL_StatusTypeDef W25Q_FastReadQuadOutput_DMA(xSPI_HandleTypeDef *hxspi, uint32_t Address, uint32_t Size, void *pData);
HAL_StatusTypeDef W25Q_FastReadDualIo_DMA(xSPI_HandleTypeDef *hxspi, uint32_t Address, uint32_t Size, void *pData);
HAL_StatusTypeDef W25Q_FastReadQuadIo_DMA(xSPI_HandleTypeDef *hxspi, uint32_t Address, uint32_t Size, void *pData);
HAL_StatusTypeDef W25Q_SetBurstWithWrap(xSPI_HandleTypeDef *hxspi, W25Q_WrapModeTypeDef WrapMode);
HAL_StatusTypeDef W25Q_PageProgram_DMA(xSPI_HandleTypeDef *hxspi, uint32_t Address, uint16_t Size, void *pData);
HAL_StatusTypeDef W25Q_PageProgramQuadInput_DMA(xSPI_HandleTypeDef *hxspi, uint32_t Address, uint16_t Size, void *pData);
HAL_StatusTypeDef W25Q_Erase4KB(xSPI_HandleTypeDef *hxspi, uint32_t Address);
HAL_StatusTypeDef W25Q_Erase32KB(xSPI_HandleTypeDef *hxspi, uint32_t Address);
HAL_StatusTypeDef W25Q_Erase64KB(xSPI_HandleTypeDef *hxspi, uint32_t Address);
HAL_StatusTypeDef W25Q_ChipErase(xSPI_HandleTypeDef *hxspi);
HAL_StatusTypeDef W25Q_Suspend(xSPI_HandleTypeDef *hxspi);
HAL_StatusTypeDef W25Q_Resume(xSPI_HandleTypeDef *hxspi);
HAL_StatusTypeDef W25Q_PowerDown(xSPI_HandleTypeDef *hxspi);
HAL_StatusTypeDef W25Q_ReleasePowerDown(xSPI_HandleTypeDef *hxspi);
HAL_StatusTypeDef W25Q_ReadDeviceId(xSPI_HandleTypeDef *hxspi, uint8_t *pDeviceId);
HAL_StatusTypeDef W25Q_ReadDeviceIdDualIo(xSPI_HandleTypeDef *hxspi, uint8_t *pDeviceId);
HAL_StatusTypeDef W25Q_ReadDeviceIdQuadIo(xSPI_HandleTypeDef *hxspi, uint8_t *pDeviceId);
HAL_StatusTypeDef W25Q_ReadUniqueId(xSPI_HandleTypeDef *hxspi, uint64_t *pUniqueId);
HAL_StatusTypeDef W25Q_ReadJedecId(xSPI_HandleTypeDef *hxspi, uint8_t *pManufacturerId, uint8_t *pMemoryTypeId, uint8_t *pCapacityId);
HAL_StatusTypeDef W25Q_EraseSecurityRegister(xSPI_HandleTypeDef *hxspi, uint8_t RegIndex);
HAL_StatusTypeDef W25Q_ProgramSecurityRegister_DMA(xSPI_HandleTypeDef *hxspi, uint8_t RegIndex, uint8_t Address, uint16_t Size, void *pData);
HAL_StatusTypeDef W25Q_ReadSecurityRegister_DMA(xSPI_HandleTypeDef *hxspi, uint8_t RegIndex, uint8_t Address, uint16_t Size, void *pData);
HAL_StatusTypeDef W25Q_IndividualLock(xSPI_HandleTypeDef *hxspi, uint32_t Address);
HAL_StatusTypeDef W25Q_IndividualUnlock(xSPI_HandleTypeDef *hxspi, uint32_t Address);
HAL_StatusTypeDef W25Q_ReadLockState(xSPI_HandleTypeDef *hxspi, uint32_t Address, uint8_t *pLockState);
HAL_StatusTypeDef W25Q_GlobalLock(xSPI_HandleTypeDef *hxspi);
HAL_StatusTypeDef W25Q_GlobalUnlock(xSPI_HandleTypeDef *hxspi);
HAL_StatusTypeDef W25Q_EnableReset(xSPI_HandleTypeDef *hxspi);
HAL_StatusTypeDef W25Q_ResetDevice(xSPI_HandleTypeDef *hxspi);
HAL_StatusTypeDef W25Q_Enter4BytesMode(xSPI_HandleTypeDef *hxspi);
HAL_StatusTypeDef W25Q_Exit4BytesMode(xSPI_HandleTypeDef *hxspi);

HAL_StatusTypeDef W25Q_BusyFlagPolling_IT(xSPI_HandleTypeDef *hxspi);

W25Q_StateTypeDef W25Q_GetState(xSPI_HandleTypeDef *hxspi);

#ifdef __cplusplus
}
#endif

#endif // W25Q_H
