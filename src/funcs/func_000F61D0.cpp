/* sym: ?func_00011C90@Object_000F55E0@@UAEXXZ = 0x000F61D0 */
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
    int unknown_40;
};

struct Vector3 {
    float x;
    float y;
    float z;
};

// The object at data_00257CE4; its position is at 0x7c.
struct Object_000C1270 {
    char unknown_00[0x7c];
    Vector3 position;
};

extern Object_000C1270 *data_00257CE4;

// The object at data_00257CE8 (func_00157F10 is the engine's).
struct Object_00157F10 {
    void func_000C1EA0(int key);
};

extern Object_00157F10 *data_00257CE8;

struct Object_0003E750 {
    void func_0003F410(int key, int value);
};

extern Object_0003E750 data_002314B0;

// The skeleton at 0x130.
struct Object_00047470 {
    void func_00047970(void *data, int argument);
};

float __fastcall func_0014C530(const Vector3 *a, const Vector3 *b);
void func_001BA9C0();
void __fastcall func_001BAAA0(float *vector);
void __fastcall func_001BB330(int angle);
void __fastcall func_001BAA50();

struct Object_000F55E0;

// The state handlers (member-function pointers with this adjustment) by the state at 0xbc.
extern void (Object_000F55E0::*data_00258800[])();

// The second base (table 0x1CE1B8), two slots.
struct Object_000C60C0 {
    virtual void func_000C6090();
    virtual void func_000C60C0();
};

// The child of Node whose table is at 0x1CF220 (constructor func_000F5E70, destructor func_000F60C0); slots 16 to
// 52 of its table. The class of the table at 0x1CEAC0 derives from it. The second base sits at 0x44 (tables 0x1CE1B8,
// then 0x1CF214).
struct Object_000F55E0 : Node, Object_000C60C0 {
    virtual void func_000F51A0();
    virtual void func_000F5310();
    virtual void func_000F5380();
    virtual void func_000F53E0();
    virtual void func_000F63E0();
    virtual void func_000F6480();
    virtual void func_000F6500();
    virtual void func_000F54C0();
    virtual void func_000F5510();
    virtual void func_000F5550();
    virtual void func_000F55A0();
    virtual void func_000F6580();
    virtual void func_000F55E0();
    virtual void func_000F6620();
    virtual void func_000F5600();
    virtual void func_000F5620();
    virtual void func_000F66C0();
    virtual void func_000F6700();
    virtual void func_000F5640();
    virtual void func_000F6770();
    virtual void func_000F6B70();
    virtual void func_000F6BF0();
    virtual void func_000F6C40();
    virtual void func_000F6C90();
    virtual void func_000F6D60();
    virtual void func_000F6DD0();
    virtual void func_000F6E30();
    virtual void func_000F6E90();
    virtual void func_000F6F00();
    virtual void func_000F6F70();
    virtual void func_000F6FE0();
    virtual void func_000F7050();
    virtual void func_000F70E0();
    virtual void func_000F7120();
    virtual void func_000F7180();
    virtual void func_000F71D0();
    virtual void func_000F7230();

    virtual void func_00011C90();
    void func_000F5C00();
    void func_000F6A30();

    Vector3 position;
    char unknown_054[0x4];
    int angle;
    char unknown_05c[0x18];
    float distance;
    char unknown_078[0x18];
    unsigned int bits;
    char unknown_094[0x28];
    int state;
    char unknown_0c0[0xc];
    Vector3 point;
    char unknown_0d8[0x58];
    Object_00047470 *skeleton;
    char unknown_134[0x14];
    void *motion;
    char unknown_14c[0xa0];
    int sound;
};

// Slot 1: the distance at 0x74 to data_00257CE4's position (func_0014C530), the state handler of data_00258800 for
// the state at 0xbc, func_000F6A30; between func_001BA9C0 and func_001BAA50 the matrix at the point at 0xcc turned by
// the angle at 0x58 + 0x8000, the skeleton at 0x130 posed by the motion at 0x148, and func_000F5C00. The sound key at
// 0x1ec (unless -1, or with flags 0x1001 at 0x90) is switched on (func_0003F410 of data_002314B0, func_000C1EA0) with
// flag 0x8000 within 100, else off.
void Object_000F55E0::func_00011C90()
{
    distance = func_0014C530(&position, &data_00257CE4->position);
    (this->*data_00258800[state])();
    func_000F6A30();
    func_001BA9C0();
    func_001BAAA0(&point.x);
    func_001BB330(angle + 0x8000);
    skeleton->func_00047970(motion, 0);
    func_000F5C00();
    if (sound != -1 && !(bits & 0x1001)) {
        if ((bits & 0x8000) && distance < 100.0f) {
            data_002314B0.func_0003F410(sound, 1);
            data_00257CE8->func_000C1EA0(sound);
        } else {
            data_002314B0.func_0003F410(sound, 0);
        }
    }
    func_001BAA50();
}
