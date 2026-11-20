struct Matrix_001BA950 {
    float m[4][4];
};

void __fastcall func_001BA950(Matrix_001BA950 *matrix);
void func_0005F0F0(void *object, void *frames, void *data, float frame, int mode);

struct Frame_000479D0 {
    int unknown_00;
    char unknown_04[0x10];
    float position[3];
    char unknown_20[0x4c];
};

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
    virtual void __stdcall slot82();
    virtual void __stdcall slot83(int first, int second);
};

extern Device_00251D6C *data_00251D6C;

extern int data_001FA1CC;
extern int data_00251D58;

// The model base class (table 0x1CAA8C): frames (+0x8), textures (+0xc), matrices (+0x1c, +0x20) and flags (+0x24).
struct Object_00047470 {
    virtual ~Object_00047470();

    void *surface;
    Frame_000479D0 *frames;
    int *textures;
    char unknown_10[0xc];
    unsigned int count;
    Matrix_001BA950 *matrices;
    unsigned int flags;

    void func_000479D0(Frame_000479D0 *frames, int kind);
    void func_00047A10(Frame_000479D0 *frames, int *textures);
    void func_000488B0(int data, int frame);
};

#define SET_STAGE(cache, stage, value) \
    if (cache != (value)) { \
        cache = (value); \
        data_00251D6C->slot81(stage, (value)); \
    }

// Handler 2 of the table at 0x1F97B4: turns slot 71 of the device off (cached in 0x1FA1CC) and poses the frames for
// kind 3 (kind 6 with flag 0x40): from the motion data with func_0005F0F0 when given, else func_000479D0 and the
// first matrix loaded and copied to the others. Then sets slot 83 (1, 1), clears texture stage 1 and runs
// func_00047A10 when flag 0x10 is set.
void Object_00047470::func_000488B0(int data, int frame)
{
    if (data_001FA1CC != 0) {
        data_001FA1CC = 0;
        data_00251D6C->slot71(0);
    }
    if (!(flags & 0x40)) {
        if (!data) {
            func_000479D0(frames, 3);
            func_001BA950(matrices);
            for (unsigned int i = 1; i < count; i++) {
                matrices[i] = matrices[0];
            }
        } else {
            func_0005F0F0(this, frames, (void *)data, *(float *)&frame, 3);
        }
    } else if (!data) {
        func_000479D0(frames, 6);
        func_001BA950(matrices);
        for (unsigned int i = 1; i < count; i++) {
            matrices[i] = matrices[0];
        }
    } else {
        func_0005F0F0(this, frames, (void *)data, *(float *)&frame, 6);
    }
    data_00251D6C->slot83(1, 1);
    SET_STAGE(data_00251D58, 1, -1);
    if (flags & 0x10) {
        func_00047A10(frames, textures);
    }
}
