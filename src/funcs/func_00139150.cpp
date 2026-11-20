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

struct Sprite_00139150 {
    float x;
    float y;
    unsigned int color_08;
    int value_0c;
    float value_10;
    float value_14;
    float width;
    float height;
    unsigned int color_20;
    int value_24;
    float scale_x;
    float scale_y;
};

// The sprite drawer interface (as at data_0025ECF8).
struct Interface_00136690 {
    virtual long __stdcall slot0();
    virtual long __stdcall slot1();
    virtual long __stdcall slot2();
    virtual long __stdcall slot3();
    virtual long __stdcall slot4();
    virtual long __stdcall slot5(Sprite_00139150 *sprites, int count);
    virtual long __stdcall slot6();
    virtual long __stdcall slot7();
    virtual long __stdcall slot8(float depth, float offset);
    virtual long __stdcall slot9();
    virtual long __stdcall slot10(int value);
};

struct Rect_00139150 {
    float x;
    float y;
    float width;
    float height;
};

// The class whose table is at 0x1DEA60 (destructor 0x1379E0).
struct Object_001379E0 {
    char unknown_000[0x44];
    unsigned int value_44;
    char unknown_048[0x290];
    Interface_00136690 *bars[5];

    void func_00139150(float depth);
};

extern Device_00251D6C *data_00251D6C;
extern int data_00251D54;
extern Rect_00139150 data_0022D9D8[5];

// Draws the bars at +0x2d8 from index +0x44 on (none when it is 4): each as one sprite of the rectangle at
// data_0022D9D8 in colour 0x96000000 with no texture, then sets its depth (`depth`, offset -0.1) and slot 10 (1).
void Object_001379E0::func_00139150(float depth)
{
    if (value_44 != 4) {
        for (unsigned int i = 0; i < 5; i++) {
            if (i >= value_44) {
                if (bars[i]->slot3() >= 0) {
                    if (data_00251D54 != -1) {
                        data_00251D54 = -1;
                        data_00251D6C->slot81(0, -1);
                    }
                    Sprite_00139150 sprite;
                    sprite.x = data_0022D9D8[i].x;
                    sprite.y = data_0022D9D8[i].y;
                    sprite.value_10 = 0.0f;
                    sprite.value_14 = 0.0f;
                    sprite.width = data_0022D9D8[i].width;
                    sprite.height = data_0022D9D8[i].height;
                    sprite.scale_x = 0.0f;
                    sprite.scale_y = 0.0f;
                    sprite.color_20 = 0x96000000;
                    sprite.color_08 = 0x96000000;
                    sprite.value_24 = 0;
                    sprite.value_0c = 0;
                    bars[i]->slot5(&sprite, 1);
                    bars[i]->slot4();
                }
                bars[i]->slot8(depth, -0.1f);
                bars[i]->slot10(1);
            }
        }
    }
}
