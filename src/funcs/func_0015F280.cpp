/* sym: ??0Object_001E17E0@@QAE@XZ = 0x0015F280 */
/* sym: ??0Object_001E17BC@@QAE@XZ = 0x0015F1C0 */
/* sym: ?func_00157F00_3@Object_001E17E0@@UAGJPBXPAPAX@Z = 0x0015F800 */
/* sym: ?func_0014D080_8@Object_001E17E0@@UAGKXZ = 0x0015F360 */
/* sym: ?func_0015F1E0@Object_001E17E0@@UAGJKKK@Z = 0x0015F860 */
/* sym: ?func_00157F30_1@Object_001E17E0@@UAGXKK@Z = 0x0015F770 */
// What the classes whose tables are at 0x1E1798 and 0x1E17BC have in common: the keys and the references. The
// constructors 0x15F190 and 0x15F1C0 clear them before they store the table pointer.
struct KeyState {
    KeyState() : keys(0), value_48(0), references(0) {}

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
    virtual long __stdcall func_0015F1E0(unsigned long first, unsigned long second, unsigned long third);  // slot 3
    virtual unsigned int __stdcall func_0015F5E0();  // slot 4
    virtual void __stdcall func_0015F730(int index);  // slot 5
    virtual void __stdcall func_0015F450_1(unsigned int data, unsigned int stride, int count);  // slot 6: folded
    virtual void __stdcall func_0015F750(void *out, float time);  // slot 7
    virtual void __stdcall func_00157F30_1(unsigned long first, unsigned long second);  // slot 8: folded

    Object_001E17BC();
};

// The class whose table is at 0x1E17E0 (constructor 0x15F280).
struct Object_001E17E0 : Object_001E17BC {
    virtual long __stdcall func_00157F00_3(const void *iid, void **object);  // slot 0, at 0x15F800
    virtual unsigned long __stdcall func_0014D080_8();  // slot 2, at 0x15F360: Release
    virtual long __stdcall func_0015F1E0(unsigned long first, unsigned long second, unsigned long third);  // slot 3, at 0x15F860
    virtual void __stdcall func_00157F30_1(unsigned long first, unsigned long second);  // slot 8, at 0x15F770

    Object_001E17E0();
};

// The constructor: the base's (0x15F1C0), then this class's table.
Object_001E17E0::Object_001E17E0()
{
}
