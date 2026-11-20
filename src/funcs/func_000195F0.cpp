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

void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);
void __fastcall func_0014C4C0(Vector3 *out, const Vector3 *from, const Vector3 *to);

struct Object_00016200 {
    void func_00017FD0(Mesh_00017FD0 *mesh);
    void func_000195F0(Mesh_00017FD0 *mesh, const Mesh_00017FD0 *source);
};

// Transforms a mesh's centre and both ends of its parts from the source mesh (func_001BAB20), keeps how far each
// part's start moved, and recomputes the bounds.
void Object_00016200::func_000195F0(Mesh_00017FD0 *mesh, const Mesh_00017FD0 *source)
{
    func_001BAB20(&mesh->bounds.center, &source->bounds.center);
    Part_00017FD0 *part = mesh->parts;
    Part_00017FD0 *from = source->parts;
    for (unsigned int i = 0; i < mesh->count; i++, part++, from++) {
        Vector3 old = part->start;
        func_001BAB20(&part->start, &from->start);
        func_001BAB20(&part->end, &from->end);
        func_0014C4C0(&part->motion, &part->start, &old);
    }
    func_00017FD0(mesh);
}
