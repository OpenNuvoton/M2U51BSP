# M2U51 BSP Current SBOM

## SBOM Files

| File                              | Purpose                                                                            |
|-----------------------------------|------------------------------------------------------------------------------------|
| M2U51BSP_Product_SBOM_cdx.json    | Current Product SBOM for Product vulnerability assessment.                         |
| M2U51BSP_TestSample_SBOM_cdx.json | Current Test Sample SBOM for sample code and FMC IAP Firmware Artifact assessment. |
| M2U51BSP_SBOM_Manifest.json       | Manifest Index for the two Current SBOM files.                                     |

## SBOM Information

| Item                   | Value                                    |
|------------------------|------------------------------------------|
| SBOM Format            | CycloneDX                                |
| CycloneDX Version      | 1.6                                      |
| Source Git Commit      | 2d7239bf30845b214f2fb6af38e13244bd3b479a |
| Release Identifier     | V3.00.000-12-g2d7239bf                   |
| Formal SVN Revision    | 41                                       |
| Product Components     | 5                                        |
| Test Sample Components | 8                                        |

The Product SBOM and Test Sample SBOM are separated by design.

The Product SBOM is the primary input for Product vulnerability
assessment.

The Test Sample SBOM contains sample code, the vendored FreeRTOS Kernel
10.5.1 component, three FMC IAP LDROM Firmware components, and three
exact-path binary file components for the IAR, Keil, and GCC build
environments.

The FMC IAP Firmware components are represented as first-party Build
Artifacts with Apache-2.0 License Evidence supported by the recorded
Build Closure Review.

The current Product and Test Sample SBOM files are byte-for-byte copies of
formal SVN release `V3.00.000-12-g2d7239bf`, generated from clean source
commit `2d7239bf30845b214f2fb6af38e13244bd3b479a`.

The immutable evidence package is stored at
`bsp/m2u51/V3.00.000-12-g2d7239bf/` in SVN revision 41.

## Vulnerability scan status

The formal Product scan records zero matches. The Test Sample scan records
five CPE-based matches for FreeRTOS-Kernel 10.5.1: one Critical and four High.
The formal package preserves the raw findings but makes no affected or
not-affected VEX applicability disposition.

## Git Artifact Distribution

The Git commit that distributes these files is artifact-only. It is not a new
SBOM scan source, and its commit SHA is intentionally not recorded in the
manifest because a tracked file cannot contain the SHA of its own commit.

## Regeneration

The Current SBOM files shall be regenerated when the Git Commit, SBOM
Scope, Component Evidence, Binary Hash, License Evidence, or Build
Closure changes.

Do not manually edit the generated Product or Test Sample SBOM files.
