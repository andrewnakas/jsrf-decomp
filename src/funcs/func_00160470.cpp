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

    unsigned int size() const
    {
        return first == 0 ? 0 : last - first;
    }
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
    virtual void slot9();
    virtual long __stdcall func_00160470(unsigned int index, Registered **entry);

    char unknown_04[0x10];
    unsigned int interval;
    unsigned int counter;
    char unknown_1c[8];
    void *inner;
    DeviceList devices;
    RegisteredList registered;
};

// Slot 10: entry `index` of the list at +0x38, with a reference. E_INVALIDARG for a null pointer or an index past the
// end, 0x800710D8 (with a null result) for an empty entry, 0x800401F0 (not initialised) while +0x24 is null.
long __stdcall MGameInput8::func_00160470(unsigned int index, Registered **entry)
{
    if (inner) {
        if (entry && index < registered.size()) {
            Registered *found = registered.first[index];
            if (found) {
                found->slot1();
                *entry = found;
                return 0;
            }
            *entry = 0;
            return 0x800710D8;
        }
        return 0x80070057;
    }
    return 0x800401F0;
}
