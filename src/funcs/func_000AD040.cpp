/* sym: ?func_00011C80@Object_000ACFB0@@UAEXH@Z = 0x000AD040 */
struct Vector3 {
    float x;
    float y;
    float z;
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
    Node *drawNext;
    Node **drawLink;
    Node ***drawTail;
};


struct Motion_0005F060;

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

struct Object_00047470;

struct Matrix_001BA950 {
    float m[4][4];
};

// A frame of a model's tree (func_000BA4C0 finds the n-th): its matrix at 0x14.
struct Frame_000AD040 {
    char unknown_00[0x14];
    float matrix[16];
};

// The skeleton model: its frame tree at 0x8 and its bone matrices at 0x20.
struct Object_00047470 {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6(Object_00047470 *model);

    char unknown_04[4];
    Frame_000AD040 *frames;
    char unknown_0c[0x14];
    Matrix_001BA950 *matrices;

    void func_00048000();
};

struct Model_000AD040 {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5(int first, int second);
};

struct Object_0006A960 {
    int func_0006AC10(int key);
};
extern Object_0006A960 data_0020C6C0;

void func_001BA9C0();
void __fastcall func_001BAA50();
void __fastcall func_001BA8F0(Matrix_001BA950 *matrix);
void __fastcall func_001BA950(Matrix_001BA950 *matrix);
void __fastcall func_001BAAA0(float *vector);
void __fastcall func_001BAAE0(float *matrix);
void __fastcall func_001BAC50(int *angles, int order);
void __fastcall func_001BB2E0(int angle);
void __fastcall func_001BB270(float *scale);
Frame_000AD040 *func_000BA4C0(Frame_000AD040 *root, int index);
struct Model_00101A70;

unsigned int func_000B9B50(Model_00101A70 *model, float *depth);

// One of 17 direct children of Node that share slots 4, 5, 6, 12 and 15 (table 0x1CD6E8, constructor
// func_000AD4B0).
struct Object_000ACFB0 : Node {
    virtual void func_00011C80(int argument);

    char unknown_040[4];
    int key;
    char unknown_048[8];
    Vector3 position;
    int angles[3];
    int turn[3];
    int lean[3];
    char unknown_080[0x28];
    Matrix_001BA950 matrix;
    unsigned int drawn;
    float distance;
    char unknown_0f0[0xb8];
    Object_00047470 *model;
    Model_000AD040 *extra;
    char unknown_1b0[0x48];
    Vector3 scale;
};

// Slot 3, while the key at 0x44 is live (func_0006AC10): on 0, 3 and 8 poses the model at 0x1a8 from the matrix at
// 0xa8 (frames 2 and 1 turned by the angles at 0x68, frame 3 by their first, the top by those at 0x74, func_000BA4C0
// and the model's bone matrices), runs it (func_00048000, slot 6) and draws the extra model at 0x1ac on the top, with
// render state data_001FA1D0 at 1. On those and on 2 and 7 then rebuilds the matrix at 0xa8 from the position at
// 0x50, the angles at 0x5c and the scale at 0x1f8, and takes the model's depth (func_000B9B50) as its own.
void Object_000ACFB0::func_00011C80(int argument)
{
    int saved = data_001FA1D0;
    if (key == -1 || !data_0020C6C0.func_0006AC10(key)) {
        return;
    }
    switch (argument) {
    case 0:
    case 3:
    case 8:
        if (model) {
            if (data_001FA1D0 != 1) {
                data_001FA1D0 = 1;
                data_00251D6C->slot73(1);
            }
            func_001BA9C0();
            func_001BA8F0(&matrix);
            func_001BA950(&model->matrices[0]);
            Frame_000AD040 *frame = func_000BA4C0(model->frames, 2);
            func_001BA9C0();
            func_001BAAA0(frame->matrix);
            func_001BAC50(turn, 0);
            func_001BAAE0(frame->matrix);
            func_001BA950(&model->matrices[2]);
            func_001BAA50();
            frame = func_000BA4C0(model->frames, 1);
            func_001BA9C0();
            func_001BAAA0(frame->matrix);
            func_001BAC50(turn, 0);
            func_001BAAE0(frame->matrix);
            func_001BA950(&model->matrices[1]);
            func_001BAA50();
            frame = func_000BA4C0(model->frames, 3);
            func_001BA9C0();
            func_001BAAA0(frame->matrix);
            func_001BB2E0(turn[0]);
            func_001BAAE0(frame->matrix);
            func_001BA950(&model->matrices[3]);
            func_001BAA50();
            func_001BA9C0();
            func_001BAC50(lean, 0);
            Matrix_001BA950 top;
            func_001BA950(&top);
            func_001BA950(&model->matrices[4]);
            func_001BAA50();
            model->func_00048000();
            model->slot6(model);
            if (extra) {
                func_001BA9C0();
                func_001BA8F0(&top);
                extra->slot5(0, 0);
                func_001BAA50();
            }
            func_001BAA50();
            if (data_001FA1D0 != saved) {
                data_001FA1D0 = saved;
                data_00251D6C->slot73(saved);
            }
        }
    case 2:
    case 7:
        func_001BA9C0();
        func_001BAAA0(&position.x);
        func_001BAC50(angles, 0);
        func_001BB270(&scale.x);
        func_001BA950(&matrix);
        drawn = func_000B9B50((Model_00101A70 *)model, &distance);
        func_001BAA50();
        depth = distance;
        break;
    }
}
