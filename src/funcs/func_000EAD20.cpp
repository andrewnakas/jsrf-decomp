/* sym: ??0Object_000EAD20@@QAE@PAUNode@@HIPAUVector3@@@Z = 0x000EAD20 */
/* sym: ??0Node@@QAE@PAU0@HI@Z = 0x00012100 */
/* sym: ??1Object_000EAD20@@UAE@XZ = 0x000EADE0 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ?func_00011C90@Object_000EAD20@@UAEXXZ = 0x000EB200 */
/* sym: ?func_00011C80@Object_000EAD20@@UAEXH@Z = 0x000EAE40 */
/* sym: ?func_00011C80_3@Object_000EAD20@@UAEXH@Z = 0x000B3DE0 */
/* sym: ?func_00011C80_4@Object_000EAD20@@UAEXH@Z = 0x000B3DE0 */
struct Vector3 {
    float x;
    float y;
    float z;
};

struct Mesh_00017F60;

struct Object_00016200 {
    Mesh_00017F60 *func_00019680(const Mesh_00017F60 *mesh);
};

extern Object_00016200 data_0022FCE8;
extern Mesh_00017F60 data_002192CC;

struct Holder_000EAD20 {
    char unknown_00[0x14];
    int value_14;
};

// What func_00025700 gives.
struct Resource_000EAD20 {
    Holder_000EAD20 *holder;
};

void *func_00025700(unsigned int first, int second, int third, int fourth);

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
    unsigned int mask;
    float depth;
    int sortKey;
    char unknown_18[0xc];
    Node *parent;
    Node *child;
    Node *previous;
    Node *next;
    Node *drawNext;
    Node **drawLink;
    Node ***drawTail;
};


// The class whose table is at 0x1CEE90 (0x84 bytes; built by func_000EB160): overrides slots 1, 3 of Node; slots 12,
// 15 hold folded thunks.
struct Object_000EAD20 : Node {
    Object_000EAD20(Node *owner, int id, unsigned int flags, Vector3 *position);
    virtual ~Object_000EAD20();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C80_4(int argument);

    char unknown_40[4];
    Vector3 position;
    Vector3 up;
    int value_5c;
    int kind;
    int size;
    Mesh_00017F60 *handle;
    char unknown_6c[0x18];
};

// Keeps the value at 0x14 of resource (5, 0xc), the position, an up vector (0, 1, 0) and a copy of the mesh at
// data_002192CC with kind 0x40 and size 0x400.
Object_000EAD20::Object_000EAD20(Node *owner, int id, unsigned int flags, Vector3 *position) : Node(owner, id, flags)
{
    Resource_000EAD20 *resource = (Resource_000EAD20 *)func_00025700(5, 0xc, 0, 0);
    value_5c = resource->holder->value_14;
    this->position = *position;
    up.x = 0.0f;
    up.y = 1.0f;
    up.z = 0.0f;
    handle = data_0022FCE8.func_00019680(&data_002192CC);
    kind = 0x40;
    size = 0x400;
}
