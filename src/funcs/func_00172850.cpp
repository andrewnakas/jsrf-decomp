struct Guid;

// The class whose table is at 0x1E3C80.
struct Object_001E3C80 {
    virtual long __stdcall slot0(const Guid &id, void **object);
    virtual unsigned long __stdcall slot1();
    virtual unsigned long __stdcall slot2();
    virtual void slot3();
    virtual void slot4();
    virtual long __stdcall func_00172850();

    char unknown_04[0x24];
    int low;
    int high;
};

// Slot 5: clears the two words at +0x28 and +0x2c.
long __stdcall Object_001E3C80::func_00172850()
{
    low = 0;
    high = 0;
    return 0;
}
