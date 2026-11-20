// The device at data_00251D6C: slot 81 sets a stage's texture.
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
    virtual void __stdcall slot81(int first, int second);
};

// One corner of a textured quad (0x18 bytes), filled as raw words: the coordinates are float bit patterns.
struct Vertex_00131F60 {
    unsigned int x;
    unsigned int y;
    unsigned int color;
    unsigned int value_0c;
    unsigned int u;
    unsigned int v;
};

// The drawer data_0025C314 holds.
struct Interface_00131F60 {
    virtual long __stdcall slot0();
    virtual long __stdcall slot1();
    virtual long __stdcall slot2();
    virtual long __stdcall slot3();
    virtual long __stdcall slot4();
    virtual long __stdcall slot5(Vertex_00131F60 *vertices, int value);
    virtual long __stdcall slot6();
    virtual long __stdcall slot7();
    virtual long __stdcall slot8(float depth, float offset);
    virtual long __stdcall slot9();
    virtual long __stdcall slot10(int value);
};

// The part of the texture each layout shows (0x2c bytes): its corners in the texture and the size on screen, all
// float bit patterns read as words.
struct Frame_00131F60 {
    unsigned int u0;
    unsigned int v0;
    unsigned int u1;
    unsigned int v1;
    char unknown_10[8];
    unsigned int width;
    unsigned int height;
    char unknown_20[0xc];
};

struct Object_0006E130 {
    int func_0006E130(int id);
};

struct Object_00120420 {
    char unknown_000[0x5c];
    Vertex_00131F60 vertices[4];
    char unknown_0bc[0x120];
    int layout;
    char unknown_1e0[0x6c4];
    int texture;

    void func_00131F60();
};

extern Device_00251D6C *data_00251D6C;
extern int data_00251D54;
extern Object_0006E130 data_00252790;
extern int data_0025C314;
extern Frame_00131F60 data_0022C15C[];

// Draws the texture at +0x8a4 as the quad at +0x5c from (0, 0) to the layout's size (data_0022C15C for the layout
// at +0x1dc) through the drawer data_0025C314 (slots 3, 5, 4), setting it on stage 0 when it changed; then slot 8
// (14900, -0.1) and slot 10 (1) either way.
void Object_00120420::func_00131F60()
{
    if (((Interface_00131F60 *)data_0025C314)->slot3() >= 0) {
        if (data_00251D54 != data_00252790.func_0006E130(texture)) {
            data_00251D54 = data_00252790.func_0006E130(texture);
            data_00251D6C->slot81(0, data_00252790.func_0006E130(texture));
        }
        vertices[0].x = 0;
        vertices[0].y = 0;
        vertices[0].color = 0xffffffff;
        vertices[0].value_0c = 0;
        vertices[0].u = data_0022C15C[layout].u0;
        vertices[0].v = data_0022C15C[layout].v0;
        vertices[1].x = data_0022C15C[layout].width;
        vertices[1].y = 0;
        vertices[1].color = 0xffffffff;
        vertices[1].value_0c = 0;
        vertices[1].u = data_0022C15C[layout].u1;
        vertices[1].v = data_0022C15C[layout].v0;
        vertices[2].x = 0;
        vertices[2].y = data_0022C15C[layout].height;
        vertices[2].color = 0xffffffff;
        vertices[2].value_0c = 0;
        vertices[2].u = data_0022C15C[layout].u0;
        vertices[2].v = data_0022C15C[layout].v1;
        vertices[3].x = data_0022C15C[layout].width;
        vertices[3].y = data_0022C15C[layout].height;
        vertices[3].color = 0xffffffff;
        vertices[3].value_0c = 0;
        vertices[3].u = data_0022C15C[layout].u1;
        vertices[3].v = data_0022C15C[layout].v1;
        ((Interface_00131F60 *)data_0025C314)->slot5(vertices, 0);
        ((Interface_00131F60 *)data_0025C314)->slot4();
    }
    ((Interface_00131F60 *)data_0025C314)->slot8(14900.0f, -0.1f);
    ((Interface_00131F60 *)data_0025C314)->slot10(1);
}
