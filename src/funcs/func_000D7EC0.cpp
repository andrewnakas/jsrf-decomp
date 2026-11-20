/* sym: ?func_00011C80@Object_000D8A40@@UAEXH@Z = 0x000D7EC0 */
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
struct Shape_000D7EC0 {
    char unknown_00[0x54];
    Sphere_0005BCE0 bounds;
};

struct Object_00047470 {
    virtual ~Object_00047470();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5(void *data, int argument);
    virtual void slot6(Object_00047470 *model);

    char unknown_04[8];
    Shape_000D7EC0 *shape;
    char unknown_10[0x14];
    unsigned int flags;
    char unknown_28[0x30];
    float scale;
    int value_5c;
    char unknown_60[0x14];
    int value_74;
    char unknown_78[4];
    int value_7c;
};

struct Device_00251D6C {
    virtual void __stdcall slot0();
    virtual void __stdcall slot1();
    virtual void __stdcall slot2();
    virtual void __stdcall slot3();
    virtual void __stdcall slot4();
    virtual void __stdcall slot5();
    virtual void __stdcall slot6();
    virtual void __stdcall slot7();
    virtual void __stdcall slot8();
    virtual void __stdcall slot9();
    virtual void __stdcall slot10();
    virtual void __stdcall slot11();
    virtual void __stdcall slot12();
    virtual void __stdcall slot13();
    virtual void __stdcall slot14();
    virtual void __stdcall slot15();
    virtual void __stdcall slot16();
    virtual void __stdcall slot17();
    virtual void __stdcall slot18();
    virtual void __stdcall slot19();
    virtual void __stdcall slot20();
    virtual void __stdcall slot21();
    virtual void __stdcall slot22();
    virtual void __stdcall slot23();
    virtual void __stdcall slot24();
    virtual void __stdcall slot25();
    virtual void __stdcall slot26();
    virtual void __stdcall slot27();
    virtual void __stdcall slot28();
    virtual void __stdcall slot29();
    virtual void __stdcall slot30();
    virtual void __stdcall slot31();
    virtual void __stdcall slot32();
    virtual void __stdcall slot33();
    virtual void __stdcall slot34();
    virtual void __stdcall slot35();
    virtual void __stdcall slot36();
    virtual void __stdcall slot37();
    virtual void __stdcall slot38();
    virtual void __stdcall slot39();
    virtual void __stdcall slot40();
    virtual void __stdcall slot41();
    virtual void __stdcall slot42();
    virtual void __stdcall slot43();
    virtual void __stdcall slot44();
    virtual void __stdcall slot45();
    virtual void __stdcall slot46();
    virtual void __stdcall slot47();
    virtual void __stdcall slot48();
    virtual void __stdcall slot49();
    virtual void __stdcall slot50();
    virtual void __stdcall slot51();
    virtual void __stdcall slot52();
    virtual void __stdcall slot53();
    virtual void __stdcall slot54();
    virtual void __stdcall slot55();
    virtual void __stdcall slot56();
    virtual void __stdcall slot57();
    virtual void __stdcall slot58();
    virtual void __stdcall slot59();
    virtual void __stdcall slot60();
    virtual void __stdcall slot61();
    virtual void __stdcall slot62();
    virtual void __stdcall slot63();
    virtual void __stdcall slot64();
    virtual void __stdcall slot65();
    virtual void __stdcall slot66();
    virtual void __stdcall slot67();
    virtual void __stdcall slot68();
    virtual void __stdcall slot69();
    virtual void __stdcall slot70();
    virtual void __stdcall slot71();
    virtual void __stdcall slot72();
    virtual void __stdcall slot73();
    virtual void __stdcall slot74(int first, int second);
};
extern Device_00251D6C *data_00251D6C;

struct Object_00157F10 {
    int func_000C1340(Object_00047470 *model, Sphere_0005BCE0 *sphere, float nearDepth, float middleDepth,
                      float farDepth);
    void func_000C1690(int key);
    void func_000C1730(int *key);
    void func_000C1770(int key);
};

extern Object_00157F10 *data_00257CE8;

// The object at data_00257CE4: an angle at 0xc8.
struct Object_000C1270 {
    char unknown_00[0xc8];
    int angle;
};

extern Object_000C1270 *data_00257CE4;

// The owner at 0x4: depth at 0x10, position at 0x44, heading at 0x54, flags at 0xa4.
struct Object_000C5B50 {
    char unknown_00[0x10];
    float depth;
    char unknown_14[0x30];
    Vector3 position;
    int pitch;
    int heading;
    char unknown_58[0x4c];
    unsigned int flags;
};

void func_001BA9C0();
void __fastcall func_001BAA50();
void __fastcall func_001BAAA0(float *vector);
void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);
void __fastcall func_001BB330(int angle);

// The base with a pure slot 0 (table 0x1CE304, destructor func_000E7EB0).
struct Object_000CC600 {
    virtual void func_000CD1E0() = 0;
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_1(int argument);
    virtual ~Object_000CC600() {}
};

// The class whose table is at 0x1CE63C (constructor func_000D8A40).
struct Object_000D8A40 : Object_000CC600 {
    virtual void func_000CD1E0();
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_1(int argument);
    virtual ~Object_000D8A40();

    Object_000C5B50 *owner;
    char unknown_008[0x24];
    int value_2c;
    char unknown_030[0x44];
    Sphere_0005BCE0 sphere;
    char unknown_084[4];
    int kind;
    char unknown_08c[4];
    float scale;
    char unknown_094[0x10];
    Object_00047470 **models;
    Object_00047470 *shadow;
    int part;
    char unknown_0b0[0x10];
    void *handle_c0;
    char unknown_0c4[0xf4];
    int value_1b8;
    int value_1bc;
    int value_1c0;
    int key_1c4;
    int value_1c8;
};

// Slot 2, drawing at the owner's place: pass 7 puts the sphere at 0x74 on the model's bounds and gives the owner its
// depth; pass 8 takes the key at 0x1c4 (made first when 0x1c8 is set), turns by the owner's heading, picks the detail
// kind at 0x88 (func_000C1340: 100, 500, 700), shows the model and part 0xac for kinds 1 and 2, copies the values at
// 0x1bc/0x1c0, the scale and 0x2c into them, draws both, and draws the shadow at 0xa8 between render states 0x306
// and 0x302/0x303.
void Object_000D8A40::func_00011C80(int pass)
{
    func_001BAAA0(&owner->position.x);
    switch (pass) {
    case 8: {
        if (value_1c8) {
            data_00257CE8->func_000C1730(&key_1c4);
            value_1c8 = 0;
        }
        data_00257CE8->func_000C1690(key_1c4);
        Object_00047470 *model = models[0];
        func_001BA9C0();
        func_001BB330(owner->heading + 0x8000);
        kind = data_00257CE8->func_000C1340(model, &sphere, 100.0f, 500.0f, 700.0f);
        if (!kind) {
            func_001BAA50();
            return;
        }
        if (kind == 1) {
            model->flags |= 0x10;
            models[part]->flags &= ~0x10;
            models[part]->flags |= 0x10;
        } else if (kind == 2) {
            model->flags |= 0x10;
            models[part]->flags &= ~0x10;
            models[part]->flags |= 0x10;
        } else {
            model->flags &= ~0x10;
            models[part]->flags &= ~0x10;
        }
        if (owner->flags & 0x8000) {
            data_00257CE8->func_000C1770(value_1b8);
        }
        model->value_74 = value_1bc;
        model->value_7c = value_1c0;
        model->scale = scale * model->scale;
        model->value_5c = value_2c;
        model->slot5(handle_c0, 0);
        models[part]->scale = model->scale;
        models[part]->value_5c = value_2c;
        models[part]->slot6(model);
        func_001BAA50();
        if (shadow && (kind == 2 || kind == 1)) {
            data_00251D6C->slot74(0x306, 0);
            func_001BB330(data_00257CE4->angle);
            shadow->slot5(0, 0);
            data_00251D6C->slot74(0x302, 0x303);
        }
        break;
    }
    case 7:
        func_001BAB20(&sphere.center, &models[0]->shape->bounds.center);
        owner->depth = sphere.center.z;
        break;
    }
}
