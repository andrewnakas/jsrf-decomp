struct Guid;

// The class's interface (the table at 0x1E3F84). The fields follow it at +4, so the 64-bit ones are not padded.
struct FileInterface {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual void slot3();
    virtual void slot4();
    virtual long __stdcall func_00178D80(long offset, int origin);
};

// The class whose table is at 0x1E3F84: the one the MFile2 factory (0x1E3F1C) creates for IID_IUnknown and the
// interface 0x1E3F64. The table at 0x1E406C holds the same function in this slot.
struct Object_001E3F84 : FileInterface {
    virtual long __stdcall func_00178D80(long offset, int origin);

    char unknown_04[8];
    void *file;
    unsigned __int64 size;
    unsigned __int64 position;
    char unknown_20[0x18];
    char name[1];
};

// Slot 5: moves the 64-bit position (+0x18) to the offset from the start (origin 0), from the position (1) or from the
// size (+0x10, 2). E_INVALIDARG for any other origin, 0x800401F0 (not initialised) while the file handle (+0xc) is -1.
long __stdcall Object_001E3F84::func_00178D80(long offset, int origin)
{
    if (file != (void *)-1) {
        if (origin == 0) {
            position = offset;
            return 0;
        }
        if (origin == 1) {
            position += offset;
            return 0;
        }
        if (origin == 2) {
            position = size + offset;
            return 0;
        }
        return 0x80070057;
    }
    return 0x800401F0;
}
