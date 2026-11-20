/* const: 0x200000 */
struct Vector3 {
    float x;
    float y;
    float z;
};

struct Box_00017CC0 {
    Vector3 min;
    Vector3 max;
};

// The part of the collision item func_0001B5C0 tests: two counts, at +0x4 and +0x14.
struct Shape_000EC910 {
    int unknown_00;
    unsigned int first;
    char unknown_08[0xc];
    unsigned int second;
    char unknown_18[0xc];
};

// The collision item of data_0022FCE8 (func_00016260): a mask, a box (func_00017D90) and a shape.
struct Item_00016260 {
    int mask;
    int value;
    Box_00017CC0 box;
    Shape_000EC910 shape;
};

// A centre and a radius.
struct Sphere_000EC910 {
    Vector3 center;
    float radius;
};

// The sphere mesh of an item (func_00019570 copies one): its parts carry a level at 0x1c.
struct Part_00017F60 {
    char unknown_00[0x1c];
    int level;
    char unknown_20[4];
};

struct Mesh_00017F60 {
    Part_00017F60 *parts;
};

// What func_000162A0 takes: flags, kind, the mesh and what touches it.
struct Item_000162A0 {
    unsigned int flags;
    int kind;
    Mesh_00017F60 *mesh;
    void *touches;
};

struct Object_00016200 {
    void func_00016260(Item_00016260 *item, int value);
    void func_000162A0(Item_000162A0 *item);
    void func_00017CC0(Box_00017CC0 *box, const Vector3 *points, unsigned int count);
    void func_00017D90(Box_00017CC0 *box, const Vector3 *points, unsigned int count, float radius);
    void func_00019570(Mesh_00017F60 *mesh, const Mesh_00017F60 *source);
};

extern Object_00016200 data_0022FCE8;

struct Object_00047470 {
    void func_000480C0(unsigned int flags);
};

void func_001BA9C0();
void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);
void __fastcall func_001BAA50();

struct Object_000C7910 {
    char unknown_00[8];
    int id;
    char unknown_0c[0x3c];
    Vector3 last;
    char unknown_54[0xc];
    float speed;
    float lift;
    char unknown_68[0x28];
    unsigned int flags;
    char unknown_94[0x28];
    int mode;
    char unknown_c0[0x10];
    Vector3 position;
    char unknown_dc[0x2c];
    Vector3 points[3];
    char unknown_12c[0x58];
    Object_00047470 *model;
    char unknown_188[0x4c];
    Mesh_00017F60 *source;
    Sphere_000EC910 sphere;
    Sphere_000EC910 sphere2;
    Item_00016260 path;
    Item_00016260 item;
    Item_00016260 item2;
    Item_00016260 marks[3];
    Item_000162A0 body;

    void func_000C9420();
};

// Registers the collision items with data_0022FCE8 for this step. Flag 0x100 frees the body's touches; flags 0x100
// or 0x4000000 (or, without bit 7, no speed and no lift) clear the item counts. The body (0x390) takes the source
// mesh: kind 4 and level 2 with flag 0x200000, else 2 and 1 (left alone, its touches freed, while flags 0x2200000
// stand without 0x1000000 or mode 5 and there is no speed). With flag 0x2000000 the three points at 0x108 get boxes
// up to 3 above them and the sphere is placed at the model's part 11, all under the object's id; otherwise the path
// box from 3 above the last position to 1 below the new one, the sphere at part 8 and the second sphere's sweep.
void Object_000C7910::func_000C9420()
{
    if (flags & 0x100) {
        body.touches = 0;
    }
    if (flags & 0x4000100) {
        path.shape.second = 0;
        path.shape.first = 0;
        item.shape.second = 0;
        item.shape.first = 0;
        item2.shape.second = 0;
        item2.shape.first = 0;
        return;
    }
    if ((flags & 0x2200000) && !(flags & 0x1000000) && mode != 5) {
        if (speed != 0.0f) {
            data_0022FCE8.func_00019570(body.mesh, source);
            if (flags & 0x200000) {
                body.flags = 4;
                body.mesh->parts[0].level = 2;
                body.mesh->parts[1].level = 2;
            } else {
                body.flags = 2;
                body.mesh->parts[0].level = 1;
                body.mesh->parts[1].level = 1;
            }
            data_0022FCE8.func_000162A0(&body);
        } else {
            body.touches = 0;
        }
    } else {
        data_0022FCE8.func_00019570(body.mesh, source);
        body.flags = 2;
        body.mesh->parts[0].level = 1;
        body.mesh->parts[1].level = 1;
        data_0022FCE8.func_000162A0(&body);
    }
    Vector3 ends[2];
    if (flags & 0x2000000) {
        ends[1] = points[0];
        ends[0] = points[0];
        ends[0].y += 3.0f;
        data_0022FCE8.func_00017CC0(&marks[0].box, ends, 2);
        data_0022FCE8.func_00016260(&marks[0], id);
        ends[1] = points[1];
        ends[0] = points[1];
        ends[0].y += 3.0f;
        data_0022FCE8.func_00017CC0(&marks[1].box, ends, 2);
        data_0022FCE8.func_00016260(&marks[1], id);
        ends[1] = points[2];
        ends[0] = points[2];
        ends[0].y += 3.0f;
        data_0022FCE8.func_00017CC0(&marks[2].box, ends, 2);
        data_0022FCE8.func_00016260(&marks[2], id);
        func_001BA9C0();
        model->func_000480C0(0xb);
        func_001BAB20(&sphere.center, 0);
        func_001BAA50();
        data_0022FCE8.func_00017D90(&item.box, &sphere.center, 1, sphere.radius);
        data_0022FCE8.func_00016260(&item, id);
    } else if ((flags & 0x80) || speed != 0.0f || lift != 0.0f) {
        ends[0] = last;
        ends[0].y += 3.0f;
        ends[1] = position;
        ends[1].y -= 1.0f;
        data_0022FCE8.func_00017CC0(&path.box, ends, 2);
        data_0022FCE8.func_00016260(&path, -1);
        func_001BA9C0();
        model->func_000480C0(8);
        func_001BAB20(&sphere.center, 0);
        func_001BAA50();
        data_0022FCE8.func_00017D90(&item.box, &sphere.center, 1, sphere.radius);
        data_0022FCE8.func_00016260(&item, -1);
        ends[0] = last;
        ends[0].y += sphere2.radius;
        ends[1] = position;
        ends[1].y += sphere2.radius;
        data_0022FCE8.func_00017D90(&item2.box, ends, 2, sphere2.radius);
        data_0022FCE8.func_00016260(&item2, -1);
    } else {
        path.shape.second = 0;
        path.shape.first = 0;
        item.shape.second = 0;
        item.shape.first = 0;
        item2.shape.second = 0;
        item2.shape.first = 0;
    }
}
