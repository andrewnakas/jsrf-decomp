struct Guid {
    unsigned long data1;
    unsigned short data2;
    unsigned short data3;
    unsigned char data4[8];
};

// The objects in MGameInput8's vector at +0x28 (the devices found).
struct Device {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();

    char unknown_04[0x38];
    Guid id;
    char unknown_4c[0x108];
    char name[0x120];
    unsigned char type;
};

// A std::vector of pointers.
struct DeviceList {
    unsigned int size() const
    {
        return first == 0 ? 0 : last - first;
    }

    char allocator;
    Device **first;
    Device **last;
    Device **end;
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
    virtual void slot11();
    virtual void slot12();
    virtual long __stdcall func_00160550(void *argument1, void *argument2);

    char unknown_04[0x20];
    void *inner;
    DeviceList devices;
};

// Slot 13: gives out how many devices there are, or with a type (the first argument) how many of that type (2, 3 and
// 4 also count the types 0x12, 0x13 and 0x14 or above). E_INVALIDARG without an out pointer, 0x800401F0 (not
// initialised) while +0x24 is null.
long __stdcall MGameInput8::func_00160550(void *argument1, void *argument2)
{
    if (inner) {
        if (argument2) {
            unsigned long type = (unsigned long)argument1;
            if (type) {
                unsigned int number = 0;
                for (Device **entry = devices.first; entry != devices.last; ++entry) {
                    Device *device = *entry;
                    if (device) {
                        if ((type == 2 && device->type == 0x12) || (type == 3 && device->type == 0x13) ||
                            (type == 4 && device->type >= 0x14) || device->type == type)
                            number++;
                    }
                }
                *(unsigned int *)argument2 = number;
                return 0;
            }
            *(unsigned int *)argument2 = devices.size();
            return 0;
        }
        return 0x80070057;
    }
    return 0x800401F0;
}
