# W25Q STM32 HAL Driver

A universal, hardware-abstracted driver for Winbond W25Q SPI Flash memories. Designed for STM32 microcontrollers.

**Key Features:**

*   **Universal Support:** Seamlessly works with both **QSPI** and **OSPI** peripherals (auto-detected via HAL definitions).
*   **Performance:** Optimized for DMA transfers.
*   **Flexible I/O:** Supports Standard SPI (1-line), Dual SPI (2-lines), and Quad SPI (4-lines) modes.
*   **Lightweight:** Thin wrapper around STM32 HAL with minimal runtime overhead.

**Limitations:**

*   **Addressing Mode:** **24-bit addressing** by default.
    *   Compatible with Flash sizes up to **128 Mbit (16 MB)**.
    *   Memories larger than 16 MB (256 Mbit, 512 Mbit): define `W25Q_32BIT_MODE` and call `W25Q_Enter4BytesMode()` after each reset (QSPI only; the OSPI implementation is 24-bit only).
*   **Operating Mode:** Works in **Indirect Mode** (Command/Response). Memory-Mapped Mode (XIP) is not implemented.

## Requirements

*   STM32Cube HAL Library.
*   Configured QSPI or OSPI peripheral (handle `hqspi` or `hospi` in `main.c`).
*   DMA and NVIC (Interrupts) configured for the chosen peripheral.

> [!WARNING]
> **Important Note for Cortex-M7 (STM32F7 / STM32H7)**
>
> This driver **does not** explicitly handle D-Cache maintenance. Since DMA transfers bypass the D-Cache, you must manually manage cache coherency if D-Cache is enabled:
> *   **Before Writing (Transmit):** Call `SCB_CleanDCache_by_Addr(...)` on your TX buffer to ensure data is flushed from Cache to RAM.
> *   **After Reading (Receive):** Call `SCB_InvalidateDCache_by_Addr(...)` on your RX buffer to ensure the CPU reads fresh data from RAM.
>
> Alternatively, place your buffers in a non-cacheable memory region (e.g., DTCMRAM or configured via MPU).

## Installation

1.  Add this repository as a submodule to your project:

```bash
git submodule add https://github.com/mpekurin/W25Q_STM32_HAL_Driver Drivers/W25Q_STM32_HAL_Driver
```

2.  **Include Path:** Add `Drivers/W25Q_STM32_HAL_Driver/Inc` to your C/C++ compiler include paths.
3.  **Source Files:** Add `Drivers/W25Q_STM32_HAL_Driver/Src` to your build sources.

*Note: The driver contains separate source files for QSPI and OSPI. You can include both in your project; the unused one will be automatically excluded by the preprocessor based on your HAL configuration.*

## Usage Example

Assuming OSPI is used.

### 1. Initialization

```C
/* After MX_OSPI_Init(): */

// 1. Reset the device to a known state (recover from soft resets)
W25Q_EnableReset(&hospi);
W25Q_ResetDevice(&hospi);

// 2. Enable Quad bit (QE) in Status Register 2 for Quad I/O operations
// Using Volatile Write Enable to avoid wearing out the flash on every boot
W25Q_VolatileSrWriteEnable(&hospi);
W25Q_WriteStatusRegister(&hospi, W25Q_SR2, W25Q_SR2_QE);
```

### 2. Blocking Usage (Simple)

```C
// Erase a 4KB sector
W25Q_WriteEnable(&hospi);
W25Q_Erase4KB(&hospi, address);
while(W25Q_GetState(&hospi) != W25Q_STATE_READY); // Wait for Erase

// Write a page using Quad Input
// Note: If using H7/F7, clean D-Cache for txData here
W25Q_WriteEnable(&hospi);
W25Q_PageProgramQuadInput_DMA(&hospi, address, W25Q_PAGE_SIZE, txData);
while(W25Q_GetState(&hospi) != W25Q_STATE_READY); // Wait for Program

// Read data back using Quad I/O
// Note: If using H7/F7, invalidate D-Cache for rxData after this
W25Q_FastReadQuadIo_DMA(&hospi, address, W25Q_PAGE_SIZE, rxData);
while(W25Q_GetState(&hospi) != W25Q_STATE_READY); // Wait for Read
```

### 3. Asynchronous Usage (IT/DMA)

Non-blocking workflow using HAL Callbacks. Ideally, this should be implemented as a state machine.

*Note: Configure the callbacks in your code.*

```C
void StartWriteSequence(void)
{
  W25Q_WriteEnable(&hospi);
  // Start DMA transfer, the rest is handled in callbacks
  W25Q_PageProgramQuadInput_DMA(&hospi, address, W25Q_PAGE_SIZE, txData);
}

// 1. Called when DMA transfer (Write) is complete
void HAL_OSPI_TxCpltCallback(OSPI_HandleTypeDef *hospi)
{
  // DMA finished sending data, but Flash is still busy writing internally
  // Start polling the Status Register (in Interrupt mode) to wait for "Ready"
  W25Q_BusyFlagPolling_IT(hospi);
}

// 2. Called when Flash BUSY flag clears (Write finished)
void HAL_OSPI_StatusMatchCallback(OSPI_HandleTypeDef *hospi)
{
  // Write operation is physically complete
  // Immediately start reading back (DMA)
  W25Q_FastReadQuadIo_DMA(hospi, address, W25Q_PAGE_SIZE, rxData);
}

// 3. Called when Read is complete
void HAL_OSPI_RxCpltCallback(OSPI_HandleTypeDef *hospi)
{
  // If using H7/F7: SCB_InvalidateDCache_by_Addr(rxData, W25Q_PAGE_SIZE);
  // Set a flag and process in the main loop
  isDataReady = 1;
}
```
