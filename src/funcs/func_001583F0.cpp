struct Interface {
    virtual void __stdcall slot0();
    virtual void __stdcall slot1();
    virtual unsigned long __stdcall slot2();
};

struct Holder {
    Interface *object;
    void *memory;
};

int __stdcall func_00145A5D(void *address, unsigned long size, unsigned long type);

// A class whose table is at 0x1E1640 (26 slots; Release 0x159D40, created by 0x159D70).
struct Object_001E1640 {
    virtual void __stdcall func_001583F0(Holder *holder);  // slot 5
};

// Releases the holder's object until its Release returns 0 and frees its memory (func_00145A5D with 0x8000).
// The linker folded it with slot 4 of the table at 0x1E1498.
void __stdcall Object_001E1640::func_001583F0(Holder *holder)
{
    if (holder->object) {
        while (holder->object->slot2())
            ;
        holder->object = 0;
    }
    if (holder->memory) {
        func_00145A5D(holder->memory, 0, 0x8000);
        holder->memory = 0;
    }
}
