struct Guid;

// The object the class passes its calls on to.
struct Inner {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual long __stdcall slot4(void *, void *, void *, void *);
};

// The class whose table is at 0x1E3D30: one of the two classes the MRIFFFile factory (0x1E3CD8) creates. Slots 10 to
// 17 hold the same functions as the table at 0x1E3D88, and slots 5, 6, 7 and 9 the same as 0x1E3FE4.
struct Object_001E3D30 {
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
    virtual long __stdcall func_00173160(void *argument1, void *argument2, void *argument3, void *argument4);

    char unknown_04[8];
    Inner *inner;
    Inner *second;
};

// Slot 18: passes its arguments on to slot 4 of the object at +0x10, or fails with 0x800401F0 (not initialised) when
// there is none.
long __stdcall Object_001E3D30::func_00173160(void *argument1, void *argument2, void *argument3, void *argument4)
{
    if (second)
        return second->slot4(argument1, argument2, argument3, argument4);
    return 0x800401F0;
}
