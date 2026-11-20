/* sym: ??0Object_000F4A30@@QAE@PAUNode@@HI@Z = 0x000F4820 */
/* sym: ??1Object_000F4A30@@UAE@XZ = 0x000F4A30 */
/* sym: ??0Object_000C7910@@QAE@PAUNode@@HI@Z = 0x000C8680 */
/* sym: ??1Object_000C7910@@UAE@XZ = 0x000C7240 */
/* sym: ?func_000C60C0@Object_000C7910@@UAEXXZ = 0x000C9EB0 */
struct Mesh_00017F60;

struct Object_00016200 {
    Mesh_00017F60 *func_00019680(const Mesh_00017F60 *mesh);
};

extern Object_00016200 data_0022FCE8;

struct Object_0003E750 {
    int func_0003EE90(void *effect, int first, int second, int third, float scale, int fourth, int id, int fifth);
    void func_0003F410(int index, int value);
};

extern Object_0003E750 data_002314B0;

struct Object_0006DB80 {
    int func_0006DAE0(int kind, int value, int first, int second);
    void func_0006DEB0(int key, int value);
};

extern Object_0006DB80 data_00251F78;

extern Mesh_00017F60 data_0021B610;
extern char data_0021B398[];
extern int data_0021B5C4;
extern char data_00258598[];
extern char data_00258688[];

void *func_00025700(unsigned int index, int first, int second, int third);
int func_0005E790(void *source, int flags);
int func_0005E7B0(void *source, int first, int second, int third, int fourth);

// A centre and a radius.
struct Sphere_000F4820 {
    float x;
    float y;
    float z;
    float radius;
};

// What a model points at (0x0c): its bounds at 0x54.
struct Info_000F4820 {
    char unknown_00[0x54];
    Sphere_000F4820 bounds;
};

// The model of resource 5/3.
struct Model_000F4820 {
    int unknown_00[2];
    void *skeleton;
    Info_000F4820 *info;
};

struct Holder_000F4820 {
    Model_000F4820 *model;
};

// The motion set of resource 5/3: its source at 0, a value at 0x3c.
struct Motions_000F4820 {
    void *source;
    char unknown_04[0x38];
    int value;
};

// Resource 5/3.
struct Resource_000F4820 {
    Holder_000F4820 *holder;
    int unknown_04[5];
    Motions_000F4820 *motions;
};

// The node that makes this one; its flags at 0xa4.
struct Owner_000F4820 {
    char unknown_00[0xa4];
    unsigned int flags;
};

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

// The second base (table 0x1CE1B8), two slots.
struct Object_000C60C0 {
    virtual void func_000C6090();
    virtual void func_000C60C0();
};

// The class whose tables are at 0x1CE1C8 (Node) and 0x1CE1C0 (Object_000C60C0 at +0x44).
struct Object_000C7910 : Node, Object_000C60C0 {
    Object_000C7910(Node *owner, int id, unsigned int flags);
    virtual ~Object_000C7910();
    virtual void func_000C60C0();

    char unknown_048[0x30];
    Sphere_000F4820 bounds;
    char unknown_088[8];
    unsigned int flags;
    char unknown_094[4];
    int sound;
    char unknown_09c[0x20];
    int unknown_bc;
    char unknown_0c0[0x84];
    int unknown_144;
    char unknown_148[0x3c];
    Model_000F4820 *model;
    char unknown_188[4];
    Motions_000F4820 *motions;
    int value_190;
    char unknown_194[8];
    int blocks_19c[3];
    int unknown_1a8[3];
    char unknown_1b4[8];
    int unknown_1bc;
    int unknown_1c0;
    int unknown_1c4;
    char unknown_1c8[4];
    int unknown_1cc;
    char unknown_1d0[4];
    Mesh_00017F60 *source_1d4;
    char unknown_1d8[0xc];
    float unknown_1e4;
    char unknown_1e8[0xc];
    float unknown_1f4;
    char unknown_1f8[0x1a0];
    Mesh_00017F60 *mesh_398;
    char unknown_39c[0x1c];
    int effect_3b8;
    int value_3bc;
    int value_3c0;
};

// The class whose tables are at 0x1CF0E0 and 0x1CF0D8: overrides only the destructor of Object_000C7910.
struct Object_000F4A30 : Object_000C7910 {
    Object_000F4A30(Node *owner, int id, unsigned int flags);
    virtual ~Object_000F4A30();

    void *table_3c4;
    void *table_3c8;
};

// Takes the model and motion set of resource 5/3 with their blocks, sets flags 0x101, copies a mesh, plays effect
// 0x21B398 when the owner has flag 0x4000 and takes a sound of kind 1.
Object_000F4A30::Object_000F4A30(Node *owner, int id, unsigned int flags)
    : Object_000C7910(owner, id, flags)
{
    Resource_000F4820 *resource = (Resource_000F4820 *)func_00025700(5, 3, 0, 0);
    unsigned int state = this->flags;
    model = resource->holder->model;
    motions = resource->motions;
    unknown_1c4 = 0;
    unknown_1c0 = 6;
    unknown_1bc = 6;
    value_190 = motions->value;
    unknown_1cc = 0;
    unknown_1a8[0] = 0;
    unknown_1a8[2] = 0;
    unknown_1a8[1] = 0;
    unknown_bc = 0;
    this->flags = state | 0x101;
    bounds = model->info->bounds;
    unknown_144 = data_0021B5C4;
    table_3c4 = data_00258598;
    table_3c8 = data_00258688;
    blocks_19c[0] = func_0005E790(motions->source, 1);
    blocks_19c[1] = func_0005E790(motions->source, 1);
    blocks_19c[2] = func_0005E790(motions->source, 1);
    func_0005E7B0(model->skeleton, blocks_19c[0], 0, value_190, 0);
    mesh_398 = data_0022FCE8.func_00019680(&data_0021B610);
    source_1d4 = &data_0021B610;
    unknown_1e4 = 4.0f;
    unknown_1f4 = 4.0f;
    if (((Owner_000F4820 *)owner)->flags & 0x4000) {
        effect_3b8 = data_002314B0.func_0003EE90(data_0021B398, -1, -1, 1, 0.5f, 1, Node::id, -1);
        data_002314B0.func_0003F410(effect_3b8, 0);
    }
    sound = data_00251F78.func_0006DAE0(1, 0, -1, -1);
    if (sound != -1) {
        data_00251F78.func_0006DEB0(sound, 0);
    }
}
