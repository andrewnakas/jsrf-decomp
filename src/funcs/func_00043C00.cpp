/* const: 0x10000 */
/* const: 0x100000 */
/* const: 0x80000 */
/* sym: ??0Object_000432E0@@QAE@PAUNode@@HIPAUInfo_00043C00@@@Z = 0x00043C00 */
/* sym: ??1Object_000432E0@@UAE@XZ = 0x000432E0 */
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
void func_001BAA50();

// The first part of a mesh: two words at +0x1c and +0x20.
struct Part_00017F60 {
    char unknown_00[0x1c];
    int unknown_1c;
    int unknown_20;
};

struct Mesh_00017F60 {
    Part_00017F60 *parts;
};

extern Mesh_00017F60 data_001F9120;

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

// One place the constructor is given (16 bytes): a position and a kind (0 to 5).
struct Place_00043C00 {
    Vector3 position;
    int kind;
};

// What the constructor is given: its places and how many.
struct Info_00043C00 {
    Place_00043C00 *places;
    unsigned int count;
};

// One entry (0x54 bytes): a place, its lookups, collision bits for its kind and a collision mesh.
struct Entry_00043370 {
    Place_00043C00 place;
    int unknown_10;
    int unknown_14;
    int unknown_18;
    int unknown_1c;
    int unknown_20;
    int unknown_24;
    float unknown_28;
    float unknown_2c;
    int unknown_30;
    int unknown_34;
    Mesh_00017F60 *block;
    char unknown_3c[0x18];
};

extern void *data_00231CD0[18];
extern void *data_00231D18[9];
extern unsigned int data_00231D3C;

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

// The node class whose table is at 0x1CA678 (destructor 0x432E0).
struct Object_000432E0 : Node {
    Object_000432E0(Node *owner, int id, unsigned int flags, Info_00043C00 *info);
    virtual ~Object_000432E0();

    Entry_00043370 *entries;
    unsigned int count;
};

// Sets flags 0xc and makes one entry per place in `info`: its place, the lookups of func_0006AAA0 (0x20C6C0) and
// func_000466C0 (0x1F93C8), 1 and 0.05, and a collision mesh from 0x1F9120 placed at it, with collision bits and a
// type (0xe, 0x10 or 0x14) by kind and the kind joined with the next serial of 0x231D3C (24 bits, shifted up 8) in
// its first part. Then fills the tables at 0x231CD0 (18) and 0x231D18 (9) from func_00025700.
Object_000432E0::Object_000432E0(Node *owner, int id, unsigned int flags, Info_00043C00 *info)
    : Node(owner, id, flags)
{
    this->flags |= 0xc;
    count = info->count;
    entries = new Entry_00043370[count];
    for (unsigned int i = 0; i < count; i++) {
        entries[i].place = info->places[i];
        entries[i].unknown_10 = data_0020C6C0.func_0006AAA0(&entries[i].place.position, -1);
        entries[i].unknown_20 = 0;
        entries[i].unknown_24 = 0;
        entries[i].unknown_18 = 1;
        entries[i].unknown_28 = 0.05f;
        entries[i].unknown_1c = 0;
        entries[i].unknown_2c = data_001F93C8.func_000466C0(&entries[i].place.position, -1);
        func_001BA9C0();
        entries[i].block = data_0022FCE8.func_00019680(&data_001F9120);
        func_001BAAA0(&entries[i].place.position.x);
        data_0022FCE8.func_00019570(entries[i].block, &data_001F9120);
        switch (entries[i].place.kind) {
        case 0:
        case 1:
            entries[i].unknown_30 = 0x4000;
            entries[i].unknown_34 = 0x2000;
            entries[i].block->parts->unknown_1c = 0xe;
            break;
        case 2:
        case 3:
            entries[i].unknown_30 = 0x10000;
            entries[i].unknown_34 = 0x8000;
            entries[i].block->parts->unknown_1c = 0x10;
            break;
        case 4:
            entries[i].unknown_30 = 0x100000;
            entries[i].unknown_34 = 0x80000;
            entries[i].block->parts->unknown_1c = 0x14;
            break;
        case 5:
            entries[i].unknown_30 = 0x100000;
            entries[i].unknown_34 = 0x80000;
            entries[i].block->parts->unknown_1c = 0x14;
            break;
        }
        unsigned int serial = data_00231D3C << 8;
        data_00231D3C++;
        if (data_00231D3C > 0xffffff) {
            data_00231D3C = 0;
        }
        entries[i].block->parts->unknown_20 = entries[i].place.kind | serial;
        func_001BAA50();
    }
    for (unsigned int j = 0; j < 18; j++) {
        data_00231CD0[j] = func_00025700(11, 0, 1, j);
    }
    for (unsigned int k = 0; k < 9; k++) {
        data_00231D18[k] = func_00025700(11, 0, 4, k);
    }
}
