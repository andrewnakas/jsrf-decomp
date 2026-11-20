struct Guid;

// The objects in MGameInput8's list at +0x28.
struct Device {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
};

// The objects in MGameInput8's list at +0x38 (slot 9 adds one, slot 10 gives one out).
struct Registered {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
};

// A std::vector of pointers.
struct DeviceList {
    char allocator;
    Device **first;
    Device **last;
    Device **end;
};

// A std::vector of pointers.
struct RegisteredList {
    char allocator;
    Registered **first;
    Registered **last;
    Registered **end;

    void func_00161780(Registered *const &value);
};

// MGameInput8, the class its factory (table 0x1E185C, next to the "MUSASHI.MGameInput8.1" strings) creates; its
// table is at 0x1E1900.
struct MGameInput8 {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual long __stdcall func_00161890(Registered *entry);

    char unknown_04[0x10];
    unsigned int interval;
    unsigned int counter;
    char unknown_1c[8];
    void *inner;
    DeviceList devices;
    RegisteredList registered;
};

// Slot 9: appends the object, with a reference, to the list at +0x38 (0x161780). E_INVALIDARG for a null object,
// 0x800401F0 (not initialised) while +0x24 is null.
long __stdcall MGameInput8::func_00161890(Registered *entry)
{
    if (inner) {
        if (entry) {
            entry->slot1();
            registered.func_00161780(entry);
            return 0;
        }
        return 0x80070057;
    }
    return 0x800401F0;
}
