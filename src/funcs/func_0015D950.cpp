// What slot 118 of the interface at data_00265110 takes.
struct Desc {
    int value_00;
    unsigned long value_04;
    unsigned long value_08;
    int value_0C;
    unsigned long value_10;
    unsigned long value_14;
};

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
    virtual long __stdcall slot54(unsigned long first, unsigned long second, unsigned long third,
                                  unsigned long fourth, unsigned long fifth);
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
    virtual void __stdcall slot93();
    virtual void __stdcall slot94();
    virtual void __stdcall slot95();
    virtual void __stdcall slot96();
    virtual void __stdcall slot97();
    virtual void __stdcall slot98();
    virtual void __stdcall slot99();
    virtual void __stdcall slot100();
    virtual void __stdcall slot101();
    virtual void __stdcall slot102();
    virtual void __stdcall slot103();
    virtual void __stdcall slot104();
    virtual void __stdcall slot105();
    virtual void __stdcall slot106();
    virtual void __stdcall slot107();
    virtual void __stdcall slot108();
    virtual void __stdcall slot109();
    virtual void __stdcall slot110();
    virtual void __stdcall slot111();
    virtual void __stdcall slot112();
    virtual void __stdcall slot113();
    virtual void __stdcall slot114();
    virtual void __stdcall slot115();
    virtual void __stdcall slot116();
    virtual void __stdcall slot117();
    virtual long __stdcall slot118(const struct Desc *desc, unsigned long value);
};

extern Interface_00265110 *data_00265110;

struct Format {
    unsigned long value_00;
    unsigned long value_04;
    unsigned long unknown_08[3];
    unsigned long value_14;
};

struct Slot;

// A class whose table is at 0x1E1640 (26 slots; created by 0x159D70).
struct Object_001E1640 {
    virtual long __stdcall func_00159B70(const void *iid, void **object);  // slot 0

    long func_0015D950(const Format *format, unsigned long second, unsigned long third, unsigned long fourth,
                       unsigned long fifth);

    Slot *slots;
    unsigned int count;
    int value_0C;
    int value_10;
};

// Hands the format's values at +4 and +0x14 with the arguments to slot 54 of the interface at data_00265110, or,
// when bit 31 of the fourth argument is set, to slot 118 in a description that also holds the two ints at +0xC and
// +0x10.
long Object_001E1640::func_0015D950(const Format *format, unsigned long second, unsigned long third,
                                    unsigned long fourth, unsigned long fifth)
{
    if (!(fourth & 0x80000000))
        return data_00265110->slot54(second, format->value_04, format->value_14, third, fifth);
    Desc desc;
    desc.value_00 = value_0C;
    desc.value_04 = second;
    desc.value_08 = format->value_04;
    desc.value_0C = value_10;
    desc.value_10 = format->value_14;
    desc.value_14 = 0;
    return data_00265110->slot118(&desc, fifth);
}
