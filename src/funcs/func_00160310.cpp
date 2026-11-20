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
    virtual long __stdcall func_001603B0(void *argument1, void *argument2, void *argument3);

    long __stdcall func_00160200(const char *name, unsigned char index, Device **found);
    long __stdcall func_00160270(const Guid *id, unsigned char index, Device **found);
    long __stdcall func_00160310(unsigned long type, unsigned char index, Device **found);

    char unknown_04[0x20];
    void *inner;
    DeviceList devices;
};

// Finds the device at `index` among those of the type `type` (any type for 0; 2, 3 and 4 also take the types 0x12,
// 0x13 and 0x14 or above) and gives it out with a reference added (a null object and 0x800710D8 when there is none).
long __stdcall MGameInput8::func_00160310(unsigned long type, unsigned char index, Device **found)
{
    long result = 0x800710D8;
    unsigned int number = 0;
    *found = 0;
    for (Device **entry = devices.first; entry != devices.last; entry++) {
        Device *device = *entry;
        if (device) {
            if (!type || (type == 2 && device->type == 0x12) || (type == 3 && device->type == 0x13) ||
                (type == 4 && device->type >= 0x14) || device->type == type) {
                if (number == index) {
                    device->slot1();
                    *found = device;
                    result = 0;
                    break;
                }
                number++;
            }
        }
    }
    return result;
}
