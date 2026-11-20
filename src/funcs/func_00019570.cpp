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

void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);
void __fastcall func_0014C4C0(Vector3 *out, const Vector3 *from, const Vector3 *to);

struct Object_00016200 {
    void func_00017F60(Mesh_00017F60 *mesh);
    void func_00019570(Mesh_00017F60 *mesh, const Mesh_00017F60 *source);
};

// Transforms a mesh's centre and its parts' centres from the source mesh (func_001BAB20), keeps how far each part
// moved, and recomputes the bounding sphere.
void Object_00016200::func_00019570(Mesh_00017F60 *mesh, const Mesh_00017F60 *source)
{
    func_001BAB20(&mesh->bounds.center, &source->bounds.center);
    Part_00017F60 *part = mesh->parts;
    Part_00017F60 *from = source->parts;
    for (unsigned int i = 0; i < mesh->count; i++, part++, from++) {
        Vector3 old = part->sphere.center;
        func_001BAB20(&part->sphere.center, &from->sphere.center);
        func_0014C4C0(&part->motion, &part->sphere.center, &old);
    }
    func_00017F60(mesh);
}
