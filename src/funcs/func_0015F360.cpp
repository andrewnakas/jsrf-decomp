/* sym: ?func_0014D080_8@Object_001E17E0@@UAGKXZ = 0x0015F360 */
// What the classes whose tables are at 0x1E1798 and 0x1E17BC have in common: the keys and the references. The
// constructors 0x15F190 and 0x15F1C0 clear them before they store the table pointer.
struct KeyState {
    char unknown_04[0x40];
    void *keys;
    void *value_48;
    unsigned long references;
};

// The base of the classes whose tables are at 0x1E17BC (constructor 0x15F1C0) and 0x1E17E0 (constructor 0x15F280): keys at +0x44.
struct Object_001E17BC : KeyState {
    virtual long __stdcall func_00157F00_3(const void *iid, void **object);  // slot 0: E_UNEXPECTED, folded
    virtual unsigned long __stdcall func_0015F1B0_1();  // slot 1: AddRef, folded
    virtual unsigned long __stdcall func_0014D080_8();  // slot 2: returns 0, folded
};

// The class whose table is at 0x1E17E0 (constructor 0x15F280).
struct Object_001E17E0 : Object_001E17BC {
    virtual unsigned long __stdcall func_0014D080_8();  // slot 2, at 0x15F360: Release
};

void __stdcall func_0015F9A0(Object_001E17E0 *object);

// Release: the last reference lets func_0015F9A0 count the object out, then deletes it.
unsigned long __stdcall Object_001E17E0::func_0014D080_8()
{
    if (--references == 0) {
        func_0015F9A0(this);
        delete this;
        return 0;
    }
    return references;
}
