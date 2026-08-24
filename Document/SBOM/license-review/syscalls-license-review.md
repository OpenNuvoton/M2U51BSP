# M2U51 `_syscalls.c` License Review Decision

## Review Status

Accepted for SBOM treatment based on the established M55M1 BSP precedent.

This record documents the SBOM classification decision. It does not relicense
third-party source code or override file-level copyright and license notices.

## Reviewed File

`Library/Device/Nuvoton/M2U51/Source/GCC/_syscalls.c`

## File-Level Notices

The file contains the following notices:

- The file is part of the µOS++ III distribution.
- Parts of the file are from newlib sources and are stated to be issued under GPL.
- Copyright (c) 2014 Liviu Ionescu.

These file-level notices remain applicable and are not replaced by the
directory-level BSP component license declaration.

## Distribution Status

The file is tracked by Git and distributed as part of the M2U51 BSP repository.

## Build Relationship

No explicit reference to `_syscalls.c` was identified in the reviewed M2U51
build metadata, SampleCode project files, or generated build metadata.

The file is treated as an optional distributed GCC syscall and semihosting
source template. It has not been demonstrated to be part of the default
M2U51 product build.

## M55M1 Precedent

The M55M1 BSP distributes an `_syscalls.c` file with the same source notices
and implementation pattern.

The approved M55M1 Product SBOM does not define a separate `_syscalls.c`,
µOS++, or newlib component. The file is represented through the directory-level
`Library/Device` product component.

M2U51 follows this established SBOM representation:

- No separate `_syscalls.c` CycloneDX component is created.
- No separate newlib or µOS++ component is asserted without reliable version evidence.
- The file remains within the directory-level `M2U51 Device` component.
- File-level third-party notices are preserved.
- The directory-level Apache-2.0 declaration shall not be interpreted as
  relicensing the third-party portions of `_syscalls.c`.

## File Identity Evidence

- M2U51 SHA-256: `F2A6DFF29C7EEB015068E34B4498B99A154A86D67ADB2F9CF1ED935D2FD3CD7E`
- M55M1 SHA-256: `4BAD59591992CFEAB783AE10B7CBB8DA95FA8A6A8227301B779B3EE4BE00591E`
- Byte-for-byte identity confirmed: `False`

If byte-for-byte identity has not been confirmed, the M55M1 precedent is used
only for SBOM representation, not as proof of an identical upstream revision.

## SBOM Treatment

The file remains represented by:

- Component: `M2U51 Device`
- Type: `library`
- Scope: `required`
- Component granularity: directory
- Product relationship: included in the Product SBOM

No additional manual CycloneDX component is added because an exact upstream
package version and applicable SPDX license expression have not been confirmed.

## Review Conditions

This decision must be reviewed again if any of the following occurs:

1. `_syscalls.c` is added to a default product build.
2. The file content or license header changes.
3. An exact µOS++ or newlib upstream revision is identified.
4. The applicable GPL version or exception terms are confirmed.
5. The M55M1 SBOM treatment is revised.
6. Internal OSS or Legal review requires a separate component or license notice.

## Release Decision

For SBOM representation, the previous release-blocking finding is closed by
following the established M55M1 directory-level treatment.

The file-level third-party notices remain documented and must be preserved in
all source distributions.

Resolution date: 2026-08-24