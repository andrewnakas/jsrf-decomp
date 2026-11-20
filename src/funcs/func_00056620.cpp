int func_00024650();
void func_00024620(unsigned int color, float rate);

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// The buttons pressed this frame.
extern unsigned int data_00251EE8;

struct Object_00039BE0 {
    void func_00039D80(int *values, unsigned int count);
};

extern Object_00039BE0 data_001EFFB0;

// Object 0x12ac (destructor 0x4FBC0).
struct Object_0004FC40 {
    int func_000500F0();
};

struct Stage_00056540 {
    char unknown_00[8];
    int *values;
    unsigned int count;
    char unknown_10[8];
    int unknown_18;
};

struct Object_0004ABA0 {
    char unknown_000[0xfb8];
    Stage_00056540 *stage;
    char unknown_fbc[0x2c];
    int skipped;
    int fading;

    void func_00053FB0(int index);
    void func_00056620();
};

// A state handler: notes bits 0 or 2 of the buttons pressed at +0xfe8; with object 0x12ac there, once its answer
// (func_000500F0) or such a press comes, fades out (1/60) and marks +0xfec, and after the fade hands the stage's
// values to func_00039D80 of 0x1EFFB0 and runs func_00053FB0 with its word at +0x18.
void Object_0004ABA0::func_00056620()
{
    if (!skipped && (data_00251EE8 & 5)) {
        skipped = 1;
    }
    Object_0004FC40 *object = (Object_0004FC40 *)data_0022FCE0->func_000128C0(0x12ac);
    if (object) {
        if (fading) {
            if (func_00024650()) {
                data_001EFFB0.func_00039D80(stage->values, stage->count);
                func_00053FB0(stage->unknown_18);
            }
        } else if (object->func_000500F0() || skipped) {
            func_00024620(0xff000000, 1.0f / 60.0f);
            fading = 1;
        }
    }
}
