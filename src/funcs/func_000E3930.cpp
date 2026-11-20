/* sym: ?func_00011C80@Object_000E45D0@@UAEXH@Z = 0x000E3930 */
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
struct Shape_000E3930 {
    char unknown_00[0x54];
    Sphere_0005BCE0 bounds;
};

struct Matrix_001BA950 {
    float m[4][4];
};

struct Object_00047470 {
    virtual ~Object_00047470();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5(void *data, int value);

    char unknown_04[8];
    Shape_000E3930 *shape;
    char unknown_10[0x14];
    unsigned int flags;
    char unknown_28[0x34];
    int value_5c;
    char unknown_60[0x14];
    int value_74;
    char unknown_78[4];
    int value_7c;

    void func_00047970(void *data, int argument);
    void func_000480C0(unsigned int index);
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
    virtual int __stdcall slot39(const Sphere_0005BCE0 *sphere);
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

// A point in the model's frame.
extern Vector3 data_00218ACC;

void func_001BA9C0();
void __fastcall func_001BA8F0(Matrix_001BA950 *matrix);
void __fastcall func_001BA950(Matrix_001BA950 *matrix);
void __fastcall func_001BAA50();
void __fastcall func_001BAAA0(float *vector);
void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);
void __fastcall func_001BB2E0(int angle);
void __fastcall func_001BB330(int angle);
void __fastcall func_001BB380(int angle);

// The models at 0x164.
struct Holder_000E45D0 {
    Object_00047470 *models[5];
};

// What 0x168 points at: data at 0x8.
struct Source_000E45D0 {
    char unknown_00[8];
    void *data;
};

struct Node {
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

// The class whose tables are at 0x1CED20 (Node) and 0x1CED18 (Object_000C60C0 at +0x44).
struct Object_000E45D0 : Node, Object_000C60C0 {
    virtual void func_00011C80(int pass);
    virtual void func_00011C80_3(int pass);

    Vector3 position;
    int pitch;
    int heading;
    int roll;
    char unknown_060[0x18];
    Sphere_0005BCE0 sphere;
    int value_88;
    char unknown_08c[4];
    unsigned int flags_90;
    char unknown_094[4];
    int key_98;
    int pending;
    char unknown_0a0[0x64];
    Matrix_001BA950 matrix;
    char unknown_144[8];
    Sphere_0005BCE0 point;
    char unknown_15c[8];
    Holder_000E45D0 *holder;
    Source_000E45D0 *source;
    void *handle_16c;
    char unknown_170[4];
    int value_174;
    char unknown_178[0xa0];
    int effect_218;
    int value_21c;
    int value_220;
};

// Slot 3, slot 12's drawing with the key, the block and the effect: pass 13 (without flag 0x2000) turns by the
// angles at 0x54, draws model 4 with the source at 0x168 and 0x174, then model 2 in the frame at 0x104 with render
// state 0x302. Pass 8 takes the key at 0x98 (made first when 0x9c is set), turns, poses model 0 (model 1 with flag
// 0x2000) with the block at 0x16c and part 2, keeps the point data_00218ACC of the frame at 0x14c and sets flag
// 0x1000000 unless it is nearer than 600 and in view, picks the detail kind (func_000C1340: 300, 500, 700), shows
// the model for kinds 1 and 2, gives it 0x21c/0x220 and 0x88, draws it and runs the effect at 0x218. Pass 7 puts the
// sphere at 0x78 on model 0's bounds and gives the node its depth.
void Object_000E45D0::func_00011C80(int pass)
{
    func_001BAAA0(&position.x);
    switch (pass) {
    case 13:
        if (flags_90 & 0x2000) {
            return;
        }
        func_001BB330(heading + 0x8000);
        func_001BB2E0(pitch);
        func_001BB380(roll);
        holder->models[4]->slot5(source->data, value_174);
        func_001BA8F0(&matrix);
        data_00251D6C->slot74(0x302, 1);
        holder->models[2]->slot5(0, 0);
        data_00251D6C->slot74(0x302, 0x303);
        break;
    case 8: {
        if (pending) {
            data_00257CE8->func_000C1730(&key_98);
            pending = 0;
        }
        data_00257CE8->func_000C1690(key_98);
        func_001BB330(heading + 0x8000);
        func_001BB2E0(pitch);
        func_001BB380(roll);
        Object_00047470 *model;
        if (!(flags_90 & 0x2000)) {
            model = holder->models[0];
        } else {
            model = holder->models[1];
        }
        func_001BA9C0();
        model->func_00047970(handle_16c, 0);
        model->func_000480C0(2);
        func_001BAAA0(&data_00218ACC.x);
        func_001BA950(&matrix);
        func_001BAB20(&point.center, 0);
        func_001BAA50();
        if (!(point.center.z > 600.0f) && data_00251D6C->slot39(&point)) {
            flags_90 &= ~0x1000000;
        } else {
            flags_90 |= 0x1000000;
        }
        int kind = data_00257CE8->func_000C1340(model, &sphere, 300.0f, 500.0f, 700.0f);
        if (!kind) {
            return;
        }
        if (kind == 1) {
            model->flags |= 0x10;
        } else if (kind == 2) {
            model->flags |= 0x10;
        } else {
            model->flags &= ~0x10;
        }
        model->value_74 = value_21c;
        model->value_7c = value_220;
        model->value_5c = value_88;
        model->slot5(handle_16c, 0);
        model->func_000480C0(2);
        data_00257CE8->func_000C1770(effect_218);
        break;
    }
    case 7:
        func_001BAB20(&sphere.center, &holder->models[0]->shape->bounds.center);
        depth = sphere.center.z;
        break;
    }
}
