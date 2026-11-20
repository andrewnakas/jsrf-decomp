/* sym: ??0Object_001E3828@@QAE@PAUUnknown@@@Z = 0x00167D60 */
extern "C" long __cdecl _InterlockedIncrement(long volatile *addend);
extern "C" long __cdecl _InterlockedDecrement(long volatile *addend);
extern "C" void *__cdecl memset(void *destination, int value, unsigned int size);

struct Guid;

// The controlling object of an aggregate.
struct Unknown {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
};

// What slot 3 gives out (0x2c bytes, its size first).
struct Caps {
    unsigned long size;
    unsigned long words[10];
};

// What slot 15 gives out (0x244 bytes, its size first).
struct State {
    unsigned long size;
    unsigned long words[0x90];
};

// What slot 11 takes (0x18 bytes, its size first).
struct Format {
    unsigned long size;
    unsigned long unknown_04[2];
    unsigned long dataSize;
    unsigned long unknown_10[2];
};

struct Buffer;

// The input device library's close (0x1C3C16).
int __stdcall func_001C3C16(void *device);

// The number of live DirectInput8 objects and devices.
extern long data_00265188;

// The class whose table is at 0x1E3828: a DirectInput8 device (0x480 bytes).
struct Object_001E3828 {
    Object_001E3828(Unknown *outer);
    virtual long __stdcall func_00167CD0(const Guid &id, void **object);
    virtual unsigned long __stdcall func_00177FE0();
    virtual unsigned long __stdcall func_00166CA0();
    virtual long __stdcall func_001675F0(Caps *caps);
    virtual long __stdcall func_00167110(void *argument1, void *argument2, void *argument3);
    virtual long __stdcall func_001676B0(void *argument1, void *argument2);
    virtual long __stdcall func_001678F0(void *argument1, void *argument2);
    virtual long __stdcall func_00167C90();
    virtual long __stdcall func_00167C90_1();
    virtual long __stdcall func_001675A0(unsigned long size, void *data);
    virtual long __stdcall func_00167CC0(void *argument1, void *argument2, unsigned long argument3, void *argument4);
    virtual long __stdcall func_00167670(const Format *format);
    virtual long __stdcall func_00167C30(void *event);
    virtual long __stdcall func_00167C50(void *argument1, unsigned long argument2);
    virtual long __stdcall func_00167C70(void *argument1, unsigned long argument2, unsigned long argument3);
    virtual long __stdcall func_00167630(State *state);
    virtual long __stdcall func_00167CB0(void *argument1, unsigned long argument2);
    virtual long __stdcall func_001670B0(void *, unsigned long version, const Buffer *buffer);
    virtual long __stdcall func_00167CC0_1(void *argument1, void *argument2, unsigned long argument3, void *argument4);
    virtual long __stdcall func_001526D0(void *argument1, void *argument2, void *argument3);
    virtual long __stdcall func_00167CB0_1(void *argument1, unsigned long argument2);
    virtual long __stdcall func_001504B0(void *argument);
    virtual long __stdcall func_001504B0_1(void *argument);
    virtual long __stdcall func_001526D0_1(void *argument1, void *argument2, void *argument3);
    virtual long __stdcall func_001504B0_2(void *argument);
    virtual long __stdcall func_00167180();
    virtual long __stdcall func_00167CC0_2(void *argument1, void *argument2, unsigned long argument3, void *argument4);
    virtual long __stdcall func_00167CC0_3(void *argument1, void *argument2, unsigned long argument3, void *argument4);
    virtual long __stdcall func_00167CC0_4(void *argument1, void *argument2, unsigned long argument3, void *argument4);
    virtual long __stdcall func_001526D0_2(void *argument1, void *argument2, void *argument3);
    virtual long __stdcall func_001526D0_3(void *argument1, void *argument2, void *argument3);
    virtual long __stdcall func_001504B0_3(void *argument);

    // Closes the device, lets go of the controlling object and counts the object out (inlined into the deleting
    // destructor, 0x167E20).
    virtual __forceinline ~Object_001E3828()
    {
        if (device)
            func_001C3C16(device);
        if (outer) {
            outer->slot2();
            outer = 0;
        }
        _InterlockedDecrement(&data_00265188);
    }

    Unknown *outer;
    long references;
    unsigned long unknown_0c;
    unsigned long unknown_10;
    void *device;
    void *buffer;
    unsigned long last;
    unsigned long unknown_20;
    unsigned long unknown_24;
    void *event;
    long status;
    Caps caps;
    State state;
    Format format;
    unsigned char keys[0x19];
    unsigned long data[0x28];
    unsigned long unknown_374[0x20];
    unsigned long unknown_3f4[0x23];
};

// Constructor: one reference, no device, buffer or event, the status 0x800401F0 (not initialised) and every block
// zero; holds a reference to the controlling object, if any, and counts the object in.
Object_001E3828::Object_001E3828(Unknown *outer)
{
    this->outer = outer;
    references = 1;
    unknown_0c = 0;
    unknown_10 = 0;
    device = 0;
    buffer = 0;
    last = 0;
    unknown_20 = 0;
    unknown_24 = 0;
    event = 0;
    status = 0x800401F0;
    if (outer)
        outer->slot1();
    memset(&state, 0, sizeof(state));
    memset(&caps, 0, sizeof(caps));
    memset(&format, 0, sizeof(format));
    memset(keys, 0, sizeof(keys));
    memset(data, 0, sizeof(data));
    memset(unknown_374, 0, sizeof(unknown_374));
    memset(unknown_3f4, 0, sizeof(unknown_3f4));
    _InterlockedIncrement(&data_00265188);
}
