struct Interface {
    virtual void __stdcall slot0();
    virtual void __stdcall slot1();
    virtual void __stdcall slot2();
    virtual void __stdcall slot3();
    virtual void __stdcall slot4();
    virtual long __stdcall slot5();
};

struct Holder {
    Interface *object;
};

// A class whose table is at 0x1E1640 (26 slots; Release 0x159D40, created by 0x159D70).
struct Object_001E1640 {
    virtual long __stdcall func_00159570(Holder *holder);  // slot 7
};

long __stdcall Object_001E1640::func_00159570(Holder *holder)
{
    return holder->object->slot5();
}
