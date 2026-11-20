struct Guid;

// The objects in the list at +0x40.
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

    void func_0017A330(Listener *const &value);
};

// The class whose table is at 0x1E420C: the one the MThread factory (0x1E4190) creates for the interface 0x1E41A8.
struct Object_001E420C {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual void slot3();
    virtual long __stdcall func_0017BE20(Listener *entry);

    char unknown_04[8];
    void *thread;
    char unknown_10[4];
    int value;
    char unknown_18[0x24];
    void *worker;
    ListenerList list;
};

// Slot 4: appends an object, with a reference, to the list at +0x40 (0x17A330) and then calls slot 6 of the list's
// second entry with 0. E_INVALIDARG for a null object, 0x800401F0 (not initialised) without a thread (+0xc).
long __stdcall Object_001E420C::func_0017BE20(Listener *entry)
{
    if (thread) {
        if (entry) {
            entry->slot1();
            list.func_0017A330(entry);
            list.first[1]->slot6(0);
            return 0;
        }
        return 0x80070057;
    }
    return 0x800401F0;
}
