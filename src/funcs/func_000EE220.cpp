/* sym: ?func_00011C80_1@Object_000EDC30@@UAEXH@Z = 0x000EE220 */
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
struct Shape_000EDF40 {
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
    Shape_000EDF40 *shape;
    char unknown_10[0x14];
    unsigned int flags;
    char unknown_28[0x34];
    int value_5c;
    char unknown_60[0x14];
    float value_74;
    float value_78;
    float value_7c;
    char unknown_80[8];
    int value_88;
    int value_8c;

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

void func_001BA9C0();
void __fastcall func_001BAA50();
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
struct Ranges_000EDF40 {
    char unknown_00[0xc];
    float nearDepth;
    float middleDepth;
    float farDepth;
};

// The models at 0xe8.
struct Holder_000EDC30 {
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
    Ranges_000EDF40 *ranges;
    char unknown_34[0x34];
    int pending;
};

// The class whose table is at 0x1CEFA8 (constructor func_000EDC30).
struct Object_000EDC30 : Object_000CD1E0 {
    virtual void func_00011C80(int pass);
    virtual void func_00011C80_1(int pass);

    char unknown_06c[0x54];
    Sphere_0005BCE0 sphere;
    int kind;
    char unknown_0d4[0x20];
    Holder_000EDC30 *holder;
    char unknown_0f8[4];
    void *handle_0fc;
    char unknown_100[0x254];
    int effect_354;
    int effect_358;
    int effect_35c;
    float size_360;
    float size_364;
    float value_368;
    int value_36c;
    int value_370;
    float value_374;
    int key_378;
    Vector3 position;
    int angles[3];
    void *data_394;
    int value_398;
};

// Slot 3, slot 2's drawing without the key, the block or the data: pass 2 puts the sphere at 0xc0 on model 0's
// bounds and gives the owner its depth. Pass 3 turns by the owner's angles and picks model 0's detail kind at 0xd0
// (func_000C1340 with the distances at 0x30); kinds 1 and 2 show it, 3 hides it, any other sets the owner's flag
// 0x400000. Then the effects at 0x354 and 0x358 (unless the owner's flag 0x2000000), the doubled sizes at 0x360 and
// the values at 0x36c and 0x2c draw it; with the owner's flag 0x2000000 model 1 draws at 0x37c with its angles at
// 0x388 and the effect at 0x35c (unless flag 0x1000). Passes 17 and 18 draw model 3 for kinds 1 and 2.
void Object_000EDC30::func_00011C80_1(int pass)
{
    func_001BAAA0(&owner->position.x);
    switch (pass) {
    case 2:
        func_001BAB20(&sphere.center, &holder->models[0]->shape->bounds.center);
        owner->depth = sphere.center.z;
        break;
    case 3: {
        func_001BB330(owner->heading + 0x8000);
        func_001BB2E0(owner->pitch);
        func_001BB380(owner->roll);
        Object_00047470 *model = holder->models[0];
        kind = data_00257CE8->func_000C1340(model, &sphere, ranges->nearDepth, ranges->middleDepth,
                                            ranges->farDepth);
        if (kind == 1) {
            model->flags |= 0x10;
        } else if (kind == 2) {
            model->flags |= 0x10;
        } else if (kind == 3) {
            model->flags &= ~0x10;
        } else {
            owner->flags |= 0x400000;
            return;
        }
        owner->flags &= ~0x400000;
        if (!(owner->flags & 0x2000000)) {
            data_00257CE8->func_000C1770(effect_354);
            data_00257CE8->func_000C1770(effect_358);
        }
        model->value_74 = size_360 + size_360;
        model->value_78 = size_364 + size_364;
        model->value_88 = value_36c;
        model->value_8c = value_370;
        model->value_5c = value_2c;
        model->slot5(0, 0);
        if (owner->flags & 0x2000000) {
            Object_00047470 *other = holder->models[1];
            func_001BAA50();
            func_001BA9C0();
            func_001BAAA0(&position.x);
            func_001BB330(angles[1] + 0x8000);
            func_001BB2E0(angles[0]);
            func_001BB380(angles[2]);
            if (!(owner->flags & 0x1000)) {
                data_00257CE8->func_000C1770(effect_35c);
            }
            other->value_74 = value_368;
            other->value_7c = value_374;
            other->value_5c = value_2c;
            other->slot5(0, 0);
            func_001BAA50();
            func_001BA9C0();
        }
        break;
    }
    case 17:
    case 18:
        if ((kind == 1 || kind == 2) && (pass == 17 || pass == 18)) {
        func_001BB330(owner->heading + 0x8000);
        func_001BB2E0(owner->pitch);
        func_001BB380(owner->roll);
            holder->models[3]->slot5(0, 0);
        }
        break;
    }
}
