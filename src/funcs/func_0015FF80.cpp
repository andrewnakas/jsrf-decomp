struct Guid;

// The object at +0x24 (created by slot 3).
struct Inner {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual long __stdcall slot6(void *context, int);
};

// MGameInput8, the class its factory (table 0x1E185C, next to the "MUSASHI.MGameInput8.1" strings) creates; its table
// is at 0x1E1900.
struct MGameInput8 {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual long __stdcall func_0015FF80();

    char unknown_04[0xc];
    void *context;
    char unknown_14[0x10];
    Inner *inner;
};

// Slot 12: calls slot 6 of the object at +0x24 with the value at +0x10 and 0, or fails with 0x800401F0 (not
// initialised) when there is none.
long __stdcall MGameInput8::func_0015FF80()
{
    if (inner)
        return inner->slot6(context, 0);
    return 0x800401F0;
}
