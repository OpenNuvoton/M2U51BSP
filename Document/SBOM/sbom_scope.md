# M2U51 BSP SBOM Scope Definition

## 1. Purpose

This document defines the Product SBOM and Test Sample SBOM scopes for the M2U51 BSP.

## 2. Product SBOM Scope

The Product SBOM contains software components intended to support target
firmware development and runtime integration.

### Included Paths

- `Library/CMSIS`
- `Library/Device`
- `Library/LCDLib`
- `Library/StdDriver`

### Excluded Paths

- `Document/`
- `SampleCode/`
- `Library/CMSIS/Documentation/`
- `Library/CMSIS/Core/Test/`
- `Library/Device/Nuvoton/M2U51/Source/GCC/_syscalls.c`
- `Library/Device/Nuvoton/M2U51/Source/GCC/semihosting.h`

The GCC `_syscalls.c` and `semihosting.h` files are retained in the
repository but excluded from the Product SBOM. Repository-wide project and
build configuration review found no external reference that compiles or
links these files.

The separate `Library/Device/Nuvoton/M2U51/Source/semihost.s` file remains
in scope because multiple Keil sample projects explicitly reference it.


CMSIS documentation and CMSIS upstream test content are distributed as
reference material but are not treated as Product runtime components.
They are therefore excluded from the Product SBOM scan view.

## 3. Test Sample SBOM Scope

The Test Sample SBOM contains examples, demonstration projects, validation projects, project configuration files, and generated sample binaries distributed with the BSP.

### Included Paths

- `SampleCode/`

### Excluded Paths

- `Document/`
- `Library/`

## 4. Scope Relationship

The Product SBOM and Test Sample SBOM are complementary views of the same BSP release.

The Test Sample SBOM is not interpreted as a runtime dependency of the Product SBOM unless an individual sample component is explicitly integrated into a product.

## 5. Scope Maintenance

The scope definitions shall be reviewed when any of the following conditions occur:

- A new top-level BSP directory is added.
- A new library or middleware component is introduced.
- A third-party component is added or removed.
- A host-side tool or binary utility is added.
- The BSP release structure changes.
