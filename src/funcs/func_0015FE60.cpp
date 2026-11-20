/* sym: ??0Object_001E19E0@@QAE@PAUUnknown@@@Z = 0x00164FD0 */
struct Guid;
struct Unknown;
struct MGameInput8;

// The objects in MGameInput8's list at +0x28.
struct Device {
    virtual long __stdcall slot0(const Guid &id, void **object);
};

// The class whose table is at 0x1E19E0: the objects slot 8 makes (0x144 bytes).
struct Object_001E19E0 {
    Object_001E19E0(Unknown *outer);
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual long __stdcall slot3(MGameInput8 *input, void *description);

    char unknown_04[0x140];
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
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual long __stdcall func_0015FE60(void *description, Object_001E19E0 **device);

    char unknown_04[0x10];
    unsigned int interval;
    unsigned int counter;
    char unknown_1c[8];
    void *inner;
    DeviceList devices;
    RegisteredList registered;
};

// Slot 8: makes an object (0x1E19E0, 0x144 bytes, constructor 0x164FD0), has its slot 3 set it up with this object and
// the description, and gives it out with a reference when that works. E_INVALIDARG for a null argument, E_OUTOFMEMORY
// when the allocation fails, 0x800401F0 (not initialised) while +0x24 is null.
long __stdcall MGameInput8::func_0015FE60(void *description, Object_001E19E0 **device)
{
    long result;
    if (inner) {
        if (description && device) {
            *device = 0;
            Object_001E19E0 *created = new Object_001E19E0(0);
            if (!created) {
                result = 0x8007000E;
            } else {
                result = created->slot3(this, description);
                if (result >= 0) {
                    created->slot1();
                    *device = created;
                }
                created->slot2();
            }
        } else {
            result = 0x80070057;
        }
    } else {
        result = 0x800401F0;
    }
    return result;
}
