/* sym: ?func_00011C90@Object_000AE220@@UAEXXZ = 0x000AE290 */
struct Vector3 {
    float x;
    float y;
    float z;
};

// The first part of a mesh: a centre and an extent.
struct Part_00017F60 {
    Vector3 center;
    float radius;
    Vector3 extent;
    char unknown_1c[8];
};

struct Mesh_00017F60 {
    Part_00017F60 *parts;
    unsigned int count;
};

// What data_0022FCE8 keeps for the node (0x198): a kind, a value and the mesh.
struct Item_000162A0 {
    int kind;
    int value;
    Mesh_00017F60 *mesh;
};

struct Object_00016200 {
    void func_000162A0(Item_000162A0 *item);
    void func_00017F60(Mesh_00017F60 *mesh);
};

extern Object_00016200 data_0022FCE8;

struct Object_0006A960 {
    int func_0006AAA0(Vector3 *position, int hint);
    float func_0006AC40(Vector3 *position, int key);
};

extern Object_0006A960 data_0020C6C0;

// Where func_000BAC60 places the object: position, angles, scale and a model code (bank << 10 | index).
struct Params_000BAC60 {
    Vector3 position;
    int angles[3];
    Vector3 scale;
    unsigned int model;
};

struct Node {
    virtual ~Node();
    virtual void func_00011C90();

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

// One of 17 direct children of Node that share slots 4, 5, 6, 12 and 15 (table 0x1CD730).
struct Object_000AE220 : Node {
    virtual void func_00011C90();

    char unknown_040[8];
    Params_000BAC60 placement;
    char unknown_070[0x44];
    float height;
    char unknown_0b8[0x20];
    int key;
    float floor;
    int seen;
    int value_e4;
    char unknown_0e8[0x10];
    Vector3 position;
    int angles[3];
    Vector3 scale;
    Vector3 first;
    Vector3 second;
    Vector3 extent;
    int alpha;
    char unknown_144[0x40];
    int value_184;
    int value_188;
    int value_18c;
    int mode;
    char unknown_194[4];
    Item_000162A0 item;
    char unknown_1a4[0x18];
    Mesh_00017F60 mesh;
};

// Slot 1: mode 0 takes the placement's scale, keeps the position twice, makes the mesh (func_00017F60) with its first
// part at the position raised by the height at 0xb4, hands the mesh to the item (kind 0x800) and finds the key and
// floor at the position in data_0020C6C0, then goes on as mode 1: a seen node (0xe0, 0xe4) remakes its mesh and
// queues its item. Mode 10 leaves the draw links.
void Object_000AE220::func_00011C90()
{
    switch (mode) {
    case 10:
        func_00011BE0(this);
        func_00011C20(child);
        break;
    case 0:
        mode = 1;
        scale.x = placement.scale.x;
        scale.y = placement.scale.y;
        scale.z = placement.scale.z;
        first.x = position.x;
        first.y = position.y;
        first.z = position.z;
        second.x = position.x;
        second.y = position.y;
        second.z = position.z;
        extent.x = 0;
        extent.y = 0;
        extent.z = 0;
        alpha = 0xff;
        value_18c = 0;
        value_184 = 0;
        value_188 = 0;
        data_0022FCE8.func_00017F60(&mesh);
        mesh.parts->center.x = first.x;
        mesh.parts->center.y = height + first.y;
        mesh.parts->center.z = first.z;
        mesh.parts->extent = extent;
        item.value = 3;
        item.kind = 0x800;
        item.mesh = &mesh;
        key = data_0020C6C0.func_0006AAA0(&position, key);
        floor = data_0020C6C0.func_0006AC40(&position, key);
    case 1:
        if (seen && value_e4) {
            data_0022FCE8.func_00017F60(&mesh);
            data_0022FCE8.func_000162A0(&item);
        }
        break;
    }
}
