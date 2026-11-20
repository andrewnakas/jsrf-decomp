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
};

// A block of 0xc bytes: its size, flags, and a word the flags ask for.
struct Info {
    unsigned long size;
    unsigned long flags;
    int value;
};

// The class whose table is at 0x1E41D8: the one the MThread factory (0x1E4190) creates for IID_IUnknown.
struct Object_001E41D8 {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual long __stdcall func_0017AB70(const Info *info);

    char unknown_04[8];
    void *thread;
    char unknown_10[4];
    int value;
    char unknown_18[0x24];
    void *worker;
    ClientList list;
};

// Slot 7: takes the word at +0x14 from the caller's block when its flags ask for it (flag 1) and then calls slot 6 of
// the second entry of the list at +0x40. E_INVALIDARG for a null pointer or a block whose first word is not 0xc,
// 0x800401F0 (not initialised) without a thread (+0xc).
long __stdcall Object_001E41D8::func_0017AB70(const Info *info)
{
    if (thread) {
        if (info && info->size == sizeof(Info)) {
            if (info->flags & 1) {
                value = info->value;
                list.first[1]->slot6();
            }
            return 0;
        }
        return 0x80070057;
    }
    return 0x800401F0;
}
