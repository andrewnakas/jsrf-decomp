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
    Device *operator[](unsigned int index) const
    {
        return first[index];
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
    virtual long __stdcall func_001603B0(void *argument1, void *argument2, void *argument3);

    long __stdcall func_00160200(const char *name, unsigned char index, Device **found);
    long __stdcall func_00160270(const Guid *id, unsigned char index, Device **found);
    long __stdcall func_00160310(unsigned long type, unsigned char index, Device **found);

    char unknown_04[0x20];
    void *inner;
    DeviceList devices;
};

// Slot 6: gives out the device at the index in the low byte of the second argument, with a reference added. With a
// key, the index counts only the devices that match it: the second byte says how (1 a name, 2 an identifier, else a
// type). E_INVALIDARG without an out pointer or for an index past the end, 0x800401F0 (not initialised) while +0x24
// is null, 0x800710D8 when there is no device.
long __stdcall MGameInput8::func_001603B0(void *argument1, void *argument2, void *argument3)
{
    if (inner) {
        if (argument3) {
            unsigned int count = devices.size();
            unsigned int index = (unsigned char)(unsigned long)argument2;
            if (index < count) {
                if (argument1) {
                    if ((unsigned char)((unsigned long)argument2 >> 8) == 1)
                        return func_00160200((const char *)argument1, index, (Device **)argument3);
                    if ((unsigned char)((unsigned long)argument2 >> 8) == 2)
                        return func_00160270((const Guid *)argument1, index, (Device **)argument3);
                    return func_00160310((unsigned long)argument1, index, (Device **)argument3);
                }
                Device *device = devices[index];
                if (device) {
                    device->slot1();
                    *(Device **)argument3 = device;
                    return 0;
                }
                *(Device **)argument3 = 0;
                return 0x800710D8;
            }
        }
        return 0x80070057;
    }
    return 0x800401F0;
}
