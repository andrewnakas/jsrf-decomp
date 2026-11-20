int __stdcall func_00145A5D(void *address, unsigned long size, unsigned long type);

// A class whose table is at 0x1E141C (12 slots; Release 0x1579A0).
struct Object_001E141C {
    virtual void __stdcall func_00157960();  // slot 6

    char unknown_04[0x1024];
    void *memory;
    unsigned long size;
};

// Frees the memory at +0x1028 (func_00145A5D with 0x8000) and forgets it.
void __stdcall Object_001E141C::func_00157960()
{
    if (memory) {
        func_00145A5D(memory, 0, 0x8000);
        memory = 0;
        size = 0;
    }
}
