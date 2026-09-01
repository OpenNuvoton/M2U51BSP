# M2U51 BSP Current SBOM

## SBOM Files

| File | Purpose |
|---|---|
| `M2U51BSP_Product_SBOM_cdx.json` | Current Product SBOM for Product vulnerability assessment. |
| `M2U51BSP_TestSample_SBOM_cdx.json` | Current Test Sample SBOM for sample code and FMC IAP firmware artifact assessment. |
| `M2U51BSP_SBOM_Manifest.json` | Manifest index for the two current SBOM files. |

## SBOM Information

| Item | Value |
|---|---|
| SBOM Format | CycloneDX 1.6 |
| Source Git Commit | `00b0843b3254c1c09961d0fc5d4b1b266a547ae8` |
| Release Identifier | `V3.00.000-14-g00b0843b` |
| Formal SVN Revision | `48` |
| Product Components | 5 |
| Test Sample Components | 8 |

The Product SBOM is the primary input for Product vulnerability assessment.
The Test Sample SBOM contains sample code, FreeRTOS-Kernel 10.5.1, three FMC
IAP firmware components, and three exact-path binary file components for IAR,
Keil, and GCC.

The current Product and Test Sample SBOM files are byte-for-byte copies of the
formal SVN release generated from clean merged source commit
`00b0843b3254c1c09961d0fc5d4b1b266a547ae8`. The immutable evidence package is
stored at `bsp/m2u51/V3.00.000-14-g00b0843b/` in SVN revision 48.

## Vulnerability scan status

The Product scan records zero matches, which is not a clean-security claim.
The Test Sample scan records five CPE-based matches for FreeRTOS-Kernel 10.5.1:
one Critical and four High. The raw reports preserve every finding. Findings
are disclosed and Product Security disposition remains pending; no affected,
not-affected, fixed, resolved, VEX, or approval status is asserted.

The scan used Grype 0.117.0 with database schema v6.1.9, built
2026-08-31T06:37:31Z and reported valid. CycloneDX identifiers and offline or
stale databases can limit coverage.

## Git Artifact Distribution

The Git commit that distributes these files is artifact-only. It is not a new
SBOM scan source, and its commit SHA is intentionally not recorded in the
manifest because a tracked file cannot contain its own commit SHA.

## Regeneration

Regenerate the current SBOM files when the Git commit, scope, component
evidence, binary hash, license evidence, or build closure changes.
