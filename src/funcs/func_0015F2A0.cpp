// What the classes whose tables are at 0x1E1798 and 0x1E17BC have in common: the keys and the references. The
// constructors 0x15F190 and 0x15F1C0 clear them before they store the table pointer.
struct KeyState {
    char unknown_04[0x40];
    void *keys;
    void *value_48;
    unsigned long references;
};

// A class whose table is at 0x1E1798 (9 slots, constructor 0x15F190): its keys are at +0x44.
struct Object_001E1798 : KeyState {
    virtual long __stdcall func_0015F580(const void *iid, void **object);  // slot 0
    virtual unsigned long __stdcall func_0015F1B0();  // slot 1
    virtual unsigned long __stdcall func_0015F2A0();  // slot 2: Release
};

void __stdcall func_0015F3C0(Object_001E1798 *object);

// Release: the last reference lets func_0015F3C0 count the object out, then deletes it.
unsigned long __stdcall Object_001E1798::func_0015F2A0()
{
    if (--references == 0) {
        func_0015F3C0(this);
        delete this;
        return 0;
    }
    return references;
}
