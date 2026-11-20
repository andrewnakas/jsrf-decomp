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
    virtual long __stdcall slot9(void *);
};

// The class whose table is at 0x1E3FE4: one of the classes the MFile2 factory (0x1E3F1C) creates. Slots 5 to 9 hold
// the same functions as the table at 0x1E3D88, slots 5, 6, 7 and 9 the same as 0x1E3D30, and slots 7 and 8 the same
// as 0x1E3FB0.
struct Object_001E3FE4 {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual long __stdcall func_001775E0(void *argument1);

    char unknown_04[8];
    Inner *inner;
};

// Slot 9: passes its argument on to slot 9 of the object at +0xc, or fails with 0x800401F0 (not initialised) when
// there is none.
long __stdcall Object_001E3FE4::func_001775E0(void *argument1)
{
    if (inner)
        return inner->slot9(argument1);
    return 0x800401F0;
}
