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
| Source Git Commit      | 5b218455116c756a5ca72ee97f8faa92ef8a97d3 |
| Release Identifier     | V3.00.000-5-g5b218455                    |
| Product Components     | 5                                        |
| Test Sample Components | 7                                        |

The Product SBOM and Test Sample SBOM are separated by design.

The Product SBOM is the primary input for Product vulnerability
assessment.

The Test Sample SBOM contains sample code, three FMC IAP LDROM
Firmware components, and three exact-path binary file components for the IAR,
Keil, and GCC build environments.

The FMC IAP Firmware components are represented as first-party Build
Artifacts with Apache-2.0 License Evidence supported by the recorded
Build Closure Review.

The immutable, versioned SBOM Release Evidence Package is maintained in
the corresponding SVN SBOM release directory:
`bsp/m2u51/V3.00.000-5-g5b218455/`.

## Git Artifact Distribution

The Product and Test Sample SBOM files in this directory are byte-for-byte
copies of formal SVN release `V3.00.000-5-g5b218455`, generated from clean
source commit `5b218455116c756a5ca72ee97f8faa92ef8a97d3`.

The Git commit that distributes these files is artifact-only. It is not a new
SBOM scan source, and its commit SHA is intentionally not recorded in the
manifest because a tracked file cannot contain the SHA of its own commit.

## Regeneration

The Current SBOM files shall be regenerated when the Git Commit, SBOM
Scope, Component Evidence, Binary Hash, License Evidence, or Build
Closure changes.

Do not manually edit the generated Product or Test Sample SBOM files.
