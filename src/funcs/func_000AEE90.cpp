/* sym: ?func_00011C80@Object_000AE970@@UAEXH@Z = 0x000AEE90 */
struct Vector3 {
    float x;
    float y;
    float z;
};

struct Matrix_001BA950 {
    float m[4][4];
};

void func_001BA9C0();
void __fastcall func_001BAA50();
void __fastcall func_001BA8F0(Matrix_001BA950 *matrix);
void __fastcall func_001BA950(Matrix_001BA950 *matrix);
void __fastcall func_001BAAA0(float *vector);
void __fastcall func_001BAC50(int *angles, int zero);
void __fastcall func_001BB270(float *scale);
void func_001BB9A0(float scale);

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
};

extern Device_00251D6C *data_00251D6C;

// A model drawn through its slot 5 (two words); a value at 0x5c.
struct Model_00101A70 {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void draw(int first, int second);

    char unknown_04[0x58];
    int value_5c;
};

unsigned int func_000B9B50(Model_00101A70 *model, float *time);

struct Object_0006A960 {
    int func_0006AC10(int key);
};

extern Object_0006A960 data_0020C6C0;

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

// One of 17 direct children of Node that share slots 4, 5, 6, 12 and 15 (table 0x1CD770).
struct Object_000AE970 : Node {
    virtual void func_00011C80(int argument);

    char unknown_040[0x4c];
    Vector3 offsets[2];
    char unknown_0a4[0xc];
    int key;
    int value_b4;
    int seen;
    int value_bc;
    int bank;
    Model_00101A70 *models[2];
    int data[2];
    int values[2];
    Vector3 position;
    int angles[3];
    Vector3 scale;
    char unknown_100[0x18];
    float side;
    char unknown_11c[4];
    Matrix_001BA950 matrix;
    unsigned int state;
    float time;
};

// Slot 3 (the pass), when data_0020C6C0 knows the key at 0xb0: marks the node seen (0xb8), then poses it (pass 2:
// position, angles and scale into the matrix at 0x120, the first model's state from func_000B9B50, the time as the
// node's depth) or draws its two models at their offsets (pass 3), mirrored by the side at 0x118 (device slot 66
// around the draw) when that is not above zero.
void Object_000AE970::func_00011C80(int argument)
{
    if (key == -1 || !data_0020C6C0.func_0006AC10(key)) {
        return;
    }
    seen = 1;
    switch (argument) {
    case 2:
        func_001BA9C0();
        func_001BAAA0(&position.x);
        func_001BAC50(angles, 0);
        func_001BB270(&scale.x);
        func_001BA950(&matrix);
        state = func_000B9B50(models[0], &time);
        if (state != 2 && state != 3) {
            value_bc = 1;
        }
        func_001BAA50();
        depth = time;
        break;
    case 3:
        func_001BA9C0();
        func_001BA8F0(&matrix);
        if (side <= 0.0f) {
            data_00251D6C->slot66(0);
        }
        if (models[0]) {
            models[0]->value_5c = value_b4;
            func_001BA9C0();
            func_001BAAA0(&offsets[0].x);
            if (side <= 0.0f) {
                func_001BB9A0(side);
            }
            models[0]->draw(data[0], values[0]);
            func_001BAA50();
        }
        if (models[1]) {
            models[1]->value_5c = value_b4;
            func_001BA9C0();
            func_001BAAA0(&offsets[1].x);
            if (side <= 0.0f) {
                func_001BB9A0(side);
            }
            models[1]->draw(data[1], values[1]);
            func_001BAA50();
        }
        if (side <= 0.0f) {
            data_00251D6C->slot66(1);
        }
        func_001BAA50();
        break;
    }
}
