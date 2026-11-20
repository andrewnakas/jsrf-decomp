struct Guid;

// The object at +0x3b0.
struct Inner {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual long __stdcall slot5(void *, void *);
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
    virtual long __stdcall func_00162580(void *argument1, void *argument2);

    char unknown_04[0x3ac];
    Inner *inner;
};

// Slot 21: passes its arguments on to slot 5 of the object at +0x3b0, or fails with 0x800401F0 (not initialised) when
// there is none.
long __stdcall Object_001E1968::func_00162580(void *argument1, void *argument2)
{
    if (inner)
        return inner->slot5(argument1, argument2);
    return 0x800401F0;
}
