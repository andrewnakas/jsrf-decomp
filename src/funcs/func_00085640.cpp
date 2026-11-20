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
    int unknown_1c;
    int kind;
};

struct Mesh_00017F60 {
    Part_00017F60 *parts;
    unsigned int count;
    Sphere_00017EC0 bounds;
};

struct Item_000162A0 {
    int unknown_00[2];
    Mesh_00017F60 *mesh;
    char unknown_0c[8];
    int unknown_14;
};

struct Object_00016200 {
    void func_000162A0(Item_000162A0 *item);
    void func_00019570(Mesh_00017F60 *mesh, const Mesh_00017F60 *source);
};

extern Object_00016200 data_0022FCE8;
extern Mesh_00017F60 data_0020D948;

struct Object_00086060 {
    char unknown_000[0x90];
    unsigned int time;
    unsigned int delay;
    int unknown_098;
    unsigned int flags;
    char unknown_0a0[0xac];
    Item_000162A0 item;

    void func_00085640();
};

// Counts up to the delay (clearing +0x160); after it, marks its first part by its flags (bit 2: 1, bit 0: 0, else 2),
// moves its mesh to the one at 0x20D948 and queues it on the fifth list of 0x22FCE8.
void Object_00086060::func_00085640()
{
    if (time > delay) {
        if (flags & 4) {
            item.mesh->parts->kind = 1;
        } else if (flags & 1) {
            item.mesh->parts->kind = 0;
        } else {
            item.mesh->parts->kind = 2;
        }
        data_0022FCE8.func_00019570(item.mesh, &data_0020D948);
        data_0022FCE8.func_000162A0(&item);
    } else {
        time++;
        item.unknown_14 = 0;
    }
}
