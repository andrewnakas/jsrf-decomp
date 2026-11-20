/* const: 0x200000 */
/* sym: ??0Object_0003BB10@@QAE@PAUNode@@HIPAUInfo_0003B940@@@Z = 0x0003B940 */
/* sym: ??1Object_0003BB10@@UAE@XZ = 0x0003BB10 */
/* sym: ??0Node@@QAE@PAU0@HI@Z = 0x00012100 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
struct Vector3 {
    float x;
    float y;
    float z;
};

void *func_00025700(unsigned int index, int first, int second, int third);
void func_001BA9C0();
void __fastcall func_001BAAA0(float *vector);
void __fastcall func_001BAA50();

// The first part of a mesh: two words at +0x1c and +0x20.
struct Part_00017F60 {
    char unknown_00[0x1c];
    int unknown_1c;
    int unknown_20;
};

struct Mesh_00017F60 {
    Part_00017F60 *parts;
};

extern Mesh_00017F60 data_001F706C;

// The collision world (data_0022FCE8).
struct Object_00016200 {
    void func_00019570(Mesh_00017F60 *mesh, const Mesh_00017F60 *source);
    Mesh_00017F60 *func_00019680(const Mesh_00017F60 *mesh);
};

extern Object_00016200 data_0022FCE8;

struct Object_0006A960 {
    int func_0006AAA0(Vector3 *position, int index);
};

extern Object_0006A960 data_0020C6C0;

struct Object_00046670 {
    float func_000466C0(Vector3 *position, int index);
};

extern Object_00046670 data_001F93C8;

// One place the constructor is given (16 bytes).
struct Place_0003B940 {
    Vector3 position;
    int unknown_0c;
};

// What the constructor is given: its places and how many.
struct Info_0003B940 {
    Place_0003B940 *places;
    unsigned int count;
};

// One entry (0x5c bytes): a place, its lookups, a fade and a collision mesh.
struct Entry_0003BC80 {
    Vector3 position;
    int unknown_0c;
    int unknown_10;
    int unknown_14;
    int unknown_18;
    float time;
    int unknown_20;
    int unknown_24;
    float unknown_28;
    float unknown_2c;
    float unknown_30;
    float unknown_34;
    int unknown_38;
    int unknown_3c;
    Mesh_00017F60 *block;
    char unknown_44[0x18];
};

struct Node {
    Node(Node *owner, int id, unsigned int flags);
    virtual ~Node();

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

// The node class whose table is at 0x1CA3E8 (destructor 0x3BB10; 0x5c bytes).
struct Object_0003BB10 : Node {
    Object_0003BB10(Node *owner, int id, unsigned int flags, Info_0003B940 *info);
    virtual ~Object_0003BB10();

    int unknown_44;
    unsigned int count;
    char unknown_4c[4];
    Entry_0003BC80 *entries;
    void *unknown_54;
    void *unknown_58;
};

// Sets flag 4 and makes one entry per place in `info`: its position, -1 twice, the lookups of func_0006AAA0 (0x20C6C0)
// and func_000466C0 (0x1F93C8), 30 and three times 1.0, and a collision mesh from 0x1F706C placed at it with 0x16
// and the entry's index in its first part. Then takes +0x54 and +0x58 from func_00025700.
Object_0003BB10::Object_0003BB10(Node *owner, int id, unsigned int flags, Info_0003B940 *info)
    : Node(owner, id, flags)
{
    this->flags |= 4;
    unknown_44 = 0;
    count = info->count;
    entries = new Entry_0003BC80[count];
    for (unsigned int i = 0; i < count; i++) {
        entries[i].position = info->places[i].position;
        entries[i].unknown_0c = -1;
        entries[i].unknown_10 = -1;
        entries[i].unknown_14 = data_0020C6C0.func_0006AAA0(&entries[i].position, -1);
        entries[i].unknown_18 = 0;
        entries[i].time = 0.0f;
        entries[i].unknown_20 = 0;
        entries[i].unknown_24 = 30;
        entries[i].unknown_28 = 1.0f;
        entries[i].unknown_2c = 1.0f;
        entries[i].unknown_30 = 1.0f;
        entries[i].unknown_34 = data_001F93C8.func_000466C0(&entries[i].position, -1);
        func_001BA9C0();
        entries[i].block = data_0022FCE8.func_00019680(&data_001F706C);
        func_001BAAA0(&entries[i].position.x);
        data_0022FCE8.func_00019570(entries[i].block, &data_001F706C);
        entries[i].unknown_38 = 0x400000;
        entries[i].unknown_3c = 0x200000;
        entries[i].block->parts->unknown_1c = 0x16;
        entries[i].block->parts->unknown_20 = i;
        func_001BAA50();
    }
    unknown_54 = func_00025700(11, 0, 1, 0x10);
    unknown_58 = func_00025700(11, 0, 4, 7);
}
