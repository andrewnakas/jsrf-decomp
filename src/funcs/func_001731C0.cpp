struct Guid;

extern "C" char *__cdecl func_0017C750(char *destination, const char *source, unsigned int size);

// The class whose table is at 0x1E3D30: one of the two classes the MRIFFFile factory (0x1E3CD8) creates.
struct Object_001E3D30 {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual long __stdcall func_001731C0(char *buffer, unsigned int size);

    char unknown_04[8];
    void *ready;
    char unknown_10[4];
    char name[1];
};

// Slot 8: copies the name (+0x14) into the given buffer (0x17C750, the C library strncpy) and ends it at the last byte.
// E_INVALIDARG for a null buffer or a size of 0, 0x800401F0 (not initialised) while +0xc is null.
long __stdcall Object_001E3D30::func_001731C0(char *buffer, unsigned int size)
{
    if (ready) {
        if (buffer && size) {
            func_0017C750(buffer, name, size);
            buffer[size - 1] = 0;
            return 0;
        }
        return 0x80070057;
    }
    return 0x800401F0;
}
