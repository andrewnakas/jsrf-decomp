/* sym: ?func_00157F20_5@Object_001E15C0@@UAGXK@Z = 0x0015C0C0 */
struct Vector4;
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
    virtual void __stdcall slot27(int kind, int value);
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
    virtual void __stdcall slot13();
    virtual void __stdcall slot14();
    virtual void __stdcall slot15();
    virtual void __stdcall slot16();
    virtual void __stdcall slot17();
    virtual void __stdcall slot18();
    virtual void __stdcall slot19();
    virtual void __stdcall slot20();
    virtual void __stdcall slot21(unsigned long value);
};

// The base of the classes whose tables are at 0x1E1598, 0x1E15C0 and 0x1E15E8 (created by 0x158F00).
struct Object_001E1598 {
    virtual long __stdcall func_00157F00_2(const void *iid, void **object);  // slot 0: E_UNEXPECTED, folded
    virtual unsigned long __stdcall func_00158EE0();  // slot 1
    virtual unsigned long __stdcall func_0014D080_7();  // slot 2: returns 0, folded
    virtual long __stdcall func_00158D70();  // slot 3
    virtual unsigned long __stdcall func_00158D90();  // slot 4
    virtual long __stdcall func_00158DB0(const Vector4 *value);  // slot 5
    virtual long __stdcall func_00158E30(const void *source, unsigned int count, unsigned int stride);  // slot 6
    virtual void __stdcall func_00158E80();  // slot 7
    virtual void __stdcall func_00158ED0(float value);  // slot 8
    virtual void __stdcall func_00157F20_5(unsigned long value);  // slot 9: does nothing, folded

    Buffer *buffer;
    unsigned long value_08;
};

// Kind 0 of 0x158F00.
struct Object_001E15C0 : Object_001E1598 {
    virtual void __stdcall func_00157F20_5(unsigned long value);  // slot 9, at 0x15C0C0
};

// Slot 9: sets slots 71 (0) and 27 (6, -1) of the object at data_00265110, then runs the buffer: its slots 9, 8 (0)
// and 21 with the value, or with the value at +8 for -1.
void __stdcall Object_001E15C0::func_00157F20_5(unsigned long value)
{
    data_00265110->slot71(0);
    data_00265110->slot27(6, -1);
    if (value == -1)
        value = value_08;
    buffer->slot9();
    buffer->slot8(0);
    buffer->slot21(value);
}
