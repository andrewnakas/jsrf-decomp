struct Guid;

// The controlling object of an aggregate.
struct Unknown;

// The devices in MGameInput8's list at +0x28.
struct Device {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
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

// Slot 16: removes every registered object and every device (slots 11 and 7 with none given), clears +0x48 and
// succeeds.
long __stdcall MGameInput8::func_0015FFB0()
{
    func_00160D80(0);
    func_00160CE0(0);
    unknown_48 = 0;
    return 0;
}
