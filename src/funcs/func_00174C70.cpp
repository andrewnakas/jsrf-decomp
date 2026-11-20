struct Guid;

// MemStream's first interface: the table at 0x1E3EA8.
struct FirstInterface {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
};

// MemStream's second interface, at +4: the table at 0x1E3E98.
struct SecondInterface {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual long __stdcall func_00174C70(void **data, unsigned long *length);
};

// MemStream, a stream over a block of memory (two interfaces, like MGameSound8).
struct MemStream : FirstInterface, SecondInterface {
    virtual long __stdcall func_00174C70(void **data, unsigned long *length);

    void *outer;
    long references;
    void *data;
    char unknown_14[4];
    __int64 length;
    unsigned __int64 capacity;
    __int64 position;
    int growable;
    int mode;
};

// The second interface's slot 3: copies the block (+0x10) and the low word of the length (+0x18) out, each when asked.
// 0x800401F0 (not initialised) before slot 3.
long __stdcall MemStream::func_00174C70(void **data, unsigned long *length)
{
    if (mode) {
        if (data)
            *data = this->data;
        if (length)
            *length = (unsigned long)this->length;
        return 0;
    }
    return 0x800401F0;
}
