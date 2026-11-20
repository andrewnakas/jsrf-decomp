struct Guid;

// The class's interface (the table at 0x1E3F84). The fields follow it at +4, so the 64-bit ones are not padded.
struct FileInterface {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual long __stdcall func_00176800(unsigned __int64 *position);
};

// The class whose table is at 0x1E3F84: the one the MFile2 factory (0x1E3F1C) creates for IID_IUnknown and the
// interface 0x1E3F64. The table at 0x1E406C holds the same function in this slot.
struct Object_001E3F84 : FileInterface {
    virtual long __stdcall func_00176800(unsigned __int64 *position);

    char unknown_04[8];
    void *file;
    unsigned __int64 size;
    unsigned __int64 position;
    char unknown_20[0x18];
    char name[1];
};

// Slot 6: copies the position (+0x18) out when asked; S_FALSE (1) when it is at or past the size (+0x10), else 0.
// 0x800401F0 (not initialised) while the file handle (+0xc) is -1.
long __stdcall Object_001E3F84::func_00176800(unsigned __int64 *position)
{
    if (file != (void *)-1) {
        if (position)
            *position = this->position;
        return this->position < size ? 0 : 1;
    }
    return 0x800401F0;
}
