struct Guid;

// The class whose table is at 0x1E3828 (33 slots; the destructor is the last).
struct Object_001E3828 {
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
    virtual long __stdcall func_00167C70(void *, unsigned long, unsigned long);

    char unknown_04[0x10];
    void *device;
};

// Slot 14: the same check as slot 13, with three arguments.
long __stdcall Object_001E3828::func_00167C70(void *, unsigned long, unsigned long)
{
    return device ? 0 : 0x800401F0;
}
