/* sym: ?func_00011C90@Object_000ED7E0@@UAEXXZ = 0x000ED4D0 */
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
    void func_00060810(int key);
};

struct Object_000C1270 {
    char unknown_00[0x7c];
    Vector3 unknown_7c;
};

extern Object_000C1270 *data_00257CE4;

// The object at data_00257CE8 (func_00157F10 is the engine's).
struct Object_00157F10 {
    void func_000C1770(int key);
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
    char unknown_094[0x2c];
    int sound;
    char unknown_0c4[4];
    Model_000ED7E0 *model;
    Model_000ED7E0 *shadow;
    Motion_0005F060 *motion;
    char unknown_0d4[4];
    float time;
    Item_00016200 link;
    int effect;
    int value_e8;
    int value_ec;
};

// Slot 1: within 100 of the point at 0x7c of data_00257CE4 hands the link to data_0022FCE8; the effect at 0xe4 is
// switched on within 100 and off beyond (func_0003F410); the motion at 0xd0, when there is one, plays at half speed
// and rewinds when it ends.
void Object_000ED7E0::func_00011C90()
{
    float distance = func_0014C530(&data_00257CE4->unknown_7c, &position);
    if (distance < 100.0f) {
        data_0022FCE8.func_00016240(&link);
    }
    if (effect != -1) {
        if (distance < 100.0f) {
            data_002314B0.func_0003F410(effect, 1);
        } else {
            data_002314B0.func_0003F410(effect, 0);
        }
    }
    if (motion && func_0005E030(motion, &time, 0.5f, 1)) {
        time = 0.0f;
    }
}
