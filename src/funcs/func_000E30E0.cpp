/* sym: ??0Object_000E32A0@@QAE@PAUNode@@HI@Z = 0x000E30E0 */
/* sym: ??0Object_000C7910@@QAE@PAUNode@@HI@Z = 0x000C8680 */
/* sym: ??1Object_000E32A0@@UAE@XZ = 0x000E32A0 */
/* sym: ??1Object_000C7910@@UAE@XZ = 0x000C7240 */
/* sym: ?func_00011C90@Object_000C7910@@UAEXXZ = 0x000C9280 */
/* sym: ?func_00011C90_1@Object_000C7910@@UAEXXZ = 0x000C7330 */
/* sym: ?func_00011C80@Object_000C7910@@UAEXH@Z = 0x000C74B0 */
/* sym: ?func_00011C80_3@Object_000C7910@@UAEXH@Z = 0x000C7720 */
/* sym: ?func_00011C80_4@Object_000C7910@@UAEXH@Z = 0x000B3DE0 */
/* sym: ?func_000C60C0@Object_000C7910@@UAEXXZ = 0x000C9EB0 */
struct Vector3 {
    float x;
    float y;
    float z;
};

// A bounding sphere (0x10 bytes).
struct Sphere_000E30E0 {
    Vector3 center;
    float radius;
};

// The shape at 0xc of a model: its bounds at 0x54.
struct Shape_000E30E0 {
    char unknown_00[0x54];
    Sphere_000E30E0 bounds;
};

// A model: the target func_0005E7B0 poses at 0x8, its shape at 0xc.
struct Model_000E30E0 {
    char unknown_00[8];
    void *target;
    Shape_000E30E0 *shape;
};

struct Motion_0005F060;

// The motion set: motions by index.
struct MotionSet_000E30E0 {
    Motion_0005F060 *motions[64];
};

// What func_00025700 (5, ...) returns: its models first, its motion set at 0x18.
struct Bank_000E30E0 {
    Model_000E30E0 **models;
    char unknown_04[0x14];
    MotionSet_000E30E0 *motionSet;
};

struct Mesh_00017F60;

struct Object_00016200 {
    Mesh_00017F60 *func_00019680(const Mesh_00017F60 *mesh);
};

struct Object_0006DB80 {
    int func_0006DAE0(int first, int second, int third, int fourth);
};

void *func_00025700(unsigned int index, int first, int second, int third);
int func_0005E790(void *source, int flags);
int func_0005E7B0(void *target, int first, int second, int third, int fourth);

extern Object_00016200 data_0022FCE8;
extern Object_0006DB80 data_00251F78;
extern Mesh_00017F60 data_002188C0;
extern char data_None[];
extern int data_00218874;
extern char data_00258380[];
extern char data_00258290[];

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
    char unknown_34[0x10];
};

// The second base (table 0x1CE1B8), two slots.
struct Object_000C60C0 {
    virtual void func_000C6090();
    virtual void func_000C60C0();
};

// The class whose tables are at 0x1CE1C8 (Node) and 0x1CE1C0 (Object_000C60C0 at +0x44); slot 15 holds a folded
// thunk.
struct Object_000C7910 : Node, Object_000C60C0 {
    Object_000C7910(Node *owner, int id, unsigned int flags);
    virtual ~Object_000C7910();
    virtual void func_00011C90();
    virtual void func_00011C90_1();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C80_4(int argument);
    virtual void func_000C60C0();

    char unknown_048[0x30];
    Sphere_000E30E0 bounds;
    char unknown_088[8];
    unsigned int flags_90;
    char unknown_094[4];
    int sound;
    char unknown_09c[0x20];
    int unknown_bc;
    char unknown_0c0[0x84];
    int unknown_144;
    char unknown_148[0x3c];
    Model_000E30E0 *model;
    char unknown_188[4];
    MotionSet_000E30E0 *motionSet;
    Motion_0005F060 *motion;
    char unknown_194[8];
    int blocks[3];
    int unknown_1a8;
    int unknown_1ac;
    int unknown_1b0;
    char unknown_1b4[8];
    int unknown_1bc;
    int unknown_1c0;
    int unknown_1c4;
    char unknown_1c8[4];
    int unknown_1cc;
    char unknown_1d0[4];
    const Mesh_00017F60 *mesh_1d4;
    char unknown_1d8[0xc];
    float unknown_1e4;
    char unknown_1e8[0xc];
    float unknown_1f4;
    char unknown_1f8[0x1a0];
    Mesh_00017F60 *mesh_398;
    char unknown_39c[0x1c];
    int effect_3b8;
    char unknown_3bc[8];
};

// The 0x3cc-byte child the factory func_000E32C0 builds for each of its points.
struct Object_000E32A0 : Object_000C7910 {
    Object_000E32A0(Node *owner, int id, unsigned int flags);
    virtual ~Object_000E32A0();

    void *unknown_3c4;
    void *unknown_3c8;
};

// Takes model 1 and the motion set of bank (5, 0) with motion 15, the bounds of the model's shape, three blocks of
// motion 0 posed with motion 15, the mesh at 0x2188C0, flag 0x1000 at 0x90 and a sound handle from data_00251F78.
Object_000E32A0::Object_000E32A0(Node *owner, int id, unsigned int flags)
    : Object_000C7910(owner, id, flags)
{
    Bank_000E30E0 *bank = (Bank_000E30E0 *)func_00025700(5, 0, 0, 0);
    model = bank->models[1];
    motionSet = bank->motionSet;
    unknown_1c4 = 0;
    unknown_1c0 = 6;
    unknown_1bc = 6;
    motion = motionSet->motions[15];
    unknown_1cc = 0;
    unknown_1a8 = 0;
    unknown_1b0 = 0;
    unknown_1ac = 0;
    unknown_bc = 0;
    flags_90 |= 0x1101;
    bounds = model->shape->bounds;
    unknown_144 = data_00218874;
    unknown_3c4 = data_00258380;
    unknown_3c8 = data_00258290;
    blocks[0] = func_0005E790(motionSet->motions[0], 1);
    blocks[1] = func_0005E790(motionSet->motions[0], 1);
    blocks[2] = func_0005E790(motionSet->motions[0], 1);
    func_0005E7B0(model->target, blocks[0], 0, (int)motion, 0);
    mesh_398 = data_0022FCE8.func_00019680(&data_002188C0);
    mesh_1d4 = &data_002188C0;
    unknown_1e4 = 4.0f;
    unknown_1f4 = 4.0f;
    sound = data_00251F78.func_0006DAE0(1, 0, -1, -1);
}
