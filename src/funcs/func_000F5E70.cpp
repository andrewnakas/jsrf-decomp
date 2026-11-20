/* sym: ??0Object_000F55E0@@QAE@PAUNode@@HIPAUInit_000F55E0@@@Z = 0x000F5E70 */
/* sym: ??1Object_000F55E0@@UAE@XZ = 0x000F60C0 */
/* sym: ??0Node@@QAE@PAU0@HI@Z = 0x00012100 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
extern "C" void *memset(void *destination, int value, unsigned int size);

struct Vector3 {
    float x;
    float y;
    float z;
};

void *func_00025700(unsigned int index, int first, int second, int third);
int func_0005E790(void *source, int flags);
int func_0005E7B0(void *target, int first, int second, int third, int fourth);

struct Motion_0005F060;

// The motion set at 0x138: motions by index.
struct MotionSet_000F55E0 {
    Motion_0005F060 *motions[64];
};

// A bounding sphere (0x10 bytes).
struct Sphere_000F55E0 {
    Vector3 center;
    float radius;
};

// The shape at 0xc of a model: its bounds at 0x54.
struct Shape_000F55E0 {
    char unknown_00[0x54];
    Sphere_000F55E0 bounds;
};

// A model: the target func_0005E7B0 poses at 0x8, its shape at 0xc.
struct Model_000F55E0 {
    char unknown_00[8];
    void *target;
    Shape_000F55E0 *shape;
};

// What func_00025700 (5, ...) returns: its models first, its motion set at 0x18.
struct Bank_000F55E0 {
    Model_000F55E0 **models;
    char unknown_04[0x14];
    MotionSet_000F55E0 *motionSet;
};

// One placement (0x1c bytes): a position and a value at 0x10.
struct Init_000F55E0 {
    Vector3 position;
    int unknown_0c;
    int value;
    char unknown_14[8];
};

struct Object_0006DB80 {
    int func_0006DAE0(int first, int second, int third, int fourth);
    void func_0006DEB0(int key, int value);
};

extern Object_0006DB80 data_00251F78;

// The parameters at 0x118 and 0x11c.
struct Params_000F55E0 {
    char unknown_00[0x38];
    int value_38;
};

extern Params_000F55E0 data_0021B788;
extern Params_000F55E0 data_0021B7E4;

struct Node {
    Node(Node *owner, int id, unsigned int flags);
    virtual ~Node();

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

// The object the factories of the table at 0x215D68 serve: its kind at 0x9c.
struct Desc_000E5380 : Node {
    char unknown_44[0x58];
    int kind;
};

// A 0x44-byte block at 0x184 (kind 0x41b).
struct Block_000F55E0 {
    int kind;
    char unknown_04[0x40];
};

// The link of a chain (the second base, at 0x44; table 0x1CE1B8): the object it serves at 0x6c.
struct Object_000C60C0 {
    virtual void func_000C6090(Object_000C60C0 *previous, Desc_000E5380 *owner, int index);
    virtual void func_000C60C0();

    char unknown_04[0x30];
    Sphere_000F55E0 bounds;
    char unknown_44[8];
    unsigned int flags_90;
    int index;
    int handle;
    char unknown_58[0x14];
    void *owner;
    Object_000C60C0 *previous;
    Object_000C60C0 *next;
};

// The child of Node whose table is at 0x1CF220 (0x200 bytes; destructor func_000F60C0), a link of the chain at 0x44.
struct Object_000F55E0 : Node, Object_000C60C0 {
    Object_000F55E0(Node *owner, int id, unsigned int flags, Init_000F55E0 *init);
    virtual ~Object_000F55E0();

    int state;
    char unknown_0c0[0x58];
    Params_000F55E0 *params;
    Params_000F55E0 *params_11c;
    Vector3 position;
    int value_12c;
    Model_000F55E0 *model;
    Model_000F55E0 *shadow;
    MotionSet_000F55E0 *motionSet;
    Motion_0005F060 *motion;
    char unknown_140[8];
    int blocks[3];
    float time;
    float unknown_158;
    float lastTime;
    char unknown_160[8];
    int mode;
    int unknown_16c;
    int phase;
    char unknown_174[4];
    float turnTime;
    void *item;
    int unknown_180;
    Block_000F55E0 block;
    char unknown_1c8[0xc];
    int unknown_1d4;
    char unknown_1d8[0x14];
    int key;
    int unknown_1f0;
    int unknown_1f4;
    int handles[2];
};

// Takes the model of the owner's kind (24: bank (5, 3) model 1; 25: bank (5, 5) model 2) with its motion set and
// motion 15, the placement's position and value, the bounds of the model's shape, three blocks of motion 0
// (func_0005E790) posed with motion 15 (func_0005E7B0), block kind 0x41b, both parameter sets, a handle from
// data_00251F78 (func_0006DAE0, released at once with func_0006DEB0) and the shadow model of bank (5, 0x12).
Object_000F55E0::Object_000F55E0(Node *owner, int id, unsigned int flags, Init_000F55E0 *init)
    : Node(owner, id, flags)
{
    Bank_000F55E0 *bank;
    switch (((Desc_000E5380 *)owner)->kind) {
    case 24:
        bank = (Bank_000F55E0 *)func_00025700(5, 3, 0, 0);
        model = bank->models[1];
        motionSet = bank->motionSet;
        break;
    case 25:
        bank = (Bank_000F55E0 *)func_00025700(5, 5, 0, 0);
        model = bank->models[2];
        motionSet = bank->motionSet;
        break;
    }
    position = init->position;
    value_12c = init->value;
    unknown_16c = 0;
    mode = 0;
    phase = 0;
    motion = motionSet->motions[15];
    turnTime = 0.0f;
    time = 0.0f;
    lastTime = 0.0f;
    unknown_158 = 0.0f;
    state = 0;
    flags_90 = 0x101;
    bounds = model->shape->bounds;
    blocks[0] = func_0005E790(motionSet->motions[0], 1);
    blocks[1] = func_0005E790(motionSet->motions[0], 1);
    blocks[2] = func_0005E790(motionSet->motions[0], 1);
    func_0005E7B0(model->target, blocks[0], 0, (int)motion, 0);
    memset(&block, 0, sizeof block);
    block.kind = 0x41b;
    item = 0;
    unknown_180 = 0;
    unknown_1d4 = 0;
    params = &data_0021B788;
    params_11c = &data_0021B7E4;
    key = -1;
    unknown_1f0 = 0;
    unknown_1f4 = 0;
    handle = data_00251F78.func_0006DAE0(1, 0, -1, -1);
    if (handle != -1) {
        data_00251F78.func_0006DEB0(handle, 0);
    }
    Bank_000F55E0 *shadows = (Bank_000F55E0 *)func_00025700(5, 0x12, 0, 0);
    if (shadows) {
        shadow = shadows->models[0];
    } else {
        shadow = 0;
    }
    handles[1] = -1;
    handles[0] = -1;
}
