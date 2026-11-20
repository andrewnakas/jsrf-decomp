/* sym: ??1MGameInput8@@UAE@XZ = 0x00160C30 */
extern "C" long __cdecl _InterlockedIncrement(long volatile *addend);
extern "C" long __cdecl _InterlockedDecrement(long volatile *addend);
void __cdecl operator delete(void *memory) throw();

struct Guid;

// The controlling object of an aggregate.
struct Unknown {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
};

struct Device;
struct Registered;
struct Object_001E19E0;

// A std::vector of pointers: empty when made, its block freed when destroyed.
struct DeviceList {
    DeviceList()
    {
        first = 0;
        last = 0;
        end = 0;
    }
    ~DeviceList()
    {
        if (first)
            operator delete(first);
        first = 0;
        last = 0;
        end = 0;
    }

    char allocator;
    Device **first;
    Device **last;
    Device **end;
};

// A std::vector of pointers, the same way.
struct RegisteredList {
    RegisteredList()
    {
        first = 0;
        last = 0;
        end = 0;
    }
    ~RegisteredList()
    {
        if (first)
            operator delete(first);
        first = 0;
        last = 0;
        end = 0;
    }

    char allocator;
    Registered **first;
    Registered **last;
    Registered **end;
};

// The controlling object's inner object at +0x24.
struct Inner {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
};

// The number of live objects of the library's input classes.
extern long data_0026517C;

// MGameInput8, the class its factory (table 0x1E185C, next to the "MUSASHI.MGameInput8.1" strings) creates; its table
// is at 0x1E1900 (0x4c bytes).
struct MGameInput8 {
    MGameInput8(Unknown *outer);
    virtual long __stdcall func_00160080(const Guid &id, void **object);
    virtual unsigned long __stdcall func_00177FE0();
    virtual unsigned long __stdcall func_0015FD40();
    virtual long __stdcall func_0015FF10(void *argument1, void *argument2, void *argument3);
    virtual long __stdcall func_0015FF60(void *argument);
    virtual long __stdcall func_00161C20(unsigned int *argument1, unsigned int *argument2);
    virtual long __stdcall func_001603B0(void *argument1, void *argument2, void *argument3);
    virtual long __stdcall func_00160CE0(Device *device);
    virtual long __stdcall func_0015FE60(void *argument, Object_001E19E0 **object);
    virtual long __stdcall func_00161890(Registered *registered);
    virtual long __stdcall func_00160470(unsigned int index, Registered **registered);
    virtual long __stdcall func_00160D80(Registered *registered);
    virtual long __stdcall func_0015FF80();
    virtual long __stdcall func_00160550(void *argument1, void *argument2);
    virtual long __stdcall func_00160610(void *argument);
    virtual long __stdcall func_00161B00(void *argument);
    virtual long __stdcall func_0015FFB0();
    virtual long __stdcall func_0015FFE0(void *argument1, void *argument2);
    virtual ~MGameInput8();

    // Lets go of the registered objects (slot 11) and the devices (slot 7) and of the inner object. Inlined into
    // the destructor, where its calls stay virtual: retail calls slot 11 through the table (0x1E192C).
    void close()
    {
        func_00160D80(0);
        func_00160CE0(0);
        unknown_48 = 0;
        if (inner) {
            inner->slot2();
            inner = 0;
        }
    }

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

// Destructor: closes the object (the registered objects, the devices, +0x48 and the inner object), lets go of the
// controlling object and counts the object out; the two lists free their blocks.
MGameInput8::~MGameInput8()
{
    close();
    if (outer) {
        outer->slot2();
        outer = 0;
    }
    _InterlockedDecrement(&data_0026517C);
}
