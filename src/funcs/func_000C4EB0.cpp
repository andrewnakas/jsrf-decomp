/* sym: ?func_00011C90@Object_000C4CF0@@UAEXXZ = 0x000C4EB0 */
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

// The part of the collision item func_00018260 tests: two counts, at +0x4 and +0x14.
struct Model_00018260 {
    void *unknown_00;
    unsigned int count;
    char unknown_08[0xc];
    unsigned int otherCount;
    char unknown_18[8];
};

// The collision item of data_0022FCE8 (func_00016260): a mask, a box and a shape.
struct Item_00016260 {
    int mask;
    int value;
    Box_00017CC0 box;
    Model_00018260 shape;
    Item_00016260 *next;
};

// The drawing item of data_0022FCE8 (func_000162E0).
struct Item_000162A0 {
    int flags;
    int count;
    void *mesh;
    int value;
    char unknown_10[8];
};

// The shot's own mesh (0xfc): one capsule part (ends at 0 and 0xc, radius at 0x18, motion at 0x1c) and a bounding
// sphere (centre at 8, radius at 0x14).
struct Part_000C4EB0 {
    Vector3 end;
    Vector3 start;
    float radius;
    Vector3 motion;
};

struct Mesh_000C4EB0 {
    Part_000C4EB0 *parts;
    unsigned int count;
    Vector3 center;
    float radius;
};

struct Object_00016200 {
    void func_00016260(Item_00016260 *item, int value);
    void func_000162E0(Item_000162A0 *item);
    void func_00017CC0(Box_00017CC0 *box, const Vector3 *points, unsigned int count);
};

extern Object_00016200 data_0022FCE8;

struct Object_00047470;

void __fastcall func_0014C340(Vector3 *vector, const Vector3 *offset);
void __fastcall func_0014C370(Vector3 *out, const Vector3 *in, float scale);
void __fastcall func_0014C4C0(Vector3 *out, const Vector3 *from, const Vector3 *to);
float __fastcall func_0014C6B0(const Vector3 *vector);

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
    int active;
    int life;
    Object_00047470 *model;
    Item_00016260 item;
    Item_000162A0 draw;
    char unknown_0f0[0xc];
    Mesh_000C4EB0 *mesh;
};

// Slot 1: runs slot 16, then counts the life down; at 0 it unlinks itself. While active (0x88) the collision item's
// box spans the start point and the position (func_00017CC0, func_00016260) and the mesh becomes a capsule from
// the start point to the position (the sphere around their midpoint, the part's motion = how far the centre moved)
// drawn with func_000162E0; otherwise both contact counts and the drawing value are cleared. The roll always turns
// by 0xccc.
void Object_000C4CF0::func_00011C90()
{
    func_00011C90_10();
    if (--life == 0) {
        func_00011BE0(this);
        func_00011C20(child);
    } else if (active) {
        Box_00017CC0 box;
        box.min = origin;
        box.max = position;
        data_0022FCE8.func_00017CC0(&item.box, &box.min, 2);
        data_0022FCE8.func_00016260(&item, -1);
        func_0014C4C0(&box.max, &box.max, &box.min);
        func_0014C370(&box.max, &box.max, 0.5f);
        mesh->radius = func_0014C6B0(&box.max) + mesh->parts->radius;
        func_0014C340(&box.min, &box.max);
        func_0014C4C0(&mesh->parts->motion, &box.min, &mesh->center);
        mesh->center = box.min;
        mesh->parts->end = position;
        mesh->parts->start = origin;
        data_0022FCE8.func_000162E0(&draw);
    } else {
        item.shape.count = 0;
        item.shape.otherCount = 0;
        draw.value = 0;
    }
    roll += 0xccc;
}
