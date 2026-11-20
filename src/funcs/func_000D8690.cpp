struct Vector3 {
    float x;
    float y;
    float z;
};

struct Item_00016260 {
    char unknown_00[8];
};

struct Box_00017CC0 {
    char unknown_00[8];
};

struct Item_000162A0 {
    char unknown_00[8];
};

struct Mesh_00017F60;

struct Object_00016200 {
    void func_00016260(Item_00016260 *item, int value);
    void func_000162A0(Item_000162A0 *item);
    void func_00017CC0(Box_00017CC0 *box, const Vector3 *points, unsigned int count);
    void func_00019570(Mesh_00017F60 *mesh, const Mesh_00017F60 *source);
};

extern Object_00016200 data_0022FCE8;
extern Mesh_00017F60 data_00217360;

// The object a behaviour serves.
struct Object_000C5B50 {
    char unknown_00[0x44];
    Vector3 position;
    char unknown_50[0xc];
    float value_5c;
    float value_60;
    char unknown_64[0xc];
    float value_70;
    char unknown_74[0x30];
    unsigned int flags;
};

// The base with a pure slot 0 (table 0x1CE304).
struct Object_000CC600 {
    virtual void func_000CD1E0() = 0;
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_1(int argument);
    virtual ~Object_000CC600();
};

// The class whose table is at 0x1CE63C (handlers by state at 0x217378).
struct Object_000D8A40 : Object_000CC600 {
    virtual void func_000CD1E0();

    void func_000D8690();

    Object_000C5B50 *owner;
    int state;
    char unknown_00c[8];
    Vector3 base;
    char unknown_020[0xdc];
    Item_00016260 item_0fc;
    Box_00017CC0 box;
    char unknown_10c[0x14];
    int value_120;
    char unknown_124[0xc];
    int value_130;
    char unknown_134[0x30];
    int value_164;
    char unknown_168[0xc];
    int value_174;
    char unknown_178[0xc];
    Item_000162A0 item_184;
    Mesh_00017F60 *mesh;
    int value_190;
};

// Unless the owner stands still (no flag 0x80, 0 at 0x5c and 0x60; then 0x120, 0x130, 0x164 and 0x174 are
// cleared), the box at 0x104 spans the owner's position lifted by 3 and the point at 0x14 lowered by 1, and the item
// at 0xfc is updated; below 80 at the owner's 0x70 without its flag 0x1000000 the mesh at 0x18c is set from
// data_00217360 and the item at 0x184 updated, else below 100 only the mesh, and 0x190 is cleared.
void Object_000D8A40::func_000D8690()
{
    if (!(owner->flags & 0x80) && owner->value_5c == 0.0f && owner->value_60 == 0.0f) {
        value_130 = 0;
        value_120 = 0;
        value_174 = 0;
        value_164 = 0;
    } else {
        Vector3 points[2];
        points[0] = owner->position;
        points[0].y += 3.0f;
        points[1] = base;
        points[1].y -= 1.0f;
        data_0022FCE8.func_00017CC0(&box, points, 2);
        data_0022FCE8.func_00016260(&item_0fc, -1);
    }
    if (owner->value_70 < 80.0f && !(owner->flags & 0x1000000)) {
        data_0022FCE8.func_00019570(mesh, &data_00217360);
        data_0022FCE8.func_000162A0(&item_184);
        return;
    }
    if (owner->value_70 < 100.0f) {
        data_0022FCE8.func_00019570(mesh, &data_00217360);
    }
    value_190 = 0;
}
