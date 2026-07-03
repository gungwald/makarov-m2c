# AGENTS.md

## Big Picture
- This repository is **M2C**, a Modula-2 to C translator; pipeline is scanner -> parser -> semantics -> generator -> C output (`README`, `m2-main.c`).
- The compiler executable is `m2c`; runtime support is archived as `m2lib.a` from `m2l_*.c` (`Makefile`).
- Core boundaries are file-based by phase: `m2-scanner.*`, `m2-syntax.*`, `m2-semantics.*`, `m2-generator.*`, with shared IR/state in `m2-icode.*` and `m2-common.h`.

## Key Directories and Files
- Compiler driver and mode orchestration: `m2-main.c`.
- Shared compiler data and macros: `m2-common.h`, `m2-config.h`.
- Intermediate representation node modes (`ICNM_*`): `m2-icode.h`.
- Platform/config headers and suffix defaults (`.def`, `.mod`, `.o`): `config/`, especially `config/common_part.h`.
- Language tests are under `m2-tests/`; naming follows report sections (see `m2-tests/README`).

## Build and Run Workflow
- Build everything:
  ```bash
  make
  ```
- Clean build artifacts:
  ```bash
  make clean
  ```
- Install (target exists in `Makefile`):
  ```bash
  make install
  ```
- Compile a module with verbose output:
  ```bash
  ./m2c -v path/to/file.mod
  ```

## Compiler Modes Agents Should Know
- `-all`: full-program mode with dependency-aware analysis/generation.
- `-make`: incremental dependency rebuild behavior.
- `-MAKE`: emit make-style dependency rules.
- `-C`: generate C only (skip C compilation/linking stage).
- `-update`: timestamp-based recompilation decisions.
- `-strict` and `-3`: stricter language compatibility modes.

## Project Conventions (Non-Generic)
- Module naming is consistent and meaningful: compiler phase files use `m2-*.c/.h`; runtime helpers use `m2l_*.c`.
- Standard library modules are paired `.def`/`.mod` files in repo root (for example `String.def` + `String.mod`).
- Parser/scanner token and stop-symbol handling is centralized in scanner/syntax headers; follow existing enums/macros rather than ad hoc literals (`m2-scanner.h`, `m2-syntax.h`).
- Memory/dynamic buffers rely on project macros (`M2C_ALLOC`/`M2C_FREE`, VLS helpers); preserve these patterns instead of mixing raw allocation styles.
- Driver behavior is flag-heavy with static global option state in `m2-main.c`; new options should align with that model.

## Integration Notes
- External toolchain dependency is the host C compiler/linker invoked after C generation; `m2c` may stop early with `-C`.
- Dependency and import ordering matter: definition modules must be discoverable before implementation modules in multi-module builds.
- When debugging cross-phase issues, start at `m2-main.c` mode path, then trace phase handoff (`scanner -> syntax -> semantics -> generator`).

