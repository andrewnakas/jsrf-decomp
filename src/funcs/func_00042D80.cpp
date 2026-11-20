/* const: 0x10000 */
/* const: 0x40000 */
extern "C" void *memcpy(void *, const void *, unsigned int);

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
};

struct Buffer_00042CC0;

// The object at 0x1F90C0: an interface from 0x251D74 (+0x4) with a handle (+0x8), and two blocks of memory.
struct Object_00042CC0 {
    int unknown_00;
    Buffer_00042CC0 *buffer;
    long handle;
    char *data;
    unsigned int vertexCount;
    int format;
    int unknown_18;
    unsigned short *scratch;
    unsigned int indexCount;

    long func_00042D80(Batch_00042EA0 *batch, Mesh_00042D80 *mesh);
};

// Appends a mesh to the buffers (at most 0x10000 vertices, 0x40000 indices): copies its vertices, copies its indices
// moved past the vertices already there, and tells the batch its triangle count and first index. 0x80004005 when
// it does not fit.
long Object_00042CC0::func_00042D80(Batch_00042EA0 *batch, Mesh_00042D80 *mesh)
{
    unsigned int vertexEnd = vertexCount + mesh->vertexCount;
    unsigned int indexEnd = mesh->indexCount + indexCount;
    if (vertexEnd >= 0x10000) {
        return 0x80004005;
    }
    if (indexEnd >= 0x40000) {
        return 0x80004005;
    }
    memcpy(data + vertexCount * 32, mesh->vertices, mesh->vertexCount * 32);
    unsigned short *to = scratch + indexCount;
    unsigned short *from = mesh->indices;
    for (unsigned int i = 0; i < mesh->indexCount; i++) {
        *to++ = *from++ + (unsigned short)vertexCount;
    }
    batch->count = mesh->indexCount / 3;
    batch->first = indexCount;
    indexCount = indexEnd;
    vertexCount = vertexEnd;
    return 0;
}
