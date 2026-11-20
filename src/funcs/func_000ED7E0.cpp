/* sym: ??0Object_000ED7E0@@QAE@PAUNode@@HIPAUInit_000ED7E0@@H@Z = 0x000ED7E0 */
/* sym: ??0Node@@QAE@PAU0@HI@Z = 0x00012100 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ??1Object_000ED7E0@@UAE@XZ = 0x000ED420 */
/* sym: ?func_00011C90@Object_000ED7E0@@UAEXXZ = 0x000ED4D0 */
/* sym: ?func_00011C90_1@Object_000ED7E0@@UAEXXZ = 0x000ED570 */
/* sym: ?func_00011C80@Object_000ED7E0@@UAEXH@Z = 0x000ED670 */
/* sym: ?func_00011C80_3@Object_000ED7E0@@UAEXH@Z = 0x000ED730 */
/* sym: ?func_00011C80_4@Object_000ED7E0@@UAEXH@Z = 0x000B3DE0 */
struct Vector3 {
    float x;
    float y;
    float z;
};

struct Angles {
    int x;
    int y;
    int z;
};

struct Motion_0005F060;

// The motion set of a bank: motions by index.
struct MotionSet_000ED7E0 {
    Motion_0005F060 *motions[8];
};

struct Model_000ED7E0;

// What func_00025700 (5, 0x16) returns: its models first, its motion set at 0x18, the meshes at 0x20.
struct Bank_000ED7E0 {
    Model_000ED7E0 **models;
    char unknown_04[0x14];
    MotionSet_000ED7E0 *motionSet;
    char unknown_1c[4];
    void **meshes;
};

struct Object_00016200 {
    int func_0001D950(void *source, int id);
};

struct Object_0003E750 {
    int func_0003EE90(void *effect, int first, int second, int third, float scale, int kind, int owner, int fourth);
};

struct Object_00039BE0 {
    int func_0003A580(unsigned int index);
};

struct Object_00046670 {
    float func_000466C0(Vector3 *position, int index);
};

extern Object_00016200 data_0022FCE8;
extern Object_0003E750 data_002314B0;
extern Object_00039BE0 data_001EFFB0;
extern Object_00046670 data_001F93C8;
extern char data_0021A250[];

void *func_00025700(unsigned int index, int first, int second, int third);
void func_001BA9C0();
void __fastcall func_001BAA50();
void __fastcall func_001BAAA0(float *vector);
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
    char unknown_0c[0x38];
};

// One placement (0x1c bytes): a position, angles and a kind (0 to 2).
struct Init_000ED7E0 {
    Vector3 position;
    Angles angles;
    int kind;
};

struct Desc_000E5380;

// The second base (table 0x1CE1B8), two slots.
struct Object_000C60C0 {
    virtual void func_000C6090(Object_000C60C0 *previous, Desc_000E5380 *owner, int index);
    virtual void func_000C60C0();
};

// The class whose tables are at 0x1CEF68 (Node) and 0x1CEF60 (Object_000C60C0 at +0x44); slot 15 holds a folded
// thunk.
struct Object_000ED7E0 : Node, Object_000C60C0 {
    Object_000ED7E0(Node *owner, int id, unsigned int flags, Init_000ED7E0 *init, int value);
    virtual ~Object_000ED7E0();
    virtual void func_00011C90();
    virtual void func_00011C90_1();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C80_4(int argument);

    Vector3 position;
    Angles angles;
    char unknown_060[0x28];
    float height;
    char unknown_08c[4];
    unsigned int flags_90;
    char unknown_094[0x28];
    int kind;
    int sound;
    int value_c4;
    Model_000ED7E0 *model;
    Model_000ED7E0 *shadow;
    Motion_0005F060 *motion;
    Motion_0005F060 *motion_d4;
    int time;
    int handle;
    char unknown_0e0[4];
    int effect;
    float value_e8;
    int value_ec;
};

// Takes the placement's position and angles, models, motions and mesh of bank (5, 0x16) by kind (kind 2 also keeps
// the value at 0xc4), the effect at 0x21A250 unless kind 2 and data_001EFFB0 (func_0003A580) say otherwise, and the
// ground height under the position (func_000466C0) at 0x88.
Object_000ED7E0::Object_000ED7E0(Node *owner, int id, unsigned int flags, Init_000ED7E0 *init, int value)
    : Node(owner, id, flags)
{
    position = init->position;
    angles = init->angles;
    flags_90 = 0;
    Bank_000ED7E0 *bank = (Bank_000ED7E0 *)func_00025700(5, 0x16, 0, 0);
    switch (init->kind) {
    case 0:
        model = bank->models[0];
        shadow = bank->models[1];
        motion = bank->motionSet->motions[0];
        motion_d4 = bank->motionSet->motions[2];
        break;
    case 1:
        model = bank->models[2];
        shadow = bank->models[3];
        motion = bank->motionSet->motions[0];
        motion_d4 = bank->motionSet->motions[2];
        break;
    case 2:
        model = bank->models[4];
        shadow = bank->models[5];
        motion = bank->motionSet->motions[2];
        motion_d4 = bank->motionSet->motions[1];
        value_c4 = value;
        break;
    }
    kind = init->kind;
    sound = -1;
    time = 0;
    func_001BA9C0();
    func_001BAAA0(&position.x);
    func_001BAC50(&angles.x, 0);
    handle = data_0022FCE8.func_0001D950(bank->meshes[init->kind], -1);
    if (init->kind == 2 && data_001EFFB0.func_0003A580(value)) {
        effect = -1;
        value_e8 = 1.0f;
        value_ec = 0;
    } else {
        effect = data_002314B0.func_0003EE90(data_0021A250, -1, -1, 1, 0.1f, 1, Node::id, -1);
        value_e8 = 0.0f;
        value_ec = 0;
    }
    func_001BAA50();
    height = data_001F93C8.func_000466C0(&position, -1);
}
