/* sym: ?func_00011C90@Object_000AF790@@UAEXXZ = 0x000AF860 */
struct Vector3 {
    float x;
    float y;
    float z;
};

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
// Where func_000BAC60 places the object: position, angles, scale and a model code (bank << 10 | index).
struct Params_000BAC60 {
    Vector3 position;
    int angles[3];
    Vector3 scale;
    unsigned int model;
};

// A 0x40-byte entry (bank 6, table 5 of group 0xc): the key of an extra model at 0x34 (or -1).
struct Entry_000AF090 {
    char unknown_00[0x34];
    int extraKey;
    int unknown_38;
    int unknown_3c;
};

// A part of the drawn shape: its place and a second point at 0x10.
struct Part_000AF860 {
    Vector3 position;
    int unknown_0c;
    Vector3 point;
};

struct Mesh_00017F60 {
    Part_000AF860 *parts;
    unsigned int count;
    float bounds[4];
};

// With an extra model: eight corner points and a centre at 0x60.
struct Mesh_000181F0 {
    Vector3 *points;
    unsigned int count;
    float bounds[4];
};

// A draw-list item: flags, count and the mesh it draws.
struct Item_000162A0 {
    unsigned int flags;
    int count;
    void *mesh;
    Item_000162A0 *head;
    Item_000162A0 **tail;
    int unknown_14;
};

struct Object_00016200 {
    void func_00016320(Item_000162A0 *item);
    void func_000162A0(Item_000162A0 *item);
    void func_00017F60(Mesh_00017F60 *mesh);
    void func_000181F0(Mesh_000181F0 *mesh);
};

extern Object_00016200 data_0022FCE8;

struct Object_0006A960 {
    int func_0006AAA0(Vector3 *position, int index);
    float func_0006AC40(Vector3 *position, int index);
};

extern Object_0006A960 data_0020C6C0;

void func_001BA9C0();
void __fastcall func_001BAA50();
void __fastcall func_001BAAA0(float *vector);
void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);
void __fastcall func_001BAC50(int *angles, int order);
void __fastcall func_001BB270(float *scale);

// One of 17 direct children of Node that share slots 4, 5, 6, 12 and 15 (table 0x1CD7B0).
struct Object_000AF790 : Node {
    virtual ~Object_000AF790();
    virtual void func_00011C90();

    int unknown_40;
    int unknown_44;
    int unknown_48;
    int state;
    Params_000BAC60 placement;
    Entry_000AF090 entry;
    int cell;
    float height;
    int visible;
    int ready;
    char unknown_0c8[0xc];
    Vector3 position;
    int angles[3];
    Vector3 size;
    Vector3 low;
    Vector3 high;
    Vector3 velocity;
    char unknown_11c[0x24];
    int alpha;
    char unknown_144[0x40];
    int unknown_184;
    int unknown_188;
    char unknown_18c[4];
    Vector3 *extra;
    Item_000162A0 firstItem;
    char unknown_1ac[0xc];
    Mesh_000181F0 firstMesh;
    Item_000162A0 secondItem;
    char unknown_1e8[0xc];
    Mesh_00017F60 secondMesh;
};

// Slot 1. On the first frame (state 0, then 1) takes its size from the placement's scale and its bounds from the
// position, clears the velocity, sets alpha 0xff, and either puts the extra model's eight points (0x190) in its frame
// (with an extra model, 0xac not -1) or fills the plain shape (func_00017F60) at its bounds; then takes the cell and
// height of the position (data_0020C6C0). While 0xc0 and 0xc4 are set, hands the shape and its draw item to
// data_0022FCE8 (func_000181F0 and func_00016320, or func_00017F60 and func_000162A0).
void Object_000AF790::func_00011C90()
{
    switch (state) {
    case 0:
        state = 1;
        size.x = placement.scale.x;
        size.y = placement.scale.y;
        size.z = placement.scale.z;
        low.x = position.x;
        low.y = position.y;
        low.z = position.z;
        high.x = position.x;
        high.y = position.y;
        high.z = position.z;
        velocity.x = 0.0f;
        velocity.y = 0.0f;
        velocity.z = 0.0f;
        alpha = 0xff;
        unknown_48 = 0;
        unknown_184 = 0;
        unknown_188 = 0;
        if (entry.extraKey != -1) {
            func_001BA9C0();
            func_001BAAA0(&position.x);
            func_001BAC50(angles, 0);
            func_001BB270(&size.x);
            for (int i = 0; i < 8; i++) {
                func_001BAB20(&firstMesh.points[i], &extra[i]);
            }
            func_001BAA50();
            firstMesh.points[8] = velocity;
            firstItem.count = 1;
            firstItem.flags = 0x800;
            firstItem.mesh = &firstMesh;
        } else {
            data_0022FCE8.func_00017F60(&secondMesh);
            secondMesh.parts->position.x = low.x;
            secondMesh.parts->position.y = low.y;
            secondMesh.parts->position.z = low.z;
            secondMesh.parts->point = velocity;
            secondItem.count = 1;
            secondItem.flags = 0x800;
            secondItem.mesh = &secondMesh;
        }
        cell = data_0020C6C0.func_0006AAA0(&position, cell);
        height = data_0020C6C0.func_0006AC40(&position, cell);
    case 1:
        if (visible && ready) {
            if (entry.extraKey != -1) {
                data_0022FCE8.func_000181F0(&firstMesh);
                data_0022FCE8.func_00016320(&firstItem);
            } else {
                data_0022FCE8.func_00017F60(&secondMesh);
                data_0022FCE8.func_000162A0(&secondItem);
            }
        }
        break;
    }
}
