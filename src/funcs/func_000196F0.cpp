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

struct Part_00017FD0 {
    Vector3 start;
    Vector3 end;
    float radius;
    Vector3 motion;
    char unknown_28[8];
};

struct Mesh_00017FD0 {
    Part_00017FD0 *parts;
    unsigned int count;
    Sphere_00017EC0 bounds;
};

struct Object_00016200 {
    Mesh_00017FD0 *func_000196F0(const Mesh_00017FD0 *mesh);
};

// A copy of a mesh of capsules with its parts, in one block (the parts follow the mesh).
Mesh_00017FD0 *Object_00016200::func_000196F0(const Mesh_00017FD0 *mesh)
{
    Mesh_00017FD0 *copy = (Mesh_00017FD0 *)operator new(mesh->count * sizeof(Part_00017FD0) + sizeof(Mesh_00017FD0));
    Part_00017FD0 *to = (Part_00017FD0 *)(copy + 1);
    *copy = *mesh;
    copy->parts = to;
    Part_00017FD0 *from = mesh->parts;
    for (unsigned int i = 0; i < mesh->count; i++, to++, from++) {
        *to = *from;
    }
    return copy;
}
