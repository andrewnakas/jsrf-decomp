void __cdecl operator delete(void *memory) throw();

struct Guid;

// The objects in the list at +0x10 (slot 2 lets go of one).
struct Listener {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
};

// A std::vector of pointers.
struct ListenerList {
    // Frees the block and leaves the vector empty.
    void tidy()
    {
        if (first)
            operator delete(first);
        first = 0;
        last = 0;
        end = 0;
    }

    char allocator;
    Listener **first;
    Listener **last;
    Listener **end;
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
    virtual long __stdcall func_00179DB0(Listener *listener);

    void *outer;
    long references;
    void *event;
    ListenerList listeners;
};

// Slot 10: takes an object out of the list at +0x10 (releases it and clears its place); 0x80004005 (E_FAIL) when it
// is not there. Without an object, releases every object of the list and frees the list.
long __stdcall Object_001E4130::func_00179DB0(Listener *listener)
{
    long result;
    if (listener) {
        result = 0x80004005;
        for (Listener **entry = listeners.first; entry != listeners.last; ++entry) {
            if (*entry == listener) {
                if (*entry) {
                    (*entry)->slot2();
                    *entry = 0;
                }
                result = 0;
                break;
            }
        }
    } else {
        for (Listener **entry = listeners.first; entry != listeners.last; ++entry) {
            if (*entry) {
                (*entry)->slot2();
                *entry = 0;
            }
        }
        listeners.tidy();
        result = 0;
    }
    return result;
}
