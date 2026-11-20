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
    char unknown_10[0x14];
};

struct Mesh_00017F60 {
    Part_00017F60 *parts;
    unsigned int count;
    Sphere_00017EC0 bounds;
};

struct Object_00016200 {
    void func_00017EC0(Sphere_00017EC0 *sphere, const Sphere_00017EC0 *other);
    void func_00017F60(Mesh_00017F60 *mesh);
};

// The sphere around all the parts' spheres of a mesh, kept in the mesh.
void Object_00016200::func_00017F60(Mesh_00017F60 *mesh)
{
    if (mesh && mesh->parts) {
        mesh->bounds = mesh->parts[0].sphere;
        for (unsigned int i = 1; i < mesh->count; i++) {
            func_00017EC0(&mesh->bounds, &mesh->parts[i].sphere);
        }
    }
}
