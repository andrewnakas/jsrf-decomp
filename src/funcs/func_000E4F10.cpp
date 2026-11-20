/* sym: ?func_00011C90_1@Object_000E45D0@@UAEXXZ = 0x000E4F10 */
struct Vector3 {
    float x;
    float y;
    float z;
};

struct Rotation_000E45D0 {
    int x;
    int y;
    int z;
};

struct Object_0006DB80 {
    void func_0006DFC0(int key, const Vector3 *position);
};

extern Object_0006DB80 data_00251F78;

// The object a behaviour serves (at 0xb0).
struct Object_000C5B50 {
    char unknown_00[0x9c];
    int value_9c;
};

void func_000FEC30(int value, const Vector3 *position);


struct Object_0003E750 {
    void func_0003F410(int key, int value);
};

extern Object_0003E750 data_002314B0;

// The object at data_00257CE8 (func_00157F10 is the engine's).
struct Object_00157F10 {
    int func_000C1D40(int *first, int *second, int *third);
};

extern Object_00157F10 *data_00257CE8;

struct Object_00047470 {
    void func_00047970(void *data, int argument);
    void func_000480C0(unsigned int index);
};

struct Holder_000E45D0 {
    Object_00047470 *model;
};

float __fastcall func_0014C530(const Vector3 *a, const Vector3 *b);
void func_001BA9C0();
void func_001BAA50();
void __fastcall func_001BAAA0(float *vector);
void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);
void __fastcall func_001BB2E0(int angle);
void __fastcall func_001BB330(int angle);
void __fastcall func_001BB380(int angle);

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

// The second base (table 0x1CE1B8), two slots.
struct Object_000C60C0 {
    virtual void func_000C6090();
    virtual void func_000C60C0();
};


// The class whose tables are at 0x1CED20 (Node) and 0x1CED18 (Object_000C60C0 at +0x44); slot 15 holds a folded

// The class whose tables are at 0x1CED20 (Node) and the Object_000C60C0 part at +0x44.
struct Object_000E45D0 : Node, Object_000C60C0 {
    virtual ~Object_000E45D0();
    virtual void func_00011C90();
    virtual void func_00011C90_1();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C80_4(int argument);

    void func_000E4C20();

    Vector3 position;
    Rotation_000E45D0 rotation;
    char unknown_060[0x30];
    unsigned int flags_90;
    char unknown_094[4];
    int effect;
    int value_9c;
    char unknown_0a0[0x10];
    Object_000C5B50 *owner;
    char unknown_0b4[8];
    unsigned int state;
    char unknown_0c0[0x1c];
    Vector3 point_dc;
    Vector3 point_e8;
    char unknown_0f4[0xc];
    float distance;
    char unknown_104[0x60];
    Holder_000E45D0 *holder;
    char unknown_168[4];
    void *data_16c;
    char unknown_170[0xa8];
    int value_218;
    int value_21c;
    int value_220;
};

// Slot 2: unless the flag 0x2000 is set at 0x90: up to state 2 runs func_000E4C20 and keeps the distance between the
// points at 0xdc and 0xe8 at 0x100; when func_000C1D40 of data_00257CE8 says so (with 0x218, 0x220 and 0x21c), sets
// that flag, state 4 and 1 at 0x9c, else func_000FEC30 with the owner's 0x9c at the position. Then with an effect at
// 0x98, hands it the point of bone 2 of the holder's model posed with the data at 0x16c at the position and turned
// by the rotation at 0x54.
void Object_000E45D0::func_00011C90_1()
{
    if (flags_90 & 0x2000) {
        return;
    }
    if (state <= 2) {
        func_000E4C20();
        distance = func_0014C530(&point_dc, &point_e8);
    }
    if (data_00257CE8->func_000C1D40(&value_218, &value_220, &value_21c)) {
        flags_90 |= 0x2000;
        state = 4;
        value_9c = 1;
    } else {
        func_000FEC30(owner->value_9c, &position);
    }
    if (effect != -1) {
        func_001BA9C0();
        func_001BAAA0(&position.x);
        func_001BB330(rotation.y + 0x8000);
        func_001BB2E0(rotation.x);
        func_001BB380(rotation.z);
        holder->model->func_00047970(data_16c, 0);
        holder->model->func_000480C0(2);
        Vector3 point;
        func_001BAB20(&point, 0);
        func_001BAA50();
        data_00251F78.func_0006DFC0(effect, &point);
    }
}
