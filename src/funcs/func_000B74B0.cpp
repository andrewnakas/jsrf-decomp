/* sym: ?func_00011C80@Object_000B7440@@UAEXH@Z = 0x000B74B0 */
struct Matrix_001BA950 {
    float m[4][4];
};

struct Vector3 {
    float x;
    float y;
    float z;
};

void func_001BA9C0();
void __fastcall func_001BAA50();
void __fastcall func_001BA8F0(Matrix_001BA950 *matrix);
void __fastcall func_001BA950(Matrix_001BA950 *matrix);
void __fastcall func_001BAAA0(float *vector);
void __fastcall func_001BAC50(int *angles, int zero);
void __fastcall func_001BB270(float *scale);
void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);
void func_001BB650(float distance);

// The Direct3D device.
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
    virtual void __stdcall slot73(int value);
};

extern Device_00251D6C *data_00251D6C;
extern int data_001FA1D0;

// Hands `value` to the device slot when the cached state differs.
#define SET_STATE(cache, slot, value) \
    if (cache != (value)) { \
        cache = (value); \
        data_00251D6C->slot(value); \
    }

// The model, drawn through its slot 5 (two words); its fade at 0x58 and a value at 0x5c.
struct Model_00101A70 {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void draw(int first, int second);

    char unknown_04[0x54];
    float fade;
    int value_5c;
};

unsigned int func_000B9B50(Model_00101A70 *model, float *time);

struct Node {
    virtual ~Node();
    virtual void func_00011C90();
    virtual void func_00011C90_1();
    virtual void func_00011C80(int argument);

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
    Node *drawNext;
    Node **drawLink;
    Node ***drawTail;
};

// One of 17 direct children of Node that share slots 4, 5, 6, 12 and 15 (table 0x1CD950).
struct Object_000B7440 : Node {
    virtual void func_00011C80(int argument);

    char unknown_040[4];
    unsigned int state;
    char unknown_048[4];
    int mode;
    Vector3 position;
    int angles[3];
    Vector3 scale;
    char unknown_074[4];
    unsigned int options;
    char unknown_07c[0x1c];
    Vector3 offset;
    char unknown_0a4[0x24];
    int value_c8;
    Model_00101A70 *model;
    int first;
    char unknown_0d4[0xc];
    int second;
    char unknown_0e4[8];
    Vector3 origin;
    float distance;
    int turn[3];
    Vector3 size;
    char unknown_114[0x28];
    int spin[3];
    int alpha;
    Matrix_001BA950 matrix;
    unsigned int result;
    float time;
};

// Slot 3 (the pass), unless the mode at 0x4c is 7 and only with the top bit of 0x44 set. Pass 3 draws the model with
// the matrix at 0x14c (its value from 0xc8, slot 5 with 0xd0 and 0xe0); below the alpha 255 at 0x148 it turns device
// state 73 on and fades the model by alpha / 255 for the draw, then back to 1. Pass 2 builds the matrix (from 0x50,
// 0x5c, 0x68, 0x98 and 0x13c, or with bit 30 of 0x44 from 0xec, 0xf8 back along z, 0xfc and 0x108), keeps the
// transformed origin's z as the node's depth and, with bit 29 of 0x78 in mode 3, moves to mode 7 once the model's
// state (func_000B9B50) is 2 or 3.
void Object_000B7440::func_00011C80(int argument)
{
    if (mode == 7) {
        return;
    }
    switch (argument) {
    case 3:
        if (!(state & 0x80000000)) {
            break;
        }
        if (!model) {
            break;
        }
        if (alpha < 0xff) {
            SET_STATE(data_001FA1D0, slot73, 1);
            model->fade = alpha * (1.0f / 255.0f);
        }
        func_001BA9C0();
        func_001BA8F0(&matrix);
        model->value_5c = value_c8;
        model->draw(first, second);
        func_001BAA50();
        if (alpha < 0xff) {
            model->fade = 1.0f;
        }
        break;
    case 2: {
        if (!(state & 0x80000000)) {
            break;
        }
        Vector3 point;
        point.x = 0.0f;
        point.y = 0.0f;
        point.z = 0.0f;
        func_001BA9C0();
        if (!(state & 0x40000000)) {
            func_001BAAA0(&position.x);
            func_001BAC50(angles, 0);
            func_001BB270(&scale.x);
            func_001BAAA0(&offset.x);
            func_001BAC50(spin, 0);
        } else {
            func_001BAAA0(&origin.x);
            func_001BB650(distance * -1.0f);
            func_001BAC50(turn, 0);
            func_001BB270(&size.x);
        }
        func_001BAB20(&point, &point);
        depth = point.z;
        if ((options & 0x20000000) && mode == 3) {
            result = func_000B9B50(model, &time);
            if (result == 3 || result == 2) {
                mode = 7;
            }
        }
        func_001BA950(&matrix);
        func_001BAA50();
        break;
    }
    }
}
