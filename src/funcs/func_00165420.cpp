struct Guid;

// A block of 0x13c bytes whose first word is its size.
struct Info {
    unsigned long size;
    char data[0x138];
};

// The class whose table is at 0x1E1FE4.
struct Object_001E1FE4 {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual long __stdcall func_00165420(Info *info);

    char unknown_04[0x10];
    Info info;
};

// Slot 7: copies the block at +0x14 out when the caller's block says it is 0x13c bytes; E_INVALIDARG otherwise.
long __stdcall Object_001E1FE4::func_00165420(Info *info)
{
    if (info && info->size == sizeof(Info)) {
        *info = this->info;
        return 0;
    }
    return 0x80070057;
}
