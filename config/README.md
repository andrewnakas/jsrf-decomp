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
