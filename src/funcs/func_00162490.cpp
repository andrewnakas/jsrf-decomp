struct Inner {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual long __stdcall slot4(void *argument);
};

struct Guid;

// The class whose table is at 0x1E1968.
struct Object_001E1968 {
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
    virtual void slot12();
    virtual void slot13();
    virtual long __stdcall func_00162490(void *argument);

    char unknown_04[0x1c];
    Inner *inner;
};

// Slot 14: passes the argument on to slot 4 of the object at +0x20, or fails with 0x800401F0 (not initialised) when
// there is none.
long __stdcall Object_001E1968::func_00162490(void *argument)
{
    if (inner)
        return inner->slot4(argument);
    return 0x800401F0;
}
