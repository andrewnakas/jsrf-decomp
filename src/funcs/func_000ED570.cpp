/* sym: ?func_00011C90_1@Object_000ED7E0@@UAEXXZ = 0x000ED570 */
struct Vector3 {
    float x;
    float y;
    float z;
};

struct Motion_0005F060;
struct Item_00017940;

struct Item_00016200 {
    Item_00017940 *handle;
    Item_00016200 *next;
};

struct Object_00016200 {
    void func_00016240(Item_00016200 *item);
    void func_000178D0(Item_00017940 *item);
};

extern Object_00016200 data_0022FCE8;

struct Object_0003E750 {
    void func_0003F280(int index);
    void func_0003F410(int key, int value);
};

extern Object_0003E750 data_002314B0;

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Object_000607B0 {
    int func_000651E0(int kind, void *data, Vector3 *direction);
};

struct Object_00039BE0 {
    void func_0003A550(unsigned int index);
};

extern Object_00039BE0 data_001EFFB0;

// The owner at 0xb0.
struct Object_000C5B50 {
    char unknown_00[0x9c];
    int value_9c;
};

void func_000FEC30(int value, const Vector3 *position);

struct Object_000C1270 {
    char unknown_00[0x7c];
    Vector3 unknown_7c;
};

extern Object_000C1270 *data_00257CE4;

// The object at data_00257CE8 (func_00157F10 is the engine's).
struct Object_00157F10 {
    int func_000C1D40(int *effect, int *second, int *third);
};

extern Object_00157F10 *data_00257CE8;

int func_0005E030(Motion_0005F060 *motion, float *time, float speed, int loop);
float __fastcall func_0014C530(const Vector3 *a, const Vector3 *b);
void __fastcall func_001BAAA0(float *vector);
void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);
void __fastcall func_001BAC50(int *angles, int order);

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

struct Angles {
    int x;
    int y;
    int z;
};

// The models at 0xc8 and 0xcc: a scale at 0x5c and its slot 5 poses it.
struct Model_000ED7E0 {
    virtual void func_00();
    virtual void func_04();
    virtual void func_08();
    virtual void func_0C();
    virtual void func_10();
    virtual void func_14(Motion_0005F060 *motion, float time);

    char unknown_04[0x58];
    float scale;
    char unknown_60[0x14];
    int value_74;
    char unknown_78[4];
    int value_7c;
};

// The second base (table 0x1CE1B8), two slots.
struct Object_000C60C0 {
    virtual void func_000C6090();
    virtual void func_000C60C0();
};

// The class whose tables are at 0x1CEF68 (Node) and 0x1CEF60 (Object_000C60C0 at +0x44); slot 15 holds a folded
// thunk.
struct Object_000ED7E0 : Node, Object_000C60C0 {
    virtual ~Object_000ED7E0();
    virtual void func_00011C90();
    virtual void func_00011C90_1();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C80_4(int argument);

    Vector3 position;
    Angles angles;
    char unknown_060[0x28];
    float scale;
    char unknown_08c[4];
    unsigned int flags_90;
    char unknown_094[0x1c];
    Object_000C5B50 *owner;
    char unknown_0b4[8];
    int mode;
    int sound;
    unsigned int value_c4;
    Model_000ED7E0 *model;
    Model_000ED7E0 *shadow;
    Motion_0005F060 *motion;
    Motion_0005F060 *next_motion;
    float time;
    Item_00016200 link;
    int effect;
    int value_e8;
    int value_ec;
};

// Slot 2: unless flag 0x2000 is set at 0x90, when func_000C1D40 of data_00257CE8 gives nonzero it sets that flag,
// runs the second base's slot 1 and starts the motion at 0xd4; in mode 2 (0xbc) also sound 0x7e 21 above the
// position (kept at 0xc0) and func_0003A550 of data_001EFFB0 with 0xc4. Then func_000FEC30 with the owner's 0x9c and
// the position.
void Object_000ED7E0::func_00011C90_1()
{
    if (!(flags_90 & 0x2000)) {
        if (data_00257CE8->func_000C1D40(&effect, &value_ec, &value_e8)) {
            flags_90 |= 0x2000;
            func_000C60C0();
            motion = next_motion;
            time = 0.0f;
            if (mode == 2) {
                Vector3 point = position;
                point.y += 21.0f;
                Object_000607B0 *object = (Object_000607B0 *)data_0022FCE0->func_000128C0(0xe8);
                if (object) {
                    sound = object->func_000651E0(0x7e, &point, 0);
                }
                data_001EFFB0.func_0003A550(value_c4);
            }
        }
        func_000FEC30(owner->value_9c, &position);
    }
}
