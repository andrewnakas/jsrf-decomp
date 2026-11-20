/* const: 0x10002 */
/* const: 0x20002 */
/* const: 0x20103 */
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
    virtual long __stdcall slot84(int index, unsigned long value);
};

extern Interface_00265110 *data_00265110;
extern unsigned long data_002650F0[];

// A class whose table is at 0x1E1640 (26 slots; Release 0x159D40, created by 0x159D70).
struct Object_001E1640 {
    virtual long __stdcall func_00159700(unsigned long argument1, unsigned long argument2);  // slot 12
};

// Keeps mode as entry index of the table at 0x2650F0 and passes index and the word for mode (0 to 8) to slot 84 of
// the object at 0x265110. E_INVALIDARG for a mode past 8.
long __stdcall Object_001E1640::func_00159700(unsigned long index, unsigned long mode)
{
    data_002650F0[index] = mode;
    switch (mode) {
    case 4:
        return data_00265110->slot84(index, 0x10002);
    case 1:
        return data_00265110->slot84(index, 0x10002);
    case 5:
        return data_00265110->slot84(index, 0x10002);
    case 2:
        return data_00265110->slot84(index, 0x20002);
    case 3:
        return data_00265110->slot84(index, 0x20002);
    case 6:
        return data_00265110->slot84(index, 0x10002);
    case 7:
        return data_00265110->slot84(index, 2);
    case 8:
        return data_00265110->slot84(index, 0x20103);
    case 0:
        return data_00265110->slot84(index, 0);
    }
    return 0x80070057;
}
