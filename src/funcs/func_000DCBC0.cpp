/* sym: ??0Object_000DCBC0@@QAE@PAUDesc_000DCBC0@@@Z = 0x000DCBC0 */
/* sym: ??0Object_000CCE00@@QAE@XZ = 0x000CC620 */
/* sym: ??1Object_000DCBC0@@UAE@XZ = 0x000DCDD0 */
/* sym: ??1Object_000CCE00@@UAE@XZ = 0x000CC680 */
/* sym: ?func_000CD1E0@Object_000DCBC0@@UAEXXZ = 0x000DE8A0 */
/* sym: ?func_00011C90@Object_000DCBC0@@UAEXXZ = 0x000DCE90 */
/* sym: ?func_00011C80@Object_000DCBC0@@UAEXH@Z = 0x000DCFF0 */
/* sym: ?func_00011C80_1@Object_000DCBC0@@UAEXH@Z = 0x000DD370 */
/* sym: ?func_000CBCD0@Object_000DCBC0@@UAEXXZ = 0x000DD670 */
/* sym: ?func_000CBD90@Object_000DCBC0@@UAEXXZ = 0x000DD7A0 */
/* sym: ?func_000CBE60@Object_000DCBC0@@UAEXXZ = 0x000DE9E0 */
/* sym: ?func_000CC910@Object_000DCBC0@@UAEXXZ = 0x000DEBB0 */
/* sym: ?func_000CD060@Object_000DCBC0@@UAEXXZ = 0x000DEC50 */
/* sym: ?func_000CD140@Object_000DCBC0@@UAEXXZ = 0x000DECD0 */
/* sym: ?func_000CD1A0@Object_000DCBC0@@UAEXXZ = 0x000DEE50 */
/* sym: ?func_000CBF90@Object_000DCBC0@@UAEXXZ = 0x000DF070 */
/* sym: ?func_000CBFC0@Object_000DCBC0@@UAEXXZ = 0x000DD830 */
/* sym: ?func_000CCA40@Object_000DCBC0@@UAEXXZ = 0x000DD8A0 */
extern "C" void *memset(void *destination, int value, unsigned int size);

struct Mesh_00017F60;
struct Motion_0005F060;

// The motion set of a bank: motions by index.
// A bounding sphere (0x10 bytes).
struct Sphere_000DCBC0 {
    float x;
    float y;
    float z;
    float radius;
};

// The shape at 0xc of a model: its bounds at 0x54.
struct Shape_000DCBC0 {
    char unknown_00[0x54];
    Sphere_000DCBC0 bounds;
};

// A model: the target func_0005E7B0 poses at 0x8, its shape at 0xc.
struct Model_000DCBC0 {
    char unknown_00[8];
    void *target;
    Shape_000DCBC0 *shape;
};

struct MotionSet_000DCBC0 {
    Motion_0005F060 *motions[20];
};

// What func_00025700 (5, 1) returns: its models first, its motion set at 0x18.
struct Bank_000DCBC0 {
    Model_000DCBC0 **models;
    char unknown_04[0x14];
    MotionSet_000DCBC0 *motionSet;
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
    void func_0006DEB0(int key, int value);
};

extern Object_00016200 data_0022FCE8;
extern Object_0003E750 data_002314B0;
extern Object_0006DB80 data_00251F78;
extern Mesh_00017F60 data_002179F8;
extern char data_00217878[];

void *func_00025700(unsigned int index, int first, int second, int third);
int func_0005E790(void *source, int flags);
int func_0005E7B0(void *target, int first, int second, int third, int fourth);

// The object the behaviour serves: its id at 0x8, flags at 0xa4.
struct Desc_000DCBC0 {
    char unknown_00[8];
    int id;
    char unknown_0c[0x98];
    unsigned int flags_a4;
};

// The base with a pure slot 0 (table 0x1CE304, destructor func_000E7EB0).
struct Object_000CC600 {
    virtual void func_000CD1E0() = 0;
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_1(int argument);
    virtual ~Object_000CC600();
};

// The class whose table is at 0x1CE320 (constructor func_000CC620, destructor func_000CC680).
struct Object_000CCE00 : Object_000CC600 {
    Object_000CCE00();
    virtual void func_000CD1E0();
    virtual void func_00011C90();
    virtual ~Object_000CCE00();
    virtual void func_000CBCD0();
    virtual void func_000CBD90();
    virtual void func_000CBE60();
    virtual void func_000CBF20();
    virtual void func_000CC910();
    virtual void func_000CD060();
    virtual void func_000CD140();
    virtual void func_000CD1A0();
    virtual void func_000CBF90();
    virtual void func_000CBFC0();
    virtual void func_000CCA40();
    virtual void func_000CC020();

    void *owner;
    int state;
    int unknown_0c;
    int count;
    char unknown_14[0x1c];
    void *limits;
};

// The class whose table is at 0x1CE7B8 (constructor func_000DCBC0, which runs func_000CC620 first); slots 8 and 16
// stay Object_000CCE00's.
struct Object_000DCBC0 : Object_000CCE00 {
    Object_000DCBC0(Desc_000DCBC0 *desc);
    virtual void func_000CD1E0();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_1(int argument);
    virtual ~Object_000DCBC0();
    virtual void func_000CBCD0();
    virtual void func_000CBD90();
    virtual void func_000CBE60();
    virtual void func_000CC910();
    virtual void func_000CD060();
    virtual void func_000CD140();
    virtual void func_000CD1A0();
    virtual void func_000CBF90();
    virtual void func_000CBFC0();
    virtual void func_000CCA40();

    char unknown_034[0x11c];
    Sphere_000DCBC0 bounds;
    char unknown_160[0x20];
    Model_000DCBC0 **models;
    int value_184;
    int value_188;
    int value_18c;
    MotionSet_000DCBC0 *motionSet;
    Motion_0005F060 *motion;
    char unknown_198[8];
    int items[3];
    int value_1ac;
    int value_1b0;
    int value_1b4;
    char unknown_1b8[8];
    int value_1c0;
    int value_1c4;
    int value_1c8;
    int value_1cc;
    char unknown_1d0[0xd0];
    int value_2a0;
    int value_2a4;
    Mesh_00017F60 *mesh;
    int value_2ac;
    char unknown_2b0[0x14];
    int effect;
    int value_2c8;
    int value_2cc;
    int key;
    int value_2d4;
};

// Takes the models and motion set of bank (5, 1) with the bounds of model 0's shape, motion 19, three blocks of
// motion 0 posed with it, the mesh at 0x2179F8 and, when the owner has flag 0x4000 at 0xa4, the effect at 0x217878
// and a key from data_00251F78 (released at once with func_0006DEB0).
Object_000DCBC0::Object_000DCBC0(Desc_000DCBC0 *desc)
{
    Bank_000DCBC0 *bank = (Bank_000DCBC0 *)func_00025700(5, 1, 0, 0);
    models = bank->models;
    motionSet = bank->motionSet;
    value_184 = 4;
    value_188 = 6;
    value_18c = 0xb;
    bounds = models[0]->shape->bounds;
    state = 0;
    value_1c4 = 0;
    value_1c0 = 0;
    value_1c8 = 0;
    value_1cc = 0;
    value_1ac = 0;
    value_1b4 = 0;
    value_1b0 = 0;
    motion = motionSet->motions[19];
    items[0] = func_0005E790(motionSet->motions[0], 1);
    items[1] = func_0005E790(motionSet->motions[0], 1);
    items[2] = func_0005E790(motionSet->motions[0], 1);
    func_0005E7B0(models[0]->target, items[0], 0, (int)motion, 0);
    mesh = data_0022FCE8.func_00019680(&data_002179F8);
    value_2a0 = 2;
    value_2a4 = 0x201;
    value_2ac = 0;
    if (desc->flags_a4 & 0x4000) {
        effect = data_002314B0.func_0003EE90(data_00217878, -1, -1, 1, 3.0f, 2, desc->id, -1);
        data_002314B0.func_0003F410(effect, 0);
        key = data_00251F78.func_0006DAE0(1, 0, -1, -1);
        if (key != -1) {
            data_00251F78.func_0006DEB0(key, 0);
        }
    } else {
        effect = -1;
        key = -1;
    }
    value_2d4 = 0;
    value_2c8 = 0;
    value_2cc = 0;
}
