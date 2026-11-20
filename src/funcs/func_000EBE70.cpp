/* sym: ?func_00011C80@Object_000ECB50@@UAEXH@Z = 0x000EBE70 */
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
struct Shape_000EBE70 {
    char unknown_00[0x54];
    Sphere_0005BCE0 bounds;
};

struct Matrix_001BA950;

struct Object_00047470 {
    virtual ~Object_00047470();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5(int first, int second);
    virtual void slot6(Object_00047470 *model);

    char unknown_04[8];
    Shape_000EBE70 *shape;
    char unknown_10[0x10];
    Matrix_001BA950 *matrix;
    unsigned int flags;
    char unknown_28[0x34];
    int value_5c;

    void func_00047970(void *data, int argument);
    void func_000480C0(unsigned int index);
    void func_00048000();
};

struct Target_000EBC60;

// The part at 0xbc (built by func_000EB830).
struct Part_000EB830 {
    void func_000EBC60(Target_000EBC60 *target);

    char unknown_00[0x6c];
};

// The same part seen by func_000EBCF0.
struct Object_000EBB80 {
    void func_000EBCF0(Object_00047470 *model);
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
    virtual void __stdcall slot66(int value);
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
    void func_000C1690(int key);
    void func_000C1730(int *key);
};

extern Object_00157F10 *data_00257CE8;

void __fastcall func_001BA8F0(Matrix_001BA950 *matrix);
void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);

// The owner at 0xb0: flags at 0xa4.
struct Owner_000EBE70 {
    char unknown_00[0xa4];
    unsigned int flags;
};

// What 0x144 points at: a value at 0x4c.
struct Source_000EBE70 {
    char unknown_00[0x4c];
    int value;
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

// The class whose tables are at 0x1CEF20 (Node) and 0x1CEF18 (Object_000C60C0 at +0x44).
struct Object_000ECB50 : Node, Object_000C60C0 {
    virtual void func_00011C80(int pass);
    virtual void func_00011C80_3(int pass);

    char unknown_048[0x30];
    Sphere_0005BCE0 sphere;
    int value_88;
    char unknown_08c[0x10];
    int pending;
    char unknown_0a0[0x10];
    Owner_000EBE70 *owner;
    char unknown_0b4[8];
    Part_000EB830 part;
    char unknown_128[0x14];
    Object_00047470 **models;
    Object_00047470 *model;
    Source_000EBE70 *source;
    char unknown_148[8];
    void *block_150;
    char unknown_154[0xc];
    int value_160;
    char unknown_164[0x210];
    int key_374;
};

// Slot 3, the draw passes. Pass 0 sets the model at 0x140 up with the block at 0x150, puts the sphere at 0x78 on its
// bounds, shows it nearer than 600, gives it the part's sizes (func_000EBC60) and 0x88 and draws it; a pending key
// at 0x374 is made first (func_000C1730). With the owner's flag 0x4000000 model 7 draws it, else the key's part
// draws (func_000C1690, func_000EBCF0). Pass 13 (without that flag) draws through models 2 and 4 with render state
// 0x302; pass 12 gives the node the sphere's depth; passes 17 and 18 draw through model 1.
void Object_000ECB50::func_00011C80(int pass)
{
    switch (pass) {
    case 0: {
        Object_00047470 *drawn = model;
        drawn->func_00047970(block_150, 0);
        drawn->func_000480C0(0);
        func_001BAB20(&sphere.center, &models[0]->shape->bounds.center);
        if (sphere.center.z < 600.0f) {
            drawn->flags |= 0x10;
        } else {
            drawn->flags &= ~0x10;
        }
        part.func_000EBC60((Target_000EBC60 *)drawn);
        drawn->value_5c = value_88;
        drawn->slot6(drawn);
        if (pending) {
            data_00257CE8->func_000C1730(&key_374);
            pending = 0;
            key_374 = -1;
        }
        if (owner->flags & 0x4000000) {
            models[7]->value_5c = value_88;
            models[7]->slot6(model);
            return;
        }
        model->func_000480C0(0);
        data_00257CE8->func_000C1690(key_374);
        ((Object_000EBB80 *)&part)->func_000EBCF0(model);
        break;
    }
    case 13:
        if (owner->flags & 0x4000000) {
            return;
        }
        data_00251D6C->slot74(0x302, 1);
        model->func_00048000();
        models[2]->slot6(model);
        data_00251D6C->slot66(0);
        func_001BA8F0(model->matrix);
        models[4]->slot5(source->value, value_160);
        data_00251D6C->slot66(1);
        data_00251D6C->slot74(0x302, 0x303);
        break;
    case 12:
        depth = sphere.center.z;
        break;
    case 17:
    case 18:
        models[1]->slot6(model);
        break;
    }
}
