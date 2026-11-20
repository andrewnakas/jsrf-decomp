struct Vector3 {
    float x;
    float y;
    float z;
};

struct Box_00017CC0 {
    Vector3 min;
    Vector3 max;
};

// A vertex of a deformed mesh (0x18 bytes): position and normal.
struct Vertex_00017DF0 {
    Vector3 position;
    Vector3 normal;
};

void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);
void __fastcall func_001BAC00(Vector3 *out, const Vector3 *in);
void __fastcall func_0014C410(Vector3 *out, const Vector3 *in);

// A deformed mesh: its source vertices, two buffers it moves them into in turn, their bounds, an id and the next
// mesh in its bucket.
struct Mesh_0001B500 {
    Vertex_00017DF0 *source;
    Vertex_00017DF0 *buffers[2];
    int current;
    Box_00017CC0 bounds;
    int count;
    char unknown_2c[0xc];
    int id;
    char unknown_3c[0x58];
    Mesh_0001B500 *next;
};

// The collision world (data_0022FCE8): deformed meshes hashed by the low byte of their id at +0x890.
struct Object_00016200 {
    char unknown_000[0x890];
    Mesh_0001B500 *meshes[256];

    void func_00017DF0(Box_00017CC0 *box, const Vertex_00017DF0 *vertices, unsigned int count);
    void func_0001B500(int id);
};

// Moves the mesh with this id into its other buffer by the current matrix (positions by func_001BAB20, normals by
// func_001BAC00; the source normals are normalised in place by func_0014C410) and takes the new bounds.
void Object_00016200::func_0001B500(int id)
{
    int index = id & 0xff;
    for (Mesh_0001B500 *mesh = meshes[index]; mesh; mesh = mesh->next) {
        if (mesh->id == id) {
            Vertex_00017DF0 *from = mesh->source;
            mesh->current = (mesh->current - 1) & 1;
            Vertex_00017DF0 *to = mesh->buffers[mesh->current];
            for (int i = 0; i < mesh->count; i++) {
                func_001BAB20(&to[i].position, &from[i].position);
                func_001BAC00(&to[i].normal, &from[i].normal);
                func_0014C410(&from[i].normal, &from[i].normal);
            }
            func_00017DF0(&mesh->bounds, to, mesh->count);
            return;
        }
    }
}
