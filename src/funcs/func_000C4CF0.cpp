/* sym: ??0Object_000C4CF0@@QAE@PAUNode@@HIPAUVector3@@1@Z = 0x000C4CF0 */
/* sym: ??1Object_000C4CF0@@UAE@XZ = 0x000C4E50 */
/* sym: ??0Node@@QAE@PAU0@HI@Z = 0x00012100 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ?func_00011C90@Object_000C4CF0@@UAEXXZ = 0x000C4EB0 */
/* sym: ?func_00011C90_1@Object_000C4CF0@@UAEXXZ = 0x000C5040 */
/* sym: ?func_00011C80@Object_000C4CF0@@UAEXH@Z = 0x000C5170 */
/* sym: ?func_00011C80_3@Object_000C4CF0@@UAEXH@Z = 0x000B3DE0 */
/* sym: ?func_00011C80_4@Object_000C4CF0@@UAEXH@Z = 0x000B3DE0 */
struct Vector3 {
    float x;
    float y;
    float z;
};

// Three angles (x, y, z).
struct Angles_000C1300 {
    int x;
    int y;
    int z;
};

struct Box_00017CC0 {
    Vector3 min;
    Vector3 max;
};

// The collision item of data_0022FCE8 (func_00016260): a mask and a box.
struct Item_00016260 {
    int mask;
    int value;
    Box_00017CC0 box;
    int unknown_20[8];
    Item_00016260 *next;
};

struct Part_00017FD0 {
    char unknown_00[0x18];
    float scale;
};

struct Mesh_00017FD0 {
    Part_00017FD0 *part;
};

struct Matrix_001BA950 {
    float m[4][4];
};

// The models' base (tables 0x1CA490, 0x1CAA8C, 0x1CC12C).
struct Object_00047470 {
    virtual ~Object_00047470();
};

extern "C" void *memset(void *destination, int value, unsigned int size);

float __fastcall func_0014C460(Vector3 *out, const Vector3 *in);

// The object in data_00257CE8.
struct Object_00157F10 {
    void func_000C1F20(Angles_000C1300 *angles, Vector3 *direction, int step);
};

extern Object_00157F10 *data_00257CE8;

struct Object_00016200 {
    Mesh_00017FD0 *func_000196F0(const Mesh_00017FD0 *mesh);
};

extern Object_00016200 data_0022FCE8;
extern Mesh_00017FD0 data_002161FC;

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

    void func_00011BE0(Node *node);
    void func_00011C20(Node *node);
};

// The child of Node whose table is at 0x1CDE60 (constructor func_000C4CF0, destructor func_000C4E50): it
// overrides slots 1, 2, 3, 12 and 15 and adds three empty slots, 16 to 18. A shot: it starts at a point (0x44 and
// 0x50) going along a direction (0x5c, angles at 0x74) for a life (0x8c, frames), with a model (0x90), a collision item
// (0x94) and a drawing item (0xd8) on a mesh of its own (0xfc).
struct Object_000C4CF0 : Node {
    Object_000C4CF0(Node *owner, int id, unsigned int flags, Vector3 *position, Vector3 *direction);
    virtual ~Object_000C4CF0();
    virtual void func_00011C90();
    virtual void func_00011C90_1();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C80_4(int argument);
    virtual void func_00011C90_10();
    virtual void func_00011C90_11();
    virtual void func_00011C90_12();

    char unknown_040[4];
    Vector3 origin;
    Vector3 position;
    Vector3 direction;
    Vector3 unknown_068;
    Angles_000C1300 angles;
    int roll;
    int value_084;
    int value_088;
    int life;
    Object_00047470 *model;
    Item_00016260 item;
    int drawFlags;
    int drawCount;
    Mesh_00017FD0 *drawMesh;
    int drawValue;
    char unknown_0e8[0x14];
    Mesh_00017FD0 *mesh;
};

// Builds the Node part (flag 0x1000), starts at the position going along the direction made unit length
// (func_0014C460) with its angles (func_000C1F20 of data_00257CE8); a zero direction removes it at once
// (func_00011BE0, func_00011C20). Life 180, an empty collision item with mask 0xf3ff, and a drawing item (0x100, 1) on
// a copy of the mesh data_002161FC (func_000196F0), also kept at 0xfc for the destructor.
Object_000C4CF0::Object_000C4CF0(Node *owner, int id, unsigned int flags, Vector3 *position, Vector3 *direction)
    : Node(owner, id, flags)
{
    this->flags |= 0x1000;
    this->position = *position;
    origin = *position;
    this->direction = *direction;
    if (func_0014C460(&this->direction, &this->direction) != 0.0f) {
        data_00257CE8->func_000C1F20(&angles, &this->direction, 0x8000);
    } else {
        memset(&this->direction, 0, sizeof this->direction);
        func_00011BE0(this);
        func_00011C20(child);
    }
    roll = 0;
    value_084 = 0;
    value_088 = 1;
    life = 180;
    memset(&item, 0, sizeof item);
    item.mask = 0xf3ff;
    drawMesh = mesh = data_0022FCE8.func_000196F0(&data_002161FC);
    drawValue = 0;
    drawFlags = 0x100;
    drawCount = 1;
}
