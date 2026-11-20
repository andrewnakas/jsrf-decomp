/* sym: ?func_00011C80_1@Object_000E7F50@@UAEXH@Z = 0x000E8500 */
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
struct Shape_000E8280 {
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

    char unknown_04[8];
    Shape_000E8280 *shape;
    char unknown_10[0x14];
    unsigned int flags;
    char unknown_28[0x4c];
    int value_74;
    char unknown_78[4];
    int value_7c;

    void func_00047970(void *data, int argument);
    void func_000480C0(unsigned int index);
};

struct Object_00157F10 {
    int func_000C1340(Object_00047470 *model, Sphere_0005BCE0 *sphere, float nearDepth, float middleDepth,
                      float farDepth);
    void func_000C1690(int key);
    void func_000C1730(int *key);
    void func_000C1770(int key);
};

extern Object_00157F10 *data_00257CE8;

void __fastcall func_001BAAA0(float *vector);
void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);
void __fastcall func_001BB2E0(int angle);
void __fastcall func_001BB330(int angle);
void __fastcall func_001BB380(int angle);

// The owner at 0x4: depth at 0x10, position at 0x44, angles at 0x50, flags at 0xa4.
struct Object_000C5B50 {
    char unknown_00[0x10];
    float depth;
    char unknown_14[0x30];
    Vector3 position;
    int pitch;
    int heading;
    int roll;
    char unknown_5c[0x48];
    unsigned int flags;
};

// What 0x30 points at: the three detail distances at 0xc.
struct Ranges_000E8280 {
    char unknown_00[0xc];
    float nearDepth;
    float middleDepth;
    float farDepth;
};

// The models at 0xe8.
struct Holder_000E7F50 {
    Object_00047470 *models[4];
};

// What 0xec points at: data at 0x10.
struct Source_000E7F50 {
    char unknown_00[0x10];
    void *data;
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
    char unknown_08[0x28];
    Ranges_000E8280 *ranges;
    char unknown_34[0x34];
    int pending;
};

// The class whose table is at 0x1CEE44 (destructor func_000E8170).
struct Object_000E7F50 : Object_000CD1E0 {
    virtual void func_00011C80(int pass);
    virtual void func_00011C80_1(int pass);

    char unknown_06c[0x64];
    Sphere_0005BCE0 sphere;
    int kind;
    char unknown_0e4[4];
    Holder_000E7F50 *holder;
    Source_000E7F50 *source;
    void *handle_0f0;
    char unknown_0f4[0xc];
    int value_100;
    char unknown_104[0x1a8];
    int effect_2ac;
    int value_2b0;
    int value_2b4;
    int key_2b8;
};

// Slot 3, the draw passes at the owner's place. Pass 3 turns model 0 by the owner's angles, picks its detail kind at
// 0xe0 (func_000C1340 with the distances at 0x30), shows it for kinds 1 and 2 and hides it for 3, gives it the values
// at 0x2b0/0x2b4 and draws it. Pass 2 puts the sphere at 0xd0 on its bounds and gives the owner its depth; pass 13
// (with a kind) poses model 0 (part 4) and draws model 2; passes 17 and 18 draw model 1 for kinds 1 and 2.
void Object_000E7F50::func_00011C80_1(int pass)
{
    func_001BAAA0(&owner->position.x);
    switch (pass) {
    case 3: {
        Object_00047470 *model = holder->models[0];
        func_001BB330(owner->heading + 0x8000);
        func_001BB2E0(owner->pitch);
        func_001BB380(owner->roll);
        kind = data_00257CE8->func_000C1340(model, &sphere, ranges->nearDepth, ranges->middleDepth,
                                            ranges->farDepth);
        if (kind == 1) {
            model->flags |= 0x10;
        } else if (kind == 2) {
            model->flags |= 0x10;
        } else if (kind == 3) {
            model->flags &= ~0x10;
        } else {
            return;
        }
        model->value_74 = value_2b0;
        model->value_7c = value_2b4;
        model->slot5(0, 0);
        break;
    }
    case 2:
        func_001BAB20(&sphere.center, &holder->models[0]->shape->bounds.center);
        owner->depth = sphere.center.z;
        break;
    case 13:
        if (!kind) {
            return;
        }
        func_001BB330(owner->heading + 0x8000);
        func_001BB2E0(owner->pitch);
        func_001BB380(owner->roll);
        holder->models[0]->func_00047970(0, 0);
        holder->models[0]->func_000480C0(4);
        holder->models[2]->slot5(source->data, value_100);
        break;
    case 17:
    case 18:
        if (kind == 1 || kind == 2) {
            func_001BB330(owner->heading + 0x8000);
            func_001BB2E0(owner->pitch);
            func_001BB380(owner->roll);
            holder->models[1]->slot5(0, 0);
        }
        break;
    }
}
