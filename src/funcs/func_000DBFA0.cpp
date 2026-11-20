struct Vector3 {
    float x;
    float y;
    float z;
};

// The object at data_00257CE8 (func_00157F10 is the engine's); it also answers func_000C1D40.
struct Object_00157F10 {
    int func_000C1D40(int *effect, int *second, int *third);
};

extern Object_00157F10 *data_00257CE8;

struct Object_0006DB80 {
    void func_0006DFC0(int key, const Vector3 *position);
};

extern Object_0006DB80 data_00251F78;

struct Angles_000DB8F0 {
    int x;
    int y;
    int z;
};

// The object a behaviour serves (at 0x4).
struct Object_000C5B50 {
    char unknown_00[8];
    int id;
    char unknown_0c[0x38];
    Vector3 position;
    Angles_000DB8F0 angles;
    float value_5c;
    char unknown_60[0x10];
    float value_70;
    char unknown_74[0x28];
    int value_9c;
    char unknown_a0[4];
    unsigned int flags;

    void func_000C5AD0(int amount);
    int func_000C5B10(int message, void *data);
};

void func_000FEC30(int value, const Vector3 *position);
void __fastcall func_0014C4C0(Vector3 *out, const Vector3 *from, const Vector3 *to);
int __fastcall func_0014C840(int first, int second);
void func_000E73D0(int first, int second, int third);
void func_001BA9C0();
void __fastcall func_001BAA50();
void __fastcall func_001BAAA0(float *vector);
void __fastcall func_001BAB20(Vector3 *out, const Vector3 *in);
void __fastcall func_001BAC00(Vector3 *out, const Vector3 *in);
void __fastcall func_001BB330(int angle);

struct Object_000C1270 {
    char unknown_00[0x7c];
    Vector3 unknown_7c;
};

extern Object_000C1270 *data_00257CE4;

// Four points, one per shot.
extern Vector3 data_0021773C[4];

struct Limits_000CC020 {
    char unknown_00[0x18];
    float range;
};

// A point of the path at 0x70 (24 bytes).
struct Point_000DB8F0 {
    Vector3 position;
    float value_0c;
    char unknown_10[8];
};

// The base with a pure slot 0 (table 0x1CE304).
struct Object_000CC600 {
    virtual void func_000CD1E0() = 0;
    virtual void func_00011C90();
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_1(int argument);
    virtual ~Object_000CC600();
};

struct Object_000CD1E0 : Object_000CC600 {
    virtual void func_000CD1E0();
    virtual void func_00011C90();
    virtual ~Object_000CD1E0();
    virtual void func_000CD210();
    virtual void func_000CD800();
    virtual void func_000CD850();
    virtual void func_000D77D0() = 0;
    virtual void func_000D7880() = 0;
    virtual float func_000CD440();
    virtual float func_000CD4F0();
    virtual int func_000CD390(Vector3 *position, float value, Vector3 *direction);

    void func_000CD310(float rate);

    Object_000C5B50 *owner;
    int state;
    int unknown_0c;
    int timer;
    Vector3 position;
    char unknown_20[0x10];
    Limits_000CC020 *limits;
    char unknown_34[8];
    int index;
    char unknown_40[0x28];
    int value_68;
};

// The block at 0x217694 (0x8c).
struct Extra_000DB8F0 {
    int value_00;
    char unknown_04[0xc];
    int value_10;
};

// The class whose table is at 0x1CE780 (constructor func_000DB8F0).
struct Object_000DB8F0 : Object_000CD1E0 {
    virtual void func_00011C80(int argument);
    virtual void func_00011C80_1(int argument);
    virtual ~Object_000DB8F0();
    virtual void func_000CD210();
    virtual void func_000CD800();
    virtual void func_000CD850();
    virtual void func_000D77D0();
    virtual void func_000D7880();
    virtual int func_000CD390(Vector3 *position, float value, Vector3 *direction);
    void func_000DBFA0();
    void func_000DC800();
    void func_000DC8E0();
    int func_000DC360();

    char unknown_06c[4];
    Point_000DB8F0 *path;
    char unknown_074[0x18];
    Extra_000DB8F0 *extra;
    char unknown_090[8];
    int value_98;
    char unknown_09c[0x10];
    int value_ac;
    unsigned int value_b0;
    char unknown_0b4[0x80];
    int effect_134;
    int value_138;
    int value_13c;
    int sound_140;
};

// A handler of the table at 0x2177A0: turns the owner's angles towards the current point of the path (slot 12 with
// the range at 0x18 of the object at 0x30) and keeps the new y angle; after 180 frames, state 2 once the y angle
// stops changing.
void Object_000DB8F0::func_000DBFA0()
{
    Angles_000DB8F0 angles = owner->angles;
    Vector3 direction;
    func_0014C4C0(&direction, &path[index].position, &owner->position);
    func_000CD390((Vector3 *)&angles, limits->range, &direction);
    int y = angles.y;
    if (++timer > 180) {
        int delta = y - owner->angles.y;
        if (!delta) {
            state = 2;
        }
    }
    owner->angles.y = y;
}
