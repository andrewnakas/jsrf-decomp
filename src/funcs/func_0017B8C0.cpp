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
};

// A block of 0xc bytes: its size, flags, and a word the flags ask for.
struct Info {
    unsigned long size;
    unsigned long flags;
    int value;
};

// The class whose table is at 0x1E420C: the one the MThread factory (0x1E4190) creates for the interface 0x1E41A8.
struct Object_001E420C {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual long __stdcall func_0017B8C0(const Info *info);

    char unknown_04[8];
    void *thread;
    char unknown_10[4];
    int value;
    char unknown_18[0x24];
    void *worker;
    ListenerList list;
};

// Slot 7: takes the word at +0x14 from the caller's block when its flags ask for it (flag 1) and then calls slot 6 of
// the second entry of the list at +0x40 with 0. E_INVALIDARG for a null pointer or a block whose first word is not 0xc,
// 0x800401F0 (not initialised) without a thread (+0xc).
long __stdcall Object_001E420C::func_0017B8C0(const Info *info)
{
    if (thread) {
        if (info && info->size == sizeof(Info)) {
            if (info->flags & 1) {
                value = info->value;
                list.first[1]->slot6(0);
            }
            return 0;
        }
        return 0x80070057;
    }
    return 0x800401F0;
}
