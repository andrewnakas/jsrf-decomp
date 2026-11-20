/* sym: ??0Object_000ECB50@@QAE@PAUNode@@HIPAUInit_000ECB50@@@Z = 0x000ECB50 */
/* sym: ??0Node@@QAE@PAU0@HI@Z = 0x00012100 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ??0Part_000EB830@@QAE@PAX@Z = 0x000EB830 */
/* sym: ??1Object_000ECB50@@UAE@XZ = 0x000EBD60 */
/* sym: ?func_00011C90@Object_000ECB50@@UAEXXZ = 0x000ECDB0 */
/* sym: ?func_00011C90_1@Object_000ECB50@@UAEXXZ = 0x000ECE70 */
/* sym: ?func_00011C80@Object_000ECB50@@UAEXH@Z = 0x000EBE70 */
/* sym: ?func_00011C80_3@Object_000ECB50@@UAEXH@Z = 0x000EC0B0 */
/* sym: ?func_00011C80_4@Object_000ECB50@@UAEXH@Z = 0x000B3DE0 */
extern "C" void *memset(void *destination, int value, unsigned int size);

struct Vector3 {
    float x;
    float y;
    float z;
};

// A bounding sphere (0x10 bytes).
struct Sphere_000ECB50 {
    Vector3 center;
    float radius;
};

// The shape at 0xc of a model: its bounds at 0x54.
struct Shape_000ECB50 {
    char unknown_00[0x54];
    Sphere_000ECB50 bounds;
};

// A model: its shape at 0xc, two values at 0x74 and 0x7c.
struct Model_000ECB50 {
    char unknown_00[0xc];
    Shape_000ECB50 *shape;
    char unknown_10[0x64];
    float value_74;
    char unknown_78[4];
    float value_7c;
};

struct Motion_0005F060;

// The motion set of a bank: motions by index.
struct MotionSet_000ECB50 {
    Motion_0005F060 *motions[9];
};

// What func_00025700 (5, 0xc) returns: its models first, its motion set at 0x18, the meshes at 0x20.
struct Bank_000ECB50 {
    Model_000ECB50 **models;
    char unknown_04[0x14];
    MotionSet_000ECB50 *motionSet;
    char unknown_1c[4];
    void **meshes;
};

struct Mesh_00017F60;

struct Object_00016200 {
    int func_0001D950(void *source, int id);
    Mesh_00017F60 *func_00019680(const Mesh_00017F60 *mesh);
};

struct Object_0006DB80 {
    int func_0006DAE0(int first, int second, int third, int fourth);
};

extern Object_00016200 data_0022FCE8;
extern Object_0006DB80 data_00251F78;
extern Mesh_00017F60 data_0021A110;

void *func_00025700(unsigned int index, int first, int second, int third);
int func_0005E790(void *source, int flags);

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

struct Desc_000E5380;

// The second base (table 0x1CE1B8, 0x78 bytes), two slots: the bounds at 0x34, flags at 0x4c.
struct Object_000C60C0 {
    virtual void func_000C6090(Object_000C60C0 *previous, Desc_000E5380 *owner, int index);
    virtual void func_000C60C0();

    char unknown_04[0x30];
    Sphere_000ECB50 bounds;
    char unknown_44[8];
    unsigned int flags_90;
    char unknown_50[8];
    int value_9c;
    char unknown_5c[0x1c];
};

// The third base, at 0xbc (0x6c bytes): two quads at 0x4c and 0x5c.
struct Part_000EB830 {
    Part_000EB830(void *owner);
    void func_000EB870();
    void func_000EBAA0(int id);

    char unknown_00[0x4c];
    int quad_4c[4];
    int quad_5c[4];
};

// One placement.
struct Init_000ECB50 {
    int unknown_00;
};

// A drawn block (0x24 bytes) of the four at 0x1c8.
struct Block_000ECB50 {
    int kind;
    int count;
    Mesh_00017F60 *mesh;
    int value_0c;
    char unknown_10[0x14];
};

// One of the four 0x10-byte entries at 0x174: a value at 0xc.
struct Entry_000ECB50 {
    char unknown_00[0xc];
    float value;
};

// A 0x44-byte block of the four at 0x264.
struct Light_000ECB50 {
    int kind;
    char unknown_04[0x40];
};

// The class whose tables are at 0x1CEF20 (Node) and 0x1CEF18 (Object_000C60C0 at +0x44); slot 15 holds a folded
// thunk.
struct Object_000ECB50 : Node, Object_000C60C0, Part_000EB830 {
    Object_000ECB50(Node *owner, int id, unsigned int flags, Init_000ECB50 *init);
    virtual ~Object_000ECB50();
    virtual void func_00011C90();
    virtual void func_00011C90_1();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C80_4(int argument);

    int value_128;
    int value_12c;
    char unknown_130[4];
    int value_134;
    char unknown_138[4];
    Model_000ECB50 **models;
    Model_000ECB50 *model;
    MotionSet_000ECB50 *motionSet;
    Motion_0005F060 *motion_148;
    int value_14c;
    int block_150;
    int value_154;
    char unknown_158[4];
    int value_15c;
    int value_160;
    char unknown_164[0x10];
    Entry_000ECB50 entries[4];
    int values_1b4[4];
    char unknown_1c4[4];
    Block_000ECB50 blocks[4];
    int handle;
    int handle_25c;
    char unknown_260[4];
    Light_000ECB50 lights[4];
    int key_374;
};

// Takes the models and motion set of bank (5, 0xc) (two values on model 1), the bounds of model 0's shape, motion 8, a
// block of motion 0, four drawn blocks with the mesh at 0x21A110, the mesh handle of the first mesh, four lights (kind
// 0x11f), and a key from data_00251F78; the part base at 0xbc is set up with func_000EB870 and func_000EBAA0.
Object_000ECB50::Object_000ECB50(Node *owner, int id, unsigned int flags, Init_000ECB50 *init)
    : Node(owner, id, flags), Part_000EB830((void *)1)
{
    Bank_000ECB50 *bank = (Bank_000ECB50 *)func_00025700(5, 0xc, 0, 0);
    models = bank->models;
    model = models[0];
    motionSet = bank->motionSet;
    Model_000ECB50 *second = models[1];
    second->value_74 = 500.0f;
    second->value_7c = 3.0f;
    flags_90 = 0;
    value_128 = 0;
    value_12c = 0;
    bounds = model->shape->bounds;
    value_134 = 0;
    motion_148 = motionSet->motions[8];
    value_14c = 0;
    value_160 = 0;
    value_15c = 0;
    value_154 = 0;
    block_150 = func_0005E790(motionSet->motions[0], 1);
    for (int i = 0; i < 4; i++) {
        blocks[i].mesh = data_0022FCE8.func_00019680(&data_0021A110);
        blocks[i].kind = 0x10;
        blocks[i].count = 1;
        blocks[i].value_0c = 0;
    }
    handle_25c = handle = data_0022FCE8.func_0001D950(bank->meshes[0], Node::id);
    func_000EB870();
    for (int j = 0; j < 4; j++) {
        memset(&lights[j], 0, sizeof lights[j]);
        lights[j].kind = 0x11f;
        entries[j].value = 5.0f;
        values_1b4[j] = 0;
    }
    func_000EBAA0(Node::id);
    quad_4c[1] = 0;
    quad_4c[0] = 0;
    quad_5c[1] = 0;
    quad_5c[0] = 0;
    key_374 = data_00251F78.func_0006DAE0(1, 0, -1, -1);
    value_9c = 0;
}
