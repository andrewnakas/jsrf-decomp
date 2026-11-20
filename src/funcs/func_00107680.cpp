/* sym: ?func_00011C80@Object_00107FE0@@UAEXH@Z = 0x00107680 */
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

    void func_00011BE0(Node *node);
    void func_00011C20(Node *node);
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
    virtual void __stdcall slot31(unsigned int value, float first, float second);
    virtual void __stdcall slot32();
    virtual void __stdcall slot33(float value);
};

extern Device_00251D6C *data_00251D6C;

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
    void func_00046700(const Light_00046920 *light);
    void func_00046740(Light_00046920 *light);
    void func_00046940(int enable);
};

extern Object_00046670 data_001F93C8;
extern Light_00046920 *data_001F963C;

struct Matrix_001BA950 {
    float m[4][4];
};

void func_001BAA00();
void __fastcall func_001BA8F0(Matrix_001BA950 *matrix);
void __fastcall func_001BAA50();

struct Motion_0005F060;

// A model from func_00025700; its slot 5 poses it.
struct Model_00107680 {
    virtual void func_00();
    virtual void func_04();
    virtual void func_08();
    virtual void func_0C();
    virtual void func_10();
    virtual void func_14(Motion_0005F060 *motion, float time);
};

// One of the models queued at 0x1a4 (0x54 bytes each).
struct Queued_00107680 {
    int hidden;
    Model_00107680 *model;
    Matrix_001BA950 matrix;
    float bias;
    char unknown_4c[8];
};

// The objects with ids 0x115e to 0x1162 (table 0x1D2020, destructor func_00107620).
struct Object_00107FE0 : Node {
    virtual ~Object_00107FE0();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C90_2();
    virtual void func_00011C90_4();
    virtual void func_00011C90_6();
    virtual void func_00011C90_8();

    char unknown_0040[0x164];
    Queued_00107680 queued[64];
    unsigned int queuedCount;
};

// Slot 3: draws the models queued at 0x1a4 that are not hidden (slot 5 with no motion) under a copy of the light at
// data_001F963C pointing along z with color 0xffffff, each with its matrix (func_001BA8F0) and its bias (slot 33 of
// data_00251D6C) at slot 31 setting 0x2aaa (0x222 otherwise), then empties the queue. The argument is not used.
void Object_00107FE0::func_00011C80(int argument)
{
    data_00251D6C->slot31(0x222, 1.0f, 4000.0f);
    Light_00046920 light = *data_001F963C;
    light.direction.x = 0.0f;
    light.direction.y = 0.0f;
    light.direction.z = 1.0f;
    light.value_50 = 0;
    light.color_04 = 0xffffff;
    light.color_08 = 0;
    data_001F93C8.func_00046700(&light);
    data_001F93C8.func_00046740(&light);
    data_001F93C8.func_00046940(0);
    for (unsigned int i = 0; i < queuedCount; i++) {
        if (queued[i].hidden == 0) {
            data_00251D6C->slot31(0x2aaa, 1.0f, 4000.0f);
            data_00251D6C->slot33(queued[i].bias);
            func_001BAA00();
            func_001BA8F0(&queued[i].matrix);
            queued[i].model->func_14(0, 0.0f);
            func_001BAA50();
            data_00251D6C->slot31(0x222, 1.0f, 4000.0f);
        }
    }
    queuedCount = 0;
    data_00251D6C->slot33(0.0f);
}
