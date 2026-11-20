struct Guid;

// A block of 0x10 bytes: its size, flags, and the two words the flags ask for (flag 1 the first, flag 2 the
// second).
struct Info {
    unsigned long size;
    unsigned long flags;
    unsigned long first;
    unsigned long second;
};

// The class whose table is at 0x1E3FB0: the one the MFile2 factory (0x1E3F1C) creates for the interface 0x1E3F34.
struct Object_001E3FB0 {
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
    virtual long __stdcall func_001770D0(Info *info);

    char unknown_04[8];
    void *ready;
    unsigned long first;
    unsigned long second;
};

// Slot 11: fills in the words the flags of the given block ask for from +0x10 and +0x14. E_INVALIDARG for a null
// pointer or a block whose first word is not 0x10, 0x800401F0 (not initialised) while +0xc is null.
long __stdcall Object_001E3FB0::func_001770D0(Info *info)
{
    if (ready) {
        if (info && info->size == sizeof(Info)) {
            if (info->flags & 1)
                info->first = first;
            if (info->flags & 2)
                info->second = second;
            return 0;
        }
        return 0x80070057;
    }
    return 0x800401F0;
}
