struct Vector3 {
    float x;
    float y;
    float z;
};

struct Box_00017CC0 {
    Vector3 min;
    Vector3 max;
};

extern "C" void *memcpy(void *destination, const void *source, unsigned int size);

// A vertex of a deformed mesh (0x18 bytes): position and normal.
struct Vertex_00017DF0 {
    Vector3 position;
    Vector3 normal;
};

// What func_0001D810 is given: the vertices, how many, and a value.
struct Source_0001D810 {
    Vertex_00017DF0 *vertices;
    int count;
    int value;
};

// A deformed mesh (0xa0 bytes, its vertices and two buffers after it): kept in a bucket of the hash at +0x890 by
// its key and in the list at +0x1090.
struct Mesh_0001B500 {
    Vertex_00017DF0 *source;
    Vertex_00017DF0 *buffers[2];
    int current;
    Box_00017CC0 bounds;
    int count;
    int value;
    int id;
    int enabled;
    int key;
    char unknown_3c[0x50];
    int unknown_8c;
    Mesh_0001B500 **link;
    Mesh_0001B500 *next;
    Mesh_0001B500 **link2;
    Mesh_0001B500 *next2;
};

// The collision world (data_0022FCE8).
struct Object_00016200 {
    char unknown_0000[0x88c];
    int serial;
    Mesh_0001B500 *meshes[256];
    Mesh_0001B500 **tails[256];
    char unknown_1090[4];
    Mesh_0001B500 **tail2;

    void func_0001B500(int id);
    int func_0001D810(void *data, int id);
};

// Registers a deformed mesh: copies the vertices `data` describes after a new header with room for two moved copies,
// gives it the next key (+0x88c), files it in the hash and the list, moves it twice (func_0001B500) and returns the
// key.
int Object_00016200::func_0001D810(void *data, int id)
{
    Source_0001D810 *source = (Source_0001D810 *)data;
    unsigned int size = source->count * 0x48 + sizeof(Mesh_0001B500);
    Mesh_0001B500 *mesh = (Mesh_0001B500 *)operator new(size);
    mesh->source = (Vertex_00017DF0 *)(mesh + 1);
    memcpy(mesh->source, source->vertices, source->count * sizeof(Vertex_00017DF0));
    mesh->buffers[0] = mesh->source + source->count;
    mesh->buffers[1] = mesh->buffers[0] + source->count;
    mesh->current = 0;
    mesh->count = source->count;
    mesh->value = source->value;
    mesh->enabled = 1;
    mesh->key = serial;
    mesh->id = id;
    serial++;
    int index = mesh->key & 0xff;
    *tails[index] = mesh;
    mesh->link = tails[index];
    tails[index] = &mesh->next;
    mesh->next = 0;
    *tail2 = mesh;
    mesh->link2 = tail2;
    tail2 = &mesh->next2;
    mesh->next2 = 0;
    mesh->unknown_8c = 0;
    func_0001B500(mesh->key);
    func_0001B500(mesh->key);
    return mesh->key;
}
