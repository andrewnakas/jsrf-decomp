# Start here: joining the JSRF decomp (agents and humans)

One page to go from a fresh machine to your first merged function. The details live in [AGENTS.md](AGENTS.md);
read it before your first PR.

## What you need

1. **Linux x86_64** (or WSL2) with Wine, Python 3.11+, [uv](https://docs.astral.sh/uv/), git, and `gh` logged in.
2. **Your own dump of the game**: Jet Set Radio Future (USA), original Xbox, the standalone release. You need its
   `default.xbe`. The repo contains no game data and nobody will send you any. The tools verify the file by
   sha256 and refuse any other executable.
3. **Your own licensed copy of Visual C++ 7.0** (Visual Studio .NET 2002): a directory holding its `bin/`,
   `include/` and `lib/`. Its `cl` must report version 13.00.9466, and `xbx gate toolcheck` compares its files
   with the checksums recorded in `toolchain/checksums.sha256`. The tools download no compiler.
4. **Your own GitHub account.** Claims belong to accounts.

## Setup (about 10 minutes)

```sh
git clone https://github.com/andrewnakas/jsrf-decomp && cd jsrf-decomp
mkdir -p orig toolchain
cp /path/to/your/default.xbe orig/               # git-ignored, never committed
ln -s /path/to/your/vc70 toolchain/msvc          # bin/ include/ lib/ from your own Visual Studio, git-ignored
uv venv && uv pip install -r requirements.txt    # the pinned xbx tools, into .venv
.venv/bin/xbx cc --setup                         # creates the Wine prefix (toolchain/wineprefix)
.venv/bin/xbx gate toolcheck                     # must end with: gate toolcheck: OK
```

Paths outside the clone work too: set `XBX_XBE` (default `orig/default.xbe`), `XBX_MSVC` (default
`toolchain/msvc`) and `XBX_WINEPREFIX` (default `toolchain/wineprefix`). They are read from the environment
and never written to a committed file.

If any step fails, open an issue with the "Build or setup problem" template. Never attach game files or
compiler files.

## Your first function

1. Look at the pinned **Active claims** issue and pick an address range nobody holds.
   `.venv/bin/xbx asm --small 20` prints the 20 smallest game functions with no unit yet. Skip any whose header
   line says `reads ... at entry` (see "Link-time code generation" in AGENTS.md). Claim with `/claim 0x0012A340`.
2. Follow the loop in [AGENTS.md](AGENTS.md#the-loop-per-function): `xbx asm` → write
   `src/funcs/func_0012A340.cpp` → `xbx match` until it prints `MATCH` → `tools/gate.sh scan` and
   `tools/gate.sh match` pass.
3. Open a PR from a branch, with the template as the body (`--body-file`), at most 20 functions.

**Your first PR waits for the maintainer** (the `judge-ok` label). After one merged PR, Steward judges and merges
automatically.

## Paste this to your agent

> You are contributing to a matching decompilation of Jet Set Radio Future (Xbox) at
> https://github.com/andrewnakas/jsrf-decomp. Read START_HERE.md, then AGENTS.md, then docs/MATCHING_GUIDE.md,
> and follow them exactly. Never open or search leaked source code, debug or prototype builds, the Xbox
> Development Kit, or the KeybadeBlox JSRF-Decompilation repository. Set up the repo as START_HERE.md says (my
> `default.xbe` is at `<PATH TO default.xbe>`, my Visual C++ 7.0 directory is at `<PATH TO bin/include/lib>`) and
> confirm `xbx gate toolcheck` passes. Then work continuously: claim an unclaimed address range on the Active
> claims issue, match functions one at a time with `xbx asm` and `xbx match`, check each with `tools/gate.sh scan`
> and `tools/gate.sh match`, and open PRs of up to 20 matched functions using the PR template. Plain C++ only: no
> inline asm, no `#pragma` except `pack`, no hard-coded addresses, every other function and global named
> `func_XXXXXXXX` or `data_XXXXXXXX` after its own address, no edits outside `src/funcs/` and `src/nonmatching/`.
> Skip functions whose `conv` column is not empty. If a function doesn't match after about 15 compiles (25 for a
> large one), stop, note why in `work/`, and move on.
