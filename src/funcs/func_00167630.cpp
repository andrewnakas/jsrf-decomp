struct Guid;

// The block slot 3 copies out (0x2c bytes, its size first).
struct Caps {
    unsigned long size;
    unsigned long words[10];
};

// The block slot 15 copies out (0x244 bytes, its size first).
struct State {
    unsigned long size;
    unsigned long words[0x90];
};

// The block slot 11 copies in (0x18 bytes, its size first); +0xc is the size of the data slot 9 copies out.
struct Format {
    unsigned long size;
    unsigned long unknown_04[2];
    unsigned long dataSize;
    unsigned long unknown_10[2];
};

// The class whose table is at 0x1E3828 (33 slots; the destructor is the last).
struct Object_001E3828 {
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
    virtual long __stdcall func_00167630(State *state);

    char unknown_04[0x10];
    void *device;
    void *buffer;
    unsigned long last;
    char unknown_20[0x10];
    Caps caps;
    State state;
    Format format;
    char unknown_2b8[0x1c];
    char data[1];
};

// Slot 15: copies the 0x244-byte block at +0x5c out. E_INVALIDARG for a null pointer or a block whose first word is not
// 0x244, 0x800401F0 (not initialised) without a device (+0x14).
long __stdcall Object_001E3828::func_00167630(State *state)
{
    if (device) {
        if (state && state->size == sizeof(State)) {
            *state = this->state;
            return 0;
        }
        return 0x80070057;
    }
    return 0x800401F0;
}
