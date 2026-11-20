/* sym: ??0Object_000EA3B0@@QAE@PAUDesc_000EA3B0@@@Z = 0x000EA3B0 */
/* sym: ??0Part_000EB830@@QAE@PAX@Z = 0x000EB830 */
/* sym: ??1Object_000EA3B0@@UAE@XZ = 0x000EA570 */
/* sym: ?func_000CD1E0@Object_000EA3B0@@UAEXXZ = 0x000EA6A0 */
/* sym: ?func_00011C90@Object_000EA3B0@@UAEXXZ = 0x000E96E0 */
/* sym: ?func_00011C80@Object_000EA3B0@@UAEXH@Z = 0x000E97F0 */
/* sym: ?func_00011C80_1@Object_000EA3B0@@UAEXH@Z = 0x000E9A40 */
extern "C" void *memset(void *destination, int value, unsigned int size);

struct Vector3 {
    float x;
    float y;
    float z;
};

// A bounding sphere (0x10 bytes).
struct Sphere_000EA3B0 {
    Vector3 center;
    float radius;
};

// The shape at 0xc of a model: its bounds at 0x54.
struct Shape_000EA3B0 {
    char unknown_00[0x54];
    Sphere_000EA3B0 bounds;
};

// A model: its shape at 0xc, two values at 0x74 and 0x7c.
struct Model_000EA3B0 {
    char unknown_00[0xc];
    Shape_000EA3B0 *shape;
    char unknown_10[0x64];
    float value_74;
    char unknown_78[4];
    float value_7c;
};

struct Motion_0005F060;

// The motion set of a bank: motions by index.
struct MotionSet_000EA3B0 {
    Motion_0005F060 *motions[19];
};

// What func_00025700 (5, 0xc) returns: its models first, its motion set at 0x18, the meshes at 0x20.
struct Bank_000EA3B0 {
    Model_000EA3B0 **models;
    char unknown_04[0x14];
    MotionSet_000EA3B0 *motionSet;
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
extern Mesh_00017F60 data_00219190;

void *func_00025700(unsigned int index, int first, int second, int third);
int func_0005E790(void *source, int flags);

// The object the factory func_000EAC20 serves (a Node): its id at 0x8.
struct Desc_000EA3B0 {
    char unknown_00[8];
    int id;
};

// The base with a pure slot 0 (table 0x1CE304).
struct Object_000CC600 {
    virtual void func_000CD1E0() = 0;
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_1(int argument);
    virtual ~Object_000CC600() {}

    Desc_000EA3B0 *owner;
    int state;
    char unknown_0c[4];
    int value_10;
    char unknown_14[0x1c];
};

// The second base, at 0x30 (0x6c bytes): two quads at 0x4c and 0x5c.
struct Part_000EB830 {
    Part_000EB830(void *owner);
    void func_000EB870();
    void func_000EBAA0(int id);

    char unknown_00[0x4c];
    int quad_4c[4];
    int quad_5c[4];
};

// A drawn block (0x24 bytes) of the four at 0x150.
struct Block_000EA3B0 {
    int kind;
    int count;
    Mesh_00017F60 *mesh;
    int value_0c;
    char unknown_10[0x14];
};

// The behaviour whose table is at 0x1CEE78 (0x1f4 bytes), with the part at 0x30 as its second base.
struct Object_000EA3B0 : Object_000CC600, Part_000EB830 {
    Object_000EA3B0(Desc_000EA3B0 *desc);
    virtual void func_000CD1E0();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_1(int argument);
    virtual ~Object_000EA3B0();

    char unknown_09c[0x14];
    Sphere_000EA3B0 bounds;
    char unknown_0c0[0x50];
    Model_000EA3B0 **models;
    Model_000EA3B0 *model;
    MotionSet_000EA3B0 *motionSet;
    Motion_0005F060 *motion_11c;
    int value_120;
    int value_124;
    int block_128;
    int value_12c;
    char unknown_130[8];
    int value_138;
    int value_13c;
    char unknown_140[4];
    int value_144;
    char unknown_148[8];
    Block_000EA3B0 blocks[4];
    int handle;
    int handle_1e4;
    char unknown_1e8[4];
    int key_1ec;
    int value_1f0;
};

// Takes the models and motion set of bank (5, 0xc) (two values on model 1), the bounds of model 0's shape, motion
// 18, a block of motion 0, four drawn blocks with the mesh at 0x219190, the mesh handle of the first mesh, and a key
// from data_00251F78; the part base at 0x30 is set up with func_000EB870 and func_000EBAA0.
Object_000EA3B0::Object_000EA3B0(Desc_000EA3B0 *desc) : Part_000EB830(0)
{
    Bank_000EA3B0 *bank = (Bank_000EA3B0 *)func_00025700(5, 0xc, 0, 0);
    models = bank->models;
    model = models[0];
    motionSet = bank->motionSet;
    Model_000EA3B0 *second = models[1];
    second->value_74 = 100.0f;
    second->value_7c = 3.0f;
    state = 0;
    value_144 = 0;
    value_10 = 0;
    bounds = model->shape->bounds;
    motion_11c = motionSet->motions[18];
    value_124 = 0;
    value_120 = 0;
    value_13c = 0;
    value_138 = 0;
    value_12c = 0;
    block_128 = func_0005E790(motionSet->motions[0], 1);
    for (int i = 0; i < 4; i++) {
        blocks[i].mesh = data_0022FCE8.func_00019680(&data_00219190);
        blocks[i].kind = 0x10;
        blocks[i].count = 1;
        blocks[i].value_0c = 0;
    }
    handle_1e4 = handle = data_0022FCE8.func_0001D950(bank->meshes[0], desc->id);
    func_000EB870();
    func_000EBAA0(desc->id);
    quad_4c[1] = 0;
    quad_4c[0] = 0;
    quad_5c[1] = 0;
    quad_5c[0] = 0;
    key_1ec = data_00251F78.func_0006DAE0(1, 0, -1, -1);
    value_1f0 = 0;
}
