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

struct Animation_00126920 {
    short unknown_00;
    short frames;
};

// A model with a colour (func_00047F40); its slot 5 poses it with an animation at a frame.
struct Model_00133370 {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5(Animation_00126920 *animation, float frame);

    char unknown_04[0xc];
    int mode;
    char unknown_14[0x10];
    unsigned int flags;
    char unknown_28[0x30];
    float value_58;

    void func_00047F40(int value);
};

struct Object_00120420 {
    char unknown_0000[0x458];
    float first[3];
    float second[3];
    char unknown_0470[0x2230];
    Animation_00126920 *animation;
    char unknown_26a4[0x7bc];
    Model_00133370 *models[2];

    void func_00126920(int which);
};

extern Device_00251D6C *data_00251D6C;
extern float data_00258F90;
extern float data_00258F94;

void func_001BA9C0();
void func_001BAA50();
void func_001BB630(float distance);
void func_001BB650(float distance);
void func_001BB670(float angle);

// Draws model `which` (+0x2E60 or +0x2E64) with device slot 33 at -10, placed by the three values at +0x458 or
// +0x464 (func_001BB630, func_001BB650, func_001BB670), in mode 0, white and hidden, playing the animation at
// +0x26A0 one frame further each call (data_00258F90 or data_00258F94, wrapping at its frame count).
void Object_00120420::func_00126920(int which)
{
    func_001BA9C0();
    data_00251D6C->slot33(-10.0f);
    if (!which) {
        func_001BB630(first[0]);
        func_001BB650(first[1]);
        func_001BB670(first[2]);
        Animation_00126920 *playing = animation;
        if (playing) {
            float frame = data_00258F90 + 1.0f;
            int frames = playing->frames;
            data_00258F90 = frame;
            if (frame >= frames) {
                data_00258F90 = 0.0f;
            }
        }
        models[0]->func_00047F40(-1);
        models[0]->value_58 = 1.0f;
        models[0]->mode = 0;
        models[0]->flags &= ~1;
        models[0]->slot5(animation, data_00258F90);
    } else {
        func_001BB630(second[0]);
        func_001BB650(second[1]);
        func_001BB670(second[2]);
        Animation_00126920 *playing = animation;
        if (playing) {
            float frame = data_00258F94 + 1.0f;
            int frames = playing->frames;
            data_00258F94 = frame;
            if (frame >= frames) {
                data_00258F94 = 0.0f;
            }
        }
        models[1]->func_00047F40(-1);
        models[1]->value_58 = 1.0f;
        models[1]->mode = 0;
        models[1]->flags &= ~1;
        models[1]->slot5(animation, data_00258F94);
    }
    data_00251D6C->slot33(0.0f);
    func_001BAA50();
}
