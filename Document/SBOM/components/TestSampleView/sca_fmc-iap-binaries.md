# M2U51 FMC_IAP Binary Artifact Evidence

## Classification

- SBOM View: Test Sample SBOM
- Sample: FMC_IAP
- Component Type: Firmware
- Origin: Built from the M2U51 BSP sample source
- Distribution Status: Tracked and distributed in the BSP repository

## Source Files

Representative source files include:

- `SampleCode/StdDriver/FMC_IAP/aprom_main.c`
- `SampleCode/StdDriver/FMC_IAP/ldrom_main.c`
- `SampleCode/StdDriver/FMC_IAP/system_M2U51.c`

## IAR Binary

- Toolchain: IAR
- Path: `SampleCode/StdDriver/FMC_IAP/IAR/Release/Exe/fmc_ld_iap.bin`
- Size: 1292 bytes
- SHA-256: `5C3C7DE4395FE61AF314BCCA715A6BBF9AE1289D714775975AD4762148EFA82C`

### Relationship Evidence

The IAR project configuration generates and embeds the binary through:

- `SampleCode/StdDriver/FMC_IAP/IAR/fmc_ld_iap.ewp`
- `SampleCode/StdDriver/FMC_IAP/IAR/fmc_ap_main.ewp`

## Keil Binary

- Toolchain: Keil
- Path: `SampleCode/StdDriver/FMC_IAP/KEIL/obj/fmc_ld_iap.bin`
- Size: 2704 bytes
- SHA-256: `8174A77F0068F5A87164FFDD10CBE42634F6AA07115753B4C473D7DC67505241`

### Relationship Evidence

The binary is embedded by:

- `SampleCode/StdDriver/FMC_IAP/KEIL/ap_image.s`

The assembly source uses:

- `INCBIN ./obj/fmc_ld_iap.bin`

## VSCode/GCC Binary

- Toolchain: GCC through the VSCode CMSIS project
- Path: `SampleCode/StdDriver/FMC_IAP/VSCode/bin/fmc_ld_iap.bin`
- Size: 2780 bytes
- SHA-256: `B45A1CCB8981686794E456F272D8FD702E74CBEF0D15D09160651C70F2E6FD01`

### Relationship Evidence

The binary is referenced by:

- `SampleCode/StdDriver/FMC_IAP/VSCode/FMC_IAP_APROM/ap_image.s`
- `SampleCode/StdDriver/FMC_IAP/VSCode/FMC_IAP_APROM/ap_image_gcc.S`
- `SampleCode/StdDriver/FMC_IAP/VSCode/FMC_IAP_LDROM/FMC_IAP_LDROM.cproject.yml`

## Binary Identity

The three files have different sizes and SHA-256 values. They are treated as separate build artifacts produced for different toolchains rather than duplicate copies of a single binary.

## License Treatment

The related M2U51 sample source files use Apache-2.0 SPDX declarations.

A binary artifact shall not automatically be assigned Apache-2.0 solely based on the source license when the applicable compiler runtime and linked toolchain support have not been independently evaluated.

No evidence currently identifies these files as externally supplied third-party binary packages.

## SBOM Treatment

The three binaries shall be represented in the Test Sample SBOM as firmware artifacts associated with the FMC_IAP sample.

They shall not be represented as Product SBOM runtime components.

They do not require a third-party binary license database entry unless subsequent analysis identifies an externally supplied binary or redistributable toolchain runtime.
