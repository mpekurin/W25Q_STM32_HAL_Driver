/*
 * Copyright (c) 2026 Maxim Pekurin
 * Licensed under the MIT License.
 */

#include "main.h"

#if defined(HAL_QSPI_MODULE_ENABLED)

#include "w25q.h"
#include "w25q_defs.h"

HAL_StatusTypeDef W25Q_WriteEnable(xSPI_HandleTypeDef *hxspi)
{
  QSPI_CommandTypeDef cmd;
  HAL_StatusTypeDef status;

  cmd.Instruction = W25Q_WRITE_ENABLE;
  cmd.InstructionMode = QSPI_INSTRUCTION_1_LINE;
  cmd.Address = 0;
  cmd.AddressMode = QSPI_ADDRESS_NONE;
  cmd.AddressSize = QSPI_ADDRESS_8_BITS;
  cmd.AlternateBytes = 0;
  cmd.AlternateByteMode = QSPI_ALTERNATE_BYTES_NONE;
  cmd.AlternateBytesSize = QSPI_ALTERNATE_BYTES_8_BITS;
  cmd.DummyCycles = 0;
  cmd.NbData = 0;
  cmd.DataMode = QSPI_DATA_NONE;
  cmd.DdrMode = QSPI_DDR_MODE_DISABLE;
  cmd.DdrHoldHalfCycle = QSPI_DDR_HHC_ANALOG_DELAY;
  cmd.SIOOMode = QSPI_SIOO_INST_EVERY_CMD;

  status = HAL_QSPI_Command(hxspi, &cmd, W25Q_TIMEOUT_VALUE);

  return status;
}

HAL_StatusTypeDef W25Q_VolatileSrWriteEnable(xSPI_HandleTypeDef *hxspi)
{
  QSPI_CommandTypeDef cmd;
  HAL_StatusTypeDef status;

  cmd.Instruction = W25Q_VOLATILE_SR_WRITE_ENABLE;
  cmd.InstructionMode = QSPI_INSTRUCTION_1_LINE;
  cmd.Address = 0;
  cmd.AddressMode = QSPI_ADDRESS_NONE;
  cmd.AddressSize = QSPI_ADDRESS_8_BITS;
  cmd.AlternateBytes = 0;
  cmd.AlternateByteMode = QSPI_ALTERNATE_BYTES_NONE;
  cmd.AlternateBytesSize = QSPI_ALTERNATE_BYTES_8_BITS;
  cmd.DummyCycles = 0;
  cmd.NbData = 0;
  cmd.DataMode = QSPI_DATA_NONE;
  cmd.DdrMode = QSPI_DDR_MODE_DISABLE;
  cmd.DdrHoldHalfCycle = QSPI_DDR_HHC_ANALOG_DELAY;
  cmd.SIOOMode = QSPI_SIOO_INST_EVERY_CMD;

  status = HAL_QSPI_Command(hxspi, &cmd, W25Q_TIMEOUT_VALUE);

  return status;
}

HAL_StatusTypeDef W25Q_WriteDisable(xSPI_HandleTypeDef *hxspi)
{
  QSPI_CommandTypeDef cmd;
  HAL_StatusTypeDef status;

  cmd.Instruction = W25Q_WRITE_DISABLE;
  cmd.InstructionMode = QSPI_INSTRUCTION_1_LINE;
  cmd.Address = 0;
  cmd.AddressMode = QSPI_ADDRESS_NONE;
  cmd.AddressSize = QSPI_ADDRESS_8_BITS;
  cmd.AlternateBytes = 0;
  cmd.AlternateByteMode = QSPI_ALTERNATE_BYTES_NONE;
  cmd.AlternateBytesSize = QSPI_ALTERNATE_BYTES_8_BITS;
  cmd.DummyCycles = 0;
  cmd.NbData = 0;
  cmd.DataMode = QSPI_DATA_NONE;
  cmd.DdrMode = QSPI_DDR_MODE_DISABLE;
  cmd.DdrHoldHalfCycle = QSPI_DDR_HHC_ANALOG_DELAY;
  cmd.SIOOMode = QSPI_SIOO_INST_EVERY_CMD;

  status = HAL_QSPI_Command(hxspi, &cmd, W25Q_TIMEOUT_VALUE);

  return status;
}

HAL_StatusTypeDef W25Q_ReadStatusRegister(xSPI_HandleTypeDef *hxspi, W25Q_StatusRegTypeDef RegIndex, uint8_t *pRegValue)
{
  QSPI_CommandTypeDef cmd;
  HAL_StatusTypeDef status;
  uint32_t instruction;

  switch (RegIndex)
  {
    case 1:
      instruction = W25Q_READ_STATUS_REG_1;
      break;
    case 2:
      instruction = W25Q_READ_STATUS_REG_2;
      break;
    case 3:
      instruction = W25Q_READ_STATUS_REG_3;
      break;
    default:
      return HAL_ERROR;
  }

  cmd.Instruction = instruction;
  cmd.InstructionMode = QSPI_INSTRUCTION_1_LINE;
  cmd.Address = 0;
  cmd.AddressMode = QSPI_ADDRESS_NONE;
  cmd.AddressSize = QSPI_ADDRESS_8_BITS;
  cmd.AlternateBytes = 0;
  cmd.AlternateByteMode = QSPI_ALTERNATE_BYTES_NONE;
  cmd.AlternateBytesSize = QSPI_ALTERNATE_BYTES_8_BITS;
  cmd.DummyCycles = 0;
  cmd.NbData = 1;
  cmd.DataMode = QSPI_DATA_1_LINE;
  cmd.DdrMode = QSPI_DDR_MODE_DISABLE;
  cmd.DdrHoldHalfCycle = QSPI_DDR_HHC_ANALOG_DELAY;
  cmd.SIOOMode = QSPI_SIOO_INST_EVERY_CMD;

  status = HAL_QSPI_Command(hxspi, &cmd, W25Q_TIMEOUT_VALUE);
  if (status != HAL_OK)
  {
    return status;
  }
  status = HAL_QSPI_Receive(hxspi, pRegValue, W25Q_TIMEOUT_VALUE);

  return status;
}

HAL_StatusTypeDef W25Q_WriteStatusRegister(xSPI_HandleTypeDef *hxspi, W25Q_StatusRegTypeDef RegIndex, uint8_t RegValue)
{
  QSPI_CommandTypeDef cmd;
  HAL_StatusTypeDef status;
  uint32_t instruction;

  switch (RegIndex)
  {
    case 1:
      instruction = W25Q_WRITE_STATUS_REG_1;
      break;
    case 2:
      instruction = W25Q_WRITE_STATUS_REG_2;
      break;
    case 3:
      instruction = W25Q_WRITE_STATUS_REG_3;
      break;
    default:
      return HAL_ERROR;
  }

  cmd.Instruction = instruction;
  cmd.InstructionMode = QSPI_INSTRUCTION_1_LINE;
  cmd.Address = 0;
  cmd.AddressMode = QSPI_ADDRESS_NONE;
  cmd.AddressSize = QSPI_ADDRESS_8_BITS;
  cmd.AlternateBytes = 0;
  cmd.AlternateByteMode = QSPI_ALTERNATE_BYTES_NONE;
  cmd.AlternateBytesSize = QSPI_ALTERNATE_BYTES_8_BITS;
  cmd.DummyCycles = 0;
  cmd.NbData = 1;
  cmd.DataMode = QSPI_DATA_1_LINE;
  cmd.DdrMode = QSPI_DDR_MODE_DISABLE;
  cmd.DdrHoldHalfCycle = QSPI_DDR_HHC_ANALOG_DELAY;
  cmd.SIOOMode = QSPI_SIOO_INST_EVERY_CMD;

  status = HAL_QSPI_Command(hxspi, &cmd, W25Q_TIMEOUT_VALUE);
  if (status != HAL_OK)
  {
    return status;
  }
  status = HAL_QSPI_Transmit(hxspi, &RegValue, W25Q_TIMEOUT_VALUE);

  return status;
}

HAL_StatusTypeDef W25Q_ReadData_DMA(xSPI_HandleTypeDef *hxspi, uint32_t Address, uint32_t Size, void *pData)
{
  QSPI_CommandTypeDef cmd;
  HAL_StatusTypeDef status;

  cmd.Instruction = W25Q_CMD_READ_DATA;
  cmd.InstructionMode = QSPI_INSTRUCTION_1_LINE;
  cmd.Address = Address;
  cmd.AddressMode = QSPI_ADDRESS_1_LINE;
  cmd.AddressSize = W25Q_ADDRESS_BITS;
  cmd.AlternateBytes = 0;
  cmd.AlternateByteMode = QSPI_ALTERNATE_BYTES_NONE;
  cmd.AlternateBytesSize = QSPI_ALTERNATE_BYTES_8_BITS;
  cmd.DummyCycles = 0;
  cmd.NbData = Size;
  cmd.DataMode = QSPI_DATA_1_LINE;
  cmd.DdrMode = QSPI_DDR_MODE_DISABLE;
  cmd.DdrHoldHalfCycle = QSPI_DDR_HHC_ANALOG_DELAY;
  cmd.SIOOMode = QSPI_SIOO_INST_EVERY_CMD;

  status = HAL_QSPI_Command(hxspi, &cmd, W25Q_TIMEOUT_VALUE);
  if (status != HAL_OK)
  {
    return status;
  }
  status = HAL_QSPI_Receive_DMA(hxspi, pData);

  return status;
}

HAL_StatusTypeDef W25Q_FastRead_DMA(xSPI_HandleTypeDef *hxspi, uint32_t Address, uint32_t Size, void *pData)
{
  QSPI_CommandTypeDef cmd;
  HAL_StatusTypeDef status;

  cmd.Instruction = W25Q_CMD_FAST_READ;
  cmd.InstructionMode = QSPI_INSTRUCTION_1_LINE;
  cmd.Address = Address;
  cmd.AddressMode = QSPI_ADDRESS_1_LINE;
  cmd.AddressSize = W25Q_ADDRESS_BITS;
  cmd.AlternateBytes = 0;
  cmd.AlternateByteMode = QSPI_ALTERNATE_BYTES_NONE;
  cmd.AlternateBytesSize = QSPI_ALTERNATE_BYTES_8_BITS;
  cmd.DummyCycles = 8;
  cmd.NbData = Size;
  cmd.DataMode = QSPI_DATA_1_LINE;
  cmd.DdrMode = QSPI_DDR_MODE_DISABLE;
  cmd.DdrHoldHalfCycle = QSPI_DDR_HHC_ANALOG_DELAY;
  cmd.SIOOMode = QSPI_SIOO_INST_EVERY_CMD;

  status = HAL_QSPI_Command(hxspi, &cmd, W25Q_TIMEOUT_VALUE);
  if (status != HAL_OK)
  {
    return status;
  }
  status = HAL_QSPI_Receive_DMA(hxspi, pData);

  return status;
}

HAL_StatusTypeDef W25Q_FastReadDualOutput_DMA(xSPI_HandleTypeDef *hxspi, uint32_t Address, uint32_t Size, void *pData)
{
  QSPI_CommandTypeDef cmd;
  HAL_StatusTypeDef status;

  cmd.Instruction = W25Q_CMD_FAST_READ_DUAL_OUT;
  cmd.InstructionMode = QSPI_INSTRUCTION_1_LINE;
  cmd.Address = Address;
  cmd.AddressMode = QSPI_ADDRESS_1_LINE;
  cmd.AddressSize = W25Q_ADDRESS_BITS;
  cmd.AlternateBytes = 0;
  cmd.AlternateByteMode = QSPI_ALTERNATE_BYTES_NONE;
  cmd.AlternateBytesSize = QSPI_ALTERNATE_BYTES_8_BITS;
  cmd.DummyCycles = 8;
  cmd.NbData = Size;
  cmd.DataMode = QSPI_DATA_2_LINES;
  cmd.DdrMode = QSPI_DDR_MODE_DISABLE;
  cmd.DdrHoldHalfCycle = QSPI_DDR_HHC_ANALOG_DELAY;
  cmd.SIOOMode = QSPI_SIOO_INST_EVERY_CMD;

  status = HAL_QSPI_Command(hxspi, &cmd, W25Q_TIMEOUT_VALUE);
  if (status != HAL_OK)
  {
    return status;
  }
  status = HAL_QSPI_Receive_DMA(hxspi, pData);

  return status;
}

HAL_StatusTypeDef W25Q_FastReadQuadOutput_DMA(xSPI_HandleTypeDef *hxspi, uint32_t Address, uint32_t Size, void *pData)
{
  QSPI_CommandTypeDef cmd;
  HAL_StatusTypeDef status;

  cmd.Instruction = W25Q_CMD_FAST_READ_QUAD_OUT;
  cmd.InstructionMode = QSPI_INSTRUCTION_1_LINE;
  cmd.Address = Address;
  cmd.AddressMode = QSPI_ADDRESS_1_LINE;
  cmd.AddressSize = W25Q_ADDRESS_BITS;
  cmd.AlternateBytes = 0;
  cmd.AlternateByteMode = QSPI_ALTERNATE_BYTES_NONE;
  cmd.AlternateBytesSize = QSPI_ALTERNATE_BYTES_8_BITS;
  cmd.DummyCycles = 8;
  cmd.NbData = Size;
  cmd.DataMode = QSPI_DATA_4_LINES;
  cmd.DdrMode = QSPI_DDR_MODE_DISABLE;
  cmd.DdrHoldHalfCycle = QSPI_DDR_HHC_ANALOG_DELAY;
  cmd.SIOOMode = QSPI_SIOO_INST_EVERY_CMD;

  status = HAL_QSPI_Command(hxspi, &cmd, W25Q_TIMEOUT_VALUE);
  if (status != HAL_OK)
  {
    return status;
  }
  status = HAL_QSPI_Receive_DMA(hxspi, pData);

  return status;
}

HAL_StatusTypeDef W25Q_FastReadDualIo_DMA(xSPI_HandleTypeDef *hxspi, uint32_t Address, uint32_t Size, void *pData)
{
  QSPI_CommandTypeDef cmd;
  HAL_StatusTypeDef status;

  cmd.Instruction = W25Q_CMD_FAST_READ_DUAL_IO;
  cmd.InstructionMode = QSPI_INSTRUCTION_1_LINE;
  cmd.Address = Address;
  cmd.AddressMode = QSPI_ADDRESS_2_LINES;
  cmd.AddressSize = W25Q_ADDRESS_BITS;
  cmd.AlternateBytes = W25Q_CONTINUOUS_READ_MODE;
  cmd.AlternateByteMode = QSPI_ALTERNATE_BYTES_2_LINES;
  cmd.AlternateBytesSize = QSPI_ALTERNATE_BYTES_8_BITS;
  cmd.DummyCycles = 0;
  cmd.NbData = Size;
  cmd.DataMode = QSPI_DATA_2_LINES;
  cmd.DdrMode = QSPI_DDR_MODE_DISABLE;
  cmd.DdrHoldHalfCycle = QSPI_DDR_HHC_ANALOG_DELAY;
  cmd.SIOOMode = QSPI_SIOO_INST_EVERY_CMD;

  status = HAL_QSPI_Command(hxspi, &cmd, W25Q_TIMEOUT_VALUE);
  if (status != HAL_OK)
  {
    return status;
  }
  status = HAL_QSPI_Receive_DMA(hxspi, pData);

  return status;
}

HAL_StatusTypeDef W25Q_FastReadQuadIo_DMA(xSPI_HandleTypeDef *hxspi, uint32_t Address, uint32_t Size, void *pData)
{
  QSPI_CommandTypeDef cmd;
  HAL_StatusTypeDef status;

  cmd.Instruction = W25Q_CMD_FAST_READ_QUAD_IO;
  cmd.InstructionMode = QSPI_INSTRUCTION_1_LINE;
  cmd.Address = Address;
  cmd.AddressMode = QSPI_ADDRESS_4_LINES;
  cmd.AddressSize = W25Q_ADDRESS_BITS;
  cmd.AlternateBytes = W25Q_CONTINUOUS_READ_MODE;
  cmd.AlternateByteMode = QSPI_ALTERNATE_BYTES_4_LINES;
  cmd.AlternateBytesSize = QSPI_ALTERNATE_BYTES_8_BITS;
  cmd.DummyCycles = 4;
  cmd.NbData = Size;
  cmd.DataMode = QSPI_DATA_4_LINES;
  cmd.DdrMode = QSPI_DDR_MODE_DISABLE;
  cmd.DdrHoldHalfCycle = QSPI_DDR_HHC_ANALOG_DELAY;
  cmd.SIOOMode = QSPI_SIOO_INST_EVERY_CMD;

  status = HAL_QSPI_Command(hxspi, &cmd, W25Q_TIMEOUT_VALUE);
  if (status != HAL_OK)
  {
    return status;
  }
  status = HAL_QSPI_Receive_DMA(hxspi, pData);

  return status;
}

HAL_StatusTypeDef W25Q_SetBurstWithWrap(xSPI_HandleTypeDef *hxspi, W25Q_WrapModeTypeDef WrapMode)
{
  QSPI_CommandTypeDef cmd;
  HAL_StatusTypeDef status;

  cmd.Instruction = W25Q_SET_BURST_WITH_WRAP;
  cmd.InstructionMode = QSPI_INSTRUCTION_1_LINE;
#ifdef W25Q_32BIT_MODE
  // 4 dummy bytes (sent as a null address) followed by W7-W0
  cmd.Address = 0;
  cmd.AddressMode = QSPI_ADDRESS_4_LINES;
  cmd.AddressSize = QSPI_ADDRESS_32_BITS;
  cmd.AlternateBytes = WrapMode;
  cmd.AlternateByteMode = QSPI_ALTERNATE_BYTES_4_LINES;
  cmd.AlternateBytesSize = QSPI_ALTERNATE_BYTES_8_BITS;
#else
  cmd.Address = 0;
  cmd.AddressMode = QSPI_ADDRESS_NONE;
  cmd.AddressSize = QSPI_ADDRESS_8_BITS;
  cmd.AlternateBytes = WrapMode;
  cmd.AlternateByteMode = QSPI_ALTERNATE_BYTES_4_LINES;
  cmd.AlternateBytesSize = QSPI_ALTERNATE_BYTES_32_BITS;
#endif
  cmd.DummyCycles = 0;
  cmd.NbData = 0;
  cmd.DataMode = QSPI_DATA_NONE;
  cmd.DdrMode = QSPI_DDR_MODE_DISABLE;
  cmd.DdrHoldHalfCycle = QSPI_DDR_HHC_ANALOG_DELAY;
  cmd.SIOOMode = QSPI_SIOO_INST_EVERY_CMD;

  status = HAL_QSPI_Command(hxspi, &cmd, W25Q_TIMEOUT_VALUE);

  return status;
}

HAL_StatusTypeDef W25Q_PageProgram_DMA(xSPI_HandleTypeDef *hxspi, uint32_t Address, uint16_t Size, void *pData)
{
  QSPI_CommandTypeDef cmd;
  HAL_StatusTypeDef status;

  cmd.Instruction = W25Q_CMD_PAGE_PROGRAM;
  cmd.InstructionMode = QSPI_INSTRUCTION_1_LINE;
  cmd.Address = Address;
  cmd.AddressMode = QSPI_ADDRESS_1_LINE;
  cmd.AddressSize = W25Q_ADDRESS_BITS;
  cmd.AlternateBytes = 0;
  cmd.AlternateByteMode = QSPI_ALTERNATE_BYTES_NONE;
  cmd.AlternateBytesSize = QSPI_ALTERNATE_BYTES_8_BITS;
  cmd.DummyCycles = 0;
  cmd.NbData = Size;
  cmd.DataMode = QSPI_DATA_1_LINE;
  cmd.DdrMode = QSPI_DDR_MODE_DISABLE;
  cmd.DdrHoldHalfCycle = QSPI_DDR_HHC_ANALOG_DELAY;
  cmd.SIOOMode = QSPI_SIOO_INST_EVERY_CMD;

  status = HAL_QSPI_Command(hxspi, &cmd, W25Q_TIMEOUT_VALUE);
  if (status != HAL_OK)
  {
    return status;
  }
  status = HAL_QSPI_Transmit_DMA(hxspi, pData);

  return status;
}

HAL_StatusTypeDef W25Q_PageProgramQuadInput_DMA(xSPI_HandleTypeDef *hxspi, uint32_t Address, uint16_t Size, void *pData)
{
  QSPI_CommandTypeDef cmd;
  HAL_StatusTypeDef status;

  cmd.Instruction = W25Q_CMD_PAGE_PROGRAM_QUAD;
  cmd.InstructionMode = QSPI_INSTRUCTION_1_LINE;
  cmd.Address = Address;
  cmd.AddressMode = QSPI_ADDRESS_1_LINE;
  cmd.AddressSize = W25Q_ADDRESS_BITS;
  cmd.AlternateBytes = 0;
  cmd.AlternateByteMode = QSPI_ALTERNATE_BYTES_NONE;
  cmd.AlternateBytesSize = QSPI_ALTERNATE_BYTES_8_BITS;
  cmd.DummyCycles = 0;
  cmd.NbData = Size;
  cmd.DataMode = QSPI_DATA_4_LINES;
  cmd.DdrMode = QSPI_DDR_MODE_DISABLE;
  cmd.DdrHoldHalfCycle = QSPI_DDR_HHC_ANALOG_DELAY;
  cmd.SIOOMode = QSPI_SIOO_INST_EVERY_CMD;

  status = HAL_QSPI_Command(hxspi, &cmd, W25Q_TIMEOUT_VALUE);
  if (status != HAL_OK)
  {
    return status;
  }
  status = HAL_QSPI_Transmit_DMA(hxspi, pData);

  return status;
}

HAL_StatusTypeDef W25Q_Erase4KB(xSPI_HandleTypeDef *hxspi, uint32_t Address)
{
  QSPI_CommandTypeDef cmd;
  HAL_StatusTypeDef status;

  cmd.Instruction = W25Q_CMD_SECTOR_ERASE_4KB;
  cmd.InstructionMode = QSPI_INSTRUCTION_1_LINE;
  cmd.Address = Address;
  cmd.AddressMode = QSPI_ADDRESS_1_LINE;
  cmd.AddressSize = W25Q_ADDRESS_BITS;
  cmd.AlternateBytes = 0;
  cmd.AlternateByteMode = QSPI_ALTERNATE_BYTES_NONE;
  cmd.AlternateBytesSize = QSPI_ALTERNATE_BYTES_8_BITS;
  cmd.DummyCycles = 0;
  cmd.NbData = 0;
  cmd.DataMode = QSPI_DATA_NONE;
  cmd.DdrMode = QSPI_DDR_MODE_DISABLE;
  cmd.DdrHoldHalfCycle = QSPI_DDR_HHC_ANALOG_DELAY;
  cmd.SIOOMode = QSPI_SIOO_INST_EVERY_CMD;

  status = HAL_QSPI_Command(hxspi, &cmd, W25Q_TIMEOUT_VALUE);

  return status;
}

HAL_StatusTypeDef W25Q_Erase32KB(xSPI_HandleTypeDef *hxspi, uint32_t Address)
{
  QSPI_CommandTypeDef cmd;
  HAL_StatusTypeDef status;

  cmd.Instruction = W25Q_BLOCK_ERASE_32KB;
  cmd.InstructionMode = QSPI_INSTRUCTION_1_LINE;
  cmd.Address = Address;
  cmd.AddressMode = QSPI_ADDRESS_1_LINE;
  cmd.AddressSize = W25Q_ADDRESS_BITS;
  cmd.AlternateBytes = 0;
  cmd.AlternateByteMode = QSPI_ALTERNATE_BYTES_NONE;
  cmd.AlternateBytesSize = QSPI_ALTERNATE_BYTES_8_BITS;
  cmd.DummyCycles = 0;
  cmd.NbData = 0;
  cmd.DataMode = QSPI_DATA_NONE;
  cmd.DdrMode = QSPI_DDR_MODE_DISABLE;
  cmd.DdrHoldHalfCycle = QSPI_DDR_HHC_ANALOG_DELAY;
  cmd.SIOOMode = QSPI_SIOO_INST_EVERY_CMD;

  status = HAL_QSPI_Command(hxspi, &cmd, W25Q_TIMEOUT_VALUE);

  return status;
}

HAL_StatusTypeDef W25Q_Erase64KB(xSPI_HandleTypeDef *hxspi, uint32_t Address)
{
  QSPI_CommandTypeDef cmd;
  HAL_StatusTypeDef status;

  cmd.Instruction = W25Q_CMD_BLOCK_ERASE_64KB;
  cmd.InstructionMode = QSPI_INSTRUCTION_1_LINE;
  cmd.Address = Address;
  cmd.AddressMode = QSPI_ADDRESS_1_LINE;
  cmd.AddressSize = W25Q_ADDRESS_BITS;
  cmd.AlternateBytes = 0;
  cmd.AlternateByteMode = QSPI_ALTERNATE_BYTES_NONE;
  cmd.AlternateBytesSize = QSPI_ALTERNATE_BYTES_8_BITS;
  cmd.DummyCycles = 0;
  cmd.NbData = 0;
  cmd.DataMode = QSPI_DATA_NONE;
  cmd.DdrMode = QSPI_DDR_MODE_DISABLE;
  cmd.DdrHoldHalfCycle = QSPI_DDR_HHC_ANALOG_DELAY;
  cmd.SIOOMode = QSPI_SIOO_INST_EVERY_CMD;

  status = HAL_QSPI_Command(hxspi, &cmd, W25Q_TIMEOUT_VALUE);

  return status;
}

HAL_StatusTypeDef W25Q_ChipErase(xSPI_HandleTypeDef *hxspi)
{
  QSPI_CommandTypeDef cmd;
  HAL_StatusTypeDef status;

  cmd.Instruction = W25Q_CHIP_ERASE;
  cmd.InstructionMode = QSPI_INSTRUCTION_1_LINE;
  cmd.Address = 0;
  cmd.AddressMode = QSPI_ADDRESS_NONE;
  cmd.AddressSize = QSPI_ADDRESS_8_BITS;
  cmd.AlternateBytes = 0;
  cmd.AlternateByteMode = QSPI_ALTERNATE_BYTES_NONE;
  cmd.AlternateBytesSize = QSPI_ALTERNATE_BYTES_8_BITS;
  cmd.DummyCycles = 0;
  cmd.NbData = 0;
  cmd.DataMode = QSPI_DATA_NONE;
  cmd.DdrMode = QSPI_DDR_MODE_DISABLE;
  cmd.DdrHoldHalfCycle = QSPI_DDR_HHC_ANALOG_DELAY;
  cmd.SIOOMode = QSPI_SIOO_INST_EVERY_CMD;

  status = HAL_QSPI_Command(hxspi, &cmd, W25Q_TIMEOUT_VALUE);

  return status;
}

HAL_StatusTypeDef W25Q_Suspend(xSPI_HandleTypeDef *hxspi)
{
  QSPI_CommandTypeDef cmd;
  HAL_StatusTypeDef status;

  cmd.Instruction = W25Q_SUSPEND;
  cmd.InstructionMode = QSPI_INSTRUCTION_1_LINE;
  cmd.Address = 0;
  cmd.AddressMode = QSPI_ADDRESS_NONE;
  cmd.AddressSize = QSPI_ADDRESS_8_BITS;
  cmd.AlternateBytes = 0;
  cmd.AlternateByteMode = QSPI_ALTERNATE_BYTES_NONE;
  cmd.AlternateBytesSize = QSPI_ALTERNATE_BYTES_8_BITS;
  cmd.DummyCycles = 0;
  cmd.NbData = 0;
  cmd.DataMode = QSPI_DATA_NONE;
  cmd.DdrMode = QSPI_DDR_MODE_DISABLE;
  cmd.DdrHoldHalfCycle = QSPI_DDR_HHC_ANALOG_DELAY;
  cmd.SIOOMode = QSPI_SIOO_INST_EVERY_CMD;

  status = HAL_QSPI_Command(hxspi, &cmd, W25Q_TIMEOUT_VALUE);

  return status;
}

HAL_StatusTypeDef W25Q_Resume(xSPI_HandleTypeDef *hxspi)
{
  QSPI_CommandTypeDef cmd;
  HAL_StatusTypeDef status;

  cmd.Instruction = W25Q_RESUME;
  cmd.InstructionMode = QSPI_INSTRUCTION_1_LINE;
  cmd.Address = 0;
  cmd.AddressMode = QSPI_ADDRESS_NONE;
  cmd.AddressSize = QSPI_ADDRESS_8_BITS;
  cmd.AlternateBytes = 0;
  cmd.AlternateByteMode = QSPI_ALTERNATE_BYTES_NONE;
  cmd.AlternateBytesSize = QSPI_ALTERNATE_BYTES_8_BITS;
  cmd.DummyCycles = 0;
  cmd.NbData = 0;
  cmd.DataMode = QSPI_DATA_NONE;
  cmd.DdrMode = QSPI_DDR_MODE_DISABLE;
  cmd.DdrHoldHalfCycle = QSPI_DDR_HHC_ANALOG_DELAY;
  cmd.SIOOMode = QSPI_SIOO_INST_EVERY_CMD;

  status = HAL_QSPI_Command(hxspi, &cmd, W25Q_TIMEOUT_VALUE);

  return status;
}

HAL_StatusTypeDef W25Q_PowerDown(xSPI_HandleTypeDef *hxspi)
{
  QSPI_CommandTypeDef cmd;
  HAL_StatusTypeDef status;

  cmd.Instruction = W25Q_POWER_DOWN;
  cmd.InstructionMode = QSPI_INSTRUCTION_1_LINE;
  cmd.Address = 0;
  cmd.AddressMode = QSPI_ADDRESS_NONE;
  cmd.AddressSize = QSPI_ADDRESS_8_BITS;
  cmd.AlternateBytes = 0;
  cmd.AlternateByteMode = QSPI_ALTERNATE_BYTES_NONE;
  cmd.AlternateBytesSize = QSPI_ALTERNATE_BYTES_8_BITS;
  cmd.DummyCycles = 0;
  cmd.NbData = 0;
  cmd.DataMode = QSPI_DATA_NONE;
  cmd.DdrMode = QSPI_DDR_MODE_DISABLE;
  cmd.DdrHoldHalfCycle = QSPI_DDR_HHC_ANALOG_DELAY;
  cmd.SIOOMode = QSPI_SIOO_INST_EVERY_CMD;

  status = HAL_QSPI_Command(hxspi, &cmd, W25Q_TIMEOUT_VALUE);

  return status;
}

HAL_StatusTypeDef W25Q_ReleasePowerDown(xSPI_HandleTypeDef *hxspi)
{
  QSPI_CommandTypeDef cmd;
  HAL_StatusTypeDef status;

  cmd.Instruction = W25Q_RELEASE_POWER_DOWN;
  cmd.InstructionMode = QSPI_INSTRUCTION_1_LINE;
  cmd.Address = 0;
  cmd.AddressMode = QSPI_ADDRESS_NONE;
  cmd.AddressSize = QSPI_ADDRESS_8_BITS;
  cmd.AlternateBytes = 0;
  cmd.AlternateByteMode = QSPI_ALTERNATE_BYTES_NONE;
  cmd.AlternateBytesSize = QSPI_ALTERNATE_BYTES_8_BITS;
  cmd.DummyCycles = 0;
  cmd.NbData = 0;
  cmd.DataMode = QSPI_DATA_NONE;
  cmd.DdrMode = QSPI_DDR_MODE_DISABLE;
  cmd.DdrHoldHalfCycle = QSPI_DDR_HHC_ANALOG_DELAY;
  cmd.SIOOMode = QSPI_SIOO_INST_EVERY_CMD;

  status = HAL_QSPI_Command(hxspi, &cmd, W25Q_TIMEOUT_VALUE);

  return status;
}

HAL_StatusTypeDef W25Q_ReadDeviceId(xSPI_HandleTypeDef *hxspi, uint8_t *pDeviceId)
{
  QSPI_CommandTypeDef cmd;
  HAL_StatusTypeDef status;
  uint8_t response[2];

  cmd.Instruction = W25Q_READ_MFTR_DEVICE_ID;
  cmd.InstructionMode = QSPI_INSTRUCTION_1_LINE;
  cmd.Address = 0;
  cmd.AddressMode = QSPI_ADDRESS_1_LINE;
  cmd.AddressSize = QSPI_ADDRESS_24_BITS; // 3 bytes even in 4-byte address mode
  cmd.AlternateBytes = 0;
  cmd.AlternateByteMode = QSPI_ALTERNATE_BYTES_NONE;
  cmd.AlternateBytesSize = QSPI_ALTERNATE_BYTES_8_BITS;
  cmd.DummyCycles = 0;
  cmd.NbData = 2;
  cmd.DataMode = QSPI_DATA_1_LINE;
  cmd.DdrMode = QSPI_DDR_MODE_DISABLE;
  cmd.DdrHoldHalfCycle = QSPI_DDR_HHC_ANALOG_DELAY;
  cmd.SIOOMode = QSPI_SIOO_INST_EVERY_CMD;

  status = HAL_QSPI_Command(hxspi, &cmd, W25Q_TIMEOUT_VALUE);
  if (status != HAL_OK)
  {
    return status;
  }
  status = HAL_QSPI_Receive(hxspi, &response[0], W25Q_TIMEOUT_VALUE);
  if (status == HAL_OK)
  {
    *pDeviceId = response[1];
  }

  return status;
}

HAL_StatusTypeDef W25Q_ReadDeviceIdDualIo(xSPI_HandleTypeDef *hxspi, uint8_t *pDeviceId)
{
  QSPI_CommandTypeDef cmd;
  HAL_StatusTypeDef status;
  uint8_t response[2];

  cmd.Instruction = W25Q_READ_MFTR_DEVICE_ID_DUAL_IO;
  cmd.InstructionMode = QSPI_INSTRUCTION_1_LINE;
  cmd.Address = 0;
  cmd.AddressMode = QSPI_ADDRESS_2_LINES;
  cmd.AddressSize = W25Q_ADDRESS_BITS;
  cmd.AlternateBytes = W25Q_CONTINUOUS_READ_MODE;
  cmd.AlternateByteMode = QSPI_ALTERNATE_BYTES_2_LINES;
  cmd.AlternateBytesSize = QSPI_ALTERNATE_BYTES_8_BITS;
  cmd.DummyCycles = 0;
  cmd.NbData = 2;
  cmd.DataMode = QSPI_DATA_2_LINES;
  cmd.DdrMode = QSPI_DDR_MODE_DISABLE;
  cmd.DdrHoldHalfCycle = QSPI_DDR_HHC_ANALOG_DELAY;
  cmd.SIOOMode = QSPI_SIOO_INST_EVERY_CMD;

  status = HAL_QSPI_Command(hxspi, &cmd, W25Q_TIMEOUT_VALUE);
  if (status != HAL_OK)
  {
    return status;
  }
  status = HAL_QSPI_Receive(hxspi, &response[0], W25Q_TIMEOUT_VALUE);
  if (status == HAL_OK)
  {
    *pDeviceId = response[1];
  }

  return status;
}

HAL_StatusTypeDef W25Q_ReadDeviceIdQuadIo(xSPI_HandleTypeDef *hxspi, uint8_t *pDeviceId)
{
  QSPI_CommandTypeDef cmd;
  HAL_StatusTypeDef status;
  uint8_t response[2];

  cmd.Instruction = W25Q_READ_MFTR_DEVICE_ID_QUAD_IO;
  cmd.InstructionMode = QSPI_INSTRUCTION_1_LINE;
  cmd.Address = 0;
  cmd.AddressMode = QSPI_ADDRESS_4_LINES;
  cmd.AddressSize = W25Q_ADDRESS_BITS;
  cmd.AlternateBytes = W25Q_CONTINUOUS_READ_MODE;
  cmd.AlternateByteMode = QSPI_ALTERNATE_BYTES_4_LINES;
  cmd.AlternateBytesSize = QSPI_ALTERNATE_BYTES_8_BITS;
  cmd.DummyCycles = 4;
  cmd.NbData = 2;
  cmd.DataMode = QSPI_DATA_4_LINES;
  cmd.DdrMode = QSPI_DDR_MODE_DISABLE;
  cmd.DdrHoldHalfCycle = QSPI_DDR_HHC_ANALOG_DELAY;
  cmd.SIOOMode = QSPI_SIOO_INST_EVERY_CMD;

  status = HAL_QSPI_Command(hxspi, &cmd, W25Q_TIMEOUT_VALUE);
  if (status != HAL_OK)
  {
    return status;
  }
  status = HAL_QSPI_Receive(hxspi, &response[0], W25Q_TIMEOUT_VALUE);
  if (status == HAL_OK)
  {
    *pDeviceId = response[1];
  }

  return status;
}

HAL_StatusTypeDef W25Q_ReadUniqueId(xSPI_HandleTypeDef *hxspi, uint64_t *pUniqueId)
{
  QSPI_CommandTypeDef cmd;
  HAL_StatusTypeDef status;

  cmd.Instruction = W25Q_READ_UNIQUE_ID;
  cmd.InstructionMode = QSPI_INSTRUCTION_1_LINE;
  cmd.Address = 0;
  cmd.AddressMode = QSPI_ADDRESS_NONE;
  cmd.AddressSize = QSPI_ADDRESS_8_BITS;
  cmd.AlternateBytes = 0;
  cmd.AlternateByteMode = QSPI_ALTERNATE_BYTES_NONE;
  cmd.AlternateBytesSize = QSPI_ALTERNATE_BYTES_8_BITS;
  cmd.DummyCycles = 32;
  cmd.NbData = 8;
  cmd.DataMode = QSPI_DATA_1_LINE;
  cmd.DdrMode = QSPI_DDR_MODE_DISABLE;
  cmd.DdrHoldHalfCycle = QSPI_DDR_HHC_ANALOG_DELAY;
  cmd.SIOOMode = QSPI_SIOO_INST_EVERY_CMD;

  status = HAL_QSPI_Command(hxspi, &cmd, W25Q_TIMEOUT_VALUE);
  if (status != HAL_OK)
  {
    return status;
  }
  status = HAL_QSPI_Receive(hxspi, (uint8_t *)pUniqueId, W25Q_TIMEOUT_VALUE);

  return status;
}

HAL_StatusTypeDef W25Q_ReadJedecId(xSPI_HandleTypeDef *hxspi, uint8_t *pManufacturerId, uint8_t *pMemoryTypeId, uint8_t *pCapacityId)
{
  QSPI_CommandTypeDef cmd;
  HAL_StatusTypeDef status;
  uint8_t response[3];

  cmd.Instruction = W25Q_READ_JEDEC_ID;
  cmd.InstructionMode = QSPI_INSTRUCTION_1_LINE;
  cmd.Address = 0;
  cmd.AddressMode = QSPI_ADDRESS_NONE;
  cmd.AddressSize = QSPI_ADDRESS_8_BITS;
  cmd.AlternateBytes = 0;
  cmd.AlternateByteMode = QSPI_ALTERNATE_BYTES_NONE;
  cmd.AlternateBytesSize = QSPI_ALTERNATE_BYTES_8_BITS;
  cmd.DummyCycles = 0;
  cmd.NbData = 3;
  cmd.DataMode = QSPI_DATA_1_LINE;
  cmd.DdrMode = QSPI_DDR_MODE_DISABLE;
  cmd.DdrHoldHalfCycle = QSPI_DDR_HHC_ANALOG_DELAY;
  cmd.SIOOMode = QSPI_SIOO_INST_EVERY_CMD;

  status = HAL_QSPI_Command(hxspi, &cmd, W25Q_TIMEOUT_VALUE);
  if (status != HAL_OK)
  {
    return status;
  }
  status = HAL_QSPI_Receive(hxspi, &response[0], W25Q_TIMEOUT_VALUE);
  if (status == HAL_OK)
  {
    *pManufacturerId = response[0];
    *pMemoryTypeId   = response[1];
    *pCapacityId     = response[2];
  }

  return status;
}

HAL_StatusTypeDef W25Q_EraseSecurityRegister(xSPI_HandleTypeDef *hxspi, uint8_t RegIndex)
{
  QSPI_CommandTypeDef cmd;
  HAL_StatusTypeDef status;

  cmd.Instruction = W25Q_ERASE_SECURITY_REG;
  cmd.InstructionMode = QSPI_INSTRUCTION_1_LINE;
  cmd.Address = (uint32_t)RegIndex << 12;
  cmd.AddressMode = QSPI_ADDRESS_1_LINE;
  cmd.AddressSize = W25Q_ADDRESS_BITS;
  cmd.AlternateBytes = 0;
  cmd.AlternateByteMode = QSPI_ALTERNATE_BYTES_NONE;
  cmd.AlternateBytesSize = QSPI_ALTERNATE_BYTES_8_BITS;
  cmd.DummyCycles = 0;
  cmd.NbData = 0;
  cmd.DataMode = QSPI_DATA_NONE;
  cmd.DdrMode = QSPI_DDR_MODE_DISABLE;
  cmd.DdrHoldHalfCycle = QSPI_DDR_HHC_ANALOG_DELAY;
  cmd.SIOOMode = QSPI_SIOO_INST_EVERY_CMD;

  status = HAL_QSPI_Command(hxspi, &cmd, W25Q_TIMEOUT_VALUE);

  return status;
}

HAL_StatusTypeDef W25Q_ProgramSecurityRegister_DMA(xSPI_HandleTypeDef *hxspi, uint8_t RegIndex, uint8_t Address, uint16_t Size, void *pData)
{
  QSPI_CommandTypeDef cmd;
  HAL_StatusTypeDef status;

  cmd.Instruction = W25Q_PROGRAM_SECURITY_REG;
  cmd.InstructionMode = QSPI_INSTRUCTION_1_LINE;
  cmd.Address = ((uint32_t)RegIndex << 12) + Address;
  cmd.AddressMode = QSPI_ADDRESS_1_LINE;
  cmd.AddressSize = W25Q_ADDRESS_BITS;
  cmd.AlternateBytes = 0;
  cmd.AlternateByteMode = QSPI_ALTERNATE_BYTES_NONE;
  cmd.AlternateBytesSize = QSPI_ALTERNATE_BYTES_8_BITS;
  cmd.DummyCycles = 0;
  cmd.NbData = Size;
  cmd.DataMode = QSPI_DATA_1_LINE;
  cmd.DdrMode = QSPI_DDR_MODE_DISABLE;
  cmd.DdrHoldHalfCycle = QSPI_DDR_HHC_ANALOG_DELAY;
  cmd.SIOOMode = QSPI_SIOO_INST_EVERY_CMD;

  status = HAL_QSPI_Command(hxspi, &cmd, W25Q_TIMEOUT_VALUE);
  if (status != HAL_OK)
  {
    return status;
  }
  status = HAL_QSPI_Transmit_DMA(hxspi, pData);

  return status;
}

HAL_StatusTypeDef W25Q_ReadSecurityRegister_DMA(xSPI_HandleTypeDef *hxspi, uint8_t RegIndex, uint8_t Address, uint16_t Size, void *pData)
{
  QSPI_CommandTypeDef cmd;
  HAL_StatusTypeDef status;

  cmd.Instruction = W25Q_READ_SECURITY_REG;
  cmd.InstructionMode = QSPI_INSTRUCTION_1_LINE;
  cmd.Address = ((uint32_t)RegIndex << 12) + Address;
  cmd.AddressMode = QSPI_ADDRESS_1_LINE;
  cmd.AddressSize = W25Q_ADDRESS_BITS;
  cmd.AlternateBytes = 0;
  cmd.AlternateByteMode = QSPI_ALTERNATE_BYTES_NONE;
  cmd.AlternateBytesSize = QSPI_ALTERNATE_BYTES_8_BITS;
  cmd.DummyCycles = 8;
  cmd.NbData = Size;
  cmd.DataMode = QSPI_DATA_1_LINE;
  cmd.DdrMode = QSPI_DDR_MODE_DISABLE;
  cmd.DdrHoldHalfCycle = QSPI_DDR_HHC_ANALOG_DELAY;
  cmd.SIOOMode = QSPI_SIOO_INST_EVERY_CMD;

  status = HAL_QSPI_Command(hxspi, &cmd, W25Q_TIMEOUT_VALUE);
  if (status != HAL_OK)
  {
    return status;
  }
  status = HAL_QSPI_Receive_DMA(hxspi, pData);

  return status;
}

HAL_StatusTypeDef W25Q_IndividualLock(xSPI_HandleTypeDef *hxspi, uint32_t Address)
{
  QSPI_CommandTypeDef cmd;
  HAL_StatusTypeDef status;

  cmd.Instruction = W25Q_INDIVIDUAL_LOCK;
  cmd.InstructionMode = QSPI_INSTRUCTION_1_LINE;
  cmd.Address = Address;
  cmd.AddressMode = QSPI_ADDRESS_1_LINE;
  cmd.AddressSize = W25Q_ADDRESS_BITS;
  cmd.AlternateBytes = 0;
  cmd.AlternateByteMode = QSPI_ALTERNATE_BYTES_NONE;
  cmd.AlternateBytesSize = QSPI_ALTERNATE_BYTES_8_BITS;
  cmd.DummyCycles = 0;
  cmd.NbData = 0;
  cmd.DataMode = QSPI_DATA_NONE;
  cmd.DdrMode = QSPI_DDR_MODE_DISABLE;
  cmd.DdrHoldHalfCycle = QSPI_DDR_HHC_ANALOG_DELAY;
  cmd.SIOOMode = QSPI_SIOO_INST_EVERY_CMD;

  status = HAL_QSPI_Command(hxspi, &cmd, W25Q_TIMEOUT_VALUE);

  return status;
}

HAL_StatusTypeDef W25Q_IndividualUnlock(xSPI_HandleTypeDef *hxspi, uint32_t Address)
{
  QSPI_CommandTypeDef cmd;
  HAL_StatusTypeDef status;

  cmd.Instruction = W25Q_INDIVIDUAL_UNLOCK;
  cmd.InstructionMode = QSPI_INSTRUCTION_1_LINE;
  cmd.Address = Address;
  cmd.AddressMode = QSPI_ADDRESS_1_LINE;
  cmd.AddressSize = W25Q_ADDRESS_BITS;
  cmd.AlternateBytes = 0;
  cmd.AlternateByteMode = QSPI_ALTERNATE_BYTES_NONE;
  cmd.AlternateBytesSize = QSPI_ALTERNATE_BYTES_8_BITS;
  cmd.DummyCycles = 0;
  cmd.NbData = 0;
  cmd.DataMode = QSPI_DATA_NONE;
  cmd.DdrMode = QSPI_DDR_MODE_DISABLE;
  cmd.DdrHoldHalfCycle = QSPI_DDR_HHC_ANALOG_DELAY;
  cmd.SIOOMode = QSPI_SIOO_INST_EVERY_CMD;

  status = HAL_QSPI_Command(hxspi, &cmd, W25Q_TIMEOUT_VALUE);

  return status;
}

HAL_StatusTypeDef W25Q_ReadLockState(xSPI_HandleTypeDef *hxspi, uint32_t Address, uint8_t *pLockState)
{
  QSPI_CommandTypeDef cmd;
  HAL_StatusTypeDef status;

  cmd.Instruction = W25Q_READ_LOCK_STATE;
  cmd.InstructionMode = QSPI_INSTRUCTION_1_LINE;
  cmd.Address = Address;
  cmd.AddressMode = QSPI_ADDRESS_1_LINE;
  cmd.AddressSize = W25Q_ADDRESS_BITS;
  cmd.AlternateBytes = 0;
  cmd.AlternateByteMode = QSPI_ALTERNATE_BYTES_NONE;
  cmd.AlternateBytesSize = QSPI_ALTERNATE_BYTES_8_BITS;
  cmd.DummyCycles = 0;
  cmd.NbData = 1;
  cmd.DataMode = QSPI_DATA_1_LINE;
  cmd.DdrMode = QSPI_DDR_MODE_DISABLE;
  cmd.DdrHoldHalfCycle = QSPI_DDR_HHC_ANALOG_DELAY;
  cmd.SIOOMode = QSPI_SIOO_INST_EVERY_CMD;

  status = HAL_QSPI_Command(hxspi, &cmd, W25Q_TIMEOUT_VALUE);
  if (status != HAL_OK)
  {
    return status;
  }
  status = HAL_QSPI_Receive(hxspi, pLockState, W25Q_TIMEOUT_VALUE);

  return status;
}

HAL_StatusTypeDef W25Q_GlobalLock(xSPI_HandleTypeDef *hxspi)
{
  QSPI_CommandTypeDef cmd;
  HAL_StatusTypeDef status;

  cmd.Instruction = W25Q_GLOBAL_LOCK;
  cmd.InstructionMode = QSPI_INSTRUCTION_1_LINE;
  cmd.Address = 0;
  cmd.AddressMode = QSPI_ADDRESS_NONE;
  cmd.AddressSize = QSPI_ADDRESS_8_BITS;
  cmd.AlternateBytes = 0;
  cmd.AlternateByteMode = QSPI_ALTERNATE_BYTES_NONE;
  cmd.AlternateBytesSize = QSPI_ALTERNATE_BYTES_8_BITS;
  cmd.DummyCycles = 0;
  cmd.NbData = 0;
  cmd.DataMode = QSPI_DATA_NONE;
  cmd.DdrMode = QSPI_DDR_MODE_DISABLE;
  cmd.DdrHoldHalfCycle = QSPI_DDR_HHC_ANALOG_DELAY;
  cmd.SIOOMode = QSPI_SIOO_INST_EVERY_CMD;

  status = HAL_QSPI_Command(hxspi, &cmd, W25Q_TIMEOUT_VALUE);

  return status;
}

HAL_StatusTypeDef W25Q_GlobalUnlock(xSPI_HandleTypeDef *hxspi)
{
  QSPI_CommandTypeDef cmd;
  HAL_StatusTypeDef status;

  cmd.Instruction = W25Q_GLOBAL_UNLOCK;
  cmd.InstructionMode = QSPI_INSTRUCTION_1_LINE;
  cmd.Address = 0;
  cmd.AddressMode = QSPI_ADDRESS_NONE;
  cmd.AddressSize = QSPI_ADDRESS_8_BITS;
  cmd.AlternateBytes = 0;
  cmd.AlternateByteMode = QSPI_ALTERNATE_BYTES_NONE;
  cmd.AlternateBytesSize = QSPI_ALTERNATE_BYTES_8_BITS;
  cmd.DummyCycles = 0;
  cmd.NbData = 0;
  cmd.DataMode = QSPI_DATA_NONE;
  cmd.DdrMode = QSPI_DDR_MODE_DISABLE;
  cmd.DdrHoldHalfCycle = QSPI_DDR_HHC_ANALOG_DELAY;
  cmd.SIOOMode = QSPI_SIOO_INST_EVERY_CMD;

  status = HAL_QSPI_Command(hxspi, &cmd, W25Q_TIMEOUT_VALUE);

  return status;
}

HAL_StatusTypeDef W25Q_EnableReset(xSPI_HandleTypeDef *hxspi)
{
  QSPI_CommandTypeDef cmd;
  HAL_StatusTypeDef status;

  cmd.Instruction = W25Q_ENABLE_RESET;
  cmd.InstructionMode = QSPI_INSTRUCTION_1_LINE;
  cmd.Address = 0;
  cmd.AddressMode = QSPI_ADDRESS_NONE;
  cmd.AddressSize = QSPI_ADDRESS_8_BITS;
  cmd.AlternateBytes = 0;
  cmd.AlternateByteMode = QSPI_ALTERNATE_BYTES_NONE;
  cmd.AlternateBytesSize = QSPI_ALTERNATE_BYTES_8_BITS;
  cmd.DummyCycles = 0;
  cmd.NbData = 0;
  cmd.DataMode = QSPI_DATA_NONE;
  cmd.DdrMode = QSPI_DDR_MODE_DISABLE;
  cmd.DdrHoldHalfCycle = QSPI_DDR_HHC_ANALOG_DELAY;
  cmd.SIOOMode = QSPI_SIOO_INST_EVERY_CMD;

  status = HAL_QSPI_Command(hxspi, &cmd, W25Q_TIMEOUT_VALUE);

  return status;
}

HAL_StatusTypeDef W25Q_ResetDevice(xSPI_HandleTypeDef *hxspi)
{
  QSPI_CommandTypeDef cmd;
  HAL_StatusTypeDef status;

  cmd.Instruction = W25Q_RESET_DEVICE;
  cmd.InstructionMode = QSPI_INSTRUCTION_1_LINE;
  cmd.Address = 0;
  cmd.AddressMode = QSPI_ADDRESS_NONE;
  cmd.AddressSize = QSPI_ADDRESS_8_BITS;
  cmd.AlternateBytes = 0;
  cmd.AlternateByteMode = QSPI_ALTERNATE_BYTES_NONE;
  cmd.AlternateBytesSize = QSPI_ALTERNATE_BYTES_8_BITS;
  cmd.DummyCycles = 0;
  cmd.NbData = 0;
  cmd.DataMode = QSPI_DATA_NONE;
  cmd.DdrMode = QSPI_DDR_MODE_DISABLE;
  cmd.DdrHoldHalfCycle = QSPI_DDR_HHC_ANALOG_DELAY;
  cmd.SIOOMode = QSPI_SIOO_INST_EVERY_CMD;

  status = HAL_QSPI_Command(hxspi, &cmd, W25Q_TIMEOUT_VALUE);

  return status;
}

HAL_StatusTypeDef W25Q_Enter4BytesMode(xSPI_HandleTypeDef *hxspi)
{
  QSPI_CommandTypeDef cmd;
  HAL_StatusTypeDef status;

  cmd.Instruction = W25Q_ENTER_4B_ADDRESS_MODE;
  cmd.InstructionMode = QSPI_INSTRUCTION_1_LINE;
  cmd.Address = 0;
  cmd.AddressMode = QSPI_ADDRESS_NONE;
  cmd.AddressSize = QSPI_ADDRESS_8_BITS;
  cmd.AlternateBytes = 0;
  cmd.AlternateByteMode = QSPI_ALTERNATE_BYTES_NONE;
  cmd.AlternateBytesSize = QSPI_ALTERNATE_BYTES_8_BITS;
  cmd.DummyCycles = 0;
  cmd.NbData = 0;
  cmd.DataMode = QSPI_DATA_NONE;
  cmd.DdrMode = QSPI_DDR_MODE_DISABLE;
  cmd.DdrHoldHalfCycle = QSPI_DDR_HHC_ANALOG_DELAY;
  cmd.SIOOMode = QSPI_SIOO_INST_EVERY_CMD;

  status = HAL_QSPI_Command(hxspi, &cmd, W25Q_TIMEOUT_VALUE);

  return status;
}

HAL_StatusTypeDef W25Q_Exit4BytesMode(xSPI_HandleTypeDef *hxspi)
{
  QSPI_CommandTypeDef cmd;
  HAL_StatusTypeDef status;

  cmd.Instruction = W25Q_EXIT_4B_ADDRESS_MODE;
  cmd.InstructionMode = QSPI_INSTRUCTION_1_LINE;
  cmd.Address = 0;
  cmd.AddressMode = QSPI_ADDRESS_NONE;
  cmd.AddressSize = QSPI_ADDRESS_8_BITS;
  cmd.AlternateBytes = 0;
  cmd.AlternateByteMode = QSPI_ALTERNATE_BYTES_NONE;
  cmd.AlternateBytesSize = QSPI_ALTERNATE_BYTES_8_BITS;
  cmd.DummyCycles = 0;
  cmd.NbData = 0;
  cmd.DataMode = QSPI_DATA_NONE;
  cmd.DdrMode = QSPI_DDR_MODE_DISABLE;
  cmd.DdrHoldHalfCycle = QSPI_DDR_HHC_ANALOG_DELAY;
  cmd.SIOOMode = QSPI_SIOO_INST_EVERY_CMD;

  status = HAL_QSPI_Command(hxspi, &cmd, W25Q_TIMEOUT_VALUE);

  return status;
}

HAL_StatusTypeDef W25Q_BusyFlagPolling_IT(xSPI_HandleTypeDef *hxspi)
{
  QSPI_CommandTypeDef cmd;
  QSPI_AutoPollingTypeDef cfg;
  HAL_StatusTypeDef status;

  cmd.Instruction = W25Q_READ_STATUS_REG_1;
  cmd.InstructionMode = QSPI_INSTRUCTION_1_LINE;
  cmd.Address = 0;
  cmd.AddressMode = QSPI_ADDRESS_NONE;
  cmd.AddressSize = QSPI_ADDRESS_8_BITS;
  cmd.AlternateBytes = 0;
  cmd.AlternateByteMode = QSPI_ALTERNATE_BYTES_NONE;
  cmd.AlternateBytesSize = QSPI_ALTERNATE_BYTES_8_BITS;
  cmd.DummyCycles = 0;
  cmd.NbData = 1;
  cmd.DataMode = QSPI_DATA_1_LINE;
  cmd.DdrMode = QSPI_DDR_MODE_DISABLE;
  cmd.DdrHoldHalfCycle = QSPI_DDR_HHC_ANALOG_DELAY;
  cmd.SIOOMode = QSPI_SIOO_INST_EVERY_CMD;

  cfg.Match = 0x00;
  cfg.Mask = W25Q_SR1_BUSY_MASK;
  cfg.Interval = 0;
  cfg.StatusBytesSize = 1;
  cfg.MatchMode = QSPI_MATCH_MODE_AND;
  cfg.AutomaticStop = QSPI_AUTOMATIC_STOP_ENABLE;

  status = HAL_QSPI_AutoPolling_IT(hxspi, &cmd, &cfg);

  return status;
}

W25Q_StateTypeDef W25Q_GetState(xSPI_HandleTypeDef *hxspi)
{
  HAL_StatusTypeDef status;
  W25Q_StateTypeDef state;
  uint8_t sr1Value;

  status = W25Q_ReadStatusRegister(hxspi, W25Q_SR1, &sr1Value);

  switch (status)
  {
    case HAL_OK:
      if ((sr1Value & W25Q_SR1_BUSY_MASK) != W25Q_SR1_BUSY)
      {
        state = W25Q_STATE_READY;
      }
      else
      {
        state = W25Q_STATE_BUSY;
      }
      break;
    case HAL_BUSY:
      state = W25Q_STATE_BUSY;
      break;
    default: // HAL_ERROR or HAL_TIMEOUT
      state = W25Q_STATE_ERROR;
  }

  return state;
}

#endif // HAL_QSPI_MODULE_ENABLED
