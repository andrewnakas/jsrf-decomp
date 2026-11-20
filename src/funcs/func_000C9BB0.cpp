struct Vector3 {
    float x;
    float y;
    float z;
};

// A centre and a radius.
struct Sphere_000EC910 {
    Vector3 center;
    float radius;
};

struct Box_00017CC0 {
    Vector3 min;
    Vector3 max;
};

// The collision item of data_0022FCE8 (func_00016260): a mask, a box (func_00017D90) and its links.
struct Item_00016260 {
    int mask;
    int value;
    Box_00017CC0 box;
    int unknown_20[8];
    Item_00016260 *next;
};

struct Part_00017F60 {
    char unknown_00[0x1c];
    int unknown_1c;
    char unknown_20[0x20];
    int unknown_40;
};

struct Mesh_00017F60 {
    Part_00017F60 *parts;
};

// A collision body (0x24 bytes): its kinds and its mesh.
struct Item_000162A0 {
    int kind;
    int mask;
    Mesh_00017F60 *mesh;
    char unknown_0c[0x18];
};

// The collision world (data_0022FCE8).
struct Object_00016200 {
    void func_00016260(Item_00016260 *item, int value);
    void func_000162A0(Item_000162A0 *item);
    void func_00017D90(Box_00017CC0 *box, const Vector3 *points, unsigned int count, float radius);
    void func_00019570(Mesh_00017F60 *mesh, const Mesh_00017F60 *source);
};

extern Object_00016200 data_0022FCE8;

struct Object_00047470 {
    void func_000480C0(unsigned int index);
};

void func_001BA9C0();
void __fastcall func_001BAA50();
void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);

// The child of Node whose table is at 0x1CE1C8 (destructor func_000C7240).
struct Object_000C7910 {
    char unknown_00[0x184];
    Object_00047470 *model;
    char unknown_188[0x4c];
    Mesh_00017F60 *source;
    Sphere_000EC910 previous;
    Sphere_000EC910 current;
    char unknown_1f8[0x44];
    Item_00016260 sweep;
    char unknown_280[0x110];
    Item_000162A0 body;

    void func_000C9BB0();
};

// Keeps the sphere at 0x1e8 as the previous one (0x1d8) and puts it at the model's node 7 (func_000480C0,
// func_001BAB20 between func_001BA9C0 and func_001BAA50). The item at 0x23c gets the box swept by the previous
// radius from the previous centre to the new one (func_00017D90) and is queued (func_00016260, -1); the body at 0x390
// takes a copy of the mesh at 0x1d4 (func_00019570), kind 2 and its first part's words 0x1c and 0x40 set, and is
// added (func_000162A0).
void Object_000C7910::func_000C9BB0()
{
    previous = current;
    func_001BA9C0();
    model->func_000480C0(7);
    func_001BAB20(&current.center, 0);
    func_001BAA50();
    Vector3 points[2];
    points[0].x = previous.center.x;
    points[0].y = previous.center.y;
    points[0].z = previous.center.z;
    points[1].x = current.center.x;
    points[1].y = current.center.y;
    points[1].z = current.center.z;
    data_0022FCE8.func_00017D90(&sweep.box, points, 2, previous.radius);
    data_0022FCE8.func_00016260(&sweep, -1);
    data_0022FCE8.func_00019570(body.mesh, source);
    body.kind = 2;
    body.mesh->parts->unknown_1c = 1;
    body.mesh->parts->unknown_40 = 1;
    data_0022FCE8.func_000162A0(&body);
}
