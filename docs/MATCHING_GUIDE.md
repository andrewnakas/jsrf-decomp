# Matching guide (Microsoft Visual C++ 7.0 / x86 / Xbox)

How to turn one function's retail code back into C++ that the pinned compiler compiles to the same bytes.

This guide starts short on purpose. It holds the workflow, what the tools tell you, the conventions of a unit
file and the rulings. Compiler idioms go in the "Findings" section at the end, by maintainer PR, and only when a
merged unit proves one. Nothing here is carried over from other compilers.

The addresses and names in the examples are made up.

## The workflow

```sh
.venv/bin/xbx asm --small 20                                # the 20 smallest game functions with no unit yet
.venv/bin/xbx asm 0x0012A340                                # one function's retail disassembly
$EDITOR src/funcs/func_0012A340.cpp                         # write the unit
.venv/bin/xbx match src/funcs/func_0012A340.cpp             # compile and compare; explains what differs
.venv/bin/xbx match --strict src/funcs/func_0012A340.cpp    # the same, by the gate's rules
tools/gate.sh scan && tools/gate.sh match                   # what the judge runs
```

1. Read the disassembly until you can say what the function does, what it takes and what it returns.
2. Write the unit: the types and prototypes it needs, then the one function.
3. Run `xbx match`. Without `--strict` it explains instead of failing early: it tells you the addresses of
   names you have not mapped yet and marks things the gate would refuse.
4. When it says `DIFF`, read the `!` lines, then use `xbx diff` to see the retail code next to yours.
5. When it says `MATCH`, run it once more with `--strict`, then run the gates.

`xbx match` also takes several units, `--all` for every unit of a tier, `--tier nonmatching`, `-q` for one
line per unit and `--no-cache` to compile again when the object is cached. `xbx cc <source> <object> [flags...]`
compiles one file with the pinned compiler, for experiments under `work/`.

### The workbench

For near misses. `xbx help` lists every command.

| Command | What it does |
|---|---|
| `xbx diff ADDR [file]` | diagnoses a unit and shows the retail code next to ours, with the differing lines marked |
| `xbx score ADDR [files...]` | scores source variants of a function (default: the unit in the tree) |
| `xbx try ADDR variants.txt [--start base.cpp]` | scores a file of variants (separated by lines of `=====`) and records them |
| `xbx history ADDR` | shows a function's recorded variants, best first |
| `xbx triage [ADDR...]` | classifies the open functions by what kind of difference is left |
| `xbx exemplars ADDR` | finds matched functions that look like this one |
| `xbx idiom ADDR [file]` | shows where matched code uses an instruction that so far only the retail code has |
| `xbx search ADDR [--time-limit S] [--beam N]` | runs a beam search over source mutators |
| `xbx names [ADDR...]` | prints the declaration the tree already uses for an address |

A variant is a whole unit file; keep variants under `work/`. Every scored variant gets a line of numbers:

```
0003BEC0 work/func_0003BEC0.cpp size 58  lock    7  dist    4  sem   2  frame +0  first +0x12
  classes: semantic regs   frame retail 0x0 ours 0x0
  retail only: inc R x1
  ours only:   add R, 2 x1
   0028 cmp dword ptr [ecx], eax                       | 0028 cmp dword ptr [ecx], eax
!! 002c inc esi                                        | 002c add esi, 2
```

`dist` is the number of instructions that differ after the two sides are aligned, `sem` the difference with
registers and stack slots ignored (the code does something else), `lock` the instruction-by-instruction count,
`frame` the difference in stack frame size and `first` the offset of the first difference. `MATCH` is the
gate's strict verdict, nothing less. Steer by `dist` and `sem`, not by `lock`: one extra instruction early
shifts every later one. The full description of every command and number is
[docs/WORKBENCH.md](https://github.com/andrewnakas/decompathon-xbox/blob/main/docs/WORKBENCH.md) in the tools'
repository.

Whatever a search or a mutator finds must still pass the rulings below. A variant that matches by a banned
construct is not a match.

## Reading `xbx asm`

The format (an illustration, not a real function):

```
; func_0012A340  52 bytes  game func
0012a340  push    esi
0012a341  mov     esi, ecx
0012a343  mov     eax, dword ptr [esi + 4]
0012a346  push    eax
0012a347  call    0x1ba8a0    ; func_001BA8A0
0012a34c  mov     ecx, dword ptr [0x1efc88]    ; data_001EFC88 (.data)
0012a352  push    0x1c5a10    ; data_001C5A10 (.rdata) "stage%02d"
...
```

| You see | It is | In the unit |
|---|---|---|
| `; func_001BA8A0` on a `call` or `jmp` | a function start in the table | a prototype (or member declaration) named `func_001BA8A0` |
| `; data_001EFC88 (.data)` | a global | `extern T data_001EFC88;` |
| `; data_001C5A10 (.rdata) "text"` | a string constant | the string literal |
| `; data_001C4F00 (.rdata)` with no string | a constant in read-only data: a float or double literal when an x87 instruction loads it, otherwise a table or a vtable | the literal, or what the section below says for vtables |
| `; kernel import #N` | a slot of the kernel import table | the name `config/symbols.csv` gives that slot |
| `; code 0x...` | an address inside a code section that is not a function start | nothing by itself; if it should be a function start, open a `tooling` issue |
| `dd 0x...` lines after the last instruction | the function's switch table | a `switch`; the table is part of the function's bytes |
| `reads eax at entry` in the header line | a `conv` row | see "Functions with a `conv` entry" |
| `game eh` in the header line | an exception-handling stub | no unit; it is matched with the function that registers it (the table's `parent` column) |

## The unit file

```cpp
struct Node {
    unsigned int flags;
    Node *next;

    void func_0012A340(unsigned int mask);
};

extern int data_001EFC88;
void func_001BA8A0(Node *node);

// Calls func_001BA8A0 on every node of the list whose flags meet the mask, and counts them.
void Node::func_0012A340(unsigned int mask)
{
    for (Node *node = this; node; node = node->next) {
        if (node->flags & mask) {
            func_001BA8A0(node);
            data_001EFC88++;
        }
    }
}
```

- The file is `src/funcs/func_0012A340.cpp`: the function's retail address, 8 uppercase hex digits.
- The unit's function is named `func_0012A340`, as a free function or as a member of the class it belongs to.
  Define it out of line: a function defined inside the class body or marked `inline` is refused.
- Every other function or global is declared in the unit and named `func_XXXXXXXX` or `data_XXXXXXXX` after its
  own retail address. The address is read out of the compiler's decorated name
  (`?func_0012A340@Node@@QAEXI@Z`, `_func_0012A340@8`, `?data_001EFC88@@3HA`), so there is nothing else to
  declare.
- The unit is self-contained. The judge copies only unit files, so declare every type and prototype you need in
  the file. You may include only headers already on `main` under `include/`.
- Classes, members, parameters and locals are yours to name. Use real names when the binary gives a reason;
  for fields you do not understand, a padding array (`char unknown_08[0x20];`) keeps the offsets right.
- A comment above the function saying what it does is welcome when you know.

### One address, one decorated name

The decorated name encodes the class, the calling convention, the parameter types and the return type. Across
all units an address may be referenced under only one decorated name, and that is the name its own unit
defines. So the first merged declaration of a function is the contract for everyone after it. The match gate
names the declaration already in the tree:

```
PROBLEM src/funcs/func_0012A340.cpp: 0x1ba8a0 is declared as ?func_001BA8A0@@YAXPAUNode@@@Z here and as ?func_001BA8A0@@YAHPAUNode@@@Z in src/funcs/func_0012B000.cpp: one address, one declaration (use the same class, calling convention and types)
```

Before you declare a callee, search `src/` for its address and copy the declaration you find, class name
included. If that declaration is wrong (the callee's own code proves another signature), say so in the PR and
fix the units that use it together; the owner rule in RULES.md applies to units that are not yours.

Declare game functions with ordinary C++ linkage, so the decorated name carries the whole signature. Library and
runtime functions use the names in `config/symbols.csv`.

## Reading the matcher's output

The format (again an illustration):

```
0012A340 DIFF     52 bytes  ?func_0012A340@Node@@QAEXI@Z  first@+0x1c differing=6
    ! code differs: 2 bytes, first at +0x1c
    ! ?func_0012A340@Node@@QAEXI@Z+0x21: ?func_001BA8A0@@YAXPAUNode@@@Z is 0x1ba8a0, retail refers to 0x1ba9c0
    . +0x30: `cmp eax, 0x20000` holds 0x20000, a number in the image's address range; if it is a number add /* const: 0x20000 */, if it is an address use a symbol
    ? ?helper@@YAXXZ = 0x12b000  (no mapping; retail implies this address)
0 of 1 match
```

The first line of a unit gives its address, `MATCH` or `DIFF`, the size of our function, its decorated name and,
for a `DIFF`, the first differing offset and the number of differing bytes.

- **`!` is a problem.** Any one of them makes the unit a `DIFF`.
- **`.` is a note.** It does not fail the unit in the default mode. Most notes are problems under `--strict`,
  so clear them before you open a PR.
- **`?` is an assumed address.** The name carries no address and nothing maps it, so the matcher assumed the
  address the retail bytes imply and went on. Read the address off the line and rename the declaration
  (`func_0012B000`), or add a `/* sym: */` line if it is a special member or an override. Under `--strict` every `?` is a
  failure.

Compare sizes first. If the sizes differ, the structure is wrong (a missing branch, a wrong loop, a wrong type
width); fix that before you look at registers.

| Message | Meaning | Do |
|---|---|---|
| `code differs: N bytes, first at +0x..` | our instructions are not retail's | `xbx diff` |
| `size: ours is N bytes, retail's function is M` | the function is shorter than retail's, or runs into the next one | fix the structure |
| `size: ours is N bytes, the function table says M` | every byte may equal retail and the table row be short | if the bytes agree, open a `tooling` issue |
| `NAME is 0x.., retail refers to 0x..` | a call, global or member refers to the wrong address | fix the name: the retail address is the one printed last |
| `NAME at 0x.. differs from retail: N of M bytes` | a string, float, table or vtable our object carries is not what retail has there | fix the literal, the table or the slot |
| `NAME is at 0x.. by an earlier reference, retail refers to 0x.. here` | one constant of ours stands for two different retail addresses | they are two different things in retail; write them so |
| `the object defines no function for this unit` | no function is named `func_<address>` | rename it, or add the `/* sym: */` line for a special member or an override |
| `is emitted as an inline copy` | the unit's function is defined in the class body or marked `inline` | define it out of line |
| `a second function rides in this unit` | a helper was not inlined, so it is a real function in retail | declare it as a prototype named after its address |
| `the unit defines a global` / `uninitialised data` / `data it should only declare` | the unit owns data | declare it `extern` as `data_XXXXXXXX` |
| `the unit emits .CRT$...` | a dynamic initialiser or thread-local data | a unit may not have one |
| `unverified code/data in the object` | something in the object is referenced by nothing that was compared | remove it |
| `reads or writes the address 0x.. written as a number` | an address was typed as a number | declare `data_XXXXXXXX` |
| `holds 0x.., a number in the image's address range` | a number that could be an address | add `/* const: */` if it is a number, use the symbol if it is an address |
| `is not a function start in the function table` | a name declared as a function points at no row | check the address; if it really is a function, open a `tooling` issue |
| `is a compiler-made eh stub` | the file is named for an exception-handling row | write the unit for the function it belongs to |
| `has no address (retail implies 0x..)` | (`--strict`) an unmapped name | rename it after that address, or map it |
| `/* sym: NAME */ is not used by the object` / `/* const: 0x.. */ excuses nothing` | (`--strict`) a directive line the unit does not need | remove the line |
| `does not compile` | the compiler's messages follow | fix the C++ |

## Calling conventions: what the code shows

These are Microsoft's documented x86 conventions. Read them off the callee and its call sites.

| The code shows | It is |
|---|---|
| callers remove the arguments after the call (`add esp, N`); the callee ends with a plain `ret` | `__cdecl` |
| the callee reads its arguments from the stack only and ends with `ret N` | `__stdcall`, with N bytes of arguments |
| the callee reads `ecx`, then `edx`, as its first two arguments and removes any others with `ret N` | `__fastcall` |
| the callee uses `ecx` as an object pointer, takes the other arguments on the stack and ends with `ret N` | a member function |
| the callee reads `eax`, `ebx`, `esi` or `edi` before writing it | not a standard convention: a `conv` row |

- A function with no stack arguments ends with a plain `ret` under every convention; look at the registers it
  reads.
- Integers and pointers return in `eax`, 64-bit integers in `edx:eax`, floating point in `st(0)`.
- `ebx`, `esi`, `edi` and `ebp` survive a call; `eax`, `ecx` and `edx` do not.

## Member functions

A function that takes `this` in `ecx` is a member function. This compiler has no `__thiscall` keyword (Microsoft
added it in Visual C++ 2005), so the only way to get the convention is to write a member of a class.

- Declare the class in the unit with the fields the function touches, at their offsets, and the members it calls.
- A callee that is a member function is declared as a member too: `void func_0012B000(int);` inside the class,
  called as `node->func_0012B000(1)`.
- Use the class name other units already use for the same class; it is part of the decorated name. If no unit
  names the class yet, choose a plain name for what the code shows it is.

## Virtual calls

A call through a pointer loaded from the object's first word (`mov eax, dword ptr [ecx]` then
`call dword ptr [eax + 8]`) is a virtual call: here, the slot at offset 8.

- Declare the class with virtual functions in slot order and call the one in that slot. A virtual call refers
  to no symbol, so the slot needs no address.
- Declare virtual functions; do not define them in a unit that is not theirs.
- Check that the offset the code reads the vtable pointer from is where your class puts it.

### Units whose object carries a vtable

A constructor or destructor stores the class's vtable pointer, so its object usually carries the vtable. The
matcher places that vtable at the address the retail code stores and compares it slot by slot: each slot must
resolve to the function the retail table holds there.

So in such a unit every virtual function is declared in slot order and named `func_XXXXXXXX` after the function
in its slot. Run `xbx match` once with any names: the `?` lines give the address each slot implies. Code the
compiler generates for the class (a deleting destructor, for example) is placed and compared in the same way.

#### Folded functions

The linker folds identical functions into one: a bare `ret` can be a dozen different empty virtual functions,
and then fills several slots of one vtable. C++ cannot give two of a class's virtual functions the same name,
so an address the project lists under `[names] folded` in `xbx.toml` may also be written
`func_XXXXXXXX_1`, `func_XXXXXXXX_2`, ... up to `_99`. Each alias is the same address and counts as an address
of its own for the one-declaration rule, so number them in slot order within a class:

```cpp
struct Node {
    virtual ~Node();
    virtual void func_00011C90();       // slot 1
    virtual void func_00011C90_1();     // slot 2: the same folded function
    virtual void func_00011C80(int);    // slot 3
    virtual void func_00011C90_2();     // slot 4
};
```

The evidence for a folded address is one function filling two slots of the same vtable. An alias on an address
that is not listed is refused; ask a maintainer to list it.

#### Overrides

An override keeps the name of the virtual function it overrides, so it cannot carry its own address. Give it
one with a `sym:` line, in its own unit and in every unit whose object carries the class's vtable:

```cpp
/* sym: ?func_00011C90@Derived@@UAEXXZ = 0x000728D0 */
struct Derived : Node {
    virtual ~Derived();
    virtual void func_00011C90();       // overrides Node's slot 1; this one is at 0x728D0
};
```

Only a virtual member function's name may take another address this way. A slot the class does not override
keeps the base's name and address. If one override's code fills the same slot of two unrelated classes, the
linker folded them: the address goes under `[names] folded`, and each class keeps its own override name.

A class that declares no destructor gets an implicit one. When a deleting destructor in the object calls it,
the matcher places and compares it like the deleting destructor; declaring an empty destructor instead adds a
vtable store that retail does not have.

#### Functions retail inlined

Retail sometimes inlined a function into its caller (usually one from the same source file). Write the callee as
an `inline` helper in the caller's unit and call it: the compiler inlines it the same way. The out-of-line copy
it also emits is a COMDAT that nothing refers to, which the linker drops; the matcher notes it and ignores it.
The callee's own unit is still written separately at its own address.

## `/* sym: */`: special members

Constructors, destructors, operators and vtables have decorated names that start with `??` and cannot carry an
address. Map each one the unit refers to, one per line:

```cpp
/* sym: ??0Node@@QAE@XZ = 0x0012A300 */
/* sym: ??1Node@@QAE@XZ = 0x0012A320 */
```

- When the unit's own function is a special member, the file is still named for its address
  (`func_0012A300.cpp`) and carries the `sym:` line that gives its decorated name that address.
- Copy the decorated name from the matcher's output (the `?` line, or the list of functions it prints when it
  finds none named for the unit). Do not compose decorations by hand.
- `sym:` is only for `??` names and for virtual overrides ("Overrides" above). Everything else is named `func_`
  or `data_`.
- The one-name-per-address contract covers these too (folded addresses excepted).

## `/* const: */`: numbers that look like addresses

The image spans `0x10000` to `0x288620`. A 32-bit number in that range that no relocation covers could be an
address someone typed as a number, so the matcher points it out.

- If it is a number (a size, a mask, a count, a colour), add `/* const: 0x20000 */` on a line of its own.
- If it is an address, use the symbol: `data_XXXXXXXX` or `func_XXXXXXXX`.
- A direct read or write of an address written as a number is always refused.

Addresses outside the image (hardware registers, for example) are ordinary numbers and need no directive.

## Strings, floats, switch tables, exception handling

All of these are legal in a unit, because all of them are verified.

- **Strings.** Write the literal. The compiler puts it in the object; the matcher places it at the address the
  retail instruction refers to and compares the bytes. Spell it exactly, escapes included.
- **Floats and doubles.** Write the literal with enough digits to give the same bits. It is placed and compared
  like a string.
- **Switch tables.** Write the `switch`. The table follows the function's instructions and is compared with
  them; every entry must land on the same offset. Never invent a `case` to shape the table (see the rulings).
- **Exception handling.** A function with objects to unwind registers a handler. The handler stub and the
  unwind funclets are the kind `eh` rows of the function table; the compiler generates them with their tables,
  and the matcher places and compares each one. Write the C++ that needs them; never write a unit for an `eh`
  row.

## Functions with a `conv` entry

The `conv` column of `config/functions.csv` lists the registers (`eax ebx esi edi`) a function reads at entry.
No standard convention passes arguments there. A non-empty `conv` means the retail linker's link-time code
generation gave the function a custom calling convention, and a per-object compile cannot reproduce it.

- Skip the function. `xbx asm` prints `reads ... at entry` in its header line.
- Before you start any function, check the functions it calls (the `calls` column, or `xbx asm` on each). If
  one has a `conv` entry, the call site in your function loads a register for it where a standard convention
  would push an argument, and it will not match either. Skip it too.
- If you want the C++ on record anyway, write it as equivalent code (the register value becomes an ordinary
  parameter, with a comment saying which register retail uses) and put it in the non-matching tier.
- Never chase a custom convention with inline assembly, `__declspec(naked)` or steering code.

## Not matching yet: `src/nonmatching/`

After about 15 compiles on a small function or 25 on a large one, stop. If your C++ is equivalent, it goes in
`src/nonmatching/func_XXXXXXXX.cpp` with a `/* fuzzy: NN.N */` line. If it is not, keep it under `work/` with
a note on what differs.

```sh
.venv/bin/xbx match --write-fuzzy src/nonmatching/func_0012A340.cpp    # writes the /* fuzzy: */ line
```

The score is the share of instructions that line up with the retail code, from 0 to 100. `xbx match` prints it
for every `DIFF`. It only ranks unfinished work. A score never makes a function count as matched. The match
gate computes it again and rejects a line that differs, and it rejects a non-matching unit that matches: that
one belongs in `src/funcs/`.

Equivalence needs evidence at the instruction level. Every claim that the C++ does what the retail code does
(the address arithmetic, the width of a store, the arguments a callee receives) should be checkable against
the disassembly, and where it is not obvious a comment cites the retail addresses. An exact match is proof. A
higher fuzzy score is not.

## Rulings

These carry over from the earlier Decompathon projects and hold here from the first unit. The scan gate
catches bare expression statements, self-assignments and `do { } while (0)` wrappers. The rest are rules all
the same.

### The instruction test

A statement whose result is never read is allowed **only if every instruction it produces exists in the retail
function**. Then the original source had it and the compiler kept it. Add a comment citing the retail addresses.

A statement that only steers the compiler is banned: one that emits nothing of its own, or emits instructions
the retail function does not have, and is there to change a register, an order or a stack slot somewhere else.

Ordinary choices of form are not steering: the order of statements, how an expression is split across
statements, the type and scope of a local, the order of operands, `for` or `while`. That is how the original
was written. Each choice must still read as code a programmer would write.

### Banned constructs

- **Bare expression statements**: `count;`, `(void)node->flags;`, `a, b;`. A read that does nothing.
- **Self-assignments**: `x = x;`, `p = (Node *)p;`.
- **Empty branches**: `if (c) { }`, an empty `else { }`, a `case` with no retail evidence.
- **`do { ... } while (0)` wrappers**, and anything used the same way (`if (1) { ... }`, a loop with an
  unconditional `break`): a loop that never loops, written to move code or change a register.
- **Alias temporaries**: a local that only renames another variable (`Node *n2 = node;`, `int count2 = count;`)
  when the retail code keeps no second copy. If the retail code really holds the copy (a second register or a
  stack slot that is written and later read), the copy is real code: write it and cite the instructions.
- **Dead stores and dead initialisations** that the compiler removes, and comma tricks.
- **`volatile` to force a reload or a store.** Declare something `volatile` only when hardware or another
  thread really touches it, and say which in a comment.
- **Per-unit flags as a lever.** The allow-list in `xbx.toml` is the whole list. A flag is a claim about how the
  original source file was compiled; a maintainer adds one only with evidence that the matched neighbours from
  the same source file still match with it.

### Signatures are behaviour

A callee's declaration is a statement about the callee: how many arguments it takes, how wide each is, its
calling convention, what it returns and, for a member, its class. Each can be checked against the callee's own
code and its call sites.

- Check the callee first. Before you chase a register or an instruction order in the caller, read the callee's
  code for its real argument count, convention and return value. A missing argument, a bogus `this` or a wrong
  return type shifts everything in the caller.
- Never declare a callee wrongly to steer the caller: a `void` function as `int`, an `int` function as `void`,
  an extra or missing parameter, another convention, another class.
- Parameters are what callers pass. If the retail call sites push an argument, declare it even when the callee
  ignores it, and cite a call site. Never invent a parameter that no caller passes.
- The decorated name makes this a contract: one address, one decorated name, across all units.

### Case values

An empty `case` is allowed only when the binary pins its value: the table or the compare sequence shows that a
label for exactly that value existed. Never invent a case value the binary does not show.

## Findings

A finding is added here when a merged unit proves it: what the retail code shows and what C++ produces it, with
the unit that proves it.

**Loops, copies and stores**
- `lea edi; mov ecx, 8; xor eax, eax; rep stosd` is a `for` loop that zeroes 8 words. The `memset` intrinsic
  copies `this` to `edx` first and misses (`func_00039F40`).
- Eight unrolled `mov` pairs are eight element-wise assignments; a struct assignment of the same 32 bytes gives
  `rep movsd` (`func_00039F60`).
- The order of constant stores shows in the code: `a = 0; b = 1; c = 0; d = 12; return 1;` stores an immediate
  1, while the order a, c, b, d shares the 1 with the return value (`func_00031450`). `x = 0; y = arg; z = 0;`
  loads the argument first (`func_00038DA0`).
- Walking a list with the parameter itself (`while (first->next) first = first->next;`) gives `je; jmp`; a
  copy local changes the addressing (`func_00011B60`).
- `delete node;` on a class with a virtual destructor inside `while (node)` emits no null check
  (`func_00011B90`).

**Conditions and branches**
- `if (a && b) return 1; return 0;` stays branchy (`func_0003A580`). A single-condition `if (x) return 1;
  return 0;` and every equivalent spelling become `setne`.
- `return p->x == 0;` gives `mov; xor eax, eax; test; sete al` (`func_00012910`).
- The same constant stored in both arms of an if/else is hoisted above the branch and kept in a register
  (`func_001015E0`).
- `js`/`jns` after `test eax, eax` is a top-bit test of an unsigned field (`flags & 0x80000000`); `x >= 0` on an
  `int` gives `jl`/`jge` (`func_000B9960`).
- `if (state < 3 && x) state = 3;` on an unsigned field loads 3 once and reuses it for the compare and the store
  (`func_000F44E0`).
- A switch with four cases and no default keeps the unreachable load of a pointer it never set. Guarded by
  `type <= 3` the guard merges with the switch's range test (`func_00039B50`); guarded by `type < 4` both tests
  stay (`func_00039BE0`).
- Only the nested `if (!busy) { if (index < N) { if (h) {...} else {...} } return 1; } return 0;` shape
  matched `func_00025390`; early returns changed the register assignment.
- `cmp 1; je X; cmp 2; jne Y` comes from `if (k == 1) {A} else if (k == 2) {A}` with identical blocks, not from
  `k == 1 || k == 2` (`func_000E8500`, `func_000E8280`, `func_000E08A0`).
- Where retail keeps a short "back out and return" path inline and puts the long path last, a flag set by the
  test gives that order: `int turn = 0; if (cond) turn = 1; if (!turn) { ...; return; } ...` (`func_000D4860`,
  `func_000E24B0`, `func_000D9220`). About 20 spellings with `break`, `goto`, if/else and switch did not.
- A `goto` to a shared tail gives retail's load, operate, store with one cross-jumped store (`func_000D87E0`).

**Registers and evaluation order**
- An expression repeated in two statements and the same expression named as a local give different register
  assignments (`func_00039E80`).
- `return t[i] ? (o->*t[i])(arg) : 1;` keeps the index in `ecx` and the handler in `edx`; the if/else spelling
  puts both in `edx` (`func_000256C0`).
- `Object *o = (Object *)game->f(7); return o->g(a, b);` finds the object before pushing the arguments; written
  as one expression the arguments are pushed first (`func_000256A0`).
- `int result = 0; p = lookup(); if (p) result = p->f(); return result;` gives `xor esi, esi ... mov eax, esi`
  on the null path and a tail `jmp` on the other (`func_00107AB0`).
- `time = owner->step + time;` gives `fld [owner+N]; fadd [this+M]`: the operand order of a float sum shows
  (`func_000E6980`). Likewise `position.x += velocity.x` and `+= at->x` load in opposite orders
  (`func_000D9220`).
- An array pointer read from an address-taken local struct is reloaded on every pass of a loop; copied to a
  pointer local before the loop it becomes retail's single advancing pointer (`func_000E5EA0`).
- x87 stack slots follow how often each value is used, not the order of declaration; a separate temporary
  changed them to retail's (`func_00044F00`).
- Quad drawers match when each vertex field repeats its sum inline (`x + w[i]`): the compiler merges the
  repeats into stack temporaries itself, and sums computed into locals first do not match (`func_00120F40`,
  `func_00132290`).
- Equality tests on a field read from memory are not jump-threaded; the same tests on a local copy are
  (`func_00123240`).
- A jump table whose entries land in the middle of blocks comes from cases that fall through into the next
  (`func_000EC990`).
- `!(a < b)` on floats gives `test ah, 5; jnp`, `a >= b` gives `test ah, 1; jne` (`func_000993D0`).
- `if (x) f(k, 1); else f(k, 0);` gives two pushes of constants; `f(k, x ? 1 : 0)` gives `setne`
  (`func_00098100`).
- `size = size + (a + b)` keeps retail's order of additions; `size += a + b` is reassociated
  (`func_001063A0`).
- MSVC cross-jumps identical tails only when each arm carries the full copy (`func_000A0610`,
  `func_001045D0`, `func_000F4FF0`).
- A float a loop assigns after a call stays on the x87 stack across passes; taking a pointer to its field
  before the call (`float *distance = &faces[i].distance;`) gives retail's store (`func_000C9860` went from
  lock 144 to 5).
- Before naming the cases of a switch with a byte map, read the whole map (`xbx asm` prints it in rows of
  four, the last row may be short): an empty case shifts every label after it (`func_000BB7B0`).
- MSVC unrolls small constant-count loops completely (2 passes in `func_000B6ED0`, 4 in `func_000A5070`), but
  not every one (`func_000A4D80`). With an `unsigned int` index a 2- or 4-pass loop keeps retail's countdown
  counter in memory; an `int` index gives a pointer compare (`func_000EFFF0`, `func_000DC490`).
- Struct copies written in both arms of an if/else are merged into one shared copy through a pointer
  (`func_000DA3E0`).
- `x * 45.0f * 182.04445f` folds the two constants into one; an inline helper that multiplies by the second
  keeps both `fmul`s (`func_000AFA90`).
- Copies through a walking pointer (`*v = template[i]; ... v++;`) match where indexed `vertex[i]` keeps a
  base register (`func_0005FAF0`).
- Computing a derived pointer before its base (`data = pack + off + 0x10; chunk = pack + off;`) gives retail's
  `lea` and registers (`func_0002E1C0`, `func_0002E4C0`, `func_00033920`).
- An inline helper's argument is evaluated inside the helper's loop; computed into a local first, it is
  evaluated once, as in retail (`func_0004FE50`).
- `return f() != 0;` and `if (f()) return 1; return 0;` place the shared return differently
  (`func_00016DA0`); success returns written out on each path keep retail's duplicated blocks
  (`func_00016A30`).
- Float literals need the digits that round to retail's bits: `5.5555556f` is one bit off `0x40B1C71C`,
  `5.5555553f` matches (`func_000C55F0`).

**Classes**
- A pointer to a member of a class that is only forward-declared takes the 16-byte general form and a thunked
  call. Defining the class first (an empty body is enough) gives the 4-byte form and `call edx`
  (`func_00025700`, `func_00025740`).
- Several functions end in `ret N` and never read `ecx`, but every caller loads `ecx` with an object first: they
  match as member functions that do not use `this` (`func_000C1440`, `func_000C1810`).
