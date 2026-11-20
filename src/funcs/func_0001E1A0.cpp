/* sym: ?func_00011C80_3@Object_0001E140@@UAEXH@Z = 0x0001E1A0 */
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

// A camera node (as in 0x1DAA0): eye at +0x44, target at +0x5c, field of view at +0x74, roll at +0x7c and the
// viewport from +0x84.
struct Object_00012170 : Node {
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
    virtual void __stdcall slot42(int value);
};

extern Device_00251D6C *data_00251D6C;
extern int data_00251D88;

struct Game {
    void func_00012750();
};

extern Game *data_0022FCE0;

struct Object_0006A960 {
    void func_0006A970(Vector3 *position);
};

extern Object_0006A960 data_0020C6C0;

// The light stack (data_001F93C8).
struct Object_00046670 {
    void func_00046670(Vector3 *position);
    void func_00046940(int enable);
};

extern Object_00046670 data_001F93C8;

void __fastcall func_001BAF70(Vector3 *eye, Vector3 *target, int roll);

// The node class whose table is at 0x1C45C8 (destructor 0x1E140): overrides slots 10 (42880), 11 (1E3C0) and 12
// (1E1A0).
struct Object_0001E140 : Object_00012170 {
    virtual ~Object_0001E140();
    virtual void func_00011C80_3(int message);
};

// Slot 12 (also of the tables at 0x1CA5F0, 0x1CA630 and in 0x1CA6C8): on message 0x13 drops the bound texture, sets
// the viewport and a projection (depth 1 to 5000) from the field of view, the view from eye, target and roll, and
// hands the eye to data_0020C6C0 and the light stack (lights off); on 0x14 only the viewport and projection. Both end
// with func_00012750 of the game.
void Object_0001E140::func_00011C80_3(int message)
{
    switch (message) {
    case 0x13:
        if (data_00251D88 != -1) {
            data_00251D88 = -1;
            data_00251D6C->slot42(-1);
        }
        data_00251D6C->slot30(&left);
        data_00251D6C->slot31(fov, 1.0f, 5000.0f);
        func_001BAF70(&eye, &target, roll);
        data_0020C6C0.func_0006A970(&eye);
        data_001F93C8.func_00046670(&eye);
        data_001F93C8.func_00046940(0);
        data_0022FCE0->func_00012750();
        break;
    case 0x14:
        data_00251D6C->slot30(&left);
        data_00251D6C->slot31(fov, 1.0f, 5000.0f);
        data_0022FCE0->func_00012750();
        break;
    }
}
