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

struct Part_000181F0 {
    Box_00017CC0 box;
    char unknown_18[0x5c];
};

struct Mesh_000181F0 {
    Part_000181F0 *parts;
    unsigned int count;
    Sphere_00017EC0 bounds;
};

struct Object_00016200 {
    void func_00017EC0(Sphere_00017EC0 *sphere, const Sphere_00017EC0 *other);
    void func_000180C0(Sphere_00017EC0 *sphere, const Box_00017CC0 *box);
    void func_000181F0(Mesh_000181F0 *mesh);
};

// The sphere around the spheres of all the parts' boxes of a mesh, kept in the mesh.
void Object_00016200::func_000181F0(Mesh_000181F0 *mesh)
{
    if (mesh && mesh->parts) {
        Sphere_00017EC0 sphere;
        func_000180C0(&mesh->bounds, &mesh->parts[0].box);
        for (unsigned int i = 1; i < mesh->count; i++) {
            func_000180C0(&sphere, &mesh->parts[i].box);
            func_00017EC0(&mesh->bounds, &sphere);
        }
    }
}
