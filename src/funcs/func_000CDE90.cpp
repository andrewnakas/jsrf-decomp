/* sym: ?func_00011C80_1@Object_000CE9D0@@UAEXH@Z = 0x000CDE90 */
struct Frame_000479D0;
struct Vector3 {
    float x;
    float y;
    float z;
};

struct Angles_000C1300 {
    int x;
    int y;
    int z;
};

void __fastcall func_001BAAA0(float *vector);
void __fastcall func_001BB330(int angle);
void func_001BB2B0(float scale);
void __fastcall func_001BAA50();
void func_001BA9C0();

// The object a behaviour serves: its position at 0x44 and angles at 0x50.
struct Object_000C5B50 {
    char unknown_00[0x44];
    Vector3 position;
    Angles_000C1300 angles;
};

struct Surface_000476F0;

// The models' base (tables 0x1CA490, 0x1CAA8C, 0x1CC12C): slot 5 poses the model, slot 6 draws it.
struct Object_00047470 {
    virtual ~Object_00047470();
    virtual void slot1();
    virtual void func_00047470(void *first, void *second, Frame_000479D0 *frame);
    virtual void slot3();
    virtual void func_00047540();
    virtual void func_00047690(int first, int second);
    virtual void func_00047820(int argument);

    Surface_000476F0 *surface;
    char unknown_08[0x54];
    float frame;
    char unknown_60[0x14];
    int value_74;
    char unknown_78[4];
    int value_7c;
};

struct Object_00015D50 {
    virtual ~Object_00015D50();

    void func_00015F90();
};

// The base with a pure slot 0 (table 0x1CE304).
struct Object_000CC600 {
    virtual void func_000CD1E0() = 0;
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_1(int argument);
    virtual ~Object_000CC600() {}
};

// The behaviour func_000CE9D0 builds (0x140 bytes, table 0x1CE3A0); 0x4 holds the object it serves.
struct Object_000CE9D0 : Object_000CC600 {
    virtual void func_000CD1E0();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_1(int argument);
    virtual ~Object_000CE9D0();

    Object_000C5B50 *owner;
    int state;
    char unknown_0c[0x20];
    float frame;
    char unknown_30[0x14];
    int pose;
    char unknown_48[0x10];
    Object_00047470 **models;
    Object_00047470 *shadow;
    Object_00015D50 *first;
    Object_00015D50 *second;
    char unknown_68[0xac];
    int value_114;
    int value_118;
};

// Slot 3: draws at the owner's position, turned half round from its angle, at scale 2 (func_001BAAA0,
// func_001BB330, func_001BB2B0). Pass 0 poses the body for the pose at 0x44 (model 0, 1, or 2 with the values at
// 0x114 and 0x118) at the frame at 0x2c, draws the shadow at 0x5c and models 8 and 9 (10 and 11 in state 6) on it,
// then the effects at 0x60 and 0x64 (func_00015F90) between func_001BAA50 and func_001BA9C0. Passes 0x11 and 0x12
// draw model 3 on model 0.
void Object_000CE9D0::func_00011C80_1(int argument)
{
    func_001BAAA0(&owner->position.x);
    func_001BB330(owner->angles.y + 0x8000);
    func_001BB2B0(2.0f);
    switch ((unsigned int)argument) {
    case 0: {
        Object_00047470 *body;
        if (pose == 0) {
            body = models[0];
        } else if (pose == 1) {
            body = models[1];
        } else {
            body = models[2];
            body->value_74 = value_114;
            body->value_7c = value_118;
        }
        body->frame = frame;
        body->func_00047690(0, 0);
        shadow->frame = frame;
        shadow->func_00047820((int)body);
        if (state != 6) {
            models[8]->frame = frame;
            models[9]->frame = frame;
            models[8]->func_00047820((int)body);
            models[9]->func_00047820((int)body);
        } else {
            models[10]->frame = frame;
            models[11]->frame = frame;
            models[10]->func_00047820((int)body);
            models[11]->func_00047820((int)body);
        }
        func_001BAA50();
        first->func_00015F90();
        second->func_00015F90();
        func_001BA9C0();
        break;
    }
    case 0x11:
    case 0x12:
        models[3]->func_00047820((int)models[0]);
        break;
    }
}
