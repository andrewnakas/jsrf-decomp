/* sym: ?func_00011C80@Object_00135130@@UAEXH@Z = 0x00135140 */
struct Vector3 {
    float x;
    float y;
    float z;
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
    virtual void __stdcall slot20(const Vector3 *direction);
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
    void func_00046670(Vector3 *position);
    void func_00046740(Light_00046920 *light);
    void func_00046920(Light_00046920 *light);
    void func_00046940(int enable);
};

struct Game {
    void func_00012750();
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
    char unknown_34[0x60];
};

// The class whose table is at 0x1DE938: overrides slot 3 of Node.
struct Object_00135130 : Node {
    virtual ~Object_00135130();
    virtual void func_00011C80(int argument);

    int unknown_94;
    Vector3 eye;
    Vector3 target;
};

extern Device_00251D6C *data_00251D6C;
extern unsigned char data_0022C6F4[];
extern Object_00046670 data_001F93C8;
extern Game *data_0022FCE0;
void __fastcall func_001BAF70(Vector3 *eye, Vector3 *target, int roll);

// Slot 3: sets up the device and the view as at construction, then the light: the default from func_00046920
// with its colours and direction set, through func_00046670, func_00046740 and func_00046940; then
// func_00012750 of the game. The argument is not read.
void Object_00135130::func_00011C80(int)
{
    Light_00046920 light;
    data_00251D6C->slot30(data_0022C6F4);
    data_00251D6C->slot31(0x18e3, 1.0f, 20000.0f);
    func_001BAF70(&eye, &target, 0);
    data_001F93C8.func_00046670(&target);
    data_001F93C8.func_00046920(&light);
    light.value_50 = 0;
    light.color_48 = 0xffffff;
    light.color_40 = 0xffffff;
    light.direction.x = 1.0f;
    light.direction.y = -0.6f;
    light.direction.z = 0.6f;
    light.color_04 = 0xffffff;
    light.color_08 = 0x8c8c8c;
    data_001F93C8.func_00046740(&light);
    data_001F93C8.func_00046940(0);
    data_0022FCE0->func_00012750();
}
