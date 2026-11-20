struct Guid;

// The class whose table is at 0x1E1FE4.
struct Object_001E1FE4 {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual void slot3();
    virtual long __stdcall func_00165380(int *first, int *second);

    char unknown_04[8];
    int first;
    int second;
};

// Slot 4: copies the two values at +0xc and +0x10 out, to whichever pointer is not null.
long __stdcall Object_001E1FE4::func_00165380(int *first, int *second)
{
    if (first)
        *first = this->first;
    if (second)
        *second = this->second;
    return 0;
}
