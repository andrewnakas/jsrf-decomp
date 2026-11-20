struct Frame_000479D0;
struct Data_000C2700 {
    char unknown_00;
    unsigned char type;
    char unknown_02;
    char kind;
};

struct Pair_000C3100 {
    short first;
    short second;
};

struct Matrix_001BA950 {
    float m[4][4];
};

// The models' base (tables 0x1CA490, 0x1CAA8C, 0x1CC12C): slot 5 poses the model.
struct Object_00047470 {
    virtual ~Object_00047470();
    virtual void slot1();
    virtual void func_00047470(void *first, void *second, Frame_000479D0 *frame);
    virtual void slot3();
    virtual void func_00047540();
    virtual void func_00047690(int first, int second);

    char unknown_04[0x1c];
    Matrix_001BA950 *matrices;
    char unknown_24[0x34];
    float frame;

    void func_00047970(void *data, int argument);
    void func_00047850();
};

struct Vector3 {
    float x;
    float y;
    float z;
};

struct Direction_000C3BE0 {
    Vector3 vector;
    float unknown_0c;
};

// The object at data_00257CEC: four points at 0x8 with a range each at 0x38, four directions at 0x78, an angle at
// 0xb8 and its models at 0xc0.
struct Object_000C3BE0 {
    char unknown_00[8];
    Vector3 points[4];
    float ranges[4];
    char unknown_48[0x30];
    Direction_000C3BE0 directions[4];
    int angle;
    char unknown_bc[4];
    Object_00047470 **models;
};

extern Object_000C3BE0 *data_00257CEC;

void __fastcall func_001BAAA0(float *vector);
void __fastcall func_001BB330(int angle);
void __fastcall func_0014C4C0(Vector3 *out, const Vector3 *from, const Vector3 *to);
float __fastcall func_0014C460(Vector3 *out, const Vector3 *in);
float __fastcall func_0014C800(const Vector3 *a, const Vector3 *b);
void __fastcall func_0014C3B0(Vector3 *out, const Vector3 *a, const Vector3 *b);

// The base whose table is at 0x1CDCF8 (constructor func_000C2420, destructor func_000C2470); slot 9 is the
// destructor.
struct Object_000C2420 {
    Object_000C2420(Data_000C2700 *data);
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

    Vector3 position;
    char unknown_10[0x18];
    int value_28;
    char unknown_2c[4];
    unsigned int flags;
    unsigned int state;
    char unknown_38[8];
    int angle;
    float distance;
    float speed;
    char unknown_4c[0x10];
    float value_5c;
    unsigned int model;
    char unknown_64[4];
    int point;
    char unknown_6c[0xc];
    Data_000C2700 *data;
    Pair_000C3100 *pair;
    float value;
};

// Slot 15: places the matrix at the position (func_001BAAA0) turned by the angle at 0x40 plus a half turn
// (func_001BB330), poses its model (index at 0x60) from the pair at 0x7c and the value at 0x80 (func_00047970)
// and draws it (func_00047850).
void Object_000C2420::func_000C25D0()
{
    func_001BAAA0(&position.x);
    func_001BB330(angle + 0x8000);
    data_00257CEC->models[model]->func_00047970(pair, *(int *)&value);
    data_00257CEC->models[model]->func_00047850();
}
