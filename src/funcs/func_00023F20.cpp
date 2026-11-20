/* cflags: /Oy- */
/* sym: ?func_00011C80_1@Object_000239D0@@UAEXH@Z = 0x00023F20 */
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
    char unknown_34[0x10];
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
    virtual void __stdcall slot30(const void *settings);
    virtual void __stdcall slot31(unsigned int value, float first, float second);
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
    virtual void __stdcall slot73(int value);
    virtual void __stdcall slot74();
    virtual void __stdcall slot75();
    virtual void __stdcall slot76();
    virtual void __stdcall slot77();
    virtual void __stdcall slot78();
    virtual void __stdcall slot79();
    virtual void __stdcall slot80();
    virtual void __stdcall slot81(int first, int second);
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

struct Light_001EC020 {
    int unknown_00[2];
    unsigned int color;
    int unknown_0c[5];
    unsigned int ambient;
};

extern Light_001EC020 data_001EBFE0;
extern int data_00251D54;
extern int data_00251D58;
extern int data_001FA1D0;
extern char data_001EBF20[][0x10];

struct Light_00046920 {
    char unknown_00[0x64];
    unsigned int unknown_64;
    unsigned int unknown_68;
};

extern Light_00046920 *data_001F963C;

struct Object_00046670 {
    void func_00046670(Vector3 *position);
    void func_00046940(int enable);
};

extern Object_00046670 data_001F93C8;

struct Object_0006A960 {
    void func_0006A970(Vector3 *position);
};

extern Object_0006A960 data_0020C6C0;

struct Object_0006E130 {
    void func_0006E0F0(unsigned int value);
    void func_0006E110(unsigned int value);
};

extern Object_0006E130 data_00252790;

struct Game {
    void func_00012750();
};

extern Game *data_0022FCE0;

void __fastcall func_001BAF70(Vector3 *eye, Vector3 *target, int roll);

// Sets the render state at 0x1FA1D0 when it changes.
inline void setState_00023F20(int value)
{
    if (data_001FA1D0 != value) {
        data_001FA1D0 = value;
        data_00251D6C->slot73(value);
    }
}

// The class whose table is at 0x1C4C88: overrides slots 4 (23C50), 5 (23F10), 6 (23F20).
struct Object_000239D0 : Object_00012170 {
    virtual ~Object_000239D0();
    virtual void func_00011C90_2();
    virtual void func_00011C90_3();
    virtual void func_00011C80_1(int argument);

    char unknown_98[0x08];
    int settings;
    int useEye;
    int notify;
    char unknown_ac[0x24];
    unsigned int color;
    int unknown_d4;
    Vector3 viewEye;
    Vector3 viewTarget;
    int viewRoll;
    unsigned int value;
};

// Slot 6: on event 0x14 puts the colour (when it is not transparent) into the light at 0x1EBFE0 and sets the light;
// on event 0x13 sets the view from the node's own eye and target and places the lights. Both then tell the game
// (func_00012750) when `notify` is set.
void Object_000239D0::func_00011C80_1(int argument)
{
    Vector3 distant = {100000.0f, 100000.0f, 100000.0f};
    switch (argument) {
    case 0x13:
        if (viewTarget.x == viewEye.x && viewTarget.y == viewEye.y && viewTarget.z == viewEye.z) {
            viewTarget.x += 1.0f;
        }
        data_00251D6C->slot30(data_001EBF20[settings]);
        data_00251D6C->slot31(value, 1.5f, 5000.0f);
        func_001BAF70(&viewEye, &viewTarget, viewRoll);
        if (useEye) {
            data_0020C6C0.func_0006A970(&viewEye);
        } else {
            data_0020C6C0.func_0006A970(&distant);
        }
        data_001F93C8.func_00046670(&eye);
        data_001F93C8.func_00046940(0);
        data_00252790.func_0006E0F0(data_001F963C->unknown_64);
        data_00252790.func_0006E110(data_001F963C->unknown_68);
        break;
    case 0x14:
        if (color & 0xff000000) {
            int saved = data_001FA1D0;
            setState_00023F20(1);
            data_001EBFE0.color = color;
            data_001EBFE0.ambient = color;
            if (data_00251D54 != -1) {
                data_00251D54 = -1;
                data_00251D6C->slot81(0, -1);
            }
            if (data_00251D58 != -1) {
                data_00251D58 = -1;
                data_00251D6C->slot81(1, -1);
            }
            data_00251D78->slot8(1.51f, 0);
            data_00251D78->slot9(&data_001EBFE0, 1);
            data_00251D78->slot8(5.0f, 0);
            setState_00023F20(saved);
        }
        break;
    default:
        return;
    }
    if (notify) {
        data_0022FCE0->func_00012750();
    }
}
