/* sym: ?func_00011C80_1@Object_000D6350@@UAEXH@Z = 0x000D6830 */
struct Frame_000479D0;
struct Vector3 {
    float x;
    float y;
    float z;
};

struct Sphere_0005BCE0 {
    Vector3 center;
    float radius;
};

// The part at 0xc of a model: a point at 0x54.
struct Part_000D6830 {
    char unknown_00[0x54];
    Vector3 point;
};

struct Object_00047470 {
    virtual ~Object_00047470();
    virtual void slot1();
    virtual void func_00047470(void *first, void *second, Frame_000479D0 *frame);
    virtual void slot3();
    virtual void func_00047540();
    virtual void func_00047690(int first, int second);

    char unknown_04[8];
    Part_000D6830 *part;
    char unknown_10[0x4c];
    int value_5c;
    char unknown_60[0x14];
    int value_74;
    char unknown_78[4];
    int value_7c;
};

// The object at data_00257CE8 (func_00157F10 is the engine's).
struct Object_00157F10 {
    int func_000C1340(Object_00047470 *model, Sphere_0005BCE0 *sphere, float nearDepth, float farDepth, float scale);
};

extern Object_00157F10 *data_00257CE8;

void __fastcall func_001BAAA0(float *vector);
void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);
void __fastcall func_001BB2E0(int angle);
void __fastcall func_001BB330(int angle);
void __fastcall func_001BB380(int angle);

// The object a behaviour serves.
struct Owner_000D6830 {
    char unknown_00[0x10];
    float depth;
    char unknown_14[0x30];
    Vector3 position;
    int angles[3];
};

// The limits at 0x30: the depths and scale func_000C1340 takes (0xc, 0x10, 0x14).
struct Limits_000D6830 {
    char unknown_00[0xc];
    float nearDepth;
    float farDepth;
    float scale;
};

// The two models at 0xec.
struct Models_000D6830 {
    Object_00047470 *model;
    Object_00047470 *shadow;
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

    Owner_000D6830 *owner;
    int state;
    int unknown_0c;
    int unknown_10;
    char unknown_14[0xc];
    int unknown_20[3];
    int value_2c;
    Limits_000D6830 *limits;
    char unknown_34[4];
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

    char unknown_06c[0x64];
    Sphere_0005BCE0 sphere;
    int visible;
    char unknown_0e4[8];
    Models_000D6830 *models;
    char unknown_0f0[0x1c0];
    int value_2b0;
    int value_2b4;
};

// Slot 3: in the owner's frame. Pass 2: the sphere's centre at 0xd0 from the model's point at 0x54 of its part, its
// depth handed to the owner. Pass 3: turned by the owner's angles, the model's visibility at 0xe0 from func_000C1340
// with the limits at 0x30; when visible, the model takes 0x2b0, 0x2b4 and 0x2c and is drawn (slot 5). Passes 15 and
// 16: while visible (1 or 2), the shadow at 0xec+4 is drawn the same way.
void Object_000D6350::func_00011C80_1(int argument)
{
    func_001BAAA0(&owner->position.x);
    switch (argument) {
    case 3: {
        Object_00047470 *model = models->model;
        func_001BB330(owner->angles[1] + 0x8000);
        func_001BB2E0(owner->angles[0]);
        func_001BB380(owner->angles[2]);
        visible = data_00257CE8->func_000C1340(model, &sphere, limits->nearDepth, limits->farDepth, limits->scale);
        if (visible) {
            model->value_74 = value_2b0;
            model->value_7c = value_2b4;
            model->value_5c = value_2c;
            model->func_00047690(0, 0);
        }
        return;
    }
    case 2:
        func_001BAB20(&sphere.center, &models->model->part->point);
        owner->depth = sphere.center.z;
        return;
    case 15:
    case 16:
        if (visible == 1 || visible == 2) {
            func_001BB330(owner->angles[1] + 0x8000);
            func_001BB2E0(owner->angles[0]);
            func_001BB380(owner->angles[2]);
            models->shadow->func_00047690(0, 0);
        }
        return;
    }
}
