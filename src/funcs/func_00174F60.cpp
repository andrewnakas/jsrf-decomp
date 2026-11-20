struct Guid;

// MemStream's first interface: the table at 0x1E3EA8.
struct FirstInterface {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual long __stdcall func_00174F60(void *argument1, void *argument2);
};

// MemStream's second interface, at +4: the table at 0x1E3E98.
struct SecondInterface {
    virtual long __stdcall slot0(const Guid &id, void **object);
};

// MemStream, a stream over a block of memory (two interfaces, like MGameSound8).
struct MemStream : FirstInterface, SecondInterface {
    virtual long __stdcall func_00174F60(void *argument1, void *argument2);

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

// Slot 6: moves the position to the offset from the start (origin 0) or from the position (1), never before the
// start. 0x80070057 (E_INVALIDARG) for any other origin, 0x800401F0 (not initialised) before slot 3.
long __stdcall MemStream::func_00174F60(void *argument1, void *argument2)
{
    if (mode) {
        if ((int)argument2 == 0) {
            position = (long)argument1;
            if (position < 0)
                position = 0;
            return 0;
        }
        if ((int)argument2 == 1) {
            position += (long)argument1;
            if (position < 0)
                position = 0;
            return 0;
        }
        return 0x80070057;
    }
    return 0x800401F0;
}
