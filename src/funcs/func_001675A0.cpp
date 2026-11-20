struct Guid;
extern "C" void *__cdecl memcpy(void *destination, const void *source, unsigned int size);

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
    virtual long __stdcall func_001675A0(unsigned long size, void *data);

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

// Slot 9: copies the data at +0x2d4 out; the size must be the one the block at +0x2a0 gives (+0x2ac), else
// E_INVALIDARG. 0x800401F0 (not initialised) without a device (+0x14).
long __stdcall Object_001E3828::func_001675A0(unsigned long size, void *data)
{
    if (device) {
        if (size == format.dataSize) {
            memcpy(data, this->data, format.dataSize);
            return 0;
        }
        return 0x80070057;
    }
    return 0x800401F0;
}
