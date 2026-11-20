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
    virtual void slot21();
    virtual long __stdcall func_00162900(int count, void *argument1, void *argument2);
    long __stdcall func_001625A0(int count, void *argument1, void *argument2);
    long __stdcall func_001625F0(int count, void *argument1, void *argument2);
    long __stdcall func_001626C0(int count, void *argument1, void *argument2);

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

// Slot 22: passes its arguments on (tail calls) by the kind byte at +0x274: 0x1625F0 for 0x12, 0x1625A0 for 0x13,
// 0x1626C0 for any other. 0x800710D8 for a count below 1, 0x800401F0 (not initialised) without the object at +0x3b0.
long __stdcall Object_001E1968::func_00162900(int count, void *argument1, void *argument2)
{
    if (inner) {
        if (count > 0) {
            switch (caps.kind) {
            case 0x12:
                return func_001625F0(count, argument1, argument2);
            case 0x13:
                return func_001625A0(count, argument1, argument2);
            default:
                return func_001626C0(count, argument1, argument2);
            }
        }
        return 0x800710D8;
    }
    return 0x800401F0;
}
