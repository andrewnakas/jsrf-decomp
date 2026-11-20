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
    virtual long __stdcall func_00167C90();

    char unknown_04[0x10];
    void *device;
};

// Slot 7 (and slot 8: the linker folded the two): succeeds once the object has a device (+0x14), else 0x800401F0.
long __stdcall Object_001E3828::func_00167C90()
{
    return device ? 0 : 0x800401F0;
}
