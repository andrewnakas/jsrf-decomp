# config

| File | What it is |
|---|---|
| `functions.csv` | The function table, generated from the executable by `xbx inventory` and checked by the split gate. Addresses and sizes only. Never edited by hand: a wrong row is fixed in `xbx.toml` (`[inventory]`) or in the tools. |
| `symbols.csv` | Names that cannot carry their own address: the C++ runtime's and the platform's. Everything else is called `func_XXXXXXXX` or `data_XXXXXXXX`. |

## symbols.csv: the evidence for each name

A name is added only with evidence from the executable itself or from public documentation (PROVENANCE.md).

| Name | Address | Evidence |
|---|---|---|
| `??3@YAXPAX@Z` (`operator delete(void *)`) | `0004a900` | The compiler's scalar deleting destructors call it: destructor, `test byte [flags], 1`, then this function with `this` (for example the function at `000ecd90`). |
| `??2@YAPAXI@Z` (`operator new(unsigned int)`) | `0004a8f0` | The neighbour of `operator delete`, the same five-byte shape (a jump into the C runtime's allocator), called with a size before constructors run. |
| `___CxxFrameHandler` | `0017c00f` | The target of all 462 frame-handler stubs (`mov eax, offset FuncInfo; jmp`), each of whose `FuncInfo` starts with the compiler's magic number `0x19930520`. |
| `??_U@YAPAXI@Z` (`operator new[]`) | `0017d71b` | Its whole body is a jump to `operator new`. |
| `??_V@YAXPAX@Z` (`operator delete[]`) | `0017d716` | Its whole body is a jump to `operator delete`. |
| `__CxxThrowException@8` | `0017d5f9` | Copies the eight-word exception record template at `001e4264` (code `0xE06D7363`), fills in the object and its throw information, and raises it. 30 callers. |
| `__EH_prolog` | `00186b80` | `push -1; push eax; mov eax, fs:[0]; push eax; ...; mov fs:[0], esp`: the shared prologue that sets up an exception frame. |
| `__purecall` | `0017cac0` | Reports runtime error `0x19` (a pure virtual call) and never returns to useful code. It fills the unused slots of vtables, for example the one at `001cdda4`. |
| `__ftol2` | `0017c3e8` | `fistp qword`, `fild qword`, then a correction by the sign of the remainder: float to integer with truncation, without touching the control word. 153 callers. |
| `__allmul` | `0017ca70` | 64-bit multiply of two stack arguments, `ret 0x10`. |
| `__alldiv`, `__aulldiv`, `__aullrem` | `0017c9c0`, `0017d4d0`, `0017d2c0` | 64-bit signed divide (with the sign fix-up), unsigned divide and unsigned remainder of two stack arguments. |
| `__aullshr`, `__allshr` | `0017d2a0`, `0017d540` | 64-bit shift right of `edx:eax` by `cl`: logical (`shr`) and arithmetic (`sar`). |
| `__chkstk` | `0017cab0` | Lowers `esp` by `eax` and returns to its caller on the new stack. |
| `_atexit` | `0017c53d` | Registers one function pointer and returns 0 or -1. All 27 of its callers are the dynamic initialisers at the end of `.text`. |

These are the names the compiler itself puts into an object. A unit cannot spell them any other way, so they
are the names that must be here. Functions that a unit calls by a declaration of its own (the C library, the
platform API) keep their address names.

A wrong row cannot make a false match: the match gate resolves every reference against the retail bytes, so a
name that points at the wrong address makes the unit fail.
