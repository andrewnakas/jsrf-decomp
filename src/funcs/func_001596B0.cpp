struct Interface_00265110 {
    virtual void __stdcall slot0();
    virtual void __stdcall slot1();
    virtual void __stdcall slot2();
    virtual void __stdcall slot3();
    virtual void __stdcall slot4();
    virtual void __stdcall slot5();
    virtual void __stdcall slot6();
    virtual void __stdcall slot7();
    virtual void __stdcall slot8();
    virtual void __stdcall slot9();
    virtual void __stdcall slot10();
    virtual void __stdcall slot11();
    virtual void __stdcall slot12();
    virtual void __stdcall slot13();
    virtual void __stdcall slot14();
    virtual void __stdcall slot15();
    virtual void __stdcall slot16();
    virtual void __stdcall slot17();
    virtual void __stdcall slot18();
    virtual void __stdcall slot19();
    virtual void __stdcall slot20();
    virtual void __stdcall slot21();
    virtual void __stdcall slot22();
    virtual void __stdcall slot23();
    virtual void __stdcall slot24();
    virtual void __stdcall slot25();
    virtual void __stdcall slot26();
    virtual long __stdcall slot27(int kind, unsigned long value);
};

struct Interface {
    virtual void __stdcall slot0();
    virtual void __stdcall slot1();
    virtual void __stdcall slot2();
    virtual void __stdcall slot3();
    virtual void __stdcall slot4();
    virtual void __stdcall slot5();
    virtual void __stdcall slot6();
    virtual void __stdcall slot7();
    virtual long __stdcall slot8(unsigned long flags);
    virtual long __stdcall slot9();
    virtual long __stdcall slot10();
};

struct Holder {
    Interface *object;
};

extern Interface_00265110 *data_00265110;

// A class whose table is at 0x1E1640 (26 slots; Release 0x159D40, created by 0x159D70).
struct Object_001E1640 {
    virtual long __stdcall func_001596B0(Holder *holder);  // slot 23
};

// Slot 27 of the object at 0x265110 with 6 and -1, then slots 9, 8 and 10 of the argument's object.
long __stdcall Object_001E1640::func_001596B0(Holder *holder)
{
    data_00265110->slot27(6, (unsigned long)-1);
    Interface *object = holder->object;
    object->slot9();
    object->slot8(0);
    return object->slot10();
}
