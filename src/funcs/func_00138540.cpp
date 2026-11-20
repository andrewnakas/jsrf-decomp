struct Animation_00138540 {
    short unknown_00;
    short frames;
};

struct Shader_00138540 {
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
    virtual void __stdcall slot12(int first, int second);
    virtual void __stdcall slot13(int value);
};

struct Model_00138540 {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5(Animation_00138540 *animation, float frame);

    Shader_00138540 *shader;
    char unknown_08[0x8];
    int mode;
    char unknown_14[0x10];
    unsigned int flags;
};

struct Object_00139B50 {
    char unknown_000[0x2c0];
    Animation_00138540 *animation;
    Model_00138540 *model;
    float frame;

    void func_00138540(float angle);
};

void func_001BA9C0();
void func_001BAA50();
void func_001BB2B0(float scale);
void func_001BB630(float distance);
void func_001BB650(float distance);
void func_001BB670(float angle);

// Advances the animation at +0x2c0 by half a frame (wrapping at its frame count) and draws the model at +0x2c4
// with it, placed by func_001BB630 (0.76), func_001BB650 (-0.88), func_001BB670 (`angle`) and scaled by 0.07.
void Object_00139B50::func_00138540(float angle)
{
    if (animation) {
        frame += 0.5f;
        if (frame >= (float)animation->frames) {
            frame = 0.0f;
        }
    }
    if (model) {
        func_001BA9C0();
        model->shader->slot12(0, 0);
        func_001BB630(0.76f);
        func_001BB650(-0.88f);
        func_001BB670(angle);
        func_001BB2B0(0.07f);
        model->mode = 0;
        model->flags &= ~1;
        model->slot5(animation, frame);
        model->shader->slot13(0);
        func_001BAA50();
    }
}
