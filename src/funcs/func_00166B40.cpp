struct Guid;

// DirectInput8, the class its factory (table 0x1E20A0, after the "MUSASHI.DirectInput8.1" strings) creates; its
// table is at 0x1E21A0. Several tables hold this same function (folded).
struct DirectInput8 {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual long __stdcall func_00166B40(void *, void *, void *, void *, unsigned long);
};

// Slot 9: not implemented (E_NOTIMPL).
long __stdcall DirectInput8::func_00166B40(void *, void *, void *, void *, unsigned long)
{
    return 0x80004001;
}
