struct Matrix_001BA950 {
    float m[4][4];
};

void func_001BA9C0();
void __fastcall func_001BAA50();
void __fastcall func_001BA8F0(Matrix_001BA950 *matrix);
void __fastcall func_001BB430(float *vector);

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
    virtual void __stdcall slot66(int value);
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
};

extern Device_00251D6C *data_00251D6C;
extern int data_001FA1CC;
extern int data_00251D54;
extern int data_00251D58;
extern int data_00251D40;

struct Frame_000479D0 {
    int unknown_00;
    int mesh;
    char unknown_08[0xc];
    float position[3];
    char unknown_20[0x4c];
};

// The model base class (table 0x1CAA8C).
struct Object_00047470 {
    virtual ~Object_00047470();

    char unknown_04[4];
    Frame_000479D0 *frames;
    char unknown_0c[0x10];
    unsigned int count;
    char unknown_20[0x1c];
    float height;
    char unknown_40[0x24];
    void (Object_00047470::*draw)(int argument);

    void func_00047C30(Matrix_001BA950 *matrices);
};

#define SET_STAGE(cache, stage, value) \
    if (cache != (value)) { \
        cache = (value); \
        data_00251D6C->slot81(stage, (value)); \
    }

// Draws every frame that has a mesh with its own matrix (func_001BA8F0) at the matrix's position raised by +0x3c
// (func_001BB430), through the draw handler at +0x64, counting the draws in 0x251D40; clears the 0x1FA1CC flag
// (device slot 71) and the textures of stages 0 and 1 first, and runs with slot 66 at 2 (1 afterwards).
void Object_00047470::func_00047C30(Matrix_001BA950 *matrices)
{
    Frame_000479D0 *frame = frames;
    func_001BA9C0();
    if (data_001FA1CC != 0) {
        data_001FA1CC = 0;
        data_00251D6C->slot71(0);
    }
    SET_STAGE(data_00251D54, 0, -1);
    SET_STAGE(data_00251D58, 1, -1);
    data_00251D6C->slot66(2);
    for (unsigned int i = 0; i < count; i++) {
        if (frame->mesh) {
            func_001BA8F0(&matrices[i]);
            float position[4];
            *(int *)&position[0] = *(int *)&matrices[i].m[3][0];
            *(int *)&position[1] = *(int *)&matrices[i].m[3][1];
            *(int *)&position[2] = *(int *)&matrices[i].m[3][2];
            *(int *)&position[3] = *(int *)&matrices[i].m[3][3];
            position[2] += height;
            func_001BB430(position);
            (this->*draw)(frame->mesh);
            data_00251D40++;
        }
        frame++;
    }
    data_00251D6C->slot66(1);
    func_001BAA50();
}
