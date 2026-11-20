struct Guid;

// The blocks the object keeps (each with its size first): 0x244 bytes at +0x28, 0x2c bytes at +0x26c (its byte at
// +8 is the kind) and 0x18 bytes at +0x298.
struct State {
    unsigned long size;
    unsigned long words[0x90];
};

struct Caps {
    unsigned long size;
    unsigned long unknown_04;
    unsigned char kind;
    char unknown_09[3];
    unsigned long words[8];
};

struct Format {
    unsigned long size;
    unsigned long words[5];
};

// The object at +0x3b0.
struct Inner {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
};

struct EntryList {
    char unknown[0x10];
};

// A property block (0x14 bytes): its size, the header size, the object, how to read it, and the value.
struct Property {
    unsigned long size;
    unsigned long header;
    unsigned long object;
    unsigned long how;
    unsigned long value;
};

// The class whose table is at 0x1E1968.
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
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual long __stdcall slot21(unsigned long property, Property *value);
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual long __stdcall func_00161F80(unsigned long *value);

    char unknown_04[0xc];
    void *value;
    char unknown_14[0x14];
    State state;
    Caps caps;
    Format format;
    char unknown_2b0[0x100];
    Inner *inner;
    char unknown_3b4[0x10];
    void *other;
    EntryList first;
    EntryList second;
};

// Slot 27: reads property 3 through slot 21 with a 0x14-byte block (header 0x10, object 8, kind 1) and copies its value
// out when that works. E_INVALIDARG for a null pointer, 0x800401F0 (not initialised) without the object at +0x3b0.
long __stdcall Object_001E1968::func_00161F80(unsigned long *value)
{
    long result;
    if (inner) {
        if (value) {
            Property property;
            property.size = sizeof(Property);
            property.header = 0x10;
            property.object = 8;
            property.how = 1;
            result = slot21(3, &property);
            if (result >= 0)
                *value = property.value;
        } else {
            result = 0x80070057;
        }
    } else {
        result = 0x800401F0;
    }
    return result;
}
