/* sym: ?func_00011C80_1@Object_00050FE0@@UAEXH@Z = 0x00051130 */
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
    char unknown_80[0x14];
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
};

extern Device_00251D6C *data_00251D6C;

struct Object_0006A960 {
    void func_0006A970(Vector3 *position);
};

struct Object_00046670 {
    void func_00046670(Vector3 *position);
    void func_00046940(int enable);
};

struct Game {
    void func_00012750();
};

extern Object_0006A960 data_0020C6C0;
extern Object_00046670 data_001F93C8;
extern Game *data_0022FCE0;

void __fastcall func_001BAF70(Vector3 *eye, Vector3 *target, int roll);

// The class whose table is at 0x1CADA8: overrides slots 5 (50FF0), 6 (51130).
struct Object_00050FE0 : Object_00012170 {
    virtual ~Object_00050FE0();
    virtual void func_00011C90_3();
    virtual void func_00011C80_1(int argument);

    void *unknown_98;
    int unknown_9c;
};

// Slot 6: message 0x13 sets up the view from the camera (projection, look-at) and the light at the eye.
void Object_00050FE0::func_00011C80_1(int argument)
{
    if (argument == 0x13) {
        data_00251D6C->slot30(0);
        data_00251D6C->slot31(fov, 1.0f, 5000.0f);
        func_001BAF70(&eye, &target, roll);
        data_0020C6C0.func_0006A970(&eye);
        data_001F93C8.func_00046670(&eye);
        data_001F93C8.func_00046940(0);
        data_0022FCE0->func_00012750();
    }
}
