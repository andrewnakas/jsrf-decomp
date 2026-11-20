# Status

## 2026-11-19: clean start

| | |
|---|---|
| Target | `default.xbe` verified: sha256 `fd19055756719893c466302809b433b785ecf5732df0441286f3f605f0f3ef9c`, title id `5345000A`, linked 2002-01-28, Xbox SDK libraries version 1.0.4134 |
| Toolchain | Pinned: Microsoft Visual C++ 7.0 (`cl` 13.00.9466) under Wine, with the flags in `xbx.toml`. The compiler's files are recorded by checksum in `toolchain/checksums.sha256`. The `xbx` tools are pinned by commit in `requirements.txt`. |
| Units | 10 matched (`src/funcs/`), 0 non-matching (`src/nonmatching/`): the calibration set below |
| Merging | Steward with five gates (toolcheck, scan, split, match, build). No AI takes part. |

## Function table

`config/functions.csv` lists 9,344 functions.

| Owner | Functions | Bytes | Counts toward |
|---|---|---|---|
| `game` | 8,101 (6,948 kind `func`, 1,153 kind `eh`) | 1,509,111 | the headline |
| `lib:d3d8` | 275 | 57,181 | the library category |
| `lib:dsound` | 719 | 115,267 | the library category |
| `lib:xgraphics` | 10 | 3,321 | the library category |
| `lib:xpp` | 239 | 30,607 | the library category |

- Kind `eh` rows are compiler-made exception-handling stubs. They are matched together with the function that
  registers them (the `parent` column) and never get a unit of their own.
- 442 functions (104 of them `game`) have a non-empty `conv`: link-time code generation gave them a custom
  calling convention. Lanes skip them for now (AGENTS.md).

## How the flags were pinned

Ten small functions of different shapes (loops, member functions, a virtual call, floating point, a callback)
were matched by hand, then compiled again under other flag sets. The pinned set is the plainest one that
matches all ten.

| Flags | Matches of 10 |
|---|---|
| `/O2 /GX` (pinned) | 10 |
| `/O2`, `/Ox /GX`, `/O2 /GX /G6`, `/O2 /GX /GF`, `/Ogityb1 /GX` | 10 (the same code: these ten do not tell them apart) |
| `/O2 /GX /Op` | 9 |
| `/O2 /GX /G5` | 7 |
| `/O2 /GX /Gr` | 7 |
| `/O2 /GX /Oy-` | 4 |
| `/O1 /GX` | 1 |

`/GX` is pinned because the executable carries C++ exception-handling tables (1,153 compiler-made stubs); none
of the ten functions has one, so they match with or without it. A function that only matches under another
set is evidence for a per-file flag: see RULES.md.

## Known gaps

- `.text` also holds library code that has no section of its own (the executable's library table lists XAPILIB,
  LIBCMT and LIBCPMT). It is not tagged yet, so the table counts it as `game`. The headline denominator shrinks
  as those ranges are tagged in `xbx.toml`.
- Link-time code generation is rare here: 104 `game` functions read a register no standard calling convention
  passes arguments in. The per-object compile cannot reproduce those; everything else is in reach.
- `config/symbols.csv` is empty. Library, runtime and kernel-import names are added by maintainers as units
  need them.

## History

| Date | Milestone |
|---|---|
| 2026-11-19 | Project started. Executable verified, compiler pinned, function table generated, Steward and CI configured. 10 calibration units matched by hand. |
