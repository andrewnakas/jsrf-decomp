struct Guid;

// The controlling object of an aggregate.
struct Unknown;

// The devices in MGameInput8's list at +0x28.
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
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual long __stdcall slot25(void *argument);
};

// The objects in the list at +0x38.
struct Registered {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
};

struct Object_001E19E0;
struct Inner;

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

// MGameInput8, the class its factory (table 0x1E185C, after the "MUSASHI.MGameInput8.1" strings) creates.
struct MGameInput8 {
    virtual long __stdcall func_00160080(const Guid &id, void **object);
    virtual unsigned long __stdcall func_00177FE0();
    virtual unsigned long __stdcall func_0015FD40();
    virtual long __stdcall func_0015FF10(void *argument1, void *argument2, void *argument3);
    virtual long __stdcall func_0015FF60(void *argument);
    virtual long __stdcall func_00161C20(unsigned int *first, unsigned int *second);
    virtual long __stdcall func_001603B0(void *argument1, void *argument2, void *argument3);
    virtual long __stdcall func_00160CE0(Device *device);
    virtual long __stdcall func_0015FE60(void *argument, Object_001E19E0 **object);
    virtual long __stdcall func_00161890(Registered *entry);
    virtual long __stdcall func_00160470(unsigned int index, Registered **entry);
    virtual long __stdcall func_00160D80(Registered *entry);
    virtual long __stdcall func_0015FF80();
    virtual long __stdcall func_00160550(void *argument1, void *argument2);
    virtual long __stdcall func_00160610(void *argument);
    virtual long __stdcall func_00161B00(void *argument);
    virtual long __stdcall func_0015FFB0();
    virtual long __stdcall func_0015FFE0(void *argument1, void *argument2);

    Unknown *outer;
    long references;
    unsigned long unknown_0c;
    void *context;
    unsigned int interval;
    unsigned int counter;
    char unknown_1c[8];
    Inner *inner;
    DeviceList devices;
    RegisteredList registered;
    unsigned long unknown_48;
};

// Slot 14: passes the argument on to slot 25 of every device in the list, or fails with 0x800401F0 (not initialised)
// without the inner object.
long __stdcall MGameInput8::func_00160610(void *argument)
{
    if (inner) {
        for (Device **device = devices.first; device != devices.last; ++device) {
            if (*device)
                (*device)->slot25(argument);
        }
        return 0;
    }
    return 0x800401F0;
}
