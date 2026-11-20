struct Guid;

// The objects in MGameInput8's list at +0x28.
struct Device {
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
    virtual long __stdcall slot10();
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

    unsigned int size() const
    {
        return first == 0 ? 0 : last - first;
    }
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

    long __stdcall func_00160190(unsigned int *count);

    char unknown_04[0x10];
    unsigned int interval;
    unsigned int counter;
    char unknown_1c[8];
    void *inner;
    DeviceList devices;
    RegisteredList registered;
};

// Calls slot 10 of every object of the list at +0x28 and stops at the first failure (0x800401F0 (not initialised) while
// +0x24 is null); stores the size of the list when asked.
long __stdcall MGameInput8::func_00160190(unsigned int *count)
{
    long result;
    if (inner) {
        result = 0;
        for (Device **device = devices.first; device != devices.last; ++device) {
            if (*device) {
                result = (*device)->slot10();
                if (result < 0)
                    break;
            }
        }
    } else {
        result = 0x800401F0;
    }
    if (count)
        *count = devices.size();
    return result;
}
