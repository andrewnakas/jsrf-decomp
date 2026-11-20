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
    virtual void func_00047470();
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

// Slot 16: with a range for the point (index at 0x68 of data_00257CEC's points), returns 1 at once when the
// distance at 0x44 is at most 12; otherwise 0 unless the point lies within 30 ranges of the position and the way to
// it is within 30 degrees of the point's direction (dot at least 0.866), in which case 0x5c takes the y of their
// cross product and it returns 1. Without a range, 0.
int Object_000C2420::func_000C2AA0()
{
    float range = data_00257CEC->ranges[point];
    if (range == 0.0f) {
        return 0;
    }
    if (distance > 12.0f) {
        Direction_000C3BE0 way;
        func_0014C4C0(&way.vector, &position, &data_00257CEC->points[point]);
        if (func_0014C460(&way.vector, &way.vector) > range * 30.0) {
            return 0;
        }
        if (func_0014C800(&way.vector, &data_00257CEC->directions[point].vector) < 0.866f) {
            return 0;
        }
        func_0014C3B0(&way.vector, &way.vector, &data_00257CEC->directions[point].vector);
        value_5c = way.vector.y;
    }
    return 1;
}
