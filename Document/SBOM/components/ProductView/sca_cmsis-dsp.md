# CMSIS-DSP Third-Party Component Evidence

## Component

- Name: CMSIS-DSP
- Supplier: Arm Limited
- Component Type: Library
- Integration: Vendored source subset
- SBOM View: Product SBOM
- Scope: Optional

## Included Path

- `Library/CMSIS/DSP`

## Included Source Areas

The distributed CMSIS-DSP subset includes the following primary source areas:

- `Library/CMSIS/DSP/Include`
- `Library/CMSIS/DSP/PrivateInclude`
- `Library/CMSIS/DSP/Source`

## Relationship to CMSIS

CMSIS-DSP is maintained as an independent SBOM component because it has its own version and release lifecycle.

It is excluded from the main CMSIS component represented by:

- `Document/SBOM/components/ProductView/sca_cmsis.json`
- `Document/SBOM/components/ProductView/sca_cmsis.md`

## Version Evidence

- Version: 1.10.0
- Evidence: `Library/CMSIS/DSP/Include/arm_math.h`

The file header contains:

- `@version V1.10.0`
- `@date 08 July 2021`

## License

- SPDX License Identifier: Apache-2.0

## License Evidence

Representative evidence:

- `Library/CMSIS/DSP/Include/arm_math.h`

The source license scan identified:

- 296 source or header files containing `SPDX-License-Identifier: Apache-2.0`
- 296 source or header files containing an Apache License 2.0 declaration

No other SPDX license identifier was identified in the distributed CMSIS-DSP source subset during the review.

## Repository Traceability

The CMSIS-DSP directory and representative header can be traced in the BSP repository to:

- BSP import commit: `0c04521352c26bcf9352ee78292be0dfb6f346cf`
- Import commit message: `clone from SVN`

The BSP import commit is not treated as an upstream CMSIS-DSP commit.

## Upstream Traceability

The local source evidence confirms CMSIS-DSP version 1.10.0.

An exact upstream repository tag and upstream commit have not been confirmed from the files distributed in this BSP. No upstream tag or commit shall be asserted without additional evidence.

## SBOM Classification

- Origin: Third-party
- Integration: Vendored source subset
- Product relationship: Optional firmware library
- Component version used by the SBOM: 1.10.0
