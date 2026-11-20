struct Guid;

extern "C" char *__cdecl func_0017C750(char *destination, const char *source, unsigned int size);

// The class's interface (the table at 0x1E3F84). The fields follow it at +4, so the 64-bit ones are not padded.
struct FileInterface {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual long __stdcall func_001791C0(char *buffer, unsigned int size);
};

// The class whose table is at 0x1E3F84: the one the MFile2 factory (0x1E3F1C) creates for IID_IUnknown and the
// interface 0x1E3F64. The table at 0x1E406C holds the same function in this slot.
struct Object_001E3F84 : FileInterface {
    virtual long __stdcall func_001791C0(char *buffer, unsigned int size);

    char unknown_04[8];
    void *file;
    unsigned __int64 size;
    unsigned __int64 position;
    char unknown_20[0x18];
    char name[1];
};

// Slot 8: copies the name (+0x38) into the given buffer (0x17C750, the C library strncpy) and ends it at the last byte.
// E_INVALIDARG for a null buffer or a size of 0, 0x800401F0 (not initialised) while the file handle (+0xc) is -1.
long __stdcall Object_001E3F84::func_001791C0(char *buffer, unsigned int size)
{
    if (file != (void *)-1) {
        if (buffer && size) {
            func_0017C750(buffer, name, size);
            buffer[size - 1] = 0;
            return 0;
        }
        return 0x80070057;
    }
    return 0x800401F0;
}
