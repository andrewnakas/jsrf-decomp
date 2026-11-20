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
    virtual unsigned long __stdcall slot2();
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
};

// MGameInput8, the class its factory (table 0x1E185C, next to the "MUSASHI.MGameInput8.1" strings) creates; its
// table is at 0x1E1900.
struct MGameInput8 {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual void slot3();
    virtual void slot4();
    virtual long __stdcall func_00161C20(unsigned int *devices, unsigned int *registered);

    long __stdcall func_00160190(unsigned int *count);
    long __stdcall func_001604E0(unsigned int *count);
    long __stdcall func_00161A90();

    char unknown_04[0x10];
    unsigned int interval;
    unsigned int counter;
    char unknown_1c[8];
    void *inner;
    DeviceList devices;
    RegisteredList registered;
};

// Slot 5: runs 0x160190 and 0x1604E0 (which give the sizes of the two lists) and then 0x161A90, stopping at the first
// failure. 0x800401F1 while +0x24 is null.
long __stdcall MGameInput8::func_00161C20(unsigned int *devices, unsigned int *registered)
{
    if (inner) {
        long result = func_00160190(devices);
        if (result < 0)
            return result;
        result = func_001604E0(registered);
        if (result < 0)
            return result;
        return func_00161A90();
    }
    return 0x800401F1;
}
