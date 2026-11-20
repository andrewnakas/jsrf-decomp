struct Guid;

// The system library's string copy.
char *__stdcall func_00148126(char *destination, const char *source);

// The objects in the list at +0x10.
struct Listener {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
};

// A std::vector of pointers.
struct ListenerList {
    char allocator;
    Listener **first;
    Listener **last;
    Listener **end;
};

// The name at +0x20 (a std::string: the characters live in the 16-byte buffer while they fit).
struct String {
    char allocator;
    union {
        char buffer[16];
        char *pointer;
    } text;
    unsigned int size;
    unsigned int reserved;
};

// The class whose table is at 0x1E4130: the one the MEvent factory (0x1E40C4) creates for the interface 0x1E40DC.
struct Object_001E4130 {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual long __stdcall func_00179C20(char *buffer, unsigned int size);

    void *outer;
    long references;
    void *event;
    ListenerList listeners;
    String name;
};

// Slot 11: copies the name (+0x20) into the given buffer (0x148126). E_INVALIDARG for a null buffer or a size of 0,
// 0x80028016 for a buffer shorter than the name.
long __stdcall Object_001E4130::func_00179C20(char *buffer, unsigned int size)
{
    if (buffer && size) {
        if (size >= name.size) {
            func_00148126(buffer, name.reserved >= 16 ? name.text.pointer : name.text.buffer);
            return 0;
        }
        return 0x80028016;
    }
    return 0x80070057;
}
