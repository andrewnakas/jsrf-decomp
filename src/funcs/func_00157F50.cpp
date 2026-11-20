extern "C" void *memset(void *destination, int value, unsigned int size);
void *__stdcall func_00145A2F(void *address, unsigned long size, unsigned long type, unsigned long protect);
// Puts the object in the list at data_00265120 (E_OUTOFMEMORY when the list cannot grow).
long __stdcall func_00159E90(void *link, void *object);

// The base of the classes whose tables are at 0x1E1498 and 0x1E14B8 (created by 0x158490).
struct Object_001E1478 {
    virtual long __stdcall func_00157F00(const void *iid, void **object);  // slot 0

    unsigned long references;
};

// Kind 0 of 0x158490.
struct Object_001E1498 : Object_001E1478 {
    long __stdcall func_00157F50(unsigned int count, unsigned long flags);

    void *entries;
    unsigned int count;
};

// Sets the object up for count 0x14-byte entries (cleared, from func_00145A2F) and puts it in the list.
// E_INVALIDARG for no entries, E_OUTOFMEMORY when the allocation fails.
long __stdcall Object_001E1498::func_00157F50(unsigned int count, unsigned long flags)
{
    if (count) {
        unsigned int size = count * 0x14;
        void *memory = func_00145A2F(0, size, 0x3000, 4);
        if (memory) {
            memset(memory, 0, size);
            entries = memory;
            this->count = count;
            func_00159E90(&references, this);
            return 0;
        }
        return 0x8007000e;
    }
    return 0x80070057;
}
