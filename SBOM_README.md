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
| Source Git Commit      | 2ea3b0351c9953fe2f36bace75fe943fdea3f5c6 |
| Current SBOM Identity  | V3.00.000-11-g2ea3b035                   |
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

The current SBOM files were generated from clean Git source commit
`2ea3b0351c9953fe2f36bace75fe943fdea3f5c6`. They supersede the current
Git artifacts from formal SVN release `V3.00.000-5-g5b218455`.

The latest formal SVN release remains
`bsp/m2u51/V3.00.000-5-g5b218455/` until a new immutable release package is
generated and validated from the merged Git SBOM artifact commit.

## Git Current Artifact

The Git commit that distributes these current files is an SBOM artifact
commit. The files record the preceding clean source/evidence commit because a
tracked file cannot contain the SHA of its own commit. After this artifact
commit is merged, it becomes the source identity for the next formal SVN
release generation.

## Regeneration

The Current SBOM files shall be regenerated when the Git Commit, SBOM
Scope, Component Evidence, Binary Hash, License Evidence, or Build
Closure changes.

Do not manually edit the generated Product or Test Sample SBOM files.
