void __cdecl operator delete(void *memory) throw();

struct Guid;

// The objects in MGameInput8's vector at +0x28.
struct Device {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
};

// The objects in MGameInput8's vector at +0x38 (slot 9 adds one, slot 10 gives one out).
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
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual long __stdcall func_00160D80(Registered *registered);

    char unknown_04[0x20];
    void *inner;
    DeviceList devices;
    RegisteredList registered;
};

// Slot 11: lets go of the object (its slot 2) and empties its entry of the vector at +0x38; 0x800710D8 when it is not
// there. A null object lets go of every entry and frees the vector.
long __stdcall MGameInput8::func_00160D80(Registered *object)
{
    if (object) {
        long result = 0x800710D8;
        for (Registered **entry = registered.first, **last = registered.last; entry != last; ++entry) {
            if (*entry == object) {
                if (*entry) {
                    (*entry)->slot2();
                    *entry = 0;
                }
                result = 0;
                break;
            }
        }
        return result;
    }
    for (Registered **entry = registered.first; entry != registered.last; ++entry) {
        if (*entry) {
            (*entry)->slot2();
            *entry = 0;
        }
    }
    if (registered.first)
        operator delete(registered.first);
    registered.first = 0;
    registered.last = 0;
    registered.end = 0;
    return 0;
}
