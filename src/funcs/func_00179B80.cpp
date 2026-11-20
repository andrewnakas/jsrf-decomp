struct Guid;

// The system library's event function.
int __stdcall func_00145B26(void *event);

// The objects in the list at +0x10.
struct Listener {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual long __stdcall slot6(int all);
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
    virtual long __stdcall func_00179B80(int all);

    void *outer;
    long references;
    void *event;
    ListenerList listeners;
    String name;
};

// Slot 6: sets the event at +0xc (0x145B26) and, for 1, calls slot 6 of every object of the list at +0x10 with 1.
// 0x800401F0 (not initialised) without an event.
long __stdcall Object_001E4130::func_00179B80(int all)
{
    if (event) {
        func_00145B26(event);
        if (all == 1) {
            for (Listener **listener = listeners.first; listener != listeners.last; ++listener) {
                if (*listener)
                    (*listener)->slot6(1);
            }
        }
        return 0;
    }
    return 0x800401F0;
}
