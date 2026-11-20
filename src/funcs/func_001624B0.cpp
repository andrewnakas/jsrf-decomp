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
    virtual void slot6();
    virtual long __stdcall slot7();
    virtual long __stdcall slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual long __stdcall slot13(void *argument1, void *argument2);
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
    virtual long __stdcall func_001624B0(void *argument1, void *argument2);

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

// Slot 18: keeps the arguments at +0x10 and +0x3c4 and passes them on to slot 13 of the object at +0x3b0; when that
// fails and its slot 8 works, passes them again and returns its slot 7. 0x800401F0 (not initialised) without the
// object.
long __stdcall Object_001E1968::func_001624B0(void *argument1, void *argument2)
{
    if (inner) {
        value = argument1;
        other = argument2;
        long result = inner->slot13(argument1, argument2);
        if (result < 0) {
            result = inner->slot8();
            if (result >= 0) {
                inner->slot13(value, argument2);
                result = inner->slot7();
            }
        }
        return result;
    }
    return 0x800401F0;
}
