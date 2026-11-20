/* sym: ??0Object_000CE9D0@@QAE@PAUDesc_000CF9C0@@@Z = 0x000CE9D0 */
/* sym: ??0Object_00015D50@@QAE@PAX@Z = 0x00015420 */
/* sym: ??1Object_000CE9D0@@UAE@XZ = 0x000CEC70 */
/* sym: ?func_000CD1E0@Object_000CE9D0@@UAEXXZ = 0x000CED90 */
/* sym: ?func_00011C90@Object_000CE9D0@@UAEXXZ = 0x000CDAC0 */
/* sym: ?func_00011C80@Object_000CE9D0@@UAEXH@Z = 0x000CDCF0 */
/* sym: ?func_00011C80_1@Object_000CE9D0@@UAEXH@Z = 0x000CDE90 */
struct Mesh_00017F60;
struct Object_000C5B50;

extern Mesh_00017F60 data_00216580;
extern Mesh_00017F60 data_002165BC;
extern char data_00216480[];

struct Object_00016200 {
    Mesh_00017F60 *func_00019680(const Mesh_00017F60 *mesh);
};

extern Object_00016200 data_0022FCE8;

struct Object_0003E750 {
    int func_0003EE90(void *effect, int first, int second, int third, float scale, int kind, int owner, int fourth);
    void func_0003F410(int key, int value);
};

extern Object_0003E750 data_002314B0;

struct Object_0006DB80 {
    int func_0006DAE0(int first, int second, int third, int fourth);
};

extern Object_0006DB80 data_00251F78;

void *func_00025700(unsigned int index, int first, int second, int third);
int func_0005E790(void *source, int flags);
int func_0005E7B0(void *target, int first, int second, int third, int fourth);

struct Node {
    virtual ~Node();

    unsigned int flags;
    int id;
};

// The object the factories of the table at 0x215D68 serve: a Node.
struct Desc_000CF9C0 : Node {
};

// The two springs at 0x60 and 0x64 (0x118 bytes; func_00015D90 resets them).
struct Object_00015D50 {
    Object_00015D50(void *owner);
    virtual ~Object_00015D50();

    int unknown_04;
    float unknown_08;
    float unknown_0c;
    int unknown_10;
    int unknown_14;
    char unknown_18[0x100];

    void func_00015D90();
};

struct Frame_000CE9D0 {
    char unknown_00[0x74];
    float range;
    char unknown_78[4];
    float scale;
};

struct Model_000CE9D0 {
    char unknown_00[8];
    void *target;
};

// The mesh of entry 0 of table 0x13 of set 5: the model, a frame at 0xc, a value at 0x10 and the springs' owners
// at 0x30 and 0x34.
struct Mesh_000CE9D0 {
    Model_000CE9D0 *model;
    char unknown_04[8];
    Frame_000CE9D0 *frame;
    void *value_10;
    char unknown_14[0x1c];
    void *first;
    void *second;
};

struct Motion_000CE9D0 {
    void *frames;
};

struct Resource_000CE9D0 {
    Mesh_000CE9D0 *mesh;
    char unknown_04[0x14];
    Motion_000CE9D0 *motion;
};

// A probe: its kind, a count, a mesh copy and a spare word.
struct Probe_000CE9D0 {
    int kind;
    int count;
    Mesh_00017F60 *mesh;
    int unknown_0c;
};

// The base with a pure slot 0 (table 0x1CE304).
struct Object_000CC600 {
    virtual void func_000CD1E0() = 0;
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_1(int argument);
    virtual ~Object_000CC600() {}
};

// The behaviour func_000CE9D0 builds (0x140 bytes, table 0x1CE3A0); 0x4 holds the object it serves.
struct Object_000CE9D0 : Object_000CC600 {
    virtual void func_000CD1E0();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_1(int argument);
    Object_000CE9D0(Desc_000CF9C0 *desc);
    virtual ~Object_000CE9D0();

    Object_000C5B50 *owner;
    int state;
    char unknown_0c[0x34];
    int value_40;
    char unknown_44[0x14];
    Mesh_000CE9D0 *mesh;
    void *value_5c;
    Object_00015D50 *first;
    Object_00015D50 *second;
    Motion_000CE9D0 *motion;
    int frame;
    int value_70;
    int value_74;
    int handle_78;
    int handle_7c;
    int value_80;
    int value_84;
    int value_88;
    char unknown_8c[4];
    int value_90;
    int value_94;
    int value_98;
    int value_9c;
    int value_a0;
    Probe_000CE9D0 probe_a4;
    char unknown_b4[0x14];
    Probe_000CE9D0 probe_c8;
    char unknown_d8[0x14];
    Probe_000CE9D0 probe_ec;
    char unknown_fc[0x14];
    int effect;
    int value_114;
    int value_118;
    int sound;
    int value_120;
    int value_124;
    char unknown_128[0x10];
    int handle;
    int value_13c;
};

// Looks up entry 0 of table 0x13 of set 5 (its mesh at 0x58 and value at 0x5c, the frame's range 100 and scale 1),
// makes the two springs at 0x60 and 0x64 (0.6 and 0.08 / 0.04), starts the motion at 0x68 (func_0005E790 twice,
// func_0005E7B0), copies the three probe meshes, starts the effect (owner the node's id) and the sound, and clears
// the rest.
Object_000CE9D0::Object_000CE9D0(Desc_000CF9C0 *desc)
{
    Resource_000CE9D0 *entry = (Resource_000CE9D0 *)func_00025700(5, 0x13, 0, 0);
    mesh = entry->mesh;
    value_5c = mesh->value_10;
    Frame_000CE9D0 *frame = mesh->frame;
    frame->range = 100.0f;
    frame->scale = 1.0f;
    first = new Object_00015D50(mesh->first);
    first->func_00015D90();
    first->unknown_04 = 0;
    first->unknown_08 = 0.6f;
    first->unknown_0c = 0.08f;
    first->unknown_14 = 0;
    first->unknown_10 = 0;
    second = new Object_00015D50(mesh->second);
    second->func_00015D90();
    second->unknown_04 = 0;
    second->unknown_08 = 0.6f;
    second->unknown_0c = 0.04f;
    second->unknown_14 = 0;
    second->unknown_10 = 0;
    motion = entry->motion;
    state = 0;
    value_98 = 0;
    value_94 = 0;
    value_9c = 0;
    value_90 = 0;
    value_80 = 0;
    value_88 = 0;
    value_84 = 0;
    this->frame = (int)motion->frames;
    value_74 = 0;
    value_70 = 0;
    value_a0 = 1;
    value_40 = 0;
    handle_78 = func_0005E790(motion->frames, 1);
    handle_7c = func_0005E790(motion->frames, 1);
    func_0005E7B0(mesh->model->target, handle_78, 0, this->frame, 0);
    probe_a4.mesh = data_0022FCE8.func_00019680(&data_00216580);
    probe_a4.kind = 0x10;
    probe_a4.count = 1;
    probe_a4.unknown_0c = 0;
    probe_c8.mesh = data_0022FCE8.func_00019680(&data_002165BC);
    probe_c8.kind = 0x10;
    probe_c8.count = 1;
    probe_c8.unknown_0c = 0;
    probe_ec.mesh = data_0022FCE8.func_00019680(&data_002165BC);
    probe_ec.kind = 0x10;
    probe_ec.count = 1;
    probe_ec.unknown_0c = 0;
    effect = data_002314B0.func_0003EE90(data_00216480, -1, -1, 1, 7.0f, 2, desc->id, -1);
    data_002314B0.func_0003F410(effect, 0);
    sound = data_00251F78.func_0006DAE0(1, 0, -1, -1);
    value_120 = 0;
    value_114 = 0;
    value_118 = 0;
    value_124 = -1;
    handle = -1;
    value_13c = 0;
}
