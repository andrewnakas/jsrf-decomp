# Jet Set Radio Future (Xbox) decompilation

![Code](https://bytematch.dev/andrewnakas/jsrf-decomp.svg?label=Code&measure=matched_code_percent)
![Functions](https://bytematch.dev/andrewnakas/jsrf-decomp.svg?label=Functions&measure=matched_functions)
![Fuzzy](https://bytematch.dev/andrewnakas/jsrf-decomp.svg?label=Fuzzy&measure=fuzzy_match_percent)

A matching decompilation of **Jet Set Radio Future** (Smilebit / Sega, 2002, original Xbox, NTSC-U standalone
release, title id `5345000A`). The game's C++ is being written back function by function. Each function is
compiled with the original compiler and compared with the retail executable byte for byte.

**This project is AI-assisted.** Most functions are matched by AI agents (Claude) that the maintainer runs, under
the rules in [AGENTS.md](AGENTS.md) and [RULES.md](RULES.md). No AI takes part in merging: deterministic gates
decide. If you want to work on this game in a project without AI assistance, see [Prior work](#prior-work).

**Bring your own disc.** This repository contains no game executable, data or assets, and no compiler. You need
your own legally owned copy of the game, dumped yourself, and your own licensed copy of Visual C++ 7.0. Leaked
source, debug and prototype builds and the Xbox Development Kit are off limits: see [PROVENANCE.md](PROVENANCE.md).

## Status

| | |
|---|---|
| Target | `default.xbe`, sha256 `fd19055756719893c466302809b433b785ecf5732df0441286f3f605f0f3ef9c`, title id `5345000A`, linked 2002-01-28, Xbox SDK libraries version 1.0.4134 |
| Compiler | Microsoft Visual C++ 7.0 (`cl` 13.00.9466, from Visual Studio .NET 2002), run under [Wine](https://www.winehq.org/), with the flags pinned in `xbx.toml`. Each contributor uses their own licensed copy; the tools download nothing. |
| Function table | `config/functions.csv`: about 9,350 functions (exact counts are in [STATUS.md](STATUS.md)). Owner `game` is the headline. The Xbox SDK libraries linked into the executable (`lib:d3d8`, `lib:dsound`, `lib:xgraphics`, `lib:xpp`) are a separate category. |
| Progress (2026-11-19) | Clean start: the toolchain is pinned and the first 10 functions are matched (the set the compiler flags were calibrated on). |

Progress is tracked on [bytematch.dev](https://bytematch.dev/andrewnakas/jsrf-decomp). The headline counts exact
matches of owner `game` only.

## Two tiers of C++

| Tier | Folder | Meaning | Counts as matched? |
|---|---|---|---|
| Matched | `src/funcs/` | Compiles with the pinned compiler to the retail bytes at its address, and everything it refers to is verified against the retail executable. | Yes |
| Non-matching | `src/nonmatching/` | Equivalent C++ that does not match yet, with a verified `/* fuzzy: NN.N */` similarity score. | No, fuzzy progress only |

**Joining (human or AI agent)? Read [START_HERE.md](START_HERE.md).**

## Quick start (Linux)

You need Wine, [uv](https://docs.astral.sh/uv/), git, your own `default.xbe` and your own Visual C++ 7.0
directory (`bin/`, `include/`, `lib/`).

```sh
git clone https://github.com/andrewnakas/jsrf-decomp && cd jsrf-decomp
mkdir -p orig toolchain
cp /path/to/your/default.xbe orig/               # your own dump, git-ignored (or set XBX_XBE)
ln -s /path/to/your/vc70 toolchain/msvc          # your own Visual C++ 7.0, git-ignored (or set XBX_MSVC)
uv venv && uv pip install -r requirements.txt    # the pinned xbx tools, into .venv
.venv/bin/xbx gate toolcheck                     # the compiler and the executable are the pinned ones
.venv/bin/xbx asm --small 20                     # the 20 smallest game functions nobody has done
```

Then write a unit, `src/funcs/func_XXXXXXXX.cpp` (the function's retail address, 8 uppercase hex digits), and
compare it:

```sh
.venv/bin/xbx match src/funcs/func_XXXXXXXX.cpp
```

`xbx xiso your-disc.iso` lists the files of your own disc image, and `xbx xiso your-disc.iso orig default.xbe`
extracts the executable (give the path exactly as the listing prints it).

## Working on a function

```sh
.venv/bin/xbx asm 0x0012A340                                # the function's retail disassembly
.venv/bin/xbx match src/funcs/func_0012A340.cpp             # compile and compare; "!" lines say what differs
.venv/bin/xbx match --strict src/funcs/func_0012A340.cpp    # the same, by the gate's rules
tools/gate.sh scan && tools/gate.sh match                   # what the judge runs
```

`xbx help` lists every command, including the workbench (`score`, `diff`, `triage`, `try`, `history`,
`exemplars`, `idiom`, `search`) for near misses.

Then open a pull request using the template. Claim first: comment `/claim 0x0012A340` on the pinned
**Active claims** issue. See [AGENTS.md](AGENTS.md), [RULES.md](RULES.md), [PROVENANCE.md](PROVENANCE.md) and
[docs/MATCHING_GUIDE.md](docs/MATCHING_GUIDE.md).

## How merges work

[Decompathon Steward](https://github.com/andrewnakas/decompathon-steward) runs on the maintainer's machine,
which has the disc and the compiler. **No AI is involved in merging.** For every PR, Steward checks out `main`,
copies in only the PR's unit files (`src/funcs/`, `src/nonmatching/`), and runs five deterministic gates,
cheapest first:

| Gate | Checks |
|---|---|
| toolcheck | the judge is the machine it claims to be: the executable has the pinned sha256, every compiler file has its recorded checksum, `cl` reports 13.00.9466, a fixed canary source compiles to the recorded object, and the installed tools are the commit `requirements.txt` pins |
| scan | unit files are plain C++ with none of the banned constructs: inline assembly, `__emit`, naked functions, `#pragma` other than `pack`, most `__declspec`, statements that only steer the compiler (the full list is in [AGENTS.md](AGENTS.md)). Text only: it needs no game file |
| split | the committed function table is exactly what the tools derive from the executable, and it accounts for every byte of the game's code: rows in order, nothing but padding between them, every direct call landing on a row |
| match | every unit in `src/funcs/` compiles with the pinned compiler and is a proven match: byte for byte at its address, every relocation resolved against the retail bytes, everything else in its object verified in place. The units must also agree with each other: one name means one address, and one address is declared one way. Units in `src/nonmatching/` must compile, must not match, and must carry the score the tools compute |
| build | a second proof, made the other way round, as a linker works: every block of every matched unit's object is given its address, every relocation is applied, and the bytes that come out must equal the retail executable over every range the units cover |

Each gate is `tools/gate.sh <name>`, which runs `xbx gate <name>` with the tools commit pinned in
`requirements.txt`. A gate prints `PROBLEM <file>: <why>` for everything it refuses, and its exit status says
whether it passed. Because the judge copies in only unit files, a PR cannot change the tools, the function
table or the headers that judge it.

Public CI (GitHub Actions) runs what needs no game data and no compiler: the Steward config check, a
no-game-data check, and the progress report that ByteMatch reads.

## What a match proves

Nothing is masked.

- The function is compared byte for byte at its retail address.
- Every relocation is resolved against the retail bytes, so a wrong call target, global, constant, string,
  table entry or vtable slot is a difference.
- Everything else the object would put in the image (string and float constants, exception-handling funclets
  and tables, vtables, switch tables) is placed at the address the retail code implies and compared there.
- Anything in the object that cannot be verified fails the unit. A unit may not define global data, dynamic
  initialisers or out-of-line copies of inline functions.

## Layout

```
xbx.toml          project description for the xbx tools: the pinned executable, compiler, flags and owners
config/           functions.csv (the function table), symbols.csv (library and runtime names)
src/funcs/        one matched function per file: func_XXXXXXXX.cpp
src/nonmatching/  equivalent C++ that does not match yet (/* fuzzy: */ score)
include/          shared headers (maintainer-only)
tools/            gate.sh (runs a gate with the pinned tools), linux/ (the Steward service unit)
tests/            the fixtures of the toolcheck gate (a canary source and its recorded object checksum)
docs/             matching guide, lessons
requirements.txt  the pinned commit of the xbx tools
steward.toml      Steward's gates and merge policy
orig/             your own default.xbe (git-ignored)
toolchain/        checksums.sha256 (the pinned compiler's files, by checksum); msvc/ and wineprefix/ are
                  your own compiler and Wine prefix (git-ignored)
```

## Prior work

[JSRF-Decompilation](https://codeberg.org/KeybadeBlox/JSRF-Decompilation) by KeybadeBlox, on Codeberg, was the
first matching decompilation of this game. If you want to contribute to a project without AI assistance, that
is the place: it does not accept LLM-assisted work.

This repository is an independent clean start. It copies nothing from that project (no names, types or code;
contributors here do not open it, see [PROVENANCE.md](PROVENANCE.md)) and sends nothing to it.

## Credits

- The `xbx` tools are [decompathon-xbox](https://github.com/andrewnakas/decompathon-xbox) (GPL-3.0-or-later),
  a separate repository that is installed here, not copied. Its XBE tools derive from the
  [halo2-decompiled](https://github.com/kirklandsig/halo2-decompiled) project.
- Merging is done by [Decompathon Steward](https://github.com/andrewnakas/decompathon-steward); progress is
  shown by [ByteMatch](https://bytematch.dev).
- Disassembly uses [Capstone](https://www.capstone-engine.org/); the compiler runs under
  [Wine](https://www.winehq.org/).
- The project structure follows the [THUG PS2 decomp](https://github.com/andrewnakas/thug-decomp), the
  [THPS N64 decomp](https://github.com/andrewnakas/thps64) and the
  [Thrasher PS1 decomp](https://github.com/andrewnakas/thrasher-skate-decomp).

## Legal

The code in this repository is released under CC0 (see [LICENSE](LICENSE)). Jet Set Radio Future is © its
respective owners. This project is not affiliated with or endorsed by Sega, Smilebit or Microsoft. The
repository contains no game data, no Xbox SDK files and no compiler.
