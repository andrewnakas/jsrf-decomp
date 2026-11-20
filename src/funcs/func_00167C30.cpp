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
    virtual long __stdcall func_00167C30(void *event);

    char unknown_04[0x10];
    void *device;
    char unknown_18[0x10];
    void *event;
};

// Slot 12: keeps the value at +0x28 once the object has a device (+0x14); before that it fails with 0x800401F0 (not
// initialised).
long __stdcall Object_001E3828::func_00167C30(void *event)
{
    if (device) {
        this->event = event;
        return 0;
    }
    return 0x800401F0;
}
