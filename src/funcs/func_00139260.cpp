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

struct Vertex_00139260 {
    float x;
    float y;
    unsigned int color;
    int value_0c;
    float u;
    float v;
};

// The sprite drawer interface (as at data_0025ECF8).
struct Interface_00136690 {
    virtual long __stdcall slot0();
    virtual long __stdcall slot1();
    virtual long __stdcall slot2();
    virtual long __stdcall slot3();
    virtual long __stdcall slot4();
    virtual long __stdcall slot5(Vertex_00139260 *vertices, int count);
    virtual long __stdcall slot6();
    virtual long __stdcall slot7();
    virtual long __stdcall slot8(float depth, float offset);
    virtual long __stdcall slot9();
    virtual long __stdcall slot10(int value);
};

struct Object_00043700 {
    int func_00043700();
};

struct Line_00139260 {
    int language;
    int text;
};

struct Object_0006E130 {
    int func_0006E130(int id);
};

// The class whose table is at 0x1DEA60 (destructor 0x1379E0).
struct Object_001379E0 {
    char unknown_000[0x2b0];
    int state;
    char unknown_2b4[0x1c];
    Interface_00136690 *panel;

    void func_00139260(float depth);
};

extern Device_00251D6C *data_00251D6C;
extern int data_00251D54;
extern Object_0006E130 data_00252790;
extern Object_00043700 data_001FC724;
extern Line_00139260 data_0022DA28[];

void *func_00025700(unsigned int index, int first, int second, int third);
void func_0003D610(float x, float y, float scale, unsigned int color, float width, float height, int text);

// In state 10: draws the panel at +0x2d0 (texture 3 of group 0x12, from (145, 140) to (495, 340)) at `depth`
// (offset -0.1), then the lines of data_0022DA28 (up to language -1) for the current language, 24 apart from
// y 155 at x 160.
void Object_001379E0::func_00139260(float depth)
{
    if (state == 10) {
        if (panel->slot3() >= 0) {
            int texture = data_00252790.func_0006E130((int)func_00025700(0x12, 1, 1, 3));
            if (data_00251D54 != texture) {
                data_00251D54 = texture;
                data_00251D6C->slot81(0, texture);
            }
            Vertex_00139260 vertices[4];
            vertices[0].x = vertices[2].x = 145.0f;
            vertices[0].y = vertices[1].y = 140.0f;
            vertices[1].x = vertices[3].x = 495.0f;
            vertices[2].y = vertices[3].y = 340.0f;
            vertices[0].u = vertices[2].u = 0.642578125f;
            vertices[0].v = vertices[1].v = 0.015625f;
            vertices[1].u = vertices[3].u = 0.9853515625f;
            vertices[2].v = vertices[3].v = 0.2119140625f;
            vertices[0].color = vertices[1].color = vertices[2].color = vertices[3].color = 0xffffffff;
            vertices[0].value_0c = vertices[1].value_0c = vertices[2].value_0c = vertices[3].value_0c = 0;
            panel->slot8(depth, -0.1f);
            panel->slot5(vertices, 0);
            panel->slot4();
        }
        panel->slot10(1);
        unsigned int offset = 0;
        for (int i = 0; data_0022DA28[i].language != -1; i++) {
            if (data_0022DA28[i].language == data_001FC724.func_00043700()) {
                func_0003D610(160.0f, (float)offset + 155.0f, depth, 0xff000000, 0.7f, 0.8f, data_0022DA28[i].text);
                offset += 24;
            }
        }
    }
}
