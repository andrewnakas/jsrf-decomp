// The device at data_00251D6C: slot 81 sets a stage's texture.
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
    virtual void __stdcall slot81(int first, int second);
};

// One sprite to draw: a position and rectangle, two colours (0x8, 0x20), a size and a scale.
struct Sprite_00136C30 {
    float value_00;
    float value_04;
    unsigned int color_08;
    float value_0c;
    float value_10;
    float value_14;
    float width;
    float height;
    unsigned int color_20;
    float value_24;
    float scale_x;
    float scale_y;
};

// The sprite drawer at data_0025ECF8.
struct Interface_00136690 {
    virtual long __stdcall slot0();
    virtual long __stdcall slot1();
    virtual long __stdcall slot2();
    virtual long __stdcall slot3();
    virtual long __stdcall slot4();
    virtual long __stdcall slot5(Sprite_00136C30 *sprites, int count);
    virtual long __stdcall slot6();
    virtual long __stdcall slot7();
    virtual long __stdcall slot8(float depth, float offset);
    virtual long __stdcall slot9();
    virtual long __stdcall slot10(int value);
};

struct Object_0006E130 {
    int func_0006E130(int id);
};

struct Object_00134880 {
    void func_00136C30();
};

void *func_00025700(unsigned int index, int first, int second, int third);

extern Device_00251D6C *data_00251D6C;
extern int data_00251D54;
extern Object_0006E130 data_00252790;
extern Sprite_00136C30 data_0025E3E0;
extern Interface_00136690 *data_0025ECF8;

// Draws resource 0x12/1/1/3 as one 640 x 480 sprite (scaled 0.625 by 0.46875) through data_0025ECF8 (slots 3, 8,
// 5, 4), setting the texture on stage 0 when it changed; then slot 10 with 1 either way. Never reads this.
void Object_00134880::func_00136C30()
{
    if (data_0025ECF8->slot3() >= 0) {
        int texture = data_00252790.func_0006E130((int)func_00025700(0x12, 1, 1, 3));
        if (data_00251D54 != texture) {
            data_00251D54 = texture;
            data_00251D6C->slot81(0, texture);
        }
        data_0025E3E0.value_00 = 0.0f;
        data_0025E3E0.value_04 = 0.0f;
        data_0025E3E0.color_08 = 0xffffffff;
        data_0025E3E0.value_0c = 0.0f;
        data_0025E3E0.value_10 = 0.0f;
        data_0025E3E0.value_14 = 0.0f;
        data_0025E3E0.width = 640.0f;
        data_0025E3E0.height = 480.0f;
        data_0025E3E0.color_20 = 0xffffffff;
        data_0025E3E0.value_24 = 0.0f;
        data_0025E3E0.scale_x = 0.625f;
        data_0025E3E0.scale_y = 0.46875f;
        data_0025ECF8->slot8(100.0f, -0.1f);
        data_0025ECF8->slot5(&data_0025E3E0, 1);
        data_0025ECF8->slot4();
    }
    data_0025ECF8->slot10(1);
}
