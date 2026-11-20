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
    virtual long __stdcall slot8(void *, void *);
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
    virtual long __stdcall func_00177400(void *argument1, void *argument2);

    char unknown_04[8];
    Inner *inner;
};

// Slot 8: passes its arguments on to slot 8 of the object at +0xc, or fails with 0x800401F0 (not initialised) when
// there is none.
long __stdcall Object_001E3FE4::func_00177400(void *argument1, void *argument2)
{
    if (inner)
        return inner->slot8(argument1, argument2);
    return 0x800401F0;
}
