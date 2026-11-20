struct Game {
    void *func_000128C0(int id);
};

struct Vector3 {
    float x;
    float y;
    float z;
};

struct Light_00046920 {
    int unknown_00;
    unsigned int color_04;
    unsigned int color_08;
    int unknown_0c;
    Vector3 direction;
    char unknown_1c[0x24];
    unsigned int color_40;
    int unknown_44;
    unsigned int color_48;
    int unknown_4c;
    int value_50;
    char unknown_54[0x1c];
};

struct Transform_000704E0 {
    float scale;
    float unknown_04;
    float unknown_08;
    float unknown_0c;
    float unknown_10;
    float rate;
};

struct Object_00046670 {
    void func_000466D0();
    void func_00046740(Light_00046920 *light);
    void func_00046920(Light_00046920 *light);
    void func_00046940(int enable);
    void func_00046A30();
};

// The device at data_00251D6C: slot 33 takes a float.
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
    virtual void __stdcall slot33(float value);
};

// The interface a model keeps at +4 (stdcall slots 12-14).
struct Interface_00128680 {
    virtual long __stdcall slot0();
    virtual long __stdcall slot1();
    virtual long __stdcall slot2();
    virtual long __stdcall slot3();
    virtual long __stdcall slot4();
    virtual long __stdcall slot5();
    virtual long __stdcall slot6();
    virtual long __stdcall slot7();
    virtual long __stdcall slot8();
    virtual long __stdcall slot9();
    virtual long __stdcall slot10();
    virtual long __stdcall slot11();
    virtual long __stdcall slot12(int stage, int value);
    virtual long __stdcall slot13(int stage);
    virtual long __stdcall slot14(int stage, Transform_000704E0 *transform);
};

// A model with a colour (func_00047F40); its slot 5 poses it.
struct Model_00133370 {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5(int first, int second);

    Interface_00128680 *effect;
    char unknown_08[8];
    int mode;
    char unknown_14[0x10];
    unsigned int flags;

    void func_00047F40(int value);
};

struct Object_00120420 {
    char unknown_0000[0x490];
    Vector3 position;
    char unknown_049c[0xc50];
    int pattern;
    char unknown_10f0[0x17ec];
    Model_00133370 *models[0x46];
    char unknown_29f4[0x7a8];
    unsigned char shown[0x46];
};

// The class whose table is at 0x1DA350 (destructor 0x127E60).
struct Object_00127E60 {
    void func_00128680(float alpha);
};

extern Game *data_0022FCE0;
extern Object_00046670 data_001F93C8;
extern Device_00251D6C *data_00251D6C;
extern Transform_000704E0 data_00227A74;
extern Transform_000704E0 data_00227A8C;
extern Transform_000704E0 data_00227AA4;

void func_001BA9C0();
void __fastcall func_001BAA50();
void func_001BAA60(float x, float y, float z);

// Draws each shown model of the 70 at +0x28DC of object 0x1de2 (flags at +0x319C) at its position (+0x490) with
// device slot 33 at -10 and a white light along z: in mode 0, visible, coloured white with `alpha` (0-1) as its
// alpha, with the stage-0 transform data_00227A74, or for models 1-60 data_00227A8C / data_00227AA4 when the pattern
// at +0x10EC is 1 / another nonzero value.
void Object_00127E60::func_00128680(float alpha)
{
    Object_00120420 *game = (Object_00120420 *)data_0022FCE0->func_000128C0(0x1de2);
    unsigned int color = (int)(alpha * 255.0f) << 24 | 0xffffff;
    for (unsigned int i = 0; i < 0x46; i++) {
        if (game->shown[i]) {
            func_001BA9C0();
            data_00251D6C->slot33(-10.0f);
            Light_00046920 light;
            data_001F93C8.func_00046920(&light);
            light.value_50 = 0;
            light.direction.x = 0.0f;
            light.direction.y = 0.0f;
            light.direction.z = 1.0f;
            light.color_04 = 0xffffff;
            light.color_08 = 0xffffff;
            data_001F93C8.func_000466D0();
            data_001F93C8.func_00046740(&light);
            data_001F93C8.func_00046940(0);
            game->models[i]->effect->slot12(0, 7);
            if (i >= 1 && i <= 0x3c && game->pattern) {
                if (game->pattern == 1) {
                    game->models[i]->effect->slot14(0, &data_00227A8C);
                } else {
                    game->models[i]->effect->slot14(0, &data_00227AA4);
                }
            } else {
                game->models[i]->effect->slot14(0, &data_00227A74);
            }
            func_001BAA60(game->position.x, game->position.y, game->position.z);
            game->models[i]->mode = 0;
            game->models[i]->flags &= ~1;
            game->models[i]->flags |= 1;
            game->models[i]->func_00047F40(color);
            game->models[i]->slot5(0, 0);
            game->models[i]->effect->slot13(0);
            data_001F93C8.func_00046A30();
            data_00251D6C->slot33(0.0f);
            func_001BAA50();
        }
    }
}
