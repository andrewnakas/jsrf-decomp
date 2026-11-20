/* const: 0x40000 */
/* const: 0x20000 */
/* sym: ??0Object_000448B0@@QAE@PAUNode@@HIPAUInfo_00044250@@@Z = 0x00044250 */
/* sym: ??1Object_000448B0@@UAE@XZ = 0x000448B0 */
/* sym: ??0Node@@QAE@PAU0@HI@Z = 0x00012100 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
struct Vector3 {
    float x;
    float y;
    float z;
};

void *func_00025700(unsigned int index, int first, int second, int third);
void func_001BA9C0();
void __fastcall func_001BAAA0(float *matrix);
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

// What the constructor is given (0x30 bytes): a position and a word at +0xc.
struct Info_00044250 {
    Vector3 position;
    int value;
    char unknown_10[0x20];
};

// An entry of the list at 0x1F9138: a copy of the info, its index and links.
struct Entry_00044520 {
    Info_00044250 info;
    int index;
    Entry_00044520 **link;
    Entry_00044520 *next;
};

// The list at 0x1F9138.
struct Object_00043700 {
    Entry_00044520 *head;
    Entry_00044520 **tail;
    int count;
};

extern Object_00043700 data_001F9138;

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

// The node class whose table is at 0x1CA748 (destructor 0x448B0; 0xc8 bytes).
struct Object_000448B0 : Node {
    Object_000448B0(Node *owner, int id, unsigned int flags, Info_00044250 *info);
    virtual ~Object_000448B0();

    Info_00044250 info;
    int unknown_74;
    int unknown_78;
    int unknown_7c;
    float unknown_80;
    int index;
    int value;
    void *unknown_8c;
    void *unknown_90;
    void *unknown_94;
    char unknown_98[8];
    int unknown_a0;
    int unknown_a4;
    Mesh_00017F60 *mesh;
};

// Sets flags 0x1004, keeps a copy of `info`, looks up +0x74 (func_0006AAA0 of 0x20C6C0) and +0x80 (func_000466C0 of
// 0x1F93C8) for its position, appends a copy of it to the list at 0x1F9138 (its index to +0x84), keeps its word,
// makes a collision mesh from 0x1F9120 placed at the position (func_00019680, func_00019570) with 0x12 and the index
// in its first part, and takes +0x8c, +0x90 and +0x94 from func_00025700.
Object_000448B0::Object_000448B0(Node *owner, int id, unsigned int flags, Info_00044250 *info)
    : Node(owner, id, flags)
{
    this->flags |= 0x1004;
    this->info = *info;
    unknown_74 = data_0020C6C0.func_0006AAA0(&info->position, -1);
    unknown_78 = 0;
    unknown_7c = 0;
    unknown_80 = data_001F93C8.func_000466C0(&info->position, -1);
    Entry_00044520 *entry = new Entry_00044520;
    entry->index = data_001F9138.count;
    entry->info = *info;
    entry->next = 0;
    *data_001F9138.tail = entry;
    entry->link = data_001F9138.tail;
    data_001F9138.tail = &entry->next;
    data_001F9138.count++;
    index = entry->index;
    value = info->value;
    func_001BA9C0();
    mesh = data_0022FCE8.func_00019680(&data_001F9120);
    func_001BAAA0(&info->position.x);
    data_0022FCE8.func_00019570(mesh, &data_001F9120);
    unknown_a0 = 0x40000;
    unknown_a4 = 0x20000;
    mesh->parts->unknown_1c = 0x12;
    mesh->parts->unknown_20 = index;
    func_001BAA50();
    unknown_8c = func_00025700(11, 0, 1, 4);
    unknown_90 = func_00025700(11, 0, 1, 5);
    unknown_94 = func_00025700(11, 0, 4, 3);
}
