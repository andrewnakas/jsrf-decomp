struct Matrix_001BA950 {
    float m[4][4];
};

void func_001BA9C0();
void __fastcall func_001BA8F0(Matrix_001BA950 *matrix);
void func_001BAA50();
void __fastcall func_001BB430(float *vector);

struct Frame_000479D0 {
    int unknown_00;
    int mesh;
    char unknown_08[0xc];
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

struct Surface_000476F0 {
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
    virtual void __stdcall slot16(int argument);
};

extern int data_001FA1CC;
extern int data_00251D54;
extern int data_00251D40;

// One row of a matrix.
struct Row_00047A10 {
    float x;
    float y;
    float z;
    float w;
};

// The model base class (table 0x1CAA8C): its surface (+0x4), matrices (+0x1c, +0x20) and a height at +0x3c.
struct Object_00047470 {
    virtual ~Object_00047470();

    Surface_000476F0 *surface;
    char unknown_08[0x14];
    unsigned int count;
    Matrix_001BA950 *matrices;
    char unknown_24[0x18];
    float height;

    void func_00047A10(Frame_000479D0 *frames, int *textures);
};

#define SET_STAGE(cache, stage, value) \
    if (cache != (value)) { \
        cache = (value); \
        data_00251D6C->slot81(stage, (value)); \
    }

// Run when flag 0x10 is set: with slot 71 of the device off, no texture in stage 0 and slot 66 at 2, draws the mesh
// of every frame that has one (slot 16 of the surface) at its matrix with the translation raised by +0x3c (counting
// the draws in 0x251D40). The textures are not used.
void Object_00047470::func_00047A10(Frame_000479D0 *frames, int *)
{
    func_001BA9C0();
    if (data_001FA1CC != 0) {
        data_001FA1CC = 0;
        data_00251D6C->slot71(0);
    }
    SET_STAGE(data_00251D54, 0, -1);
    data_00251D6C->slot66(2);
    for (unsigned int i = 0; i < count; frames++, i++) {
        if (frames->mesh) {
            func_001BA8F0(&matrices[i]);
            Row_00047A10 row;
            row.x = matrices[i].m[3][0];
            row.y = matrices[i].m[3][1];
            row.z = matrices[i].m[3][2];
            row.w = matrices[i].m[3][3];
            row.z += height;
            func_001BB430(&row.x);
            surface->slot16(frames->mesh);
            data_00251D40++;
        }
    }
    data_00251D6C->slot66(1);
    func_001BAA50();
}
