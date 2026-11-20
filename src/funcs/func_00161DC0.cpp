struct Guid;

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
    virtual long __stdcall slot25();
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
    virtual void slot10();
    virtual void slot11();
    virtual long __stdcall func_00161DC0();

    void *outer;
    long references;
    unsigned long unknown_0c;
    void *context;
    char unknown_14[0x260];
    unsigned char type;
    char unknown_275[0x13b];
    Device *device;
    char unknown_3b4[0x10];
    unsigned long level;
};

// Slot 12: takes the device at +0x3b0 (type 0x13: slot 7) or polls it (other types: slot 25); when that fails, lets
// it go (slot 8), sets it up again with the context and the level at +0x3c4 (slot 13) and retries. 0x800401F0 (not
// initialised) without a device.
long __stdcall Object_001E1968::func_00161DC0()
{
    long result;
    if (device) {
        if (type == 0x13) {
            result = device->slot7();
            if (result < 0) {
                device->slot8();
                device->slot13(context, level);
                return device->slot7();
            }
        } else {
            result = device->slot25();
            if (result < 0) {
                device->slot8();
                device->slot13(context, level);
                result = device->slot7();
                if (result >= 0)
                    return device->slot25();
            }
        }
    } else {
        result = 0x800401F0;
    }
    return result;
}
