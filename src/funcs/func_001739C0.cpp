struct Guid;

// The object the class passes its calls on to.
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
    virtual void slot18();
    virtual void slot19();
    virtual long __stdcall slot20(void *);
};

// The class whose table is at 0x1E3D88: the other class the MRIFFFile factory (0x1E3CD8) creates. Slots 10 to 17 hold
// the same functions as the table at 0x1E3D30, and slots 5 to 9 the same as 0x1E3FE4.
struct Object_001E3D88 {
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
    virtual long __stdcall func_001739C0(void *argument1);

    char unknown_04[8];
    Inner *inner;
};

// Slot 20: passes its argument on to slot 20 of the object at +0xc, or fails with 0x800401F0 (not initialised) when
// there is none.
long __stdcall Object_001E3D88::func_001739C0(void *argument1)
{
    if (inner)
        return inner->slot20(argument1);
    return 0x800401F0;
}
