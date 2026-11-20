struct Guid;

// The object at +0xc (slot 4 takes the call on).
struct Inner {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual void slot3();
    virtual long __stdcall slot4(void *argument1, void *argument2, void *argument3, unsigned long flags);
};

// The format at +0x10: its first word is the format tag (1 is plain PCM in Microsoft's published WAVEFORMATEX).
struct Format {
    unsigned short tag;
};

// The class whose table is at 0x1E3D88: the class the MRIFFFile factory creates for the interface 0x1E3CF0.
struct Object_001E3D88 {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual void slot3();
    virtual long __stdcall func_00173950(void *argument1, void *argument2, void *argument3, void *argument4);

    char unknown_04[8];
    Inner *inner;
    Format *format;
};

// Slot 4: passes the call on to slot 4 of the object at +0xc with the flags in the fourth argument adjusted: 0x10
// added without a third argument, 0x40 added to flag 4 when the format at +0x10 is not plain PCM. 0x80070057
// (E_INVALIDARG) without the first or second argument, 0x800401F0 (not initialised) while +0xc is null.
long __stdcall Object_001E3D88::func_00173950(void *argument1, void *argument2, void *argument3, void *argument4)
{
    if (inner) {
        if (argument1 && argument2) {
            if (!argument3)
                argument4 = (void *)((unsigned long)argument4 | 0x10);
            if (format->tag != 1 && ((unsigned long)argument4 & 4))
                argument4 = (void *)((unsigned long)argument4 | 0x40);
            return inner->slot4(argument1, argument2, argument3, (unsigned long)argument4);
        }
        return 0x80070057;
    }
    return 0x800401F0;
}
