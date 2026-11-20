struct Device_00251D6C {
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
    virtual void __stdcall slot20(const void *light);
    virtual void __stdcall slot21(unsigned int color);
    virtual void __stdcall slot22(unsigned int color);
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
    virtual void __stdcall slot78(int value);
};

extern Device_00251D6C *data_00251D6C;
extern int data_00251D84;

// A light (0x70 bytes): on or off, two colours, two settings blocks (+0x10 when off, +0x30 when on), a render state
// and three values for the texture cache.
struct Light_00046920 {
    int enabled;
    unsigned int color_04;
    unsigned int color_08;
    int unknown_0c;
    char settings_10[0x20];
    char settings_30[0x20];
    int value_50;
    char unknown_54[0x10];
    unsigned int value_64;
    unsigned int value_68;
    int value_6c;
};

extern Light_00046920 *data_001F963C;

struct Object_0006E130 {
    void func_0006E0F0(unsigned int value);
    void func_0006E110(unsigned int value);
};

extern Object_0006E130 data_00252790;

void func_0004EAC0(int value);

struct Object_00046670 {
    char unknown_000[0x274];
    Light_00046920 *current;

    void func_00046770();
    void func_00046940(int enable);
};

// Turns the current light on (its settings at +0x30) or off (its settings at +0x10, its colours, the texture cache
// values of the light at 0x1F963C, func_00046770 and its render state).
void Object_00046670::func_00046940(int enable)
{
    if (enable) {
        current->enabled = 1;
        data_00251D6C->slot20(current->settings_30);
        return;
    }
    current->enabled = 0;
    data_00251D6C->slot20(current->settings_10);
    data_00251D6C->slot21(current->color_04);
    data_00251D6C->slot22(current->color_08);
    data_00252790.func_0006E0F0(data_001F963C->value_64);
    data_00252790.func_0006E110(data_001F963C->value_68);
    func_0004EAC0(data_001F963C->value_6c);
    func_00046770();
    if (data_00251D84 != current->value_50) {
        data_00251D84 = current->value_50;
        data_00251D6C->slot78(current->value_50);
    }
}
