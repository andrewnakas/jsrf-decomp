/* sym: ??0Object_00043860@@QAE@PAUNode@@HIPAUInfo_00043710@@@Z = 0x00043710 */
/* sym: ??1Object_00043860@@UAE@XZ = 0x00043860 */
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

struct Object_00039BE0 {
    int func_00039DB0(int type, int index);
};

extern Object_00039BE0 data_001EFFB0;

// What the constructor is given: a position and a word.
struct Info_00043710 {
    Vector3 position;
    int value;
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

// The node class whose table is at 0x1CA6C8 (destructor 0x43860; 0x98 bytes).
struct Object_00043860 : Node {
    Object_00043860(Node *owner, int id, unsigned int flags, Info_00043710 *info);
    virtual ~Object_00043860();

    Vector3 position;
    int value;
    void *unknown_54;
    void *unknown_58;
    int unknown_5c;
    int unknown_60;
    int unknown_64;
    int unknown_68;
    float unknown_6c;
    char unknown_70[4];
    int unknown_74;
    int unknown_78;
    Mesh_00017F60 *mesh;
};

// Sets flags 0x1004, keeps the position and word of `info`, looks up +0x68 (func_0006AAA0 of 0x20C6C0) and +0x6c
// (func_000466C0 of 0x1F93C8) for the position, takes +0x54 and +0x58 from func_00025700, makes a collision mesh from
// 0x1F9120 placed at the position (func_00019680, func_00019570) with 0x18 and the word in its first part, and sets
// +0x60 when func_00039DB0 (3, word) of 0x1EFFB0 gives 0.
Object_00043860::Object_00043860(Node *owner, int id, unsigned int flags, Info_00043710 *info)
    : Node(owner, id, flags)
{
    this->flags |= 0x1004;
    position = info->position;
    value = info->value;
    unknown_68 = data_0020C6C0.func_0006AAA0(&position, -1);
    unknown_6c = data_001F93C8.func_000466C0(&position, -1);
    unknown_54 = func_00025700(11, 0, 1, 0x11);
    unknown_58 = func_00025700(11, 0, 4, 8);
    unknown_5c = 0;
    func_001BA9C0();
    mesh = data_0022FCE8.func_00019680(&data_001F9120);
    func_001BAAA0(&position.x);
    data_0022FCE8.func_00019570(mesh, &data_001F9120);
    func_001BAA50();
    unknown_74 = 0x1000000;
    unknown_78 = 0x800000;
    mesh->parts->unknown_1c = 0x18;
    mesh->parts->unknown_20 = value;
    unknown_60 = !data_001EFFB0.func_00039DB0(3, value);
    unknown_64 = 0;
}
