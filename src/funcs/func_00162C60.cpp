struct Guid;

// What slot 4 of the object at +0x20 fills (0x1c bytes).
struct Frame {
    unsigned long unknown_00[3];
    unsigned char *values;
    unsigned long offset;
    unsigned long unknown_14[2];
};

// The object at +0x20.
struct Source {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual void slot3();
    virtual long __stdcall slot4(Frame *frame);
    virtual long __stdcall slot5(void *state);
};

// The input device at +0x3b0.
struct Device {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual long __stdcall slot7();
    virtual long __stdcall slot8();
    virtual long __stdcall slot9(unsigned long size, void *state);
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual long __stdcall slot13(void *context, unsigned long level);
};

// The objects in the vectors at +0x3c8 and +0x3d8.
struct Entry {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual long __stdcall slot6(unsigned long value, unsigned long where);

    char unknown_04[0x24];
    long index;
    unsigned long flags;
};

// A std::vector of pointers.
struct EntryList {
    char allocator;
    Entry **first;
    Entry **last;
    Entry **end;
};

// The class whose table is at 0x1E1968 (29 slots; the destructor is the last).
struct Object_001E1968 {
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
    virtual long __stdcall func_00162C60();

    long __stdcall func_00162BC0();

    void *outer;
    long references;
    unsigned long unknown_0c;
    void *context;
    char unknown_14[8];
    unsigned char **tables;
    Source *source;
    char unknown_24[0x280];
    unsigned long stateSize;
    char unknown_2a8[8];
    unsigned long state[0x40];
    Device *device;
    char unknown_3b4[0x10];
    unsigned long level;
    EntryList first;
    EntryList second;
};

// Slot 10: reads the device state into +0x2b0 (slot 9 of the device at +0x3b0); when that fails, takes the device
// back (slots 8, 13 with the context and the level at +0x3c4, 7) and reads again. Then hands the state to the object at
// +0x20 (its slot 5) and, when that succeeds, updates the entries (0x162BC0). 0x800401F0 (not initialised) without a
// device.
long __stdcall Object_001E1968::func_00162C60()
{
    if (device) {
        long result;
        if (device->slot9(stateSize, state) < 0) {
            device->slot8();
            result = device->slot13(context, level);
            device->slot7();
            if (result >= 0)
                result = device->slot9(stateSize, state);
            else
                device->slot8();
            if (result < 0)
                goto done;
        }
        result = source->slot5(state);
        if (result >= 0)
            func_00162BC0();
    done:
        return result;
    }
    return 0x800401F0;
}
