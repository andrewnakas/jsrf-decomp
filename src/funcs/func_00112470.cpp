/* sym: ?func_00011C80@Object_001118F0@@UAEXH@Z = 0x00112470 */
struct Vector3 {
    float x;
    float y;
    float z;
};

void func_001BA9C0();
void func_001BAA00();
void __fastcall func_001BAA50();
void __fastcall func_001BAAA0(float *vector);
void __fastcall func_001BAC50(int *angles, int order);
void __fastcall func_001BAF70(Vector3 *eye, Vector3 *target, int roll);

// The screen rectangle device slot 30 takes.
struct Rect_00112470 {
    int x;
    int y;
    int width;
    int height;
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
    virtual void __stdcall slot30(Rect_00112470 *rect);
    virtual void __stdcall slot31(int angle, float aspect, float range);
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
    char unknown_1c[0x34];
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

struct Game {
    void func_00012750();
};

extern Game *data_0022FCE0;

struct Frame_00112470 {
    char unknown_00[0x80];
    float matrix[16];
};

// The model at 0x98: its frame at 0x8.
struct Model_00112470 {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5(int first, int second);

    char unknown_04[4];
    Frame_00112470 *frame;
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
};

struct Object_001118F0 : Node {
    virtual ~Object_001118F0();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);

    void func_00111900();
    void func_00111A00();
    void func_00111A90();
    void func_00111B30();
    void func_00111C60();
    void func_00112150();

    char unknown_044[0x54];
    Model_00112470 *holder;
    char unknown_09c[0x90];
    Vector3 position;
    Vector3 eye;
    int angles[3];
    char unknown_150[0xc];
    int stage;
};

// Slot 3: unless in stage 2 (0x15c): full-screen rectangle (slot 30) and projection (slot 31: 0x3555, 1, 4000) on the
// device and func_00012750; on passes 0, 8 and 19 draws at the point at 0x12c turned by the angles at 0x144 and seen
// from the point at 0x138 under a white light from +z: the parts (func_00112150, func_00111900, func_00111A00,
// func_00111A90, func_00111B30, func_00111C60) placed at the model at 0x98's frame, then that model. Pass 7 sets the
// depth to 5.
void Object_001118F0::func_00011C80(int argument)
{
    if (stage == 2) {
        return;
    }
    Vector3 up;
    up.x = 0.0f;
    up.y = 0.0f;
    up.z = 0.0f;
    Rect_00112470 rect;
    rect.x = 0;
    rect.y = 0;
    rect.width = 640;
    rect.height = 480;
    data_00251D6C->slot33(0.0f);
    data_00251D6C->slot30(&rect);
    data_00251D6C->slot31(0x3555, 1.0f, 4000.0f);
    data_0022FCE0->func_00012750();
    switch (argument) {
    case 0:
    case 8:
    case 19: {
        data_00251D6C->slot33(0.0f);
        func_001BAA00();
        func_001BAAA0(&position.x);
        func_001BAC50(angles, 0);
        func_001BAF70(&eye, &up, 0);
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
        if (holder) {
            func_001BAAA0(holder->frame->matrix);
        }
        func_00112150();
        func_00111900();
        func_00111A00();
        func_00111A90();
        func_00111B30();
        func_00111C60();
        func_001BAA50();
        data_00251D6C->slot33(0.0f);
        if (holder) {
            holder->slot5(0, 0);
        }
        data_001F93C8.func_00046A30();
        func_001BAA50();
        data_00251D6C->slot33(0.0f);
        break;
    }
    case 7:
        depth = 5.0f;
        break;
    }
}
