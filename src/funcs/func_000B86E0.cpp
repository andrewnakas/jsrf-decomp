/* sym: ?func_00011C80@Object_000B9960@@UAEXH@Z = 0x000B86E0 */
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

struct Vector3 {
    float x;
    float y;
    float z;
};

// Where func_000BAC60 places the object: position, angles, scale and a model code (bank << 10 | index).
struct Params_000BAC60 {
    Vector3 position;
    int angles[3];
    Vector3 scale;
    unsigned int model;
};

// An entry of table 5 (0xf0 bytes, copied to 0x228): ids in tables 2, 3 and 7 (-1 = none) and the 16 children.
struct Entry_000B8230 {
    unsigned int flags;
    int model;
    int shadow;
    int first;
    int second;
    int extra;
    float lift;
    float friction;
    char unknown_20[0x20];
    Vector3 corners[8];
    int children[16];
    Vector3 position;
    int sound;
};

struct Matrix_001BA950 {
    float m[4][4];
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
    virtual void __stdcall slot73(int value);
};

extern Device_00251D6C *data_00251D6C;
extern int data_001FA1D0;

struct Model_00101A70 {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void draw(void *first, int second);

    char unknown_04[0x54];
    float fade;
    float floor;
};

struct Object_0006A960 {
    int func_0006AC10(int key);
};

extern Object_0006A960 data_0020C6C0;

float func_000B9C70(float time);
unsigned int func_000B9B50(Model_00101A70 *model, float *time);
void func_001BA9C0();
void __fastcall func_001BA8F0(Matrix_001BA950 *matrix);
void __fastcall func_001BA950(Matrix_001BA950 *matrix);
void __fastcall func_001BAAA0(float *vector);
void func_001BB650(float angle);
void __fastcall func_001BAC50(int *angles, int order);
void __fastcall func_001BB270(float *scale);
void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);
void __fastcall func_001BAA50();

__forceinline void setState_000B86E0(int value)
{
    if (data_001FA1D0 != value) {
        data_001FA1D0 = value;
        data_00251D6C->slot73(value);
    }
}

// The child of Node whose table is at 0x1CD998 (destructor func_000B8610).
struct Object_000B9960 : Node {
    virtual void func_00011C80(int argument);

    char unknown_040[4];
    int value_44;
    int state;
    int seen;
    int value_50;
    int posed;
    int key;
    float floor;
    int set;
    int sound;
    void *model;
    void *shadow;
    Model_00101A70 *current;
    char unknown_074[8];
    void *active;
    char unknown_080[0xc];
    int value_8c;
    char unknown_090[0x50];
    int alpha;
    Matrix_001BA950 matrix;
    unsigned int view;
    float time;
    char unknown_12c[0xfc];
    Entry_000B8230 entry;
    unsigned int flags_318;
    Vector3 direction;
    float turn;
    int spin[3];
    int angles[3];
    Vector3 scale;
};

// Slot 3 (the pass), when the key at 0x58 is known to data_0020C6C0 and the state is not 7: marks it seen (0x4c).
// Pass 2 poses the model into the matrix at 0xe4 (position, turn unless flag 0x4000000, angles, spin, scale), keeps
// the nearest view depth in front of the eye among the entry's eight corners (the origin's when opaque or with flag
// 0x8000000) as the node's depth and the view state from func_000B9B50 at 0x124 (0x54 set unless 2 or 3; 0x50 with
// flag 0x400000 unless state 3 with view 2 or 3). Pass 3 draws the current model: faded by its alpha or by
// func_000B9C70 in view state 1 (device state 1), state 1 or 0 by flag 0x40000000 when opaque, and flag 0x10000000
// around the draw.
void Object_000B9960::func_00011C80(int argument)
{
    int saved = data_001FA1D0;
    if (key == -1) {
        return;
    }
    if (!data_0020C6C0.func_0006AC10(key)) {
        return;
    }
    seen = 1;
    if (state == 7) {
        return;
    }
    switch (argument) {
    case 3:
        if (!(entry.flags & 0x20000000) && (view == 2 || view == 3)) {
            break;
        }
        if (!current) {
            break;
        }
        if (flags_318 & 0x10000000) {
            break;
        }
        if (!(entry.flags & 0x20000000) && (view == 1 || alpha < 0xff)) {
            setState_000B86E0(1);
            if (alpha < 0xff) {
                current->fade = alpha * (1.0f / 255.0f);
            } else {
                current->fade = func_000B9C70(time);
            }
        }
        if (alpha >= 0xff) {
            if (entry.flags & 0x40000000) {
                setState_000B86E0(1);
            } else {
                setState_000B86E0(0);
            }
        }
        func_001BA9C0();
        func_001BA8F0(&matrix);
        if (entry.flags & 0x10000000) {
            data_00251D6C->slot66(0);
        }
        current->floor = floor;
        current->draw(active, value_8c);
        if (entry.flags & 0x10000000) {
            data_00251D6C->slot66(1);
        }
        func_001BAA50();
        if (!(entry.flags & 0x20000000) && (view == 1 || alpha < 0xff)) {
            current->fade = -1.0f;
        }
        setState_000B86E0(saved);
        break;
    case 2: {
        func_001BA9C0();
        func_001BAAA0(&direction.x);
        if (!(entry.flags & 0x4000000)) {
            func_001BB650(turn * -1.0f);
        }
        func_001BAC50(angles, 0);
        func_001BAC50(spin, 0);
        func_001BB270(&scale.x);
        float nearest;
        Vector3 corners[8];
        if (alpha < 0xff && !(entry.flags & 0x8000000)) {
            for (int i = 0; i < 8; i++) {
                func_001BAB20(&corners[i], &entry.corners[i]);
                if (i == 0) {
                    nearest = corners[0].z;
                } else if (corners[i].z > 0.0f && corners[i].z < nearest) {
                    nearest = corners[i].z;
                }
            }
        } else {
            corners[0].x = 0;
            corners[0].y = 0;
            corners[0].z = 0;
            func_001BAB20(&corners[0], &corners[0]);
            nearest = corners[0].z;
        }
        view = func_000B9B50(current, &time);
        if ((entry.flags & 0x400000) && (state != 3 || view == 0 || view == 1)) {
            value_50 = 1;
        }
        if (view != 2 && view != 3) {
            posed = 1;
        }
        depth = nearest;
        func_001BA950(&matrix);
        func_001BAA50();
        break;
    }
    }
}
