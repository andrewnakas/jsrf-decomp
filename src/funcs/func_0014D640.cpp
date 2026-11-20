// The empty helper base at +4 of the engine's objects (the device's statistics; here it has no fields).
struct Stats {
    unsigned int func_001563A0(unsigned long fvf);
};

// A Direct3D resource header (0xC bytes, laid out like Direct3D 8's: common word, data, lock).
struct Resource {
    unsigned long common;
    void *data;
    unsigned long lock;
};

// What 0x14D640 sets an object up from: vertices of format fvf at vertexData, 16-bit indices at indexData.
struct Buffers {
    void *vertexData;
    unsigned long fvf;
    unsigned int vertices;
    void *indexData;
    unsigned int indices;
};

void __stdcall func_001BBCE8(unsigned int length, unsigned long usage, unsigned long fvf, unsigned long pool,
                             Resource *buffer, unsigned long data);
void __stdcall func_001BBD00(unsigned int length, unsigned long usage, unsigned long format, unsigned long pool,
                             Resource *buffer, unsigned long data);
void __stdcall func_001929E0(Resource *resource, void *data);

// The Direct3D device wrapper: table 0x1E0F00 (121 slots), 0xE4 bytes.
struct Object_001E0F00 {
    long func_00154EE0(void *resource);
};

// The device in use.
extern Object_001E0F00 *data_002650D8;

// The base of the classes whose tables are at 0x1E10E8, 0x1E1150 (created by 0x14D800) and 0x1E11B8 (created by 0x14D8E0).
struct Object_001E10E8 : Stats {
    virtual long __stdcall func_0014D490(const void *iid, void **object);  // slot 0

    Resource *object;
    Resource *resource;
    unsigned long shader;
    unsigned long extra;
    unsigned int vertexCount;
    unsigned long value_18;
    unsigned long value_1C;
    unsigned long references;
};

// The class whose table is at 0x1E11B8 (0x24 bytes, created by 0x14D8E0).
struct Object_001E11B8 : Object_001E10E8 {
    long func_0014D640(unsigned long argument1);
};

// Sets the object up over buffers the caller already has (argument1 points at a Buffers): a vertex buffer header
// over vertexData (kept at +4 with the vertex size at +0x10 and the count at +0x14) and an index buffer header over
// indexData (format 0x65, kept at +8 with the count at +0x18 and the triangle count at +0x1C), then puts the
// object on the device's list. E_FAIL (both headers freed) when a header cannot be allocated, E_INVALIDARG unless
// one of the two has both data and a count.
long Object_001E11B8::func_0014D640(unsigned long argument1)
{
    const Buffers *buffers = (const Buffers *)argument1;
    if ((buffers->vertexData && buffers->vertices) || (buffers->indexData && buffers->indices)) {
        long result = 0;
        if (buffers->vertices) {
            shader = buffers->fvf;
            extra = func_001563A0(buffers->fvf);
            Resource *vertexBuffer = new Resource;
            if (vertexBuffer) {
                func_001BBCE8(0, 0, (unsigned long)-1, 0, vertexBuffer, 0);
                func_001929E0(vertexBuffer, buffers->vertexData);
                object = vertexBuffer;
                vertexCount = buffers->vertices;
            } else {
                result = 0x80004005;
            }
        }
        if (buffers->indices) {
            Resource *indexBuffer = new Resource;
            if (indexBuffer) {
                func_001BBD00(0, 0, (unsigned long)-1, 0, indexBuffer, 0);
                indexBuffer->data = buffers->indexData;
                indexBuffer->lock = 0;
                resource = indexBuffer;
                value_18 = buffers->indices;
                value_1C = buffers->indices / 3;
            } else {
                result = 0x80004005;
                goto failed;
            }
        }
        if (result >= 0) {
            data_002650D8->func_00154EE0(this);
            return 0;
        }
    failed:
        if (object) {
            delete object;
            object = 0;
        }
        if (resource) {
            delete resource;
            resource = 0;
        }
        return result;
    }
    return 0x80070057;
}
