# Lessons carried over (thps64, Thrasher, THUG)

The earlier Decompathon projects paid for these. Each row says where the lesson came from and what this
project does about it from day one. Lessons found here are added below as they happen.

| Lesson | From | Here |
|---|---|---|
| Pin the compiler before matching anything | thps64, THUG: no match ever had to be redone because of a compiler change | `xbx.toml` pins `cl` 13.00.9466 and its flags before the first unit; the `toolcheck` gate refuses any other compiler or executable |
| Never mask relocations | thps64, THUG | `xbx match` resolves every relocation against the retail bytes and verifies everything else the object carries (strings, floats, tables, vtables, exception-handling code) at the address retail implies; what it cannot verify fails the unit |
| The judge is the early bottleneck | THUG: Steward merged one PR per 4–8 minutes while matching ran faster, and newest-first ordering starved old PRs until the queue stalled | Steward judges the oldest PR first; PRs carry up to 20 units; the cheap gates run first |
| Plan the non-matching tier from the start | THUG: the tier was added after the start, by an owner ruling; it gave complete C++ coverage by day 4 and made fuzzy progress measurable | `src/nonmatching/` exists from the first day, with a score the gate verifies; it is where functions with a custom calling convention go for now |
| Gate memory on the shared machine | THUG, 2026-11-12: parallel builds across sessions used up the RAM and took down the desktop and every session | on the maintainer's machine every compiling command runs under `memgate` (AGENTS.md) |
| Never pipe a gate through `tail` | THUG: a pipe hid a failing exit status once | read the gate's exit status; `tools/gate.sh` ends in `exec`, so the status is the gate's own |
| Retry compiles under the emulation layer | THUG: wibo, the layer that ran the Windows compiler, hung under load; compiles timed out and a gate crashed on the timeout | `xbx` gives every compiler run under Wine a timeout, kills the whole process tree and retries (`XBX_TOOL_TIMEOUT`, `XBX_TOOL_ATTEMPTS`); each compile has its own temporary directory |
| Fresh agents with short briefs | THUG: agents past about 350k of context hit errors and lost work | start a new agent with a short brief that points at START_HERE.md, AGENTS.md and the matching guide; keep notes under `work/`, not in the conversation |
| Name things as you go | THUG: every function and nearly every type ended with an address for a name, each unit re-declared its own partial structs, and nothing forced the meaning to be recovered | function and global names must carry their address here, but class, member, parameter and local names are free, a comment says what a function does, and one decorated name per address makes every unit agree on each function's class and signature |

## Found here

Nothing yet.
