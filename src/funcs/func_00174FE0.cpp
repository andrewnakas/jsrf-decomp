struct Guid;

// MemStream's first interface: the table at 0x1E3EA8.
struct FirstInterface {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual long __stdcall func_00174FE0(__int64 *position);
};

// MemStream's second interface, at +4: the table at 0x1E3E98.
struct SecondInterface {
    virtual long __stdcall slot0(const Guid &id, void **object);
};

// MemStream, a stream over a block of memory (two interfaces, like MGameSound8).
struct MemStream : FirstInterface, SecondInterface {
    virtual long __stdcall func_00174FE0(__int64 *position);

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

// Slot 7: copies the position (+0x28) out when asked; S_FALSE (1) when it is at or past the length (+0x18), else 0.
// 0x800401F0 (not initialised) before slot 3.
long __stdcall MemStream::func_00174FE0(__int64 *position)
{
    if (mode) {
        if (position)
            *position = this->position;
        return this->position < length ? 0 : 1;
    }
    return 0x800401F0;
}
