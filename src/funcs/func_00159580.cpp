struct Interface {
    virtual void __stdcall slot0();
    virtual void __stdcall slot1();
    virtual void __stdcall slot2();
    virtual unsigned long __stdcall slot3(int what);
    virtual void __stdcall slot4();
    virtual void __stdcall slot5();
    virtual long __stdcall slot6(unsigned long *value, int flags);
};

struct Holder {
    Interface *object;
};

// A class whose table is at 0x1E1640 (26 slots; Release 0x159D40, created by 0x159D70).
struct Object_001E1640 {
    virtual long __stdcall func_00159580(Holder *holder, unsigned long *first, unsigned long *second);  // slot 8
};

// Asks the holder's object for a value (its slot 6) and, if asked for, its slot 3 value for 4.
long __stdcall Object_001E1640::func_00159580(Holder *holder, unsigned long *first, unsigned long *second)
{
    Interface *object = holder->object;
    unsigned long value = 0;
    long result = object->slot6(&value, 0);

    if (result < 0)
        return result;
    if (first)
        *first = value;
    if (second)
        *second = object->slot3(4);
    return 0;
}
