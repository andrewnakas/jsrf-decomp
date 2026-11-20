struct Vector3 {
    float x;
    float y;
    float z;
};

struct Sphere_00017EC0 {
    Vector3 center;
    float radius;
};

// A capsule: its two ends and radius (0x30 bytes).
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

// The collision world (data_0022FCE8).
struct Object_00016200 {
    void func_00017EC0(Sphere_00017EC0 *sphere, const Sphere_00017EC0 *other);
    void func_00017FD0(Mesh_00017FD0 *mesh);
};

// Makes the mesh's bounds the smallest sphere around both ends of every capsule (func_00017EC0 grows it by one
// sphere), starting from the first capsule's start.
void Object_00016200::func_00017FD0(Mesh_00017FD0 *mesh)
{
    if (mesh && mesh->parts) {
        mesh->bounds.center = mesh->parts[0].start;
        mesh->bounds.radius = mesh->parts[0].radius;
        Sphere_00017EC0 sphere;
        sphere.center = mesh->parts[0].end;
        sphere.radius = mesh->parts[0].radius;
        func_00017EC0(&mesh->bounds, &sphere);
        for (unsigned int i = 0; i < mesh->count; i++) {
            sphere.radius = mesh->parts[i].radius;
            sphere.center = mesh->parts[i].start;
            func_00017EC0(&mesh->bounds, &sphere);
            sphere.center = mesh->parts[i].end;
            func_00017EC0(&mesh->bounds, &sphere);
        }
    }
}
