# Rules (Jet Set Radio Future Xbox decomp)

1. One function per file: `src/funcs/func_XXXXXXXX.cpp` (8 uppercase hex digits, the function's retail
   address), defining exactly that one function in C++ (a free function, member function, constructor,
   destructor or operator). The file is self-contained: it declares the types and prototypes it needs and
   includes only headers already on `main` under `include/`.
2. It must compile with the pinned compiler (Microsoft Visual C++ 7.0, `cl` 13.00.9466, the flags pinned in
   `xbx.toml`) to the retail bytes at its address: the `match` gate. Nothing is masked. Every relocation is
   resolved against the retail bytes, and everything else the object would put in the image is compared at the
   address the retail code implies. Anything in the object that cannot be verified fails the unit. A file may
   ask for extra flags in a first-line `/* cflags: ... */` comment, but only from `allowed_cflags` in `xbx.toml`.
3. Zero loss: nothing that already matches may break. The `match` gate proves every unit again and checks that
   the units agree with each other; the `build` gate links the matched units and requires the retail bytes.
   Gates run on the judge box with the maintainer's disc and compiler, never on GitHub.
4. Plain C++ only (`scan` gate). No `__asm` / `_asm`, `__emit`, `__declspec(naked)`, `#pragma` other than
   `pack`, `__declspec` other than `noreturn` / `novtable` / `align`, `__FILE__` / `__DATE__` / `__TIME__`,
   non-ASCII bytes, includes outside `include/`, or numbers written where an address is meant (the full list
   is in AGENTS.md).
   No data of the unit's own: no global data, no dynamic initialisers, no out-of-line copies of inline
   functions. String and float literals, classes with virtual functions, the calling-convention keywords and
   inline helpers that the compiler really inlines are fine.
5. Names carry addresses. The unit's function is named `func_XXXXXXXX`; every other function or global it
   refers to is named `func_XXXXXXXX` or `data_XXXXXXXX` after its own retail address. `/* sym: */` lines are
   only for C++ special members whose decorated names start with `??`. Library and runtime names come only from
   `config/symbols.csv`. Across all units, one address is referenced under one decorated name.
6. No steering or fake-match code. A statement is allowed only if it is real code: every instruction it
   produces exists in the retail function (the instruction test). Bare expression statements, self-assignments,
   empty branches, `do { } while (0)` wrappers, alias temporaries and untruthful callee declarations are banned
   whether or not a gate catches them; a merged unit found to carry one is removed. The rulings are in
   [docs/MATCHING_GUIDE.md](docs/MATCHING_GUIDE.md#rulings).
7. Provenance (PROVENANCE.md): every PR ticks every box. **Never use leaked source or symbols, debug builds,
   prototypes, linker maps, the Xbox Development Kit or the KeybadeBlox repository.**
8. Claim before you work (`/claim 0xADDR` on the Active claims issue). Someone else's claim wins. Claims lapse
   after 7 days without activity (reminder after 5). Touching someone's merged function: Steward asks them;
   7 days of silence means go ahead, credit kept.
9. Up to 20 units per PR. `tools/`, `config/`, `toolchain/`, `include/`, `tests/`, `xbx.toml`,
   `requirements.txt`, `steward.toml`, `.github/` and these docs are maintainer-only.
10. Tick who made the PR. AI agents may contribute, but must tick every box themselves on every PR, after
    checking each against the PR's actual changes, plus the agent acknowledgement.
11. Merges are decided by deterministic gates and rules only. No AI takes part in reviewing or merging.
    Appeals: open an issue labelled `appeal`.
12. **Non-matching tier.** Equivalent C++ that does not match yet may live in
    `src/nonmatching/func_XXXXXXXX.cpp` with a `/* fuzzy: NN.N */` score that the tool writes
    (`xbx match --write-fuzzy`) and the `match` gate verifies. A unit that matches belongs in `src/funcs/`.
    Every other rule applies unchanged. Non-matching units count toward fuzzy progress only and are never
    treated as matched.
13. **Link-time code generation.** A function whose `conv` column in `config/functions.csv` is not empty has a
    custom calling convention that a per-object compile cannot reproduce. Such functions, and callers whose
    call site is affected, are skipped for now or go to the non-matching tier as equivalent C++.
14. Progress: the headline counts exact matches of the owners `game`, `engine` and `musashi` (STATUS.md). Library code (`lib:*` owners) is reported
    as a separate category.
