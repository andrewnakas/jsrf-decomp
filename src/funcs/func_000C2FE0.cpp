struct Frame_000479D0;
struct Data_000C2700 {
    unsigned char type;
    unsigned char mode;
    char unknown_02;
    char kind;
};

struct Matrix_001BA950;

// The models of data_00257CEC, one per type.
struct Object_00047470 {
    virtual ~Object_00047470();
    virtual void slot1();
    virtual void func_00047470(void *first, void *second, Frame_000479D0 *frame);
    virtual void slot3();
    virtual void func_00047540();
    virtual void func_00047690(int first, int second);

    char unknown_04[0x54];
    float scale;
    int value_5c;

    void func_00047850();
    void func_00047970(void *data, int argument);
};

void __fastcall func_001BAAA0(float *position);
void __fastcall func_001BB330(int angle);

struct Object_000C3BE0 {
    char unknown_00[0xb8];
    int angle;
    char unknown_bc[4];
    Object_00047470 **models;
};

extern Object_000C3BE0 *data_00257CEC;

struct Vector3 {
    float x;
    float y;
    float z;
};

// The base whose table is at 0x1CDCF8 (constructor func_000C2420, destructor func_000C2470); slot 9 is the
// destructor.
struct Object_000C2420 {
    virtual void func_000C2630();
    virtual void func_000C2700();
    virtual void func_000C3800();
    virtual void func_000C30C0();
    virtual void func_000C3100();
    virtual void func_000C3140();
    virtual void func_000C31B0();
    virtual void func_000C3350();
    virtual void func_000C33C0();
    virtual ~Object_000C2420();
    virtual void func_000C2480();
    virtual void func_000C36F0();
    virtual void func_000C2FE0();
    virtual void func_000C2500();
    virtual void func_000C2560();
    virtual void func_000C25D0();
    virtual int func_000C2AA0();

    int func_000C29C0(Object_00047470 *model);

    Vector3 position;
    char unknown_10[0x20];
    unsigned int flags;
    char unknown_34[0xc];
    int angle;
    char unknown_44[4];
    float depth;
    int visibility;
    char unknown_50[0x10];
    unsigned int type;
    char unknown_64[8];
    int value_6c;
    char unknown_70[8];
    Data_000C2700 *data;
    void *motion;
    float time;
};

// Slot 12: places the model at the position (func_001BAAA0) and keeps how it is seen (func_000C29C0) at 0x4c.
// Unless it is unseen, near (1) or flag 2 is set, turns it by the angle at 0x40 plus a half turn, gives it the
// value at 0x6c (at its 0x5c) and a scale (fading from 1 at depth 300 to 0 at 400 when far, kind 3; else 1)
// and runs its slot 5 with the motion and time.
void Object_000C2420::func_000C2FE0()
{
    Object_00047470 *model;
    func_001BAAA0(&position.x);
    visibility = func_000C29C0(data_00257CEC->models[type]);
    if (visibility == 0 || (flags & 2))
        return;
    if (visibility == 3) {
        model = data_00257CEC->models[type];
        func_001BB330(angle + 0x8000);
        model->value_5c = value_6c;
        model->scale = (400.0f - depth) * 0.01f;
        model->func_00047690((int)motion, *(int *)&time);
    } else if (visibility != 1) {
        model = data_00257CEC->models[type];
        func_001BB330(angle + 0x8000);
        model->value_5c = value_6c;
        model->scale = 1.0f;
        model->func_00047690((int)motion, *(int *)&time);
    }
}
