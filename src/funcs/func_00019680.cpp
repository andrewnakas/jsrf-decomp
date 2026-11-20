struct Vector3 {
    float x;
    float y;
    float z;
};

struct Box_00017CC0 {
    Vector3 min;
    Vector3 max;
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

struct Object_00016200 {
    Mesh_00017F60 *func_00019680(const Mesh_00017F60 *mesh);
};

// A copy of a mesh with its parts, in one block (the parts follow the mesh).
Mesh_00017F60 *Object_00016200::func_00019680(const Mesh_00017F60 *mesh)
{
    unsigned int size = mesh->count * sizeof(Part_00017F60) + sizeof(Mesh_00017F60);
    Mesh_00017F60 *copy = (Mesh_00017F60 *)operator new(size);
    Part_00017F60 *to = (Part_00017F60 *)(copy + 1);
    *copy = *mesh;
    copy->parts = to;
    Part_00017F60 *from = mesh->parts;
    for (unsigned int i = 0; i < mesh->count; i++, to++, from++) {
        *to = *from;
    }
    return copy;
}
