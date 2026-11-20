/* sym: ??0Object_000E5FF0@@QAE@PAUDesc_000E5FF0@@@Z = 0x000E5FF0 */
/* sym: ??1Object_000E5FF0@@UAE@XZ = 0x000E6100 */
/* sym: ?func_000CD1E0@Object_000E5FF0@@UAEXXZ = 0x000E6180 */
/* sym: ?func_00011C90@Object_000E5FF0@@UAEXXZ = 0x000E6900 */
/* sym: ?func_00011C80@Object_000E5FF0@@UAEXH@Z = 0x000E5450 */
extern "C" void *memset(void *destination, int value, unsigned int size);

struct Mesh_00017F60;
struct Model_000E5FF0;
struct Motion_0005F060;

// The motion set of a bank: motions by index.
struct MotionSet_000E5FF0 {
    Motion_0005F060 *motions[1];
};

// What func_00025700 (5, 0x17) returns: its models first, its motion set at 0x18.
struct Bank_000E5FF0 {
    Model_000E5FF0 **models;
    char unknown_04[0x14];
    MotionSet_000E5FF0 *motionSet;
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
extern Mesh_00017F60 data_00218D78;
extern char data_00218C78[];

void *func_00025700(unsigned int index, int first, int second, int third);

// The object the behaviour serves: its id at 0x8.
struct Desc_000E5FF0 {
    char unknown_00[8];
    int id;
};

// A 0x44-byte block (kind 0xbdff) of the three at 0x88.
struct Block_000E5FF0 {
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

// The behaviour whose table is at 0x1CED80 (0x184 bytes).
struct Object_000E5FF0 : Object_000CC600 {
    Object_000E5FF0(Desc_000E5FF0 *desc);
    virtual void func_000CD1E0();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual ~Object_000E5FF0();

    Desc_000E5FF0 *owner;
    int state;
    char unknown_0c[0x24];
    int value_30;
    int value_34;
    char unknown_38[0x14];
    int key;
    int value_50;
    Model_000E5FF0 *model;
    MotionSet_000E5FF0 *motionSet;
    Motion_0005F060 *motion;
    int value_60;
    int value_64;
    int value_68;
    Mesh_00017F60 *mesh;
    int value_70;
    char unknown_74[0x14];
    Block_000E5FF0 blocks[3];
    char unknown_154[0x24];
    int effect;
    int value_17c;
    int value_180;
};

// Takes model 0, the motion set and motion 0 of bank (5, 0x17), three blocks of kind 0xbdff, the mesh at 0x218D78, the
// effect at 0x218C78 and a key from data_00251F78.
Object_000E5FF0::Object_000E5FF0(Desc_000E5FF0 *desc)
{
    Bank_000E5FF0 *bank = (Bank_000E5FF0 *)func_00025700(5, 0x17, 0, 0);
    model = bank->models[0];
    motionSet = bank->motionSet;
    motion = motionSet->motions[0];
    value_60 = 0;
    value_50 = 0;
    state = 0;
    value_30 = 0;
    value_34 = 0;
    memset(blocks, 0, sizeof blocks);
    blocks[0].kind = 0xbdff;
    blocks[1].kind = 0xbdff;
    blocks[2].kind = 0xbdff;
    mesh = data_0022FCE8.func_00019680(&data_00218D78);
    value_64 = 0x400;
    value_68 = 1;
    value_70 = 0;
    effect = data_002314B0.func_0003EE90(data_00218C78, -1, -1, 1, 0.1f, 1, desc->id, -1);
    data_002314B0.func_0003F410(effect, 0);
    value_17c = 0;
    value_180 = 0;
    key = data_00251F78.func_0006DAE0(1, 0, -1, -1);
}
