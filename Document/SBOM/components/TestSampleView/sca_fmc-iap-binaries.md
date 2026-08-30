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

## Software Identifiers

The firmware artifacts use generic Package URLs that identify the M2U51
FMC_IAP LDROM artifact and the corresponding build toolchain:

- IAR:
  `pkg:generic/m2u51-fmc-iap-ldrom@iar?artifact=fmc_ld_iap.bin`
- Keil:
  `pkg:generic/m2u51-fmc-iap-ldrom@keil?artifact=fmc_ld_iap.bin`
- GCC:
  `pkg:generic/m2u51-fmc-iap-ldrom@gcc?artifact=fmc_ld_iap.bin`

The Package URLs were validated against CycloneDX 1.6 and accepted by the
SBOM compliance checker as software identifiers. Package URL assignment
does not determine or assert the binary license.

## Binary Identity

The three files have different sizes and SHA-256 values. They are treated as separate build artifacts produced for different toolchains rather than duplicate copies of a single binary.

## License Treatment

The related M2U51 sample source files use Apache-2.0 SPDX declarations.

A binary artifact shall not automatically be assigned Apache-2.0 solely based on the source license when the applicable compiler runtime and linked toolchain support have not been independently evaluated.

No evidence currently identifies these files as externally supplied third-party binary packages.

### Build Closure Review Result

The M2U51 FMC_IAP LDROM firmware binaries follow the same first-party
repository-built sample firmware and license treatment principle used by
the M460 FMC_IAP sample.

The IAR, Keil, and GCC firmware artifacts are generated from the
corresponding M2U51 FMC_IAP sample source. The related source files use
Apache-2.0 SPDX declarations, and the firmware artifacts are embedded or
referenced by the corresponding FMC_IAP APROM sample projects.

Review of the recorded repository build relationships did not identify an
externally supplied third-party binary package or a separately distributed
binary-only component as an input to these firmware artifacts.

No independently licensed redistributable compiler runtime requiring a
separate SBOM license representation was identified in the reviewed
repository build closure.

Therefore, the applicable SBOM license representation for the reviewed IAR,
Keil, and GCC FMC_IAP LDROM firmware artifacts is `Apache-2.0`.

This decision applies only to the following reviewed artifact hashes:

- IAR:
  `5C3C7DE4395FE61AF314BCCA715A6BBF9AE1289D714775975AD4762148EFA82C`
- Keil:
  `8174A77F0068F5A87164FFDD10CBE42634F6AA07115753B4C473D7DC67505241`
- GCC:
  `B45A1CCB8981686794E456F272D8FD702E74CBEF0D15D09160651C70F2E6FD01`

A rebuilt artifact shall be revalidated when its SHA-256 hash, source
closure, build configuration, linked input, or toolchain runtime changes.

## SBOM Treatment

The three binaries shall be represented in the Test Sample SBOM as firmware artifacts associated with the FMC_IAP sample.

They shall not be represented as Product SBOM runtime components.

They do not require a third-party binary license database entry unless subsequent analysis identifies an externally supplied binary or redistributable toolchain runtime.
