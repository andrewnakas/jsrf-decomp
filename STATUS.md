# Status

## 2026-11-19: clean start

| | |
|---|---|
| Target | `default.xbe` verified: sha256 `fd19055756719893c466302809b433b785ecf5732df0441286f3f605f0f3ef9c`, title id `5345000A`, linked 2002-01-28, Xbox SDK libraries version 1.0.4134 |
| Toolchain | Pinned: Microsoft Visual C++ 7.0 (`cl` 13.00.9466) under Wine, with the flags in `xbx.toml`. The compiler's files are recorded by checksum in `toolchain/checksums.sha256`. The `xbx` tools are pinned by commit in `requirements.txt`. |
| Units | 10 matched (`src/funcs/`), 0 non-matching (`src/nonmatching/`): the calibration set below |
| Merging | Steward with five gates (toolcheck, scan, split, match, build). No AI takes part. |

## Function table

`config/functions.csv` lists 9,260 functions. The headline counts 7,150 of them (1,398,634 bytes).

| Owner | Functions | Bytes | Counts toward |
|---|---|---|---|
| `game` | 5,715 (4,714 kind `func`, 1,001 kind `eh`) | 1,206,966 | the headline |
| `engine` | 592 | 78,916 | the headline |
| `musashi` | 843 (693 kind `func`, 150 kind `eh`) | 112,752 | the headline |
| `lib:adx` | 429 | 41,908 | the library category |
| `lib:crt` | 264 (262 kind `func`, 2 kind `eh`) | 27,628 | the library category |
| `lib:d3d8` | 275 | 57,181 | the library category |
| `lib:dsound` | 720 | 115,275 | the library category |
| `lib:xapi` | 155 | 25,384 | the library category |
| `lib:xboxkrnl` | 6 | 36 | the library category |
| `lib:xgraphics` | 22 | 18,859 | the library category |
| `lib:xpp` | 239 | 30,607 | the library category |

- Kind `eh` rows are compiler-made exception-handling stubs. They are matched together with the function that
  registers them (the `parent` column) and never get a unit of their own.
- Other compiler-made functions (deleting and implicit destructors, adjustor thunks, special members emitted
  as COMDATs) are placed and proven inside the unit that carries them. `config/covered.csv` lists them so the
  progress report counts them; the match gate refuses the file if it lists one no proven unit carries. A
  maintainer refreshes it with `xbx covers --write`.
- 412 functions (33 of them `game`) have a non-empty `conv`: link-time code generation gave them a custom
  calling convention. Lanes skip them for now (AGENTS.md).

## What is in `.text`

The linker laid `.text` out in the order it took its inputs: the game's own objects, then what it pulled from
libraries. The boundaries below were found from the executable alone (2026-11-19) and three independent signs
agree on them: the code style (function alignment and padding), the order of the data each range uses, and the
order of the exception-handling stubs.

| Range | Owner | Evidence |
|---|---|---|
| `0x11000`–`0x13A570` | `game` | Every function aligned to 16 bytes. The only code that uses the game's own data. |
| `0x13A570`–`0x145560` | `lib:adx` | The only code that refers to the version strings at `0x1DEFD5` and after ("ADXT/XB Ver.7.49", "ADXF/XB Ver.6.21", "CVFS/XB Ver.2.23" and others, built 10 December 2001). It uses none of the game's data and the game uses none of its. |
| `0x145560`–`0x14B774`, `0x182B81`–`0x182C97` | `lib:xapi` | Packed, unaligned code. 90 of the first range's 150 functions call kernel imports directly; no function of the game or of ADX does. Holds the executable's entry point (`0x148023`), which ends up calling the game's `main` at `0x6F9E0`. |
| `0x14B774`–`0x14B7A0`, `0x18694A`–`0x186950` | `lib:dsound`, `lib:xboxkrnl` | One adjustor thunk into the `DSOUND` section and six `jmp [import slot]` thunks. |
| `0x14B7A0`–`0x15FA30`, `0x186950`–`0x186B80` | `engine` | Hand-written x87 and SSE vector and matrix routines, then a Direct3D rendering and resource layer with vtables and data of its own (244 calls into `D3D`, 114 into `DSOUND`). Linked after the platform libraries, so it came from a library, but 500 game functions call into it and it calls two game functions. Nothing in the executable names it. |
| `0x15FA30`–`0x17BF40` (stubs `0x18A380`–`0x18ACA2`) | `musashi` | Class-name strings at `0x1E1824` and after: "MUSASHI.MGameInput8.1", "MUSASHI.MGameSound8", "MUSASHI.MFile2", "MUSASHI.MThread" and others. Self-contained: the game calls it at three addresses and it calls back only `operator new` and `operator delete`. |
| `0x17BF40`–`0x182B81`, `0x186B80`–`0x186BA0` (stubs `0x18ACA2`–`0x18ACC0`) | `lib:crt` | The C++ frame handler, `malloc` and `free` behind `operator new` and `operator delete`, the structured exception handler with its "VC20XC00" mark, the runtime error strings (R6002 to R6028). |
| `0x182C97`–`0x18694A` | `lib:xgraphics` | Two functions that only the `XGRPH` section calls, and the ten functions only they call. |
| `0x186BA0`–`0x18A380` | `game` (stubs) | Exception-handling stubs of game functions, in the order of their parents. |
| `0x18ACC0`–`0x18CB30` | `game` | The dynamic initialisers and the destructors they register, all on game data. |

`engine` and `musashi` stay in the headline because nothing in the executable says they are someone else's
product. The vector routines at the start of `engine` are hand-written assembly, which a C++ unit cannot
reproduce.

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

`/Oy-` is allowed per file (2026-11-20). Eleven game functions open a frame pointer (`push ebp; mov ebp, esp`)
that the pinned flags do not give them, with no stack alignment: `0x14370`, `0x23F20`, `0x47160`, `0x47230`,
`0x50690`, `0xA2960`, `0xA6DC0`, `0xC3A60`, `0xD27F0`, `0xE45D0`, `0xEDC30` (the last three are constructors
with exception handling). Their neighbours have none, so it is not a whole file built differently but these
functions, and a unit is one function. A unit may ask for `/* cflags: /Oy- */` only if it matches with it and
not without. Confirmed by ten units: `0x14370`, `0x23F20`, `0x47160`, `0x47230`, `0x50690`, `0xA2960`,
`0xA6DC0`, `0xD27F0`, `0xE45D0` and `0xEDC30` each match with the flag, and without it differ by 153, 23, 24,
96, 13, 606, 135, 68, 129 and 130 bytes.
(20 other functions open a frame and align the stack, 19 with `and esp, -8` and `0x15520` with `and esp, -32`:
that comes from aligned locals under the pinned flags and needs no per-file flag.)

## Known gaps

- Link-time code generation is rare in the game's own code: 33 `game` functions read a register no standard
  calling convention passes arguments in. The per-object compile cannot reproduce those; everything else is in
  reach.
- 84 two-byte rows (75 in `engine`, 9 in hand-written game routines) were short jumps over filler to the next
  routine, the alignment padding of hand-written assembly. Since 2026-11-20 they are listed under `not_starts` and
  belong to the routine before them.
- Some rows inside `lib:xapi` and `lib:crt` are fragments of hand-written routines, and the 8-byte row at
  `0x180498` is the text "VC20XC00". They are library rows and do not affect the headline.
- `config/symbols.csv` holds only the names the compiler itself emits (see `config/README.md`).

## History

| Date | Milestone |
|---|---|
| 2026-11-19 | Project started. Executable verified, compiler pinned, function table generated, Steward and CI configured. 10 calibration units matched by hand. |
| 2026-11-19 | Steward installed and judging; the first pull request merged by itself after all five gates. Progress page live on bytematch.dev. |
| 2026-11-19 | Library code inside `.text` identified from the executable and tagged: the headline went from 8,101 functions to 7,234. Three function-table rows corrected. Runtime names the compiler emits added to `config/symbols.csv`. |
