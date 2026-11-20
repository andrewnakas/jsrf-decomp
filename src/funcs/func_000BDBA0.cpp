/* sym: ?func_00011C90@Object_000BDAE0@@UAEXXZ = 0x000BDBA0 */
struct Node {
    virtual ~Node();
    virtual void func_00011C90();

    char unknown_04[0x3c];
};

struct Vector3 {
    float x;
    float y;
    float z;
};

struct Angles_000BDBA0 {
    int x;
    int y;
    int z;
};

struct Transform_000BDBA0 {
    Vector3 position;
    Angles_000BDBA0 angles;
    Vector3 scale;
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

struct Object_000607B0 {
    int func_000651E0(int kind, void *data, Vector3 *direction);
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

struct Item_00016200;

struct Object_00016200 {
    void func_00016240(Item_00016200 *item);
    void func_000162A0(Item_000162A0 *item);
    void func_00017F60(Mesh_00017F60 *mesh);
    void func_0001D940(void **item);
};

extern Object_00016200 data_0022FCE8;

struct Object_0006A960 {
    int func_0006AAA0(Vector3 *position, int key);
    float func_0006AC40(Vector3 *position, int key);
};

extern Object_0006A960 data_0020C6C0;

void func_001BA9C0();
void func_001BA8A0();
void __fastcall func_001BAAA0(float *vector);
void __fastcall func_001BAC50(int *angles, int order);
void __fastcall func_001BB270(float *scale);
void __fastcall func_001BAA50();

// One of 17 direct children of Node that share slots 4, 5, 6, 12 and 15 (table 0x1CDAE0).
struct Object_000BDAE0 : Node {
    virtual void func_00011C90();

    char unknown_040[8];
    Transform_000BDBA0 transform;
    char unknown_06c[4];
    unsigned int flags;
    char unknown_074[8];
    int handle;
    char unknown_080[0xc];
    int kind;
    int key;
    float value_94;
    int seen;
    int posed;
    char unknown_0a0[0x10];
    int second;
    Transform_000BDBA0 placed;
    Vector3 center;
    Vector3 last;
    Vector3 motion;
    int value_fc;
    char unknown_100[0x40];
    unsigned int state;
    float time;
    int value_148;
    int phase;
    char unknown_150[4];
    Item_000162A0 item;
    char unknown_16c[0xc];
    Mesh_00017F60 mesh;
    char unknown_190[4];
    void **model;
    char shadow[4];
};

// Slot 1 (the frame). Phase 0 places the object: copies the position, angles and scale to 0xb4, the position to 0xd8
// and 0xe4, clears the motion, the model state and time, registers the kind at 0x8c with object 0xe8 (key at 0xb0),
// goes to phase 10 when flag 0x20000000 is set or else to phase 1 with its collision part at the position (item 0x154,
// mesh 0x178; the model at 0x194 posed twice when the handle at 0x7c is set) and its key at 0x90 and value at 0x94
// from data_0020C6C0, and goes on like phase 1. Phase 1 adds the collision item (and the shadow at 0x198 with a
// handle) once seen and posed; phase 3 always does.
void Object_000BDAE0::func_00011C90()
{
    switch (phase) {
    case 0:
        placed.position.x = transform.position.x;
        placed.position.y = transform.position.y;
        placed.position.z = transform.position.z;
        placed.angles.x = transform.angles.x;
        placed.angles.y = transform.angles.y;
        placed.angles.z = transform.angles.z;
        placed.scale.x = transform.scale.x;
        placed.scale.y = transform.scale.y;
        placed.scale.z = transform.scale.z;
        center.x = transform.position.x;
        center.y = transform.position.y;
        center.z = transform.position.z;
        phase = 1;
        last.x = transform.position.x;
        last.y = transform.position.y;
        last.z = transform.position.z;
        motion.x = 0.0f;
        motion.y = 0.0f;
        motion.z = 0.0f;
        value_148 = 0;
        state = 0;
        time = 0.0f;
        value_fc = 0xff;
        if (kind != -1) {
            Object_000607B0 *target = (Object_000607B0 *)data_0022FCE0->func_000128C0(0xe8);
            if (target) {
                second = target->func_000651E0(kind, &placed.position, 0);
            }
        }
        if (flags & 0x20000000) {
            phase = 10;
            return;
        }
        mesh.parts->sphere.center.x = center.x;
        mesh.parts->sphere.center.y = center.y;
        mesh.parts->sphere.center.z = center.z;
        mesh.parts->motion = motion;
        item.mesh = &mesh;
        item.count = 3;
        item.flags = 0x800;
        if (handle != -1) {
            func_001BA9C0();
            func_001BA8A0();
            func_001BAAA0(&transform.position.x);
            func_001BAC50(&transform.angles.x, 0);
            func_001BB270(&transform.scale.x);
            data_0022FCE8.func_0001D940(model);
            data_0022FCE8.func_0001D940(model);
            func_001BAA50();
        }
        key = data_0020C6C0.func_0006AAA0(&placed.position, key);
        value_94 = data_0020C6C0.func_0006AC40(&placed.position, key);
    case 1:
        if (seen && posed) {
            data_0022FCE8.func_00017F60(&mesh);
            data_0022FCE8.func_000162A0(&item);
            if (handle != -1) {
                data_0022FCE8.func_00016240((Item_00016200 *)shadow);
            }
        }
        break;
    case 3:
        data_0022FCE8.func_00017F60(&mesh);
        data_0022FCE8.func_000162A0(&item);
        if (handle != -1) {
            data_0022FCE8.func_00016240((Item_00016200 *)shadow);
        }
        break;
    }
}
