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
| Source Git Commit      | ed801718d15370f136863c6307fc3b545a8289d9 |
| Current SBOM Identity  | ed801718                                 |
| Formal SVN Release     | Pending source review merge              |
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

The current Product and Test Sample SBOM files were generated from clean source
commit `ed801718d15370f136863c6307fc3b545a8289d9`. They are source-review
artifacts, not a new formal release.

The prior immutable formal package remains
`bsp/m2u51/V3.00.000-12-g2d7239bf/` at SVN revision 41. It and
`latest-release.txt` are unchanged. A new canonical versioned SVN release may
be generated only after this source/current review is merged, using the actual
merged master commit.

## Vulnerability scan status

The validation Product scan records zero matches. The Test Sample scan records
five CPE-based matches for FreeRTOS-Kernel 10.5.1: one Critical and four High.
The raw Grype reports preserve all findings. No affected, not-affected, fixed,
resolved, VEX, or Product Security approval disposition is asserted;
disposition remains pending Product Security review.

The scan used Grype 0.117.0 with database schema v6.1.9, built
2026-08-31T06:37:31Z and reported valid. CycloneDX inputs can omit identifiers
needed for matching, while offline or stale databases further limit coverage.
Zero matches is not a clean or complete security assessment.

## Two-stage delivery status

This change is stage one: one source/current SBOM Git review. It does not create
or modify an SVN release or an artifact-only Git commit. Stage two starts only
after the source review is confirmed merged.

## Regeneration

The Current SBOM files shall be regenerated when the Git Commit, SBOM
Scope, Component Evidence, Binary Hash, License Evidence, or Build
Closure changes.

Do not manually edit the generated Product or Test Sample SBOM files.
