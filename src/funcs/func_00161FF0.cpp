struct Guid;

// The object at +0x3b0.
struct Inner {
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
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual long __stdcall slot18(void *, void *, void *, void *);
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
    virtual long __stdcall func_00161FF0(void *argument1, void *argument2, void *argument3, void *argument4);

    char unknown_04[0x3ac];
    Inner *inner;
};

// Slot 8: passes its arguments on to slot 18 of the object at +0x3b0, or fails with 0x800401F0 (not initialised) when
// there is none.
long __stdcall Object_001E1968::func_00161FF0(void *argument1, void *argument2, void *argument3, void *argument4)
{
    if (inner)
        return inner->slot18(argument1, argument2, argument3, argument4);
    return 0x800401F0;
}
