struct Guid;

// The objects in the list at +0x40.
struct Client {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual long __stdcall slot6();
};

// A std::vector of pointers.
struct ClientList {
    char allocator;
    Client **first;
    Client **last;
    Client **end;

    void func_0017B1E0(Client *const &value);
};

// The class whose table is at 0x1E41D8: the one the MThread factory (0x1E4190) creates for IID_IUnknown.
struct Object_001E41D8 {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual void slot3();
    virtual long __stdcall func_0017B580(Client *entry);

    char unknown_04[8];
    void *thread;
    char unknown_10[4];
    int value;
    char unknown_18[0x24];
    void *worker;
    ClientList list;
};

// Slot 4: appends an object, with a reference, to the list at +0x40 (0x17B1E0) and then calls slot 6 of the list's
// second entry. E_INVALIDARG for a null object, 0x800401F0 (not initialised) without a thread (+0xc).
long __stdcall Object_001E41D8::func_0017B580(Client *entry)
{
    if (thread) {
        if (entry) {
            entry->slot1();
            list.func_0017B1E0(entry);
            list.first[1]->slot6();
            return 0;
        }
        return 0x80070057;
    }
    return 0x800401F0;
}
