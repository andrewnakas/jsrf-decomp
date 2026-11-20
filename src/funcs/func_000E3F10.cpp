struct Vector3 {
    float x;
    float y;
    float z;
};

struct Motion_0005F060;

void func_001BA9C0();
void __fastcall func_001BAA50();
void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);
void __fastcall func_001BAC00(Vector3 *out, const Vector3 *in);
void __fastcall func_0014C300(Vector3 *out, const Vector3 *a, const Vector3 *b);
void __fastcall func_0014C370(Vector3 *out, const Vector3 *in, float scale);
void __fastcall func_0014C8B0(Vector3 *out, const Vector3 *first, const Vector3 *second, float share);

struct Model_000178B0;

// A collision link: the model it stands for.
struct Item_00016200 {
    Model_000178B0 *model;
    Item_00016200 *next;
};

struct Item_00016260 {
    char unknown_00[8];
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

// What func_000179B0 finds by key: its vertices, a copy of them, their bounds and count.
struct Entry_000179B0 {
    int unknown_00;
    Vertex_00017DF0 *vertices;
    Vertex_00017DF0 *copies;
    char unknown_0c[4];
    Box_00017CC0 box;
    int count;
};

// The beam a mark draws: its two ends, centre and radius.
struct Mesh_00017F60 {
    Vector3 *ends;
    char unknown_04[4];
    Vector3 center;
    float radius;
};

// A drawn mark (0x24 bytes).
struct Item_000162A0 {
    int mode;
    int flag;
    Mesh_00017F60 *mesh;
    int value;
    char unknown_10[0x14];
};

// The collision world (data_0022FCE8).
struct Object_00016200 {
    void func_00016240(Item_00016200 *item);
    void func_00016260(Item_00016260 *item, int value);
    void func_000162E0(Item_000162A0 *item);
    void func_000178B0(Model_000178B0 *model, Motion_0005F060 *motion, float time);
    Entry_000179B0 *func_000179B0(int key);
    void func_00017CC0(Box_00017CC0 *box, const Vector3 *points, unsigned int count);
    void func_00017DF0(Box_00017CC0 *box, const Vertex_00017DF0 *vertices, unsigned int count);
};

extern Object_00016200 data_0022FCE8;

// The rest points and normals of the two deformed meshes.
extern Vector3 data_00218B54[];
extern Vector3 data_00218B3C[];
extern Vector3 data_00218B18[];
extern Vector3 data_00218AF4[];

struct Object_00047470 {
    void func_000480C0(unsigned int index);
};

struct Holder_000E45D0 {
    Object_00047470 *model;
};

struct Node {
    Node(Node *owner, int id, unsigned int flags);
    virtual ~Node();
    virtual void func_00011C90();
    virtual void func_00011C90_1();
    virtual void func_00011C80(int argument);

    unsigned int flags;
    int id;
    unsigned int mask;
    float depth;
    int sortKey;
    char unknown_18[0xc];
    Node *parent;
    Node *child;
    Node *previous;
    Node *next;
    char unknown_34[0x10];
};

// The second base (table 0x1CE1B8), two slots.
struct Object_000C60C0 {
    virtual void func_000C6090();
    virtual void func_000C60C0();
};

// A collision block: a link, a box and two counts.
struct Block_000E3F10 {
    Item_00016260 link;
    Box_00017CC0 box;
    char unknown_20[4];
    int value_24;
    char unknown_28[0xc];
    int value_34;
};

// The class whose tables are at 0x1CED20 (Node) and 0x1CED18 (Object_000C60C0 at +0x44).
struct Object_000E45D0 : Node, Object_000C60C0 {
    virtual ~Object_000E45D0();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);

    void func_000E3F10();

    char unknown_048[0x2c];
    float distance;
    char unknown_078[0x18];
    unsigned int flags_90;
    char unknown_094[0x48];
    Vector3 start;
    Vector3 end;
    Vector3 direction;
    float size;
    char unknown_104[0x44];
    int value_148;
    char unknown_14c[0x18];
    Holder_000E45D0 *holder;
    char unknown_168[4];
    Motion_0005F060 *motion;
    char unknown_170[0xc];
    Item_00016200 link;
    char unknown_184[0x24];
    Block_000E3F10 block;
    char unknown_1e0[0xc];
    Item_000162A0 beam;
    int keys[2];
};

// Unless flag 0x100 at 0x90 is set, inside a matrix: poses and links the model of the link at 0x17c (motion 0x16c);
// without flag 0x2000, within 300 (0x74) and with nothing at 0x148 lays the beam at 0x1ec from 0xdc to 0xe8 (radius
// half the value at 0x100 plus 10), else clears its value; puts 0xdc at the matrix origin, 0xf4 along its -z and 0xe8
// 300 further, and within 300 boxes the two points in the block at 0x1a8 (with the id), else clears its counts. Then
// deforms the meshes found by the keys at 0x210 and 0x214 to joint 0 of the holder's model and bounds them.
void Object_000E45D0::func_000E3F10()
{
    if (flags_90 & 0x100) {
        return;
    }
    func_001BA9C0();
    data_0022FCE8.func_000178B0(link.model, motion, 0.0f);
    data_0022FCE8.func_00016240(&link);
    if (!(flags_90 & 0x2000)) {
        holder->model->func_000480C0(2);
        if (distance < 300.0f && value_148 == 0) {
            *beam.mesh->ends = start;
            beam.mesh->ends[1] = end;
            func_0014C8B0(&beam.mesh->center, &start, &end, 0.5f);
            beam.mesh->radius = size * 0.5f + 10.0f;
            data_0022FCE8.func_000162E0(&beam);
        } else {
            beam.value = 0;
        }
        Vector3 down;
        down.x = 0.0f;
        down.y = 0.0f;
        down.z = -1.0f;
        func_001BAB20(&start, 0);
        func_001BAC00(&down, &down);
        direction = down;
        func_0014C370(&down, &down, 300.0f);
        func_0014C300(&end, &start, &down);
        if (distance < 300.0f) {
            data_0022FCE8.func_00017CC0(&block.box, &start, 2);
            data_0022FCE8.func_00016260(&block.link, id);
        } else {
            block.value_24 = 0;
            block.value_34 = 0;
        }
    }
    Entry_000179B0 *entry = data_0022FCE8.func_000179B0(keys[0]);
    holder->model->func_000480C0(0);
    if (entry) {
        for (int i = 0; i < entry->count; i++) {
            func_001BAB20(&entry->vertices[i].position, &data_00218B54[i]);
            func_001BAC00(&entry->vertices[i].normal, &data_00218B3C[i]);
            entry->copies[i].position = entry->vertices[i].position;
            entry->copies[i].normal = entry->vertices[i].normal;
        }
        data_0022FCE8.func_00017DF0(&entry->box, entry->vertices, entry->count);
    }
    entry = data_0022FCE8.func_000179B0(keys[1]);
    if (entry) {
        for (int i = 0; i < entry->count; i++) {
            func_001BAB20(&entry->vertices[i].position, &data_00218B18[i]);
            func_001BAC00(&entry->vertices[i].normal, &data_00218AF4[i]);
            entry->copies[i].position = entry->vertices[i].position;
            entry->copies[i].normal = entry->vertices[i].normal;
        }
        data_0022FCE8.func_00017DF0(&entry->box, entry->vertices, entry->count);
    }
    func_001BAA50();
}
