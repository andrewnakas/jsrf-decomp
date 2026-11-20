/* sym: ??0Object_000D8A40@@QAE@PAUDesc_000D8A40@@@Z = 0x000D8A40 */
/* sym: ??1Object_000D8A40@@UAE@XZ = 0x000D8CA0 */
/* sym: ?func_000CD1E0@Object_000D8A40@@UAEXXZ = 0x000D8D80 */
/* sym: ?func_00011C90@Object_000D8A40@@UAEXXZ = 0x000D8E90 */
/* sym: ?func_00011C80@Object_000D8A40@@UAEXH@Z = 0x000D7EC0 */
/* sym: ?func_00011C80_1@Object_000D8A40@@UAEXH@Z = 0x000D8130 */
extern "C" void *memset(void *destination, int value, unsigned int size);

struct Mesh_00017F60;
struct Motion_0005F060;

// The motion set of a bank: motions by index.
// A bounding sphere (0x10 bytes).
struct Sphere_000D8A40 {
    float x;
    float y;
    float z;
    float radius;
};

// The shape at 0xc of a model: its bounds at 0x54.
struct Shape_000D8A40 {
    char unknown_00[0x54];
    Sphere_000D8A40 bounds;
};

// A model: the target func_0005E7B0 poses at 0x8, its shape at 0xc.
struct Model_000D8A40 {
    char unknown_00[8];
    void *target;
    Shape_000D8A40 *shape;
};

struct MotionSet_000D8A40 {
    Motion_0005F060 *motions[17];
};

// What func_00025700 (5, 0xa) returns: its models first, its motion set at 0x18.
struct Bank_000D8A40 {
    Model_000D8A40 **models;
    char unknown_04[0x14];
    MotionSet_000D8A40 *motionSet;
};

struct Object_00016200 {
    Mesh_00017F60 *func_00019680(const Mesh_00017F60 *mesh);
};

struct Object_0003E750 {
    int func_0003EE90(void *effect, int first, int second, int third, float scale, int kind, int owner, int fourth);
    void func_0003F410(int effect, int value);
};

struct Object_0006DB80 {
    int func_0006DAE0(int first, int second, int third, int fourth);
};

extern Object_00016200 data_0022FCE8;
extern Object_0003E750 data_002314B0;
extern Object_0006DB80 data_00251F78;
extern Mesh_00017F60 data_00217360;
extern char data_00217260[];

void *func_00025700(unsigned int index, int first, int second, int third);
int func_0005E790(void *source, int flags);
void func_0005E7B0(void *target, int first, int second, int third, int fourth);

// The object the behaviour serves: its id at 0x8, flags at 0xa4.
struct Desc_000D8A40 {
    char unknown_00[8];
    int id;
    char unknown_0c[0x98];
    unsigned int flags_a4;
};

// A 0x44-byte block (kinds 0x41b and 0x824 at 0xfc and 0x140).
struct Block_000D8A40 {
    int kind;
    char unknown_04[0x40];
};

// The base with a pure slot 0 (table 0x1CE304).
struct Object_000CC600 {
    virtual void func_000CD1E0() = 0;
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_1(int argument);
    virtual ~Object_000CC600() {}
};

// The behaviour whose table is at 0x1CE63C (0x1d0 bytes).
struct Object_000D8A40 : Object_000CC600 {
    Object_000D8A40(Desc_000D8A40 *desc);
    virtual void func_000CD1E0();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_1(int argument);
    virtual ~Object_000D8A40();

    Desc_000D8A40 *owner;
    int state;
    char unknown_0c[0x68];
    Sphere_000D8A40 bounds;
    char unknown_084[0x14];
    int sound;
    char unknown_09c[8];
    Model_000D8A40 **models;
    Model_000D8A40 *shadow;
    int value_ac;
    MotionSet_000D8A40 *motionSet;
    Motion_0005F060 *motion;
    int value_b8;
    int value_bc;
    int blocks[3];
    int value_cc;
    int value_d0;
    int value_d4;
    char unknown_d8[8];
    int value_e0;
    int value_e4;
    int value_e8;
    int value_ec;
    int value_f0;
    int value_f4;
    char unknown_f8[4];
    Block_000D8A40 first;
    Block_000D8A40 second;
    int value_184;
    int value_188;
    Mesh_00017F60 *mesh;
    int value_190;
    char unknown_194[0x20];
    float value_1b4;
    int effect;
    int value_1bc;
    int value_1c0;
    int key;
    int value_1c8;
    int handle;
};

// Takes the models and motion set of bank (5, 0xa) with the bounds of model 0's shape, motion 16, three blocks of
// motion 0 posed with it, blocks of kinds 0x41b and 0x824, the mesh at 0x217360, and, when the owner has flag 0x4000
// at 0xa4, the effect at 0x217260 and a key from data_00251F78; then the shadow model of bank (5, 0x12).
Object_000D8A40::Object_000D8A40(Desc_000D8A40 *desc)
{
    Bank_000D8A40 *bank = (Bank_000D8A40 *)func_00025700(5, 0xa, 0, 0);
    models = bank->models;
    motionSet = bank->motionSet;
    value_ac = 1;
    bounds = models[0]->shape->bounds;
    state = 0;
    value_e4 = 0;
    value_e0 = 0;
    value_e8 = 0;
    value_f4 = 0;
    value_cc = 0;
    value_d4 = 0;
    value_d0 = 0;
    motion = motionSet->motions[16];
    value_bc = 0;
    value_b8 = 0;
    value_ec = 0;
    value_f0 = 0;
    sound = -1;
    blocks[0] = func_0005E790(motionSet->motions[0], 1);
    blocks[1] = func_0005E790(motionSet->motions[0], 1);
    blocks[2] = func_0005E790(motionSet->motions[0], 1);
    func_0005E7B0(models[0]->target, blocks[0], 0, (int)motion, 0);
    memset(&first, 0, sizeof first);
    first.kind = 0x41b;
    memset(&second, 0, sizeof second);
    second.kind = 0x824;
    value_1b4 = 3.0f;
    mesh = data_0022FCE8.func_00019680(&data_00217360);
    value_184 = 2;
    value_188 = 1;
    value_190 = 0;
    if (desc->flags_a4 & 0x4000) {
        effect = data_002314B0.func_0003EE90(data_00217260, -1, -1, 1, 6.0f, 2, desc->id, -1);
        data_002314B0.func_0003F410(effect, 0);
        key = data_00251F78.func_0006DAE0(1, 0, -1, -1);
    } else {
        effect = -1;
        key = -1;
    }
    value_1c8 = 0;
    value_1bc = 0;
    value_1c0 = 0;
    Bank_000D8A40 *shadows = (Bank_000D8A40 *)func_00025700(5, 0x12, 0, 0);
    if (shadows) {
        shadow = shadows->models[0];
    } else {
        shadow = 0;
    }
    handle = -1;
}
