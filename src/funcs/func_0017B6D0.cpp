struct Guid;

// A block of 0xc bytes: its size, flags, and a word the flags ask for.
struct Info {
    unsigned long size;
    unsigned long flags;
    int value;
};

// The class whose table is at 0x1E41D8: the one the MThread factory (0x1E4190) creates for IID_IUnknown. The table at
// 0x1E420C holds the same function in this slot.
struct Object_001E41D8 {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual long __stdcall func_0017B6D0(Info *info);

    char unknown_04[8];
    void *thread;
    char unknown_10[4];
    int value;
};

// Slot 8: fills in the word at +0x14 when the caller's block (0xc bytes) asks for it with flag 1. Fails with
// 0x800401F0 (not initialised) while there is no thread handle at +0xc, and with E_INVALIDARG for a wrong block.
long __stdcall Object_001E41D8::func_0017B6D0(Info *info)
{
    if (thread) {
        if (info && info->size == sizeof(Info)) {
            if (info->flags & 1)
                info->value = value;
            return 0;
        }
        return 0x80070057;
    }
    return 0x800401F0;
}
