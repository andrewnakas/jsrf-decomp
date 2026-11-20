/* sym: ??0Object_000E7770@@QAE@PAUNode@@HIPAUInit_000E7770@@I@Z = 0x000E7A60 */
/* sym: ??0Node@@QAE@PAU0@HI@Z = 0x00012100 */
/* sym: ??1Object_000E7770@@UAE@XZ = 0x000E76F0 */
/* sym: ??1Node@@UAE@XZ = 0x00011000 */
/* sym: ?func_00011C90@Object_000E7770@@UAEXXZ = 0x000E7770 */
/* sym: ?func_00011C90_1@Object_000E7770@@UAEXXZ = 0x000E7CA0 */
struct Vector3 {
    float x;
    float y;
    float z;
};

// Three angles (x, y, z).
struct Angles_000C1300 {
    int x;
    int y;
    int z;
};

struct Vector4_000E7A60 {
    float x;
    float y;
    float z;
    float w;
};

struct Mesh_00017F60;

struct Object_00016200 {
    Mesh_00017F60 *func_00019680(const Mesh_00017F60 *mesh);
    void func_00019570(Mesh_00017F60 *mesh, const Mesh_00017F60 *source);
};

extern Object_00016200 data_0022FCE8;
extern Mesh_00017F60 data_00218EB8;

struct Object_00046670 {
    float func_000466C0(Vector3 *position, int index);
};

extern Object_00046670 data_001F93C8;

struct Object_00066980 {
    float func_00066950();
};

extern Object_00066980 data_00251F28;

struct Object_0006DB80 {
    int func_0006DAE0(int first, int second, int third, int fourth);
    void func_0006DEB0(int key, int value);
};

extern Object_0006DB80 data_00251F78;

void *func_00025700(unsigned int first, int second, int third, int fourth);

void func_001BA9C0();
void __fastcall func_001BAA50();
void __fastcall func_001BAAA0(float *vector);
void __fastcall func_001BB2E0(int angle);
void __fastcall func_001BB330(int angle);
void __fastcall func_001BB380(int angle);

struct Motion_0005F060 {
    short unknown_00;
    short frames;
};

struct Part_000E7A60 {
    char unknown_00[0x54];
    Vector4_000E7A60 box;
};

struct Model_000E7A60 {
    char unknown_00[0xc];
    Part_000E7A60 *part;
};

struct Holder_000E7A60 {
    Model_000E7A60 *model;
};

struct Motions_000E7A60 {
    Motion_0005F060 *motions[2];
};

// What func_00025700 gives for (5, 0xf).
struct Resource_000E7A60 {
    Holder_000E7A60 *holder;
    char unknown_04[0x14];
    Motions_000E7A60 *set;
};

struct Holder_000E7A60b {
    int value;
};

// What func_00025700 gives for (5, 0x12).
struct Resource_000E7A60b {
    Holder_000E7A60b *holder;
};

// One placement (0x1c bytes): a position, angles, and a value whose bit 1 picks the second motion.
struct Init_000E7770 {
    Vector3 position;
    Angles_000C1300 angles;
    unsigned int value_18;
};

// The item at 0xd8 (kind, count, mesh).
struct Item_000162A0 {
    int kind;
    int count;
    Mesh_00017F60 *mesh;
    int value_0c;
};

struct Node {
    Node(Node *owner, int id, unsigned int flags);
    virtual ~Node();
    virtual void func_00011C90();
    virtual void func_00011C90_1();
    virtual void func_00011C80(int argument);
    virtual void func_00011C90_2();
    virtual void func_00011C90_3();
    virtual void func_00011C80_1(int argument);
    virtual void func_00011C90_4();
    virtual void func_00011C90_5();
    virtual void func_00011C80_2(int argument);
    virtual void func_00011C90_6();
    virtual void func_00011C90_7();
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C90_8();
    virtual void func_00011C90_9();
    virtual void func_00011C80_4(int argument);

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

struct Desc_000E5380;

// The second base (table 0x1CE1B8), two slots.
struct Object_000C60C0 {
    virtual void func_000C6090(Object_000C60C0 *previous, Desc_000E5380 *owner, int index);
    virtual void func_000C60C0();
};

// The class whose tables are at 0x1CEDF0 (Node) and 0x1CEDE8 (Object_000C60C0 at +0x44), 0x104 bytes.
struct Object_000E7770 : Node, Object_000C60C0 {
    Object_000E7770(Node *owner, int id, unsigned int flags, Init_000E7770 *init, unsigned int number);
    virtual ~Object_000E7770();
    virtual void func_00011C90();
    virtual void func_00011C90_1();

    Vector3 position;
    Angles_000C1300 angles;
    char unknown_060[0x18];
    Vector4_000E7A60 box;
    float height;
    char unknown_08c[4];
    unsigned int flags_90;
    char unknown_094[0x28];
    int value_bc;
    char unknown_0c0[4];
    unsigned int number;
    Model_000E7A60 *model;
    int value_cc;
    Motion_0005F060 *motion;
    float time;
    Item_000162A0 item;
    char unknown_0e8[0x14];
    int sound;
    int value_100;
};

// Takes the placement's position and angles, flag 0x100, the number, the model of resource (5, 0xf) with its box,
// the first or (with bit 1 of the placement's 0x18) second motion started at a random point of its frames
// (func_00066950), and a mesh copy of data_00218EB8 placed there; starts a stopped sound (func_0006DAE0), keeps
// the first value of resource (5, 0x12) when the placement's 0x18 is 0, and the ground height (func_000466C0).
Object_000E7770::Object_000E7770(Node *owner, int id, unsigned int flags, Init_000E7770 *init, unsigned int number)
    : Node(owner, id, flags)
{
    position = init->position;
    angles = init->angles;
    flags_90 = 0x100;
    value_bc = 0;
    this->number = number;
    Resource_000E7A60 *resource = (Resource_000E7A60 *)func_00025700(5, 0xf, 0, 0);
    model = resource->holder->model;
    box = model->part->box;
    if (!(init->value_18 & 1)) {
        motion = resource->set->motions[0];
    } else {
        motion = resource->set->motions[1];
    }
    time = data_00251F28.func_00066950() * (motion->frames - 1.0f);
    item.mesh = data_0022FCE8.func_00019680(&data_00218EB8);
    item.kind = 2;
    item.count = 1;
    item.value_0c = 0;
    func_001BA9C0();
    func_001BAAA0(&position.x);
    func_001BB330(angles.y + 0x8000);
    func_001BB2E0(angles.x);
    func_001BB380(angles.z);
    data_0022FCE8.func_00019570(item.mesh, &data_00218EB8);
    func_001BAA50();
    sound = data_00251F78.func_0006DAE0(1, 0, -1, -1);
    if (sound != -1) {
        data_00251F78.func_0006DEB0(sound, 0);
    }
    value_100 = 0;
    Resource_000E7A60b *other = (Resource_000E7A60b *)func_00025700(5, 0x12, 0, 0);
    if (other && init->value_18 == 0) {
        value_cc = other->holder->value;
    } else {
        value_cc = 0;
    }
    height = data_001F93C8.func_000466C0(&position, -1);
}
