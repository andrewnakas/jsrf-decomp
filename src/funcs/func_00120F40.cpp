// One corner of a textured quad (0x18 bytes).
struct Vertex_00120F40 {
    float x;
    float y;
    unsigned int color;
    unsigned int value_0c;
    float u;
    float v;
};

// The drawer at data_00258C6C.
struct Interface_00120510 {
    virtual long __stdcall slot0();
    virtual long __stdcall slot1();
    virtual long __stdcall slot2();
    virtual long __stdcall slot3();
    virtual long __stdcall slot4();
    virtual long __stdcall slot5(Vertex_00120F40 *vertices, int value);
    virtual long __stdcall slot6();
    virtual long __stdcall slot7();
    virtual long __stdcall slot8(float depth, float offset);
    virtual long __stdcall slot9();
    virtual long __stdcall slot10(int value);
};

extern Interface_00120510 *data_00258C6C;

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

struct Object_0006E130 {
    int func_0006E130(int id);
};

extern Object_0006E130 data_00252790;

// The texture last given to the device.
extern int data_00251D54;

// The quad data_00258C6C draws.
extern Vertex_00120F40 data_00258C08[4];

// Where each piece starts on the screen and in the texture.
struct Corner_00120F40 {
    float x;
    float y;
};

extern Corner_00120F40 data_00225B74[];

// Each piece's width and height on the screen and in the texture.
extern float data_00225CB8[];
extern float data_00225CCC[];
extern float data_00225CE0[];
extern float data_00225CF4[];

struct Object_00120420 {
    char unknown_000[0x480];
    float depth;
    char unknown_484[0x480];
    int texture;

    void func_00120F40(int index, int x, int y);
};

// Draws piece `index` of the texture at 0x904 through data_00258C6C (slots 3, 8 with the depth at 0x480 plus 14900
// and -0.1, 5 and 4): a white quad from the piece's corner (0x225B74) by its screen size (0x225CB8, 0x225CCC), its
// texture coordinates from the same corner by the texture size (0x225CE0, 0x225CF4); setting the texture on stage 0
// when it changed. Then slot 10 (1) either way. The other two arguments are not used.
void Object_00120420::func_00120F40(int index, int x, int y)
{
    if (data_00258C6C->slot3() >= 0) {
        if (data_00251D54 != data_00252790.func_0006E130(texture)) {
            data_00251D54 = data_00252790.func_0006E130(texture);
            data_00251D6C->slot81(0, data_00252790.func_0006E130(texture));
        }
        float x = data_00225B74[index].x;
        float y = data_00225B74[index].y;
        data_00258C08[0].x = x;
        data_00258C08[0].y = y;
        data_00258C08[0].color = 0xffffffff;
        data_00258C08[0].value_0c = 0;
        data_00258C08[0].u = x;
        data_00258C08[0].v = y;
        data_00258C08[1].x = x + data_00225CB8[index];
        data_00258C08[1].y = y;
        data_00258C08[1].color = 0xffffffff;
        data_00258C08[1].value_0c = 0;
        data_00258C08[1].u = x + data_00225CE0[index];
        data_00258C08[1].v = y;
        data_00258C08[2].x = x;
        data_00258C08[2].y = y + data_00225CCC[index];
        data_00258C08[2].color = 0xffffffff;
        data_00258C08[2].value_0c = 0;
        data_00258C08[2].u = x;
        data_00258C08[2].v = y + data_00225CF4[index];
        data_00258C08[3].x = x + data_00225CB8[index];
        data_00258C08[3].y = y + data_00225CCC[index];
        data_00258C08[3].color = 0xffffffff;
        data_00258C08[3].value_0c = 0;
        data_00258C08[3].u = x + data_00225CE0[index];
        data_00258C08[3].v = y + data_00225CF4[index];
        data_00258C6C->slot8(depth + 14900.0f, -0.1f);
        data_00258C6C->slot5(data_00258C08, 0);
        data_00258C6C->slot4();
    }
    data_00258C6C->slot10(1);
}
