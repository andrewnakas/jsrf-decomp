/* sym: ?func_00011C80@Object_000E0440@@UAEXH@Z = 0x000E0710 */
struct Vector3 {
    float x;
    float y;
    float z;
};

struct Sphere_0005BCE0 {
    Vector3 center;
    float radius;
};

// The shape at 0xc of a model: its bounds at 0x54.
struct Shape_000E0710 {
    char unknown_00[0x54];
    Sphere_0005BCE0 bounds;
};

struct Object_00047470 {
    virtual ~Object_00047470();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5(void *data, int value);
    virtual void slot6(Object_00047470 *model);

    char unknown_04[8];
    Shape_000E0710 *shape;
    char unknown_10[0x14];
    unsigned int flags;
    char unknown_28[0x30];
    float scale;
    int value_5c;
    char unknown_60[0x14];
    int value_74;
    char unknown_78[4];
    int value_7c;

    void func_00047970(void *data, int argument);
    void func_000480C0(unsigned int index);
    void func_00048000();
};

struct Object_00157F10 {
    int func_000C1340(Object_00047470 *model, Sphere_0005BCE0 *sphere, float nearDepth, float middleDepth,
                      float farDepth);
    void func_000C1690(int key);
    void func_000C1730(int *key);
    void func_000C1770(int key);
};

extern Object_00157F10 *data_00257CE8;

void func_001BA9C0();
void __fastcall func_001BAA50();
void __fastcall func_001BAAA0(float *vector);
void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);
void __fastcall func_001BAC50(int *angles, int flags);

// The owner at 0x4: depth at 0x10, position at 0x44, angles at 0x50, flags at 0xa4.
struct Object_000C5B50 {
    char unknown_00[0x10];
    float depth;
    char unknown_14[0x30];
    Vector3 position;
    int angles[3];
    char unknown_5c[0x48];
    unsigned int flags;
};

// What 0x30 points at: the three detail distances at 0xc.
struct Ranges_000E0710 {
    char unknown_00[0xc];
    float nearDepth;
    float middleDepth;
    float farDepth;
};

// The models at 0xe8.
struct Holder_000E0440 {
    Object_00047470 *models[4];
};

struct Object_000CC600 {
    virtual void func_000CD1E0() = 0;
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_1(int argument);
    virtual ~Object_000CC600();
};

struct Object_000CD1E0 : Object_000CC600 {
    Object_000C5B50 *owner;
    char unknown_08[0x24];
    int value_2c;
    Ranges_000E0710 *ranges;
    char unknown_34[0x34];
    int pending;
};

// The class whose table is at 0x1CE804 (destructor func_000E05E0).
struct Object_000E0440 : Object_000CD1E0 {
    virtual void func_00011C80(int pass);
    virtual void func_00011C80_1(int pass);

    char unknown_06c[0x1c];
    int kind;
    char unknown_08c[0x18];
    Sphere_0005BCE0 sphere;
    char unknown_0b4[4];
    Holder_000E0440 *holder;
    char unknown_0bc[4];
    void *handle_0c0;
    char unknown_0c4[0x4c];
    int effect_110;
    int value_114;
    int value_118;
    int key_11c;
};

// Slot 2, the draw passes (none with the owner's flag 0x8000000). Without its flag 0x1000000 the frame is the
// owner's position and angles (func_001BAC50); model 0 takes the block at 0xc0. Pass 3 clears the owner's flag
// 0x400000, takes the key at 0x11c (made first when 0x68 is set), the effect at 0x110, the values at 0x114/0x118 and
// 0x2c, and draws model 0 and then model 1 at its scale; pass 2 gives the owner the depth of model 0's part-1 point;
// passes 17 and 18 draw model 2.
void Object_000E0440::func_00011C80(int pass)
{
    unsigned int flags = owner->flags;
    if (flags & 0x8000000) {
        return;
    }
    if (!(flags & 0x1000000)) {
        func_001BAAA0(&owner->position.x);
        func_001BAC50(owner->angles, 0);
    }
    holder->models[0]->func_00047970(handle_0c0, 0);
    switch (pass) {
    case 3: {
        Object_00047470 *model = holder->models[0];
        owner->flags &= ~0x400000;
        model->func_000480C0(0);
        if (pending) {
            data_00257CE8->func_000C1730(&key_11c);
            pending = 0;
        }
        data_00257CE8->func_000C1690(key_11c);
        data_00257CE8->func_000C1770(effect_110);
        model->value_74 = value_114;
        model->value_7c = value_118;
        model->value_5c = value_2c;
        model->func_00048000();
        model->slot6(model);
        holder->models[1]->scale = model->scale;
        holder->models[1]->slot6(model);
        break;
    }
    case 2:
        holder->models[0]->func_000480C0(1);
        func_001BAB20(&sphere.center, 0);
        owner->depth = sphere.center.z;
        break;
    case 17:
    case 18:
        holder->models[2]->slot6(holder->models[0]);
        break;
    }
}
