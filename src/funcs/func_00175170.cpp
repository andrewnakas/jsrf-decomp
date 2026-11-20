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
    virtual void slot7();
    virtual void slot8();
    virtual long __stdcall slot9(const unsigned __int64 &capacity);
    virtual long __stdcall func_00175170(const unsigned __int64 &capacity);
};

// MemStream's second interface, at +4: the table at 0x1E3E98.
struct SecondInterface {
    virtual long __stdcall slot0(const Guid &id, void **object);
};

// MemStream, a stream over a block of memory (two interfaces, like MGameSound8).
struct MemStream : FirstInterface, SecondInterface {
    virtual long __stdcall func_00175170(const unsigned __int64 &capacity);

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

// Slot 10: grows the capacity to the value through slot 9 when it is larger (a tail call); 0x800401F0 (not initialised)
// before slot 3.
long __stdcall MemStream::func_00175170(const unsigned __int64 &capacity)
{
    if (mode) {
        if (capacity > this->capacity)
            return slot9(capacity);
        return 0;
    }
    return 0x800401F0;
}
