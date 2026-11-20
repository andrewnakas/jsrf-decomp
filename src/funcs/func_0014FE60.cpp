void __stdcall func_0018F180(unsigned long stage, int type, unsigned long value);

// The four values slot 93 sets when it is given none.
extern unsigned long data_0022E644[4];

// The Direct3D device wrapper: table 0x1E0F00 (121 slots).
struct Object_001E0F00 {
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
    virtual void __stdcall slot27();
    virtual void __stdcall slot28();
    virtual void __stdcall slot29();
    virtual void __stdcall slot30();
    virtual void __stdcall slot31();
    virtual void __stdcall slot32();
    virtual void __stdcall slot33();
    virtual void __stdcall slot34();
    virtual void __stdcall slot35();
    virtual void __stdcall slot36();
    virtual void __stdcall slot37();
    virtual void __stdcall slot38();
    virtual void __stdcall slot39();
    virtual void __stdcall slot40();
    virtual void __stdcall slot41();
    virtual void __stdcall slot42();
    virtual void __stdcall slot43();
    virtual void __stdcall slot44();
    virtual void __stdcall slot45();
    virtual void __stdcall slot46();
    virtual void __stdcall slot47();
    virtual void __stdcall slot48();
    virtual void __stdcall slot49();
    virtual void __stdcall slot50();
    virtual void __stdcall slot51();
    virtual void __stdcall slot52();
    virtual void __stdcall slot53();
    virtual void __stdcall slot54();
    virtual void __stdcall slot55();
    virtual void __stdcall slot56();
    virtual void __stdcall slot57();
    virtual void __stdcall slot58();
    virtual void __stdcall slot59();
    virtual void __stdcall slot60();
    virtual void __stdcall slot61();
    virtual void __stdcall slot62();
    virtual void __stdcall slot63();
    virtual void __stdcall slot64();
    virtual void __stdcall slot65();
    virtual void __stdcall slot66();
    virtual void __stdcall slot67();
    virtual void __stdcall slot68();
    virtual void __stdcall slot69();
    virtual void __stdcall slot70();
    virtual void __stdcall slot71();
    virtual void __stdcall slot72();
    virtual void __stdcall slot73();
    virtual void __stdcall slot74();
    virtual void __stdcall slot75();
    virtual void __stdcall slot76();
    virtual void __stdcall slot77();
    virtual void __stdcall slot78();
    virtual void __stdcall slot79();
    virtual void __stdcall slot80();
    virtual void __stdcall slot81();
    virtual void __stdcall slot82();
    virtual void __stdcall slot83();
    virtual void __stdcall slot84();
    virtual void __stdcall slot85();
    virtual void __stdcall slot86();
    virtual void __stdcall slot87();
    virtual void __stdcall slot88();
    virtual void __stdcall slot89();
    virtual void __stdcall slot90();
    virtual void __stdcall slot91();
    virtual void __stdcall slot92();
    virtual long __stdcall func_0014FE60(unsigned long argument1, unsigned long argument2);  // slot 93
};

// Slot 93: sets texture stage states 0x16, 0x17, 0x19 and 0x18 of stage argument1 (func_0018F180) to the four
// values argument2 points at, or to the defaults at data_0022E644 without them.
long __stdcall Object_001E0F00::func_0014FE60(unsigned long argument1, unsigned long argument2)
{
    const unsigned long *values = (const unsigned long *)argument2;
    if (values) {
        func_0018F180(argument1, 0x16, values[0]);
        func_0018F180(argument1, 0x17, values[1]);
        func_0018F180(argument1, 0x19, values[2]);
        func_0018F180(argument1, 0x18, values[3]);
        return 0;
    }
    func_0018F180(argument1, 0x16, data_0022E644[0]);
    func_0018F180(argument1, 0x17, data_0022E644[1]);
    func_0018F180(argument1, 0x19, data_0022E644[2]);
    func_0018F180(argument1, 0x18, data_0022E644[3]);
    return 0;
}
