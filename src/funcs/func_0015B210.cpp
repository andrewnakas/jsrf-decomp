/* sym: ?func_00157F20@Object_001E14B8@@UAGXK@Z = 0x0015B210 */
struct Interface {
    virtual void __stdcall slot0();
    virtual void __stdcall slot1();
    virtual unsigned long __stdcall slot2();
};

struct Holder {
    Interface *object;
};

// The base of the classes whose tables are at 0x1E1478, 0x1E1498 and 0x1E14B8 (created by 0x158490).
struct Object_001E1478 {
    virtual long __stdcall func_00157F00(const void *iid, void **object);  // slot 0
    virtual unsigned long __stdcall func_001532F0_2();  // slot 1: AddRef, folded
    virtual unsigned long __stdcall func_0014D080_5();  // slot 2: returns 0, folded
    virtual long __stdcall func_00157F10(unsigned long value);  // slot 3
    virtual void __stdcall func_00157F20(unsigned long value);  // slot 4
    virtual void __stdcall func_00157F30(unsigned long first, unsigned long second);  // slot 5
    virtual void __stdcall func_00157F20_1(unsigned long value);  // slot 6: the same folded function
    virtual void __stdcall func_00157F20_2(unsigned long value);  // slot 7: the same folded function
};

// The class whose table is at 0x1E14B8 (created by 0x158490).
struct Object_001E14B8 : Object_001E1478 {
    virtual void __stdcall func_00157F20(unsigned long value);  // slot 4, at 0x15B210
};

// Releases the holder's object (the value is a Holder *) until its Release returns 0 and forgets it.
void __stdcall Object_001E14B8::func_00157F20(unsigned long value)
{
    Holder *holder = (Holder *)value;

    if (holder->object) {
        while (holder->object->slot2())
            ;
        holder->object = 0;
    }
}
