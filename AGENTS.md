# AGENTS.md: how to contribute (AI agents and humans alike)

This is the single source of truth for working in this repo. New here? Start with [START_HERE.md](START_HERE.md).
Read [RULES.md](RULES.md) and [PROVENANCE.md](PROVENANCE.md) once, and [docs/MATCHING_GUIDE.md](docs/MATCHING_GUIDE.md)
before your first function.

## What you are doing

You turn one function of `default.xbe` (Jet Set Radio Future, original Xbox, NTSC-U standalone release) from
machine code back into C++ that compiles to **exactly** the same bytes under the pinned compiler (Microsoft
Visual C++ 7.0, `cl` 13.00.9466, with the flags pinned in `xbx.toml`). One function per file:
`src/funcs/func_XXXXXXXX.cpp` (8 uppercase hex digits: the function's retail address). Nothing else is a
contribution: the gates judge only unit files in `src/funcs/` and `src/nonmatching/`.

**Never look at leaked source or symbols, debug builds, prototypes, linker maps, the Xbox Development Kit, or
the KeybadeBlox JSRF-Decompilation repository**, not even to check a name. See PROVENANCE.md.

## Lanes (so agents do not collide)

| Agent | Address range | Branch prefix |
|---|---|---|
| Claude lane 1 | `0x00011000`–`0x0008FFFF` | `claude-lane1/` |
| Claude lane 2 | `0x00090000`–`0x0010FFFF` | `claude-lane2/` |
| Claude lane 3 | `0x00110000`–`0x0013A56F` | `claude-lane3/` |
| Any other agent or human | an unclaimed range from the Active claims issue | `<name>/` |

A function belongs to the lane its start address falls in. Lanes work on owner `game`, kind `func`. A lane in
this table owns its range and does not `/claim` inside it; everyone else claims first.

`.venv/bin/xbx asm --list 40 --from 00011000 --to 00090000 --min-size 16` lists a range's smallest open
functions, one line each (`--leaf` for those that call nothing); `--small` prints their disassembly.

Not everything in the executable is the game's own code, and the function table's `owner` column says which
is which:

| Owner | Where | What it is |
|---|---|---|
| `game` | `.text` up to `0x13A570`, the dynamic initialisers at its end, section `MMATRIX` | the game. **Lane targets.** |
| `engine`, `musashi` | `.text` `0x14B7A0`–`0x17BF40` | engine code linked in as libraries: a Direct3D layer with hand-written vector maths, and classes the executable names `MUSASHI.*`. Counted in the headline, not lane targets yet. |
| `lib:*` | sections `D3D`, `DSOUND`, `XGRPH`, `XPP`; `.text` `0x13A570`–`0x14B7A0` and `0x17BF40`–`0x186BA0` | CRI ADX, the Xbox platform libraries and the C/C++ runtime. A separate category in the progress report. Not lane targets. |

`xbx asm --list` and `--small` show owner `game` only. STATUS.md has the evidence for each range.

A unit often calls library code. Declare the callee under its address name like any other function
(`int __stdcall func_00145585(void *handle);`). The exception is what the compiler calls by itself (`operator
new`, `__ftol2` for a float-to-integer conversion, the 64-bit arithmetic helpers, `__purecall` in a vtable):
those names are in `config/symbols.csv` and need no declaration.

Use **one clone per agent**, and keep every temporary file inside your own clone, under `work/` (git-ignored):
never in a shared temp or scratchpad directory, where another agent can pick it up.

## Setup (once per workspace)

```sh
git clone https://github.com/andrewnakas/jsrf-decomp && cd jsrf-decomp
mkdir -p orig toolchain work
cp /path/to/your/default.xbe orig/               # your own dump, git-ignored (or set XBX_XBE)
ln -s /path/to/your/vc70 toolchain/msvc          # your own Visual C++ 7.0, git-ignored (or set XBX_MSVC)
uv venv && uv pip install -r requirements.txt
.venv/bin/xbx cc --setup                         # the Wine prefix (or set XBX_WINEPREFIX to an existing one)
.venv/bin/xbx gate toolcheck                     # must end with: gate toolcheck: OK
```

## The loop, per function

1. **Pick and claim.** `.venv/bin/xbx asm --small 20` prints the 20 smallest game functions with no unit yet.
   Choose one in your lane and comment on the pinned **Active claims** issue: `/claim 0x0012A340` (up to 3 open
   claims, 0x2000 bytes each; claims lapse after 7 days). Someone else's claim wins.
2. **Read.** `.venv/bin/xbx asm 0x0012A340` prints the retail disassembly with every address labelled. Check the
   header line: owner `game`, kind `func`, and no `reads ... at entry` (see "Link-time code generation" below).
3. **Write** `src/funcs/func_0012A340.cpp`: the types and prototypes it needs, then the one function. See
   "The unit file" below.
4. **Iterate.** `.venv/bin/xbx match src/funcs/func_0012A340.cpp` until it prints `MATCH`. `!` lines are
   problems, `.` lines are notes, `?` lines are names that still need an address. The workbench (`xbx diff` and
   the others) helps with near misses; see the matching guide.
5. **Check locally, exactly as the judge will:**
   ```sh
   tools/gate.sh scan && tools/gate.sh match
   ```
   A gate prints `PROBLEM <file>: <why>` for everything it refuses and ends with `gate <name>: OK` or
   `gate <name>: FAILED`. Never pipe a gate through `tail`, `head` or `grep`: the pipe hides a failing exit
   status. Read the status.
6. **Give up cleanly.** After about 15 compiles on a small function, or 25 on a large one, stop. If the C++ is
   equivalent, move it to `src/nonmatching/` (see below). Otherwise keep your near miss under `work/` with a
   note on the remaining difference, `/unclaim`, and move on.
7. **Open a PR** from a branch with your lane prefix, at most 20 units. **The PR body must be the template**:
   ```sh
   cp .github/pull_request_template.md work/pr.md   # fill in the table, tick the boxes, name the agent
   gh pr create --base main --title "Match N functions from ..." --body-file work/pr.md
   ```
   `gh pr create --body "..."` skips the template and Steward reads the exact box text (`Own work:`,
   `No leaked material:`, `No game data:`, `Lawful decompilation:`, `Sources listed:`, one "who made this" box,
   and `Agent acknowledgement:` for agents). Use `gh api -X PATCH repos/.../pulls/N` to edit a PR body
   (`gh pr edit` breaks).

## The unit file

Steward's judge copies **only the PR's unit files** into its workspace. So a unit is self-contained: it declares
the types and prototypes it needs itself, and it may include only headers that are already on `main` under
`include/`.

- **The unit's function is named `func_XXXXXXXX`**, as a free function or as a member of whatever class it
  belongs to.
- **Every other function or global it refers to** is declared (a prototype, an `extern`, a member declaration)
  and named `func_XXXXXXXX` or `data_XXXXXXXX` after **its own** retail address. The tools read the address out
  of the compiler's decorated name, so nothing is declared separately and nothing can be misdeclared.
- **Library and runtime names** (C runtime, Xbox SDK, kernel import slots) come from `config/symbols.csv`
  (`name,addr`), which only maintainers change. If a name you need is missing, open a `tooling` issue.
- **One address, one decorated name.** The decorated name encodes the class, the calling convention and the
  parameter types, so across all units an address may be referenced under only one. This is the type contract
  between units: `xbx` reports the name other units already use, and you declare the function the same way.

Directives a unit may carry, each on a line of its own:

| Directive | Use |
|---|---|
| `/* cflags: ... */` | First line of the file only. Extra compiler flags, only from `allowed_cflags` in `xbx.toml`. |
| `/* sym: DECORATED_NAME = 0xADDR */` | Only for C++ special members that cannot carry an address in their name: constructors, destructors, operators, vtables (decorated names that start with `??`). |
| `/* const: 0xV */` | A number that happens to fall inside the image's address range (`0x10000` to `0x288620`) but is a number, not an address. |
| `/* fuzzy: NN.N */` | Non-matching tier only. Written by the tool (`xbx match --write-fuzzy`), never by hand. |

## Hard rules (the scan and match gates enforce most of them)

- **Plain C++ only.** Banned in units: `__asm` / `_asm`, `__emit`, `__declspec(naked)`, every `#pragma` except
  `pack`, every `__declspec` except `noreturn`, `novtable` and `align`, `__FILE__` / `__DATE__` / `__TIME__` /
  `__TIMESTAMP__`, non-ASCII bytes, includes outside `include/`, and numbers written where an address is meant
  (the match gate checks that one on the machine code). The scan gate also refuses the ways to spell a banned
  word without writing it: `#line`, `#import`, `#using`, token pasting (`##`), trigraphs and digraphs. Why: we
  publish our own C++, never transcriptions of the game's compiled code or its bytes.
- **Legal, because real code needs them:** the calling-convention keywords (`__cdecl`, `__stdcall`,
  `__fastcall`), `__forceinline` / `inline` helpers defined in the unit that the compiler really inlines,
  classes with virtual functions, string literals and float literals.
- **One function per file, no data of its own.** A unit may not define global data, dynamic initialisers or
  out-of-line copies of inline functions. Globals are `extern` and named `data_XXXXXXXX`. What the compiler
  itself adds to the object (string and float constants, vtables, switch tables, exception-handling funclets and
  tables) is fine, because the matcher places each at its retail address and compares it there.
- **No steering code.** A statement that exists only to push the compiler toward the retail bytes is banned:
  bare expression statements, self-assignments, empty branches, `do { } while (0)` wrappers, alias temporaries,
  untruthful callee declarations. The scan gate catches the first, second and fourth; all of them are rules.
  The rulings are in [docs/MATCHING_GUIDE.md](docs/MATCHING_GUIDE.md#rulings).
- **Never edit protected paths:** `tools/`, `config/`, `toolchain/`, `include/`, `tests/`, `xbx.toml`,
  `requirements.txt`, `steward.toml`, `.github/`, or the docs. If the function table, a symbol or a tool is
  wrong, open a `tooling` issue with a minimal repro (the `.cpp` plus the `xbx match` output).
- **Names need a reason** from the binary itself (a string, unmistakable behaviour) or, for Win32 and
  Direct3D 8 API names, from Microsoft's public documentation. Never from leaked material, the Xbox
  Development Kit or the KeybadeBlox repository. Functions and globals keep their address names; classes,
  members, parameters and locals are where real names go, and a comment above the function says what it does
  when you know.

## What the match gate proves

Nothing is masked.

- The function is compared byte for byte at its address.
- Every relocation is resolved against the retail bytes, so a wrong call target, global, constant, string,
  table entry or vtable slot is a difference.
- Everything else the object would put in the image is placed at the address the retail code implies and
  compared there.
- Anything in the object that cannot be verified fails the unit.

## Useful facts

- 32-bit x86. `xbx asm` prints Intel syntax and labels every address it can.
- The image spans `0x10000`–`0x288620`. Code sections: `.text` (from `0x11000`), `D3D`, `DSOUND`, `MMATRIX`,
  `XGRPH`, `XPP`. Read-only data (`.rdata`) starts at `0x1C3F60` with the kernel import table (120 slots);
  `.data` starts at `0x1EB760`.
- Member functions take `this` in `ecx`. Integers and pointers return in `eax`, 64-bit integers in `edx:eax`,
  floating point in `st(0)`. `ebx`, `esi`, `edi` and `ebp` survive a call.
- Kind `eh` rows are compiler-made exception-handling stubs. They get no unit of their own: they are matched
  together with the function that registers them (the `parent` column of the table names it).
- Addresses outside the image (hardware registers, for example) are ordinary numbers and need no directive.

## Link-time code generation (`conv`)

The `conv` column of `config/functions.csv` lists the registers (`eax ebx esi edi`) a function reads at entry.
Microsoft's standard calling conventions never pass arguments there. A non-empty `conv` means the retail linker
gave the function a custom calling convention, which a per-object compile cannot reproduce.

For now:

- Skip a function whose `conv` is not empty. `xbx asm` prints `reads eax at entry` (or the registers it reads)
  in the header line.
- Skip its callers where the call site is affected: the caller loads the register for the callee where a
  standard convention would push an argument.
- Or write equivalent C++ and put it in the non-matching tier.

Never chase the convention with inline assembly, `__declspec(naked)` or steering code.

## Equivalent but not matching yet (`src/nonmatching/`)

When a function is readable and equivalent but still differs from the retail code, keep it as
`src/nonmatching/func_XXXXXXXX.cpp` instead of leaving it in `work/`. The same rules apply as in `src/funcs/`:
the scan gate, the naming, one function, no data of its own, no steering code. It carries a
`/* fuzzy: NN.N */` line with its similarity score (0 to 100: the share of instructions that line up with the
retail code). The tool writes the line, never you:

```sh
.venv/bin/xbx match --write-fuzzy src/nonmatching/func_0012A340.cpp
```

The match gate computes the score again on the judge and rejects a line that differs, a unit that does not
compile, and a unit that already matches (move it to `src/funcs/` and drop the line). A function has a unit
in one tier only. Non-matching units count only toward ByteMatch's **fuzzy** progress and are never treated
as matched.

## On the maintainer's machine

Several agents share one machine there. Every `xbx` command that runs the compiler goes through `memgate`:

```sh
memgate --slots 6 --need 1 --max 2 --name jsrf -- .venv/bin/xbx match src/funcs/func_0012A340.cpp
```

- The same wrapper goes in front of `tools/gate.sh` and the workbench commands. The gates compile a few units
  at a time (`XBX_JOBS`, default 4); do not raise it.
- If `memgate` says the slots are busy, read disassembly or edit and retry. Never bypass it.
- Run `memstat` before anything large and when a job is slow.
- The compiler runs under Wine, and Wine sometimes hangs under load. The tools give every compiler run a
  timeout and retry it (`XBX_TOOL_TIMEOUT`, `XBX_TOOL_ATTEMPTS`), so wait for the result. Never run
  `wineserver -k` or kill Wine processes you did not start: lanes may share a Wine prefix.
