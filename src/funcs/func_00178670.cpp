struct Guid;

// The two objects the class passes its calls on to.
struct First {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual long __stdcall slot9(void *argument);
};

struct Second {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual long __stdcall slot9(void *argument);
};

// The class whose table is at 0x1E4020: one of the classes the MFile2 factory (0x1E3F1C) creates (func_00176460
// builds it).
struct Object_001E4020 {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual long __stdcall func_00178670(void *argument);

    char unknown_04[8];
    First *first;
    Second *second;
};

// Slot 9: passes its argument on to slot 9 of the object at +0xc, when there is one, and then to slot 9 of the object
// at +0x10, whose result it returns; without that one it fails with 0x800401F0 (not initialised).
long __stdcall Object_001E4020::func_00178670(void *argument)
{
    if (first)
        first->slot9(argument);
    if (second)
        return second->slot9(argument);
    return 0x800401F0;
}
