struct Vector3 {
    float x;
    float y;
    float z;
};

void func_001BA9C0();
void __fastcall func_001BAA50();
void __fastcall func_001BAAA0(float *vector);
void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);

struct Mesh_00017F60;
struct Model_000178B0;
struct Motion_0005F060;

struct Item_00016200 {
    int unknown_00;
};

struct Item_00016260 {
    char unknown_00[8];
};

struct Box_00017CC0 {
    char unknown_00[0x18];
};

// An item that draws a mesh (at 0x8).
struct Item_000162A0 {
    char unknown_00[8];
    Mesh_00017F60 *mesh;
    char unknown_0c[0x18];
};

struct Object_00016200 {
    void func_00016240(Item_00016200 *item);
    void func_00016260(Item_00016260 *item, int value);
    void func_000162A0(Item_000162A0 *item);
    void func_000178B0(Model_000178B0 *model, Motion_0005F060 *motion, float time);
    void func_00017D90(Box_00017CC0 *box, const Vector3 *points, unsigned int count, float radius);
    void func_00019570(Mesh_00017F60 *mesh, const Mesh_00017F60 *source);
};

extern Object_00016200 data_0022FCE8;
extern Mesh_00017F60 data_0021A110;

// The four spheres' bones, centres and the points their meshes are drawn at.
extern int data_0021A158[4];
extern Vector3 data_0021A174[4];
extern Vector3 data_0021A128[4];

struct Object_00047470 {
    void func_000480C0(unsigned int index);
};

// The 0x6c-byte part at 0xbc.
struct Part_000EB830 {
    void func_000EB950(Object_00047470 *model);

    char unknown_00[0x6c];
};

// A collision sphere: its centre and radius.
struct Sphere_000EC7E0 {
    Vector3 centre;
    float radius;
};

// A 0x44-byte collision block: its item, its box at 0x8.
struct Block_000EC7E0 {
    Item_00016260 item;
    Box_00017CC0 box;
    char unknown_20[0x24];
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

// The second base (table 0x1CE1B8), two slots.
struct Object_000C60C0 {
    virtual void func_000C6090();
    virtual void func_000C60C0();
};

// The class whose tables are at 0x1CEF20 (Node) and 0x1CEF18 (Object_000C60C0 at +0x44).
struct Object_000ECB50 : Node, Object_000C60C0 {
    virtual ~Object_000ECB50();
    virtual void func_00011C90();
    virtual void func_00011C90_1();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_3(int argument);
    virtual void func_00011C80_4(int argument);

    void func_000EC7E0();

    char unknown_048[0x48];
    unsigned int flags_90;
    char unknown_094[0x28];
    Part_000EB830 part;
    char unknown_128[0x18];
    Object_00047470 *model;
    char unknown_144[0xc];
    Motion_0005F060 *motion_150;
    char unknown_154[0x20];
    Sphere_000EC7E0 spheres[4];
    char unknown_1b4[0x14];
    Item_000162A0 items[4];
    Model_000178B0 *drawn;
    Item_00016200 item_25c;
    char unknown_260[4];
    Block_000EC7E0 blocks[4];
};

// Draws the model at 0x258 posed by the motion at 0x150 (func_000178B0) through the item at 0x25c, the part at 0xbc
// with the model at 0x140; then for each of the four spheres at 0x174, while the flag 0x4000000 is clear at 0x90: the
// model's bone from data_0021A158, the centre from data_0021A174 in that frame, the block at 0x264 around it, and the
// mesh item at 0x1c8 drawn at data_0021A128 with data_0021A110.
void Object_000ECB50::func_000EC7E0()
{
    func_001BA9C0();
    data_0022FCE8.func_000178B0(drawn, motion_150, 0.0f);
    data_0022FCE8.func_00016240(&item_25c);
    part.func_000EB950(model);
    for (unsigned int i = 0; i < 4; i++) {
        if (flags_90 & 0x4000000) {
            continue;
        }
        model->func_000480C0(data_0021A158[i]);
        func_001BAB20(&spheres[i].centre, &data_0021A174[i]);
        data_0022FCE8.func_00017D90(&blocks[i].box, &spheres[i].centre, 1, spheres[i].radius);
        data_0022FCE8.func_00016260(&blocks[i].item, id);
        func_001BAAA0(&data_0021A128[i].x);
        data_0022FCE8.func_00019570(items[i].mesh, &data_0021A110);
        data_0022FCE8.func_000162A0(&items[i]);
    }
    func_001BAA50();
}
