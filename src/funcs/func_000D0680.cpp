/* sym: ??0Object_000D0680@@QAE@PAUNode@@HIPAUVector3@@@Z = 0x000D0680 */
/* sym: ??0Node@@QAE@PAU0@HI@Z = 0x00012100 */
/* sym: ??1Object_000D0680@@UAE@XZ = 0x000D07A0 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ?func_00011C90@Object_000D0680@@UAEXXZ = 0x000D0800 */
/* sym: ?func_00011C80@Object_000D0680@@UAEXH@Z = 0x000D08F0 */
/* sym: ?func_00011C80_3@Object_000D0680@@UAEXH@Z = 0x000B3DE0 */
/* sym: ?func_00011C80_4@Object_000D0680@@UAEXH@Z = 0x000B3DE0 */
struct Vector3 {
    float x;
    float y;
    float z;
};

// The part a mesh copy points to first.
struct Part_000D0680 {
    char unknown_00[0xc];
    float scale;
};

struct Mesh_00017F60 {
    Part_000D0680 *part;
    char unknown_04[0x10];
    float scale;
};

// The item at 0x74 (kind, count, mesh).
struct Item_000162A0 {
    int kind;
    int count;
    Mesh_00017F60 *mesh;
    int unknown_0c;
};

struct Object_00016200 {
    void func_000162A0(Item_000162A0 *item);
    Mesh_00017F60 *func_00019680(const Mesh_00017F60 *mesh);
    void func_00019570(Mesh_00017F60 *mesh, const Mesh_00017F60 *source);
};

extern Object_00016200 data_0022FCE8;
extern Mesh_00017F60 data_00216718;

struct Motion_0005F060 {
    short unknown_00;
    short frames;
};

// What the models at 0x60 and 0x64 point to.
struct Frame_000D0680 {
    char unknown_00[4];
    int value_04;
};

struct Sub_000D0680 {
    char unknown_00[0x60];
    float scale;
};

// The two models at 0x60 and 0x64; slot 5 draws.
struct Model_000D0680 {
    virtual void func_0();
    virtual void func_1();
    virtual void func_2();
    virtual void func_3();
    virtual void func_4();
    virtual void func_5(int first, int second);

    char unknown_04[8];
    Sub_000D0680 *sub;
    char unknown_10[0x48];
    float fade;
    char unknown_5c[4];
    Frame_000D0680 *frame;
};

// The eight frame values at 0xc.
struct Table_000D0680 {
    char unknown_00[0xc];
    int values[8];
};

struct Holder_000D0680 {
    char unknown_00[0x38];
    Model_000D0680 *model_38;
    Model_000D0680 *model_3c;
};

struct Source_000D0680 {
    char unknown_00[0x64];
    Motion_0005F060 *motion;
};

// What func_00025700 gives.
struct Resource_000D0680 {
    Holder_000D0680 *holder;
    char unknown_04[0xc];
    Table_000D0680 *table;
    char unknown_14[4];
    Source_000D0680 *source;
};

void *func_00025700(unsigned int first, int second, int third, int fourth);

void func_001BAA00();
void func_001BAA50();
void __fastcall func_001BAAA0(float *vector);

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

    void func_00011BE0(Node *node);
    void func_00011C20(Node *node);

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

// The class whose table is at 0x1CE400 (0x98 bytes; destructor 0xD07A0): overrides slots 1 and 3 of Node; slots 12
// and 15 hold folded thunks.
struct Object_000D0680 : Node {
    Object_000D0680(Node *owner, int id, unsigned int flags, Vector3 *position);
    virtual ~Object_000D0680();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C80_4(int argument);

    Vector3 position;
    float scale;
    float fade;
    unsigned int index;
    int angle;
    Model_000D0680 *model_60;
    Model_000D0680 *model_64;
    Table_000D0680 *table;
    Motion_0005F060 *motion;
    float time;
    Item_000162A0 item;
    char unknown_84[0x14];
};

// Takes the two models, the frame table and the motion of resource (5, 0x13), the position, scale and fade 1, sets
// the template data_00216718's scale from the first model, and makes the mesh copy of the item at 0x74 (kind 0x40),
// placing it twice at the position (func_00019570).
Object_000D0680::Object_000D0680(Node *owner, int id, unsigned int flags, Vector3 *position) : Node(owner, id, flags)
{
    Resource_000D0680 *resource = (Resource_000D0680 *)func_00025700(5, 0x13, 0, 0);
    model_60 = resource->holder->model_38;
    model_64 = resource->holder->model_3c;
    table = resource->table;
    motion = resource->source->motion;
    time = 0.0f;
    this->position = *position;
    scale = 1.0f;
    fade = 1.0f;
    index = 0;
    angle = 0;
    data_00216718.scale = model_60->sub->scale;
    item.mesh = data_0022FCE8.func_00019680(&data_00216718);
    item.kind = 0x40;
    item.count = 1;
    item.unknown_0c = 0;
    func_001BAA00();
    func_001BAAA0(&this->position.x);
    data_0022FCE8.func_00019570(item.mesh, &data_00216718);
    data_0022FCE8.func_00019570(item.mesh, &data_00216718);
    func_001BAA50();
}
