struct Matrix_001BA950;

void func_0005F0F0(void *object, void *frames, void *data, float frame, int mode);

struct Frame_000479D0;

struct Object_0006E130 {
    int func_0006E130(int id);
};

extern Object_0006E130 data_00252790;

// A vertex shader effect: slot 3 begins, slot 4 ends, slot 5 sets constants.
struct Effect_00048690 {
    virtual long __stdcall slot0();
    virtual long __stdcall slot1();
    virtual long __stdcall slot2();
    virtual long __stdcall slot3();
    virtual long __stdcall slot4();
    virtual long __stdcall slot5(int index, const float *values, int count);
};

struct Context_00251D7C {
    char unknown_000[0x530];
    Effect_00048690 *effect;
};

extern Context_00251D7C *data_00251D7C;

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
    virtual void __stdcall slot71(int value);
    virtual void __stdcall slot72();
    virtual void __stdcall slot73();
    virtual void __stdcall slot74();
    virtual void __stdcall slot75();
    virtual void __stdcall slot76();
    virtual void __stdcall slot77();
    virtual void __stdcall slot78();
    virtual void __stdcall slot79();
    virtual void __stdcall slot80();
    virtual void __stdcall slot81(int stage, int texture);
    virtual void __stdcall slot82(int stage, int value);
    virtual void __stdcall slot83(int first, int second);
    virtual void __stdcall slot84();
    virtual void __stdcall slot85(int first, int second);
};

extern Device_00251D6C *data_00251D6C;

struct Surface_000476F0 {
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
    virtual long __stdcall slot12(int stage, int count);
    virtual long __stdcall slot13(int stage);
    virtual long __stdcall slot14(int stage, const float *values);
};

extern int data_001FA1CC;
extern int data_00251D48;
extern int data_00251D58;

// The model base class (table 0x1CAA8C): surface (+0x4), frames (+0x8), textures (+0xc), flags (+0x24), a stage-1
// state (+0x40), its texture (+0x44) and a colour (+0x48, the last channel raised by +0x5c).
struct Object_00047470 {
    virtual ~Object_00047470();

    Surface_000476F0 *surface;
    Frame_000479D0 *frames;
    int *textures;
    char unknown_10[0x14];
    unsigned int flags;
    char unknown_28[0x18];
    int state;
    int texture;
    float colour[4];
    char unknown_58[4];
    float raise;

    void func_00047970(void *data, int argument);
    void func_000479D0(Frame_000479D0 *frames, int kind);
    void func_00047A10(Frame_000479D0 *frames, int *textures);
    void func_00048690(int data, int frame);
};

#define SET_STATE(cache, stage, value) \
    if (cache != (value)) { \
        cache = (value); \
        data_00251D6C->slot82(stage, (value)); \
    }

#define SET_STAGE(cache, stage, value) \
    if (cache != (value)) { \
        cache = (value); \
        data_00251D6C->slot81(stage, (value)); \
    }

// Handler 1 of the table at 0x1F97B4: slot 71 of the device off, stage 1 with state +0x40 and texture +0x44 (func_0006E130
// of 0x252790), then the frames posed for kind 0 with the colour at +0x48 in surface stage 1 (slots 12 to 14), or with
// flag 0x40 for kind 5 inside the effect at +0x530 of 0x251D7C (the colour as constant 2); from the motion data with
// func_0005F0F0 when given, else func_000479D0 and func_00047970. Stage 1 is cleared after and flag 0x10 runs
// func_00047A10.
void Object_00047470::func_00048690(int data, int frame)
{
    if (data_001FA1CC != 0) {
        data_001FA1CC = 0;
        data_00251D6C->slot71(0);
    }
    SET_STATE(data_00251D48, 1, state);
    SET_STAGE(data_00251D58, 1, data_00252790.func_0006E130(texture));
    data_00251D6C->slot85(1, 0);
    float values[4];
    *(int *)&values[0] = *(int *)&colour[0];
    *(int *)&values[1] = *(int *)&colour[1];
    *(int *)&values[2] = *(int *)&colour[2];
    *(int *)&values[3] = *(int *)&colour[3];
    values[3] += raise;
    if (!(flags & 0x40)) {
        if (surface->slot12(1, 4) >= 0) {
            surface->slot14(1, values);
            if (!data) {
                func_000479D0(frames, 0);
                func_00047970(0, 0);
            } else {
                func_0005F0F0(this, frames, (void *)data, *(float *)&frame, 0);
            }
            surface->slot13(1);
            data_00251D6C->slot83(1, 1);
        }
    } else {
        Effect_00048690 *effect = data_00251D7C->effect;
        if (effect->slot3() >= 0) {
            effect->slot5(2, values, 1);
            effect->slot5(6, 0, 0x30);
            effect->slot5(7, 0, 3);
            if (!data) {
                func_000479D0(frames, 5);
                func_00047970(0, 0);
            } else {
                func_0005F0F0(this, frames, (void *)data, *(float *)&frame, 5);
            }
            effect->slot4();
        }
    }
    data_00251D6C->slot85(1, 1);
    SET_STAGE(data_00251D58, 1, -1);
    if (flags & 0x10) {
        func_00047A10(frames, textures);
    }
}
