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

struct Sprite_00138C80 {
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
    virtual long __stdcall slot5(Sprite_00138C80 *sprites, int count);
    virtual long __stdcall slot6();
    virtual long __stdcall slot7();
    virtual long __stdcall slot8(float depth, float offset);
    virtual long __stdcall slot9();
    virtual long __stdcall slot10(int value);
};

struct Cell_00138C80 {
    int x;
    int y;
    int width;
    int height;
    int kind;
};

// The class whose table is at 0x1DEA60 (destructor 0x1379E0).
struct Object_001379E0 {
    char unknown_000[0x68];
    Cell_00138C80 cells[28];
    char unknown_298[0x25];
    unsigned char red;
    unsigned char green;
    unsigned char blue;
    char unknown_2c0[0x84];
    Interface_00136690 *sprites[28];

    void func_00138C80(float depth);
};

extern Device_00251D6C *data_00251D6C;
extern int data_00251D54;

// Draws the 28 cells at +0x68 with the sprites at +0x344: kind 1 in the colour at +0x2bd (opaque), kind 2 in
// 0xff640000, kind 6 in 0xff006464, other kinds not at all; each untextured at `depth` (offset -0.1), then slot 10
// (1) of the sprite.
void Object_001379E0::func_00138C80(float depth)
{
    Interface_00136690 **drawer = sprites;
    Cell_00138C80 *cell = cells;
    for (int i = 0; i < 28; i++, drawer++, cell++) {
        unsigned int color;
        switch (cell->kind) {
        case 1:
            color = 0xff000000 | red << 16 | green << 8 | blue;
            break;
        case 2:
            color = 0xff640000;
            break;
        case 6:
            color = 0xff006464;
            break;
        default:
            continue;
        }
        if ((*drawer)->slot3() >= 0) {
            if (data_00251D54 != -1) {
                data_00251D54 = -1;
                data_00251D6C->slot81(0, -1);
            }
            Sprite_00138C80 sprite;
            sprite.x = (float)cell->x;
            sprite.y = (float)cell->y;
            sprite.value_10 = 0.0f;
            sprite.value_14 = 0.0f;
            sprite.width = (float)cell->width;
            sprite.height = (float)cell->height;
            sprite.scale_x = 0.0f;
            sprite.scale_y = 0.0f;
            sprite.color_20 = color;
            sprite.color_08 = color;
            sprite.value_24 = 0;
            sprite.value_0c = 0;
            (*drawer)->slot8(depth, -0.1f);
            (*drawer)->slot5(&sprite, 1);
            (*drawer)->slot4();
        }
        (*drawer)->slot10(1);
    }
}
