// A block of vertices (32 bytes each) and of 16-bit indices.
struct Mesh_00042D80 {
    void *vertices;
    unsigned int vertexCount;
    int unknown_08;
    int unknown_0c;
    unsigned short *indices;
    unsigned int indexCount;
};

// Where a mesh landed in the shared buffers: its triangle count and its first index.
struct Batch_00042EA0 {
    unsigned int count;
    int first;

    void func_00042EA0(int unknown1, int unknown2, Mesh_00042D80 **mesh);
};

struct Object_00042CC0 {
    long func_00042D80(Batch_00042EA0 *batch, Mesh_00042D80 *mesh);
};

extern Object_00042CC0 data_001F90C0;

// Appends a mesh, when there is one, to the buffers of the object at 0x1F90C0 (func_00042D80).
void Batch_00042EA0::func_00042EA0(int unknown1, int unknown2, Mesh_00042D80 **mesh)
{
    if (mesh) {
        data_001F90C0.func_00042D80(this, *mesh);
    }
}
