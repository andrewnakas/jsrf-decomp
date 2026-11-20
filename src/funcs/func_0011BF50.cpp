struct Material_0011BF50 {
    char unknown_00[0x30];
    unsigned int stage;
};

struct Model_0011BF50 {
    char unknown_00[0xc];
    Material_0011BF50 *material;
};

struct Sprite_0011BF50 {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5(int first, int second);

    char unknown_04[4];
    Model_0011BF50 *model;
};

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
    virtual void __stdcall slot110(unsigned int stage, int kind, unsigned int value);
    virtual void __stdcall slot111(unsigned int stage, int kind, unsigned int *value);
};

struct Object_0011BCA0 {
    char unknown_00[0x50];
    Sprite_0011BF50 *sprites[1];

    void func_0011BF50(int index);
};

extern Device_00251D6C *data_00251D6C;

unsigned int func_0014C690(float value);

// Member of the class whose table is at 0x1D8638 (called by its slot 3, 0x11C070): draws sprite `index` of those
// at +0x50 (its slot 5) with the colour of its texture stage at half brightness, then restores the colour.
void Object_0011BCA0::func_0011BF50(int index)
{
    if (sprites[index]) {
        unsigned int color;
        data_00251D6C->slot111(sprites[index]->model->material->stage, 1, &color);
        int channels[4];
        channels[0] = color >> 24;
        channels[1] = (color >> 16) & 0xff;
        channels[2] = (color >> 8) & 0xff;
        channels[3] = color & 0xff;
        unsigned int dim = ((((channels[0] << 8) | func_0014C690(channels[1] * 0.5f)) << 8 |
                             func_0014C690(channels[2] * 0.5f)) << 8) |
                           func_0014C690(channels[3] * 0.5f);
        data_00251D6C->slot110(sprites[index]->model->material->stage, 1, dim);
        sprites[index]->slot5(0, 0);
        data_00251D6C->slot110(sprites[index]->model->material->stage, 1, color);
    }
}
