/* sym: ?func_00011C80@Object_000F7280@@UAEXH@Z = 0x000F73D0 */
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
struct Model_000F7280 {
    virtual void func_00();
    virtual void func_04();
    virtual void func_08();
    virtual void func_0C();
    virtual void func_10();
    virtual void func_14(Motion_0005F060 *motion, float time);
};

struct List_000149B0;

struct Object_000149B0 {
    List_000149B0 *func_000149D0();
};

// The object at data_001EB938.
struct Object_00014A80 : Object_000149B0 {
    int func_00014A10(Vector3 *position);
};

extern Object_00014A80 data_001EB938;

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

void func_001BA9C0();
void __fastcall func_001BAAA0(float *vector);
void func_001BB3D0();
void __fastcall func_001BAA50();

// The child of Node whose table is at 0x1CF2F8 (constructor func_000F7280, destructor func_000F7320).
struct Object_000F7280 : Node {
    virtual ~Object_000F7280();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);

    int unknown_040;
    Model_000F7280 *model;
    Motion_0005F060 *motion;
    float time;
    Vector3 position;
};

// Slot 3, the message handler: on 0, while data_001EB938 has entries and gives the position at 0x50 (func_00014A10),
// draws the model at 0x44 there with the motion at 0x48 at the time at 0x4c, under a copy of the light at
// data_001F963C pointing along z with color 0xffffff (func_00046740) and func_00046940(0).
void Object_000F7280::func_00011C80(int argument)
{
    if (data_001EB938.func_000149D0() && argument == 0) {
        if (data_001EB938.func_00014A10(&position) && model) {
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
            func_001BA9C0();
            func_001BAAA0(&position.x);
            func_001BB3D0();
            model->func_14(motion, time);
            func_001BAA50();
            data_001F93C8.func_00046A30();
        }
    }
}
