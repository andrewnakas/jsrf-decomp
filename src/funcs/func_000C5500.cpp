/* sym: ??0Object_000C5500@@QAE@PAUNode@@HIPAUVector3@@1@Z = 0x000C5500 */
/* sym: ??1Object_000C5500@@UAE@XZ = 0x000C5800 */
/* sym: ??1Object_000C4CF0@@UAE@XZ = 0x000C4E50 */
/* sym: ??0Object_000C4CF0@@QAE@PAUNode@@HIPAUVector3@@1@Z = 0x000C4CF0 */
/* sym: ?func_00011C90@Object_000C4CF0@@UAEXXZ = 0x000C4EB0 */
/* sym: ?func_00011C90_1@Object_000C4CF0@@UAEXXZ = 0x000C5040 */
/* sym: ?func_00011C80@Object_000C4CF0@@UAEXH@Z = 0x000C5170 */
/* sym: ?func_00011C80_3@Object_000C4CF0@@UAEXH@Z = 0x000B3DE0 */
/* sym: ?func_00011C80_4@Object_000C4CF0@@UAEXH@Z = 0x000B3DE0 */
/* sym: ?func_00011C90_10@Object_000C5500@@UAEXXZ = 0x000C55F0 */
/* sym: ?func_00011C90_11@Object_000C5500@@UAEXXZ = 0x000C5610 */
/* sym: ?func_00011C90_12@Object_000C5500@@UAEXXZ = 0x000C5270 */
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

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Object_000607B0 {
    int func_000651E0(int kind, void *data, Vector3 *direction);
};

// What func_00025700 (5, ...) returns: its models.
struct Sprite_000C4CF0 {
    Object_00047470 **models;
};

void *func_00025700(unsigned int index, int first, int second, int third);

void __fastcall func_0014C730(Vector3 *target, Vector3 *direction, float scale);

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

// The child of func_000C4CF0's class with the table at 0x1CDFA0 (constructor func_000C5500).
struct Object_000C5500 : Object_000C4CF0 {
    Object_000C5500(Node *owner, int id, unsigned int flags, Vector3 *position, Vector3 *direction);
    virtual ~Object_000C5500();
    virtual void func_00011C90_10();
    virtual void func_00011C90_11();
    virtual void func_00011C90_12();
};

// Builds the shot (func_000C4CF0) with model 1 of sprite set 18 (func_00025700), tells node 0xe8 (func_000651E0) where
// it starts and where it goes (kind 0x28), and the point two directions behind the start (func_0014C730, kind 0x29).
Object_000C5500::Object_000C5500(Node *owner, int id, unsigned int flags, Vector3 *position, Vector3 *direction)
    : Object_000C4CF0(owner, id, flags, position, direction)
{
    model = ((Sprite_000C4CF0 *)func_00025700(5, 0x12, 0, 0))->models[1];
    Object_000607B0 *target = (Object_000607B0 *)data_0022FCE0->func_000128C0(0xe8);
    if (target) {
        target->func_000651E0(0x28, position, direction);
    }
    Vector3 point = *position;
    func_0014C730(&point, direction, -2.0f);
    target = (Object_000607B0 *)data_0022FCE0->func_000128C0(0xe8);
    if (target) {
        target->func_000651E0(0x29, &point, 0);
    }
}
