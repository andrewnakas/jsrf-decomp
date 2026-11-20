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
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual long __stdcall slot6(void *argument1, void *argument2);
    virtual long __stdcall slot7();
    virtual long __stdcall slot8();
};

struct EntryList {
    char unknown[0x10];
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
    virtual long __stdcall func_00162520(void *argument1, void *argument2);

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

// Slot 20: passes its arguments on to slot 6 of the object at +0x3b0; when that fails, calls its slot 8, tries slot 6
// again and calls slot 7, returning the second result. 0x800401F0 (not initialised) without the object.
long __stdcall Object_001E1968::func_00162520(void *argument1, void *argument2)
{
    long result;
    if (inner) {
        result = inner->slot6(argument1, argument2);
        if (result < 0) {
            inner->slot8();
            long retried = inner->slot6(argument1, argument2);
            inner->slot7();
            result = retried;
        }
    } else {
        result = 0x800401F0;
    }
    return result;
}
