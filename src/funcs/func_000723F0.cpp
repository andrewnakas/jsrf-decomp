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
    virtual void __stdcall slot81(int stage, int texture);
};

extern Device_00251D6C *data_00251D6C;
extern int data_00251D54;
extern int data_00251D58;

// Sets stage `stage` of the texture state cached at `cache` when it changes.
#define SET_STAGE(cache, stage, value) \
    if (cache != (value)) { \
        cache = (value); \
        data_00251D6C->slot81(stage, (value)); \
    }

struct Object_0006E130 {
    int func_0006E130(int id);
};

extern Object_0006E130 data_00252790;

void *func_00025700(unsigned int index, int first, int second, int third);

// A screen vertex (0x18 bytes).
struct Vertex_000725B0 {
    float x;
    float y;
    unsigned int colour;
    float z;
    float u;
    float v;
};

// The ten 512 x 1024 quads, one per effect at 0x257BD0.
extern Vertex_000725B0 data_002577E0[10][4];

// An effect: slot 3 begins (negative on failure), slot 5 draws, slot 4 ends.
struct Interface_00257BD0 {
    virtual long __stdcall slot0();
    virtual long __stdcall slot1();
    virtual long __stdcall slot2();
    virtual long __stdcall slot3();
    virtual long __stdcall slot4();
    virtual long __stdcall slot5(Vertex_000725B0 *vertices, int count);
    virtual long __stdcall slot6();
    virtual long __stdcall slot7();
    virtual long __stdcall slot8(float first, float second);
    virtual long __stdcall slot9();
    virtual long __stdcall slot10(int value);
};

extern Interface_00257BD0 *data_00257BD0[10];

// The class whose table is at 0x1CCAE0 (constructor 0x726A0, destructor 0x72710).
struct Object_00072710 {
    void func_000723F0(unsigned int index, float x, float y, unsigned int colour);
};

// Draws quad `index` (512 x 1024 from x, y, in one colour) through effect `index`: texture 0x15 / 2 / index >> 1
// on stage 0, the left or right half of it by the low bit (u 0 or 0.5); then the effect's slot 10 with 1. Does not
// use this.
void Object_00072710::func_000723F0(unsigned int index, float x, float y, unsigned int colour)
{
    if (data_00257BD0[index]->slot3() >= 0) {
        float u = 0.0f;
        if (index & 1) {
            u = 0.5f;
        }
        int texture = data_00252790.func_0006E130((int)func_00025700(0x15, 0, 2, index >> 1));
        SET_STAGE(data_00251D54, 0, texture);
        SET_STAGE(data_00251D58, 1, -1);
        data_002577E0[index][0].x = x;
        data_002577E0[index][0].y = y;
        data_002577E0[index][0].colour = colour;
        data_002577E0[index][0].z = 0.0f;
        data_002577E0[index][0].u = u;
        data_002577E0[index][0].v = 0.0009765625f;
        data_002577E0[index][1].x = x + 512.0f;
        data_002577E0[index][1].y = y;
        data_002577E0[index][1].colour = colour;
        data_002577E0[index][1].z = 0.0f;
        data_002577E0[index][1].u = u + 0.5f;
        data_002577E0[index][1].v = 0.0009765625f;
        data_002577E0[index][2].x = x;
        data_002577E0[index][2].y = y + 1024.0f;
        data_002577E0[index][2].colour = colour;
        data_002577E0[index][2].z = 0.0f;
        data_002577E0[index][2].u = u;
        data_002577E0[index][2].v = 0.99902344f;
        data_002577E0[index][3].x = x + 512.0f;
        data_002577E0[index][3].y = y + 1024.0f;
        data_002577E0[index][3].colour = colour;
        data_002577E0[index][3].z = 0.0f;
        data_002577E0[index][3].u = u + 0.5f;
        data_002577E0[index][3].v = 0.99902344f;
        data_00257BD0[index]->slot8(2.0f, -0.1f);
        data_00257BD0[index]->slot5(data_002577E0[index], 0);
        data_00257BD0[index]->slot4();
    }
    data_00257BD0[index]->slot10(1);
}
