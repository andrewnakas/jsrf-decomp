struct Guid;
struct Unknown;

// What the device gives out into +0x91c (0x2c bytes): the kind is at +8.
struct Description {
    unsigned long unknown_0;
    unsigned long unknown_4;
    unsigned long kind;
    char unknown_0c[0x20];
};

// What the device's slot 24 gives out (0x18 bytes): the word at +0xc is kept at +0x914.
struct Status {
    unsigned long unknown_0[3];
    unsigned long value;
    unsigned long unknown_10[2];
};

// The device the object is opened on.
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
    virtual long __stdcall slot23(unsigned long *first, Description *description);
    virtual long __stdcall slot24(Status *status);
};

// Gives the size for a kind of object (0x1655A0).
long __stdcall func_001655A0(unsigned long kind, unsigned int *size);

// The class whose table is at 0x1E2008 (0x950 bytes).
struct Object_001E2008 {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual long __stdcall func_001655E0(void *argument);

    Unknown *outer;
    long references;
    Device *device;
    unsigned long first;
    char table1[0x100];
    char table2[0x400];
    char table3[0x400];
    unsigned long second;
    unsigned int third;
    Description description;
};

// Slot 3: opens the object on a device: has it fill +0x10 and the description at +0x91c (slot 23), keeps the word at
// +0xc of what its slot 24 gives out at +0x914 and the size for the description's kind (0x1655A0) at +0x918, and keeps
// the device at +0xc when all of that works. 0x800401F1 when it is already open, 0x80070057 (E_INVALIDARG) without a
// device.
long __stdcall Object_001E2008::func_001655E0(void *argument)
{
    if (device)
        return 0x800401F1;
    long result;
    Device *opened = (Device *)argument;
    if (opened) {
        result = opened->slot23(&first, &description);
        if (result >= 0) {
            Status status;
            result = opened->slot24(&status);
            if (result >= 0) {
                second = status.value;
                result = func_001655A0(description.kind, &third);
                if (result >= 0)
                    device = opened;
            }
        }
    } else {
        result = 0x80070057;
    }
    return result;
}
