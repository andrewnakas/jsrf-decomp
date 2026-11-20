/* cflags: /Oy- */
/* sym: ?func_00011C80@Object_000A4D80@@UAEXH@Z = 0x000A2960 */
struct Vector3 {
    float x;
    float y;
    float z;
};

struct Node {
    Node(Node *owner, int id, unsigned int flags);
    virtual ~Node();
    virtual void func_00011C90();
    virtual void func_00011C90_1();
    virtual void func_00011C80(int argument);

    unsigned int flags;
    int id;
    unsigned int mask;
    float depth;
    int sortKey;
    char unknown_18[0xc];
    Node *parent;
    Node *child;
    Node *previous;
    Node *next;
    char unknown_34[0x10];

    Node *func_00011BD0();
};

// A camera node (table 0x1C43D8 repeats Node's slots 1 to 15; mask 7): eye, target, field of view and roll.
struct Object_00012170 : Node {
    Object_00012170(Node *owner, int id, unsigned int flags);

    Vector3 eye;
    char unknown_50[0xc];
    Vector3 target;
    char unknown_68[0xc];
    unsigned int fov;
    int unknown_78;
    int roll;
    int unknown_80;
    int left;
    int top;
    int width;
    int height;
    int unknown_94;
};

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
    virtual void __stdcall slot30(const void *viewport);
    virtual void __stdcall slot31(unsigned int value, float first, float second);
    virtual void __stdcall slot32();
    virtual void __stdcall slot33();
    virtual void __stdcall slot34();
    virtual void __stdcall slot35();
    virtual void __stdcall slot36();
    virtual void __stdcall slot37(void *out, const void *in, float scale);
    virtual void __stdcall slot38();
    virtual void __stdcall slot39();
    virtual void __stdcall slot40();
    virtual void __stdcall slot41();
    virtual void __stdcall slot42(int target);
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
    virtual void __stdcall slot68(int value);
    virtual void __stdcall slot69();
    virtual void __stdcall slot70();
    virtual void __stdcall slot71(int value);
    virtual void __stdcall slot72();
    virtual void __stdcall slot73(int value);
    virtual void __stdcall slot74();
    virtual void __stdcall slot75();
    virtual void __stdcall slot76();
    virtual void __stdcall slot77();
    virtual void __stdcall slot78();
    virtual void __stdcall slot79();
    virtual void __stdcall slot80();
    virtual void __stdcall slot81(int stage, int texture);
    virtual void __stdcall slot82(int stage, int value);
    virtual void __stdcall slot83();
    virtual void __stdcall slot84();
    virtual void __stdcall slot85(int first, int second);
    virtual void __stdcall slot86();
    virtual void __stdcall slot87();
    virtual void __stdcall slot88();
    virtual void __stdcall slot89();
    virtual void __stdcall slot90();
    virtual void __stdcall slot91();
    virtual void __stdcall slot92();
    virtual void __stdcall slot93(int index, const void *data);
};

extern Device_00251D6C *data_00251D6C;

struct Interface_00251D78 {
    virtual void __stdcall slot0();
    virtual void __stdcall slot1();
    virtual void __stdcall slot2();
    virtual void __stdcall slot3();
    virtual void __stdcall slot4();
    virtual void __stdcall slot5();
    virtual void __stdcall slot6();
    virtual void __stdcall slot7();
    virtual void __stdcall slot8(float value, int argument);
    virtual void __stdcall slot9(void *data, int argument);
};

extern Interface_00251D78 *data_00251D78;

struct Pass_000A2960 {
    virtual void __stdcall slot0();
    virtual void __stdcall slot1();
    virtual void __stdcall slot2();
    virtual int __stdcall slot3();
    virtual void __stdcall slot4();
};

struct Context_00251D7C {
    char unknown_000[0x570];
    Pass_000A2960 *pass;
};

extern Context_00251D7C *data_00251D7C;

// The surface at +0x178: slot 3 opens a handle, slot 5 closes it, slot 16 presents it.
struct Surface_000A2960 {
    virtual void __stdcall slot0();
    virtual void __stdcall slot1();
    virtual void __stdcall slot2();
    virtual int __stdcall slot3(int flags, void *settings, int argument);
    virtual void __stdcall slot4();
    virtual void __stdcall slot5(int handle);
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
    virtual void __stdcall slot16(int handle);
};

// The quad drawer at +0x180.
struct Drawer_000A2960 {
    virtual void __stdcall slot0();
    virtual void __stdcall slot1();
    virtual void __stdcall slot2();
    virtual void __stdcall slot3();
    virtual void __stdcall slot4();
    virtual void __stdcall slot5();
    virtual void __stdcall slot6();
    virtual void __stdcall slot7();
    virtual void __stdcall slot8(float scale, float alpha);
    virtual void __stdcall slot9(void *vertices, int argument);
};

// A screen vertex with texture coordinates (0x1c bytes).
struct TexturedVertex_000A2960 {
    float x;
    float y;
    float z;
    float u;
    float v;
    float unknown_14[2];
};

// A screen vertex with a colour (0x18 bytes).
struct ColoredVertex_000A2960 {
    float x;
    float y;
    unsigned int color;
    float unknown_0c[3];
};

extern unsigned char data_00215448[];
extern TexturedVertex_000A2960 data_00215458[4];
extern ColoredVertex_000A2960 data_002154C8[4];
extern ColoredVertex_000A2960 data_00215740[2];

extern int data_001FA1CC;
extern int data_001FA1D0;
extern int data_00251D80;
extern int data_00251D44;
extern int data_00251D54;
extern int data_00251D58;
extern int data_00251D88;

struct Object_0006E130 {
    int func_0006E130(int id);
};

extern Object_0006E130 data_00252790;

struct Object_0006A960 {
    void func_0006A970(Vector3 *position);
};

struct Object_00046670 {
    void func_00046670(Vector3 *position);
    void func_00046940(int enable);
};

struct Game {
    void func_00012750();
    void func_00012980();
};

extern Object_0006A960 data_0020C6C0;
extern Object_00046670 data_001F93C8;
extern Game *data_0022FCE0;

void __fastcall func_001BAF70(Vector3 *eye, Vector3 *target, int roll);
void func_001BAA00();
void func_001BAA50();
int func_0004EA70();

struct Object_000A1C50 {
    char unknown_000[0xe60];
    unsigned int value_e60;

    int func_0007F500();
};

// The class whose table is at 0x1CD518 (constructor 0xA4D80, destructor 0xA2820): overrides slots 1 (A5070),
// 2 (A28B0), 3 (A2960), 15 (B3DE0).
struct Object_000A4D80 : Object_00012170 {
    virtual ~Object_000A4D80();
    virtual void func_00011C80(int argument);

    char unknown_098[0xd4];
    int texture_16c;
    int texture_170;
    int texture_174;
    Surface_000A2960 *surface;
    int unknown_17c;
    Drawer_000A2960 *drawer;
    int handle;
    char settings[0x24];
    unsigned int phase;
    unsigned int alpha;
    float offset;
    char unknown_1b8[0x24];
    unsigned int color;
};

// Slot 3. Message 0x14 (after drawing): while the player's effect runs, blurs the frame into the surface and
// draws it back over the screen with a fading alpha, then draws the colour overlay when it is not transparent.
// Message 0x13 (before drawing): renders into one of two textures in turn while the effect runs (else resets it),
// then sets up the viewport, the view from the camera and the light at the eye.
void Object_000A4D80::func_00011C80(int argument)
{
    Object_000A1C50 *player = (Object_000A1C50 *)func_00011BD0();
    switch (argument) {
    case 0x14:
        data_00251D6C->slot30(&left);
        data_00251D6C->slot31(fov, 1.0f, 5000.0f);
        if (player->value_e60 > 0 && (func_0004EA70() & 0x80) && player->func_0007F500()) {
            if (phase == 1) {
                func_001BAA00();
                data_00215458[0].x = (float)left;
                data_00215458[0].y = (float)top;
                data_00215458[1].x = (float)width;
                data_00215458[1].y = (float)top;
                data_00215458[2].x = (float)left;
                data_00215458[2].y = (float)height;
                data_00215458[3].x = (float)width;
                data_00215458[3].y = (float)height;
                data_00251D6C->slot31(0x2aaa, 1.0f, 20.0f);
                data_00251D6C->slot37(&data_00215458[0], &data_00215458[0], 2.45f);
                data_00251D6C->slot37(&data_00215458[1], &data_00215458[1], 2.45f);
                data_00251D6C->slot37(&data_00215458[2], &data_00215458[2], 2.45f);
                data_00251D6C->slot37(&data_00215458[3], &data_00215458[3], 2.45f);
                func_001BAA50();
                data_002154C8[0].x = (float)left;
                data_002154C8[0].y = (float)top;
                data_002154C8[1].x = (float)width;
                data_002154C8[1].y = (float)top;
                data_002154C8[2].x = (float)left;
                data_002154C8[2].y = (float)height;
                data_002154C8[3].x = (float)width;
                data_002154C8[3].y = (float)height;
            }
            data_00251D6C->slot85(1, 0);
            surface->slot5(handle);
            if (alpha > 0x3c) {
                offset += 0.0018f;
            }
            data_00215458[0].u = offset;
            data_00215458[0].v = offset;
            data_00215458[1].u = 1.0f - offset;
            data_00215458[1].v = offset;
            data_00215458[2].u = offset;
            data_00215458[2].v = 1.0f - offset;
            data_00215458[3].u = 1.0f - offset;
            data_00215458[3].v = 1.0f - offset;
            handle = surface->slot3(0x202, settings, 0);
            func_001BAA00();
            if (data_001FA1CC != 0) {
                data_001FA1CC = 0;
                data_00251D6C->slot71(0);
            }
            if (data_00251D80 != 0) {
                data_00251D80 = 0;
                data_00251D6C->slot68(0);
            }
            if (data_001FA1D0 != 0) {
                data_001FA1D0 = 0;
                data_00251D6C->slot73(0);
            }
            if (data_00251D54 != data_00252790.func_0006E130(texture_174)) {
                data_00251D54 = data_00252790.func_0006E130(texture_174);
                data_00251D6C->slot81(0, data_00252790.func_0006E130(texture_174));
            }
            if (data_00251D58 != data_00252790.func_0006E130(texture_170)) {
                data_00251D58 = data_00252790.func_0006E130(texture_170);
                data_00251D6C->slot81(1, data_00252790.func_0006E130(texture_170));
            }
            if (data_00251D7C->pass->slot3() >= 0) {
                data_00251D6C->slot93(1, data_00215448);
                data_00251D6C->slot31(0x2aaa, 1.0f, 20.0f);
                if (phase != 1) {
                    surface->slot16(handle);
                }
                data_00251D7C->pass->slot4();
            }
            func_001BAA50();
            func_001BAA00();
            if (data_001FA1CC != 0) {
                data_001FA1CC = 0;
                data_00251D6C->slot71(0);
            }
            if (data_00251D80 != 0) {
                data_00251D80 = 0;
                data_00251D6C->slot68(0);
            }
            if (phase < 0x8c) {
                alpha -= 4;
            } else {
                alpha += 4;
            }
            if (alpha < 0x80) {
                alpha = 0x80;
            }
            if (alpha > 0xff) {
                alpha = 0xff;
            }
            data_002154C8[0].color = alpha << 24 | 0xffffff;
            data_002154C8[1].color = alpha << 24 | 0xffffff;
            data_002154C8[2].color = alpha << 24 | 0xffffff;
            data_002154C8[3].color = alpha << 24 | 0xffffff;
            if (phase == 1) {
                if (data_001FA1D0 != 0) {
                    data_001FA1D0 = 0;
                    data_00251D6C->slot73(0);
                }
            } else {
                if (data_001FA1D0 != 1) {
                    data_001FA1D0 = 1;
                    data_00251D6C->slot73(1);
                }
            }
            drawer->slot8(1.45f, 1.0f);
            data_00251D6C->slot85(0, 0);
            if (data_00251D44 != 6) {
                data_00251D44 = 6;
                data_00251D6C->slot82(0, 6);
            }
            if (data_00251D54 != data_00252790.func_0006E130(texture_16c)) {
                data_00251D54 = data_00252790.func_0006E130(texture_16c);
                data_00251D6C->slot81(0, data_00252790.func_0006E130(texture_16c));
            }
            if (data_00251D58 != -1) {
                data_00251D58 = -1;
                data_00251D6C->slot81(1, -1);
            }
            drawer->slot9(data_002154C8, 0);
            if (data_00251D44 != 2) {
                data_00251D44 = 2;
                data_00251D6C->slot82(0, 2);
            }
            if (data_00251D54 != -1) {
                data_00251D54 = -1;
                data_00251D6C->slot81(0, -1);
            }
            data_00251D6C->slot85(0, 1);
            func_001BAA50();
            if (data_00251D58 != -1) {
                data_00251D58 = -1;
                data_00251D6C->slot81(1, -1);
            }
            data_00251D6C->slot85(1, 1);
        }
        if (color & 0xff000000) {
            int saved = data_001FA1D0;
            if (saved != 1) {
                data_001FA1D0 = 1;
                data_00251D6C->slot73(1);
            }
            data_00215740[0].color = color;
            data_00215740[1].color = color;
            if (data_00251D54 != -1) {
                data_00251D54 = -1;
                data_00251D6C->slot81(0, -1);
            }
            if (data_00251D58 != -1) {
                data_00251D58 = -1;
                data_00251D6C->slot81(1, -1);
            }
            data_00251D78->slot8(2.0f, 0);
            data_00251D78->slot9(data_00215740, 1);
            data_00251D78->slot8(5.0f, 0);
            if (data_001FA1D0 != saved) {
                data_001FA1D0 = saved;
                data_00251D6C->slot73(saved);
            }
        }
        data_0022FCE0->func_00012750();
        break;
    case 0x13:
        if (player->value_e60 > 0 && (func_0004EA70() & 0x80) && player->func_0007F500()) {
            phase++;
            if ((phase & 1) == 0) {
                if (data_00251D88 != data_00252790.func_0006E130(texture_170)) {
                    data_00251D88 = data_00252790.func_0006E130(texture_170);
                    data_00251D6C->slot42(data_00252790.func_0006E130(texture_170));
                }
            } else {
                if (data_00251D88 != data_00252790.func_0006E130(texture_16c)) {
                    data_00251D88 = data_00252790.func_0006E130(texture_16c);
                    data_00251D6C->slot42(data_00252790.func_0006E130(texture_16c));
                }
            }
            data_0022FCE0->func_00012980();
            data_00251D6C->slot30(0);
        } else {
            phase = 0;
            offset = 0.0f;
            alpha = 0xff;
            if (data_00251D88 != -1) {
                data_00251D88 = -1;
                data_00251D6C->slot42(-1);
            }
            data_00251D6C->slot30(&left);
        }
        data_00251D6C->slot31(fov, 1.0f, 5000.0f);
        func_001BAF70(&eye, &target, roll);
        data_0020C6C0.func_0006A970(&eye);
        data_001F93C8.func_00046670(&eye);
        data_001F93C8.func_00046940(0);
        data_0022FCE0->func_00012750();
        break;
    }
}
