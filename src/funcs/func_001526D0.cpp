// The class whose table is at 0x1E12B8 (kind 2 of 0x152BC0); 0x1526D0 also fills slots 4 and 6 of 0x1E12D8 and
// slots of MUSASHI's tables 0x1E21A0 and 0x1E3828 (folded).
struct Object_001E12B8 {
    virtual void __stdcall slot0();
    virtual void __stdcall slot1();
    virtual void __stdcall slot2();
    virtual void __stdcall slot3();
    virtual void __stdcall slot4();
    virtual void __stdcall slot5();
    virtual long __stdcall func_001526D0(void *argument1, void *argument2, void *argument3);  // slot 6
};

// Not implemented: E_NOTIMPL.
long __stdcall Object_001E12B8::func_001526D0(void *argument1, void *argument2, void *argument3)
{
    return 0x80004001;
}
