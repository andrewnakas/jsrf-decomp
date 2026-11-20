/* const: 0x10000 */
extern "C" void *memset(void *destination, int value, unsigned int size);

struct Vector3 {
    float x;
    float y;
    float z;
};

void func_001BA9C0();
void __fastcall func_001BAA50();
void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);

struct Mesh_00017F60;

struct Item_00016260 {
    char unknown_00[8];
};

struct Box_00017CC0 {
    char unknown_00[8];
};

// A drawn mark (0x24 bytes).
struct Item_000162A0 {
    int flags;
    int value_04;
    Mesh_00017F60 *mesh;
    int value_0c;
    char unknown_10[0x14];
};

struct Object_00016200 {
    void func_00016260(Item_00016260 *item, int value);
    void func_000162A0(Item_000162A0 *item);
    void func_00017D90(Box_00017CC0 *box, const Vector3 *points, unsigned int count, float radius);
    void func_00019570(Mesh_00017F60 *mesh, const Mesh_00017F60 *source);
};

extern Object_00016200 data_0022FCE8;
extern Mesh_00017F60 data_00218D78;

struct Object_00047470 {
    void func_000480C0(unsigned int index);
};

// The object a behaviour serves (at 0x4).
struct Object_000C5B50 {
    char unknown_00[0x5c];
    float value_5c;
    float value_60;
    char unknown_64[0xc];
    float value_70;
    char unknown_74[0x30];
    unsigned int flags;
};

// A 0x44-byte block of the three at 0x88: a link, a box and 0x20 bytes cleared when the box is off.
struct Block_000E5FF0 {
    Item_00016260 link;
    Box_00017CC0 box;
    char unknown_10[0x10];
    int state[8];
    char unknown_40[4];
};

// The behaviour whose table is at 0x1CED80 (0x184 bytes).
struct Object_000E5FF0 {
    void *vtable;
    Object_000C5B50 *owner;
    char unknown_08[0x48];
    float value_50;
    Object_00047470 *model;
    char unknown_58[0xc];
    Item_000162A0 mark;
    Block_000E5FF0 blocks[3];
    Vector3 points[3];

    void func_000E5CD0();
};

// Unless the owner has flag 0x1000000, and while it moves (0x5c, 0x60, 0x50 here, or flag 0x80): poses the boxes of
// the three blocks (radius 3.5) at the model's joints 0 and 1 (3.5 up, then its origin) and 5 up, linking each;
// otherwise clears their state. Below 100 at 0x70 (and without flag 0x10000) draws the mark at 0x64 with the mesh at
// data_00218D78, else clears 0x70.
void Object_000E5FF0::func_000E5CD0()
{
    unsigned int flags = owner->flags;
    if (!(flags & 0x1000000)
        && (owner->value_5c != 0.0f || owner->value_60 != 0.0f || value_50 != 0.0f || (flags & 0x80))) {
        Vector3 offset = {0.0f, 3.5f, 0.0f};
        func_001BA9C0();
        model->func_000480C0(0);
        func_001BAB20(&points[0], &offset);
        data_0022FCE8.func_00017D90(&blocks[0].box, &points[0], 1, 3.5f);
        data_0022FCE8.func_00016260(&blocks[0].link, -1);
        model->func_000480C0(1);
        func_001BAB20(&points[1], 0);
        data_0022FCE8.func_00017D90(&blocks[1].box, &points[1], 1, 3.5f);
        data_0022FCE8.func_00016260(&blocks[1].link, -1);
        offset.y = 5.0f;
        func_001BAB20(&points[2], &offset);
        func_001BAA50();
        data_0022FCE8.func_00017D90(&blocks[2].box, &points[2], 1, 3.5f);
        data_0022FCE8.func_00016260(&blocks[2].link, -1);
    } else {
        memset(blocks[0].state, 0, sizeof blocks[0].state);
        memset(blocks[1].state, 0, sizeof blocks[1].state);
        memset(blocks[2].state, 0, sizeof blocks[2].state);
    }
    if (!(owner->flags & 0x10000) && owner->value_70 < 100.0f) {
        data_0022FCE8.func_00019570(mark.mesh, &data_00218D78);
        data_0022FCE8.func_000162A0(&mark);
    } else {
        mark.value_0c = 0;
    }
}
