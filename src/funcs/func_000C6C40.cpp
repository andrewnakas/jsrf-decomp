/* sym: ??0Object_000C6C40@@QAE@PAUNode@@HIPAUVector3@@@Z = 0x000C6C40 */
/* sym: ??1Object_000C6BF0@@UAE@XZ = 0x000C6B90 */
/* sym: ??0Node@@QAE@PAU0@HI@Z = 0x00012100 */
/* sym: ?func_00011C90@Object_000C6BF0@@UAEXXZ = 0x000C6BF0 */
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


struct Vector3 {
    float x;
    float y;
    float z;
};

struct Sphere_00017EC0 {
    Vector3 center;
    float radius;
};

struct Part_00017F60 {
    Sphere_00017EC0 sphere;
    Vector3 motion;
    char unknown_1c[8];
};

struct Mesh_00017F60 {
    Part_00017F60 *parts;
    unsigned int count;
    Sphere_00017EC0 bounds;
};

struct Item_000162A0 {
    int flags;
    int count;
    Mesh_00017F60 *mesh;
    char unknown_0c[8];
    int unknown_14;
};

struct Object_00016200 {
    void func_00019570(Mesh_00017F60 *mesh, const Mesh_00017F60 *source);
    Mesh_00017F60 *func_00019680(const Mesh_00017F60 *mesh);
};

extern Object_00016200 data_0022FCE8;

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Object_000607B0 {
    int func_000651E0(int kind, void *data, Vector3 *direction);
};

struct Object_000C1270 {
    int func_000C1160(int kind, int count, Vector3 *position);
};

extern Object_000C1270 *data_00257CE4;

extern Part_00017F60 data_00216240;

void func_001BAA00();
void __fastcall func_001BAA50();
void __fastcall func_001BAAA0(float *matrix);

// The base whose slot 1 is shared by the tables at 0x1CE078, 0x1CE0B8, 0x1CE0F8, 0x1CE138 and 0x1CE178 (the
// objects func_000C70A0 creates). Its constructor is inline: no store of its own table is left.
struct Object_000C6BF0 : Node {
    Object_000C6BF0(Node *owner, int id, unsigned int flags)
        : Node(owner, id, flags)
    {
    }
    virtual ~Object_000C6BF0();
    virtual void func_00011C90();

    char unknown_40[4];
    int handle;
    int life;
    Item_000162A0 item;
};

// The child with the table at 0x1CE0B8 (constructor func_000C6C40; implicit destructor func_000C7210).
struct Object_000C6C40 : Object_000C6BF0 {
    Object_000C6C40(Node *owner, int id, unsigned int flags, Vector3 *position);
};

// Tells node 0xe8 about itself (func_000651E0, kind 0x21; the answer at 0x44), lives 120 frames and draws one
// part (data_00216240) at the position as its mesh (func_00019680, func_00019570), then plays sound 0x22 there
// (func_000C1160 of data_00257CE4).
Object_000C6C40::Object_000C6C40(Node *owner, int id, unsigned int flags, Vector3 *position)
    : Object_000C6BF0(owner, id, flags)
{
    Mesh_00017F60 source;
    Object_000607B0 *target = (Object_000607B0 *)data_0022FCE0->func_000128C0(0xe8);
    if (target) {
        handle = target->func_000651E0(0x21, position, 0);
    }
    life = 120;
    source.parts = &data_00216240;
    source.count = 1;
    source.bounds = data_00216240.sphere;
    item.mesh = data_0022FCE8.func_00019680(&source);
    item.flags = 0x40;
    item.count = 1;
    func_001BAA00();
    func_001BAAA0(&position->x);
    data_0022FCE8.func_00019570(item.mesh, &source);
    func_001BAA50();
    data_00257CE4->func_000C1160(0x22, 3, position);
}
