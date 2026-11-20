struct Guid;

// The objects in the list at +0x10.
struct Listener {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
};

// A std::vector of pointers.
struct ListenerList {
    char allocator;
    Listener **first;
    Listener **last;
    Listener **end;

    void func_0017A330(Listener *const &value);
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
    virtual long __stdcall func_0017A5C0(Listener *listener);

    void *outer;
    long references;
    void *event;
    ListenerList listeners;
    String name;
};

// Slot 8: appends another object, with a reference, to the list at +0x10 (0x17A330). E_INVALIDARG for a null object or
// the object itself, 0x800401F0 (not initialised) without an event (+0xc).
long __stdcall Object_001E4130::func_0017A5C0(Listener *listener)
{
    if (event) {
        if (listener && listener != (Listener *)this) {
            listener->slot1();
            listeners.func_0017A330(listener);
            return 0;
        }
        return 0x80070057;
    }
    return 0x800401F0;
}
