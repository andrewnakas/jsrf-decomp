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
    virtual long __stdcall func_001675F0(Caps *caps);

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

// Slot 3: copies the 0x2c-byte block at +0x30 out. E_INVALIDARG for a null pointer or a block whose first word is not
// 0x2c, 0x800401F0 (not initialised) without a device (+0x14).
long __stdcall Object_001E3828::func_001675F0(Caps *caps)
{
    if (device) {
        if (caps && caps->size == sizeof(Caps)) {
            *caps = this->caps;
            return 0;
        }
        return 0x80070057;
    }
    return 0x800401F0;
}
