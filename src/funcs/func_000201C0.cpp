void *func_00025700(unsigned int index, int first, int second, int third);
int func_0014C7D0(float x, float z);
void func_001BA9C0();
void __fastcall func_001BAA50();
void __fastcall func_001BB330(int handle);

// The Direct3D device.
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
    virtual void __stdcall slot74(int state, int value);
};

extern Device_00251D6C *data_00251D6C;

// The light: its direction (+0x20, +0x28 in the ground plane).
struct Light_00046920 {
    char unknown_00[0x20];
    float x;
    float y;
    float z;
};

extern Light_00046920 *data_001F963C;

struct Model_000201C0 {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5(int first, int second);
};

struct Sprite_000201C0 {
    Model_000201C0 *model;
};

struct Object_00022990 {
    void func_000201C0();
};

// Draws the model of the object func_00025700 (5, 0x12) finds, turned to the light's direction in the ground plane
// (func_0014C7D0 + 0x8000, or a quarter turn when its z is 0), with device state 0x306 off; then sets state 0x302 to
// 0x303.
void Object_00022990::func_000201C0()
{
    Sprite_000201C0 **sprite = (Sprite_000201C0 **)func_00025700(5, 0x12, 0, 0);
    Light_00046920 *light = data_001F963C;
    if (sprite) {
        Model_000201C0 *model = (*sprite)->model;
        if (model) {
            int angle;
            if (light->z != 0.0f)
                angle = func_0014C7D0(light->x, light->z) + 0x8000;
            else if (light->x > 0.0f)
                angle = -0x4000;
            else if (light->x < 0.0f)
                angle = 0x4000;
            else
                angle = 0;
            func_001BA9C0();
            func_001BB330(angle);
            data_00251D6C->slot74(0x306, 0);
            model->slot5(0, 0);
            data_00251D6C->slot74(0x302, 0x303);
            func_001BAA50();
        }
    }
}
