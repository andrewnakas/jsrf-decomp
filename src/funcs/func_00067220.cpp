extern "C" void *memset(void *to, int value, unsigned int size);

// A 16-byte identifier.
struct Guid_00067220 {
    unsigned int data[4];
};

extern const Guid_00067220 data_001E1874;

// A range property (0x18 bytes): its size, the header's size, the object, how it is named, and the range.
struct Range_00067220 {
    unsigned int size;
    unsigned int headerSize;
    int object;
    int how;
    int low;
    int high;
};

// An input device: slot 20 sets a property.
struct Device_00067220 {
    virtual long __stdcall slot0();
    virtual long __stdcall slot1();
    virtual long __stdcall slot2();
    virtual long __stdcall slot3();
    virtual long __stdcall slot4();
    virtual long __stdcall slot5();
    virtual long __stdcall slot6();
    virtual long __stdcall slot7();
    virtual long __stdcall slot8();
    virtual long __stdcall slot9();
    virtual long __stdcall slot10();
    virtual long __stdcall slot11();
    virtual long __stdcall slot12();
    virtual long __stdcall slot13();
    virtual long __stdcall slot14();
    virtual long __stdcall slot15();
    virtual long __stdcall slot16();
    virtual long __stdcall slot17();
    virtual long __stdcall slot18();
    virtual long __stdcall slot19();
    virtual long __stdcall slot20(const Guid_00067220 *property, Range_00067220 *range);
};

// The object at 0x251F2C: four slots, each a pointer to a frame count and the time spent in it, and the range each
// slot last set.
struct Object_00067030 {
    unsigned int *values[4];
    float times[4];
    unsigned int ranges[4];

    unsigned int func_00067090(int slot);
    void func_000671D0(int slot);
    void func_00067220(int slot, int object, Device_00067220 *device);
};

// While the slot runs, hands the device the range for its current frame (func_00067090: high word low end, low word
// high end) when it changed, then steps the slot (func_000671D0); once it stops, clears the device's range once.
void Object_00067030::func_00067220(int slot, int object, Device_00067220 *device)
{
    if (values[slot]) {
        unsigned int range = func_00067090(slot);
        if (range != ranges[slot]) {
            Range_00067220 property;
            memset(&property, 0, sizeof(property));
            property.size = sizeof(Range_00067220);
            property.headerSize = 0x10;
            property.object = object;
            property.how = 0;
            property.low = range >> 16;
            property.high = range & 0xffff;
            device->slot20(&data_001E1874, &property);
            ranges[slot] = range;
        }
        func_000671D0(slot);
    } else if (ranges[slot]) {
        Range_00067220 property;
        memset(&property, 0, sizeof(property));
        property.size = sizeof(Range_00067220);
        property.headerSize = 0x10;
        property.object = object;
        property.how = 0;
        property.low = 0;
        property.high = 0;
        device->slot20(&data_001E1874, &property);
        ranges[slot] = 0;
    }
}
