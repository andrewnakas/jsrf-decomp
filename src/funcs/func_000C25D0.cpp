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
    virtual void func_00047470();
    virtual void slot3();
    virtual void func_00047540();
    virtual void func_00047690(int first, int second);

    char unknown_04[0x54];
    float scale;

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

    Vector3 position;
    char unknown_10[0x30];
    int angle;
    char unknown_44[4];
    float speed;
    char unknown_4c[0x14];
    unsigned int type;
    char unknown_64[0x14];
    Data_000C2700 *data;
    void *motion;
    float time;
};

// Slot 15: places the model of this type at the position (func_001BAAA0) turned by the angle at 0x40 plus a
// half turn (func_001BB330), poses it with the motion at 0x7c at the time at 0x80 (func_00047970) and draws it
// (func_00047850).
void Object_000C2420::func_000C25D0()
{
    func_001BAAA0(&position.x);
    func_001BB330(angle + 0x8000);
    data_00257CEC->models[type]->func_00047970(motion, *(int *)&time);
    data_00257CEC->models[type]->func_00047850();
}
