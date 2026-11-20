/* sym: ?func_00157F20_4@Object_001E1538@@UAGXK@Z = 0x0015B6E0 */
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
    virtual void __stdcall slot27();
    virtual void __stdcall slot28(int first, int second);
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
    virtual void __stdcall slot66(int value);
    virtual void __stdcall slot67();
    virtual void __stdcall slot68();
    virtual void __stdcall slot69();
    virtual void __stdcall slot70();
    virtual void __stdcall slot71(int value);
};

extern Interface_00265110 *data_00265110;

struct Buffer {
    virtual void __stdcall slot0();
    virtual void __stdcall slot1();
    virtual void __stdcall slot2();
    virtual void __stdcall slot3();
    virtual void __stdcall slot4();
    virtual void __stdcall slot5();
    virtual void __stdcall slot6();
    virtual void __stdcall slot7();
    virtual void __stdcall slot8(int value);
    virtual void __stdcall slot9();
    virtual void __stdcall slot10();
    virtual void __stdcall slot11();
    virtual void __stdcall slot12();
    virtual void __stdcall slot13(unsigned int count);
    virtual void __stdcall slot14();
    virtual void __stdcall slot15(unsigned int count, int value);
};

// The base of the classes whose tables are at 0x1E1508, 0x1E1538 and 0x1E1568 (constructor 0x1589D0).
struct Object_001E14D8 {
    virtual void __stdcall func_00157F20_3(unsigned long value);  // slot 10: does nothing, folded
    virtual void __stdcall func_00157F20_4(unsigned long value);  // slot 11: the same folded function

    unsigned long words[0x40];
    Buffer *buffer;
    unsigned int stride;
};

// The class whose table is at 0x1E1538 (kind 1 of 0x158A80).
struct Object_001E1538 : Object_001E14D8 {
    virtual void __stdcall func_00157F20_4(unsigned long count);  // slot 11, at 0x15B6E0
};

// Slot 11: resets the interface at data_00265110 (its slots 66, 71 and 28) and the buffer (slots 8 and 9), passes the buffer the count rounded down to even (slot 15)
// (count -1 means the stride at +0x108) and ends with the interface's slot 66 set to 1.
void __stdcall Object_001E1538::func_00157F20_4(unsigned long count)
{
    data_00265110->slot66(0);
    data_00265110->slot71(0);
    data_00265110->slot28(0, -1);
    buffer->slot8(0);
    buffer->slot9();
    if (count == (unsigned long)-1)
        count = stride;
    buffer->slot15(count & ~1, 0);
    data_00265110->slot66(1);
}
