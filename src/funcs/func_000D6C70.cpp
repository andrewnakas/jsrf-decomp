struct Vector3 {
    float x;
    float y;
    float z;
};

void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);

struct Mesh_00017F60;

struct Item_00016200 {
    int unknown_00;
};

// The item at 0x220: the mesh it draws at 0x8.
struct Item_000162A0 {
    char unknown_00[8];
    Mesh_00017F60 *mesh;
};

struct Item_00016260 {
    char unknown_00[8];
};

struct Box_00017CC0 {
    char unknown_00[8];
};

struct Object_00016200 {
    void func_00016240(Item_00016200 *item);
    void func_00016260(Item_00016260 *item, int value);
    void func_000162A0(Item_000162A0 *item);
    void func_00017D90(Box_00017CC0 *box, const Vector3 *points, unsigned int count, float radius);
    void func_00019570(Mesh_00017F60 *mesh, const Mesh_00017F60 *source);
    void func_0001D940(void **handle);
};

extern Object_00016200 data_0022FCE8;

// The points of the four blocks, in the model's frame.
extern Vector3 data_0021712C[4];
extern Vector3 data_0021715C[4];

// The object a behaviour serves.
struct Owner_000D6C70 {
    char unknown_00[8];
    int id;
    char unknown_0c[0x50];
    float value_5c;
    float value_60;
    char unknown_64[0x40];
    unsigned int flags;
};

// A 0x44-byte collision block: its item, its box at 0x8.
struct Block_000D6350 {
    Item_00016260 item;
    Box_00017CC0 box;
    char unknown_10[0x14];
    int value_24;
    char unknown_28[0xc];
    int value_34;
    char unknown_38[0xc];
};

// The base with a pure slot 0 (table 0x1CE304).
struct Object_000CC600 {
    virtual void func_000CD1E0() = 0;
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_1(int argument);
    virtual ~Object_000CC600();
};

struct Object_000CD1E0 : Object_000CC600 {
    virtual void func_000CD1E0();
    virtual void func_00011C90();
    virtual ~Object_000CD1E0();
    virtual void func_000CD210();
    virtual void func_000CD800();
    virtual void func_000CD850();
    virtual void func_000D77D0() = 0;
    virtual void func_000D7880() = 0;
    virtual float func_000CD440();
    virtual float func_000CD4F0();
    virtual int func_000CD390(Vector3 *position, float value, Vector3 *direction);

    Owner_000D6C70 *owner;
    int state;
    int unknown_0c;
    int unknown_10;
    char unknown_14[0xc];
    int unknown_20[3];
    char unknown_2c[0xc];
    int unknown_38;
    int unknown_3c;
    int unknown_40;
    int unknown_44;
    int unknown_48;
    char unknown_4c[0x1c];
    int unknown_68;
};


// The class whose table is at 0x1CE5F0.
struct Object_000D6350 : Object_000CD1E0 {
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_1(int argument);
    virtual ~Object_000D6350();
    virtual void func_000CD210();
    virtual void func_000CD800();
    virtual void func_000CD850();
    virtual void func_000D77D0();
    virtual void func_000D7880();

    void func_000D6C70();

    char unknown_06c[0x98];
    Mesh_00017F60 *mesh_104;
    const Mesh_00017F60 *template_108;
    void **handle_10c;
    Block_000D6350 blocks[4];
    Item_000162A0 item_220;
    char unknown_22c[0x18];
    Vector3 points[4];
    Vector3 ends[4];
    Item_00016200 item_2a4;
};

// Unless the owner stands still (0 at 0x5c and 0x60; then the four blocks' 0x24 and 0x34 are cleared), puts the
// four blocks at the points data_0021712C and data_0021715C in the current frame and updates them with the owner's
// id; without the owner's flag 0x1000000, sets the mesh at 0x104 from 0x108, hands it to the item at 0x220 and
// updates that, the handle at 0x10c and the item at 0x2a4.
void Object_000D6350::func_000D6C70()
{
    if (owner->value_5c == 0.0f && owner->value_60 == 0.0f) {
        for (int i = 0; i < 4; i++) {
            blocks[i].value_34 = 0;
            blocks[i].value_24 = 0;
        }
    } else {
        for (unsigned int i = 0; i < 4; i++) {
            func_001BAB20(&points[i], &data_0021712C[i]);
            func_001BAB20(&ends[i], &data_0021715C[i]);
            data_0022FCE8.func_00017D90(&blocks[i].box, &points[i], 1, 5.0f);
            data_0022FCE8.func_00016260(&blocks[i].item, owner->id);
        }
    }
    if (!(owner->flags & 0x1000000)) {
        data_0022FCE8.func_00019570(mesh_104, template_108);
        item_220.mesh = mesh_104;
        data_0022FCE8.func_000162A0(&item_220);
        data_0022FCE8.func_0001D940(handle_10c);
        data_0022FCE8.func_00016240(&item_2a4);
    }
}
