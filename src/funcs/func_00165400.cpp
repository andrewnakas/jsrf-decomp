struct Guid;

// The class whose table is at 0x1E1FE4.
struct Object_001E1FE4 {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual long __stdcall func_00165400(int first, int second);

    char unknown_04[8];
    int first;
    int second;
};

// Slot 6: keeps the two values at +0xc and +0x10.
long __stdcall Object_001E1FE4::func_00165400(int first, int second)
{
    this->first = first;
    this->second = second;
    return 0;
}
