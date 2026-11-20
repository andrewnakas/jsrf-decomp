int __stdcall func_00145A5D(void *address, unsigned long size, unsigned long type);
long __stdcall func_00159F30(void *unused, void *object);

// One 0x14-byte entry.
struct Entry_0x14 {
    unsigned char bytes[0x14];
};

// The base of the classes whose tables are at 0x1E1498 and 0x1E14B8 (created by 0x158490).
struct Object_001E1478 {
    virtual long __stdcall func_00157F00(const void *iid, void **object);  // slot 0
    virtual unsigned long __stdcall func_001532F0_2();  // slot 1: AddRef, folded
    virtual unsigned long __stdcall func_0014D080_5();  // slot 2: returns 0, folded
    virtual long __stdcall func_00157F10(unsigned long value);  // slot 3
    virtual void __stdcall func_00157F20(unsigned long value);  // slot 4

    unsigned long references;
};

// Kind 0 of 0x158490.
struct Object_001E1498 : Object_001E1478 {
    Entry_0x14 *entries;
    unsigned int count;
};

// Takes the object apart (its Release, 0x158430, calls it): empties every entry (slot 4), frees them (func_00145A5D
// with 0x8000) and takes the object off the list at data_00265120 (func_00159F30).
void __stdcall func_00157FC0(Object_001E1498 *object)
{
    if (object->entries) {
        for (unsigned int i = 0; i < object->count; i++)
            object->func_00157F20((unsigned long)&object->entries[i]);
        func_00145A5D(object->entries, 0, 0x8000);
        object->entries = 0;
        object->count = 0;
    }
    func_00159F30(&object->references, object);
}
