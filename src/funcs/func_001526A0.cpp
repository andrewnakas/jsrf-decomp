struct Rect;

// What slot 3 of the classes below copies out: the three values at +8.
struct Info {
    unsigned long values[3];
};

// The base of the classes whose tables are at 0x1E1290 (destructor 0x152690), 0x1E1298, 0x1E12B8 and 0x1E12D8
// (created by 0x152BC0); all four share this QueryInterface.
struct Object_001E1290 {
    virtual long __stdcall func_00152360(const void *iid, void **object);  // slot 0
    virtual unsigned long __stdcall func_0014E1F0_1();  // slot 1: AddRef, folded


    void *object;
    unsigned long value_08;
    unsigned long value_0C;
    long value_10;
    unsigned long references;
};

// The class whose table is at 0x1E1298 (kind 1 of 0x152BC0, 0x18 bytes).
struct Object_001E1298 : Object_001E1290 {
    virtual unsigned long __stdcall func_00152AE0();  // slot 2
    virtual long __stdcall func_001526A0(Info *out);  // slot 3, folded with the other two
    virtual long __stdcall func_00152740(unsigned long *second, unsigned long *first, unsigned long unused);  // slot 4
    virtual void __stdcall func_00011C80_5();  // slot 5: does nothing, folded
    virtual long __stdcall func_00152780(void *first, void *second, const Rect *rect);  // slot 6
    virtual long __stdcall func_001525D0(unsigned long value);  // slot 7
};

// Copies the three values at +8 out (slot 3 of 0x1E1298, 0x1E12B8 and 0x1E12D8, folded); E_INVALIDARG for a null
// pointer.
long __stdcall Object_001E1298::func_001526A0(Info *out)
{
    if (out) {
        out->values[0] = value_08;
        out->values[1] = value_0C;
        out->values[2] = value_10;
        return 0;
    }
    return 0x80070057;
}
