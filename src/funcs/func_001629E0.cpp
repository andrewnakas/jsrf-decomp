struct Guid;

// The object at +0x20.
struct Inner {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual long __stdcall slot7(void *);
};

// The class whose table is at 0x1E1968 (29 slots; the destructor is the last).
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
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual long __stdcall func_001629E0(void *argument1);

    char unknown_04[0x1c];
    Inner *inner;
};

// Slot 26: passes its argument on to slot 7 of the object at +0x20, or fails with 0x800401F0 (not initialised) when
// there is none.
long __stdcall Object_001E1968::func_001629E0(void *argument1)
{
    if (inner)
        return inner->slot7(argument1);
    return 0x800401F0;
}
