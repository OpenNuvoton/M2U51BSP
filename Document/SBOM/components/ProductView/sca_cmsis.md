# CMSIS Third-Party Component Evidence

## Component

- Name: CMSIS
- Supplier: Arm Limited
- Component Type: Library
- Integration: Vendored source subset
- SBOM View: Product SBOM
- Scope: Required

## Included Paths

- `Library/CMSIS/Core`
- `Library/CMSIS/Driver`
- `Library/CMSIS/RTOS2`

## Excluded Independent Components

- `Library/CMSIS/DSP`

CMSIS-DSP is maintained as an independent SBOM component because it has its own version and release lifecycle.

## Components Not Present as Source

The following items appear only in generated documentation and are not represented as independent source components:

- CMSIS-Compiler
- CMSIS-NN
- CMSIS-DAP
- CMSIS-Stream
- CMSIS-Toolbox
- CMSIS-View
- CMSIS-Zone

Compiler abstraction headers located under `Library/CMSIS/Core/Include` are treated as part of CMSIS-Core.

## Version Evidence

### CMSIS-Core

- Version: 6.1.0
- Evidence: `Library/CMSIS/Core/Include/cmsis_version.h`
- Version macros:
  - `__CM_CMSIS_VERSION_MAIN = 6`
  - `__CM_CMSIS_VERSION_SUB = 1`

### CMSIS-RTOS2 API

- Version: 2.3.0
- Evidence: `Library/CMSIS/RTOS2/Include/cmsis_os2.h`

## License

- SPDX License Identifier: Apache-2.0

## License Evidence

The source scan identified the following Apache-2.0 SPDX declarations:

- CMSIS-Core: 55 files
- CMSIS-Driver: 36 files
- CMSIS-RTOS2: 5 files

Representative evidence files:

- `Library/CMSIS/Core/Include/cmsis_version.h`
- `Library/CMSIS/RTOS2/Include/cmsis_os2.h`

## Upstream Traceability

The local source evidence confirms the included CMSIS-Core and CMSIS-RTOS2 API versions.

An exact upstream repository tag and upstream commit have not been confirmed from the files distributed in this BSP. No upstream tag or commit shall be asserted without additional evidence.

## SBOM Classification

- Origin: Third-party
- Integration: Vendored source subset
- Product relationship: Required development and runtime support library
- Component version used by the SBOM: 6.1.0
