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
extern Mesh_00017F60 data_0020DA3C;

struct Object_00086960 {
    char unknown_000[0x94];
    unsigned int time;
    int unknown_98;
    unsigned int delay;
    char unknown_0a0[0x70];
    Item_000162A0 item;

    void func_00086850();
};

// Counts up to the delay at +0x9c (clearing +0x124); after it, moves its mesh to the one at 0x20DA3C and queues it
// on the fifth list of 0x22FCE8.
void Object_00086960::func_00086850()
{
    if (time > delay) {
        data_0022FCE8.func_00019570(item.mesh, &data_0020DA3C);
        data_0022FCE8.func_000162A0(&item);
    } else {
        time++;
        item.unknown_14 = 0;
    }
}
