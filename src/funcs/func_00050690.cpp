/* cflags: /Oy- */
/* sym: ?func_00011C80@Object_00050320@@UAEXH@Z = 0x00050690 */
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

struct Game {
    void func_00012750();
    void *func_000128C0(int index);
    void func_00012980();
};

extern Game *data_0022FCE0;

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
    virtual void __stdcall slot42(int value);
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
    virtual void __stdcall slot82();
    virtual void __stdcall slot83();
    virtual void __stdcall slot84();
    virtual void __stdcall slot85(int first, int second);
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

extern Light_001EC020 data_001FA080;
extern int data_00251D54;
extern int data_00251D58;
extern int data_00251D88;

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
    int func_0006E130(int id);
};

extern Object_0006E130 data_00252790;

void __fastcall func_001BAF70(Vector3 *eye, Vector3 *target, int roll);

// Sets stage `stage` of the texture state at 0x251D54 (stage 0) or 0x251D58 (stage 1) when it changes.
#define SET_STAGE(cache, stage, value) \
    if (cache != (value)) { \
        cache = (value); \
        data_00251D6C->slot81(stage, (value)); \
    }

// What object 0x12ad holds: an id at +0xa4.
struct Object_00050690 {
    char unknown_00[0xa4];
    int id;
};

// The class whose table is at 0x1CAC18: overrides slots 1 (50330), 2 (504E0), 3 (50690).
struct Object_00050320 : Object_00012170 {
    virtual ~Object_00050320();
    virtual void func_00011C90();
    virtual void func_00011C90_1();
    virtual void func_00011C80(int argument);

    int unknown_98;
    void *unknown_9c;
    int unknown_a0;
};

// Slot 3, when +0x98 is set: on event 0x13 sets the view from the camera and places the lights; on event 0x14 draws
// with the texture of object 0x12ad's id and the light at 0x1FA080.
void Object_00050320::func_00011C80(int argument)
{
    if (unknown_98 == 0) {
        return;
    }
    switch (argument) {
    case 0x13:
        if (data_00251D88 != -1) {
            data_00251D88 = -1;
            data_00251D6C->slot42(-1);
        }
        data_0022FCE0->func_00012980();
        data_00251D6C->slot30(&left);
        data_00251D6C->slot31(fov, 1.0f, 5000.0f);
        func_001BAF70(&eye, &target, roll);
        data_0020C6C0.func_0006A970(&eye);
        data_001F93C8.func_00046670(&eye);
        data_001F93C8.func_00046940(0);
        data_0022FCE0->func_00012750();
        break;
    case 0x14: {
        data_00251D6C->slot30(0);
        Object_00050690 *object = (Object_00050690 *)data_0022FCE0->func_000128C0(0x12ad);
        if (object == 0) {
            break;
        }
        data_00251D6C->slot85(0, 0);
        SET_STAGE(data_00251D54, 0, data_00252790.func_0006E130(object->id));
        SET_STAGE(data_00251D58, 1, -1);
        data_00251D78->slot9(&data_001FA080, 0);
        SET_STAGE(data_00251D54, 0, -1);
        data_00251D6C->slot85(0, 1);
        break;
    }
    }
}
