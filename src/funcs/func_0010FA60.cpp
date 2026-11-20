/* sym: ?func_00011C80@Object_0010F950@@UAEXH@Z = 0x0010FA60 */
struct Vector3 {
    float x;
    float y;
    float z;
};

struct Node {
    virtual ~Node();
    virtual void func_00011C90();
    virtual void func_00011C90_1();
    virtual void func_00011C80(int argument);
    virtual void func_00011C90_2();
    virtual void func_00011C90_3();
    virtual void func_00011C80_1(int argument);
    virtual void func_00011C90_4();
    virtual void func_00011C90_5();
    virtual void func_00011C80_2(int argument);
    virtual void func_00011C90_6();
    virtual void func_00011C90_7();
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C90_8();
    virtual void func_00011C90_9();
    virtual void func_00011C80_4(int argument);

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
    Node *drawNext;
    Node **drawLink;
    Node ***drawTail;
};


struct Motion_0005F060;

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
    virtual void __stdcall slot30(const void *settings);
    virtual void __stdcall slot31();
    virtual void __stdcall slot32();
    virtual void __stdcall slot33(float value);
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
    virtual void __stdcall slot73(int value);
};

extern Device_00251D6C *data_00251D6C;
extern int data_001FA1D0;

void func_001BA9C0();
void func_001BA8A0();
void __fastcall func_001BAAA0(float *vector);
void func_001BB650(float scale);
struct Light_00046920 {
    int unknown_00;
    unsigned int color_04;
    unsigned int color_08;
    int unknown_0c;
    Vector3 direction;
    char unknown_1c[0x24];
    unsigned int color_40;
    int unknown_44;
    unsigned int color_48;
    int unknown_4c;
    int value_50;
    char unknown_54[0x1c];
};

struct Object_00046670 {
    void func_000466D0();
    void func_00046740(Light_00046920 *light);
    void func_00046940(int enable);
    void func_00046A30();
};

extern Object_00046670 data_001F93C8;
extern Light_00046920 *data_001F963C;
void __fastcall func_001BAA50();


void func_001BAA00();
void func_001BB670(float angle);
unsigned int func_0014C690(float value);
void func_001BB230(float x, float y, float z);
void __fastcall func_001BAAE0(float *matrix);

// A frame of the model's mesh: two matrices at 0x14 and 0x54.
struct Frame_0010FA60 {
    char unknown_00[0x14];
    float first[16];
    float second[16];
};

// The models of the six sprites; slot 5 draws one, func_00047F40 sets its colour.
struct Model_00133370 {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5(int first, int second);

    void *surface;
    Frame_0010FA60 *frames;

    void func_00047F40(int value);
};

// A direct child of Node (table 0x1D2538, constructor func_0010F870, destructor func_0010F950).
struct Object_0010F950 : Node {
    virtual ~Object_0010F950();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C90_2();
    virtual void func_00011C80_1(int argument);

    int unknown_040;
    int value;
    int mode;
    int frame;
    Model_00133370 *sprites[6];
    int state;
    int unknown_6c;
    char unknown_070[4];
    Vector3 position;
    float fade;
};

// Slot 3: on 0 and 8, with device slot 33 at -25, draws at the position at 0x74 (pushed back 3) under a white light
// from straight ahead the five sprites other than the current frame (0x4c), then the current one: while the fade at
// 0x80 runs (0 to 1) a copy pushed back 0.5 with alpha fade * 127.5 and, while 3 - 2 * fade is above 1, scaled by it
// in x and y; then the sprite itself pushed back 1 in two colours (0xff00dcdc and 0xff007f66). On 7, depth 1.1.
void Object_0010F950::func_00011C80(int argument)
{
    switch (argument) {
    case 0:
    case 8: {
        data_00251D6C->slot33(-25.0f);
        func_001BAA00();
        func_001BAAA0(&position.x);
        func_001BB650(-3.0f);
        Light_00046920 light = *data_001F963C;
        light.direction.x = 0.0f;
        light.direction.y = 0.0f;
        light.direction.z = 1.0f;
        light.value_50 = 0;
        light.color_04 = 0xffffff;
        light.color_08 = 0;
        data_001F93C8.func_000466D0();
        data_001F93C8.func_00046740(&light);
        data_001F93C8.func_00046940(0);
        for (int i = 0; i < 6; i++) {
            if (i != frame && sprites[i]) {
                sprites[i]->slot5(0, 0);
            }
        }
        if (sprites[frame]) {
            func_001BA9C0();
            if (0.0f < fade && fade < 1.0f) {
                float scale = 3.0f - (fade + fade);
                func_001BA9C0();
                func_001BB670(-0.5f);
                if (fade < 1.0f) {
                    sprites[frame]->func_00047F40(func_0014C690(fade * 127.5f) << 24 | 0xdcdc);
                }
                if (scale > 1.0f) {
                    func_001BAAA0(sprites[frame]->frames->first);
                    func_001BAAA0(sprites[frame]->frames->second);
                    func_001BB230(scale, scale, 1.0f);
                    func_001BAAE0(sprites[frame]->frames->second);
                    func_001BAAE0(sprites[frame]->frames->first);
                }
                sprites[frame]->slot5(0, 0);
                func_001BAA50();
            }
            func_001BB670(-1.0f);
            sprites[frame]->func_00047F40(0xff00dcdc);
            sprites[frame]->slot5(0, 0);
            sprites[frame]->func_00047F40(0xff007f66);
            func_001BAA50();
        }
        data_001F93C8.func_00046A30();
        func_001BAA50();
        data_00251D6C->slot33(0.0f);
        break;
    }
    case 7:
        depth = 1.1f;
        break;
    }
}
