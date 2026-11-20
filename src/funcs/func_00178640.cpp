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
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual long __stdcall slot15(void *);
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
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual long __stdcall slot13(void *);
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
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual long __stdcall func_00178640(void *argument1);

    char unknown_04[8];
    First *first;
    Second *second;
};

// Slot 13: passes its argument on to slot 15 of the object at +0xc, or when there is none to slot 13 of the object at
// +0x10; with neither it fails with 0x800401F0 (not initialised).
long __stdcall Object_001E4020::func_00178640(void *argument1)
{
    if (first)
        return first->slot15(argument1);
    if (second)
        return second->slot13(argument1);
    return 0x800401F0;
}
