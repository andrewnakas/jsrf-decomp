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
    virtual long __stdcall slot10(void *);
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
    virtual long __stdcall func_00173210(void *argument1);

    char unknown_04[8];
    Inner *inner;
    Inner *second;
};

// Slot 10: passes its argument on to slot 10 of the object at +0xc, or fails with 0x800401F0 (not initialised) when
// there is none.
long __stdcall Object_001E3D30::func_00173210(void *argument1)
{
    if (inner)
        return inner->slot10(argument1);
    return 0x800401F0;
}
