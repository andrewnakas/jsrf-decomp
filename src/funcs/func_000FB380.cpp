/* sym: ?func_00011C80@Object_000FB530@@UAEXH@Z = 0x000FB380 */
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

// A model from func_00025700; its slot 5 poses it.
struct Model_000FDDC0 {
    virtual void func_00();
    virtual void func_04();
    virtual void func_08();
    virtual void func_0C();
    virtual void func_10();
    virtual void func_14(Motion_0005F060 *motion, float time);
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
    virtual void __stdcall slot30();
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
void func_001BAA50();

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// The child of Node whose table is at 0x1D1BA8 (constructor func_000FD870); slot 16 is func_000FDDC0, and the
// classes with tables 0x1D08E0 and 0x1D1B20 derive from it.
struct Object_000FDDC0 : Node {
    virtual ~Object_000FDDC0();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C90_2();
    virtual void func_00011C80_1(int argument);
    virtual void func_00011C90_6();
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C90_8();
    virtual void func_00011C80_4(int argument);
    virtual void func_000FDDC0();

    char unknown_040[4];
    void *buffer;
};

// The child of that class whose table is at 0x1D1B20 (constructor func_000FB870, destructor func_000FB300).
struct Object_000FB530 : Object_000FDDC0 {
    virtual ~Object_000FB530();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_000FDDC0();

    char unknown_048[0x48];
    Model_000FDDC0 *model;
    int value_94;
    int unknown_098;
    Vector3 position;
    char unknown_0a8[0xc];
    void *data;
    char unknown_0b8[0x14];
    int targetId;
};

// Slot 3: unless 0x94 is 0 or 1, on 0, 3, 5 and 8 with a model, the data at 0xb4 and the object whose id is at 0xcc,
// draws the model at the position at 0x9c, scale 1, under a white light from straight ahead, with device slot 33 at
// -25 and render state data_001FA1D0 at 1 (device slot 73). On 2 and 7, depth 0.5.
void Object_000FB530::func_00011C80(int argument)
{
    if (value_94 == 0 || value_94 == 1) {
        return;
    }
    switch (argument) {
    case 0:
    case 3:
    case 5:
    case 8:
        if (model && data && data_0022FCE0->func_000128C0(targetId)) {
            data_00251D6C->slot33(-25.0f);
            int saved = data_001FA1D0;
            if (saved != 1) {
                data_001FA1D0 = 1;
                data_00251D6C->slot73(1);
            }
            func_001BA9C0();
            func_001BA8A0();
            func_001BAAA0(&position.x);
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
            func_001BB650(1.0f);
            model->func_14(0, 0.0f);
            data_001F93C8.func_00046A30();
            func_001BAA50();
            if (data_001FA1D0 != saved) {
                data_001FA1D0 = saved;
                data_00251D6C->slot73(saved);
            }
            data_00251D6C->slot33(0.0f);
        }
        break;
    case 2:
    case 7:
        depth = 0.5f;
        break;
    }
}
