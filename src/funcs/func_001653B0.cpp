struct Guid;

extern "C" char *__cdecl func_0017C750(char *destination, const char *source, unsigned int size);

// The class whose table is at 0x1E1FE4.
struct Object_001E1FE4 {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual void slot3();
    virtual void slot4();
    virtual long __stdcall func_001653B0(char *buffer, unsigned int size);

    char unknown_04[0x30];
    char name[1];
};

// Slot 5: copies the name (+0x34) into the given buffer (0x17C750, the C library strncpy, for all but the last byte)
// and ends it at the last byte. E_INVALIDARG for a null buffer or a size of 0.
long __stdcall Object_001E1FE4::func_001653B0(char *buffer, unsigned int size)
{
    if (buffer && size) {
        if (size > 1)
            func_0017C750(buffer, name, size - 1);
        buffer[size - 1] = 0;
        return 0;
    }
    return 0x80070057;
}
