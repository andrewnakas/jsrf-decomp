/* sym: ?func_00011C80@Object_000BDAE0@@UAEXH@Z = 0x000BDFD0 */
struct Node {
    virtual ~Node();
    virtual void func_00011C90();
    virtual void func_00011C90_1();
    virtual void func_00011C80(int argument);

    unsigned int flags;
    int id;
    unsigned int mask;
    float depth;
    char unknown_14[0x2c];
};

struct Vector3 {
    float x;
    float y;
    float z;
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
void __fastcall func_001BAC50(int *angles, int order);
void __fastcall func_001BB270(float *scale);
void __fastcall func_001BAA50();

__forceinline void setState_000BDFD0(int value)
{
    if (data_001FA1D0 != value) {
        data_001FA1D0 = value;
        data_00251D6C->slot73(value);
    }
}

// One of 17 direct children of Node that share slots 4, 5, 6, 12 and 15 (table 0x1CDAE0).
struct Object_000BDAE0 : Node {
    virtual void func_00011C80(int argument);

    char unknown_040[0x50];
    int key;
    int value_94;
    int seen;
    int posed;
    Model_00101A70 *model;
    char unknown_0a4[0x10];
    Vector3 position;
    int angles[3];
    Vector3 scale;
    char unknown_0d8[0x28];
    Matrix_001BA950 matrix;
    unsigned int state;
    float time;
};

// Slot 3 (the pass), when the key at 0x90 is known to data_0020C6C0: marks it seen (0x98), then in passes 2 and 7
// poses the model at 0xa0 into the matrix at 0x100 (state from func_000B9B50, kept at 0x140; 0x9c set unless the
// state is 2 or 3, or when there is no model) and keeps the time as the node's depth; in passes 3 and 8 draws it
// with state 1 set for the device (fade from func_000B9C70 of the time in model state 1, reset to 1 after).
void Object_000BDAE0::func_00011C80(int argument)
{
    if (key == -1) {
        return;
    }
    if (!data_0020C6C0.func_0006AC10(key)) {
        return;
    }
    seen = 1;
    int saved = data_001FA1D0;
    switch (argument) {
    case 3:
    case 8:
        if (state == 2 || state == 3) {
            break;
        }
        if (!model) {
            break;
        }
        setState_000BDFD0(1);
        if (state == 1) {
            model->fade = func_000B9C70(time);
        }
        func_001BA9C0();
        func_001BA8F0(&matrix);
        model->value_5c = value_94;
        model->draw(0, 0);
        func_001BAA50();
        if (state == 1) {
            model->fade = 1.0f;
        }
        setState_000BDFD0(saved);
        break;
    case 2:
    case 7:
        if (model) {
            func_001BA9C0();
            func_001BAAA0(&position.x);
            func_001BAC50(angles, 0);
            func_001BB270(&scale.x);
            func_001BA950(&matrix);
            state = func_000B9B50(model, &time);
            if (state != 2 && state != 3) {
                posed = 1;
            }
            func_001BAA50();
            depth = time;
        } else {
            posed = 1;
        }
        break;
    }
}
