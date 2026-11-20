struct Vector3 {
    float x;
    float y;
    float z;
};

void __fastcall func_0014C410(Vector3 *out, const Vector3 *in);

// A vertex of 0x20 bytes: its position and normal.
struct Vertex_00028A80 {
    Vector3 position;
    Vector3 normal;
    char unknown_18[8];
};

// What +0x4 of the mesh points at: slot 6 locks its vertices, slot 7 unlocks them.
struct Buffer_00028A80 {
    virtual void __stdcall slot0();
    virtual void __stdcall slot1();
    virtual void __stdcall slot2();
    virtual void __stdcall slot3();
    virtual void __stdcall slot4();
    virtual void __stdcall slot5();
    virtual int __stdcall slot6(int handle, Vertex_00028A80 **vertices, unsigned int *count, int flags);
    virtual int __stdcall slot7(int handle);
};

struct Mesh_00028A80 {
    int unknown_00;
    Buffer_00028A80 *buffer;
    int *handle;
};

struct Model_00028A80 {
    char unknown_00[0x14];
    Mesh_00028A80 *mesh;
};

// Object 7.
struct Object_000265A0 {
    char unknown_000[0x4b8];
    Model_00028A80 *model;

    void func_00028A80();
};

// Called by handler 39 of the table at 0x1EC068 (0x28500) for index 12: gives every vertex of the model at +0x4b8 the
// normal pointing out from the vertical axis (its position with y 0, normalised by func_0014C410), copied back as
// raw words.
void Object_000265A0::func_00028A80()
{
    Mesh_00028A80 *mesh = model->mesh;
    Vertex_00028A80 *vertex;
    unsigned int count;
    mesh->buffer->slot6(*mesh->handle, &vertex, &count, 0);
    for (unsigned int i = 0; i < count; i++, vertex++) {
        Vector3 normal;
        normal.x = vertex->position.x;
        normal.y = 0.0f;
        normal.z = vertex->position.z;
        func_0014C410(&normal, &normal);
        *(int *)&vertex->normal.x = *(int *)&normal.x;
        *(int *)&vertex->normal.y = *(int *)&normal.y;
        *(int *)&vertex->normal.z = *(int *)&normal.z;
    }
    mesh->buffer->slot7(*mesh->handle);
}
