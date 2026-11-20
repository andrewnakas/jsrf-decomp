struct Node {
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
    Node *drawNext;
    Node **drawLink;
    Node ***drawTail;
};

struct Vector3 {
    float x;
    float y;
    float z;
};

// Where func_000BAC60 places the object: position, angles, scale and a model code (bank << 10 | index).
struct Params_000BAC60 {
    Vector3 position;
    int angles[3];
    Vector3 scale;
    unsigned int model;
};

// An entry of table 5 (0xf0 bytes, copied to 0x228): ids in tables 2, 3 and 7 (-1 = none) and the 16 children.
struct Entry_000B8230 {
    unsigned int flags;
    int model;
    int shadow;
    int first;
    int second;
    int extra;
    char unknown_18[0x88];
    int children[16];
    Vector3 position;
    char unknown_ec[4];
};

struct Sphere_00017EC0 {
    Vector3 center;
    float radius;
};

// The one part of the sphere mesh at 0x1a8 (0x24 bytes).
struct Part_00017F60 {
    Sphere_00017EC0 sphere;
    Vector3 offset;
    char unknown_1c[8];
};

// The one part of the box mesh at 0x1e8 (0x74 bytes): the eight corners, then an offset.
struct Part_000181F0 {
    Vector3 corners[8];
    Vector3 offset;
    char unknown_6c[8];
};

struct Mesh_00017F60 {
    Part_00017F60 *parts;
    unsigned int count;
    Sphere_00017EC0 bounds;
};

struct Mesh_000181F0 {
    Part_000181F0 *parts;
    unsigned int count;
    Sphere_00017EC0 bounds;
};

// What func_000162A0 and func_00016320 take (0x24 bytes): flags, kind and the mesh it stands for.
struct Item_000162A0 {
    unsigned int flags;
    int kind;
    void *mesh;
    char unknown_0c[0x18];
};

struct Object_00016200 {
    void func_00017F60(Mesh_00017F60 *mesh);
    void func_000162A0(Item_000162A0 *item);
    void func_000181F0(Mesh_000181F0 *mesh);
    void func_00016320(Item_000162A0 *item);
};

extern Object_00016200 data_0022FCE8;

struct Object_0006A960 {
    int func_0006AAA0(Vector3 *position, int hint);
    float func_0006AC40(Vector3 *position, int hint);
};

extern Object_0006A960 data_0020C6C0;

void func_001BA9C0();
void __fastcall func_001BAA50();
void __fastcall func_001BAAA0(float *matrix);
void __fastcall func_001BAC50(int *angles, int order);
void __fastcall func_001BB270(float *scale);
void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);

// The child of Node whose table is at 0x1CD998 (destructor func_000B8610).
struct Object_000B9960 : Node {
    char unknown_040[4];
    int value_44;
    int state;
    int value_4c;
    int value_50;
    int value_54;
    int value_58;
    float value_5c;
    char unknown_060[8];
    void *model;
    void *shadow;
    void *current;
    char unknown_074[0x6c];
    int alpha;
    char unknown_0e4[0x40];
    int value_124;
    int value_128;
    char unknown_12c[4];
    int value_130;
    char unknown_134[0x50];
    Item_000162A0 item;
    Mesh_00017F60 mesh;
    Vector3 *points;
    Item_000162A0 item2;
    Mesh_000181F0 mesh2;
    Params_000BAC60 record;
    Entry_000B8230 entry;
    unsigned int flags_318;
    Vector3 direction;
    int value_328;
    int spin[3];
    int angles[3];
    Vector3 scale;
    Vector3 value_350;
    Vector3 value_35c;
    Vector3 value_368;

    void func_000B9270();
};

// Slot 1's routine for objects without the top bit of 0x228. State 0 starts it: both saved positions take the
// position, the offset and spin are cleared, the sphere part is placed at the position (item 0x800, kind 3) and,
// with an entry in table 7, its eight points are transformed into the box part (position, angles, spin, scale);
// the floor zone and height under the position go to 0x58 and 0x5c; state 1. In state 1, with 0x4c and 0x54 set,
// it hands the sphere or box mesh and item to data_0022FCE8.
void Object_000B9960::func_000B9270()
{
    switch (state) {
    case 0:
        value_350.x = direction.x;
        value_350.y = direction.y;
        value_350.z = direction.z;
        value_35c.x = direction.x;
        value_35c.y = direction.y;
        value_35c.z = direction.z;
        value_368.x = 0;
        value_368.y = 0;
        value_368.z = 0;
        current = model;
        spin[0] = 0;
        spin[1] = 0;
        spin[2] = 0;
        value_44 = 0;
        value_124 = 0;
        value_128 = 0;
        state = 1;
        alpha = 0xff;
        value_130 = 0xf;
        mesh.parts->sphere.center.x = value_350.x;
        mesh.parts->sphere.center.y = value_350.y;
        mesh.parts->sphere.center.z = value_350.z;
        mesh.parts->offset = value_368;
        item.mesh = &mesh;
        item.kind = 3;
        item.flags = 0x800;
        if (entry.extra != -1) {
            func_001BA9C0();
            func_001BAAA0(&direction.x);
            func_001BAC50(angles, 0);
            func_001BAC50(spin, 0);
            func_001BB270(&scale.x);
            for (int i = 0; i < 8; i++) {
                func_001BAB20(&mesh2.parts->corners[i], &points[i]);
            }
            func_001BAA50();
            mesh2.parts->offset = value_368;
            item2.kind = 1;
            item2.flags = 8;
            item2.mesh = &mesh2;
        }
        value_58 = data_0020C6C0.func_0006AAA0(&direction, value_58);
        value_5c = data_0020C6C0.func_0006AC40(&direction, value_58);
    case 1:
        if (value_4c && value_54) {
            if (entry.extra == -1) {
                data_0022FCE8.func_00017F60(&mesh);
                data_0022FCE8.func_000162A0(&item);
            } else {
                data_0022FCE8.func_000181F0(&mesh2);
                data_0022FCE8.func_00016320(&item2);
            }
        }
        break;
    }
}
